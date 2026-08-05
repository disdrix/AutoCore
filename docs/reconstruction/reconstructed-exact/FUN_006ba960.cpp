// =============================================================================
// FUN_006ba960
// -----------------------------------------------------------------------------
// Stable ID: aa_006ba960
// Address:   0x006ba960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ba960 @ 0x006ba960
// Stable ID: aa_006ba960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006ba750, FUN_006ba960, FUN_006bdc70, FUN_006c0520.
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

void FUN_006ba960(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  uint8_t local_410 [4];

  uint32_t /* width from decompiler */ local_40c;

  int local_404;

  

  FUN_006c0520();

  FUN_006ba750(param_1,local_410,param_2);

  FUN_006bdc70(local_410,param_2);

  if (-1 < local_404) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_40c,local_404 << 3,0x12);

  }

  return;

}
