#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

mrb_value
mrb_platform_s_display_clear(mrb_state *mrb, mrb_value self)
{
  /*TODO Implement*/

  return mrb_nil_value();
}

mrb_value
mrb_platform_s_display_clear_line(mrb_state *mrb, mrb_value self)
{
  mrb_int line;

  mrb_get_args(mrb, "i", &line);

  /*TODO Implement*/

  return mrb_nil_value();
}

mrb_value
mrb_platform_s_print_bitmap(mrb_state *mrb, mrb_value self)
{
  mrb_value path;
  mrb_int x, y;

  mrb_get_args(mrb, "oii", &path, &y, &x);

  /*TODO Implement*/

  return mrb_nil_value();
}

void
mrb_display_init(mrb_state* mrb)
{
  struct RClass *platform;

  platform = mrb_class_get(mrb, "Platform");

  mrb_define_class_method(mrb , platform , "display_clear"      , mrb_platform_s_display_clear      , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , platform , "display_clear_line" , mrb_platform_s_display_clear_line , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , platform , "print_bitmap"       , mrb_platform_s_print_bitmap       , MRB_ARGS_REQ(3));
}
