// =============================================================================
// FUN_0069c310
// -----------------------------------------------------------------------------
// Stable ID: aa_0069c310
// Address:   0x0069c310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069c310 @ 0x0069c310
// Stable ID: aa_0069c310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0069ac30, FUN_0069b9f0, FUN_0069c310.
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

void __thiscall FUN_0069c310(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x18) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x18))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_0069ac30(iVar1,1,param_2,param_1,param_2);

    *(int *)(param_1 + 8) = iVar1 + 0x18;

    return;

  }

  FUN_0069b9f0(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

  return;

}
