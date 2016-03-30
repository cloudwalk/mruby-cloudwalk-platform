#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

mrb_value
mrb_display_s_clear(mrb_state *mrb, mrb_value self)
{
  /*TODO Implement*/

  return mrb_nil_value();
}

mrb_value
mrb_display_s_clear_line(mrb_state *mrb, mrb_value self)
{
  mrb_int line;

  mrb_get_args(mrb, "i", &line);

  /*TODO Implement*/

  return mrb_nil_value();
}

mrb_value
mrb_display_s_print_bitmap(mrb_state *mrb, mrb_value self)
{
  mrb_value path;
  mrb_int x, y;

  mrb_get_args(mrb, "oii", &path, &y, &x);

  /*TODO Implement*/

  return mrb_nil_value();
}

mrb_value
mrb_display_s_print_line(mrb_state *mrb, mrb_value self)
{
  mrb_value buf;
  mrb_int x, y;

  mrb_get_args(mrb, "oii", &buf, &y, &x);

  /*TODO Implement*/

  return mrb_nil_value();
}

mrb_value
mrb_display_s_print_status_bar(mrb_state *mrb, mrb_value self)
{
  mrb_value path;
  mrb_int slot = 0;

  mrb_get_args(mrb, "io", &slot, &path);

  /*TODO Implement*/
  /*if (mrb_string_p(path)) {*/
    /*if (XuiSetStatusbarIcon(slot, RSTRING_PTR(path)) == 0)*/
      /*return mrb_true_value();*/
    /*else*/
      /*return mrb_nil_value();*/
  /*} else {*/
    /*if (XuiSetStatusbarIcon(slot, NULL) == 0)*/
      /*return mrb_true_value();*/
    /*else*/
      /*return mrb_nil_value();*/
    /*return mrb_nil_value();*/
  /*}*/
  return mrb_nil_value();
}

mrb_value
mrb_display_s_status_bar_slots_available(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(8);
}

void
mrb_display_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *display;

  platform = mrb_class_get(mrb, "Platform");
  display = mrb_define_class_under(mrb, platform, "Display", mrb->object_class);

  mrb_define_class_method(mrb , display , "clear"                      , mrb_display_s_clear                      , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , display , "clear_line"                 , mrb_display_s_clear_line                 , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , display , "print_bitmap"               , mrb_display_s_print_bitmap               , MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb , display , "print_line"                 , mrb_display_s_print_line                 , MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb , display , "print_status_bar"           , mrb_display_s_print_status_bar           , MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb , display , "status_bar_slots_available" , mrb_display_s_status_bar_slots_available , MRB_ARGS_NONE());
}
