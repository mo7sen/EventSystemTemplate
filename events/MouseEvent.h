#ifndef __MOUSE_EVENT_HEADER__
#define __MOUSE_EVENT_HEADER__

typedef unsigned int MouseButtonID;

enum MouseEvent
{
	MouseMoved,
	MouseButtonPressed,
	MouseButtonReleased,
	MouseScrolled,
};

struct MouseEventData
{
	unsigned int mousePosition_x;
	unsigned int mousePosition_y;
	MouseButtonID button;
};
#endif
