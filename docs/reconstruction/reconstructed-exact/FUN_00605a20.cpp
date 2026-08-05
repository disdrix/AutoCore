// =============================================================================
// FUN_00605a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00605a20
// Address:   0x00605a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605a20 @ 0x00605a20
// Stable ID: aa_00605a20
// Embedded strings (evidence for future rename):
//   - "ed_entry_point_placeholder"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00540350, FUN_00605a20.
//  - Strings: "ed_entry_point_placeholder".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00605a20(void)



{

  int iVar1;

  

  iVar1 = FUN_00540350("ed_entry_point_placeholder");

  if (iVar1 != 0) {

    _DAT_00af48c0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    return;

  }

  _DAT_00af48c0 = 0xffffffff;

  return;

}
