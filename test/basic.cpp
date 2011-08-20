#include "basic.h"
#include <FL/fl_ask.H>

BasicWin::BasicWin() : CBPlugger<BasicWin>("basic") {
	plug(push_, &BasicWin::push);
}

BasicWin::~BasicWin() {
}

void BasicWin::push() {
	fl_alert("Pushed!!!");
}
