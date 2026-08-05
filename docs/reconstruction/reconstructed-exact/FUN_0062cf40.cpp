// =============================================================================
// FUN_0062cf40
// -----------------------------------------------------------------------------
// Stable ID: aa_0062cf40
// Address:   0x0062cf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062cf40 @ 0x0062cf40
// Stable ID: aa_0062cf40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_0062cf40.
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

void __thiscall FUN_0062cf40(int param_1,int *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  float fVar14;

  float *pfVar15;

  int *piVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  int local_3c;

  int local_38;

  int local_34;

  

  if ((int)(param_2[2] & 0x7fffffffU) < *(int *)(param_1 + 0x44)) {

    FUN_005b3300(param_2,*(int *)(param_1 + 0x44),0x20);

  }

  param_2[1] = *(int *)(param_1 + 0x44);

  fVar14 = g_flOne;

  local_34 = 0;

  if (0 < *(int *)(param_1 + 0x44)) {

    local_38 = 0;

    local_3c = 0;

    do {

      piVar16 = (int *)(*(int *)(param_1 + 0x40) + local_3c);

      iVar8 = *(int *)(*(int *)(param_1 + 0x4c) + piVar16[4] * 8);

      iVar9 = *(int *)(*(int *)(param_1 + 0x58) + *piVar16 * 8);

      iVar10 = *(int *)(*(int *)(param_1 + 100) + piVar16[1] * 8);

      iVar11 = *(int *)(*(int *)(param_1 + 0x4c) + piVar16[5] * 8);

      pfVar15 = (float *)(*param_2 + local_38);

      local_3c = local_3c + 0x1c;

      local_38 = local_38 + 0x20;

      fVar17 = fVar14 / *(float *)(param_1 + 0x30);

      fVar1 = *(float *)(param_1 + 0x10);

      iVar12 = *(int *)(*(int *)(param_1 + 0x58) + piVar16[2] * 8);

      fVar2 = *(float *)(param_1 + 0x10);

      fVar18 = fVar14 / *(float *)(param_1 + 0x34);

      fVar3 = *(float *)(param_1 + 0x14);

      iVar13 = *(int *)(*(int *)(param_1 + 100) + piVar16[3] * 8);

      fVar4 = *(float *)(param_1 + 0x14);

      fVar19 = fVar14 / *(float *)(param_1 + 0x38);

      fVar5 = *(float *)(param_1 + 0x18);

      fVar6 = *(float *)(param_1 + 0x18);

      fVar7 = *(float *)(param_1 + 0x1c);

      pfVar15[3] = 0.0 - *(float *)(param_1 + 0x1c);

      pfVar15[1] = (float)iVar9 * fVar18 - fVar3;

      pfVar15[2] = (float)iVar10 * fVar19 - fVar6;

      *pfVar15 = (float)iVar8 * fVar17 - fVar1;

      pfVar15[4] = (float)iVar11 * fVar17 - fVar2;

      pfVar15[5] = (float)iVar12 * fVar18 - fVar4;

      pfVar15[6] = (float)iVar13 * fVar19 - fVar5;

      pfVar15[7] = 0.0 - fVar7;

      local_34 = local_34 + 1;

    } while (local_34 < *(int *)(param_1 + 0x44));

  }

  return;

}
