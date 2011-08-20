#ifndef QRYLGUI_GUI_CBP_H_INCLUIDO
#define QRYLGUI_GUI_CBP_H_INCLUIDO

#include <FL/Fl_Widget.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Text_Buffer.H>

#include <list>
#include <map>

class Plugger {
public:
	virtual ~Plugger() {}
};

class SimplePlugger : public Plugger {
public:
	static void bind(Fl_Widget* _w, void* _arg);
	virtual void run()=0;
};

class TextBufferPlugger : public Plugger {
public:
	static void bind(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText, void* _cbArg);
	virtual void run(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText)=0;
};

template<class C>
class WidgetPlugger : public SimplePlugger {
public:
	typedef void (C::*widgetMet)();
	WidgetPlugger(C& _cont, Fl_Widget* _w, widgetMet _met) : cont_(_cont), met_(_met)
	{
		_w->callback(SimplePlugger::bind, this);
	}
	WidgetPlugger(C& _cont, Fl_Menu_Item* _m, widgetMet _met) : cont_(_cont), met_(_met)
	{
		_m->callback(SimplePlugger::bind, this);
	}
	void run() { (cont_.*met_)(); }
private:
	C& cont_;
	widgetMet met_;
};

template<class C>
class BufferPlugger : public TextBufferPlugger {
public:
	typedef void (C::*bufferMet)(int, int, int, int, const char*);
	BufferPlugger(C& _cont, Fl_Text_Buffer* _fb, bufferMet _met) : cont_(_cont), met_(_met)
	{
		_fb->add_modify_callback(TextBufferPlugger::bind, this);
	}
	void run(int _pos, int _nInserted, int _nDeleted, int _nRestyled, const char* _deletedText) {
		(cont_.*met_)(_pos, _nInserted, _nDeleted, _nRestyled, _deletedText);
	}
private:
	C& cont_;
	bufferMet met_;
};

class PluggerList {
	typedef std::list<Plugger*> pList;
	typedef std::map<const char*,pList> pMap;
	static PluggerList& instance();
public:
	~PluggerList();
	void add(const char* _id, Plugger* _p);
	void remove(const char* _id);
private:
	PluggerList();
	pMap plugs_;
	friend PluggerList& getPL();
};

PluggerList& getPL();

template<typename Owner>
class CBPlugger {
	const char* id_;
public:
	CBPlugger(const char* _id) : id_(_id) {}
	virtual ~CBPlugger() { getPL().remove(id_); }
	void plug(Fl_Widget* _w, typename WidgetPlugger<Owner>::widgetMet _me) {
		getPL().add(id_, new WidgetPlugger<Owner>(static_cast<Owner&>(*this), _w, _me));
	}
	void plug(Fl_Menu_Item* _w, typename WidgetPlugger<Owner>::widgetMet _me) {
		getPL().add(id_, new WidgetPlugger<Owner>(static_cast<Owner&>(*this), _w, _me));
	}
	void plug(Fl_Text_Buffer* _t, typename BufferPlugger<Owner>::bufferMet _me) {
		getPL().add(id_, new BufferPlugger<Owner>(static_cast<Owner&>(*this), _t, _me));
	}
};

#endif
