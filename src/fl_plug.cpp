#include "fl_plug.h"

#include <algorithm>

void SimplePlugger::bind(Fl_Widget*, void* _arg) {
	static_cast<SimplePlugger*>(_arg)->run();
}

void TextBufferPlugger::bind(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText, void* _cbArg) {
	static_cast<TextBufferPlugger*>(_cbArg)->run(_pos, _nInserted, _nDeleted, _nRestyled, _deletedText);
}


/////////////// PluggerList
PluggerList& PluggerList::instance() {
	static PluggerList list;
	return list;
}

PluggerList::PluggerList() {}

PluggerList::~PluggerList() {}

void PluggerList::add(const char*_id, Plugger* _p) {
	plugs_[_id].push_back(_p);
}

void PluggerList::remove(const char* _id) {
	pList::const_iterator pi=plugs_[_id].begin();
	while(pi != plugs_[_id].end()) {
		delete *pi;
		++pi;
	}
	plugs_.erase(_id);
}

PluggerList& getPL() {
	return PluggerList::instance();
}

