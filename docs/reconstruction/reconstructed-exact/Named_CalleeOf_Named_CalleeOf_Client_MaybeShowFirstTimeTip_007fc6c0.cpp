// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_MaybeShowFirstTimeTip_007fc6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc6c0
// Callee of Named_CalleeOf_Client_MaybeShowFirstTimeTip
// Address:   0x007fc6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_MaybeShowFirstTimeTip: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, goto×4.
//  - Notable callees: FUN_007fc6c0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_MaybeShowFirstTimeTip
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

void Named_CalleeOf_Named_CalleeOf_Client_MaybeShowFirstTimeTip_007fc6c0(void)



{

  uint8_t *puVar1;

  int iVar2;

  uint8_t *puVar3;

  char cVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_48;

  uint8_t *puStack_44;

  int iStack_40;

  uint8_t *puStack_3c;

  int iStack_38;

  uint8_t *puStack_34;

  int iStack_30;

  int aiStack_20 [2];

  uint8_t auStack_18 [4];

  int iStack_14;

  int iStack_8;

  

  if (*(int *)(unaff_ESI + 0x1144) == 0) {

    return;

  }

  cVar4 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();

  if (cVar4 == '\0') {

    return;

  }

  if (*(int *)(unaff_ESI + 0x1168) == 0) {

    return;

  }

  iStack_30 = 1;

  puStack_34 = auStack_18;

  iStack_38 = 0x7fc70b;

  (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x140))();

  iStack_38 = 1;

  puStack_3c = auStack_18;

  iStack_40 = 0x7fc720;

  iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x1168) + 0x140))();

  iVar2 = *(int *)(iVar5 + 4);

  iStack_40 = 1;

  puStack_44 = auStack_18;

  uStack_48 = 0x7fc73c;

  piVar6 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x1168) + 0x140))();

  iVar7 = *piVar6 + iStack_14;

  iVar5 = iStack_30 + iVar7;

  uStack_48 = 1;

  iStack_38 = iVar7;

  puStack_34 = (uint8_t *)(iVar2 + iStack_8);

  piVar6 = (int *)(**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x140))(aiStack_20);

  puVar3 = puStack_3c;

  if (*piVar6 < iVar5) {

    iStack_40 = iStack_14 - iStack_38;

LAB_007fc782:

    if (iStack_40 < 0) goto LAB_007fc788;

  }

  else {

    if (-1 < iVar7) goto LAB_007fc782;

LAB_007fc788:

    iStack_40 = 0;

  }

  puVar1 = puStack_3c + (int)puStack_34;

  iVar5 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x140))(&stack0xffffffd8,1);

  if (*(int *)(iVar5 + 4) < (int)puVar1) {

    puStack_44 = (uint8_t *)(aiStack_20[0] - (int)puStack_3c);

LAB_007fc7c7:

    if (-1 < (int)puStack_44) goto LAB_007fc7d1;

  }

  else if (-1 < (int)puVar3) goto LAB_007fc7c7;

  puStack_44 = (uint8_t *)0x0;

LAB_007fc7d1:

  (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x118))(&uStack_48);

  return;

}
