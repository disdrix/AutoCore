// =============================================================================
// FUN_00733640
// -----------------------------------------------------------------------------
// Stable ID: aa_00733640
// Address:   0x00733640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00733640 @ 0x00733640
// Stable ID: aa_00733640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, for×1, goto×1.
//  - Notable callees: FUN_007332b0×2, FUN_0072a3e0, FUN_00733640, FUN_0073e720, FUN_0073e9b0.
//  - Return sites: 3.

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

uint __thiscall FUN_00733640(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  char *pcVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  

  iVar2 = (**(code **)(*(int *)*param_2 + 0x18))();

  if ((iVar2 != 0) && (FUN_0073e9b0(*(uint32_t /* width from decompiler */ *)(param_1 + 4)), *(int *)(iVar2 + 0x10) != 0)) {

    FUN_0073e720();

  }

  iVar2 = (int)*(short *)(param_2[1] + 0x1e);

  if ((iVar2 == *(int *)(param_1 + 0x6c)) && (*(int **)(param_1 + 0x5c) != (int *)0x0)) {

    uVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x14))(param_2);

    return uVar3 & 0xffffff00;

  }

  if ((((*(int **)(param_1 + 0x58) != (int *)0x0) && (*(char *)(DAT_00d1f048 + 0x11) != '\0')) &&

      ((pcVar1 = *(char **)(param_2[1] + 0x10), pcVar1 == (char *)0x0 || (*pcVar1 == '\0')))) &&

     ((*(byte *)(param_2[2] + 0x20) & 1) != 0)) {

    (**(code **)(**(int **)(param_1 + 0x58) + 0x14))(param_2);

    piVar5 = *(int **)(*(int *)(param_1 + 0x1c) + iVar2 * 4);

    if (piVar5 == (int *)0x0) {

      uVar4 = FUN_0072a3e0();

      FUN_007332b0(uVar4);

      piVar5 = *(int **)(*(int *)(param_1 + 0x1c) + iVar2 * 4);

    }

    *(uint8_t *)(param_1 + 0x68) = 1;

    *(uint8_t *)(param_1 + 0x69) = 1;

    uVar3 = (**(code **)(*piVar5 + 0x14))(param_2);

    return uVar3;

  }

  piVar5 = *(int **)(*(int *)(param_1 + 0xc) + iVar2 * 4);

  if (piVar5 == (int *)0x0) {

    for (piVar5 = *(int **)(DAT_00d1a600 + 0x10); piVar5 != *(int **)(DAT_00d1a600 + 0x14);

        piVar5 = piVar5 + 1) {

      iVar6 = *piVar5;

      if (*(int *)(iVar6 + 0x1c) == iVar2) goto LAB_00733733;

    }

    iVar6 = 0;

LAB_00733733:

    FUN_007332b0(iVar6);

    piVar5 = *(int **)(*(int *)(param_1 + 0xc) + iVar2 * 4);

  }

  *(uint8_t *)(param_1 + 0x68) = 1;

  uVar3 = (**(code **)(*piVar5 + 0x14))(param_2);

  return uVar3;

}
