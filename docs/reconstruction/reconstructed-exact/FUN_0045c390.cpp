// =============================================================================
// FUN_0045c390
// -----------------------------------------------------------------------------
// Stable ID: aa_0045c390
// Address:   0x0045c390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045c390 @ 0x0045c390
// Stable ID: aa_0045c390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0045c390, FUN_0045c6e0, FUN_0045c730.
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

void __fastcall FUN_0045c390(uint param_1)



{

  int iVar1;

  uint uVar2;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(unaff_EDI + 8) - iVar1) / 0x2c;

  }

  if (uVar2 < param_1) {

    FUN_0045c730(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),&stack0x00000004);

    return;

  }

  if ((iVar1 != 0) && (param_1 < (uint)((*(int *)(unaff_EDI + 8) - iVar1) / 0x2c))) {

    FUN_0045c6e0(unaff_EDI,&stack0x00000004,iVar1 + param_1 * 0x2c,*(int *)(unaff_EDI + 8));

  }

  return;

}
