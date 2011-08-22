// sample code

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include "flPlug.h" // include definitions

// My window
class MyWin
	: public Fl_Double_Window,
	  public fl::Plugger<MyWin> // template inheritance
{
public:
	MyWin(int _x, int _y, int _w, int _h, const char* _l=0)
		: Fl_Double_Window(_x, _y, _w, _h, _l)
	{
		Fl_Button* b=new Fl_Button(5,5,_w-10,_h-10, "Push me!");
		add(b);
		// connect the callback
		plug(b, &MyWin::push);
		end();
	}
private:
	// calback can be private
	void push() { fl_alert("Pushed!"); }
};

int main() {
	MyWin w(50,50,200, 50, "Simple Test");
	w.show();
	return Fl::run();
}
