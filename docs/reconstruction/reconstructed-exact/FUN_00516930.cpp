// =============================================================================
// FUN_00516930  (twin of Object_TeardownSecondaryFxList_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00516930
// Address:   0x00516930–0x005169a8  (121 B / 0x79)
// Dual A/B:  2026-07-29 accept (W29-N)
// Named clean: Object_TeardownSecondaryFxList_Inferred.cpp
// =============================================================================

/*
 * Secondary object-owned NDSpecialFX pointer-vector teardown:
 *   walk +0x138..+0x13c; DeactivateClear each; TeardownCore+delete if non-null;
 *   clear host+0x184 bit2; free begin buffer; always zero +0x138/+0x13c/+0x140.
 *
 * thiscall + 1 unused stack dword (ret 4). Callers push 0 (owned teardown) or 1
 * (FUN_00518370 mission FX path). Body never loads the stack formal.
 *
 * Decompiler false-noreturn on operator_delete omitted post-free triad zero — restored.
 */

#include <stdint.h>

extern void __fastcall NDSpecialFX_DeactivateClear_Inferred(void *fx);
extern void __fastcall NDSpecialFX_TeardownCore_Inferred(void *fx);
extern void __cdecl operator_delete(void *p);

void __thiscall FUN_00516930(void *self, int unused_stack)
{
  void **it;
  void **end;
  void *fx;
  char *base = (char *)self;
  (void)unused_stack;

  it  = *(void ***)(base + 0x138);
  end = *(void ***)(base + 0x13c);
  if (it != end) {
    do {
      fx = *it;
      NDSpecialFX_DeactivateClear_Inferred(fx);
      if (fx != 0) {
        NDSpecialFX_TeardownCore_Inferred(fx);
        operator_delete(fx);
      }
      it = (void **)((char *)it + 4);
    } while (it != *(void ***)(base + 0x13c));
  }

  *(uint32_t *)(base + 0x184) &= (uint32_t)~4u;

  if (*(void **)(base + 0x138) != 0) {
    operator_delete(*(void **)(base + 0x138));
  }

  *(void **)(base + 0x138) = 0;
  *(void **)(base + 0x13c) = 0;
  *(void **)(base + 0x140) = 0;
}
