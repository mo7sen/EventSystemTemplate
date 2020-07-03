#ifndef __EVENT_SYSTEM_HEADER__
#define __EVENT_SYSTEM_HEADER__
#include "Event.h"
#include "stdbool.h"

#ifndef MAX_EVENTS
#define MAX_EVENTS 256
#endif

#ifndef MAX_SUBSCRIBER_COUNT
#define MAX_SUBSCRIBER_COUNT 16 // This is the max subscribers allowed per event type (will probably need to be increased)
#endif

struct EventSystem
{
	unsigned int eventSize[EVENT_TYPE_COUNT];          // Size of each eventbuffer
	struct Event events[EVENT_TYPE_COUNT][MAX_EVENTS]; // Event buffers
	unsigned int subSize[EVENT_TYPE_COUNT];            // Size of each subscriber list (for each type of events)
	struct EventListener *subscribers[EVENT_TYPE_COUNT][MAX_SUBSCRIBER_COUNT];
};

struct EventListener
{
	struct EventSystem *sys;

	bool typeSubs[EVENT_TYPE_COUNT];

	void (*handlers[EVENT_TYPE_COUNT])();
};

struct EventDispatcher
{
	struct EventSystem *sys;
};

void event_system_init(struct EventSystem *system);
void event_system_add_listener(struct EventSystem *system, struct EventListener *listener, enum EventCategory type);
void event_system_add_event(struct EventSystem *sys, struct Event event);
void event_system_update(struct EventSystem *sys);
void event_system_handle_category(struct EventSystem *sys, enum EventCategory category);
void event_system_clear(struct EventSystem *sys);

void event_listener_init(struct EventListener *listener);
void event_listener_set_sys(struct EventListener *lis, struct EventSystem *sys);
void event_listener_subscribe(struct EventListener *listener, enum EventCategory category, void (*f)());

void event_dispatcher_init(struct EventDispatcher *dispatcher);
void event_dispatcher_set_sys(struct EventDispatcher *dis, struct EventSystem *sys);
void event_dispatch(struct EventDispatcher *dis, struct Event event);
#endif
