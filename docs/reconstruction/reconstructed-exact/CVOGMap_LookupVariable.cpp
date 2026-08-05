// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, goto×2, do×1, while×1.
//  - Notable callees: CONCAT31, CVOGMap_LookupVariable, CVOGVariable_EvaluateComputed.
//  - Return sites: 3.

// =============================================================================
// CVOGMap_LookupVariable
// -----------------------------------------------------------------------------
// Stable ID: aa_005b05f0
// Address:   0x005b05f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

uint32_t /* width from decompiler */ __thiscall CVOGMap_LookupVariable(int param_1,uint param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4) + 4);

  if (iVar1 == 0) {

LAB_005b061a:

    iVar1 = 0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar1 + 0x10)) {

        if (iVar1 == 0) goto LAB_005b061a;

        iVar1 = *(int *)(iVar1 + 8);

        goto LAB_005b0621;

      }

      iVar1 = *(int *)(iVar1 + 0xc);

    } while (iVar1 != 0);

    iVar1 = 0;

  }

LAB_005b0621:

  if (iVar1 == 0) {

    return 0;

  }

  if (*(char *)(iVar1 + 0x40) == '\0') {

    *param_3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x48);

    return CONCAT31((int3)((uint)iVar1 >> 8),1);

  }

  uVar2 = CVOGVariable_EvaluateComputed();

  return uVar2;

}
