#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

#define DONE mrb_gc_arena_restore(mrb, 0)

void
mrb_mruby_cloudwalk_platform_gem_init(mrb_state* mrb)
{
  mrb_system_init(mrb);
  mrb_display_init(mrb);
  mrb_magnetic_init(mrb);
  mrb_emv_init(mrb);
}

void
mrb_mruby_clouwalk_platform_gem_final(mrb_state* mrb)
{
}