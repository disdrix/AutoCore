// =============================================================================
// FUN_0062c140
// -----------------------------------------------------------------------------
// Stable ID: aa_0062c140
// Address:   0x0062c140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062c140 @ 0x0062c140
// Stable ID: aa_0062c140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_005b3370, FUN_0062c140.
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

void FUN_0062c140(int param_1,int param_2,int param_3,int param_4,int *param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  

  if ((*(uint *)(param_4 + 0x18) & 1) == 0) {

    if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

      FUN_005b3370(param_5,8);

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(*param_5 + param_5[1] * 8);

    param_5[1] = param_5[1] + 1;

    *puVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

    puVar1[1] = *(uint32_t /* width from decompiler */ *)(param_4 + 0x18);

    return;

  }

  iVar2 = 0;

  param_1 = (*(uint *)(param_4 + 0x18) & 0xfffffffe) + param_1;

  if (0 < *(int *)(param_1 + 0xc)) {

    piVar3 = *(int **)(param_1 + 8);

    do {

      if (*piVar3 == param_3) goto LAB_0062c1b1;

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar2 < *(int *)(param_1 + 0xc));

  }

  iVar2 = -1;

LAB_0062c1b1:

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + iVar2 * 4) =

       *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 4);

  return;

}
