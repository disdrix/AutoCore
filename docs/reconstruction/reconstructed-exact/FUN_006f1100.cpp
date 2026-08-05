// =============================================================================
// FUN_006f1100
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1100
// Address:   0x006f1100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1100 @ 0x006f1100
// Stable ID: aa_006f1100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006f1100.
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

void __thiscall FUN_006f1100(int param_1,uint param_2,uint32_t /* width from decompiler */ *param_3)



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

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  uint32_t /* width from decompiler */ uVar19;

  int iVar20;

  int iVar21;

  int *piVar22;

  byte bVar23;

  uint uVar24;

  int iVar25;

  uint uVar26;

  uint *puVar27;

  uint uVar28;

  int iVar29;

  

  bVar23 = (byte)*(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  iVar25 = *(int *)(param_1 + 0x28);

  iVar21 = (param_2 >> (0x20 - bVar23 & 0x1f)) * 0x30;

  piVar22 = (int *)(iVar21 + iVar25);

  puVar27 = (uint *)(piVar22[5] * (0xffffffffU >> (bVar23 & 0x1f) & param_2) +

                    *(int *)(iVar21 + 0xc + iVar25));

  iVar29 = piVar22[1];

  iVar20 = *piVar22;

  if (*(char *)(iVar21 + 0x10 + iVar25) == '\x01') {

    uVar24 = (uint)(ushort)*puVar27;

    uVar26 = (uint)*(ushort *)((int)puVar27 + 2);

    uVar28 = (uint)(ushort)puVar27[1];

  }

  else {

    uVar24 = *puVar27;

    uVar26 = puVar27[1];

    uVar28 = puVar27[2];

  }

  iVar25 = uVar24 * iVar29;

  iVar21 = uVar26 * iVar29;

  iVar29 = uVar28 * iVar29;

  fVar1 = *(float *)(iVar25 + iVar20);

  fVar2 = *(float *)(param_1 + 0x10);

  fVar3 = *(float *)(iVar25 + 4 + iVar20);

  fVar4 = *(float *)(param_1 + 0x14);

  fVar5 = *(float *)(iVar25 + 8 + iVar20);

  fVar6 = *(float *)(param_1 + 0x18);

  fVar7 = *(float *)(param_1 + 0x10);

  fVar8 = *(float *)(iVar21 + iVar20);

  fVar9 = *(float *)(iVar21 + 4 + iVar20);

  fVar10 = *(float *)(param_1 + 0x14);

  fVar11 = *(float *)(iVar21 + 8 + iVar20);

  fVar12 = *(float *)(param_1 + 0x18);

  fVar13 = *(float *)(param_1 + 0x10);

  fVar14 = *(float *)(iVar29 + iVar20);

  fVar15 = *(float *)(iVar29 + 4 + iVar20);

  fVar16 = *(float *)(param_1 + 0x14);

  fVar17 = *(float *)(iVar29 + iVar20 + 8);

  fVar18 = *(float *)(param_1 + 0x18);

  if (param_3 == (uint32_t /* width from decompiler */ *)0x0) {

    param_3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    uVar19 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint16_t *)((int)param_3 + 6) = 1;

    param_3[3] = uVar19;

    param_3[2] = 0;

    *param_3 = &PTR_FUN_00a0d388;

  }

  param_3[6] = fVar5 * fVar6;

  param_3[4] = fVar1 * fVar2;

  param_3[5] = fVar3 * fVar4;

  param_3[7] = 0;

  param_3[8] = fVar7 * fVar8;

  param_3[9] = fVar9 * fVar10;

  param_3[10] = fVar11 * fVar12;

  param_3[0xb] = 0;

  param_3[0xc] = fVar13 * fVar14;

  param_3[0xd] = fVar15 * fVar16;

  param_3[0xe] = fVar17 * fVar18;

  param_3[0xf] = 0;

  return;

}
