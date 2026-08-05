// =============================================================================
// FUN_006437a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006437a0
// Address:   0x006437a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006437a0 @ 0x006437a0
// Stable ID: aa_006437a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×17, do×5, while×5, goto×4, return×2.
//  - Notable callees: FUN_006a3db0×2, FUN_006437a0.
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

void __thiscall FUN_006437a0(int param_1,int param_2,int param_3,int param_4)



{

  ushort *puVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  ushort uVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  float fVar14;

  int local_18;

  float local_10;

  int local_8;

  

  fVar14 = 0.0;

  iVar13 = *(int *)(param_1 + 4);

  local_18 = param_3;

  iVar2 = *(int *)(param_4 + 0x3e0);

  local_10 = 0.0;

  local_8 = 0;

  if (0 < iVar13) {

    do {

      local_10 = fVar14;

      if (*(int *)(param_4 + 0x14) <= local_18) break;

      iVar10 = 0;

      iVar3 = param_2;

      if (3 < iVar13) {

        iVar12 = *(int *)(param_4 + 0x10);

        do {

          if (iVar12 <= iVar3) goto LAB_006438f9;

          iVar8 = iVar12 * local_18 + iVar3;

          fVar14 = (float)*(ushort *)(iVar2 + iVar8 * 2) * DAT_00af5098 + fVar14;

          if (((iVar12 <= iVar3 + 1) ||

              (fVar14 = (float)*(ushort *)(iVar2 + 2 + iVar8 * 2) * DAT_00af5098 + fVar14,

              iVar12 <= iVar3 + 2)) ||

             (fVar14 = (float)*(ushort *)(iVar2 + 4 + iVar8 * 2) * DAT_00af5098 + fVar14,

             iVar12 <= iVar3 + 3)) goto LAB_006438f9;

          iVar10 = iVar10 + 4;

          iVar3 = iVar3 + 4;

          fVar14 = (float)*(ushort *)(iVar2 + 6 + iVar8 * 2) * DAT_00af5098 + fVar14;

        } while (iVar10 < iVar13 + -3);

      }

      if (iVar10 < iVar13) {

        do {

          if (*(int *)(param_4 + 0x10) <= iVar3) break;

          iVar12 = *(int *)(param_4 + 0x10) * local_18 + iVar3;

          iVar10 = iVar10 + 1;

          iVar3 = iVar3 + 1;

          fVar14 = (float)*(ushort *)(iVar2 + iVar12 * 2) * DAT_00af5098 + fVar14;

        } while (iVar10 < iVar13);

      }

LAB_006438f9:

      local_18 = local_18 + 1;

      local_8 = local_8 + 1;

      local_10 = fVar14;

    } while (local_8 < iVar13);

  }

  fVar14 = local_10 / (float)(*(int *)(param_1 + 4) * *(int *)(param_1 + 4));

  uVar4 = FUN_006a3db0();

  uVar5 = FUN_006a3db0();

  local_10 = 0.0;

  local_18 = param_3;

  if (0 < iVar13) {

    do {

      if (*(int *)(param_4 + 0x14) <= local_18) {

        return;

      }

      param_3 = 0;

      iVar3 = param_2;

      if (0 < iVar13) {

        do {

          if (*(int *)(param_4 + 0x10) <= iVar3) break;

          puVar1 = (ushort *)(iVar2 + (*(int *)(param_4 + 0x10) * local_18 + iVar3) * 2);

          uVar9 = (uint)*puVar1;

          uVar6 = (uVar4 & 0xffff) - uVar9;

          uVar11 = (int)uVar6 >> 0x1f;

          uVar11 = (uVar6 ^ uVar11) - uVar11;

          uVar6 = uVar5 & 0xffff;

          if ((float)uVar9 <= fVar14) {

            if ((int)uVar6 <= (int)uVar11) {

              uVar11 = uVar6;

            }

            uVar9 = uVar9 + uVar11;

            if (0xfffe < uVar9) goto LAB_006439e8;

joined_r0x00643a01:

            uVar7 = (ushort)uVar9;

            if (uVar9 == 0) {

              uVar7 = 0;

            }

          }

          else {

            if ((int)uVar6 <= (int)uVar11) {

              uVar11 = uVar6;

            }

            uVar9 = uVar9 - uVar11;

            if (uVar9 < 0xffff) goto joined_r0x00643a01;

LAB_006439e8:

            uVar7 = 0xffff;

          }

          param_3 = param_3 + 1;

          *puVar1 = uVar7;

          iVar3 = iVar3 + 1;

        } while (param_3 < *(int *)(param_1 + 4));

      }

      iVar13 = *(int *)(param_1 + 4);

      local_18 = local_18 + 1;

      local_10 = (float)((int)local_10 + 1);

    } while ((int)local_10 < iVar13);

  }

  return;

}
