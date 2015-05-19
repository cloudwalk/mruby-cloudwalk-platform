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
void mrb_init_network(mrb_state *mrb);
void mrb_init_gprs(mrb_state *mrb);
void mrb_init_wifi(mrb_state *mrb);

void
mrb_mruby_cloudwalk_platform_gem_init(mrb_state* mrb)
{
  mrb_system_init(mrb); DONE;
  mrb_display_init(mrb); DONE;
  mrb_magnetic_init(mrb); DONE;
  mrb_io_init(mrb); DONE;
  mrb_init_network(mrb); DONE;
  mrb_init_gprs(mrb); DONE;
  mrb_init_wifi(mrb); DONE;
  mrb_init_ethernet(mrb); DONE;
  mrb_init_print(mrb); DONE;
}

void
mrb_mruby_cloudwalk_platform_gem_final(mrb_state* mrb)
{
}