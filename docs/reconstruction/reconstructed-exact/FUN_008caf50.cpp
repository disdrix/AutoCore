// =============================================================================
// FUN_008caf50
// -----------------------------------------------------------------------------
// Stable ID: aa_008caf50
// Address:   0x008caf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008caf50 @ 0x008caf50
// Stable ID: aa_008caf50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_008caf50.
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

void FUN_008caf50(void)



{

  int in_EAX;

  uint8_t *puVar1;

  int iVar2;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x558) = 0;

  puVar1 = (uint8_t *)(in_EAX + 0x574);

  iVar2 = 0x10;

  do {

    *(uint32_t /* width from decompiler */ *)(puVar1 + -0x10) = 0xffffffff;

    *puVar1 = 0;

    *(uint16_t *)(puVar1 + -8) = 0;

    puVar1 = puVar1 + 0x3c;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
