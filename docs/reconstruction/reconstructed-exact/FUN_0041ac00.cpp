// =============================================================================
// FUN_0041ac00
// -----------------------------------------------------------------------------
// Stable ID: aa_0041ac00
// Address:   0x0041ac00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041ac00 @ 0x0041ac00
// Stable ID: aa_0041ac00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_0041ac00, FUN_0041c500.
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

void FUN_0041ac00(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ auStack_11c [33];

  uint32_t /* width from decompiler */ local_8a [33];

  

  puVar2 = local_8a;

  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint16_t *)puVar2 = 0;

  puVar2 = local_8a;

  puVar3 = auStack_11c;

  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  *(uint16_t *)puVar3 = *(uint16_t *)puVar2;

  FUN_0041c500();

  return;

}
