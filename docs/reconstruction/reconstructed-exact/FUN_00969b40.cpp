// =============================================================================
// FUN_00969b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00969b40
// Address:   0x00969b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00969b40 @ 0x00969b40
// Stable ID: aa_00969b40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00969b40.
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

void FUN_00969b40(float param_1,float param_2,float param_3,float param_4,float param_5,

                 float param_6)



{

  float *in_EAX;

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  fVar3 = param_2 * param_6 - param_5 * param_3;

  fVar6 = param_3 * param_4 - param_6 * param_1;

  fVar7 = param_5 * param_1 - param_2 * param_4;

  fVar1 = param_5 * param_2 + param_3 * param_6 + param_1 * param_4;

  fVar2 = (g_flOne - fVar1) / (fVar3 * fVar3 + fVar7 * fVar7 + fVar6 * fVar6);

  fVar4 = fVar6 * fVar3 * fVar2;

  *in_EAX = fVar3 * fVar3 * fVar2 + fVar1;

  fVar5 = fVar7 * fVar3 * fVar2;

  in_EAX[1] = fVar4 + fVar7;

  in_EAX[2] = fVar5 - fVar6;

  in_EAX[3] = fVar4 - fVar7;

  fVar4 = fVar6 * fVar7 * fVar2;

  in_EAX[4] = fVar6 * fVar6 * fVar2 + fVar1;

  in_EAX[5] = fVar4 + fVar3;

  in_EAX[6] = fVar5 + fVar6;

  in_EAX[7] = fVar4 - fVar3;

  in_EAX[8] = fVar7 * fVar7 * fVar2 + fVar1;

  return;

}
