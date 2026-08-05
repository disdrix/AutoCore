// =============================================================================
// CLoadNode_initAI
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6880
// Address:   0x005c6880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall CLoadNode_initAI(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6dba;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0076cf00("CLoadNode::_initAI");
  *(uint8_t *)(param_1 + 100) = 0;
  local_4 = 0;
  piVar1 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1d8))
                            ();
  if (piVar1 == (int *)0x0) goto LAB_005c6932;
  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1dc))();
  if (iVar2 == 0) {
    if (((piVar1[0x8a] & piVar1[0x8b]) != 0xffffffff) || (param_2 = 0, (char)piVar1[0x8c] != '\0'))
    goto LAB_005c691c;
  }
  else {
LAB_005c691c:
    param_2 = 1;
  }
  (**(code **)(*piVar1 + 0xc0))(param_2,0xffffffff);
LAB_005c6932:
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_c;
  return 0;
}
