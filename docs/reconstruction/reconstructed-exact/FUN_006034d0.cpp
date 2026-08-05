// =============================================================================
// FUN_006034d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006034d0
// Address:   0x006034d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006034d0 @ 0x006034d0
// Stable ID: aa_006034d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_0040f5b0, FUN_006034d0.
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

int FUN_006034d0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  if (param_1 == param_2) {

    return param_3;

  }

  do {

    iVar1 = param_2 + -0x18;

    iVar2 = param_3 + -0x18;

    FUN_0040f5b0(iVar1);

    *(uint32_t /* width from decompiler */ *)(param_3 + -8) = *(uint32_t /* width from decompiler */ *)(param_2 + -8);

    *(uint32_t /* width from decompiler */ *)(param_3 + -4) = *(uint32_t /* width from decompiler */ *)(param_2 + -4);

    param_2 = iVar1;

    param_3 = iVar2;

  } while (iVar1 != param_1);

  return iVar2;

}
