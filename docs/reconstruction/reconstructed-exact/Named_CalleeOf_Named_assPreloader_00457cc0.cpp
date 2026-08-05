// =============================================================================
// Named_CalleeOf_Named_assPreloader_00457cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00457cc0
// Callee of Named_assPreloader
// Address:   0x00457cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, while×2, return×2.
//  - Notable callees: FUN_00457cc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assPreloader
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

void __fastcall Named_CalleeOf_Named_assPreloader_00457cc0(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  iVar2 = *param_2;

  if (*(char *)(iVar2 + 0x19) == '\0') {

    piVar3 = *(int **)(iVar2 + 8);

    if (*(char *)((int)piVar3 + 0x19) == '\0') {

      cVar1 = *(char *)(*piVar3 + 0x19);

      piVar4 = (int *)*piVar3;

      while (cVar1 == '\0') {

        cVar1 = *(char *)(*piVar4 + 0x19);

        piVar3 = piVar4;

        piVar4 = (int *)*piVar4;

      }

      *param_2 = (int)piVar3;

      return;

    }

    iVar2 = *(int *)(iVar2 + 4);

    cVar1 = *(char *)(iVar2 + 0x19);

    while ((cVar1 == '\0' && (*param_2 == *(int *)(iVar2 + 8)))) {

      *param_2 = iVar2;

      iVar2 = *(int *)(iVar2 + 4);

      cVar1 = *(char *)(iVar2 + 0x19);

    }

    *param_2 = iVar2;

  }

  return;

}
