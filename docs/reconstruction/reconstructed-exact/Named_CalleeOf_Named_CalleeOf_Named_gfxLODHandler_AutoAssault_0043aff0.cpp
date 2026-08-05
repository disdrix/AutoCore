// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandler_AutoAssault_0043aff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043aff0
// Callee of Named_CalleeOf_Named_gfxLODHandler_AutoAssault
// Address:   0x0043aff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxLODHandler_AutoAssault: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0043aff0, FUN_0043b110, FUN_0043b190.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxLODHandler_AutoAssault
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandler_AutoAssault_0043aff0(uint param_1,uint32_t /* width from decompiler */ param_2,void *param_3)



{

  uint uVar1;

  int iVar2;

  int unaff_ESI;

  void *in_stack_00000018;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bedc8;

  local_c = ExceptionList;

  local_4 = 0;

  iVar2 = *(int *)(unaff_ESI + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(unaff_ESI + 8) - iVar2) / 0x28;

  }

  local_10 = param_1;

  if (uVar1 < param_1) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(unaff_ESI + 8) - iVar2) / 0x28;

    }

    ExceptionList = &local_c;

    FUN_0043b190(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),param_1 - iVar2);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar2 != 0) &&

       (ExceptionList = &local_c, param_1 < (uint)((*(int *)(unaff_ESI + 8) - iVar2) / 0x28))) {

      ExceptionList = &local_c;

      FUN_0043b110(unaff_ESI,&local_10,iVar2 + param_1 * 0x28,*(int *)(unaff_ESI + 8));

    }

  }

  if (in_stack_00000018 == (void *)0x0) {

    if (param_3 == (void *)0x0) {

      ExceptionList = local_c;

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(param_3);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(in_stack_00000018);

}
