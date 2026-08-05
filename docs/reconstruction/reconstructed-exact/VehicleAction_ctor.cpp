// =============================================================================
// VehicleAction_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00597f90
// Address:   0x00597f90  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ * __thiscall
VehicleAction_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,
                  int param_5)

{
  uint32_t /* width from decompiler */ uVar1;
  uint32_t /* width from decompiler */ uVar2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a5acd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00636370(param_3);
  uVar2 = DAT_009d54e0;
  uVar1 = DAT_009c7bc0;
  local_4 = 0;
  *(uint8_t *)(param_1 + 7) = 0;
  *(uint8_t *)(param_1 + 0xb) = 0;
  param_1[0xf] = 0;
  param_1[8] = uVar2;
  *param_1 = &PTR_FUN_009d54c4;
  param_1[2] = &PTR_LAB_009d54b0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = uVar1;
  param_1[0xd] = 0;
  param_1[0xe] = param_5;
  param_1[0x10] = param_4;
  param_1[0x11] = param_2;
  if (param_5 == 1) {
    FUN_00597ec0();
  }
  ExceptionList = local_c;
  return param_1;
}
