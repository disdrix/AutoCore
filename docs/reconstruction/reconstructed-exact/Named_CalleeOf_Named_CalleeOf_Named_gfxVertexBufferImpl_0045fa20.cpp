// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_0045fa20
// -----------------------------------------------------------------------------
// Stable ID: aa_0045fa20
// Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
// Address:   0x0045fa20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0045f5d0, FUN_0045fa20, FUN_0045ffb0, FUN_00460010.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_0045fa20(int param_1,uint param_2)



{

  uint uVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bec78;

  pvStack_c = ExceptionList;

  local_4 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 5;

  }

  if (uVar1 < param_2) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 5;

    }

    ExceptionList = &pvStack_c;

    FUN_00460010(param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar2);

  }

  else {

    ExceptionList = &pvStack_c;

    if ((iVar2 != 0) &&

       (ExceptionList = &pvStack_c, param_2 < (uint)(*(int *)(param_1 + 8) - iVar2 >> 5))) {

      ExceptionList = &pvStack_c;

      FUN_0045ffb0(param_1,&param_2,param_2 * 0x20 + iVar2,*(int *)(param_1 + 8));

    }

  }

  local_4 = 0xffffffff;

  FUN_0045f5d0();

  ExceptionList = pvStack_c;

  return;

}
