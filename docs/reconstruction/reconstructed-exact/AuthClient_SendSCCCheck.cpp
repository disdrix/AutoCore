// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0067b110×2, FUN_0043fe60, FUN_0046e280, FUN_006759b0, FUN_0067ba30, FUN_00718c10, FUN_00727c00, FUN_00728700.
//  - Strings: "SCCCheck"; "AuthServer".
//  - Return sites: 1.

// =============================================================================
// AuthClient_SendSCCCheck
// -----------------------------------------------------------------------------
// Purpose:  Outbound AuthServer SCCCheck enqueue - client anti-cheat/SCC check packet.
//
// Address:  0x00728700  (autoassault.exe, image base 0x400000)
// Stable:   aa_00728700
// System:   auth
//
// String evidence: FUN_00727b70("SCCCheck","AuthServer")
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_00728700.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_00728700 using string evidence: FUN_00727b70("SCCCheck","AuthServer")
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ AuthClient_SendSCCCheck(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)

{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint uVar5;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar2 = (int)param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af409;

  local_c = ExceptionList;

  param_1 = (uint32_t /* width from decompiler */ *)0x0;

  piVar1 = *(int **)(iVar2 + 0x30);

  if ((piVar1 == (int *)0x0) || (*piVar1 == -1)) {

    ExceptionList = &local_c;

    FUN_0046e280(local_2c);

    local_4 = 1;

    uVar5 = 2;

  }

  else {

    ExceptionList = &local_c;

    FUN_0067ba30(local_1c);

    local_4 = 0;

    uVar5 = 1;

  }

  param_1 = (uint32_t /* width from decompiler */ *)uVar5;

  FUN_00727c00("SCCCheck","AuthServer");

  local_4 = 0;

  if ((uVar5 & 2) != 0) {

    uVar5 = uVar5 & 0xfffffffd;

    param_1 = (uint32_t /* width from decompiler */ *)uVar5;

    FUN_0067b110();

  }

  local_4 = 0xffffffff;

  if ((uVar5 & 1) != 0) {

    FUN_0067b110();

  }

  puVar3 = operator_new(0x18);

  local_4 = 2;

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    param_1 = puVar3;

    FUN_00718c10(6,0);

    *puVar3 = &PTR_FUN_00aa99a8;

    puVar3[4] = 0;

    puVar3[5] = 0;

  }

  local_4 = 0xffffffff;

  puVar3[4] = param_2;

  puVar3[5] = param_3;

  iVar2 = *(int *)(iVar2 + 0x48);

  param_1 = puVar3;

  iVar4 = FUN_006759b0(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),&param_1);

  FUN_0043fe60();

  *(int *)(iVar2 + 4) = iVar4;

  **(int **)(iVar4 + 4) = iVar4;

  ExceptionList = local_c;

  return 0;

}
