#ifndef __KEY_EVENT_HEADER__
#define __KEY_EVENT_HEADER__
typedef unsigned int KeyCode;

enum KeyEvent
{
	KeyPressed,
	KeyReleased,
};

struct KeyEventData
{
	KeyCode keyCode;
	unsigned int repeatCount;
};
#endif
