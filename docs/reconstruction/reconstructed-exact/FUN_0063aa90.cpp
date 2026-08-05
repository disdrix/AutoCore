// =============================================================================
// FUN_0063aa90
// -----------------------------------------------------------------------------
// Stable ID: aa_0063aa90
// Address:   0x0063aa90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063aa90 @ 0x0063aa90
// Stable ID: aa_0063aa90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063aa90.
//  - Return sites: 1.

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

void __thiscall FUN_0063aa90(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar3 = *(float *)(param_1 + 0x54);

  fVar4 = *param_2 - *(float *)(param_1 + 0x70);

  fVar6 = param_2[2] - *(float *)(param_1 + 0x78);

  fVar5 = param_2[1] - *(float *)(param_1 + 0x74);

  fVar2 = *(float *)(param_1 + 0x58) * fVar4 - *(float *)(param_1 + 0x50) * fVar6;

  fVar1 = *(float *)(param_1 + 0x50);

  *param_3 = *(float *)(param_1 + 0x54) * fVar6 - *(float *)(param_1 + 0x58) * fVar5;

  param_3[3] = 0.0;

  param_3[1] = fVar2;

  fVar3 = fVar1 * fVar5 - fVar3 * fVar4;

  param_3[2] = fVar3;

  *param_3 = *param_3 + *(float *)(param_1 + 0x40);

  param_3[1] = *(float *)(param_1 + 0x44) + fVar2;

  param_3[2] = *(float *)(param_1 + 0x48) + fVar3;

  param_3[3] = *(float *)(param_1 + 0x4c);

  return;

}
