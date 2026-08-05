// =============================================================================
// FUN_004ed1a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ed1a0
// Address:   0x004ed1a0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004ed1a0(uint32_t /* width from decompiler */ *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint32_t /* width from decompiler */ *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_c = ExceptionList;
  puStack_8 = &LAB_009a28ec;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009ccf24;
  iVar1 = param_1[0xc];
  local_4 = 7;
  *(uint8_t *)(param_1 + 0xb) = 0;
  local_10 = param_1;
  while (iVar1 != 0) {
    FUN_004eb010();
    iVar1 = param_1[0xc];
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if ((void *)param_1[0x21] != (void *)0x0) {
    operator_delete__((void *)param_1[0x21]);
  }
  uVar3 = 0;
  param_1[0x21] = 0;
  if (param_1[0x7c] != 0) {
    do {
      cVar2 = FUN_0050e770(uVar3,&local_10);
      if (cVar2 != '\0') {
        operator_delete__(local_10);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)param_1[0x7c]);
  }
  FUN_00410d60();
  param_1[0x73] = &PTR_FUN_009cccfc;
  FUN_00416c90();
  param_1[0x73] = &PTR_FUN_009ccc2c;
  FUN_00416c90();
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  local_10 = param_1 + 0x24;
  local_4 = 8;
  FUN_004eaf30();
  local_4 = 0xffffffff;
  if (-1 < (int)param_1[0x2a]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x28],param_1[0x2a] << 4,0x12);
  }
  ExceptionList = local_c;
  return;
}
