// =============================================================================
// FUN_0062b6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b6c0
// Address:   0x0062b6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b6c0 @ 0x0062b6c0
// Stable ID: aa_0062b6c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×9, do×2, while×2, return×1.
//  - Notable callees: FUN_005b3300×3, FUN_0062b590, FUN_0062b640, FUN_0062b6c0.
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

void __thiscall FUN_0062b6c0(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  iVar6 = *param_1;

  uVar2 = *(uint *)(iVar6 + 8) & 0x7fffffff;

  if ((int)uVar2 < param_3) {

    iVar3 = uVar2 * 2;

    if (iVar3 <= param_3) {

      iVar3 = param_3;

    }

    FUN_005b3300(iVar6,iVar3,4);

  }

  iVar3 = 0;

  *(int *)(iVar6 + 4) = param_3;

  if (0 < param_3) {

    do {

      *(uint32_t /* width from decompiler */ *)(*(int *)*param_1 + iVar3 * 4) = 0xffffffff;

      iVar3 = iVar3 + 1;

    } while (iVar3 < param_3);

  }

  *(uint32_t /* width from decompiler */ *)(param_1[1] + 4) = 0;

  iVar6 = param_2[1];

  uVar2 = *(uint *)(param_1[1] + 8) & 0x7fffffff;

  if ((int)uVar2 < iVar6) {

    iVar3 = uVar2 * 2;

    if (iVar3 <= iVar6) {

      iVar3 = iVar6;

    }

    FUN_005b3300(param_1[1],iVar3,4);

  }

  iVar6 = param_1[1];

  iVar3 = param_2[1];

  uVar2 = *(uint *)(iVar6 + 8) & 0x7fffffff;

  if ((int)uVar2 < iVar3) {

    iVar4 = uVar2 * 2;

    if (iVar4 <= iVar3) {

      iVar4 = iVar3;

    }

    FUN_005b3300(iVar6,iVar4,4);

  }

  *(int *)(iVar6 + 4) = iVar3;

  iVar6 = 0;

  if (0 < param_2[1]) {

    do {

      iVar4 = *(int *)(*param_2 + 4 + iVar6 * 8);

      iVar1 = *(int *)param_1[1];

      iVar8 = *(int *)(*param_2 + iVar6 * 8);

      iVar3 = iVar6 * 4;

      iVar7 = iVar4;

      if (iVar8 < iVar4) {

        iVar7 = iVar8;

        iVar8 = iVar4;

      }

      uVar5 = FUN_0062b590(iVar7,iVar8);

      iVar6 = iVar6 + 1;

      *(uint32_t /* width from decompiler */ *)(iVar1 + iVar3) = uVar5;

    } while (iVar6 < param_2[1]);

  }

  FUN_0062b640();

  param_1[2] = 0;

  return;

}
