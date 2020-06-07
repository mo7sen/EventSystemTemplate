#ifndef __EVENT_HEADER__
#define __EVENT_HEADER__

#include "events/MouseEvent.h"
#include "events/KeyboardEvent.h"
#include "events/WindowEvent.h"

enum EventCategory
{
	KeyboardEvent,
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
		enum KeyboardEvent keyboard;
		enum WindowEvent window;
	} eventType;
	union {
		struct MouseEventDetails mouseEventDetails;
		struct KeyboardEventDetails keyboardEventDetails;
		struct WindowEventDetails windowEventDetails;
	} eventDetails;
};

#endif
