// =============================================================================
// FUN_00418d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00418d40
// Address:   0x00418d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00418d40 @ 0x00418d40
// Stable ID: aa_00418d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418d40.
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

uint32_t /* width from decompiler */ __fastcall FUN_00418d40(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x124);

  if ((puVar1 != (uint32_t /* width from decompiler */ *)0x0) && (*(int *)(param_1 + 0x128) - (int)puVar1 >> 2 != 0)) {

    return *puVar1;

  }

  return 0;

}
