#ifndef BASIC_H_INCLUDED
#define BASIC_H_INCLUDED

#include "basic_ui.h"
#include "flPlug.h"

class BasicWin
	: public Basic_UI,
	  public fl::Plugger<BasicWin>
{
public:
	BasicWin();
	~BasicWin();
	void show() { win_->show(); }
private:
	void push();
};

#endif
