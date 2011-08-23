#include "basic.h"
#include <FL/fl_ask.H>
#include <sstream>

BasicWin::BasicWin() {
	// we can plug menu items
	plug(file_open_, &BasicWin::file_open);
	plug(file_exit_, &BasicWin::file_exit);
	// we can also plug text buffer
	plug(edit_->buffer(), &BasicWin::edit);
	// we can also plug buttons
	plug(push_, &BasicWin::push);

	edit_->take_focus();
}

BasicWin::~BasicWin() {}

void BasicWin::file_open() { fl_alert("File open!!!"); }
void BasicWin::file_exit() { win_->hide(); }
void BasicWin::edit(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText)
{
	std::ostringstream o;
	o << "pos(" << _pos << ")";
	o << " ins(" << _nInserted << ")";
	o << " del(" << _nDeleted << ")";
	o << " sty(" << _nRestyled << ")";
	o << " del-text(" << (_deletedText ? _deletedText : "NULL") << ")";
	status_->copy_label(o.str().c_str());
	win_->redraw();
}

void BasicWin::push() {	fl_alert("Pushed!!!"); }
