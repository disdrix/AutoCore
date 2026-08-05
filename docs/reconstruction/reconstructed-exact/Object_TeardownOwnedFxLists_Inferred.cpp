// =============================================================================
// Object_TeardownOwnedFxLists_Inferred  (named alias of FUN_005179e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005179e0
// Address:   0x005179e0–0x00517a6a  (139 B / 0x8B)
// Dual A/B:  2026-07-29 accept (W28-H)
// Authoritative clean twin: FUN_005179e0.cpp
// =============================================================================

/*
 * Object-owned NDSpecialFX pointer-vector teardown:
 *   1) nested secondary vector FUN_00516930(this, 0) at +0x138 family
 *   2) optional single-remove of sticky +0x130 via FUN_00517250
 *   3) walk primary +0x124..+0x128; free when fx+9==0 && StopFinalize != 0
 *   4) free vector storage; always zero +0x124/+0x128/+0x12c
 *
 * thiscall; virtual (vtable DATA) + direct CODE callers; plain ret.
 * Decompiler false-noreturn on operator_delete omitted post-free zeroing — restored.
 */

#include <stdint.h>

extern void __fastcall FUN_00516930(void *self, int stack_arg);
extern void __thiscall FUN_00517250(void *self, void *fx);
extern uint8_t __fastcall NDSpecialFX_StopFinalize_Inferred(void *fx);
extern void __fastcall NDSpecialFX_TeardownCore_Inferred(void *fx);
extern void __cdecl operator_delete(void *p);

void __thiscall Object_TeardownOwnedFxLists_Inferred(void *self)
{
  void **it;
  void **end;
  void *fx;
  char *base = (char *)self;

  FUN_00516930(self, 0);

  if (*(void **)(base + 0x130) != 0) {
    FUN_00517250(self, *(void **)(base + 0x130));
  }

  *(void **)(base + 0x130) = 0;

  it  = *(void ***)(base + 0x124);
  end = *(void ***)(base + 0x128);
  if (it != end) {
    do {
      fx = *it;
      if (*(char *)((char *)fx + 9) == 0 &&
          NDSpecialFX_StopFinalize_Inferred(fx) != 0) {
        NDSpecialFX_TeardownCore_Inferred(fx);
        operator_delete(fx);
      }
      it = (void **)((char *)it + 4);
    } while (it != *(void ***)(base + 0x128));
  }

  if (*(void **)(base + 0x124) != 0) {
    operator_delete(*(void **)(base + 0x124));
  }

  *(void **)(base + 0x124) = 0;
  *(void **)(base + 0x128) = 0;
  *(void **)(base + 0x12c) = 0;
}
