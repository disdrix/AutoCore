// =============================================================================
// FUN_009192b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009192b0
// Address:   0x009192b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009192b0 @ 0x009192b0
// Stable ID: aa_009192b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: SQRT×6, Client_GetMissionCompleteAudioTable×3, FUN_004e8a40×2, FUN_00404a20, FUN_00404c90, FUN_0040c320, FUN_0040c380, FUN_0040cf70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_009192b0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  float fVar4;

  float fVar5;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  float local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  if (((DAT_00d1b226 != '\0') || (DAT_00d1b227 != '\0')) && (DAT_00d1b6d8 != 0)) {

    local_20 = DAT_00d1a640;

    local_1c = DAT_00d1a644;

    local_18 = DAT_00d1a648;

    if ((*(int *)(param_1 + 0x60c) == 4) || (*(int *)(param_1 + 0xcc4) == 8)) {

      local_40 = *(float *)(DAT_00d17944 + 0x21c);

      local_38 = *(float *)(DAT_00d17944 + 0x224);

      fVar4 = local_38 * local_38 + local_40 * local_40;

      if (_DAT_00a158d0 < SQRT(fVar4)) {

        if (fVar4 == 0.0) {

          fVar4 = 0.0;

        }

        else {

          fVar4 = g_flOne / SQRT(fVar4);

        }

        local_40 = fVar4 * local_40;

        local_3c = fVar4 * 0.0;

        local_38 = local_38 * fVar4;

      }

      else {

        local_40 = DAT_00afda60;

        local_3c = DAT_00afda64;

        local_38 = DAT_00afda68;

      }

      local_2c = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x22c);

      local_28 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x230);

      local_30 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x228);

      local_24 = 0;

    }

    else {

      iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x19c))();

      if (iVar1 == 0) {

        puVar2 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8)

                             + 0x1a0))();

        local_30 = *puVar2;

        local_2c = puVar2[1];

        local_28 = puVar2[2];

        local_24 = puVar2[3];

        uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                            0x1a4))(&fStack_50);

        FUN_004e8a40(uVar3);

        fVar4 = fStack_48 * fStack_48 + fStack_4c * fStack_4c + fStack_50 * fStack_50;

        if (fVar4 == 0.0) {

          fVar4 = 0.0;

        }

        else {

          fVar4 = g_flOne / SQRT(fVar4);

        }

        fStack_50 = fVar4 * fStack_50;

        fStack_4c = fStack_4c * fVar4;

        fStack_48 = fStack_48 * fVar4;

        fStack_44 = fStack_44 * fVar4;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

        local_30 = *puVar2;

        local_2c = puVar2[1];

        local_28 = puVar2[2];

        local_24 = puVar2[3];

        uVar3 = FUN_00404a20(&fStack_50);

        FUN_004e8a40(uVar3);

        fVar5 = fStack_48 * fStack_48 + fStack_4c * fStack_4c + fStack_50 * fStack_50;

        fVar4 = 0.0;

        if (fVar5 != 0.0) {

          fVar4 = g_flOne / SQRT(fVar5);

        }

        fStack_48 = fStack_48 * fVar4;

        fStack_50 = fVar4 * fStack_50;

        fStack_4c = fStack_4c * fVar4;

        fStack_44 = fStack_44 * fVar4;

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_0040cf70();

        local_20 = *puVar2;

        local_1c = puVar2[1];

        local_18 = puVar2[2];

      }

      local_40 = fStack_50;

      local_3c = fStack_4c;

      local_38 = fStack_48;

      if (DAT_00d1a8fc == '\0') {

        local_40 = *(float *)(DAT_00d17944 + 0x21c);

        local_38 = *(float *)(DAT_00d17944 + 0x224);

        fVar4 = local_38 * local_38 + local_40 * local_40;

        if (_DAT_00a158d0 < SQRT(fVar4)) {

          if (fVar4 == 0.0) {

            fVar4 = 0.0;

          }

          else {

            fVar4 = g_flOne / SQRT(fVar4);

          }

          local_40 = fVar4 * local_40;

          local_3c = fVar4 * 0.0;

          local_38 = local_38 * fVar4;

        }

        else {

          local_40 = DAT_00afda60;

          local_3c = DAT_00afda64;

          local_38 = DAT_00afda68;

        }

      }

    }

    Client_GetMissionCompleteAudioTable();

    FUN_0040c320();

    iVar1 = Client_GetMissionCompleteAudioTable();

    *(float *)(iVar1 + 0x230) = local_40;

    *(float *)(iVar1 + 0x234) = local_3c;

    *(float *)(iVar1 + 0x238) = local_38;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x23c) = 0;

    iVar1 = Client_GetMissionCompleteAudioTable();

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x240) = local_20;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x244) = local_1c;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x248) = local_18;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24c) = 0;

    FUN_00720d40();

    FUN_0040c380();

  }

  return;

}
