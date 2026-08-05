// =============================================================================
// FUN_0079d700
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d700
// Address:   0x0079d700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079d700 @ 0x0079d700
// Stable ID: aa_0079d700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00782860, FUN_00782bb0, FUN_0079d700.
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

uint FUN_0079d700(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  uVar1 = FUN_00782860();

  if (uVar1 != 0) {

    return uVar1 & 0xffffff00;

  }

  puVar2 = operator_new(0x1c);

  puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2[1] = 0;

    puVar2[2] = 0;

    puVar2[3] = 0;

    puVar2[4] = 0;

    puVar2[5] = 0;

    *(uint8_t *)(puVar2 + 6) = 1;

    *puVar2 = &PTR_FUN_00a97b1c;

    puVar3 = puVar2;

  }

  puVar3[5] = in_EAX;

  *(uint8_t *)(puVar3 + 6) = 1;

  uVar1 = FUN_00782bb0();

  return uVar1;

}
