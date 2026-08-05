// =============================================================================
// Named_CalleeOf_Named_gfxVertexBufferImpl_00986a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00986a60
// Callee of Named_gfxVertexBufferImpl (+1 other named callers)
// Address:   0x00986a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxVertexBufferImpl (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, while×3, do×2, goto×1.
//  - Notable callees: FUN_0045f4d0×2, FUN_0045f620×2, FUN_0045f6e0, FUN_0045f7a0, FUN_0045fa20, FUN_0045fb30, FUN_00462510, FUN_00746640.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_gfxVertexBufferImpl (+1 other named callers)
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

int __fastcall

Named_CalleeOf_Named_gfxVertexBufferImpl_00986a60(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint param_4,uint param_5)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  uint64_t uVar8;

  uint8_t auStack_64 [8];

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ *puStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint *puStack_50;

  undefined *puStack_4c;

  uint local_34 [4];

  uint32_t /* width from decompiler */ *local_24;

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_4;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b190c;

  local_c = ExceptionList;

  iVar5 = 0;

  if (*(int *)(param_4 + 0x18) < 1) {

    return -1;

  }

  if ((*(int *)(param_2 + 4) == 0) || (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 3 == 0)) {

    param_4 = 0;

    ExceptionList = &local_c;

  }

  else {

    ExceptionList = &local_c;

    uVar8 = FUN_007467b0();

    param_4 = (int)uVar8 + (uint)*(ushort *)((int)((ulonglong)uVar8 >> 0x20) + 2);

  }

  local_34[0] = param_5 << 0x10 | param_4;

  iVar4 = FUN_0045f6e0();

  if ((param_5 & 9) != 0) {

    if (*(int *)(iVar4 + 4) != 0) {

      iVar5 = *(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 5;

    }

    FUN_0045f4d0(auStack_64);

    FUN_0045fa20(iVar5 + 1);

    puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 8) + -0x20);

    puStack_58 = (uint32_t /* width from decompiler */ *)FUN_00462510();

    if (puStack_58 == (uint32_t /* width from decompiler */ *)0x0) {

      puStack_58 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      *puStack_58 = 0;

      puStack_58[1] = 0xffffffff;

      puStack_58[2] = 0;

      puStack_58[3] = 0;

      puStack_58[4] = 0;

    }

    puStack_4c = (undefined *)param_5;

    *puVar6 = puStack_58;

    uStack_54 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18);

    puStack_50 = (uint *)param_4;

    uStack_5c = 0x986b6a;

    iVar5 = FUN_00746640();

    if (-1 < iVar5) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = *puVar6;

      puStack_4c = (undefined *)0x986b8f;

      FUN_0045f620();

LAB_00986cc1:

      iVar5 = 0;

    }

    ExceptionList = local_c;

    return iVar5;

  }

  iVar5 = *(int *)(iVar4 + 8);

  do {

    if (iVar5 == *(int *)(iVar4 + 4)) {

      puStack_4c = (undefined *)0x986bd4;

      FUN_0045f4d0();

      local_4 = 0;

      FUN_0045f7a0();

      local_4 = 0xffffffff;

      if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        puStack_4c = &UNK_00986bf9;

        operator_delete(local_18);

      }

      local_18 = (void *)0x0;

      local_14 = 0;

      local_10 = 0;

      puStack_4c = (undefined *)*local_24;

      puStack_50 = local_34;

      uStack_54 = 0x986c1e;

      FUN_0045fb30();

                    /* WARNING: Subroutine does not return */

      puStack_4c = &UNK_00986c28;

      operator_delete(local_24);

    }

    if (*(int *)(iVar5 + -0x20) != 0) {

      piVar7 = *(int **)(iVar5 + -0xc);

      if (piVar7 != *(int **)(iVar5 + -8)) {

        do {

          if (*(int *)(iVar3 + 0x18) <= piVar7[1]) {

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar5 + -0x20);

            *(int *)(iVar3 + 0x14) = *piVar7;

            puStack_4c = (undefined *)0x986cf8;

            FUN_0045f620();

            if (piVar7[1] == *(int *)(iVar3 + 0x18)) {

              piVar1 = *(int **)(iVar5 + -8);

              piVar2 = piVar7;

              while (piVar2 = piVar2 + 2, piVar2 != piVar1) {

                *piVar7 = *piVar2;

                piVar7[1] = piVar2[1];

                piVar7 = piVar7 + 2;

              }

              *(int *)(iVar5 + -8) = *(int *)(iVar5 + -8) + -8;

            }

            else {

              piVar7[1] = piVar7[1] - *(int *)(iVar3 + 0x18);

              *piVar7 = *piVar7 + *(int *)(iVar3 + 0x18);

            }

            goto LAB_00986cc1;

          }

          piVar7 = piVar7 + 2;

        } while (piVar7 != *(int **)(iVar5 + -8));

      }

    }

    iVar5 = iVar5 + -0x20;

  } while( true );

}
