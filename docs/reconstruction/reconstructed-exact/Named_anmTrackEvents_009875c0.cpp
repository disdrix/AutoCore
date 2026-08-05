// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, while×1.
//  - Notable callees: stoChunkWriter_EndChunk×2, FUN_00436f80, FUN_00439810, FUN_004398d0, FUN_00767160, FUN_009875c0, stoChunkWriter_BeginChunk, vog_LogMessage.
//  - Strings: "anmTrackEvents: Error Writing Track Id!"; "anmTrackEvents: Error Writing Param Id!"; "anmTrackEvents: Error Writing event count!"; "anmTrackEvents: Error Writing event!".
//  - Return sites: 2.

// =============================================================================
// Named_anmTrackEvents_009875c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009875c0
// Address:   0x009875c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmTrackEvents"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_anmTrackEvents_009875c0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  undefined *puVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad7b0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x54455654,1);

  uVar5 = 0;

  local_4 = 0;

  puVar2 = *(undefined **)(param_1 + 4);

  if (*(undefined **)(param_1 + 4) == (undefined *)0x0) {

    puVar2 = PTR_DAT_00afa2bc;

  }

  if (param_2[7] == 0) {

    uVar3 = FUN_00436f80(param_2,puVar2);

    param_2[1] = param_2[1] | uVar3;

  }

  else {

    uVar3 = FUN_00767160(&DAT_00a9d6f8,puVar2);

    param_2[1] = param_2[1] | uVar3;

    uVar3 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

    param_2[8] = 0;

    param_2[1] = uVar3 | param_2[1];

  }

  uVar3 = param_2[1];

  if ((int)uVar3 < 0) {

    pcVar7 = "anmTrackEvents: Error Writing Track Id!";

    uVar6 = 0x94;

  }

  else {

    uVar4 = FUN_004398d0();

    uVar3 = uVar3 | uVar4;

    if ((int)uVar3 < 0) {

      pcVar7 = "anmTrackEvents: Error Writing Param Id!";

      uVar6 = 0x97;

    }

    else {

      uVar4 = FUN_00439810();

      uVar3 = uVar3 | uVar4;

      if ((int)uVar3 < 0) {

        pcVar7 = "anmTrackEvents: Error Writing event count!";

        uVar6 = 0x9a;

      }

      else {

        while( true ) {

          iVar1 = *(int *)(param_1 + 0x10);

          if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x14) - iVar1 >> 2) <= uVar5)) {

            local_4 = 0xffffffff;

            stoChunkWriter_EndChunk();

            ExceptionList = local_c;

            return uVar3;

          }

          uVar4 = (**(code **)(**(int **)(iVar1 + uVar5 * 4) + 0x10))(param_2);

          uVar3 = uVar3 | uVar4;

          if ((int)uVar3 < 0) break;

          uVar5 = uVar5 + 1;

        }

        pcVar7 = "anmTrackEvents: Error Writing event!";

        uVar6 = 0xa0;

      }

    }

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmTrackEvents.cpp",uVar6,3,pcVar7

                );

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return 0xffffffff;

}
