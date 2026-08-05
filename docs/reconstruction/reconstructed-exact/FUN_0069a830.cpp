// =============================================================================
// FUN_0069a830
// -----------------------------------------------------------------------------
// Stable ID: aa_0069a830
// Address:   0x0069a830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069a830 @ 0x0069a830
// Stable ID: aa_0069a830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_0068bac0×5, SQRT×2, FUN_0068c650, FUN_0068c830, FUN_0069a830, FUN_0069ddf0.
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

void __thiscall FUN_0069a830(int param_1,int param_2,ushort param_3)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  int iVar11;

  float *pfVar12;

  float *pfVar13;

  int iVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint uVar16;

  int iVar17;

  uint8_t *puVar18;

  uint32_t /* width from decompiler */ uVar19;

  int local_38;

  float local_1c;

  float local_18;

  float local_14;

  uint8_t local_10 [16];

  

  local_38 = 0;

  if (0 < *(int *)(param_1 + 0x1c)) {

    iVar10 = param_3 + 1;

    do {

      iVar11 = iVar10 * local_38;

      uVar16 = 0;

      do {

        if (uVar16 == 0) {

          iVar14 = (param_3 - 1) + iVar11;

        }

        else {

          iVar14 = iVar11 + -1 + uVar16;

        }

        iVar17 = iVar11 + 1;

        if (uVar16 != param_3) {

          iVar17 = iVar17 + uVar16;

        }

        iVar1 = *(int *)(param_1 + 0x24);

        pfVar12 = (float *)FUN_0068bac0(iVar14 + iVar1);

        pfVar13 = (float *)FUN_0068bac0(iVar17 + iVar1);

        fVar2 = *pfVar13 - *pfVar12;

        fVar5 = pfVar13[1] - pfVar12[1];

        fVar4 = pfVar13[2] - pfVar12[2];

        fVar3 = g_flOne / SQRT(fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4);

        iVar14 = iVar11;

        if (local_38 != 0) {

          iVar14 = (local_38 + -1) * iVar10;

        }

        iVar17 = iVar11;

        if (local_38 != *(int *)(param_1 + 0x1c) + -1) {

          iVar17 = (local_38 + 1) * iVar10;

        }

        iVar1 = *(int *)(param_1 + 0x24);

        pfVar12 = (float *)FUN_0068bac0(iVar14 + uVar16 + iVar1);

        pfVar13 = (float *)FUN_0068bac0(iVar17 + uVar16 + iVar1);

        fVar6 = *pfVar13 - *pfVar12;

        fVar9 = pfVar13[1] - pfVar12[1];

        fVar8 = pfVar13[2] - pfVar12[2];

        fVar7 = g_flOne / SQRT(fVar6 * fVar6 + fVar9 * fVar9 + fVar8 * fVar8);

        local_1c = fVar5 * fVar3 * fVar8 * fVar7 - fVar9 * fVar7 * fVar4 * fVar3;

        local_18 = fVar4 * fVar3 * fVar7 * fVar6 - fVar8 * fVar7 * fVar3 * fVar2;

        local_14 = fVar9 * fVar7 * fVar3 * fVar2 - fVar5 * fVar3 * fVar7 * fVar6;

        if (*DAT_00d08ec0 == 1) {

          uVar19 = 0;

          puVar18 = local_10;

          uVar15 = FUN_0068bac0(iVar11);

          FUN_0069ddf0(&local_1c,uVar15,puVar18,uVar19);

          FUN_0068c650(local_10);

        }

        else {

          FUN_0068c830(&local_1c);

        }

        *(short *)(param_2 + 0x1a) = *(short *)(param_2 + 0x1a) + 1;

        uVar16 = uVar16 + 1;

      } while ((int)uVar16 <= (int)(uint)param_3);

      local_38 = local_38 + 1;

    } while (local_38 < *(int *)(param_1 + 0x1c));

  }

  return;

}
