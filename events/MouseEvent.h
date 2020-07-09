#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

enum MouseEventVariant {
	MouseButtonClicked,
	MouseButtonReleased,
	MouseMoved,
};

typedef unsigned int MouseButtonKeyCode;


typedef struct {
	unsigned int mousePos_x;
	unsigned int mousePos_y;

	MouseButtonKeyCode button;
} MouseEventData;

typedef struct {
	unsigned int type;
	enum MouseEventVariant variant;
	MouseEventData data;
} MouseEvent;
#endif
