# <p style="text-align: center;">Adding new Event Categories</p>

First things first, you'll need to define the event variants. This can be done by creating
a `SampleEvent.h` in the 'events/' directory. In this header file, we'll have an `enum`
and a `struct`.

```
// Sample enum
enum SampleEvent
{
	// This should include all possible events for a
	// specific event category
	SampleEventVariant1,
	SampleEventVariant2,
	SampleEventVariant3,
}

struct SampleEventDetails
{
	// This should have any extra details that need to be
	// bundled with the event for it to be useful
	int sampleInt;
	double sampleDouble;
};

```

After that, you go to the `Event.h` header file and start editing the `EventCategory` and
`Event` values.

You start by including your new event.
```
// Other Includes
#include "events/SampleEvent.h"
```

Then, to make it a recognizable category, add it to the `EventCategory` enum.
```
enum EventCategory
{
	// Other Categories
	SampleEvent,

	// Very Important!!!
	// Any new EventTypes should be added before EVENT_TYPE_COUNT
	EVENT_TYPE_COUNT,
	// Never add anything in this area
}
```

The `Event` struct will also need to be edited:
```
struct Event
{
	enum EventCategory category;
	union {
		enum SampleEvent sample;
	} eventType;
	union {
		struct SampleEventDetails sampleEventDetails;
	}
}
```

That should be it.
N.B: Not sure about whether this is all that needs to be done as I was too lazy to test it :D
