#include "EventBuffer.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "stdio.h"

#define HAVE_STRUCT_TIMESPEC
#include "pthread.h"

pthread_mutex_t addEventMutex = PTHREAD_MUTEX_INITIALIZER;

void event_buffer_init(struct EventBuffer *eventBuffer)
{
	loop_event_types {
		eventBuffer->buffers[type] = malloc(EVENT_SIZE * INITIAL_EVENT_BUFFER_CAPACITY);
		eventBuffer->capacities[type] = INITIAL_EVENT_BUFFER_CAPACITY * EVENT_SIZE;
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

	int error;
	if((error = pthread_mutex_lock(&addEventMutex)) != 0)
    {
        fprintf (stderr, "Error = %d (%s)\n", error, strerror(error)); exit (1);
    }

	if(eventBuffer->capacities[eventType] - (eventBuffer->sizes[eventType] * EVENT_SIZE) <= EVENT_SIZE)
	{
		unsigned int newCapacity = (unsigned int)((float)eventBuffer->capacities[eventType] * 1.2);
		void * newPointer = realloc(eventBuffer->buffers[eventType], newCapacity);

		if (newPointer)
		{
			eventBuffer->buffers[eventType] = newPointer;
			eventBuffer->capacities[eventType] = newCapacity;
		}
		else
			assert(!"Couldn't Realloc event buffer");
	}
	unsigned int eventIndex = eventBuffer->sizes[eventType]++;

    if ((error = pthread_mutex_unlock (&addEventMutex)) != 0) {
        fprintf (stderr, "Error = %d (%s)\n", error, strerror(error)); exit (1);
    }

	memcpy(((char*)eventBuffer->buffers[eventType]) + eventIndex * EVENT_SIZE, event, EVENT_SIZE);

	return 0;
}

unsigned int event_buffer_clear(struct EventBuffer *eventBuffer)
{
	loop_event_types {
		eventBuffer->sizes[type] = 0;
	}
	return 0;
}
