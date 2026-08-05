// =============================================================================
// FUN_0096c2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096c2c0
// Address:   0x0096c2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096c2c0 @ 0x0096c2c0
// Stable ID: aa_0096c2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0043fb50, FUN_0096c2c0, NDResource_AcquireInnerObject.
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

void __fastcall FUN_0096c2c0(int param_1)



{

  int local_c;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 0x48) != 0) {

    NDResource_AcquireInnerObject();

  }

  local_c = param_1 + -4;

  FUN_0043fb50(local_8,&local_c);

  return;

}
