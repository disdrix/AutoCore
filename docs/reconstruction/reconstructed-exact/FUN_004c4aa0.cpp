// =============================================================================
// FUN_004c4aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4aa0
// Address:   0x004c4aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c4aa0 @ 0x004c4aa0
// Stable ID: aa_004c4aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, FUN_004c4aa0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __fastcall FUN_004c4aa0(int param_1)



{

  float fVar1;

  int iVar2;

  uint3 uVar3;

  float fVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

  fVar1 = *(float *)(iVar2 + 100 + param_1);

  iVar2 = (**(code **)(*(int *)(iVar2 + param_1 + 4) + 0x244))();

  fVar4 = (float)iVar2 * (float)_DAT_00aaa6e0;

  if (g_flZero <= fVar4) {

    fVar4 = fVar4 + g_flMissionXpRoundBias;

  }

  else {

    fVar4 = fVar4 - g_flMissionXpRoundBias;

  }

  uVar3 = (uint3)((uint)(int)fVar4 >> 8);

  if (fVar1 < (float)(int)fVar4) {

    return (uint)uVar3 << 8;

  }

  return CONCAT31(uVar3,*(uint8_t *)(param_1 + 0x309));

}
