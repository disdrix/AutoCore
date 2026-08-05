// =============================================================================
// FUN_004c99e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c99e0
// Address:   0x004c99e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c99e0 @ 0x004c99e0
// Stable ID: aa_004c99e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0043fb00×2, FUN_004cb6f0×2, FUN_004c99e0.
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

void __thiscall FUN_004c99e0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  iVar2 = param_2;

  iVar1 = *(int *)(param_1 + 0x1c0);

  FUN_004cb6f0(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc),iVar1,param_2);

  if (param_2 != iVar1) {

    FUN_0043fb00(param_2 + 0x10,iVar1,param_2,param_2);

    *(int *)(param_1 + 0x1c0) = *(int *)(param_1 + 0x1c0) + -0x10;

  }

  iVar1 = *(int *)(param_1 + 0x1d0);

  piVar3 = (int *)FUN_004cb6f0(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1cc),iVar1,iVar2);

  iVar2 = *piVar3;

  if (iVar2 != iVar1) {

    FUN_0043fb00(iVar2 + 0x10,iVar1,iVar2,param_2);

    *(int *)(param_1 + 0x1d0) = *(int *)(param_1 + 0x1d0) + -0x10;

  }

  return;

}
