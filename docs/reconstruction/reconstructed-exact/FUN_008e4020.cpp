// =============================================================================
// FUN_008e4020
// -----------------------------------------------------------------------------
// Stable ID: aa_008e4020
// Address:   0x008e4020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e4020 @ 0x008e4020
// Stable ID: aa_008e4020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_008e4020.
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

int FUN_008e4020(void)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int *unaff_ESI;

  int iVar4;

  

  iVar4 = 0;

  uVar3 = 0;

  iVar2 = 1;

  if ((*unaff_ESI != 0) && (iVar1 = *(int *)(*unaff_ESI + 0xa8), *(int *)(iVar1 + 0x38) == 0x1a)) {

    uVar3 = (uint)*(byte *)(*(int *)(iVar1 + 0x3c) + 0x4c8);

    iVar2 = 2;

  }

  if ((unaff_ESI[1] != 0) && (iVar1 = *(int *)(unaff_ESI[1] + 0xa8), *(int *)(iVar1 + 0x38) == 0x1a)

     ) {

    uVar3 = uVar3 + *(byte *)(*(int *)(iVar1 + 0x3c) + 0x4c8);

    iVar2 = iVar2 + 1;

  }

  if ((unaff_ESI[2] != 0) && (iVar1 = *(int *)(unaff_ESI[2] + 0xa8), *(int *)(iVar1 + 0x38) == 0x1a)

     ) {

    uVar3 = uVar3 + *(byte *)(*(int *)(iVar1 + 0x3c) + 0x4c8);

    iVar2 = iVar2 + 1;

  }

  if ((unaff_ESI[3] != 0) && (iVar1 = *(int *)(unaff_ESI[3] + 0xa8), *(int *)(iVar1 + 0x38) == 0x1a)

     ) {

    uVar3 = uVar3 + *(byte *)(*(int *)(iVar1 + 0x3c) + 0x4c8);

    iVar2 = iVar2 + 1;

  }

  if ((unaff_ESI[4] != 0) && (iVar1 = *(int *)(unaff_ESI[4] + 0xa8), *(int *)(iVar1 + 0x38) == 0x1a)

     ) {

    uVar3 = uVar3 + *(byte *)(*(int *)(iVar1 + 0x3c) + 0x4c8);

    iVar2 = iVar2 + 1;

  }

  iVar1 = 0;

  if (iVar2 != 0) {

    do {

      iVar4 = iVar4 + iVar1;

      iVar1 = iVar1 + 1;

    } while (iVar1 < iVar2);

  }

  return uVar3 + iVar4;

}
