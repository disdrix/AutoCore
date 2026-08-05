// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00748430
// -----------------------------------------------------------------------------
// Stable ID: aa_00748430
// Callee of Named_CalleeOf_Named_gfxDeviceVB (+1 other named callers)
// Address:   0x00748430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_gfxDeviceVB (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×15, for×1, return×1.
//  - Notable callees: FUN_004148e0, FUN_0044c010, FUN_00748430.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00748430(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  if (param_1 == -8) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)(param_1 + 0xc);

  }

  piVar3 = (int *)*piVar3;

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(unaff_EBX + 0xc);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(unaff_EBX + 0xc) = piVar3;

  if (param_1 == -0x10) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)(param_1 + 0x14);

  }

  piVar3 = (int *)*piVar3;

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(unaff_EBX + 0x14);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(unaff_EBX + 0x14) = piVar3;

  if (param_1 == -0x18) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)(param_1 + 0x1c);

  }

  piVar3 = (int *)*piVar3;

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(unaff_EBX + 0x1c);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(unaff_EBX + 0x1c) = piVar3;

  FUN_004148e0(param_1 + 0x20);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  puVar6 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x28);

  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x58) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x58);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x60) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x74) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x8c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x90) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x90);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x94) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x94);

  FUN_0044c010();

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xa8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xac) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xac);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xb0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

  piVar3 = *(int **)(param_1 + 0xb8);

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(unaff_EBX + 0xb8);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(unaff_EBX + 0xb8) = piVar3;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc);

  return;

}
