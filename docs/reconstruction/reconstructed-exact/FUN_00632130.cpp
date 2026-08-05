// =============================================================================
// FUN_00632130
// -----------------------------------------------------------------------------
// Stable ID: aa_00632130
// Address:   0x00632130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00632130 @ 0x00632130
// Stable ID: aa_00632130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005b3300, FUN_00632130.
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

void __fastcall FUN_00632130(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 4) = 0;

  iVar1 = *(int *)(param_1 + 8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  iVar3 = *(int *)(iVar1 + 4) + 1;

  uVar4 = *(uint *)(iVar1 + 8) & 0x7fffffff;

  if ((int)uVar4 < iVar3) {

    iVar2 = uVar4 * 2;

    if (iVar3 < iVar2) {

      iVar3 = iVar2;

    }

    FUN_005b3300(iVar1,iVar3,1);

  }

  *(uint8_t *)((*(int **)(param_1 + 8))[1] + **(int **)(param_1 + 8)) = 0;

  return;

}
