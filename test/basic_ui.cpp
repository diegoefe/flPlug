// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include "basic_ui.h"

Fl_Menu_Item Basic_UI::menu_[] = {
 {"&File", 0,  0, 0, 64, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"&Open", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"&Debug", 0,  0, 0, 6, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {"&Exit", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};
Fl_Menu_Item* Basic_UI::file_open_ = Basic_UI::menu_ + 1;
Fl_Menu_Item* Basic_UI::file_debug_ = Basic_UI::menu_ + 2;
Fl_Menu_Item* Basic_UI::file_exit_ = Basic_UI::menu_ + 3;

Basic_UI::Basic_UI() {
  { win_ = new Fl_Double_Window(550, 270, "Basic test");
    win_->box(FL_PLASTIC_UP_BOX);
    win_->user_data((void*)(this));
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 551, 20);
      o->menu(menu_);
    } // Fl_Menu_Bar* o
    { edit_ = new Editor(10, 25, 535, 190);
      edit_->box(FL_DOWN_FRAME);
      edit_->color(FL_BACKGROUND2_COLOR);
      edit_->selection_color(FL_SELECTION_COLOR);
      edit_->labeltype(FL_NORMAL_LABEL);
      edit_->labelfont(0);
      edit_->labelsize(14);
      edit_->labelcolor(FL_FOREGROUND_COLOR);
      edit_->align(Fl_Align(FL_ALIGN_TOP));
      edit_->when(FL_WHEN_RELEASE_ALWAYS);
    } // Editor* edit_
    { status_ = new Fl_Box(4, 250, 541, 17);
      status_->box(FL_GTK_THIN_DOWN_FRAME);
      status_->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
    } // Fl_Box* status_
    { Fl_Group* o = new Fl_Group(10, 220, 180, 25);
      o->box(FL_PLASTIC_DOWN_FRAME);
      { op_red_ = new Fl_Round_Button(17, 223, 50, 21, "Red");
        op_red_->type(102);
        op_red_->down_box(FL_ROUND_DOWN_BOX);
      } // Fl_Round_Button* op_red_
      { op_green_ = new Fl_Round_Button(69, 223, 65, 21, "Green");
        op_green_->type(102);
        op_green_->down_box(FL_ROUND_DOWN_BOX);
      } // Fl_Round_Button* op_green_
      { op_blue_ = new Fl_Round_Button(136, 223, 50, 21, "Blue");
        op_blue_->type(102);
        op_blue_->down_box(FL_ROUND_DOWN_BOX);
      } // Fl_Round_Button* op_blue_
      o->end();
    } // Fl_Group* o
    { push_toggle_ = new Fl_Light_Button(358, 221, 90, 25, "Disable ->");
      push_toggle_->value(1);
      push_toggle_->selection_color((Fl_Color)97);
    } // Fl_Light_Button* push_toggle_
    { push_ = new Fl_Button(455, 221, 89, 25, "Push me!");
    } // Fl_Button* push_
    win_->set_modal();
    win_->size_range(280, 157);
    win_->end();
    win_->resizable(win_);
  } // Fl_Double_Window* win_
}

Basic_UI::~Basic_UI() {
  delete win_;
}
