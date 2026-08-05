// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0067b110×2, CONCAT22, FUN_0046e280, FUN_0067ba30, FUN_00727b70, FUN_00727c90.
//  - Strings: "SCCCheckReq"; "AuthServer".
//  - Return sites: 1.

// =============================================================================
// AuthClient_OnSCCCheckReq
// -----------------------------------------------------------------------------
// Purpose:  Inbound AuthServer SCCCheckReq handler - logs message type and dispatches callback.
//
// Address:  0x00727c90  (autoassault.exe, image base 0x400000)
// Stable:   aa_00727c90
// System:   auth
//
// String evidence: FUN_00727b70("SCCCheckReq","AuthServer")
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_00727c90.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_00727c90 using string evidence: FUN_00727b70("SCCCheckReq","AuthServer")
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ AuthClient_OnSCCCheckReq(int param_1)

{

  bool bVar1;

  bool bVar2;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  uint16_t uVar3;

  int unaff_EDI;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af16a;

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

  FUN_00727b70("SCCCheckReq","AuthServer");

  local_4 = 0;

  uVar3 = extraout_var;

  if (bVar1) {

    FUN_0067b110();

    uVar3 = extraout_var_00;

  }

  local_4 = 0xffffffff;

  if (bVar2) {

    FUN_0067b110();

    uVar3 = extraout_var_01;

  }

  if (*(int *)(unaff_EDI + 0x18) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x18) + 0x34))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),CONCAT22(uVar3,(ushort)*(byte *)(param_1 + 0x14)));

  }

  ExceptionList = local_c;

  return 0;

}
