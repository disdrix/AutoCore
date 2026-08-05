// =============================================================================
// FUN_0049c6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049c6b0
// Address:   0x0049c6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049c6b0 @ 0x0049c6b0
// Stable ID: aa_0049c6b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×4.
//  - Notable callees: FUN_0049c560×4, FUN_0049be30, FUN_0049c6b0, free, malloc.
//  - Return sites: 4.

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

int __thiscall FUN_0049c6b0(int param_1,int param_2)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  void *pvVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  

  FUN_0049be30(param_2);

  piVar7 = (int *)(param_2 + 0x118);

  piVar1 = (int *)(param_1 + 0x118);

  if (piVar1 == piVar7) {

    return param_1;

  }

  iVar6 = *(int *)(param_2 + 0x11c);

  pvVar5 = (void *)*piVar1;

  uVar2 = (*(int *)(param_1 + 0x11c) - (int)pvVar5) / 0x70;

  uVar3 = (iVar6 - *piVar7) / 0x70;

  if (uVar2 < uVar3) {

    if (pvVar5 == (void *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = (*(int *)(param_1 + 0x120) - (int)pvVar5) / 0x70;

    }

    if (uVar4 < uVar3) {

      if (pvVar5 != (void *)0x0) {

        free(pvVar5);

      }

      pvVar5 = malloc(((*(int *)(param_2 + 0x11c) - *piVar7) / 0x70) * 0x70);

      *piVar1 = (int)pvVar5;

      iVar6 = *(int *)(param_2 + 0x11c);

      for (iVar8 = *piVar7; iVar8 != iVar6; iVar8 = iVar8 + 0x70) {

        FUN_0049c560(iVar8);

        pvVar5 = (void *)((int)pvVar5 + 0x70);

      }

      *(void **)(param_1 + 0x11c) = pvVar5;

      *(void **)(param_1 + 0x120) = pvVar5;

      return param_1;

    }

    iVar6 = *piVar7;

    iVar8 = uVar2 * 0x70 + iVar6;

    for (; iVar6 != iVar8; iVar6 = iVar6 + 0x70) {

      FUN_0049c560(iVar6);

    }

    iVar6 = *(int *)(param_2 + 0x11c);

    for (; iVar8 != iVar6; iVar8 = iVar8 + 0x70) {

      FUN_0049c560(iVar8);

    }

    *(int *)(param_1 + 0x11c) = ((*(int *)(param_2 + 0x11c) - *piVar7) / 0x70) * 0x70 + *piVar1;

    return param_1;

  }

  for (iVar8 = *piVar7; iVar8 != iVar6; iVar8 = iVar8 + 0x70) {

    FUN_0049c560(iVar8);

  }

  *(int *)(param_1 + 0x11c) = ((*(int *)(param_2 + 0x11c) - *piVar7) / 0x70) * 0x70 + *piVar1;

  return param_1;

}
