// =============================================================================
// FUN_00649c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00649c60
// Address:   0x00649c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00649c60 @ 0x00649c60
// Stable ID: aa_00649c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00646360, FUN_00649c60.
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

void FUN_00649c60(void)



{

  uint8_t *puVar1;

  undefined *puVar2;

  uint32_t /* width from decompiler */ local_30 [12];

  

  puVar2 = &DAT_00d032ac;

  puVar1 = &stack0xffffffc8;

  do {

    FUN_00646360(puVar2);

    puVar2 = *(undefined **)(puVar1 + 8);

    puVar1 = puVar1 + 4;

  } while (puVar2 != (undefined *)0x0);

  return;

}
