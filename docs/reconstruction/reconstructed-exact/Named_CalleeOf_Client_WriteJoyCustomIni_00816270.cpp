// =============================================================================
// Named_CalleeOf_Client_WriteJoyCustomIni_00816270
// -----------------------------------------------------------------------------
// Stable ID: aa_00816270
// Callee of Client_WriteJoyCustomIni
// Address:   0x00816270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_WriteJoyCustomIni: config/load helper. Evidence string: "\n#\n# joy function labeled <%s> in-game\n#\n\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "\n#\n# joy function labeled <%s> in-game\n#\n\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: fprintf×3, FUN_00816270.
//  - Strings: "\n#\n# joy function labeled <%s> in-game\n#\n\n"; "%s=%s\n".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_WriteJoyCustomIni
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

uint32_t /* width from decompiler */ Named_CalleeOf_Client_WriteJoyCustomIni_00816270(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t *puVar3;

  int unaff_ESI;

  FILE *unaff_EDI;

  

  if ((*(int *)(unaff_ESI + 0x600) != 0) &&

     (iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x600) + 0x1dc))(), iVar1 != 0)) {

    uVar2 = (**(code **)(**(int **)(unaff_ESI + 0x600) + 0x1dc))();

    iVar1 = fprintf(unaff_EDI,"\n#\n# joy function labeled <%s> in-game\n#\n\n",uVar2);

    if (iVar1 < 0) {

      return 0;

    }

  }

  if (*(short *)(unaff_ESI + 0x818) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x80c) + 0x1dc))();

    if (iVar1 == 0) {

      puVar3 = &DAT_00a1419b;

    }

    else {

      puVar3 = (uint8_t *)(iVar1 + 4);

    }

    iVar1 = fprintf(unaff_EDI,"%s=%s\n",puVar3,param_1);

    if (iVar1 < 0) {

      return 0;

    }

  }

  if (*(short *)(unaff_ESI + 0x81a) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x810) + 0x1dc))();

    if (iVar1 == 0) {

      puVar3 = &DAT_00a1419b;

    }

    else {

      puVar3 = (uint8_t *)(iVar1 + 4);

    }

    iVar1 = fprintf(unaff_EDI,"%s=%s\n",puVar3,param_1);

    if (iVar1 < 0) {

      return 0;

    }

  }

  return 1;

}
