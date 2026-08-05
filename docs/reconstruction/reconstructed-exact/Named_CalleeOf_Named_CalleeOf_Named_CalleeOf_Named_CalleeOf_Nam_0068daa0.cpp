// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068daa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068daa0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068daa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, while×3.
//  - Notable callees: FUN_0068daa0.
//  - Return sites: 4.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068daa0(int param_1)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  iVar3 = 0;

  while( true ) {

    if ((*(int *)(param_1 + 0x44) == 0) ||

       ((uint)(*(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x44) >> 4) <= local_4)) {

      iVar3 = *(int *)(param_1 + 0x44);

      if (iVar3 == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

        return;

      }

      iVar4 = *(int *)(param_1 + 0x48);

      while( true ) {

        if (iVar3 == iVar4) {

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(param_1 + 0x44));

        }

        if (*(void **)(iVar3 + 4) != (void *)0x0) break;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 4) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

        iVar3 = iVar3 + 0x10;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(iVar3 + 4));

    }

    uVar5 = 0;

    while( true ) {

      iVar4 = *(int *)(*(int *)(param_1 + 0x44) + 4 + iVar3);

      if ((iVar4 == 0) ||

         ((uint)(*(int *)(*(int *)(param_1 + 0x44) + iVar3 + 8) - iVar4 >> 2) <= uVar5)) break;

      iVar1 = uVar5 * 4;

      operator_delete__(*(void **)(iVar4 + iVar1));

      uVar5 = uVar5 + 1;

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x44) + iVar3 + 4) + iVar1) = 0;

    }

    pvVar2 = *(void **)(*(int *)(param_1 + 0x44) + 4 + iVar3);

    iVar4 = *(int *)(param_1 + 0x44) + iVar3;

    if (pvVar2 != (void *)0x0) break;

    local_4 = local_4 + 1;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    iVar3 = iVar3 + 0x10;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
