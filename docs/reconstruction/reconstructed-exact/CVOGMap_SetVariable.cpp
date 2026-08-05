// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, goto×2, while×2, return×1.
//  - Notable callees: CVOGMap_SetVariable, CVOGReaction_ResolveObjectTarget, FUN_004cd3b0, FUN_007a4480, SV.
//  - Strings: "SV(%d: %f)\n".
//  - Return sites: 1.

// =============================================================================
// CVOGMap_SetVariable
// -----------------------------------------------------------------------------
// Stable ID: aa_005afbc0
// Address:   0x005afbc0  (autoassault.exe, image base 0x400000)
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

void __thiscall CVOGMap_SetVariable(int param_1,uint param_2,float param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4) + 4);

  if (iVar3 == 0) {

LAB_005afbf4:

    iVar3 = 0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar3 + 0x10)) {

        if (iVar3 == 0) goto LAB_005afbf4;

        iVar3 = *(int *)(iVar3 + 8);

        goto LAB_005afbfb;

      }

      iVar3 = *(int *)(iVar3 + 0xc);

    } while (iVar3 != 0);

    iVar3 = 0;

  }

LAB_005afbfb:

  if (iVar3 != 0) {

    if (*(char *)(param_1 + 0x3c) != '\0') {

      FUN_007a4480(0,"SV(%d: %f)\n",param_2,(double)param_3);

    }

    *(float *)(iVar3 + 0x48) = param_3;

    FUN_004cd3b0(param_2,param_3);

    puVar2 = *(uint32_t /* width from decompiler */ **)(iVar3 + 0x58);

    if (puVar2 != *(uint32_t /* width from decompiler */ **)(iVar3 + 0x5c)) {

      do {

        piVar1 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar2,puVar2[1]);

        if (piVar1 != (int *)0x0) {

          (**(code **)(*piVar1 + 0x13c))(param_4);

        }

        puVar2 = puVar2 + 2;

      } while (puVar2 != *(uint32_t /* width from decompiler */ **)(iVar3 + 0x5c));

    }

  }

  return;

}
