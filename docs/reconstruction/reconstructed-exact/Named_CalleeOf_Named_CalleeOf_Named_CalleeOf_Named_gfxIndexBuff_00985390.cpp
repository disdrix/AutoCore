// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBuff_00985390
// -----------------------------------------------------------------------------
// Stable ID: aa_00985390
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBufferImpl
// Address:   0x00985390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00445750, FUN_00445c80, FUN_004477a0, FUN_00460a60, FUN_00985390.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBufferImpl
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBuff_00985390(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int in_EAX;

  uint unaff_EBX;

  int *piVar5;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_00445750();

  FUN_004477a0(param_1 + 4,&local_4,local_4);

  if (*(int *)(param_1 + 0xc) == 0) {

    return 1;

  }

  iVar1 = *(int *)(in_EAX + 0x18);

  iVar2 = *(int *)(in_EAX + 0x1c);

  piVar3 = *(int **)(param_1 + 0x18);

  piVar4 = *(int **)(param_1 + 0x14);

  piVar5 = (int *)(unaff_EBX & 0xffffff00);

  FUN_00460a60(piVar4,piVar3,piVar5);

  if ((piVar5 != piVar3) && (iVar2 + iVar1 == *piVar5)) {

    *piVar5 = iVar1;

    piVar5[1] = piVar5[1] + iVar2;

    return 0;

  }

  if ((piVar5 != piVar4) && (piVar5[-1] + piVar5[-2] == iVar1)) {

    piVar5[-1] = piVar5[-1] + iVar2;

    return 0;

  }

  FUN_00445c80(piVar5,&stack0xffffffe8);

  return 0;

}
