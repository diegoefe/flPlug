#include "basic.h"
#include <FL/fl_ask.H>

BasicWin::BasicWin() {
	plug(push_, &BasicWin::push);
}

BasicWin::~BasicWin() {
}

void BasicWin::push() {
	fl_alert("Pushed!!!");
}
