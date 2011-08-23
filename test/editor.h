#ifndef EDITOR_H_INCLUDED
#define EDITOR_H_INCLUDED

#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>

class Editor : public Fl_Text_Editor {
public:
	Editor(int _x, int _y, int _w, int _h, const char* _l=0)
		: Fl_Text_Editor(_x, _y, _w, _h, _l)
	{
		buffer(new Fl_Text_Buffer); // does this leak?!
	}
	~Editor() {}
};

#endif
