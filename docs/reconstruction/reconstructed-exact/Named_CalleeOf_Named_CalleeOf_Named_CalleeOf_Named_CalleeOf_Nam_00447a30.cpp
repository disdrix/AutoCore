// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00447a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00447a30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff
// Address:   0x00447a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×2, while×2, if×1.
//  - Notable callees: FUN_00447a30, FUN_00447ac0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00447a30(void)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar7;

  int unaff_EBX;

  

  iVar2 = *(int *)(in_EAX + 4);

  uVar7 = FUN_00447ac0(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 4) + 4),iVar2);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = uVar7;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8);

  piVar3 = *(int **)(in_EAX + 4);

  piVar4 = (int *)piVar3[1];

  if (*(char *)((int)piVar4 + 0x11) != '\0') {

    *piVar3 = (int)piVar3;

    *(int *)(*(int *)(in_EAX + 4) + 8) = *(int *)(in_EAX + 4);

    return;

  }

  cVar1 = *(char *)(*piVar4 + 0x11);

  piVar6 = (int *)*piVar4;

  while (cVar1 == '\0') {

    cVar1 = *(char *)(*piVar6 + 0x11);

    piVar4 = piVar6;

    piVar6 = (int *)*piVar6;

  }

  *piVar3 = (int)piVar4;

  iVar2 = *(int *)(*(int *)(in_EAX + 4) + 4);

  iVar5 = *(int *)(iVar2 + 8);

  cVar1 = *(char *)(iVar5 + 0x11);

  while (cVar1 == '\0') {

    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x11);

    iVar2 = iVar5;

    iVar5 = *(int *)(iVar5 + 8);

  }

  *(int *)(*(int *)(in_EAX + 4) + 8) = iVar2;

  return;

}
