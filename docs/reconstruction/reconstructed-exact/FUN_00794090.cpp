// =============================================================================
// FUN_00794090
// -----------------------------------------------------------------------------
// Stable ID: aa_00794090
// Address:   0x00794090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00794090 @ 0x00794090
// Stable ID: aa_00794090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00794090, __RTDynamicCast.
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

void FUN_00794090(void)



{

  char in_AL;

  int *piVar1;

  int *unaff_ESI;

  

  *(char *)((int)unaff_ESI + 0x489) = in_AL;

  if (in_AL != '\0') {

    piVar1 = (int *)(**(code **)(*unaff_ESI + 0x170))(0xb);

    unaff_ESI[0x8b] = *piVar1;

    piVar1 = (int *)__RTDynamicCast(unaff_ESI[0xac],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                    &CNDUIDialog::RTTI_Type_Descriptor,0);

    if ((piVar1 != (int *)0x0) && ((int *)piVar1[0x12f] == unaff_ESI)) {

      (**(code **)(*piVar1 + 0x1c8))(0);

      (**(code **)(*piVar1 + 0x3c0))(0);

    }

    return;

  }

  piVar1 = (int *)(**(code **)(*unaff_ESI + 0x170))(3);

  unaff_ESI[0x8b] = *piVar1;

  return;

}
