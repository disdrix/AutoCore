// =============================================================================
// FUN_00477690
// -----------------------------------------------------------------------------
// Stable ID: aa_00477690
// Address:   0x00477690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477690 @ 0x00477690
// Stable ID: aa_00477690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00477690, free.
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

void __fastcall FUN_00477690(code *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *in_EAX;

  uint8_t local_26c [580];

  uint32_t /* width from decompiler */ local_28;

  

  if (in_EAX != (void *)0x0) {

    if (param_1 != (code *)0x0) {

      local_28 = param_2;

      (*param_1)(local_26c);

      return;

    }

    free(in_EAX);

  }

  return;

}
