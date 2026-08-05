// =============================================================================
// FUN_005a2120
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2120
// Address:   0x005a2120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a2120 @ 0x005a2120
// Stable ID: aa_005a2120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005a2120, free.
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

void __thiscall FUN_005a2120(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t param_4)



{

  if (*(char *)(param_1 + 0x14) != '\0') {

    *(uint8_t *)(param_1 + 0x14) = 0;

    free(*(void **)(param_1 + 0xc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = param_3;

  *(uint8_t *)(param_1 + 0x14) = param_4;

  return;

}
