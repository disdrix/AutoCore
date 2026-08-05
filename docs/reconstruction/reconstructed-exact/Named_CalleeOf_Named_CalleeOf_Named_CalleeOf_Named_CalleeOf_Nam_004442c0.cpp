// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004442c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004442c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004442c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×13, return×9.
//  - Notable callees: FUN_004e2e80×2, FUN_00506430×2, FUN_00429920, FUN_004442c0.
//  - Return sites: 9.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004442c0(void)



{

  void *pvVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int unaff_ESI;

  

  if (unaff_ESI == in_EAX) {

    return;

  }

  iVar5 = *(int *)(in_EAX + 4);

  if (iVar5 != 0) {

    uVar6 = *(int *)(in_EAX + 8) - iVar5 >> 2;

    if (uVar6 != 0) {

      pvVar1 = *(void **)(unaff_ESI + 4);

      if (pvVar1 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(unaff_ESI + 8) - (int)pvVar1 >> 2;

      }

      if (uVar6 <= uVar4) {

        FUN_00506430(iVar5,*(int *)(in_EAX + 8),pvVar1);

        if (*(int *)(in_EAX + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

          return;

        }

        *(int *)(unaff_ESI + 8) =

             *(int *)(unaff_ESI + 4) + (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2) * 4;

        return;

      }

      if (pvVar1 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(unaff_ESI + 0xc) - (int)pvVar1 >> 2;

      }

      if (uVar4 < uVar6) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        if (*(int *)(in_EAX + 4) == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2;

        }

        cVar2 = FUN_00429920(iVar5);

        if (cVar2 == '\0') {

          return;

        }

        uVar3 = FUN_004e2e80(*(uint32_t /* width from decompiler */ *)(in_EAX + 4),*(uint32_t /* width from decompiler */ *)(in_EAX + 8),

                             *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4));

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar3;

        return;

      }

      if (pvVar1 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(unaff_ESI + 8) - (int)pvVar1 >> 2;

      }

      iVar5 = *(int *)(in_EAX + 4) + iVar5 * 4;

      FUN_00506430(*(int *)(in_EAX + 4),iVar5,pvVar1);

      uVar3 = FUN_004e2e80(iVar5,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar3;

      return;

    }

  }

  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 4));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  return;

}
