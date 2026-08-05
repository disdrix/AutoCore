// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ddc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ddc0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068ddc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×12, return×8.
//  - Notable callees: FUN_0068c330×2, FUN_0068b700, FUN_0068cf50, FUN_0068cfe0, FUN_0068d160, FUN_0068d180, FUN_0068ddc0, FUN_00693ae0.
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ddc0(int param_1,int param_2)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  

  if (param_1 == param_2) {

    return param_1;

  }

  iVar5 = *(int *)(param_2 + 4);

  if (iVar5 != 0) {

    uVar3 = *(int *)(param_2 + 8) - iVar5 >> 4;

    if (uVar3 != 0) {

      iVar1 = *(int *)(param_1 + 4);

      if (iVar1 == 0) {

        uVar6 = 0;

      }

      else {

        uVar6 = *(int *)(param_1 + 8) - iVar1 >> 4;

      }

      if (uVar3 <= uVar6) {

        uVar4 = FUN_0068c330(iVar5,*(int *)(param_2 + 8),iVar1,param_2);

        FUN_0068cfe0(uVar4,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,param_2);

        if (*(int *)(param_2 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

          return param_1;

        }

        *(int *)(param_1 + 8) =

             (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 4) * 0x10 + *(int *)(param_1 + 4);

        return param_1;

      }

      if (iVar1 == 0) {

        uVar6 = 0;

      }

      else {

        uVar6 = *(int *)(param_1 + 0xc) - iVar1 >> 4;

      }

      if (uVar6 < uVar3) {

        if (iVar1 != 0) {

          FUN_00693ae0(iVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(param_1 + 4));

        }

        if (*(int *)(param_2 + 4) == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 4;

        }

        cVar2 = FUN_0068b700(iVar5);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar4 = FUN_0068d160(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        return param_1;

      }

      if (iVar1 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar1 >> 4;

      }

      iVar5 = iVar5 * 0x10 + *(int *)(param_2 + 4);

      FUN_0068c330(*(int *)(param_2 + 4),iVar5,iVar1,param_2);

      uVar4 = FUN_0068cf50(iVar5,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,

                           param_2);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

      return param_1;

    }

  }

  FUN_0068d180();

  return param_1;

}
