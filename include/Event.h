#ifndef EVENT_CONFIG_H
#define EVENT_CONFIG_H

#define INITIAL_EVENT_BUFFER_CAPACITY 200
#define EVENT_SIZE 64 // Should always be a multiple of 8 for alignment (not supporting 32 bits)

#include "generated_config.h"

#ifdef GENERATED_EVENT_INCLUDES
#include GENERATED_EVENT_INCLUDES
#endif

enum EventType {

#ifdef GENERATED_EVENT_TYPES
#include GENERATED_EVENT_TYPES
#endif

	// this needs to always be the last variant in the enum
	EVENT_TYPE_COUNT,
};

#endif
