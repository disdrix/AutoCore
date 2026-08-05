// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGWaypoint_UpdateState_004d2c60
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2c60
// Callee of Named_CalleeOf_CVOGWaypoint_UpdateState
// Address:   0x004d2c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGWaypoint_UpdateState: AI/path helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004d2c60, FUN_004e9530, FUN_005a58c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGWaypoint_UpdateState
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_CalleeOf_CVOGWaypoint_UpdateState_004d2c60(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ *param_5,

            uint32_t /* width from decompiler */ *param_6)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float10 extraout_ST0;

  float fVar5;

  uint8_t auStack_34 [8];

  uint8_t auStack_2c [40];

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xe568) + (*(uint *)(param_1 + 0xe560) & param_2) * 4

                           ) + 4);

  if (iVar1 == 0) {

LAB_004d2ca2:

    piVar2 = (int *)0x0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar1 + 0x10)) {

        if (iVar1 == 0) goto LAB_004d2ca2;

        piVar2 = *(int **)(iVar1 + 8);

        goto LAB_004d2ca9;

      }

      iVar1 = *(int *)(iVar1 + 0xc);

    } while (iVar1 != 0);

    piVar2 = (int *)0x0;

  }

LAB_004d2ca9:

  if ((piVar2 != (int *)0x0) &&

     (piVar2 = (int *)(**(code **)(*piVar2 + 0x10))(param_3,param_4), piVar2 != (int *)0x0)) {

    uVar3 = (**(code **)(*piVar2 + 0x40))(auStack_34);

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_004e9530(auStack_2c,uVar3);

    *param_5 = *puVar4;

    param_5[1] = puVar4[1];

    param_5[2] = puVar4[2];

    param_5[3] = puVar4[3];

    if (*(int *)(param_1 + 0xe4e0) == 0) {

      fVar5 = 0.0;

    }

    else {

      FUN_005a58c0(*param_5,param_5[2]);

      fVar5 = (float)extraout_ST0;

    }

    param_5[1] = fVar5;

    *param_6 = piVar2;

    return 1;

  }

  return 0;

}
