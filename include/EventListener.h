#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include "Event.h"
#include "stdbool.h"

struct EventListener {
	bool eventTypeSubs[EVENT_TYPE_COUNT];
	bool (*handlers[EVENT_TYPE_COUNT])();
};

void event_listener_init(struct EventListener *listener);
void event_listener_deinit(struct EventListener *listener);
void event_listener_subscribe(struct EventListener *listener, enum EventType type, bool (*handler)());
void event_listener_unsubscribe(struct EventListener *listener, enum EventType type);

#endif
