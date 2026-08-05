// =============================================================================
// FUN_005829d0  /  NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005829d0
// Address:   0x005829d0 – 0x00582a10  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX host bind wrapper
// Generated: 2026-07-29 W24-A dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   1) Call FUN_00518590 (BindHostAndRefresh) with MI-adjusted host this.
//   2) If *(this-0x88) != 0, FUN_004b7030(related, 0, 0, -1) with ECX=param_2.
//
// ABI: thiscall host (param_1/ECX); 3 stack formals; ret 0xC.
// Bytes seal MI lea at this-0x8C before BindHost; walk ECX=param_2.
// Prior alias Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_005829d0 is too narrow.
// =============================================================================

#include <stdint.h>

extern "C" {

// Peer dual aa_00518590 — NDSpecialFX_BindHostAndRefresh_Inferred
// Wrapper call site pushes 3 stack dwords; peer dual documents 2 formals (residual).
void __thiscall FUN_00518590(void *fxOrHost, uint32_t a, uint32_t b);

// W24-D residual — related/slot walk
void __thiscall FUN_004b7030(void *related, uint32_t a, uint32_t b, uint32_t c);

// Live Ghidra decompile text (CF authoritative). MI this-adjust is inside the
// first call's ECX setup (see annotated / review A for byte decode).
void __thiscall FUN_005829d0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
  // Decompiler flattens adjusted-ECX call as:
  //   FUN_00518590(param_2, param_3, param_4)
  // with ECX loaded from lea [*( *(param_1-0x8C)+4 ) + param_1 - 0x8C] (bytes).
  FUN_00518590((void *)param_2, param_3, param_4);

  if (*(int *)(param_1 + -0x88) != 0) {
    // Bytes: mov ecx, param_2 (edi); push -1; push 0; push 0; push related
    FUN_004b7030(*(void **)(param_1 + -0x88), 0, 0, 0xffffffff);
  }
  return;
}

} // extern "C"
