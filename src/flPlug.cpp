#include "flPlug.h"

namespace fl {

void SimpleSlot::bind(Fl_Widget*, void* _arg) {
	static_cast<SimpleSlot*>(_arg)->run();
}

void ParamSlot::bind(Fl_Widget* _w, void* _arg) {
	static_cast<ParamSlot*>(_arg)->run(_w);
}

void TextBufferSlot::bind(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText, void* _cbArg) {
	static_cast<TextBufferSlot*>(_cbArg)->run(_pos, _nInserted, _nDeleted, _nRestyled, _deletedText);
}

SlotList::~SlotList() {
	SlotList::const_iterator pi=begin();
	while(pi != end()) {
		delete *pi;
		++pi;
	}
}

void SlotList::add(Slot* _p) {
	push_back(_p);
}

} // fl

