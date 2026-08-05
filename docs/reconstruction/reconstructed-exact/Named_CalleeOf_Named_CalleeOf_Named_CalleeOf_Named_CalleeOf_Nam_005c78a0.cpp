// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c78a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c78a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x005c78a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper. Evidence string: "CLoadNode::_initFull". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CLoadNode::_initFull"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0076cef0×2, FUN_00516be0, FUN_005c6ad0, FUN_005c7290, FUN_005c78a0, FUN_0076cf00.
//  - Strings: "CLoadNode::_initFull".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c78a0(int param_1,int param_2,char param_3)



{

  int iVar1;

  int *piVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e4d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::_initFull");

  local_4 = 0;

  if (param_3 == '\0') {

    iVar1 = FUN_005c6ad0(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x160);

    if (iVar1 == 3) {

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return 3;

    }

  }

  else {

    FUN_005c7290(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x160);

  }

  *(uint8_t *)(param_1 + 99) = 0;

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1c8))();

  if (((iVar1 == 0) ||

      (*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x38) != 0xe)) ||

     (*(char *)(param_1 + 0x69) != '\0')) {

    FUN_00516be0();

  }

  if (*(char *)(param_1 + 0x6a) != '\0') {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x100))();

  }

  piVar2 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1d0))

                            ();

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 0x44))();

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0;

}
