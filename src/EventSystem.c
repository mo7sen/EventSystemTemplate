#include "EventSystem.h"
#include "string.h"
#include "assert.h"
#include "stddef.h"

void event_system_init(struct EventSystem *system)
{
	memset(system, 0, sizeof(struct EventSystem));
}

void event_system_add_listener(struct EventSystem *system, struct EventListener *listener, enum EventCategory category)
{
	if(system->subSize[category] >= MAX_SUBSCRIBER_COUNT)
		assert(!"Surpassed Max Subscriber Count");
	system->subscribers[category][system->subSize[category]] = listener;
	++system->subSize[category];
}

void event_system_add_event(struct EventSystem *sys, struct Event event)
{
	if(sys->eventSize[event.category] >= MAX_EVENTS)
		assert(!"Surpassed Max Event Count");
	sys->events[event.category][sys->eventSize[event.category]] = event;
	++sys->eventSize[event.category];
}

void event_system_handle_category(struct EventSystem *sys, enum EventCategory category)
{
	for(int j = 0; j < sys->eventSize[category]; ++j)    // For each event
	{
		struct Event event = sys->events[category][j];
		for(int k = 0; k < sys->subSize[category]; ++k)  // For each subscriber
		{
			if(!sys->subscribers[category][k] || !sys->subscribers[category][k]->typeSubs[category])
				continue;

			sys->subscribers[category][k]->handlers[category](&event.eventType, &event.eventDetails);
		}
	}
}

void event_system_update(struct EventSystem *sys)
{
	for(int i = 0; i < EVENT_TYPE_COUNT; ++i)         // For each event type
		event_system_handle_category(sys, i);
}

void event_system_clear(struct EventSystem *sys)
{
	memset(sys, 0, offsetof(struct EventSystem, subSize));
}

void event_listener_init(struct EventListener *listener)
{
	memset(listener, 0, sizeof(struct EventListener));
}

void event_listener_set_sys(struct EventListener *lis, struct EventSystem *sys)
{
	lis->sys = sys;
}

void event_listener_subscribe(struct EventListener *listener, enum EventCategory category, void (*f)())
{
	listener->typeSubs[category] = true;
	listener->handlers[category] = f;

	event_system_add_listener(listener->sys, listener, category);
}

void event_dispatcher_init(struct EventDispatcher *dispatcher)
{
	memset(dispatcher, 0, sizeof(struct EventDispatcher));
}

void event_dispatcher_set_sys(struct EventDispatcher *dis, struct EventSystem *sys)
{
	dis->sys = sys;
}

void event_dispatch(struct EventDispatcher *dis, struct Event event)
{
	event_system_add_event(dis->sys, event);
}
