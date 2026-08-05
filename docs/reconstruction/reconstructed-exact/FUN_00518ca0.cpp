// =============================================================================
// FUN_00518ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00518ca0
// Address:   0x00518ca0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W24-H dual A/B (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// PURPOSE: Insert skillId → TFID16 into owner+0x68 active-cast binding map
//          (lazy-get FUN_00518c20 + map insert FUN_004cbe20).
// Named plate: Skill_InsertActiveCastBinding_Inferred.cpp

#include <cstdint>

// Ghidra scaffold signature omits ECX mapOwner and ret 0x14 cleanup.
// See named plate for sealed ABI.

void FUN_00518ca0(
    uint32_t param_1,
    uint32_t param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5)
{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t local_18[2];
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;

  // Entry ECX = mapOwner (byte-sealed; not in this Ghidra formal list).
  puVar2 = local_18;
  local_18[0] = param_1;   // skillId @ +0
  // local_18[1] / +4 intentionally not written (pair pad)
  local_10 = param_2;      // tfid0 @ +8
  local_c = param_3;
  local_8 = param_4;
  local_4 = param_5;
  puVar1 = &param_2;       // decompiler: discard out-pair slot
  // FUN_00518c20(mapOwner) — unary; staged pushes feed FUN_004cbe20
  FUN_00518c20(puVar1, local_18);
  FUN_004cbe20(puVar1, puVar2);
  // add esp,0x18; ret 0x14
}
