// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_Load_0079cf40
// -----------------------------------------------------------------------------
// Stable ID: aa_0079cf40
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile
// Address:   0x0079cf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, while×3, return×2, do×1, goto×1.
//  - Notable callees: CONCAT31, FUN_0079cf40.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile
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

uint Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_Load_0079cf40(char *param_1)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  byte unaff_BP;

  int *unaff_ESI;

  uint uVar4;

  int unaff_retaddr;

  

  pcVar2 = param_1;

  if (*(char *)((int)unaff_ESI + 5) == '\0') {

    if (*(char *)((int)unaff_ESI + 6) != '\0') {

      cVar1 = *param_1;

      while (cVar1 != '\0') {

        pcVar2 = pcVar2 + 1;

        cVar1 = *pcVar2;

      }

      (**(code **)(*unaff_ESI + 8))(param_1,(int)pcVar2 - (int)param_1);

      param_1 = (char *)CONCAT31(param_1._1_3_,*param_1);

      (**(code **)(*unaff_ESI + 8))(&param_1,1);

    }

    return 1;

  }

  uVar4 = 0;

  (**(code **)(*unaff_ESI + 4))(&param_1,1);

  if (unaff_BP != 0) {

    while (uVar4 < unaff_retaddr - 2U) {

      cVar1 = *param_1;

      if (cVar1 != '\0') {

        pcVar3 = param_1;

        do {

          if ((int)cVar1 == (uint)unaff_BP) goto LAB_0079cfb1;

          cVar1 = pcVar3[1];

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

      }

      pcVar2[uVar4] = unaff_BP;

      uVar4 = uVar4 + 1;

      (**(code **)(*unaff_ESI + 4))(&stack0xfffffffc,1);

      if (unaff_BP == 0) break;

    }

  }

LAB_0079cfb1:

  pcVar2[uVar4] = '\0';

  return uVar4;

}
