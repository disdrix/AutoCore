// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0067b110×2, CONCAT31, FUN_0046e280, FUN_0067ba30, FUN_0071d980, FUN_00727b70, FUN_00728590.
//  - Strings: "ProtocolVer"; "AuthServer".
//  - Return sites: 1.

// =============================================================================
// Auth_AuthServer_00728590
// -----------------------------------------------------------------------------
// Stable ID: aa_00728590
// Address:   0x00728590  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall Auth_AuthServer_00728590(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  bool bVar3;

  bool bVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t local_44 [16];

  uint8_t local_34 [16];

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af3c2;

  pvStack_c = ExceptionList;

  if ((*(int **)(param_2 + 0x30) == (int *)0x0) || (**(int **)(param_2 + 0x30) == -1)) {

    ExceptionList = &pvStack_c;

    FUN_0046e280(local_44);

    local_4 = 1;

    bVar4 = false;

    bVar3 = true;

  }

  else {

    ExceptionList = &pvStack_c;

    FUN_0067ba30(local_34);

    local_4 = 0;

    bVar4 = true;

    bVar3 = false;

  }

  FUN_00727b70("ProtocolVer","AuthServer");

  local_4 = 0;

  if (bVar3) {

    FUN_0067b110();

  }

  local_4 = 0xffffffff;

  if (bVar4) {

    FUN_0067b110();

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  local_24 = DAT_00aa74d4;

  local_18 = DAT_00aa74e0;

  local_20 = DAT_00aa74d8;

  local_1c = DAT_00aa74dc;

  local_14 = DAT_00aa74e4;

  local_10 = (void *)CONCAT31(local_10._1_3_,DAT_00aa74e8);

  FUN_0071d980(&local_24,0x15);

  iVar1 = *(int *)(param_2 + 0x34);

  *(uint8_t *)(param_2 + 0x40) = 1;

  if (*(int *)(iVar1 + 4) == 0) {

    puVar6 = operator_new(0x10);

    if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar6 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x38);

      *puVar6 = uVar2;

      uVar5 = DAT_00a27c38;

      puVar6[1] = DAT_00a27c38;

      puVar6[2] = uVar2;

      puVar6[3] = uVar5;

    }

    *(uint32_t /* width from decompiler */ **)(iVar1 + 4) = puVar6;

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = 2;

  (**(code **)(**(int **)(param_2 + 0x18) + 4))(param_2 + 0x20);

  ExceptionList = local_10;

  return 0;

}
