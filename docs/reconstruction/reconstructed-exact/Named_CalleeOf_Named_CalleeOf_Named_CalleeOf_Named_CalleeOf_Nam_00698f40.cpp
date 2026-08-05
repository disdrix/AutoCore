// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00698f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00698f40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00698f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, while×2, do×1.
//  - Notable callees: FUN_00697e10×2, CONCAT31, FUN_00698400, FUN_00698f40, FUN_006a3140, FUN_006a3400.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00698f40(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  float local_44;

  uint8_t local_3c [4];

  void *local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  void *local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aacc0;

  local_c = ExceptionList;

  uVar4 = 0;

  local_44 = -1.0;

  iVar3 = 0;

  while ((*(int *)(param_1 + 0x94) != 0 &&

         (uVar4 < (uint)((*(int *)(param_1 + 0x98) - *(int *)(param_1 + 0x94)) / 0x54)))) {

    iVar2 = *(int *)(param_1 + 0x94) + iVar3;

    if (*(float *)(*(int *)(param_1 + 0x94) + 0x48 + iVar3) <= *(float *)(iVar2 + 0x4c)) {

      fVar1 = *(float *)(iVar2 + 0x4c);

    }

    else {

      fVar1 = *(float *)(iVar2 + 0x48);

    }

    fVar1 = fVar1 * *(float *)(param_1 + 0xa0);

    if (fVar1 <= local_44) {

      uVar4 = uVar4 + 1;

      iVar3 = iVar3 + 0x54;

    }

    else {

      uVar4 = uVar4 + 1;

      iVar3 = iVar3 + 0x54;

      local_44 = fVar1;

    }

  }

  if (*(int *)(param_1 + 200) != 0) {

    ExceptionList = &local_c;

    FUN_00697e10();

    iVar3 = 1;

    if (1 < *(int *)(param_1 + 0xb4)) {

      iVar2 = 0x10;

      do {

        FUN_006a3140();

        local_4 = 0;

        FUN_00698400(*(int *)(param_1 + 200) + -0x10 + iVar2);

        FUN_006a3400(local_3c);

        local_4 = CONCAT31(local_4._1_3_,1);

        FUN_00697e10();

        if (local_38 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_38);

        }

        local_38 = (void *)0x0;

        local_34 = 0;

        local_30 = 0;

        local_4 = 0xffffffff;

        if (local_28 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_28);

        }

        iVar3 = iVar3 + 1;

        iVar2 = iVar2 + 0x10;

        local_28 = (void *)0x0;

        local_24 = 0;

        local_20 = 0;

      } while (iVar3 < *(int *)(param_1 + 0xb4));

    }

  }

  ExceptionList = local_c;

  return;

}
