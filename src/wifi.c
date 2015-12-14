#include "mruby.h"
#include <stddef.h>
#include <string.h>

#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/hash.h"
#include "mruby/string.h"
#include "mruby/variable.h"

#if MRUBY_RELEASE_NO < 10000
  #include "error.h"
#else
  #include "mruby/error.h"
#endif

static mrb_value
mrb_wifi_start(mrb_state *mrb, mrb_value klass)
{
  mrb_int ret=0;

  /*TODO Implement*/
  /*ret = OsWifiOpen();*/

  return mrb_fixnum_value(ret);
}

/*Turn on/off the power 1 - on 0 - off*/
static mrb_value
mrb_wifi_power(mrb_state *mrb, mrb_value klass)
{
  mrb_int state, ret;
  mrb_get_args(mrb, "i", &state);
  /*TODO Implement*/
  /*ret = OsWifiSwitchPower(state)*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_wifi_connect(mrb_state *mrb, mrb_value klass)
{
  mrb_value password, essid, bssid, channel, mode, authentication, cipher;
  const char *sPassword, *sEssid, *sBssid, *sChannel, *sCipher, *sMode, *sAuthentication;
  int timeout=60000;
  mrb_int ret = 0;

  essid = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@essid"));
  sEssid = mrb_str_to_cstr(mrb, essid);
  /*TODO Implement*/

  bssid = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@bssid"));
  sBssid = mrb_str_to_cstr(mrb, bssid);
  /*TODO Implement*/

  channel = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@channel"));
  sChannel = mrb_str_to_cstr(mrb, channel);
  /*TODO Implement*/

  mode = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@mode"));
  sMode = mrb_str_to_cstr(mrb, mode);
  /*TODO Implement*/

  authentication = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@authentication"));
  sAuthentication = mrb_str_to_cstr(mrb, authentication);
  /*TODO Implement*/

  password = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@password"));
  sPassword = mrb_str_to_cstr(mrb, password);
  /*TODO Implement*/

  cipher = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@cipher"));
  sCipher = mrb_str_to_cstr(mrb, cipher);
  /*TODO Implement*/

  /*ret = OsWifiConnect(&wifiSet, timeout);*/
  /*TODO Implement*/
  return mrb_fixnum_value(ret);
}

/*0   -> Sucess*/
/*1   -> In Progress*/
/*< 0 -> Fail*/
static mrb_value
mrb_wifi_connected_m(mrb_state *mrb, mrb_value klass)
{
  char sEssid[32+1] = "                                \0";
  char sBssid[19+1] = "                   \0";
  mrb_int iRssi, ret;

  /*TODO Implement*/
  /*ret = OsWifiCheck(&sEssid, &sBssid, &iRssi);*/

  /*TODO Implement*/
  /*if (ret == RET_OK) {*/
    /*mrb_cv_set(mrb, klass, mrb_intern_lit(mrb, "@essid"), mrb_str_new_cstr(mrb, sEssid));*/
    /*mrb_cv_set(mrb, klass, mrb_intern_lit(mrb, "@bssid"), mrb_str_new_cstr(mrb, sBssid));*/
    /*mrb_cv_set(mrb, klass, mrb_intern_lit(mrb, "@rssi"), mrb_fixnum_value(iRssi));*/
  /*}*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_wifi_disconnect(mrb_state *mrb, mrb_value klass)
{
  mrb_int ret=0;

  /*TODO Implement*/
  /*ret = OsWifiDisconnect();*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_wifi__scan(mrb_state *mrb, mrb_value klass)
{
  /*TODO Implement*/
  /*ST_WifiApInfo * aps;*/
  mrb_int ret = 0, i = 0;

  /*ret = OsWifiScan(&aps);*/

  if (ret < 0) return mrb_false_value();

  /*for (i=0;i < ret;i++) {*/
    /*mrb_funcall(mrb, klass, "ap", 7,*/
        /*mrb_str_new_cstr(mrb, aps[i].Essid),*/
        /*mrb_str_new_cstr(mrb, aps[i].Bssid),*/
        /*mrb_fixnum_value(aps[i].Channel),*/
        /*mrb_fixnum_value(aps[i].Mode),*/
        /*mrb_fixnum_value(aps[i].Rssi),*/
        /*mrb_fixnum_value(aps[i].AuthMode),*/
        /*mrb_fixnum_value(aps[i].SecMode)*/
        /*);*/
  /*}*/
  return mrb_true_value();
}

void
mrb_wifi_init(mrb_state *mrb)
{
  struct RClass *platform, *network, *wifi;

  platform = mrb_class_get(mrb, "Platform");
  network  = mrb_class_get_under(mrb, platform, "Network");
  wifi     = mrb_define_class_under(mrb, network, "Wifi", mrb->object_class);

  mrb_define_class_method(mrb, wifi, "start", mrb_wifi_start, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, wifi, "power", mrb_wifi_power, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, wifi, "connect", mrb_wifi_connect, MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, wifi, "connected?", mrb_wifi_connected_m, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, wifi, "disconnect", mrb_wifi_disconnect, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, wifi, "_scan", mrb_wifi__scan, MRB_ARGS_NONE());
}

