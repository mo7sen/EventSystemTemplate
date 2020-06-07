#include <stdio.h>
#include "EventSystem.h"

static void on_mouse_event(enum MouseEvent *event, struct MouseEventDetails *details)
{
	printf("Mouse Moved: New Position = (%d, %d)\n", 
			details->mousePosition[0], 
			details->mousePosition[1]);
}


int main(int argc, char **argv)
{
	struct EventSystem sys;
	event_system_init(&sys);

	struct EventListener lis_1;
	event_listener_init(&lis_1);

	event_listener_set_sys(&lis_1, &sys);
	event_listener_subscribe(&lis_1, MouseEvent, on_mouse_event);

	struct EventDispatcher dis_1;
	event_dispatcher_init(&dis_1);
	event_dispatcher_set_sys(&dis_1, &sys);

	struct Event sampleEvent = {
		.category = MouseEvent,
		.eventType.mouse = MouseMoved,
		.eventDetails.mouseEventDetails = {
			.mousePosition = {100, 100},
			.button = 0,
		},
	};


	// Finished setting up events for current frame
		event_dispatch(&dis_1, sampleEvent);
		event_system_update(&sys);
		event_system_clear(&sys);

	return 0;
}
