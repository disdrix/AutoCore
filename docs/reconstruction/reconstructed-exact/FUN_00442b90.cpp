// =============================================================================
// FUN_00442b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00442b90
// Address:   0x00442b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00442b90 @ 0x00442b90
// Stable ID: aa_00442b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00442b90.
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

void FUN_00442b90(int param_1)



{

  char cVar1;

  int iVar2;

  

  if ((DAT_00d1a54c != 0) && (iVar2 = *(int *)(DAT_00d1a54c + 0x3c), iVar2 != 0)) {

    *(int *)(iVar2 + 0xdc) = *(int *)(iVar2 + 0xdc) + 1;

    *(uint8_t *)(iVar2 + 0xd1) = 0;

  }

  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x3c), iVar2 != 0)) {

    cVar1 = *(char *)(DAT_00d1f048 + 0xf);

    *(int *)(iVar2 + 0xdc) = *(int *)(iVar2 + 0xdc) + 1;

    *(bool *)(iVar2 + 0xd1) = cVar1 != '\0';

  }

  DAT_00d1a54c = param_1;

  return;

}
