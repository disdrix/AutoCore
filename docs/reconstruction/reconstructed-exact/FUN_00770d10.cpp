// =============================================================================
// FUN_00770d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00770d10
// Address:   0x00770d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770d10 @ 0x00770d10
// Stable ID: aa_00770d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×11, do×3, while×3, for×2, return×1.
//  - Notable callees: FUN_00770490, FUN_00770d10.
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

int FUN_00770d10(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  ulonglong uVar3;

  int *in_EAX;

  int iVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  uint *puVar10;

  int iVar11;

  int iVar12;

  uint *puVar13;

  uint *puVar14;

  uint local_800 [512];

  

  if ((param_3 <= param_2[1]) || (iVar4 = FUN_00770490(), iVar4 == 0)) {

    iVar4 = *param_1;

    iVar5 = iVar4 + *in_EAX;

    if (param_3 < iVar5) {

      iVar5 = param_3;

    }

    uVar6 = 0;

    iVar12 = 0;

    uVar3 = 0;

    if (0 < iVar5) {

      iVar1 = param_1[3];

      iVar2 = in_EAX[3];

      iVar8 = *in_EAX + -1;

      do {

        iVar9 = iVar8;

        if (iVar12 <= iVar8) {

          iVar9 = iVar12;

        }

        puVar10 = (uint *)(iVar1 + (iVar12 - iVar9) * 4);

        puVar13 = (uint *)(iVar2 + iVar9 * 4);

        iVar11 = iVar4 - (iVar12 - iVar9);

        if (iVar9 + 1 <= iVar11) {

          iVar11 = iVar9 + 1;

        }

        if (0 < iVar11) {

          do {

            uVar3 = (ulonglong)*puVar13 * (ulonglong)*puVar10 + uVar3;

            puVar13 = puVar13 + -1;

            puVar10 = puVar10 + 1;

            iVar11 = iVar11 + -1;

          } while (iVar11 != 0);

        }

        uVar7 = (uint)uVar3;

        uVar3 = uVar3 >> 0x1c;

        uVar6 = (uint)uVar3;

        local_800[iVar12] = uVar7 & 0xfffffff;

        iVar12 = iVar12 + 1;

      } while (iVar12 < iVar5);

    }

    puVar10 = (uint *)param_2[3];

    local_800[iVar12] = uVar6 & 0xfffffff;

    iVar4 = *param_2;

    *param_2 = iVar5;

    iVar5 = iVar5 + 1;

    iVar12 = 0;

    if (0 < iVar5) {

      puVar13 = local_800;

      puVar14 = puVar10;

      for (iVar12 = iVar5; iVar12 != 0; iVar12 = iVar12 + -1) {

        *puVar14 = *puVar13;

        puVar13 = puVar13 + 1;

        puVar14 = puVar14 + 1;

      }

      puVar10 = puVar10 + iVar5;

      iVar12 = iVar5;

    }

    if (iVar12 < iVar4) {

      for (iVar4 = iVar4 - iVar12; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar10 = 0;

        puVar10 = puVar10 + 1;

      }

    }

    iVar4 = *param_2;

    if (0 < iVar4) {

      do {

        if (*(int *)(param_2[3] + -4 + *param_2 * 4) != 0) break;

        iVar4 = *param_2 + -1;

        *param_2 = iVar4;

      } while (0 < iVar4);

      iVar4 = *param_2;

    }

    if (iVar4 == 0) {

      param_2[2] = 0;

    }

    iVar4 = 0;

  }

  return iVar4;

}
