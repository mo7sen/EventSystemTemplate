#ifndef __MOUSE_EVENT_HEADER__
#define __MOUSE_EVENT_HEADER__
typedef unsigned int MouseButtonID;
typedef unsigned int MousePosition[2];

enum MouseEvent
{
	MouseMoved,
	MouseButtonPressed,
	MouseButtonReleased,
};

struct MouseEventDetails
{
	MousePosition mousePosition;
	MouseButtonID button;
};
#endif
