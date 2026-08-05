// =============================================================================
// FUN_00628600
// -----------------------------------------------------------------------------
// Stable ID: aa_00628600
// Address:   0x00628600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00628600 @ 0x00628600
// Stable ID: aa_00628600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_00628600.
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

void __thiscall FUN_00628600(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  uint8_t local_10 [16];

  

  iVar3 = 0;

  if (0 < param_1[0x17]) {

    piVar4 = (int *)param_1[0x16];

    do {

      if ((int *)*piVar4 == param_2) goto LAB_00628628;

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar3 < param_1[0x17]);

  }

  iVar3 = -1;

LAB_00628628:

  param_1[0x17] = param_1[0x17] + -1;

  if (iVar3 < param_1[0x17]) {

    do {

      iVar2 = iVar3 * 4;

      iVar1 = iVar3 * 4;

      iVar3 = iVar3 + 1;

      *(uint32_t /* width from decompiler */ *)(param_1[0x16] + iVar1) = *(uint32_t /* width from decompiler */ *)(param_1[0x16] + 4 + iVar2);

    } while (iVar3 < param_1[0x17]);

  }

  (**(code **)(*param_2 + 0x28))(local_10);

  (**(code **)(*param_1 + 0xc))(param_2,&stack0xffffffec);

  *(uint8_t *)(param_1 + 10) = 1;

  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + -1;

  param_2[5] = 0;

  if (*(short *)((int)param_2 + 6) == 0) {

    (**(code **)*param_2)(1);

  }

  return;

}
