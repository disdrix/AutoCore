// =============================================================================
// FUN_00483480
// -----------------------------------------------------------------------------
// Stable ID: aa_00483480
// Address:   0x00483480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00483480 @ 0x00483480
// Stable ID: aa_00483480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00483480.
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

void FUN_00483480(void)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0x25c);

  while (0 < iVar1) {

    *(uint8_t *)(*(int *)(in_EAX + 0x2c) + *(int *)(in_EAX + 0x4c)) =

         *(uint8_t *)(in_EAX + 0x25b);

    *(int *)(in_EAX + 0x4c) = *(int *)(in_EAX + 0x4c) + 1;

    *(int *)(in_EAX + 600) = *(int *)(in_EAX + 600) << 8;

    *(int *)(in_EAX + 0x25c) = *(int *)(in_EAX + 0x25c) + -8;

    iVar1 = *(int *)(in_EAX + 0x25c);

  }

  return;

}
