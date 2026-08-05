// =============================================================================
// FUN_005d22a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d22a0
// Address:   0x005d22a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d22a0 @ 0x005d22a0
// Stable ID: aa_005d22a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×3, while×3, return×2.
//  - Notable callees: FUN_005d1db0, FUN_005d22a0, Map_EraseNode_IntKey.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_005d22a0(void *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4)



{

  char cVar1;

  int *piVar2;

  int *pOutIt;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  void *unaff_EDI;

  

  piVar3 = param_4;

  piVar5 = *(int **)((int)param_1 + 4);

  pOutIt = param_3;

  if ((param_3 == (int *)*piVar5) && (param_4 == piVar5)) {

    FUN_005d1db0(piVar5[1]);

    *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);

    *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)((int)param_1 + 4) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 4);

    *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);

    *param_2 = **(uint32_t /* width from decompiler */ **)((int)param_1 + 4);

    return;

  }

  while (pOutIt != piVar3) {

    piVar5 = pOutIt;

    if (*(char *)((int)pOutIt + 0x15) == '\0') {

      piVar5 = (int *)pOutIt[2];

      if (*(char *)((int)piVar5 + 0x15) == '\0') {

        cVar1 = *(char *)(*piVar5 + 0x15);

        piVar2 = (int *)*piVar5;

        while (cVar1 == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x15);

          piVar5 = piVar2;

          piVar2 = (int *)*piVar2;

        }

      }

      else {

        cVar1 = *(char *)(pOutIt[1] + 0x15);

        piVar4 = (int *)pOutIt[1];

        piVar2 = pOutIt;

        while ((piVar5 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {

          cVar1 = *(char *)(piVar5[1] + 0x15);

          piVar4 = (int *)piVar5[1];

          piVar2 = piVar5;

        }

      }

    }

    Map_EraseNode_IntKey(param_1,&param_3,pOutIt,unaff_EDI);

    pOutIt = piVar5;

  }

  *param_2 = pOutIt;

  return;

}
