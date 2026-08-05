// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_00451bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00451bf0
// Callee of Named_gfxShadowVolume
// Address:   0x00451bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, FUN_00451bf0, FUN_00452b60, FUN_00452f40, FUN_00454c10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume
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

int __thiscall Named_CalleeOf_Named_gfxShadowVolume_00451bf0(float *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  void *local_18;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bdf10;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar2 = FUN_00454c10();

  if (((iVar2 == *(int *)(iVar1 + 4)) ||

      (*param_1 <= *(float *)(iVar2 + 0xc) && *(float *)(iVar2 + 0xc) != *param_1)) ||

     ((*param_1 < *(float *)(iVar2 + 0xc) || *param_1 == *(float *)(iVar2 + 0xc) &&

      ((param_1[1] <= *(float *)(iVar2 + 0x10) && *(float *)(iVar2 + 0x10) != param_1[1] ||

       ((param_1[1] < *(float *)(iVar2 + 0x10) || param_1[1] == *(float *)(iVar2 + 0x10) &&

        ((param_1[2] <= *(float *)(iVar2 + 0x14) && *(float *)(iVar2 + 0x14) != param_1[2] ||

         ((param_1[2] < *(float *)(iVar2 + 0x14) || param_1[2] == *(float *)(iVar2 + 0x14) &&

          ((param_1[3] <= *(float *)(iVar2 + 0x18) && *(float *)(iVar2 + 0x18) != param_1[3] ||

           ((param_1[3] < *(float *)(iVar2 + 0x18) || param_1[3] == *(float *)(iVar2 + 0x18) &&

            ((param_1[4] <= *(float *)(iVar2 + 0x1c) && *(float *)(iVar2 + 0x1c) != param_1[4] ||

             ((param_1[4] < *(float *)(iVar2 + 0x1c) || param_1[4] == *(float *)(iVar2 + 0x1c) &&

              (param_1[5] <= *(float *)(iVar2 + 0x20) && *(float *)(iVar2 + 0x20) != param_1[5])))))

            ))))))))))))))) {

    local_4 = 0;

    FUN_00452f40();

    local_4 = CONCAT31(local_4._1_3_,1);

    piVar3 = (int *)FUN_00452b60(&param_2,iVar2);

    iVar2 = *piVar3;

    if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_18);

    }

  }

  ExceptionList = local_c;

  return iVar2 + 0x24;

}
