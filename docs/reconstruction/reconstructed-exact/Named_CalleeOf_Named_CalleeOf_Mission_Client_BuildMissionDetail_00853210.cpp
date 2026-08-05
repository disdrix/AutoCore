// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Client_BuildMissionDetail_00853210
// -----------------------------------------------------------------------------
// Stable ID: aa_00853210
// Callee of Named_CalleeOf_Mission_Client_BuildMissionDetailPanel
// Address:   0x00853210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Client_BuildMissionDetailPanel: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00853210.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Client_BuildMissionDetailPanel
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

void Named_CalleeOf_Named_CalleeOf_Mission_Client_BuildMissionDetail_00853210(void)



{

  int iVar1;

  int iVar2;

  int *in_EAX;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  int *unaff_ESI;

  uint8_t local_30 [48];

  

  if (unaff_ESI != (int *)0x0) {

    iVar3 = (**(code **)(*unaff_ESI + 0x120))(local_30,1,0);

    iVar4 = (**(code **)(*in_EAX + 0x140))(&stack0xffffffcc,1);

    iVar4 = *(int *)(iVar4 + 4);

    iVar3 = *(int *)(iVar3 + 4);

    piVar5 = (int *)(**(code **)(*unaff_ESI + 0x120))(&stack0xffffffcc,1,0);

    piVar6 = (int *)(**(code **)(*in_EAX + 0x140))(&stack0xffffffc8,1);

    iVar1 = *piVar6;

    iVar2 = *piVar5;

    iVar7 = (**(code **)(*unaff_ESI + 0x120))(&stack0xffffffc8,1,0);

    iVar7 = *(int *)(iVar7 + 4);

    piVar5 = (int *)(**(code **)(*unaff_ESI + 0x120))(&stack0xffffffc4,1,0);

    unaff_ESI[100] = -*piVar5;

    unaff_ESI[0x65] = -iVar7;

    unaff_ESI[0x66] = iVar1 - iVar2;

    unaff_ESI[0x67] = iVar4 - iVar3;

    (**(code **)(*unaff_ESI + 0x34c))();

  }

  return;

}
