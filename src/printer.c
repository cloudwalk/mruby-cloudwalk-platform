#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

static mrb_value
mrb_platform_printer_s__open(mrb_state *mrb, mrb_value self)
{
  mrb_int ret;

  /*ret = OsPrnOpen();*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_platform_printer_s__reset(mrb_state *mrb, mrb_value self)
{
  /*OsPrnReset();*/
  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__close(mrb_state *mrb, mrb_value self)
{
  /*OsPrnClose();*/
  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__font(mrb_state *mrb, mrb_value self)
{
  mrb_value filename;
  mrb_int ret;

  mrb_get_args(mrb, "s", &filename);

  /*ret = OsPrnSetFont(RSTRING_PTR(filename))*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_platform_printer_s__level(mrb_state *mrb, mrb_value self)
{
  mrb_int level=0;

  mrb_get_args(mrb, "i", &level);
  /*OsPrnSetGray(level);*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__size(mrb_state *mrb, mrb_value self)
{
  mrb_int singlecode_width=0,singlecode_height=0,multicode_width=0,multicode_height=0;

  mrb_get_args(mrb, "iiii", &singlecode_width, &singlecode_height, &multicode_width, &multicode_height);

  /*OsPrnSelectFontSize(singlecode_width, singlecode_height, multicode_width, multicode_height);*/
  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__feed(mrb_state *mrb, mrb_value self)
{
  mrb_int size;

  mrb_get_args(mrb, "i", &size);
  /*OsPrnFeed(size);*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__print(mrb_state *mrb, mrb_value self)
{
  mrb_value buf;

  mrb_get_args(mrb, "S", &buf);
  /*OsPrnPrintf(RSTRING_PTR(buf));*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__print_bmp(mrb_state *mrb, mrb_value self)
{
  mrb_value path;

  mrb_get_args(mrb, "s", &path);

  /*OsPrnPutImage(RSTRING_PTR(path));*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__check(mrb_state *mrb, mrb_value self)
{
  mrb_int ret;

  /*ret = OsPrnCheck();*/

  return mrb_fixnum_value(ret);
}

void
mrb_print_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *print;

  platform = mrb_class_get(mrb, "Platform");
  print    = mrb_define_class_under(mrb, platform, "Printer", mrb->object_class);

  mrb_define_class_method(mrb , print , "_open"      , mrb_platform_printer_s__open      , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , print , "_reset"     , mrb_platform_printer_s__reset     , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , print , "_close"     , mrb_platform_printer_s__close     , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , print , "_font="     , mrb_platform_printer_s__font      , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_level="    , mrb_platform_printer_s__level     , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_size"      , mrb_platform_printer_s__size      , MRB_ARGS_REQ(4));
  mrb_define_class_method(mrb , print , "_feed"      , mrb_platform_printer_s__feed      , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_print"     , mrb_platform_printer_s__print     , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_print_bmp" , mrb_platform_printer_s__print_bmp , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_check"     , mrb_platform_printer_s__check     , MRB_ARGS_NONE());
}

