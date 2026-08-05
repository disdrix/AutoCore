// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX_0048fb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0048fb10
// Callee of Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX
// Address:   0x0048fb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0048fb10, FUN_005b3a50, FUN_00787f90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX_0048fb10(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int *piVar5;

  char cVar6;

  int iVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ uVar9;

  int *local_2c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  piVar8 = *(int **)(param_1 + 0x164);

  local_2c = piVar8;

  if (piVar8 != *(int **)(param_1 + 0x168)) {

    do {

      iVar4 = *piVar8;

      piVar5 = *(int **)(iVar4 + 8);

      if (piVar5 != (int *)0x0) {

        iVar7 = (**(code **)(*piVar5 + 0xc))();

        fVar1 = *(float *)(iVar7 + 0x90);

        fVar2 = *(float *)(iVar7 + 0x94);

        fVar3 = *(float *)(iVar7 + 0x98);

        iVar7 = (**(code **)(*piVar5 + 0x48))();

        fStack_4 = *(float *)(iVar7 + 0x1c) + fVar3;

        fStack_8 = *(float *)(iVar7 + 0x18) + fVar2;

        fStack_c = *(float *)(iVar7 + 0x14) + fVar1;

        iVar7 = (**(code **)(*piVar5 + 0x48))();

        fStack_18 = (*(float *)(iVar7 + 0x20) + fVar1) - DAT_00afdfc8 * DAT_00aaa7ac;

        fStack_14 = (*(float *)(iVar7 + 0x24) + fVar2) - DAT_00afdfcc * DAT_00aaa7ac;

        fStack_10 = (*(float *)(iVar7 + 0x28) + fVar3) - DAT_00afdfd0 * DAT_00aaa7ac;

        cVar6 = FUN_00787f90(param_2,param_3,&fStack_c,&fStack_18);

        if (cVar6 != '\0') {

          uVar9 = FUN_005b3a50(*(uint32_t /* width from decompiler */ *)

                                (*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x34))

          ;

          return uVar9;

        }

        piVar8 = local_2c + 1;

        local_2c = piVar8;

      }

    } while (piVar8 != *(int **)(param_1 + 0x168));

  }

  return 0xffffffff;

}
