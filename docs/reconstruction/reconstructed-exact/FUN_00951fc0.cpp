// =============================================================================
// FUN_00951fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00951fc0
// Address:   0x00951fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00951fc0 @ 0x00951fc0
// Stable ID: aa_00951fc0
// Embedded strings (evidence for future rename):
//   - "createitem"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007a4390, FUN_007a4400, FUN_00951fc0.
//  - Strings: "createitem".
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

uint32_t /* width from decompiler */ FUN_00951fc0(void)



{

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009b06b5;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  FUN_007a4400("createitem");

  local_14 = 0xffffffff;

  FUN_007a4390();

  ExceptionList = local_1c;

  return 0;

}
