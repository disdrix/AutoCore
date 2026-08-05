// =============================================================================
// FUN_007f9df0
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9df0
// Address:   0x007f9df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f9df0 @ 0x007f9df0
// Stable ID: aa_007f9df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007f9cc0, FUN_007f9df0.
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

void __fastcall FUN_007f9df0(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = param_1;

  if (in_EAX == 0) {

    if (*(char *)((int)unaff_EDI + 0x489) == '\0') {

      (**(code **)(*unaff_EDI + 0x15c))(0,unaff_EDI + 0x139);

      (**(code **)(*unaff_EDI + 0x34c))();

    }

  }

  else if ((in_EAX == 5) && (*(char *)((int)unaff_EDI + 0x489) == '\0')) {

    local_4 = 0xffff0000;

    (**(code **)(*unaff_EDI + 0x15c))(0,&local_4);

    (**(code **)(*unaff_EDI + 0x34c))();

  }

  unaff_EDI[0x13a] = 0;

  unaff_EDI[0x13b] = in_EAX;

  if (unaff_EDI[0x13c] != (&DAT_00afa098)[in_EAX]) {

    FUN_007f9cc0();

  }

  return;

}
