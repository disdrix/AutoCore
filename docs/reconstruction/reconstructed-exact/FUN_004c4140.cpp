// =============================================================================
// FUN_004c4140  →  Creature_GetTheory
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4140
// Address:   0x004c4140–0x004c41bb  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / character stats
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W17-I dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean plate: reconstructed-exact/Creature_GetTheory.cpp
// Dual: reviews/A|B_aa_004c4140_Creature_GetTheory.md
// =============================================================================

// PURPOSE:
//   Theory stat getter: clamp(min(short@+0x140, 200) + short@+0x148, 1, 250).
//   Product string "Theory" (UI). Accuracy chain casts return to float bonus.

int __fastcall FUN_004c4140(int param_1)
{
  short sVar1;
  int iVar2;
  short sVar3;

  sVar1 = *(short *)(param_1 + 0x140);
  sVar3 = sVar1;
  if (199 < sVar1) {
    sVar3 = 200;
  }
  iVar2 = (int)*(short *)(param_1 + 0x148);
  if (sVar3 + iVar2 < 0xfa) {
    sVar3 = sVar1;
    if (199 < sVar1) {
      sVar3 = 200;
    }
    if (sVar3 + iVar2 < 2) {
      return 1;
    }
  }
  sVar3 = sVar1;
  if (199 < sVar1) {
    sVar3 = 200;
  }
  if (sVar3 + iVar2 < 0xfa) {
    if (199 < sVar1) {
      sVar1 = 200;
    }
    return sVar1 + iVar2;
  }
  return 0xfa;
}
