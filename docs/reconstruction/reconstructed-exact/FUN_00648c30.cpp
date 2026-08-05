// =============================================================================
// FUN_00648c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00648c30
// Address:   0x00648c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00648c30 @ 0x00648c30
// Stable ID: aa_00648c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, return×1.
//  - Notable callees: FUN_005b3300×3, FUN_00648c30.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00648c30(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  short *psVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  

  *param_1 = &PTR_FUN_009e4760;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0x80000000;

  piVar1 = param_1 + 2;

  param_1[7] = 0x80000000;

  param_1[5] = 0;

  param_1[6] = 0;

  piVar2 = param_1 + 5;

  param_1[10] = 0x80000000;

  param_1[8] = 0;

  param_1[9] = 0;

  iVar7 = param_2[1];

  if ((int)(param_1[7] & 0x7fffffff) < iVar7) {

    iVar4 = (param_1[7] & 0x7fffffff) * 2;

    if (iVar4 <= iVar7) {

      iVar4 = iVar7;

    }

    FUN_005b3300(piVar2,iVar4,4);

  }

  iVar4 = 0;

  param_1[6] = iVar7;

  if (0 < (int)param_1[6]) {

    do {

      *(uint32_t /* width from decompiler */ *)(*piVar2 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)(param_2[4] + iVar4 * 4);

      psVar3 = (short *)(*(int *)(*piVar2 + iVar4 * 4) + 6);

      *psVar3 = *psVar3 + 1;

      iVar4 = iVar4 + 1;

    } while (iVar4 < (int)param_1[6]);

  }

  iVar7 = *param_2;

  if ((int)(param_1[4] & 0x7fffffff) < iVar7) {

    iVar4 = (param_1[4] & 0x7fffffff) * 2;

    if (iVar4 <= iVar7) {

      iVar4 = iVar7;

    }

    FUN_005b3300(piVar1,iVar4,4);

  }

  iVar4 = 0;

  param_1[3] = iVar7;

  if (0 < (int)param_1[3]) {

    do {

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)(param_2[2] + iVar4 * 4);

      psVar3 = (short *)(*(int *)(*piVar1 + iVar4 * 4) + 6);

      *psVar3 = *psVar3 + 1;

      iVar4 = iVar4 + 1;

    } while (iVar4 < (int)param_1[3]);

  }

  if (param_2[3] != 0) {

    iVar7 = *param_2;

    if ((int)(param_1[10] & 0x7fffffff) < iVar7) {

      iVar4 = (param_1[10] & 0x7fffffff) * 2;

      if (iVar4 <= iVar7) {

        iVar4 = iVar7;

      }

      FUN_005b3300(param_1 + 8,iVar4,0x20);

    }

    param_1[9] = iVar7;

    iVar7 = 0;

    if (0 < (int)param_1[9]) {

      iVar4 = 0;

      do {

        iVar5 = param_2[3] + iVar4;

        puVar6 = (uint32_t /* width from decompiler */ *)(param_1[8] + iVar4);

        *puVar6 = *(uint32_t /* width from decompiler */ *)(param_2[3] + iVar4);

        puVar6[1] = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

        puVar6[2] = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

        puVar6[3] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

        puVar6[4] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10);

        puVar6[5] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14);

        puVar6[6] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x18);

        iVar7 = iVar7 + 1;

        puVar6[7] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x1c);

        iVar4 = iVar4 + 0x20;

      } while (iVar7 < (int)param_1[9]);

    }

  }

  return param_1;

}
