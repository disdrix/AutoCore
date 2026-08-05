// =============================================================================
// FUN_00632580
// -----------------------------------------------------------------------------
// Stable ID: aa_00632580
// Address:   0x00632580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00632580 @ 0x00632580
// Stable ID: aa_00632580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00632580.
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

uint32_t /* width from decompiler */ __thiscall FUN_00632580(int param_1,uint32_t /* width from decompiler */ param_2)



{

  code *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((*(uint32_t /* width from decompiler */ **)(param_1 + 0x10) != (uint32_t /* width from decompiler */ *)0x0) &&

     (pcVar1 = (code *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x10), pcVar1 != (code *)0x0)) {

    uVar2 = (*pcVar1)(param_2);

    return uVar2;

  }

  return 0;

}
