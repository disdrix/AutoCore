// =============================================================================
// FUN_007f7060
// -----------------------------------------------------------------------------
// Stable ID: aa_007f7060
// Address:   0x007f7060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f7060 @ 0x007f7060
// Stable ID: aa_007f7060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, return×1.
//  - Notable callees: FUN_007f7060.
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

void __fastcall FUN_007f7060(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint8_t *puVar1;

  int iVar2;

  

  puVar1 = (uint8_t *)(param_2 + 0xb);

  iVar2 = 5;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 0x34;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint8_t *)(param_2 + 0x10f);

  iVar2 = 6;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 0x34;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint8_t *)(param_2 + 0x247);

  iVar2 = 0x78;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 0x34;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint8_t *)(param_2 + 0x1aa7);

  iVar2 = 0x14;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 0x34;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
