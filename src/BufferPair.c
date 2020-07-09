#include "BufferPair.h"

void event_buffer_pair_init(struct BufferPair *pair)
{
	pair->read = &pair->_primary;
	pair->write = &pair->_secondary;
	pair->read_primary = true;

	event_buffer_init(pair->read);
	event_buffer_init(pair->write);
}

void event_buffer_pair_deinit(struct BufferPair *pair)
{
	event_buffer_deinit(pair->read);
	event_buffer_deinit(pair->write);
}

unsigned int event_buffer_pair_add_event(struct BufferPair *pair, void *event)
{
	return event_buffer_add(pair->write, event);
}

void event_buffer_pair_swap(struct BufferPair *pair)
{
	pair->read = (pair->read_primary)?&pair->_secondary:&pair->_primary;
	pair->write = (pair->read_primary)?&pair->_primary:&pair->_secondary;

	pair->read_primary = !pair->read_primary;
}

void event_buffer_pair_clear_read(struct BufferPair *pair)
{
	event_buffer_clear(pair->read);
}
