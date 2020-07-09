#include "EventBuffer.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

void event_buffer_init(struct EventBuffer *eventBuffer)
{
	loop_event_types {
		eventBuffer->buffers[type] = malloc(EVENT_SIZE * INITIAL_EVENT_BUFFER_CAPACITY);
		eventBuffer->capacities[type] = INITIAL_EVENT_BUFFER_CAPACITY;
		eventBuffer->sizes[type] = 0;
	}
}

void event_buffer_deinit(struct EventBuffer *eventBuffer)
{
	loop_event_types {
		free(eventBuffer->buffers[type]);
	}
}

unsigned int event_buffer_add(struct EventBuffer *eventBuffer, void *event)
{
	unsigned int eventType = *(unsigned int *)event;
	if(eventBuffer->capacities[eventType] - eventBuffer->sizes[eventType] * EVENT_SIZE <= EVENT_SIZE)
	{
		void * newPointer = realloc(eventBuffer->buffers[eventType], (unsigned int)((float)eventBuffer->capacities[eventType] * 1.2));

		if(newPointer)
			eventBuffer->buffers[eventType] = newPointer;
		else
			assert(!"Couldn't Realloc event buffer");
	}

	memcpy(eventBuffer->buffers[eventType] + eventBuffer->sizes[eventType] * EVENT_SIZE, event, EVENT_SIZE);
	eventBuffer->sizes[eventType]++;

	return 0;
}

unsigned int event_buffer_clear(struct EventBuffer *eventBuffer)
{
	loop_event_types {
		eventBuffer->sizes[type] = 0;
	}
	return 0;
}
