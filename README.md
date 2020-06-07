# <p style="text-align: center;">Event System Template</p>

<p style="font-size:14px; color: red;">Note: This is just a template I made while writing the event system for the <a href="https://www.github.com/mo7sener/evol">evol</a> game engine.
It is by no means complete or optimized as "evol" itself is a hobby project. I couldn't find specific resources
on how event systems are built from scratch so this is just me writing what I understood. Not sure if this is
how stuff is done; any constructive criticism will be received gladly.</p>

This is an Event System written entirely in C. It has the main parts of an actual event system: an event
dispatcher, an event listener and a whole system that tries to bind the first two parts together. 

A guide on how to add new event categories in the system can be found in the `AddingEvents.md` file. I tried
to make it as simple as possible but there is a limit on what can be done without Object-oriented concepts.

## Usage

A sample program
```  
#include <stdio.h>

// These need to be defined before including the header or they will be set to their default values
#define MAX_EVENTS 8               // Buffer-size for each event category    , default = 256
#define MAX_SUBSCRIBER_COUNT 4     // Max number of subscribers per category , default =  16

#include "EventSystem.h" // This all we need to include

// This is a sample function that we'll use as a callback whenever a MouseEvent occurs
static void on_mouse_event(enum MouseEvent *event, struct MouseEventDetails *details)
{
	printf("Mouse Moved: New Position = (%d, %d)\n", 
			details->mousePosition[0], 
			details->mousePosition[1]);
}

int main(int argc, char **argv)
{
	// Initialize EventSystem struct
	struct EventSystem sys;
	event_system_init(&sys);

	// Initialize EventListener struct
	struct EventListener lis_1;
	event_listener_init(&lis_1);

	event_listener_set_sys(&lis_1, &sys);                         // Attach lis_1 to sys
	event_listener_subscribe(&lis_1, MouseEvent, on_mouse_event); // Subscribe to MouseEvents and specify the callback function

	// Initialize EventDispatcher struct
	struct EventDispatcher dis_1;
	event_dispatcher_init(&dis_1);
	event_dispatcher_set_sys(&dis_1, &sys);   // Attach dis_1 to sys

	// Create a sample MouseEvent to be dispatched
	struct Event sampleEvent = {
		.category = MouseEvent,
		.eventType.mouse = MouseMoved,
		.eventDetails.mouseEventDetails = {
			.mousePosition = {100, 100},
			.button = 0,
		},
	};

	// Dispatch event
	event_dispatch(&dis_1, sampleEvent);

	// Handle all events currently in all of the event buffers
	event_system_update(&sys);

	// We can handle MouseEvents by using
	// event_system_handle_category(&sys, MouseEvent);

	// Clear buffers
	event_system_clear(&sys);

	return 0;
}

```

Output:
```
Mouse Moved: New Position = (100, 100)
```

## Testing

I kind of did zero testing and hoped for the best with this one. While I believe this is unacceptable, I'm in
a bit of a hurry as I want "evol" to be finished by a specific time.

## Limitations

- **Single-threaded** -- not sure if this is a limitation as there are the more fine functions that allow more 
control and, in turn, opens the way for the application to use multi-threading as needed; it's just not built 
into the system.
- **Can't target events at specific listeners** -- all events are received by all listeners that are subscribed to
this event category, which will likely cause a huge performance decline as more single-target events are added
to the event buffer.
- **Static** -- There are absolutely zero heap allocations in the entire system. While this may make it a bit
faster, it means that event buffers and subscriber lists are of a fixed size that they cannot exceed. While
the size of these two things can be set to a large value, this may not be efficient as there will probably be
unused memory that is just reserved, just in case.
