#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H

#include "BufferPair.h"
#include "vec.h"

#include "EventListener.h"

extern struct event_system_struct {
	struct BufferPair bufferPair;

	void (*init)();
	void (*deinit)();
	void (*dispatch)(void *);

	void (*update)();
	void (*unsub) (struct EventListener*, enum EventType);

	vec_void_t listeners;
	vec_void_t eventListeners[EVENT_TYPE_COUNT];

	void (*addListener)();
	void (*removeListener)(struct EventListener *listener);
} EventSystem;


#endif
