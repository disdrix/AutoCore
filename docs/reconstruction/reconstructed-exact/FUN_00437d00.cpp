// =============================================================================
// FUN_00437d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00437d00
// Address:   0x00437d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00437d00 @ 0x00437d00
// Stable ID: aa_00437d00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00437d00, FUN_00438d80, FUN_0043a660.
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

void __fastcall FUN_00437d00(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(unaff_ESI + 8) - iVar1 >> 3) < (uint)(*(int *)(unaff_ESI + 0xc) - iVar1 >> 3))

     ) {

    iVar1 = *(int *)(unaff_ESI + 8);

    FUN_0043a660(iVar1,param_1);

    *(int *)(unaff_ESI + 8) = iVar1 + 8;

    return;

  }

  FUN_00438d80(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),1,param_1);

  return;

}
