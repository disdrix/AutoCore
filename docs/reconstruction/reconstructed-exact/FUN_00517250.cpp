// =============================================================================
// FUN_00517250  (twin of Object_RemovePrimaryFxEntry_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00517250
// Address:   0x00517250–0x005172c1  (114 B / 0x72)
// Dual A/B:  2026-07-29 accept (W29-N)
// Named clean: Object_RemovePrimaryFxEntry_Inferred.cpp
// =============================================================================

/*
 * Remove one NDSpecialFX* from the object primary ptr-vector (+0x124..+0x128):
 *   gate fx!=null && fx+9==0; linear search; memmove erase; end-=4;
 *   TeardownCore + operator_delete. No DeactivateClear / StopFinalize.
 *
 * thiscall; stack formal = fx*; ret 4 on all paths.
 */

#include <stdint.h>
#include <string.h>

extern void __fastcall NDSpecialFX_TeardownCore_Inferred(void *fx);
extern void __cdecl operator_delete(void *p);

void __thiscall FUN_00517250(void *self, void *fx)
{
  void **it;
  void **end;
  void *entry;
  char *base = (char *)self;
  size_t nbytes;

  if (fx == 0 || *(char *)((char *)fx + 9) != 0) {
    return;
  }

  it  = *(void ***)(base + 0x124);
  end = *(void ***)(base + 0x128);
  if (it == end) {
    return;
  }

  for (;;) {
    entry = *it;
    if (entry == fx) {
      break;
    }
    it = (void **)((char *)it + 4);
    if (it == end) {
      return;
    }
  }

  nbytes = (size_t)((*(char **)(base + 0x128) - (char *)(it + 1)) >> 2) * 4;
  memmove(it, it + 1, nbytes);
  *(char **)(base + 0x128) = *(char **)(base + 0x128) - 4;

  if (entry != 0) {
    NDSpecialFX_TeardownCore_Inferred(entry);
    operator_delete(entry);
  }
}
