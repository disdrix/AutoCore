// =============================================================================
// FUN_0046bf40
// -----------------------------------------------------------------------------
// Stable ID: aa_0046bf40
// Address:   0x0046bf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046bf40 @ 0x0046bf40
// Stable ID: aa_0046bf40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0046bf40, FUN_0046bf90, FUN_0046c1b0.
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

int __fastcall FUN_0046bf40(int param_1)



{

  int *in_EAX;

  int *piVar1;

  int local_10 [2];

  uint8_t local_8 [8];

  

  FUN_0046c1b0();

  if (local_10[0] == *(int *)(param_1 + 8)) {

    local_10[0] = *in_EAX;

    local_10[1] = 0;

    piVar1 = (int *)FUN_0046bf90(local_8,local_10);

    local_10[0] = *piVar1;

  }

  return local_10[0] + 0xc;

}
