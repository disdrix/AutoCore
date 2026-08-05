// =============================================================================
// FUN_00464a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00464a50
// Address:   0x00464a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00464a50 @ 0x00464a50
// Stable ID: aa_00464a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00464a50, FUN_00972f10.
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

void FUN_00464a50(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_ESI;

  uint8_t local_c [12];

  

  if (*(int *)(unaff_ESI + 0xc4) != *(int *)(unaff_ESI + 8)) {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00972f10(local_c,unaff_ESI + 0x184);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 400) = *puVar2;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x194) = puVar2[1];

    uVar1 = puVar2[2];

    *(int *)(unaff_ESI + 0xdc) = *(int *)(unaff_ESI + 0xdc) + 1;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x198) = uVar1;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc4);

  }

  return;

}
