// =============================================================================
// FUN_005179e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005179e0
// Address:   0x005179e0–0x00517a6a  (139 B / 0x8B)
// System:    client-fx / object-owned NDSpecialFX ptr-vector teardown
// Generated: 2026-07-29 W28-H (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte corrections.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named alias: Object_TeardownOwnedFxLists_Inferred.cpp
// =============================================================================

#include <stdint.h>

extern void __fastcall FUN_00516930(void *self, int stack_arg);
extern void __thiscall FUN_00517250(void *self, void *fx);
extern uint8_t __fastcall FUN_004ba0a0(void *fx);
extern void __fastcall FUN_004b99c0(void *fx);
extern void __cdecl operator_delete(void *p);

void __thiscall FUN_005179e0(void *self)
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
      if (*(char *)((char *)fx + 9) == 0 && FUN_004ba0a0(fx) != 0) {
        FUN_004b99c0(fx);
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
