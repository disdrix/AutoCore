// =============================================================================
// Named_CalleeOf_Named_AudioOutThread_00679790
// -----------------------------------------------------------------------------
// Stable ID: aa_00679790
// Callee of Named_AudioOutThread
// Address:   0x00679790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00678f80, FUN_00679790, FUN_0067af90, FUN_00680c80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_AudioOutThread
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_AudioOutThread_00679790(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  byte local_26;

  uint8_t local_25;

  ushort local_24 [2];

  uint16_t local_20 [2];

  uint8_t local_1c [4];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a9588;

  pvStack_c = ExceptionList;

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  FUN_0067af90(param_2,&local_25,&local_26,local_24,local_20,local_1c);

  if ((*(int *)(param_1 + 0x84) == -1) || (*(int *)(param_1 + 0x84) <= (int)(uint)local_24[0])) {

    *(uint *)(param_1 + 0x84) = (uint)local_24[0];

    iVar7 = (uint)local_26 * *(int *)(param_1 + 8) + *(int *)(param_1 + 0x90);

    if (*(int *)(param_1 + 0x8c) <= iVar7) {

      uVar2 = iVar7 + 0x400;

      *(uint *)(param_1 + 0x8c) = uVar2;

      puVar3 = operator_new__(uVar2);

      uVar2 = *(uint *)(param_1 + 0x90);

      puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x88);

      puVar6 = puVar3;

      for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      }

      operator_delete__(*(void **)(param_1 + 0x88));

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x88) = puVar3;

    }

    FUN_00680c80(&DAT_00d07aa0,local_20[0]);

    iVar7 = 0;

    uVar2 = 0;

    if (local_26 != 0) {

      do {

        (**(code **)(**(int **)(param_1 + 0x6c) + 0xc))

                  (*(int *)(param_1 + 0x88) + *(int *)(param_1 + 0x90),&DAT_00d07aa0 + iVar7,

                   *(uint8_t *)((int)local_18 + uVar2));

        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + *(int *)(param_1 + 8);

        *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;

        iVar7 = iVar7 + (uint)*(byte *)((int)local_18 + uVar2);

        if (0x7ff < *(int *)(param_1 + 0x90)) {

          FUN_00678f80(*(uint32_t /* width from decompiler */ *)(param_1 + 0x88),*(int *)(param_1 + 0x90));

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = 0;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

        }

        iVar1 = *(int *)(param_1 + 0x7c);

        if (iVar1 < 1) {

          if (iVar1 == 0) {

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0xffffffff;

            (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),0);

            (**(code **)(**(int **)(param_1 + 0x10) + 0x30))(*(int **)(param_1 + 0x10),0,0,1);

          }

        }

        else {

          *(int *)(param_1 + 0x7c) = iVar1 + -1;

        }

        uVar2 = uVar2 + 1;

      } while (uVar2 != local_26);

    }

  }

  if (local_18 == (void *)0x0) {

    ExceptionList = pvStack_c;

    return 0;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_18);

}
