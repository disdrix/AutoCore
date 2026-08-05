// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0067b110×2, FUN_0046e280, FUN_0067ba30, FUN_00727b70, FUN_00727f30.
//  - Strings: "PlayOk"; "AuthServer".
//  - Return sites: 1.

// =============================================================================
// AuthClient_OnPlayOk
// -----------------------------------------------------------------------------
// Purpose:  Inbound AuthServer PlayOk handler - character/play session approved.
//
// Address:  0x00727f30  (autoassault.exe, image base 0x400000)
// Stable:   aa_00727f30
// System:   auth
//
// String evidence: FUN_00727b70("PlayOk","AuthServer")
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_00727f30.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_00727f30 using string evidence: FUN_00727b70("PlayOk","AuthServer")
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ AuthClient_OnPlayOk(int param_1)

{

  bool bVar1;

  bool bVar2;

  int unaff_EDI;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af21e;

  local_c = ExceptionList;

  if ((*(int **)(unaff_EDI + 0x30) == (int *)0x0) || (**(int **)(unaff_EDI + 0x30) == -1)) {

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

  FUN_00727b70("PlayOk","AuthServer");

  local_4 = 0;

  if (bVar1) {

    FUN_0067b110();

  }

  local_4 = 0xffffffff;

  if (bVar2) {

    FUN_0067b110();

  }

  if (*(int *)(unaff_EDI + 0x18) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x18) + 0x28))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14),

               *(uint8_t *)(param_1 + 0x18));

  }

  ExceptionList = local_c;

  return 0;

}
