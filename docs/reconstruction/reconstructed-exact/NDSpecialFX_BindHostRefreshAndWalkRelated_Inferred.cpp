// =============================================================================
// NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005829d0
// Address:   0x005829d0  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005829d0
// System:    client-fx / NDSpecialFX host bind wrapper
// Generated: 2026-07-29 W24-A OWN-ONLY dual seal
// Evidence:  decompile_function + read_memory + analyze_function_complete
// Exactness: Faithful CF / offsets / call order. Not modernization.
// =============================================================================

#include <stdint.h>

extern "C" {

// Peer dual: NDSpecialFX_BindHostAndRefresh_Inferred @ 0x00518590
void __thiscall NDSpecialFX_BindHostAndRefresh_Inferred(
    void *hostAdjusted, void *fxSession, uint32_t arg2 /*, uint32_t arg3 residual */);

// Residual OWN (W24-D): slot/related FX walk
void __thiscall FUN_004b7030(void *related, uint32_t a, uint32_t b, uint32_t c);

void __thiscall NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred(
    int hostThis,       // ECX — host object (often MI-adjusted subobject)
    void *fxSession,    // Stack[0x4]
    uint32_t arg2,      // Stack[0x8]
    uint32_t arg3)      // Stack[0xC]
{
  // MI this-adjust for BindHost (bytes):
  //   mi = *(int **)(hostThis - 0x8C)
  //   ecx = mi[1] + hostThis - 0x8C
  int *mi = *(int **)(hostThis - 0x8C);
  void *hostAdjusted = (void *)(mi[1] + hostThis - 0x8C);

  // Call site pushes arg3, arg2, fxSession — peer dual may only name 2 formals.
  (void)arg3;
  NDSpecialFX_BindHostAndRefresh_Inferred(hostAdjusted, fxSession, arg2);

  int related = *(int *)(hostThis - 0x88);
  if (related != 0) {
    // ECX = fxSession for thiscall walk
    FUN_004b7030((void *)related, 0, 0, 0xffffffff);
  }
}

void __thiscall FUN_005829d0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);

} // extern "C"
