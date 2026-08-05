// =============================================================================
// FUN_006c79e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c79e0
// Address:   0x006c79e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c79e0 @ 0x006c79e0
// Stable ID: aa_006c79e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c79e0.
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

void __thiscall FUN_006c79e0(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar2 = *(float *)(param_1 + 0x10);

  fVar1 = *(float *)(param_1 + 0xc);

  fVar3 = *(float *)(param_1 + 0x14);

  fVar4 = *(float *)(param_1 + 0x18);

  fVar5 = fVar2 * DAT_00aaa668;

  *param_2 = fVar2;

  param_2[1] = fVar3;

  param_2[2] = fVar4;

  param_2[3] = fVar1;

  param_2[4] = fVar5;

  param_2[5] = fVar3;

  fVar6 = fVar3 * DAT_00aaa668;

  param_2[6] = fVar4;

  param_2[7] = fVar1;

  param_2[8] = fVar2;

  param_2[9] = fVar6;

  param_2[10] = fVar4;

  param_2[0xb] = fVar1;

  param_2[0xe] = fVar4;

  param_2[0xf] = fVar1;

  param_2[0xc] = fVar5;

  param_2[0xd] = fVar6;

  fVar4 = fVar4 * DAT_00aaa668;

  param_2[0x11] = fVar3;

  param_2[0x10] = fVar2;

  param_2[0x13] = fVar1;

  param_2[0x12] = fVar4;

  param_2[0x14] = fVar5;

  param_2[0x15] = fVar3;

  param_2[0x16] = fVar4;

  param_2[0x17] = fVar1;

  param_2[0x18] = fVar2;

  param_2[0x19] = fVar6;

  param_2[0x1a] = fVar4;

  param_2[0x1b] = fVar1;

  param_2[0x1c] = fVar5;

  param_2[0x1d] = fVar6;

  param_2[0x1e] = fVar4;

  param_2[0x1f] = fVar1;

  return;

}
