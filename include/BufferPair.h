#ifndef EVENT_BUFFER_PAIR_H
#define EVENT_BUFFER_PAIR_H

#include "EventBuffer.h"
#include "stdbool.h"

struct BufferPair {
	struct EventBuffer _primary;
	struct EventBuffer _secondary;
	struct EventBuffer *read;
	struct EventBuffer *write;
	bool read_primary;
};

void event_buffer_pair_init(struct BufferPair *pair);
void event_buffer_pair_deinit(struct BufferPair *pair);

unsigned int event_buffer_pair_add_event(struct BufferPair *pair, void *event);

void event_buffer_pair_swap(struct BufferPair *pair);
void event_buffer_pair_clear_read(struct BufferPair *pair);

static inline void event_buffer_pair_for_each(struct BufferPair *pair, enum EventType type, void (*handler)(enum EventType, void*))
{
	event_buffer_for_each(pair->read, type, handler);
}

#endif
