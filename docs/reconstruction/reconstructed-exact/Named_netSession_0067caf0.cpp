// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×12, goto×1, return×1.
//  - Notable callees: FUN_0076cec0×4, vog_LogMessage×4, FUN_0067c560×3, FUN_0067ffb0×2, FUN_0067bea0, FUN_0067c030, FUN_0067c430, FUN_0067caf0.
//  - Strings: "Session %lu: netSession outbound send queue exceeded!"; "Session %d: user attempted to send over internal channel 255".
//  - Return sites: 1.

// =============================================================================
// Named_netSession_0067caf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067caf0
// Address:   0x0067caf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netSession"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_netSession_0067caf0(int *param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *piStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a96d8;

  pvStack_c = ExceptionList;

  puVar7 = (uint32_t /* width from decompiler */ *)0x0;

  ExceptionList = &pvStack_c;

  piStack_10 = param_1;

  if (param_1[0xa8f] != 0) {

    ExceptionList = &pvStack_c;

    FUN_00684b00();

  }

  puVar3 = param_2;

  if (((char)param_1[1] == '\0') || (*(char *)((int)param_1 + 5) != '\0')) {

    uVar5 = FUN_0076cec0(&piStack_10,

                         "Session %d: User attempting to send over a session that is not open!",

                         param_1[0xa88]);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x15a,2,uVar5);

  }

  else {

    if ((uint)param_1[0xa87] < (uint)(param_1[0xa86] + param_2[3])) {

      cVar4 = (**(code **)(*param_1 + 0xc))();

      if ((cVar4 == '\0') || ((uint)param_1[0xa87] < (uint)(param_1[0xa86] + puVar3[3]))) {

        uVar5 = FUN_0076cec0(&param_3,"Session %lu: netSession outbound send queue exceeded!",

                             param_1[0xa88]);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x100,2,uVar5);

        FUN_0067c430();

        iVar1 = param_1[0xa8f];

        goto LAB_0067cd53;

      }

    }

    param_2 = operator_new(0x1c);

    uStack_4 = 0;

    if (param_2 != (void *)0x0) {

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00680c30();

    }

    uStack_4 = 0xffffffff;

    param_2 = puVar7;

    FUN_00680dd0(puVar3);

    uVar2 = puVar7[3];

    if (param_1[0xa8f] != 0) {

      FUN_0067c030(uVar2);

    }

    cVar4 = (char)param_3;

    if (cVar4 == '\0') {

      FUN_0067ffb0(&param_2);

      param_1[0xa86] = param_1[0xa86] + uVar2;

      FUN_0067c560(param_3);

    }

    else if (cVar4 == -2) {

      puVar7[5] = puVar7[5] + 1;

      FUN_0067ffb0(&param_2);

      FUN_0067c560(param_3);

    }

    else if (cVar4 == -1) {

      uVar5 = FUN_0076cec0(&param_3,"Session %d: user attempted to send over internal channel 255",

                           param_1[0xa88]);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x14b,3,uVar5);

      (**(code **)*puVar7)(1);

    }

    else if ((uint)param_1[0xa8b] < uVar2) {

      uVar5 = FUN_0076cec0(&param_3,

                           "Session %lu: Attempting to send an ephemeral packet that is too large!",

                           param_1[0xa88]);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x127,2,uVar5);

      (**(code **)*puVar7)(1);

    }

    else {

      uVar6 = param_3 & 0xff;

      if (param_1[uVar6 * 10 + 0x49] != 0) {

        param_1[0xa86] = param_1[0xa86] - *(int *)(param_1[uVar6 * 10 + 0x49] + 0xc);

        *(uint8_t *)(param_1 + uVar6 * 10 + 0x4b) = 0;

        FUN_0067bea0(param_1[uVar6 * 10 + 0x49]);

        *(uint8_t *)(param_1 + uVar6 * 10 + 0x4d) = 0;

      }

      puVar7[5] = puVar7[5] + 1;

      param_1[uVar6 * 10 + 0x4a] = param_1[uVar6 * 10 + 0x48];

      param_1[uVar6 * 10 + 0x49] = (int)puVar7;

      *(uint8_t *)(param_1 + uVar6 * 10 + 0x4b) = 0;

      param_1[uVar6 * 10 + 0x48] = param_1[uVar6 * 10 + 0x48] + 1;

      param_1[0xa86] = param_1[0xa86] + uVar2;

      FUN_0067c560(param_3);

    }

  }

  iVar1 = param_1[0xa8f];

LAB_0067cd53:

  if (iVar1 != 0) {

    FUN_00684b10();

  }

  ExceptionList = pvStack_c;

  return;

}
