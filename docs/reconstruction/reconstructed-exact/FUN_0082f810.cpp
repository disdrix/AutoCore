// =============================================================================
// FUN_0082f810
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f810
// Address:   0x0082f810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082f810 @ 0x0082f810
// Stable ID: aa_0082f810
// Embedded strings (evidence for future rename):
//   - "i_m_int_2d_btn_generic.xml"
//   - "Send a Tell"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0082f810.
//  - Strings: "i_m_int_2d_btn_generic.xml"; "Send a Tell".
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

void FUN_0082f810(void)



{

  int *piVar1;

  int *unaff_EDI;

  

  piVar1 = (int *)(**(code **)(*unaff_EDI + 0x444))

                            ("i_m_int_2d_btn_generic.xml",0,0x11176,0xffffffff);

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 0x1d8))("Send a Tell",1,1);

  }

  unaff_EDI[0x155] = (int)piVar1;

  return;

}
