#ifndef __EVENT_HEADER__
#define __EVENT_HEADER__

#include "cmake_config.h"

#ifdef GENERATED_EVENT_HEADERS
#include GENERATED_EVENT_HEADERS
#endif

enum EventCategory
{
#ifdef GENERATED_EVENT_CATEGORIES
#include GENERATED_EVENT_CATEGORIES
#endif
	
	// Very Important!!!
	// Any new EventTypes should be added before EVENT_TYPE_COUNT
	EVENT_TYPE_COUNT,
	// Never add anything in this area
};

struct Event
{
	enum EventCategory category;
	union {
#ifdef GENERATED_EVENT_TYPES
#include GENERATED_EVENT_TYPES
#endif
	} eventType;
	union {
#ifdef GENERATED_EVENT_DATAS
#include GENERATED_EVENT_DATAS
#endif
	} eventDetails;
};

#endif
