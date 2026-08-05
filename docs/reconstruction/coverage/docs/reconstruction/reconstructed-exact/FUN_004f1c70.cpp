// =============================================================================
// FUN_004f1c70
// -----------------------------------------------------------------------------
// Stable ID: aa_004f1c70
// Address:   0x004f1c70  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004f1c70(int param_1)

{
  char *pcVar1;
  size_t sVar2;
  uint32_t /* width from decompiler */ uVar3;
  uint32_t /* width from decompiler */ *puVar4;
  uint8_t local_19d;
  void *local_19c;
  uint8_t local_198 [4];
  uint8_t *local_194;
  uint8_t local_190 [128];
  char local_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2b66;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x28) == '\0') {
    ExceptionList = &local_c;
    *(uint8_t *)(param_1 + 0x28) = 1;
    pcVar1 = (char *)FUN_005de8f0(&local_19d);
    if (*pcVar1 != '\0') {
      local_19c = (void *)DAT_00d1f040;
      FUN_0076cf00("Preload::ReloadRigidBody");
      local_4 = 0;
      FUN_004f1180();
      local_4 = 0xffffffff;
      FUN_0076cef0();
    }
    if ((*(int *)(param_1 + 0x88) == 0) && (*(int *)(param_1 + 0x3c) != -0x316)) {
      sVar2 = wcslen((wchar_t *)(*(int *)(param_1 + 0x3c) + 0x316));
      if (1 < sVar2) {
        local_19c = operator_new(8);
        local_4 = 1;
        if (local_19c == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_004a1620();
        }
        *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = uVar3;
        local_4 = 0xffffffff;
        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(param_1 + 0x3c) + 0x316);
        local_4 = 2;
        FUN_004a6390(*puVar4);
        local_4 = 0xffffffff;
        if (local_194 != local_190) {
          free(local_194);
        }
        _snprintf(local_110,0x104,"%S%s",*(int *)(param_1 + 0x3c) + 0x316,&DAT_009ca184);
        FUN_0043d650(0);
        FUN_00989e00(local_198,local_110);
        FUN_0043d670(local_198);
      }
    }
  }
  ExceptionList = local_c;
  return;
}
