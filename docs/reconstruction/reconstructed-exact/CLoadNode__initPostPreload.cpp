// =============================================================================
// CLoadNode__initPostPreload
// -----------------------------------------------------------------------------
// Stable ID: aa_005c69e0
// Address:   0x005c69e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CLoadNode__initPostPreload @ 0x005c69e0
// Stable ID: aa_005c69e0
// Embedded strings (evidence for future rename):
//   - "CLoadNode::_initPostPreload"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CLoadNode__initPostPreload, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CLoadNode::_initPostPreload".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CLoadNode::_initPostPreload"
 * Domain alias of FUN_005c69e0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall CLoadNode__initPostPreload(int param_1)



{

  FUN_0076cf00("CLoadNode::_initPostPreload");

  *(uint8_t *)(param_1 + 0x68) = 0;

  FUN_0076cef0();

  return 0;

}
