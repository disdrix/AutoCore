// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0067b110×2, FUN_0046e280, FUN_0067ba30, FUN_00727b70, FUN_007283d0.
//  - Strings: "BlockedAccount"; "AuthServer".
//  - Return sites: 1.

// =============================================================================
// AuthClient_OnBlockedAccount
// -----------------------------------------------------------------------------
// Purpose:  Inbound AuthServer BlockedAccount handler - account blocked.
//
// Address:  0x007283d0  (autoassault.exe, image base 0x400000)
// Stable:   aa_007283d0
// System:   auth
//
// String evidence: FUN_00727b70("BlockedAccount","AuthServer")
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_007283d0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_007283d0 using string evidence: FUN_00727b70("BlockedAccount","AuthServer")
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ AuthClient_OnBlockedAccount(int param_1)

{

  uint uVar1;

  int unaff_EDI;

  uint uVar2;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af34a;

  local_c = ExceptionList;

  if ((*(int **)(unaff_EDI + 0x30) == (int *)0x0) || (**(int **)(unaff_EDI + 0x30) == -1)) {

    ExceptionList = &local_c;

    FUN_0046e280(local_2c);

    local_4 = 1;

    uVar1 = 2;

  }

  else {

    ExceptionList = &local_c;

    FUN_0067ba30(local_1c);

    local_4 = 0;

    uVar1 = 1;

  }

  uVar2 = uVar1;

  FUN_00727b70("BlockedAccount","AuthServer");

  local_4 = 0;

  if ((uVar1 & 2) != 0) {

    uVar1 = uVar1 & 0xfffffffd;

    uVar2 = uVar1;

    FUN_0067b110();

  }

  local_4 = 0xffffffff;

  if ((uVar1 & 1) != 0) {

    FUN_0067b110(uVar2);

  }

  if (*(int *)(unaff_EDI + 0x18) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x18) + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  }

  ExceptionList = local_c;

  return 0;

}
