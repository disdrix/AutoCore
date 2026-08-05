// =============================================================================
// FUN_0040b410
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b410
// Address:   0x0040b410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040b410 @ 0x0040b410
// Stable ID: aa_0040b410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040b410, FUN_0040bc10.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040b410; evidence only — no invented semantics):
//  - Entry: `void FUN_0040b410(void)`.
//  - Calls: FUN_0040bc10(local_4,**(in_EAX + 4),*(in_EAX + 4)); operator_delete(*(in_EAX + 4)).
//  - Void function; no value return in raw.




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

void FUN_0040b410(void)



{

  int in_EAX;

  uint8_t local_4 [4];

  

  FUN_0040bc10(local_4,**(uint32_t /* width from decompiler */ **)(in_EAX + 4),*(uint32_t /* width from decompiler */ **)(in_EAX + 4));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(in_EAX + 4));

}
