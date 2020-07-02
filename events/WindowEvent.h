#ifndef __WINDOW_EVENT_HEADER__
#define __WINDOW_EVENT_HEADER__

#include <stdbool.h>

struct Rect2D {
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
};

enum WindowEvent
{
	WindowResized,
	WindowMinimized,
	WindowMaximized,
	WindowMoved,
	WindowFullScreenToggle,
};

struct WindowEventData
{
	struct Rect2D rect;
	bool fullScreen;
};
#endif
