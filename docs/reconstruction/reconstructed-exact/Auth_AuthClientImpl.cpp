// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×2, while×2.
//  - Notable callees: strncpy×3, FUN_0067b110×2, FUN_0076cec0×2, vog_LogMessage×2, FUN_0043fe60, FUN_0046e280, FUN_006759b0, FUN_0067ba30.
//  - Strings: "LoginInsecure"; "AuthServer"; "username string too long".
//  - Return sites: 3.

// =============================================================================
// Auth_AuthClientImpl
// -----------------------------------------------------------------------------
// Stable ID: aa_00728c20
// Address:   0x00728c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AuthClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Auth_AuthClientImpl(int param_1,char *param_2,char *param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  char cVar1;

  int iVar2;

  bool bVar3;

  bool bVar4;

  void *pvVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  uint8_t local_4c [16];

  uint8_t local_3c [16];

  char local_2c [32];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af525;

  local_c = ExceptionList;

  iVar8 = 0;

  if ((*(int **)(param_1 + 0x30) == (int *)0x0) || (**(int **)(param_1 + 0x30) == -1)) {

    ExceptionList = &local_c;

    FUN_0046e280(local_4c);

    local_4 = 1;

    bVar4 = false;

    bVar3 = true;

  }

  else {

    ExceptionList = &local_c;

    FUN_0067ba30(local_3c);

    local_4 = 0;

    bVar4 = true;

    bVar3 = false;

  }

  FUN_00727c00("LoginInsecure","AuthServer");

  local_4 = 0;

  if (bVar3) {

    FUN_0067b110();

  }

  local_4 = 0xffffffff;

  if (bVar4) {

    FUN_0067b110();

  }

  pvVar5 = operator_new(0x38);

  local_4 = 2;

  if (pvVar5 != (void *)0x0) {

    iVar8 = FUN_0071e420();

  }

  local_4 = 0xffffffff;

  local_2c[0] = '\0';

  local_2c[1] = '\0';

  local_2c[2] = '\0';

  local_2c[3] = '\0';

  local_2c[4] = '\0';

  local_2c[5] = '\0';

  local_2c[6] = '\0';

  local_2c[7] = '\0';

  local_2c[8] = '\0';

  local_2c[9] = '\0';

  local_2c[10] = '\0';

  local_2c[0xb] = '\0';

  local_2c[0xc] = '\0';

  local_2c[0xd] = '\0';

  local_2c[0xe] = '\0';

  local_2c[0xf] = '\0';

  local_2c[0x10] = '\0';

  local_2c[0x11] = '\0';

  local_2c[0x12] = '\0';

  local_2c[0x13] = '\0';

  local_2c[0x14] = '\0';

  local_2c[0x15] = '\0';

  local_2c[0x16] = '\0';

  local_2c[0x17] = '\0';

  local_2c[0x18] = '\0';

  local_2c[0x19] = '\0';

  local_2c[0x1a] = '\0';

  local_2c[0x1b] = '\0';

  local_2c[0x1c] = '\0';

  local_2c[0x1d] = '\0';

  pcVar6 = param_2;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  if (0xe < (int)pcVar6 - (int)(param_2 + 1)) {

    uVar7 = FUN_0076cec0(&param_5,"username string too long");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\infrastruct\\Auth\\authClientLib\\AuthClientImpl.cpp"

                   ,0xf9,3,uVar7);

    ExceptionList = local_c;

    return 0xffffffff;

  }

  strncpy(local_2c,param_2,0xe);

  pcVar6 = param_3;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  if (0x10 < (int)pcVar6 - (int)(param_3 + 1)) {

    uVar7 = FUN_0076cec0(&param_5,"username string too long");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\infrastruct\\Auth\\authClientLib\\AuthClientImpl.cpp"

                   ,0x101,3,uVar7);

    ExceptionList = local_c;

    return 0xffffffff;

  }

  strncpy((char *)(iVar8 + 0x10),param_2,0xe);

  strncpy((char *)(iVar8 + 0x1e),param_3,0x10);

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x30) = param_4;

  *(uint16_t *)(iVar8 + 0x34) = (uint16_t)param_5;

  iVar2 = *(int *)(param_1 + 0x48);

  param_5 = iVar8;

  iVar8 = FUN_006759b0(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),&param_5);

  FUN_0043fe60();

  *(int *)(iVar2 + 4) = iVar8;

  **(int **)(iVar8 + 4) = iVar8;

  ExceptionList = local_c;

  return 0;

}
