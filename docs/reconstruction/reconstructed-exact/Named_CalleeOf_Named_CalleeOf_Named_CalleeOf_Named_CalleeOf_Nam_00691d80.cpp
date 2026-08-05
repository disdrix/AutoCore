// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00691d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00691d80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00691d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×11, return×9.
//  - Notable callees: FUN_00690210×2, FUN_006909e0×2, FUN_00690a10, FUN_00690a90, FUN_00690ba0, FUN_00691d80.
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00691d80(int param_1,int param_2)



{

  void *pvVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint uVar7;

  

  if (param_1 == param_2) {

    return param_1;

  }

  if (*(int *)(param_2 + 4) != 0) {

    iVar6 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4);

    iVar4 = iVar6 >> 0x1f;

    iVar6 = iVar6 / 0x38 + iVar4;

    uVar7 = iVar6 - iVar4;

    if (iVar6 != iVar4) {

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x38;

      }

      if (uVar7 <= uVar3) {

        FUN_006909e0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),pvVar1);

        if (*(int *)(param_2 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

          return param_1;

        }

        *(int *)(param_1 + 8) =

             ((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x38) * 0x38 + *(int *)(param_1 + 4)

        ;

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(param_1 + 0xc) - (int)pvVar1) / 0x38;

      }

      if (uVar3 < uVar7) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        uVar5 = FUN_00690210();

        cVar2 = FUN_00690a90(uVar5);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar5 = FUN_00690ba0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

        return param_1;

      }

      iVar4 = FUN_00690210();

      iVar4 = iVar4 * 0x38 + *(int *)(param_2 + 4);

      FUN_006909e0(*(int *)(param_2 + 4),iVar4,pvVar1);

      uVar5 = FUN_00690a10(iVar4,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,

                           param_2);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

      return param_1;

    }

  }

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return param_1;

}
