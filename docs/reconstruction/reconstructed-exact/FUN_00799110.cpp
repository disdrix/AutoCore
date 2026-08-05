// =============================================================================
// FUN_00799110
// -----------------------------------------------------------------------------
// Stable ID: aa_00799110
// Address:   0x00799110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00799110 @ 0x00799110
// Stable ID: aa_00799110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00799060×2, FUN_00799110.
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

void __fastcall FUN_00799110(uint32_t /* width from decompiler */ param_1,uint8_t *param_2)



{

  int *in_EAX;

  int local_4;

  

  if ((*(short *)*in_EAX != 0x4e) && (*(short *)*in_EAX != 0x6e)) {

    *param_2 = 0;

    FUN_00799060();

    return;

  }

  *param_2 = 1;

  local_4 = *in_EAX + 2;

  FUN_00799060(&local_4);

  return;

}
