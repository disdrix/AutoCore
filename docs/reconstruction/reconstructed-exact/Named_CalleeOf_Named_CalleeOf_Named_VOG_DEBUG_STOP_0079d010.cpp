// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0079d010
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d010
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0079d010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×9, return×8, while×2.
//  - Notable callees: FUN_00793aa0, FUN_00793b80, FUN_0079cde0, FUN_0079d010.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

int * __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0079d010(int *param_1,int *param_2)



{

  char cVar1;

  int *piVar2;

  char *pcVar3;

  char *pcVar4;

  int *piVar5;

  int unaff_EDI;

  uint64_t uVar6;

  char *unaff_retaddr;

  int **ppiVar7;

  uint32_t /* width from decompiler */ uVar8;

  int *local_4;

  

  local_4 = param_1;

  if (*(char *)((int)param_1 + 5) == '\0') {

    if (*(char *)((int)param_1 + 6) == '\0') {

      return param_2;

    }

    FUN_0079cde0(param_2);

    return param_2;

  }

  uVar8 = 4;

  ppiVar7 = &local_4;

  (**(code **)(*param_1 + 4))(ppiVar7,4);

  piVar2 = local_4;

  if (unaff_EDI != 0) {

    pcVar3 = (char *)0x0;

    if (local_4 != (int *)0x0) {

      cVar1 = (char)*local_4;

      piVar5 = local_4;

      while (cVar1 != '\0') {

        piVar5 = (int *)((int)piVar5 + 1);

        cVar1 = *(char *)piVar5;

      }

      pcVar3 = (char *)((int)piVar5 + (1 - (int)local_4));

    }

    if (pcVar3 == (char *)(unaff_EDI + 1)) {

      (**(code **)(*param_1 + 4))(local_4,unaff_EDI,ppiVar7,uVar8,(char *)(unaff_EDI + 1));

      *(char *)((int)ppiVar7 + -1 + (int)piVar2) = '\0';

      return piVar2;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(local_4);

  }

  if (unaff_retaddr == (char *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_4);

  }

  cVar1 = *unaff_retaddr;

  pcVar3 = unaff_retaddr;

  while (cVar1 != '\0') {

    pcVar3 = pcVar3 + 1;

    cVar1 = *pcVar3;

  }

  pcVar3 = pcVar3 + (1 - (int)unaff_retaddr);

  if (pcVar3 != (char *)0x0) {

    pcVar4 = (char *)0x0;

    if (local_4 != (int *)0x0) {

      uVar6 = FUN_00793b80(ppiVar7,uVar8,pcVar3);

      pcVar3 = (char *)((ulonglong)uVar6 >> 0x20);

      pcVar4 = (char *)((int)uVar6 + 1);

    }

    if (pcVar4 == pcVar3) {

      FUN_00793aa0(piVar2,unaff_retaddr,pcVar3);

      return piVar2;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar2);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_4);

}
