// =============================================================================
// FUN_009c3150
// -----------------------------------------------------------------------------
// Stable ID: aa_009c3150
// Address:   0x009c3150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009c3150 @ 0x009c3150
// Stable ID: aa_009c3150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_009c3150, free.
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

void FUN_009c3150(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint8_t *puVar2;

  int iVar3;

  

  puVar2 = &DAT_00d1eaa0;

  iVar3 = 0xc;

  do {

    puVar1 = (uint32_t /* width from decompiler */ *)(puVar2 + -0xc);

    puVar2 = puVar2 + -0xc;

    free((void *)*puVar1);

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
