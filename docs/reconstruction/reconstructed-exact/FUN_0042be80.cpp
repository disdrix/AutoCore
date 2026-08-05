// =============================================================================
// FUN_0042be80
// -----------------------------------------------------------------------------
// Stable ID: aa_0042be80
// Address:   0x0042be80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042be80 @ 0x0042be80
// Stable ID: aa_0042be80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00424d10, FUN_0042b810, FUN_0042be80, FUN_0098b8b0, malloc.
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

void FUN_0042be80(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  undefined **local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4;

  

  in_EAX[1] = 0;

  in_EAX[2] = 0;

  *in_EAX = &PTR_LAB_00a9b370;

  in_EAX[6] = 0;

  in_EAX[7] = 0;

  local_14 = 0;

  local_10 = 0;

  local_18 = &PTR_LAB_009d7b00;

  local_8 = 0x5dc;

  local_c = malloc(0x5dc);

  local_4 = 1;

  FUN_0042b810(param_1);

  FUN_0098b8b0(&local_18);

  FUN_00424d10();

  return;

}
