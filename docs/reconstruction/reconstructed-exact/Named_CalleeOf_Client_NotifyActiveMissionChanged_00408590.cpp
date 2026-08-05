// =============================================================================
// Named_CalleeOf_Client_NotifyActiveMissionChanged_00408590
// -----------------------------------------------------------------------------
// Stable ID: aa_00408590
// Callee of Client_NotifyActiveMissionChanged
// Address:   0x00408590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_NotifyActiveMissionChanged: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, while×2, return×2.
//  - Notable callees: FUN_00408590.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_NotifyActiveMissionChanged
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

void __fastcall Named_CalleeOf_Client_NotifyActiveMissionChanged_00408590(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  iVar2 = *param_2;

  if (*(char *)(iVar2 + 0x31) == '\0') {

    piVar3 = *(int **)(iVar2 + 8);

    if (*(char *)((int)piVar3 + 0x31) == '\0') {

      cVar1 = *(char *)(*piVar3 + 0x31);

      piVar4 = (int *)*piVar3;

      while (cVar1 == '\0') {

        cVar1 = *(char *)(*piVar4 + 0x31);

        piVar3 = piVar4;

        piVar4 = (int *)*piVar4;

      }

      *param_2 = (int)piVar3;

      return;

    }

    iVar2 = *(int *)(iVar2 + 4);

    cVar1 = *(char *)(iVar2 + 0x31);

    while ((cVar1 == '\0' && (*param_2 == *(int *)(iVar2 + 8)))) {

      *param_2 = iVar2;

      iVar2 = *(int *)(iVar2 + 4);

      cVar1 = *(char *)(iVar2 + 0x31);

    }

    *param_2 = iVar2;

  }

  return;

}
