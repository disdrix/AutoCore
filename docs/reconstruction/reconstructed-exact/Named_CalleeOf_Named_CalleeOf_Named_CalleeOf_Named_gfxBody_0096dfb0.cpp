// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_0096dfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096dfb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x0096dfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_00416160, FUN_0096dfb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_0096dfb0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  FUN_00416160(param_1 + 0x30);

  if (param_1 == -0xf0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)(param_1 + 0xf4);

  }

  piVar3 = (int *)*piVar3;

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(unaff_EBX + 0xf4);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(unaff_EBX + 0xf4) = piVar3;

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x100);

  puVar6 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x100);

  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x140) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x144) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x144);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x148) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x148);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x150) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x150);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x154) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x154);

  return;

}
