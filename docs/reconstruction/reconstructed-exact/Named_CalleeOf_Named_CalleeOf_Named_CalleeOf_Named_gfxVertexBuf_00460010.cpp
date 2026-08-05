// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBuf_00460010
// -----------------------------------------------------------------------------
// Stable ID: aa_00460010
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl
// Address:   0x00460010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×13, return×2.
//  - Notable callees: FUN_00460cc0×4, CONCAT31×2, FUN_004609b0×2, FUN_00460b00×2, FUN_004540b0, FUN_0045f5d0, FUN_0045fad0, FUN_00460010.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBuf_00460010(int param_1,int param_2,uint param_3)



{

  uint uVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int extraout_ECX;

  int iVar5;

  uint8_t local_3c [32];

  int local_1c;

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bec58;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffb8;

  ExceptionList = &local_10;

  FUN_004602a0(local_3c);

  iVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 0xc) - iVar2 >> 5;

  }

  if (param_3 != 0) {

    if (iVar2 != 0) {

      iVar5 = *(int *)(param_1 + 8) - iVar2 >> 5;

    }

    if (0x7ffffffU - iVar5 < param_3) {

      uVar1 = FUN_004540b0();

      iVar2 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 8) - iVar2 >> 5;

    }

    if (uVar1 < iVar5 + param_3) {

      if (0x7ffffff - (uVar1 >> 1) < uVar1) {

        local_18 = 0;

      }

      else {

        local_18 = uVar1 + (uVar1 >> 1);

      }

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar2 >> 5;

      }

      if (local_18 < iVar5 + param_3) {

        if (iVar2 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 8) - iVar2 >> 5;

        }

        local_18 = iVar2 + param_3;

      }

      local_18 = local_18 << 5;

      pvVar3 = operator_new(local_18);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_00460cc0(param_2,pvVar3,param_2);

      FUN_00460b00(iVar2,param_2);

      FUN_00460cc0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x20,param_2);

      local_8 = 0;

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar2 >> 5;

      }

      if (iVar2 != 0) {

        FUN_0045fad0();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(uint *)(param_1 + 0xc) = local_18 + (int)pvVar3;

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar5) * 0x20 + (int)pvVar3);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      local_1c = *(int *)(param_1 + 8);

      if ((uint)(local_1c - param_2 >> 5) < param_3) {

        local_18 = param_3 * 0x20;

        FUN_00460cc0(local_1c,local_18 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00460b00(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_18;

        FUN_004609b0(*(int *)(param_1 + 8) - local_18,local_3c);

      }

      else {

        local_18 = param_3 << 5;

        uVar4 = FUN_00460cc0(local_1c,local_1c,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_00460bb0(param_2,local_1c,param_2);

        FUN_004609b0(local_18 + param_2,local_3c);

      }

    }

  }

  local_8 = 0xffffffff;

  FUN_0045f5d0();

  ExceptionList = local_10;

  return;

}
