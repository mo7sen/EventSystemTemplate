#ifndef __WINDOW_EVENT_HEADER__
#define __WINDOW_EVENT_HEADER__
typedef unsigned int WindowSize[2];

enum WindowEvent
{
	WindowResized,
	WindowMinimized,
};

struct WindowEventDetails
{
	WindowSize windowSize;
};
#endif
