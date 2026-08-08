// =============================================================================
// CVOGPhysics_WriteNotFullyReadyOut_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00404e00
// Address:   0x00404e00–0x00404e22  (autoassault.exe, image base 0x400000)
// Size:      35 B / 0x23
// System:    physics (MEGA-049 partition seed: skills-abilities nested)
// Generated: 2026-08-05 MEGA-049 dual A/B (live decompile + disasm + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Ghidra:    FUN_00404e00
// =============================================================================

// PURPOSE:
//   CVOGPhysics leaf: write *out = 0 when fully ready (byte@+0x40 != 0 AND
//   dword@+0x08 != 0); else *out = 1 (not fully ready / soft path allowed).
//   Returns out pointer in EAX (callers treat return as char*).
//
// Family:
//   Same fully-ready fields as CVOGPhysics_SetRotation (0x00404dc0) skip gate
//   and setPosition peer (0x0040d2a0). Distinct from ready-probe FUN_005070b0
//   (that probes +0x44 / +0x29, not +0x40 / +0x08).
//
// ABI: thiscall (ECX = phys); stack arg = uint8_t* out; RET 4.
//
// Callers (2):
//   FUN_005d0d60 Skill_ApplyBoundStatusMotionTable_Inferred @ 0x005d0fb6
//   FUN_005d7f70 CVOGHBAICreatureBase_DoLogic             @ 0x005d80a5
//   Both: ECX = *(entity + 0x08); branch if *out != 0.
//
// Dual A/B: reviews/A_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md
//           reviews/B_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md

#include <stdint.h>

// phys: CVOGPhysics* (this)
// out:  caller stack temp; *out written; EAX = out on return
uint8_t *__thiscall CVOGPhysics_WriteNotFullyReadyOut_Inferred(int phys, uint8_t *out)
{
  if ((*(char *)(phys + 0x40) != '\0') && (*(int *)(phys + 8) != 0)) {
    *out = 0;   // fully ready
    return out;
  }
  *out = 1;     // not fully ready
  return out;
}
