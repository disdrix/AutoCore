// =============================================================================
// FUN_00817050
// -----------------------------------------------------------------------------
// Stable ID: aa_00817050
// Address:   0x00817050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00817050 @ 0x00817050
// Stable ID: aa_00817050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: ROUND×2, FUN_00816ee0, FUN_00817050, FUN_0087b500.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_00817050(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  

  if ((((param_3 == 40000) && (param_2 == 0x1a)) && (*(int **)(param_1 + 0x548) != (int *)0x0)) &&

     (*(int *)(param_1 + 0x540) < *(int *)(param_1 + 0x514))) {

    fVar3 = (float10)(**(code **)(**(int **)(param_1 + 0x548) + 0x458))();

    iVar2 = *(int *)(param_1 + 0x514) - *(int *)(param_1 + 0x540);

    fVar4 = (float10)iVar2;

    if (iVar2 < 0) {

      fVar4 = fVar4 + (float10)_DAT_00aaa5dc;

    }

    if (*(int *)(param_1 + 0x53c) != (int)ROUND(fVar4 * fVar3)) {

      *(int *)(param_1 + 0x53c) = (int)ROUND(fVar4 * fVar3);

      FUN_00816ee0();

    }

    return 1;

  }

  uVar1 = FUN_0087b500(param_2,param_3);

  return uVar1;

}
