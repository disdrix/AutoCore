// =============================================================================
// Named_CalleeOf_Named_gfxIndexBufferImpl_00985b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00985b40
// Callee of Named_gfxIndexBufferImpl
// Address:   0x00985b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxIndexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, while×3, do×2.
//  - Notable callees: FUN_0045f620, FUN_00462240, FUN_00462390, FUN_00462450, FUN_00462510, FUN_00462820, FUN_00463500, FUN_00743cd0.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_gfxIndexBufferImpl
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

int Named_CalleeOf_Named_gfxIndexBufferImpl_00985b40(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int *piVar7;

  uint8_t local_34 [8];

  uint8_t local_2c [8];

  uint32_t /* width from decompiler */ *local_24;

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b18e3;

  local_c = ExceptionList;

  if (*(int *)(param_2 + 0x1c) < 1) {

    return -1;

  }

  if (*(int *)(param_2 + 0x14) == 2) {

    param_2 = param_3;

    ExceptionList = &local_c;

    iVar4 = FUN_00462390();

    iVar6 = *(int *)(iVar4 + 8);

    do {

      if (iVar6 == *(int *)(iVar4 + 4)) {

        FUN_00462240(local_2c);

        local_4 = 0;

        FUN_00462450();

        local_4 = 0xffffffff;

        if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_18);

        }

        local_18 = (void *)0x0;

        local_14 = 0;

        local_10 = 0;

        FUN_00462820(&param_2,*local_24,local_24);

                    /* WARNING: Subroutine does not return */

        operator_delete(local_24);

      }

      if (*(int *)(iVar6 + -0x20) != 0) {

        piVar7 = *(int **)(iVar6 + -0xc);

        if (piVar7 != *(int **)(iVar6 + -8)) {

          do {

            if (*(int *)(iVar3 + 0x1c) <= piVar7[1]) {

              *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar6 + -0x20);

              *(int *)(iVar3 + 0x18) = *piVar7;

              FUN_0045f620(local_34);

              if (piVar7[1] == *(int *)(iVar3 + 0x1c)) {

                piVar1 = *(int **)(iVar6 + -8);

                piVar2 = piVar7;

                while (piVar2 = piVar2 + 2, piVar2 != piVar1) {

                  *piVar7 = *piVar2;

                  piVar7[1] = piVar2[1];

                  piVar7 = piVar7 + 2;

                }

                *(int *)(iVar6 + -8) = *(int *)(iVar6 + -8) + -8;

                ExceptionList = local_c;

                return 0;

              }

              piVar7[1] = piVar7[1] - *(int *)(iVar3 + 0x1c);

              *piVar7 = *piVar7 + *(int *)(iVar3 + 0x1c);

              ExceptionList = local_c;

              return 0;

            }

            piVar7 = piVar7 + 2;

          } while (piVar7 != *(int **)(iVar6 + -8));

        }

      }

      iVar6 = iVar6 + -0x20;

    } while( true );

  }

  ExceptionList = &local_c;

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_00462510();

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = 0;

    puVar5[1] = 0;

    puVar5[2] = 0xffffffff;

    puVar5[3] = 0;

    puVar5[4] = 2;

  }

  *(uint32_t /* width from decompiler */ **)(iVar3 + 0x10) = puVar5;

  iVar6 = FUN_00743cd0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c),param_3,1);

  if (-1 < iVar6) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18) = 0;

    ExceptionList = local_c;

    return 0;

  }

  FUN_00463500();

  ExceptionList = local_c;

  return iVar6;

}
