// =============================================================================
// FUN_009729d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009729d0
// Address:   0x009729d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009729d0 @ 0x009729d0
// Stable ID: aa_009729d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076f240, FUN_009729d0.
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

void FUN_009729d0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_20 = *param_1;

  local_1c = param_1[1];

  local_18 = param_1[2];

  local_14 = 0;

  FUN_0076f240(&local_20);

  *param_1 = local_20;

  param_1[1] = local_1c;

  param_1[2] = local_18;

  return;

}
