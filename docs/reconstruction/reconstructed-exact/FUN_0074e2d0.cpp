// =============================================================================
// FUN_0074e2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e2d0
// Address:   0x0074e2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074e2d0 @ 0x0074e2d0
// Stable ID: aa_0074e2d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_0074e2d0, FUN_00967b10, FUN_00967cc0.
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

void FUN_0074e2d0(void)



{

  int *piVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ unaff_EBX;

  int *piVar2;

  

  FUN_00967cc0(unaff_EBX);

  piVar1 = *(int **)(in_EAX + 0xc);

  for (piVar2 = *(int **)(in_EAX + 8); piVar2 != piVar1; piVar2 = piVar2 + 1) {

    if (*(char *)(*piVar2 + 0xd0) != '\0') {

      FUN_00967b10(unaff_EBX,*piVar2);

    }

  }

  return;

}
