// =============================================================================
// FUN_005db160
// -----------------------------------------------------------------------------
// Stable ID: aa_005db160
// Address:   0x005db160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005db160 @ 0x005db160
// Stable ID: aa_005db160
// Embedded strings (evidence for future rename):
//   - "ed_trigger_point_placeholder"
//   - "ed_trigger_music_placeholder"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00540350×2, FUN_005db160.
//  - Strings: "ed_trigger_point_placeholder"; "ed_trigger_music_placeholder".
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



void FUN_005db160(void)



{

  int iVar1;

  

  iVar1 = FUN_00540350("ed_trigger_point_placeholder");

  if (iVar1 == 0) {

    DAT_00bc5684 = 0xffffffff;

  }

  else {

    DAT_00bc5684 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  }

  iVar1 = FUN_00540350("ed_trigger_music_placeholder");

  if (iVar1 != 0) {

    _DAT_00bc5680 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    return;

  }

  _DAT_00bc5680 = 0xffffffff;

  return;

}
