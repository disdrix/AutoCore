// =============================================================================
// FUN_0083ee80
// -----------------------------------------------------------------------------
// Stable ID: aa_0083ee80
// Address:   0x0083ee80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083ee80 @ 0x0083ee80
// Stable ID: aa_0083ee80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0083ee80.
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

void FUN_0083ee80(void)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *unaff_ESI;

  int unaff_EDI;

  int iStack_20;

  uint8_t auStack_10 [4];

  int iStack_c;

  uint8_t local_8 [4];

  int iStack_4;

  

  iStack_20 = 1;

  piVar1 = (int *)(**(code **)(*unaff_ESI + 0x140))();

  iVar3 = *piVar1;

  piVar1 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(auStack_10);

  iStack_20 = iStack_4 + iStack_c;

  if (*piVar1 < iStack_20 + iVar3) {

    iStack_20 = iStack_c - iVar3;

  }

  if (iStack_20 < 0) {

    iStack_20 = 0;

  }

  else {

    piVar1 = (int *)(**(code **)(*unaff_ESI + 0x140))(&iStack_c,1);

    iVar3 = *piVar1;

    piVar1 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&iStack_c,1);

    if (*piVar1 < iVar3 + 1) {

      piVar1 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&iStack_c,1);

      piVar2 = (int *)(**(code **)(*unaff_ESI + 0x140))(&iStack_c,1);

      iStack_20 = *piVar1 - *piVar2;

    }

  }

  if (-1 < unaff_EDI) {

    iVar3 = (**(code **)(*unaff_ESI + 0x140))(&iStack_c,1);

    iVar3 = *(int *)(iVar3 + 4);

    iVar4 = (**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&iStack_c,1);

    if (*(int *)(iVar4 + 4) < (int)(local_8 + iVar3)) {

      piVar1 = (int *)*DAT_00d1b780;

      (**(code **)(*unaff_ESI + 0x140))(&iStack_c,1);

      (**(code **)(*piVar1 + 0x140))(&iStack_c,1);

    }

  }

  (**(code **)(*unaff_ESI + 0x118))(&iStack_20);

  return;

}
