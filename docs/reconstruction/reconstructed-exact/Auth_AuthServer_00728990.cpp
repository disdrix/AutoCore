// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0067b110×2, FUN_0043fe60, FUN_0046e280, FUN_006759b0, FUN_0067ba30, FUN_00718c10, FUN_00727c00, FUN_00728990.
//  - Strings: "AboutToPlay"; "AuthServer".
//  - Return sites: 1.

// =============================================================================
// Auth_AuthServer_00728990
// -----------------------------------------------------------------------------
// Stable ID: aa_00728990
// Address:   0x00728990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AuthServer"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Auth_AuthServer_00728990(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  bool bVar2;

  bool bVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af497;

  local_c = ExceptionList;

  if ((*(int **)(param_1 + 0x30) == (int *)0x0) || (**(int **)(param_1 + 0x30) == -1)) {

    ExceptionList = &local_c;

    FUN_0046e280(local_2c);

    local_4 = 1;

    bVar3 = false;

    bVar2 = true;

  }

  else {

    ExceptionList = &local_c;

    FUN_0067ba30(local_1c);

    local_4 = 0;

    bVar3 = true;

    bVar2 = false;

  }

  FUN_00727c00("AboutToPlay","AuthServer");

  local_4 = 0;

  if (bVar2) {

    FUN_0067b110();

  }

  local_4 = 0xffffffff;

  if (bVar3) {

    FUN_0067b110();

  }

  puVar4 = operator_new(0x1c);

  local_4 = 2;

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_00718c10(2,0);

    *puVar4 = &PTR_FUN_00aa9a08;

    puVar4[4] = 0;

    puVar4[5] = 0;

    *(uint8_t *)(puVar4 + 6) = 0;

  }

  local_4 = 0xffffffff;

  puVar4[4] = param_2;

  puVar4[5] = param_3;

  *(uint8_t *)(puVar4 + 6) = param_4._0_1_;

  iVar1 = *(int *)(param_1 + 0x48);

  param_4 = puVar4;

  iVar5 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&param_4);

  FUN_0043fe60();

  *(int *)(iVar1 + 4) = iVar5;

  **(int **)(iVar5 + 4) = iVar5;

  ExceptionList = local_c;

  return 0;

}
