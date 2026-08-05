// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00800e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00800e60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x00800e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×20, return×1.
//  - Notable callees: FUN_00800d80×25, FUN_007fdcc0, FUN_007ff9c0, FUN_00800e60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00800e60(void)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  

  if ((((*(int **)(in_EAX + 0xf40) == (int *)0x0) ||

       (iVar1 = **(int **)(in_EAX + 0xf40), iVar1 == 0)) ||

      (iVar1 = *(int *)(iVar1 + 0x4c0), iVar1 == 0)) || (*(char *)(iVar1 + 0x1d) == '\0')) {

    FUN_007fdcc0(in_EAX);

    FUN_007ff9c0();

    if (*(int *)(in_EAX + 0x10a8) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x10a8) + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10a8));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10a8) + 0x530));

      }

    }

    if (*(int *)(in_EAX + 0x10b0) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x10b0) + 0x3d8))();

      if (cVar2 != '\0') {

        cVar2 = (**(code **)(**(int **)(in_EAX + 0x10b0) + 0xd0))();

        if (cVar2 != '\0') {

          iVar1 = *(int *)(in_EAX + 0x10b0);

          FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x624));

          FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x668));

          FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x634));

          FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x664));

          if (*(int *)(iVar1 + 0x664) != 0) {

            FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x664) + 0x570));

          }

        }

      }

    }

    if (*(int *)(in_EAX + 0x10b4) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x10b4) + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10b4) + 0x540));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10b4) + 0x520));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10b4) + 0x554));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10b4) + 0x54c));

      }

    }

    if (*(int *)(in_EAX + 0x10ac) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x10ac) + 0x3d8))();

      if (cVar2 != '\0') {

        iVar1 = *(int *)(in_EAX + 0x10ac);

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x55c));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x564));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x574));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x584));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x540));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x590));

        if ((DAT_00d1b6d8 != 0) &&

           (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                       DAT_00d1b6d8) + 0x3c) + 0x532) == '\0')) {

          FUN_00800d80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x560));

        }

      }

    }

    if (*(int *)(in_EAX + 0x1088) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x1088) + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x1088) + 0x694));

      }

    }

    if (*(int *)(in_EAX + 0x109c) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x109c) + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x109c) + 0x530));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x109c) + 0x508));

      }

    }

    if (*(int *)(in_EAX + 0x10a0) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x10a0) + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10a0) + 0x5a8));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10a0) + 0x508));

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10a0) + 0x5b4));

      }

    }

    if (*(int *)(in_EAX + 0x10f0) != 0) {

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x10f0) + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_00800d80(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10f0));

      }

    }

  }

  return;

}
