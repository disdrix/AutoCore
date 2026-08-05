// =============================================================================
// Named_CalleeOf_Named_AudioOutThread_00679480
// -----------------------------------------------------------------------------
// Stable ID: aa_00679480
// Callee of Named_AudioOutThread
// Address:   0x00679480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00678f80, FUN_00679480, FUN_0067a7b0, FUN_00680c80.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_AudioOutThread_00679480(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  undefined *puVar8;

  byte local_a;

  uint8_t local_9;

  ushort local_8 [2];

  int local_4;

  

  FUN_0067a7b0(param_2,&local_9,&local_a,local_8);

  if ((*(int *)(param_1 + 0x84) == -1) || (*(int *)(param_1 + 0x84) <= (int)(uint)local_8[0])) {

    *(uint *)(param_1 + 0x84) = (uint)local_8[0];

    local_4 = *(int *)(*(int *)(param_1 + 0x6c) + 0x18);

    iVar2 = *(int *)(param_1 + 0x90) + (uint)local_a * *(int *)(param_1 + 8);

    if (*(int *)(param_1 + 0x8c) <= iVar2) {

      uVar3 = iVar2 + 0x400;

      *(uint *)(param_1 + 0x8c) = uVar3;

      puVar4 = operator_new__(uVar3);

      uVar3 = *(uint *)(param_1 + 0x90);

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x88);

      puVar7 = puVar4;

      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

      operator_delete__(*(void **)(param_1 + 0x88));

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x88) = puVar4;

    }

    iVar2 = local_4;

    FUN_00680c80(&DAT_00d06aa0,(uint)local_a * local_4);

    uVar3 = 0;

    if (local_a != 0) {

      puVar8 = &DAT_00d06aa0;

      do {

        (**(code **)(**(int **)(param_1 + 0x6c) + 0xc))

                  (*(int *)(param_1 + 0x88) + *(int *)(param_1 + 0x90),puVar8,iVar2);

        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + *(int *)(param_1 + 8);

        *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;

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

        uVar3 = uVar3 + 1;

        puVar8 = puVar8 + iVar2;

      } while (uVar3 != local_a);

    }

  }

  return 0;

}
