#ifndef __KEYBOARD_EVENT_HEADER__
#define __KEYBOARD_EVENT_HEADER__
typedef unsigned int KeyCode;

enum KeyboardEvent
{
	KeyPressed,
	KeyReleased,
};

struct KeyboardEventDetails
{
	KeyCode keyCode;
};
#endif
