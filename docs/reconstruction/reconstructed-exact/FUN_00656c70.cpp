// =============================================================================
// FUN_00656c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00656c70
// Address:   0x00656c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00656c70 @ 0x00656c70
// Stable ID: aa_00656c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00656c70.
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

void __thiscall FUN_00656c70(int param_1,float *param_2)



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

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  

  fVar12 = *(float *)(param_1 + 100);

  fVar1 = *(float *)(param_1 + 0x88);

  fVar6 = *(float *)(param_1 + 0x68);

  fVar7 = *(float *)(param_1 + 0x84);

  fVar10 = *(float *)(param_1 + 0x60);

  fVar11 = *(float *)(param_1 + 0x88);

  fVar8 = *(float *)(param_1 + 100);

  fVar13 = *(float *)(param_1 + 0x80);

  fVar2 = *(float *)(param_1 + 0x80);

  fVar3 = *(float *)(param_1 + 0x68);

  fVar4 = *(float *)(param_1 + 0x60);

  fVar5 = *(float *)(param_1 + 0x84);

  *param_2 = *(float *)(param_1 + 0x70);

  param_2[1] = *(float *)(param_1 + 0x74);

  param_2[2] = *(float *)(param_1 + 0x78);

  param_2[3] = *(float *)(param_1 + 0x7c);

  param_2[4] = *(float *)(param_1 + 0x70);

  param_2[5] = *(float *)(param_1 + 0x74);

  param_2[6] = *(float *)(param_1 + 0x78);

  param_2[7] = *(float *)(param_1 + 0x7c);

  param_2[8] = *(float *)(param_1 + 0x70);

  param_2[9] = *(float *)(param_1 + 0x74);

  param_2[10] = *(float *)(param_1 + 0x78);

  param_2[0xb] = *(float *)(param_1 + 0x7c);

  param_2[0xc] = *(float *)(param_1 + 0x70);

  param_2[0xd] = *(float *)(param_1 + 0x74);

  param_2[0xe] = *(float *)(param_1 + 0x78);

  param_2[0xf] = *(float *)(param_1 + 0x7c);

  fVar9 = *(float *)(param_1 + 0x90);

  fVar8 = (fVar4 * fVar5 - fVar8 * fVar13) * fVar9;

  fVar6 = (fVar12 * fVar1 - fVar6 * fVar7) * fVar9;

  fVar7 = (fVar2 * fVar3 - fVar10 * fVar11) * fVar9;

  fVar9 = fVar9 * g_flZero;

  fVar12 = *(float *)(param_1 + 0x90);

  fVar13 = *(float *)(param_1 + 0x8c) * fVar12;

  fVar10 = *(float *)(param_1 + 0x80) * fVar12;

  fVar11 = *(float *)(param_1 + 0x84) * fVar12;

  fVar12 = *(float *)(param_1 + 0x88) * fVar12;

  *param_2 = *param_2 + fVar10 + fVar6;

  param_2[1] = param_2[1] + fVar11 + fVar7;

  param_2[2] = param_2[2] + fVar12 + fVar8;

  param_2[3] = param_2[3] + fVar13 + fVar9;

  param_2[4] = param_2[4] + fVar6;

  param_2[5] = param_2[5] + fVar7;

  param_2[6] = param_2[6] + fVar8;

  param_2[7] = param_2[7] + fVar9;

  param_2[4] = param_2[4] - fVar10;

  param_2[5] = param_2[5] - fVar11;

  param_2[6] = param_2[6] - fVar12;

  param_2[7] = param_2[7] - fVar13;

  param_2[8] = param_2[8] - fVar6;

  param_2[9] = param_2[9] - fVar7;

  param_2[10] = param_2[10] - fVar8;

  param_2[0xb] = param_2[0xb] - fVar9;

  param_2[8] = param_2[8] + fVar10;

  param_2[9] = param_2[9] + fVar11;

  param_2[10] = param_2[10] + fVar12;

  param_2[0xb] = param_2[0xb] + fVar13;

  fVar1 = param_2[0xc];

  param_2[0xd] = param_2[0xd] - fVar7;

  param_2[0xe] = param_2[0xe] - fVar8;

  param_2[0xf] = param_2[0xf] - fVar9;

  param_2[0xc] = fVar1 - fVar6;

  param_2[0xc] = (fVar1 - fVar6) - fVar10;

  param_2[0xd] = param_2[0xd] - fVar11;

  param_2[0xe] = param_2[0xe] - fVar12;

  param_2[0xf] = param_2[0xf] - fVar13;

  return;

}
