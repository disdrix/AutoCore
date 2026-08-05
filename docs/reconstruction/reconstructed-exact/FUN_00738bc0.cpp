// =============================================================================
// FUN_00738bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00738bc0
// Address:   0x00738bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00738bc0 @ 0x00738bc0
// Stable ID: aa_00738bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00737cf0, FUN_007385d0, FUN_00738bc0, FUN_00967150.
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

uint8_t FUN_00738bc0(void)



{

  int iVar1;

  uint8_t uVar2;

  int unaff_EBX;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (*(int *)(iVar1 + 0x34) == 0) {

    FUN_00967150(iVar1 + 0x24);

  }

  iVar1 = *(int *)(iVar1 + 0x38);

  if (*(char *)(unaff_EBX + 0xcc) != '\0') {

    if ((0 < iVar1) && (iVar1 < 4)) {

      (*(code *)(&PTR_LAB_00afa3fc)[iVar1])();

      return 1;

    }

    FUN_007385d0(unaff_EBX,unaff_EDI);

    return 1;

  }

  if ((0 < iVar1) && (iVar1 < 4)) {

    uVar2 = (*(code *)(&PTR_LAB_00afa418)[iVar1])();

    return uVar2;

  }

  uVar2 = FUN_00737cf0(unaff_EBX,unaff_EDI);

  return uVar2;

}
