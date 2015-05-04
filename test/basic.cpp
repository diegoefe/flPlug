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
	push_slot_=plug(push_, &BasicWin::push);
	plug(push_toggle_, &BasicWin::push_toggle);

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
void BasicWin::push_toggle() {
	if(push_toggle_->value()) {
		push_slot_=plug(push_, &BasicWin::push);
		push_toggle_->copy_label("Disable ->");
		msg("Enabling button");
	}
	else {
		unplug(push_slot_, push_);
		push_toggle_->copy_label("Enable ->");
		msg("Disabling button");
	}
}

void BasicWin::optate(Fl_Widget* _w) {
	std::ostringstream o;
	o << "Option " << _w->label() << " selected";
	msg(o.str().c_str());
}

void BasicWin::msg(const char* _m) {
	status_->copy_label(_m);
	win_->redraw();
}

