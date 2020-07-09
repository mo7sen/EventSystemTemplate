#include "EventListener.h"
#include "EventSystem.h"

void event_listener_init(struct EventListener *listener)
{
	loop_event_types {
		listener->eventTypeSubs[type] = false;
	}
}

void event_listener_deinit(struct EventListener *listener)
{
	loop_event_types {
		if(listener->eventTypeSubs[type])
			event_listener_unsubscribe(listener, type);
	}
	EventSystem.removeListener(listener);
}

void event_listener_subscribe(struct EventListener *listener, enum EventType type, bool (*handler)())
{
	EventSystem.addListener(listener, type);
	listener->handlers[type] = handler;
}

void event_listener_unsubscribe(struct EventListener *listener, enum EventType type)
{
	EventSystem.unsub(listener, type);
}
