#ifndef BASIC_H_INCLUDED
#define BASIC_H_INCLUDED

#include "basic_ui.h"
#include "fl_plug.h"

class BasicWin
	: public Basic_UI,
	  public CBPlugger<BasicWin>
{
public:
	BasicWin();
	~BasicWin();
	void show() { win_->show(); }
private:
	void push();
};

#endif
