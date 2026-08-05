// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_004611e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004611e0
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x004611e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004611e0, FUN_00461720, FUN_004617a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_004611e0(uint param_1)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  int unaff_EDI;

  int *in_stack_00000014;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be618;

  local_c = ExceptionList;

  local_4 = 0;

  iVar3 = *(int *)(unaff_EDI + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(unaff_EDI + 8) - iVar3) / 0x1c;

  }

  local_10 = param_1;

  if (uVar2 < param_1) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(unaff_EDI + 8) - iVar3) / 0x1c;

    }

    ExceptionList = &local_c;

    FUN_004617a0(unaff_EDI,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),param_1 - iVar3);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar3 != 0) &&

       (ExceptionList = &local_c, param_1 < (uint)((*(int *)(unaff_EDI + 8) - iVar3) / 0x1c))) {

      ExceptionList = &local_c;

      FUN_00461720(unaff_EDI,&local_10,iVar3 + param_1 * 0x1c,*(int *)(unaff_EDI + 8));

    }

  }

  local_4 = 0xffffffff;

  if (in_stack_00000014 != (int *)0x0) {

    piVar1 = in_stack_00000014 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*in_stack_00000014 + 8))();

    }

  }

  ExceptionList = local_c;

  return;

}
