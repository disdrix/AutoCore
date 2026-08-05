// =============================================================================
// FUN_00433440
// -----------------------------------------------------------------------------
// Stable ID: aa_00433440
// Address:   0x00433440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00433440 @ 0x00433440
// Stable ID: aa_00433440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00433440.
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

void FUN_00433440(uint8_t param_1,uint8_t param_2,uint8_t param_3,uint8_t param_4)



{

  int iVar1;

  int iVar2;

  uint in_EAX;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 4);

  if (((iVar1 != 0) && (*(uint *)(unaff_ESI + 0x28) != 0)) &&

     ((in_EAX & 0xff) < *(uint *)(unaff_ESI + 0x28))) {

    iVar2 = (in_EAX & 0xff) * 4;

    *(uint8_t *)(iVar2 + 0x28 + iVar1) = param_3;

    *(uint8_t *)(iVar2 + 0x29 + iVar1) = param_2;

    *(uint8_t *)(iVar2 + 0x2a + iVar1) = param_1;

    *(uint8_t *)(iVar2 + 0x2b + iVar1) = param_4;

    *(uint8_t *)(unaff_ESI + 0x1a1) = 0;

  }

  return;

}
