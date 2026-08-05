// =============================================================================
// FUN_00606380
// -----------------------------------------------------------------------------
// Stable ID: aa_00606380
// Address:   0x00606380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00606380 @ 0x00606380
// Stable ID: aa_00606380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00508390, FUN_00606380.
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

void __fastcall FUN_00606380(int param_1)



{

  if (*(void **)(param_1 + 0x660) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x660));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x660) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x664) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x668) = 0;

  FUN_00508390();

  return;

}
