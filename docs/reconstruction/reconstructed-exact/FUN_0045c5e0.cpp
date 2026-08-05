// =============================================================================
// FUN_0045c5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0045c5e0
// Address:   0x0045c5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045c5e0 @ 0x0045c5e0
// Stable ID: aa_0045c5e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0045c5e0, FUN_0045d280, FUN_0045f020.
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

void __thiscall FUN_0045c5e0(uint param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(unaff_EDI + 8) - iVar1 >> 4;

  }

  if (uVar2 < param_1) {

    FUN_0045d280(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),&param_2);

    return;

  }

  if (((iVar1 != 0) && (param_1 < (uint)(*(int *)(unaff_EDI + 8) - iVar1 >> 4))) &&

     (param_1 * 0x10 + iVar1 != *(int *)(unaff_EDI + 8))) {

    uVar3 = FUN_0045f020(param_2);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = uVar3;

  }

  return;

}
