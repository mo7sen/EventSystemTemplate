#ifndef __EVENT_HEADER__
#define __EVENT_HEADER__

#include "events/MouseEvent.h"
#include "events/KeyEvent.h"
#include "events/WindowEvent.h"

enum EventCategory
{
	KeyEvent,
	MouseEvent,
	WindowEvent,
	
	// Very Important!!!
	// Any new EventTypes should be added before EVENT_TYPE_COUNT
	EVENT_TYPE_COUNT,
	// Never add anything in this area
};

struct Event
{
	enum EventCategory category;
	union {
		enum MouseEvent mouse;
		enum KeyEvent keyboard;
		enum WindowEvent window;
	} eventType;
	union {
		struct MouseEventData mouseEventData;
		struct KeyEventData keyEventData;
		struct WindowEventData windowEventData;
	} eventDetails;
};

#endif
