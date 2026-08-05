// =============================================================================
// FUN_0053e820
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e820
// Address:   0x0053e820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053e820 @ 0x0053e820
// Stable ID: aa_0053e820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×10, return×4.
//  - Notable callees: FUN_00404a20×2, FUN_004e8a40×2, FUN_004e8ad0×2, ABS, CVOGReaction_RandomUnitScalar, FUN_00404c90, FUN_0053dee0, FUN_0053e820.
//  - Return sites: 4.

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



uint8_t __fastcall FUN_0053e820(int param_1)



{

  ushort uVar1;

  float *pfVar2;

  void *this;

  float fVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  if (*(int *)(param_1 + 8) == 0) {

    return 1;

  }

  if (*(int *)(param_1 + 0x2c) != 0) {

    if (*(int *)(param_1 + 0x30) != 0) {

      iVar6 = g_dwClientTickMs - *(int *)(param_1 + 0x30);

      fVar3 = (float)iVar6;

      if (iVar6 < 0) {

        fVar3 = fVar3 + _DAT_00aaa5dc;

      }

      fVar3 = fVar3 * g_flMsToSeconds_Inferred;

      iVar6 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar6 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

      if (fVar3 < (float)uVar1 * _DAT_009d00a4 + DAT_00aaa8dc) {

        pfVar2 = *(float **)(param_1 + 0x2c);

        local_60 = *pfVar2 + pfVar2[8] * fVar3;

        local_5c = pfVar2[1] + pfVar2[9] * fVar3;

        local_58 = pfVar2[2] + pfVar2[10] * fVar3;

        local_54 = pfVar2[3] + pfVar2[0xb] * fVar3;

        local_50 = local_60;

        local_4c = local_5c;

        local_48 = local_58;

        local_44 = local_54;

        pfVar4 = (float *)FUN_00404c90();

        local_60 = local_50 - *pfVar4;

        local_5c = local_4c - pfVar4[1];

        local_58 = local_48 - pfVar4[2];

        local_54 = local_44 - pfVar4[3];

        if ((SQRT(local_60 * local_60 + local_58 * local_58) <= _DAT_00af2444) &&

           (ABS(local_5c) <= _DAT_00af2440)) {

          local_30 = pfVar2[0xc] * DAT_00a0f298;

          local_2c = pfVar2[0xd] * DAT_00a0f298;

          local_28 = pfVar2[0xe] * DAT_00a0f298;

          local_24 = 0;

          FUN_0053fae0(&local_30,pfVar2 + 4);

          local_50 = local_20 * fVar3 + pfVar2[4];

          local_4c = local_1c * fVar3 + pfVar2[5];

          local_48 = local_18 * fVar3 + pfVar2[6];

          local_44 = local_14 * fVar3 + pfVar2[7];

          FUN_0053fa40();

          FUN_004e8a40(&local_50,&local_60);

          uVar5 = FUN_00404a20(&local_40);

          FUN_004e8a40(uVar5);

          if (DAT_00a111a8 <= local_38 * local_58 + local_3c * local_5c + local_40 * local_60) {

            FUN_004e8ad0(&local_50,&local_60);

            uVar5 = FUN_00404a20(&local_40);

            FUN_004e8ad0(uVar5);

            if (DAT_00a111a8 <= local_38 * local_58 + local_3c * local_5c + local_40 * local_60) {

              return 0;

            }

          }

        }

      }

    }

    this = *(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x18 + param_1);

    if (this != (void *)0x0) {

      NetObject_SetMaskBits(this,2,0);

    }

    FUN_0053dee0();

    return 1;

  }

  return 0;

}
