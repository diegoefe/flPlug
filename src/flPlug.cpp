#include "flPlug.h"
#include <algorithm>
#include <iostream>

namespace fl {

void SimpleSlot::bind(Fl_Widget*, void* _arg) {	static_cast<SimpleSlot*>(_arg)->run();}
void ParamSlot::bind(Fl_Widget* _w, void* _arg) { static_cast<ParamSlot*>(_arg)->run(_w); }
void MenuParamSlot::bind(Fl_Widget* _mi, void* _arg) {
   MenuParamSlot* mps = static_cast<MenuParamSlot*>(_arg);
   mps->run(mps->mi_);
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

Slot* SlotList::add(Slot* _slot) {
	push_back(_slot);
	return back();
}

namespace { void dummyCallback(Fl_Widget*, void*) { } }

void SlotList::remove(Slot* _slot, Fl_Widget* _widget) {
	SlotList::iterator s=find(begin(), end(), _slot);
	if(s != end()) {
		erase(s);
		delete _slot;
		_widget->callback(dummyCallback);
	}
}

} // fl

