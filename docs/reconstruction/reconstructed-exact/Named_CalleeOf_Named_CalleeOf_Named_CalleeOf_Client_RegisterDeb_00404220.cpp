// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RegisterDeb_00404220
// -----------------------------------------------------------------------------
// Stable ID: aa_00404220
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RegisterDebugSlashCommands
// Address:   0x00404220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RegisterDebugSlashCommands: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×2, do×1.
//  - Notable callees: FUN_00404220.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RegisterDebugSlashCommands
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RegisterDeb_00404220(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  piVar4 = (int *)*param_2;

  if (*(char *)((int)piVar4 + 0x131) != '\0') {

    *param_2 = piVar4[2];

    return;

  }

  iVar2 = *piVar4;

  if (*(char *)(iVar2 + 0x131) == '\0') {

    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x131);

    iVar3 = *(int *)(iVar2 + 8);

    while (cVar1 == '\0') {

      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x131);

      iVar2 = iVar3;

      iVar3 = *(int *)(iVar3 + 8);

    }

    *param_2 = iVar2;

    return;

  }

  piVar4 = (int *)piVar4[1];

  if (*(char *)((int)piVar4 + 0x131) == '\0') {

    do {

      if (*param_2 != *piVar4) break;

      *param_2 = (int)piVar4;

      piVar4 = (int *)piVar4[1];

    } while (*(char *)((int)piVar4 + 0x131) == '\0');

    if (*(char *)((int)piVar4 + 0x131) == '\0') {

      *param_2 = (int)piVar4;

    }

  }

  return;

}
