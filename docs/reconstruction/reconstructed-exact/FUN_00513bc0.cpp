// =============================================================================
// FUN_00513bc0  (twin of Item_TinkerPrerequisiteGate_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513bc0
// Address:   0x00513bc0  (autoassault.exe, image base 0x400000)
// Body:      0x00513bc0–0x00513c06 inclusive (71 B / 0x47)
// System:    inventory-transfer / tinker kit validation
// Generated: 2026-08-05 MEGA-104 OWN-ONLY dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Prefer Item_TinkerPrerequisiteGate_Inferred.cpp for named port.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Leaf boolean gate: candidate type (+0xb4) matches kit host type (+0xa8)+0x38,
//   or remapped pair (cand 0x44 ↔ kit subtype 10) / (cand 0x46 ↔ kit subtype 11).
//
// ABI: __thiscall ECX=kit, stack candidate, AL bool, RET 4.
// Sole caller: FUN_00513c10 @ 0x00513c36.

#include <cstdint>

// Decompiler-faithful signature (Ghidra widths).
uint32_t __thiscall FUN_00513bc0(int param_1 /*kit ECX*/, int param_2 /*candidate*/)
{
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;

  uVar2 = 0;
  if (param_2 == 0) {
    goto LAB_00513c02;
  }
  iVar1 = *reinterpret_cast<int*>(param_1 + 0xa8);
  uVar3 = *reinterpret_cast<uint32_t*>(param_2 + 0xb4);
  if (uVar3 != *reinterpret_cast<uint32_t*>(iVar1 + 0x38)) {
    if (uVar3 == 0x44) {
      uVar2 = 0;
      uVar3 = 0;
      if (*reinterpret_cast<int16_t*>(
              *reinterpret_cast<int*>(iVar1 + 0x3c) + 0x3f4) != 10) {
        goto LAB_00513c02;
      }
    } else {
      uVar2 = uVar3 - 0x46;
      if ((uVar2 != 0) ||
          (uVar2 = *reinterpret_cast<uint32_t*>(iVar1 + 0x3c), uVar3 = uVar2,
           *reinterpret_cast<int16_t*>(uVar2 + 0x3f4) != 0xb)) {
      LAB_00513c02:
        return uVar2 & 0xffffff00; // AL = 0
      }
    }
  }
  // CONCAT31((int3)(uVar3 >> 8), 1) — machine: MOV AL,1
  return (uVar3 & 0xffffff00) | 1;
}
