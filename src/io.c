#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

static mrb_value
mrb_platform_io_s__getc(mrb_state *mrb, mrb_value self)
{
  mrb_int timeout=0, key;

  mrb_get_args(mrb, "i", &timeout);

  /*key = GetKey(timeout);*/

  return mrb_fixnum_value(key);
}

/*
@param min [int]: Minimum number of characters to press.
@param max [int]: Maximum number of characters to press.
@param mode [int]: Mask to be used password, only numbers, only letters and etc.
@param y [int]: Y value, line to press.
@param x [int]: X value, row to press.
*/
static mrb_value
mrb_platform_io_s__gets(mrb_state *mrb, mrb_value self)
{
  unsigned char sValue[128];
  mrb_int min, max, mode, x, y;

  memset(&sValue, 0, sizeof(sValue));

  mrb_get_args(mrb, "iiiii", &min, &max, &mode, &y, &x);

  /*get_string(&sValue, min, max, mode, y, x);*/

  return mrb_str_new_cstr(mrb, sValue);
}

void
mrb_io_init(mrb_state* mrb)
{
  struct RClass *io;

  io = mrb_class_get(mrb, "IO");

  mrb_define_class_method(mrb , io , "_getc" , mrb_platform_io_s__getc , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , io , "_gets" , mrb_platform_io_s__gets , MRB_ARGS_REQ(5));
}
