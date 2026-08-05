// =============================================================================
// FUN_005678d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005678d0
// Address:   0x005678d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005678d0 @ 0x005678d0
// Stable ID: aa_005678d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, while×1.
//  - Notable callees: FUN_0040c1b0, FUN_00567050, FUN_005673e0, FUN_005678d0.
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

void __thiscall FUN_005678d0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = param_4;

  piVar1 = *(int **)(param_1 + 4);

  if ((param_3 == (int *)*piVar1) && (param_4 == piVar1)) {

    FUN_005673e0(piVar1[1]);

    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);

    *param_2 = **(uint32_t /* width from decompiler */ **)(param_1 + 4);

    return;

  }

  while (param_3 != piVar2) {

    FUN_0040c1b0();

    FUN_00567050(&param_4,param_3);

  }

  *param_2 = param_3;

  return;

}
