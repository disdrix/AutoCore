// =============================================================================
// FUN_00418690
// -----------------------------------------------------------------------------
// Stable ID: aa_00418690
// Address:   0x00418690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00418690 @ 0x00418690
// Stable ID: aa_00418690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00418690, FUN_00419880, FUN_00456660.
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

void __fastcall FUN_00418690(uint param_1)



{

  int iVar1;

  uint uVar2;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(unaff_ESI + 8) - iVar1 >> 2;

  }

  if (uVar2 < param_1) {

    FUN_00419880(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),&stack0x00000004);

    return;

  }

  if ((iVar1 != 0) && (param_1 < (uint)(*(int *)(unaff_ESI + 8) - iVar1 >> 2))) {

    FUN_00456660(unaff_ESI,iVar1 + param_1 * 4,*(int *)(unaff_ESI + 8));

  }

  return;

}
