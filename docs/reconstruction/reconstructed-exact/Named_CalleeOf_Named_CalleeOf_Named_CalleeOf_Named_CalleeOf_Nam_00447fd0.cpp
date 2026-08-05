// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00447fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00447fd0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00447fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×11, return×8.
//  - Notable callees: FUN_00445550×2, FUN_004484c0×2, FUN_00447720, FUN_00447fd0, FUN_004487f0.
//  - Return sites: 8.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00447fd0(int param_1)



{

  void *pvVar1;

  char cVar2;

  int in_EAX;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint uVar7;

  

  if (in_EAX == param_1) {

    return;

  }

  if (*(int *)(param_1 + 4) != 0) {

    iVar6 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);

    iVar4 = iVar6 >> 0x1f;

    iVar6 = iVar6 / 0x24 + iVar4;

    uVar7 = iVar6 - iVar4;

    if (iVar6 != iVar4) {

      pvVar1 = *(void **)(in_EAX + 4);

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(in_EAX + 8) - (int)pvVar1) / 0x24;

      }

      if (uVar7 <= uVar3) {

        FUN_004484c0();

        if (*(int *)(param_1 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = *(uint32_t /* width from decompiler */ *)(in_EAX + 4);

          return;

        }

        *(int *)(in_EAX + 8) =

             *(int *)(in_EAX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x24) * 0x24;

        return;

      }

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(in_EAX + 0xc) - (int)pvVar1) / 0x24;

      }

      if (uVar3 < uVar7) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        FUN_00445550();

        cVar2 = FUN_00447720();

        if (cVar2 == '\0') {

          return;

        }

      }

      else {

        iVar4 = FUN_00445550();

        param_1 = *(int *)(param_1 + 4) + iVar4 * 0x24;

        FUN_004484c0();

      }

      uVar5 = FUN_004487f0(param_1);

      *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = uVar5;

      return;

    }

  }

  if (*(void **)(in_EAX + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 4));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

  return;

}
