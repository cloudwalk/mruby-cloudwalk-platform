#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

#define DONE mrb_gc_arena_restore(mrb, 0)

void mrb_system_init(mrb_state *mrb);
void mrb_display_init(mrb_state *mrb);
void mrb_magnetic_init(mrb_state *mrb);
void mrb_network_init(mrb_state *mrb);
void mrb_gprs_init(mrb_state *mrb);
void mrb_wifi_init(mrb_state *mrb);
void mrb_io_init(mrb_state *mrb);
void mrb_ethernet_init(mrb_state *mrb);
void mrb_print_init(mrb_state *mrb);

void
mrb_mruby_cloudwalk_platform_gem_init(mrb_state* mrb)
{
  mrb_system_init(mrb); DONE;
  mrb_display_init(mrb); DONE;
  mrb_magnetic_init(mrb); DONE;
  mrb_io_init(mrb); DONE;
  mrb_network_init(mrb); DONE;
  mrb_gprs_init(mrb); DONE;
  mrb_wifi_init(mrb); DONE;
  mrb_ethernet_init(mrb); DONE;
  mrb_print_init(mrb); DONE;
}

void
mrb_mruby_cloudwalk_platform_gem_final(mrb_state* mrb)
{
}

