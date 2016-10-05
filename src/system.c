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
mrb_system_s__serial(mrb_state *mrb, mrb_value self)
{
  char serial[128];

  memset(&serial, 0, sizeof(serial));

  /*TODO Implement*/

  return mrb_str_new_cstr(mrb, serial);
}

static mrb_value
mrb_system_s__set_backlight(mrb_state *mrb, mrb_value self)
{
  mrb_int mode;

  mrb_get_args(mrb, "i", &mode);

  /*TODO Implement*/

  return mrb_fixnum_value(mode);
}

static mrb_value
mrb_system_s__battery(mrb_state *mrb, mrb_value self)
{
  char battery[128];

  memset(&battery, 0, sizeof(battery));

  /*TODO Implement*/

  return mrb_str_new_cstr(mrb, battery);
}

static mrb_value
mrb_audio_s__beep(mrb_state *mrb, mrb_value self)
{
  mrb_int tone, milliseconds;

  mrb_get_args(mrb, "ii", &tone, &milliseconds);

  /*TODO Implement*/
  /*OsBeep(tone, milliseconds);*/

  return mrb_nil_value();
}

static mrb_value
mrb_system_s_reboot(mrb_state *mrb, mrb_value self)
{
  mrb_int ret=0;

  /*TODO Implement*/
  /*ret = OsReboot();*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_system_s_hwclock(mrb_state *mrb, mrb_value self)
{
  /*ST_TIME t;*/
  mrb_value timezone;
  mrb_int year, month, day, hour, minute, second;

  mrb_get_args(mrb, "iiiiiio", &year, &month, &day, &hour, &minute, &second, &timezone);

  /*
   *t.Year   = year;
   *t.Month  = month;
   *t.Day    = day;
   *t.Hour   = hour;
   *t.Minute = minute;
   *t.Second = second;
   */

  /*mrb_fixnum_value(OsSetTime(&t));*/
  mrb_fixnum_value(0);
}

static mrb_value
mrb_system_s_model(mrb_state *mrb, mrb_value self)
{
  char version[32]="\0";

  memset(&version, 0, sizeof(version));

  /*TODO Implement*/
  /*OsGetSysVer(TYPE_PED_VER, version);*/

  return mrb_str_new_cstr(mrb, version);
}

static mrb_value
mrb_system_s_brand(mrb_state *mrb, mrb_value self)
{
  char brand[32]="\0";

  memset(&brand, 0, sizeof(brand));

  /*TODO Implement*/

  return mrb_str_new_cstr(mrb, brand);
}

static mrb_value
mrb_system_s_os_version(mrb_state *mrb, mrb_value self)
{
  char version[32]="\0";

  memset(&version, 0, sizeof(version));

  /*TODO Implement*/

  return mrb_str_new_cstr(mrb, version);
}

static mrb_value
mrb_system_s_sdk_version(mrb_state *mrb, mrb_value self)
{
  char version[32]="\0";

  memset(&version, 0, sizeof(version));

  /*TODO Implement*/

  return mrb_str_new_cstr(mrb, version);
}

static mrb_value
mrb_system_s_pinpad_version(mrb_state *mrb, mrb_value self)
{
  char version[32]="\0";

  memset(&version, 0, sizeof(version));

  /*TODO Implement*/

  return mrb_str_new_cstr(mrb, version);
}

static mrb_value
mrb_system_s_install(mrb_state *mrb, mrb_value self)
{
  mrb_int type;
  mrb_value path, name;

  mrb_get_args(mrb, "SSi", &name, &path, &type);

  /*TODO Implement*/
  /*ret = OsInstallFile(RSTRING_PTR(name), RSTRING_PTR(path), type);*/

  return mrb_fixnum_value(0);
}

void
mrb_system_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *audio;
  struct RClass *system;

  platform = mrb_define_class(mrb, "Platform", mrb->object_class);
  audio    = mrb_define_class_under(mrb, platform, "Audio", mrb->object_class);
  system   = mrb_define_class_under(mrb, platform, "System", mrb->object_class);

  mrb_define_class_method(mrb , system , "serial"         , mrb_system_s__serial        , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "backlight="     , mrb_system_s__set_backlight , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , system , "battery"        , mrb_system_s__battery       , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , audio  , "beep"           , mrb_audio_s__beep           , MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb , system , "reboot"         , mrb_system_s_reboot         , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "hwclock"        , mrb_system_s_hwclock        , MRB_ARGS_REQ(7));
  mrb_define_class_method(mrb , system , "model"          , mrb_system_s_model          , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "brand"          , mrb_system_s_brand          , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "os_version"     , mrb_system_s_os_version     , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "sdk_version"    , mrb_system_s_sdk_version    , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "pinpad_version" , mrb_system_s_pinpad_version , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "install"        , mrb_system_s_install        , MRB_ARGS_REQ(3));
}

