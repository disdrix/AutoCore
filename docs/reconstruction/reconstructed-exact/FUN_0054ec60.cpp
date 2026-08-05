// =============================================================================
// FUN_0054ec60
// -----------------------------------------------------------------------------
// Stable ID: aa_0054ec60
// Address:   0x0054ec60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054ec60 @ 0x0054ec60
// Stable ID: aa_0054ec60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, while×1.
//  - Notable callees: FUN_00537da0, FUN_0054d780, FUN_0054e390, FUN_0054ec60.
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

void __thiscall FUN_0054ec60(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = param_4;

  piVar1 = *(int **)(param_1 + 4);

  if ((param_3 == (int *)*piVar1) && (param_4 == piVar1)) {

    FUN_0054d780(piVar1[1]);

    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);

    *param_2 = **(uint32_t /* width from decompiler */ **)(param_1 + 4);

    return;

  }

  while (param_3 != piVar2) {

    FUN_00537da0();

    FUN_0054e390(&param_4,param_3);

  }

  *param_2 = param_3;

  return;

}
