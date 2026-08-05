// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00440db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00440db0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x00440db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00440db0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

int * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00440db0(int *param_1)



{

  int *piVar1;

  int iVar2;

  int *unaff_ESI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bd5d8;

  pvStack_c = ExceptionList;

  piVar1 = (int *)*unaff_ESI;

  ExceptionList = &pvStack_c;

  if ((piVar1 != (int *)0x0) &&

     (ExceptionList = &pvStack_c, piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {

    (**(code **)(*piVar1 + 4))();

  }

  *param_1 = *unaff_ESI;

  *(char *)(param_1 + 1) = (char)unaff_ESI[1];

  *(uint8_t *)((int)param_1 + 5) = *(uint8_t *)((int)unaff_ESI + 5);

  *(uint8_t *)((int)param_1 + 6) = *(uint8_t *)((int)unaff_ESI + 6);

  local_4 = 0;

  iVar2 = unaff_ESI[2];

  if (iVar2 != 0) {

    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

    if (*(int *)(iVar2 + 8) == 1) {

      (**(code **)(*(int *)(iVar2 + 4) + 4))();

    }

  }

  param_1[2] = unaff_ESI[2];

  param_1[3] = unaff_ESI[3];

  ExceptionList = pvStack_c;

  return param_1;

}
