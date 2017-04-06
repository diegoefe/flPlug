# flPlug
C++ Library that provides a type-safe interface for the event callback system of the Fast Light ToolKit (FLTK) library

The FLTK's callback system is a powerful mechanism but suffers for some
comfortless features that flPlug tries to easy:
- The callbacks have to be global functions, not object member functions
- The interface for callbacks is not type-safe (you have to cast the parameters
	to/from void* to use external data)

flPlug has been tested with FLTK versions 1.1.* and 1.3.*.

## Sample usage

``` C++
    #include <FL/Fl.H>
    #include <FL/Fl_Double_Window.H>
    #include <FL/Fl_Button.H>
    #include <FL/Fl_Radio_Button.H>
    #include <FL/Fl_Box.H>
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
    		Fl_Group* g=new Fl_Group(5, 5, _w-10, 24);
    		g->box(FL_EMBOSSED_FRAME);
    		g->begin();
    		Fl_Radio_Button* b_red=new Fl_Radio_Button(6, 7, 50, 20, "Red");
    		Fl_Radio_Button* b_green=new Fl_Radio_Button(60, 7, 65, 20, "Green");
    		Fl_Radio_Button* b_blue=new Fl_Radio_Button(125, 7, 55, 20, "Blue");
    		g->end();
    		Fl_Button* b=new Fl_Button(5,_h-43,_w-10, 20, "Pushme!");
    		msg_=new Fl_Box(5,_h-23,_w-10, 20);
    		msg_->box(FL_THIN_DOWN_FRAME);
    		msg_->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    		// connect the callbacks
    		plug(b, &MyWin::push);
    		for(int i=0; i<g->children(); ++i) {
    			plug(g->child(i), &MyWin::optate);
    		}
    		end();
    	}
    private:
    	// calback can be private
    	void push() { msg("Pushed!"); }
    	void optate(Fl_Widget* _w) { msg(_w->label()); }
    	void msg(const char* _m) {
    		msg_->label(_m);
    		redraw();
    	}
    	Fl_Box* msg_;
    };
    
    int main() {
    	MyWin w(50,50,190, 75, "Simple Test");
    	w.show();
    	return Fl::run();
}
```
Happy coding!


## License
[LGPL](doc/LICENSE.txt)
