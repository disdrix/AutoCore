// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil_004815a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004815a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile
// Address:   0x004815a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, while×1, goto×1.
//  - Notable callees: _stricmp×2, FUN_0044f480, FUN_004815a0, FUN_00481750.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil_004815a0(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *in_EAX;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar7;

  bool bVar8;

  

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  bVar8 = true;

  cVar1 = *(char *)((int)puVar5 + 0x25);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar1 == '\0') {

    pcVar4 = (char *)puVar5[3];

    if ((char *)puVar5[3] == (char *)0x0) {

      pcVar4 = PTR_DAT_00afa2bc;

    }

    pcVar6 = (char *)*in_EAX;

    if ((char *)*in_EAX == (char *)0x0) {

      pcVar6 = PTR_DAT_00afa2bc;

    }

    iVar3 = _stricmp(pcVar6,pcVar4);

    bVar8 = iVar3 < 0;

    if (bVar8) {

      puVar7 = (uint32_t /* width from decompiler */ *)*puVar5;

    }

    else {

      puVar7 = (uint32_t /* width from decompiler */ *)puVar5[2];

    }

    puVar2 = puVar5;

    puVar5 = puVar7;

    cVar1 = *(char *)((int)puVar7 + 0x25);

  }

  if (bVar8) {

    if (puVar2 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      bVar8 = true;

      goto LAB_00481651;

    }

    FUN_0044f480();

  }

  pcVar4 = (char *)*in_EAX;

  if ((char *)*in_EAX == (char *)0x0) {

    pcVar4 = PTR_DAT_00afa2bc;

  }

  pcVar6 = (char *)puVar2[3];

  if ((char *)puVar2[3] == (char *)0x0) {

    pcVar6 = PTR_DAT_00afa2bc;

  }

  iVar3 = _stricmp(pcVar6,pcVar4);

  if (-1 < iVar3) {

    *unaff_EBX = puVar2;

    *(uint8_t *)(unaff_EBX + 1) = 0;

    return;

  }

LAB_00481651:

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_00481750(&param_1,bVar8,in_EAX);

  *unaff_EBX = *puVar5;

  *(uint8_t *)(unaff_EBX + 1) = 1;

  return;

}
