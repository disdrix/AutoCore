// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693220
// -----------------------------------------------------------------------------
// Stable ID: aa_00693220
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00693220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×10, return×8.
//  - Notable callees: FUN_006903b0×2, FUN_00691590×2, SkillSet_GetEntryCount×2, FUN_00421e60, FUN_00422580, FUN_00690a40, FUN_006916d0, FUN_00693220.
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

void * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693220(void *param_1,void *param_2)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  

  if (param_1 == param_2) {

    return param_1;

  }

  iVar5 = *(int *)((int)param_2 + 4);

  if (iVar5 != 0) {

    iVar6 = *(int *)((int)param_2 + 8) - iVar5;

    iVar1 = iVar6 >> 0x1f;

    iVar6 = iVar6 / 0x18 + iVar1;

    uVar7 = iVar6 - iVar1;

    if (iVar6 != iVar1) {

      iVar1 = *(int *)((int)param_1 + 4);

      if (iVar1 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)((int)param_1 + 8) - iVar1) / 0x18;

      }

      if (uVar7 <= uVar3) {

        uVar4 = FUN_006903b0(iVar5,*(uint32_t /* width from decompiler */ *)((int)param_2 + 8),iVar1,param_2);

        FUN_00691590(uVar4,*(uint32_t /* width from decompiler */ *)((int)param_1 + 8));

        if (*(int *)((int)param_2 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 4);

          return param_1;

        }

        *(int *)((int)param_1 + 8) =

             *(int *)((int)param_1 + 4) +

             ((*(int *)((int)param_2 + 8) - *(int *)((int)param_2 + 4)) / 0x18) * 0x18;

        return param_1;

      }

      if (iVar1 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)((int)param_1 + 0xc) - iVar1) / 0x18;

      }

      if (uVar3 < uVar7) {

        if (iVar1 != 0) {

          FUN_00691590(iVar1,*(uint32_t /* width from decompiler */ *)((int)param_1 + 8));

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)((int)param_1 + 4));

        }

        iVar5 = SkillSet_GetEntryCount(param_2);

        cVar2 = FUN_00690a40(iVar5);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar4 = FUN_00421e60(*(uint32_t /* width from decompiler */ *)((int)param_2 + 4),*(uint32_t /* width from decompiler */ *)((int)param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)((int)param_1 + 4));

        *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar4;

        return param_1;

      }

      iVar6 = SkillSet_GetEntryCount(param_1);

      iVar6 = iVar5 + iVar6 * 0x18;

      FUN_006903b0(iVar5,iVar6,iVar1,iVar6);

      uVar4 = FUN_00422580(iVar6,*(uint32_t /* width from decompiler */ *)((int)param_2 + 8),*(uint32_t /* width from decompiler */ *)((int)param_1 + 8)

                           ,param_1,iVar6);

      *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar4;

      return param_1;

    }

  }

  FUN_006916d0();

  return param_1;

}
