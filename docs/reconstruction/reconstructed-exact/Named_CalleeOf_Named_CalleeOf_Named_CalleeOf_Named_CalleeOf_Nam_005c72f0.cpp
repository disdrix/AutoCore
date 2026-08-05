// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c72f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c72f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x005c72f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper. Evidence string: "CLoadNode::_initPreload". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CLoadNode::_initPreload"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0076cef0×2, FUN_004eb3b0, FUN_004f2540, FUN_005c6ad0, FUN_005c7290, FUN_005c72f0, FUN_0076cf00.
//  - Strings: "CLoadNode::_initPreload".
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c72f0(int param_1,int *param_2,char param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e02;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::_initPreload");

  local_4 = 0;

  if (param_3 == '\0') {

    iVar1 = FUN_005c6ad0(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x174);

    if (iVar1 == 3) {

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return 3;

    }

  }

  else {

    FUN_005c7290(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x174);

  }

  *(uint8_t *)(param_1 + 0x66) = 0;

  FUN_004eb3b0();

  if (*(int *)(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x134) == 0) {

    FUN_004f2540();

  }

  uVar2 = (**(code **)(*param_2 + 0xc))();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = uVar2;

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0;

}
