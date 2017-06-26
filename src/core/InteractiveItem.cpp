#include "InteractiveItem.hpp"

namespace core {
	__int32 InteractiveItem::gID = 0;

	InteractiveItem::InteractiveItem() : ID(gID++) {}
	InteractiveItem::~InteractiveItem() {}
}