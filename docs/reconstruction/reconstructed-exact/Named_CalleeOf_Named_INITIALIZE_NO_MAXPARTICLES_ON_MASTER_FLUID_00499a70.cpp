// =============================================================================
// Named_CalleeOf_Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID_00499a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00499a70
// Callee of Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID
// Address:   0x00499a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×16, return×4, while×1.
//  - Notable callees: FUN_00498d70, FUN_00499a70, FUN_005b8110, FUN_005b8150, FUN_005b8170.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID
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

void __fastcall Named_CalleeOf_Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID_00499a70(int param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  

  if (*(char *)(param_1 + 0x1dc) != '\0') {

    if (*(int **)(param_1 + 0x1c4) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x1c4) + 0x1c))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x194));

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

    }

    if (*(void **)(param_1 + 0x1ac) != (void *)0x0) {

      operator_delete__(*(void **)(param_1 + 0x1ac));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac) = 0;

    if (*(void **)(param_1 + 0x1a8) != (void *)0x0) {

      operator_delete__(*(void **)(param_1 + 0x1a8));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8) = 0;

    if (*(void **)(param_1 + 0x1b8) != (void *)0x0) {

      operator_delete__(*(void **)(param_1 + 0x1b8));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8) = 0;

    if (*(int **)(param_1 + 0x18c) != (int *)0x0) {

      if (*(int *)(param_1 + 400) != 0) {

        (**(code **)(**(int **)(param_1 + 0x18c) + 0x18))(*(int *)(param_1 + 400));

        *(uint32_t /* width from decompiler */ *)(param_1 + 400) = 0;

      }

      if (*(int *)(param_1 + 0x1c4) != 0) {

        uVar4 = 0;

        while( true ) {

          iVar2 = *(int *)(param_1 + 0x1d0);

          if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x1d4) - iVar2 >> 2) <= uVar4)) break;

          (**(code **)(**(int **)(param_1 + 0x18c) + 8))

                    (*(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + uVar4 * 4) + 0x70));

          pvVar1 = *(void **)(*(int *)(param_1 + 0x1d0) + uVar4 * 4);

          if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          uVar4 = uVar4 + 1;

        }

        if (*(void **)(param_1 + 0x1d0) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(param_1 + 0x1d0));

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d0) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d8) = 0;

        if (*(int *)(*(int *)(param_1 + 0x19c) + 0x19c) == param_1) {

          iVar2 = (**(code **)(**(int **)(param_1 + 0x18c) + 0xc))();

          if (iVar2 == 0) {

            FUN_005b8110();

            FUN_005b8150();

            FUN_005b8170();

            (**(code **)(**(int **)(param_1 + 0x1c4) + 0x168))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18c));

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x19c) + 0x19c) = 0;

          }

          else {

            piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x18c) + 0x10))();

            iVar2 = *(int *)(*piVar3 + 4);

            *(int *)(*(int *)(param_1 + 0x19c) + 0x19c) = iVar2;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

            *(uint8_t *)(iVar2 + 0x18) = *(uint8_t *)(param_1 + 0x18);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1a0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a0);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

          }

        }

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = 0;

    }

    piVar3 = *(int **)(param_1 + 0x198);

    if (piVar3 != (int *)0x0) {

      if ((*piVar3 != 0) && (piVar3[1] != 0)) {

        (**(code **)(*(int *)piVar3[1] + 0x1c))(*piVar3);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar3);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = 0;

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x184) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x184))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

    *(uint8_t *)(param_1 + 0x1dc) = 0;

    FUN_00498d70(param_1);

  }

  return;

}
