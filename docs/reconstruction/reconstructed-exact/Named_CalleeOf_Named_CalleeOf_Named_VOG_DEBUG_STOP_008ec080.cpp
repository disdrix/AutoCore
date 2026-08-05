// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_008ec080
// -----------------------------------------------------------------------------
// Stable ID: aa_008ec080
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x008ec080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008ec080.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_008ec080(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int unaff_ESI;

  float unaff_EDI;

  uint32_t /* width from decompiler */ uStack_40;

  int *piStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  int *piStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  int *piStack_2c;

  float fStack_28;

  int local_18;

  float local_14;

  float fStack_10;

  

  if (((*(int *)(unaff_ESI + 0x5a8) != 0) && (*(float *)(unaff_ESI + 0x514) != 0.0)) &&

     (*(float *)(unaff_ESI + 0x518) != 0.0)) {

    fStack_28 = 1.4013e-45;

    piStack_2c = &local_18;

    uStack_30 = 0x8ec0d5;

    piVar1 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0x140))();

    uStack_30 = 1;

    piStack_34 = &local_18;

    uStack_38 = 0x8ec0ec;

    piVar2 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0x140))();

    uStack_38 = 1;

    piStack_3c = &local_18;

    uStack_40 = 0x8ec103;

    piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0x140))();

    piVar5 = *(int **)(unaff_ESI + 0x5a8);

    uStack_40 = 1;

    iVar6 = (int)(((float)*piVar1 / *(float *)(unaff_ESI + 0x514)) * *(float *)(unaff_ESI + 0x524) *

                  fStack_10 -

                 ((float)*piVar2 * *(float *)(unaff_ESI + 0x528) -

                 (float)*piVar3 / (*(float *)(unaff_ESI + 0x524) * g_flLevelUpUiBase_Inferred)) *

                 *(float *)(unaff_ESI + 0x524));

    iVar4 = (**(code **)(*piVar5 + 0x140))(&stack0xffffffe0);

    local_14 = ((float)*(int *)(iVar4 + 4) / *(float *)(unaff_ESI + 0x518)) *

               *(float *)(unaff_ESI + 0x524) * local_14;

    (**(code **)(*piVar5 + 0x140))(&uStack_30,1);

    iVar4 = (**(code **)(*piVar5 + 0x140))(&uStack_40,1);

    iVar4 = (int)(unaff_EDI -

                 (fStack_28 -

                 (float)*(int *)(iVar4 + 4) /

                 (*(float *)(unaff_ESI + 0x524) * g_flLevelUpUiBase_Inferred)) *

                 *(float *)(unaff_ESI + 0x524));

    if (*(int *)(unaff_ESI + 0x5a8) != 0) {

      piVar5 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0x120))(&uStack_38,1,0);

      iVar6 = iVar6 + *piVar5;

      iVar4 = iVar4 + piVar5[1];

    }

    piStack_2c[1] = iVar4;

    *piStack_2c = iVar6;

    return;

  }

  *param_1 = local_18;

  param_1[1] = (int)local_14;

  return;

}
