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

void
mrb_display_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *display;

  platform = mrb_class_get(mrb, "Platform");
  display = mrb_define_class(mrb, "Display", platform);

  mrb_define_class_method(mrb , display , "clear"        , mrb_display_s_clear       , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , display , "clear_line"   , mrb_display_s_clear_line  , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , display , "print_bitmap" , mrb_display_s_print_bitmap , MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb , display , "print_line"   , mrb_display_s_print_line   , MRB_ARGS_REQ(3));
}
