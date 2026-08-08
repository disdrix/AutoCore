// =============================================================================
// FUN_005ebf00  (clean twin of VOGPhysics_SphereQueryCollect_Dtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ebf00
// Address:   0x005ebf00  (autoassault.exe, image base 0x400000)
// Range:     0x005ebf00–0x005ebf67 inclusive (104 B / 0x68); pad CC after
// System:    interaction-activation
// Generated: 2026-08-05 R12-038 dual seal
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// Named twin: VOGPhysics_SphereQueryCollect_Dtor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern uint32_t PTR_FUN_009dce90;
extern void **DAT_00b05060;
extern void __thiscall FUN_006343d0(uint32_t *self /* ECX */);

// Ghidra symbol body (thiscall sealed by assembly; decompiler shows __fastcall).
void __thiscall FUN_005ebf00(uint32_t *param_1 /* ECX */)
{
  int iVar1;

  iVar1 = (int)param_1[0x31];
  *param_1 = (uint32_t)(uintptr_t)&PTR_FUN_009dce90;

  while (iVar1 = iVar1 - 1, -1 < iVar1) {
    uint32_t *entry_obj =
        *reinterpret_cast<uint32_t **>(param_1[0x30] + static_cast<uint32_t>(iVar1) * 8);
    auto **vtbl = reinterpret_cast<void **>(*entry_obj);
    auto release = reinterpret_cast<void (__thiscall *)(uint32_t *)>(vtbl[0x14 / 4]);
    release(entry_obj);
  }

  param_1[0x31] = 0;

  if (-1 < (int)param_1[0x32]) {
    uint32_t size_bytes = (param_1[0x32] & 0x7fffffffu) * 8u;
    auto **alloc_vtbl = reinterpret_cast<void **>(*DAT_00b05060);
    auto free_fn = reinterpret_cast<void (__stdcall *)(void *, uint32_t, uint32_t)>(
        alloc_vtbl[0x14 / 4]);
    free_fn(reinterpret_cast<void *>(param_1[0x30]), size_bytes, 0x12u);
  }

  // Tail JMP in retail image
  FUN_006343d0(param_1);
}
