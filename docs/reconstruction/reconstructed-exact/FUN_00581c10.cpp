// =============================================================================
// FUN_00581c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00581c10
// Address:   0x00581c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581c10 @ 0x00581c10
// Stable ID: aa_00581c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004e88e0, FUN_00581c10.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00581c10(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  

  if (*(int **)(param_1 + 8) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc))();

    *param_2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90);

    param_2[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94);

    param_2[2] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98);

    return param_2;

  }

  FUN_004e88e0(param_2,*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  return param_2;

}
