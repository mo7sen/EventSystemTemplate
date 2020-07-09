#ifndef EVENT_BUFFER_HEADER_H
#define EVENT_BUFFER_HEADER_H

#include "Event.h"

#define loop_event_types for(int type = 0; type < EVENT_TYPE_COUNT; ++type)

struct EventBuffer
{
	void *buffers[EVENT_TYPE_COUNT];
	unsigned int capacities[EVENT_TYPE_COUNT];
	unsigned int sizes[EVENT_TYPE_COUNT];
};

void event_buffer_init(struct EventBuffer *eventBuffer);
void event_buffer_deinit(struct EventBuffer *eventBuffer);

unsigned int event_buffer_add(struct EventBuffer *eventBuffer, void *event);
unsigned int event_buffer_clear(struct EventBuffer *eventBuffer);

static inline void event_buffer_for_each(struct EventBuffer *eventBuffer, enum EventType type, void (*handler)(enum EventType, void *))
{
	for(int index = 0; index < eventBuffer->sizes[type]; ++index)
		handler(type, ((char*)eventBuffer->buffers[type]) + (index * EVENT_SIZE));
}

#endif
