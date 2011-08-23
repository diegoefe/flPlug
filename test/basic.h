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
	void file_open();
	void file_exit();
	void edit(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText);
	void push();
};

#endif
