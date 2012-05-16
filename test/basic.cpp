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

	plug(op_red_, &BasicWin::optate);
	plug(op_green_, &BasicWin::optate);
	plug(op_blue_, &BasicWin::optate);

	edit_->take_focus();
}

BasicWin::~BasicWin() {}

void BasicWin::file_open() { msg("File open!!!"); }
void BasicWin::file_exit() { win_->hide(); }
void BasicWin::edit(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText)
{
	std::ostringstream o;
	o << "pos(" << _pos << ")";
	o << " ins(" << _nInserted << ")";
	o << " del(" << _nDeleted << ")";
	o << " sty(" << _nRestyled << ")";
	o << " del-text(" << (_deletedText ? _deletedText : "NULL") << ")";
	msg(o.str().c_str());
}

void BasicWin::push() {	fl_alert("Pushed!!!"); }

void BasicWin::optate(Fl_Widget* _w) {
	std::ostringstream o;
	o << "Option " << _w->label() << " selected";
	msg(o.str().c_str());
}

void BasicWin::msg(const char* _m) {
	status_->copy_label(_m);
	win_->redraw();
}

