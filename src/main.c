#include "stdio.h"
#include "EventSystem.h"

bool mouseEventHandler(MouseEvent *event)
{
	printf("MouseEvent Received\n");

	return true;
}

int main(int argc, char **argv)
{
	EventSystem.init();

	struct EventListener listener;

	event_listener_init(&listener);
	event_listener_subscribe(&listener, MOUSE_EVENT, mouseEventHandler);


	EventSystem.update();

	MouseEvent e = {
		.type = MOUSE_EVENT,
		.variant = MouseMoved,
		.data = {
			.mousePos_x = 100,
			.mousePos_y = 100,
		},
	};

	EventSystem.dispatch(&e);


	EventSystem.update();

	EventSystem.deinit();
	return 0;
}

