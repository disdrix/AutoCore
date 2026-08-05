// =============================================================================
// FUN_00915820
// -----------------------------------------------------------------------------
// Stable ID: aa_00915820
// Address:   0x00915820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00915820 @ 0x00915820
// Stable ID: aa_00915820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004cd220×2, FUN_00915820.
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

void __fastcall FUN_00915820(float *param_1,int param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  

  iVar10 = *(int *)(param_2 + 0x2a4);

  fVar11 = *(float *)(iVar10 + 0xf8) + g_flOne;

  fVar12 = 0.0 - (*(float *)(iVar10 + 0xfc) + g_flOne);

  fVar13 = 0.0 - (*(float *)(iVar10 + 0xf8) + g_flOne);

  fVar14 = 0.0 - (*(float *)(iVar10 + 0xfc) + g_flOne);

  fVar1 = *(float *)(iVar10 + 0xf0);

  fVar2 = *(float *)(DAT_00d17944 + 0x224);

  fVar3 = *(float *)(DAT_00d17944 + 0x218);

  fVar4 = *(float *)(DAT_00d17944 + 0x21c);

  fVar5 = *(float *)(DAT_00d17944 + 0x210);

  fVar6 = *(float *)(DAT_00d17944 + 0x20c);

  fVar7 = *(float *)(DAT_00d17944 + 0x204);

  fVar8 = *param_1;

  fVar9 = param_1[2];

  FUN_004cd220(*(float *)(DAT_00d17944 + 0x204) * fVar11 + *(float *)(DAT_00d17944 + 0x210) * fVar12

               + *(float *)(DAT_00d17944 + 0x21c) * *(float *)(iVar10 + 0xf0) + *param_1,

               *(float *)(DAT_00d17944 + 0x20c) * fVar11 + *(float *)(DAT_00d17944 + 0x218) * fVar12

               + *(float *)(DAT_00d17944 + 0x224) * *(float *)(iVar10 + 0xf0) + param_1[2]);

  FUN_004cd220(fVar13 * fVar7 + fVar5 * fVar14 + fVar4 * fVar1 + fVar8,

               fVar6 * fVar13 + fVar3 * fVar14 + fVar2 * fVar1 + fVar9);

  return;

}
