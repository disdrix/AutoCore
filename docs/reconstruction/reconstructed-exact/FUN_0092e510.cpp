// =============================================================================
// FUN_0092e510
// -----------------------------------------------------------------------------
// Stable ID: aa_0092e510
// Address:   0x0092e510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092e510 @ 0x0092e510
// Stable ID: aa_0092e510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0048ed90, FUN_0048edc0, FUN_0092e510.
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

uint32_t /* width from decompiler */ FUN_0092e510(void)



{

  int *piVar1;

  int in_EAX;

  int iVar2;

  

  piVar1 = (int *)**(uint32_t /* width from decompiler */ **)(*(int *)(in_EAX + 0xde8) + 0x28);

  iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);

  if ((iVar2 != -0x7789f7d9) && (iVar2 != -0x7789f798)) {

    if (iVar2 != -0x7789f797) {

      return 1;

    }

    if (*(int *)(in_EAX + 0xe04) != 0) {

      FUN_0048ed90();

    }

    iVar2 = (**(code **)(**(int **)(in_EAX + 0xde8) + 4))();

    if ((iVar2 == 0) && (*(int *)(in_EAX + 0xe04) != 0)) {

      FUN_0048edc0();

    }

  }

  return 0;

}
