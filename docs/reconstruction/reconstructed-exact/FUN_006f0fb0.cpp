// =============================================================================
// FUN_006f0fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f0fb0
// Address:   0x006f0fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f0fb0 @ 0x006f0fb0
// Stable ID: aa_006f0fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006f0fb0.
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



void FUN_006f0fb0(uint8_t *param_1,int param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  fVar3 = *(float *)(param_2 + 0x10) - *(float *)(param_2 + 0x20);

  fVar6 = *(float *)(param_2 + 0x14) - *(float *)(param_2 + 0x24);

  fVar4 = *(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x28);

  fVar1 = *(float *)(param_2 + 0x10) - *(float *)(param_2 + 0x30);

  fVar2 = *(float *)(param_2 + 0x14) - *(float *)(param_2 + 0x34);

  fVar7 = *(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x38);

  fVar5 = fVar7 * fVar6 - fVar2 * fVar4;

  fVar4 = fVar4 * fVar1 - fVar7 * fVar3;

  fVar1 = fVar2 * fVar3 - fVar6 * fVar1;

  if (fVar5 * fVar5 + fVar4 * fVar4 + fVar1 * fVar1 < _DAT_00af58bc) {

    *param_1 = 1;

    return;

  }

  *param_1 = 0;

  return;

}
