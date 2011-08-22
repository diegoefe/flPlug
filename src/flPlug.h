#ifndef FLPLUG_FLPLUG_H_INCLUDED
#define FLPLUG_FLPLUG_H_INCLUDED

#include <FL/Fl_Widget.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Text_Buffer.H>

#include <list>

/*! @brief flPlug namespace */
namespace fl {
/*! @brief Base class for slots */
class Slot {
public:
	/*! @brief virtual destructor */
	virtual ~Slot() {}
};

/*! @brief Base slot for simple callback */
class SimpleSlot : public Slot {
public:
	/*! @brief Bind the callback to the widget */
	static void bind(Fl_Widget* _w, void* _arg);
	/*! @brief Execute the callback */
	virtual void run()=0;
};

/*! @brief Base slot for Fl_Text_Buffer callbacks */
class TextBufferSlot : public Slot {
public:
	/*! @brief Bind the callback to the widget */
	static void bind(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText, void* _cbArg);
	/*! @brief Execute the callback */
	virtual void run(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText)=0;
};

/*! @brief Slot for simple Fl_Widget's */
template<class C>
class WidgetSlot : public SimpleSlot {
public:
	/*! @brief PMF typedef */
	typedef void (C::*widgetMet)();
	/*! @brief Create and connect for Fl_Widget derived ones */
	WidgetSlot(C& _cont, Fl_Widget* _w, widgetMet _met) : cont_(_cont), met_(_met)
	{
		_w->callback(SimpleSlot::bind, this);
	}
	/*! @brief Create and connect for Fl_Menu_ derived ones */
	WidgetSlot(C& _cont, Fl_Menu_Item* _m, widgetMet _met) : cont_(_cont), met_(_met)
	{
		_m->callback(SimpleSlot::bind, this);
	}
	/*! @brief Execute the callback */
	void run() { (cont_.*met_)(); }
private:
	C& cont_;
	widgetMet met_;
};

/*! @brief Slot for simple Fl_Text_Buffer's */
template<class C>
class BufferSlot : public TextBufferSlot {
public:
	/*! @brief PMF typedef */
	typedef void (C::*bufferMet)(int, int, int, int, const char*);
	/*! @brief Create and connect */
	BufferSlot(C& _cont, Fl_Text_Buffer* _fb, bufferMet _met) : cont_(_cont), met_(_met)
	{
		_fb->add_modify_callback(TextBufferSlot::bind, this);
	}
	/*! @brief Execute the callback */
	void run(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText) {
		(cont_.*met_)(_pos, _nInserted, _nDeleted, _nRestyled, _deletedText);
	}
private:
	C& cont_;
	bufferMet met_;
};

/*! @brief List of Slot*'s */
class SlotList : private std::list<Slot*> {
public:
	SlotList() : std::list<Slot*>() {}
	~SlotList();
	/*! @brief Add a slot */
	void add(Slot* _p);
};

/*!
	@brief Slot plugger class
	@include simple.cpp
*/
template<typename Owner>
class Plugger {
	SlotList pgs_;
public:
	/*! @brief Default contructor */
	Plugger() {}
	/*! @brief Virtual destructor */
	virtual ~Plugger() {}
	/*! @brief Plug Fl_Widget* */
	void plug(Fl_Widget* _w, typename WidgetSlot<Owner>::widgetMet _me) {
		pgs_.add(new WidgetSlot<Owner>(static_cast<Owner&>(*this), _w, _me));
	}
	/*! @brief Plug Fl_Menu_Item* */
	void plug(Fl_Menu_Item* _w, typename WidgetSlot<Owner>::widgetMet _me) {
		pgs_.add(new WidgetSlot<Owner>(static_cast<Owner&>(*this), _w, _me));
	}
	/*! @brief Plug Fl_Text_Buffer* */
	void plug(Fl_Text_Buffer* _t, typename BufferSlot<Owner>::bufferMet _me) {
		pgs_.add(new BufferSlot<Owner>(static_cast<Owner&>(*this), _t, _me));
	}
};

} // fl

#endif

