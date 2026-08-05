// =============================================================================
// FUN_00632430
// -----------------------------------------------------------------------------
// Stable ID: aa_00632430
// Address:   0x00632430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00632430 @ 0x00632430
// Stable ID: aa_00632430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00632430.
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

uint32_t /* width from decompiler */ __thiscall FUN_00632430(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(param_1 + 0xc) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))();

  }

  if (param_2 < iVar1) {

                    /* WARNING: Could not recover jumptable at 0x00632457. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();

    return uVar2;

  }

  return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + (param_2 - iVar1) * 4);

}
