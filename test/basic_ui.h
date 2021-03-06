// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef basic_ui_h
#define basic_ui_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include "editor.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Button.H>

class Basic_UI {
protected:
  Basic_UI();
  Fl_Double_Window *win_;
  static Fl_Menu_Item menu_[];
public:
  static Fl_Menu_Item *file_open_;
protected:
  static Fl_Menu_Item *file_debug_;
public:
  static Fl_Menu_Item *file_exit_;
protected:
  Editor *edit_;
public:
  Fl_Box *status_;
  Fl_Round_Button *op_red_;
  Fl_Round_Button *op_green_;
  Fl_Round_Button *op_blue_;
protected:
  Fl_Light_Button *push_toggle_;
  Fl_Button *push_;
public:
  virtual ~Basic_UI();
};
#endif
