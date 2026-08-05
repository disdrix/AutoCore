// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: for×10, if×7, return×2.
//  - Notable callees: FUN_00679120, FUN_0076cec0, d, vog_LogMessage.
//  - Strings: "nothing"; "priority needed"; "invalid param"; "invalid call".
//  - Return sites: 2.

// =============================================================================
// Named_AudioOutStream_00679120
// -----------------------------------------------------------------------------
// Stable ID: aa_00679120
// Address:   0x00679120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioOutStream"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_AudioOutStream_00679120(int *param_1)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  uint8_t *puVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ uStack_24;

  int iStack_20;

  int iStack_1c;

  uint8_t auStack_10 [4];

  uint32_t /* width from decompiler */ auStack_c [2];

  uint32_t /* width from decompiler */ uStack_4;

  

  iStack_1c = param_1[2];

  iStack_20 = param_1[0xc];

  uStack_24 = 0x679137;

  (**(code **)(*(int *)param_1[0x1b] + 0x10))();

  uStack_24 = 0;

  uVar1 = param_1[2];

  iVar2 = (**(code **)(*(int *)param_1[4] + 0x2c))((int *)param_1[4],uStack_4);

  if (-1 < iVar2) {

    uVar4 = param_1[2];

    if ((int)uVar1 < (int)uVar4) {

      puVar9 = (uint32_t /* width from decompiler */ *)param_1[0xc];

      puVar8 = (uint32_t /* width from decompiler */ *)&stack0xffffffe8;

      for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar8 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar8 = puVar8 + 1;

      }

      for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar8 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      }

      puVar9 = (uint32_t /* width from decompiler */ *)(param_1[0xc] + uVar1);

      puVar8 = auStack_c;

      for (uVar4 = (uint)auStack_10 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar8 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar8 = puVar8 + 1;

      }

      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {

        *(uint8_t *)puVar8 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      }

      puVar9 = (uint32_t /* width from decompiler */ *)param_1[0xc];

      puVar8 = (uint32_t /* width from decompiler */ *)((uint)param_1[6] % (uint)param_1[7] + *param_1);

      for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar8 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar8 = puVar8 + 1;

      }

      for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar8 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      }

      puVar8 = (uint32_t /* width from decompiler */ *)(param_1[0xc] + uVar1);

      puVar9 = (uint32_t /* width from decompiler */ *)*param_1;

      puVar6 = auStack_10;

    }

    else {

      puVar9 = (uint32_t /* width from decompiler */ *)param_1[0xc];

      puVar8 = (uint32_t /* width from decompiler */ *)&stack0xffffffe8;

      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar8 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar8 = puVar8 + 1;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar8 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      }

      puVar6 = (uint8_t *)param_1[2];

      puVar8 = (uint32_t /* width from decompiler */ *)param_1[0xc];

      puVar9 = (uint32_t /* width from decompiler */ *)((uint)param_1[6] % (uint)param_1[7] + *param_1);

    }

    for (uVar4 = (uint)puVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar9 = *puVar8;

      puVar8 = puVar8 + 1;

      puVar9 = puVar9 + 1;

    }

    for (uVar4 = (uint)puVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar9 = *(uint8_t *)puVar8;

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    }

    (**(code **)(*(int *)param_1[4] + 0x4c))

              ((int *)param_1[4],&stack0xffffffe8,uVar1,auStack_c,auStack_10);

    return 0;

  }

  pcVar7 = "nothing";

  if (iVar2 < -0x7787ffb9) {

    if (iVar2 == -0x7787ffba) {

      pcVar7 = "priority needed";

    }

    else if (iVar2 == -0x7ff8ffa9) {

      pcVar7 = "invalid param";

    }

    else if (iVar2 == -0x7787ffce) {

      pcVar7 = "invalid call";

    }

  }

  else if (iVar2 == -0x7787ff6a) {

    pcVar7 = "buffer lost";

  }

  uVar3 = FUN_0076cec0(&uStack_24,

                       "Failed to lock silence buffer size: %d offset: %d length: %d (%s)",

                       param_1[7],uStack_4,param_1[2],pcVar7);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutStream.cpp"

                 ,0x22b,2,uVar3);

  return 0;

}
