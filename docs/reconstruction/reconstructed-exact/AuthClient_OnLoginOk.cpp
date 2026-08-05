// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0067b110×2, FUN_0046e280, FUN_0067ba30, FUN_00727b70, FUN_007280f0.
//  - Strings: "LoginOk"; "AuthServer".
//  - Return sites: 2.

// =============================================================================
// AuthClient_OnLoginOk
// -----------------------------------------------------------------------------
// Purpose:  Inbound AuthServer LoginOk handler - credentials accepted.
//
// Address:  0x007280f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_007280f0
// System:   auth
//
// String evidence: FUN_00727b70("LoginOk","AuthServer")
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_007280f0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_007280f0 using string evidence: FUN_00727b70("LoginOk","AuthServer")
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ __thiscall AuthClient_OnLoginOk(int param_1,int param_2)

{

  bool bVar1;

  bool bVar2;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af296;

  local_c = ExceptionList;

  if ((*(int **)(param_2 + 0x30) == (int *)0x0) || (**(int **)(param_2 + 0x30) == -1)) {

    ExceptionList = &local_c;

    FUN_0046e280(local_2c);

    local_4 = 1;

    bVar2 = false;

    bVar1 = true;

  }

  else {

    ExceptionList = &local_c;

    FUN_0067ba30(local_1c);

    local_4 = 0;

    bVar2 = true;

    bVar1 = false;

  }

  FUN_00727b70("LoginOk","AuthServer");

  local_4 = 0;

  if (bVar1) {

    FUN_0067b110();

  }

  local_4 = 0xffffffff;

  if (bVar2) {

    FUN_0067b110();

  }

  if (param_1 == 0) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (*(int *)(param_2 + 0x18) != 0) {

    (**(code **)(**(int **)(param_2 + 0x18) + 0x18))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14),

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x20),*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x28),*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x30));

  }

  ExceptionList = local_c;

  return 0;

}
