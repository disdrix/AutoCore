// =============================================================================
// FUN_00442d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00442d50
// Address:   0x00442d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00442d50 @ 0x00442d50
// Stable ID: aa_00442d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00442d50, FUN_00969a50.
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

void __thiscall FUN_00442d50(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(*(int *)(param_1 + 4) + 0xc) == 0) {

    uVar2 = 0;

  }

  else {

    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0xc);

    uVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,0,param_2);

  }

  FUN_00969a50(uVar2,*param_3,param_3[1],param_3[2],param_3[3]);

  return;

}
