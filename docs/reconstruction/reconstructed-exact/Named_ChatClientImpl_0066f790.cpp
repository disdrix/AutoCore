// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×2.
//  - Notable callees: FUN_0066f790, FUN_0067b120, FUN_006813e0, FUN_006815a0, FUN_00681b20, FUN_006839f0, vog_LogMessage.
//  - Strings: "

                   ,0xb0,3,".
//  - Return sites: 3.

// =============================================================================
// Named_ChatClientImpl_0066f790
// -----------------------------------------------------------------------------
// Stable ID: aa_0066f790
// Address:   0x0066f790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_ChatClientImpl_0066f790(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8f6d;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0x58) != '\0') {

    return 0xffffffff;

  }

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = param_2;

  *(uint8_t *)(param_1 + 0x5a) = 0;

  FUN_0067b120(param_3);

  if (*(int *)(param_1 + 0x34) == 2) {

    pvVar2 = operator_new(0xd0);

    local_4 = 0;

    if (pvVar2 != (void *)0x0) {

      uVar3 = FUN_006839f0();

      goto LAB_0066f824;

    }

  }

  else {

    pvVar2 = operator_new(0x80);

    local_4 = 1;

    if (pvVar2 != (void *)0x0) {

      uVar3 = FUN_00681b20();

      goto LAB_0066f824;

    }

  }

  uVar3 = 0;

LAB_0066f824:

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = uVar3;

  pvVar2 = operator_new(0x18);

  local_4 = 2;

  if (pvVar2 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_006815a0();

  }

  local_4 = 0xffffffff;

  pvVar2 = operator_new(8);

  local_4 = 3;

  if (pvVar2 == (void *)0x0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_006813e0();

  }

  local_4 = 0xffffffff;

  (**(code **)(**(int **)(param_1 + 0x3c) + 0x2c))(uVar3,1);

  (**(code **)(**(int **)(param_1 + 0x3c) + 0x28))(uVar4,1);

  cVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x18))(puStack_8);

  if (cVar1 == '\0') {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                   ,0xb0,3,"Failed to connect to remote host.");

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x3c))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    ExceptionList = local_c;

    return 0xffffffff;

  }

  *(uint8_t *)(param_1 + 0x59) = 1;

  ExceptionList = local_c;

  return 0;

}
