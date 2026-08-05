// =============================================================================
// FUN_00711f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00711f10
// Address:   0x00711f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711f10 @ 0x00711f10
// Stable ID: aa_00711f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×12, do×2, while×2, return×1.
//  - Notable callees: CONCAT22×2, FUN_00711f10, FUN_00715ac0, FUN_00715b70, FUN_00715f30, FUN_00716180, ROUND, f2xm1.
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



void FUN_00711f10(int param_1,short *param_2,uint16_t *param_3,uint32_t /* width from decompiler */ param_4,

                 uint16_t param_5,uint16_t *param_6,uint8_t *param_7,uint32_t /* width from decompiler */ param_8,

                 uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ *param_10)



{

  float fVar1;

  short sVar2;

  int iVar3;

  uint16_t extraout_var;

  int iVar4;

  float10 fVar5;

  float10 fVar6;

  float local_b8;

  uint8_t local_b1;

  float local_b0;

  int local_ac;

  int local_a8;

  int local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  uint32_t /* width from decompiler */ local_90;

  uint8_t local_8c [48];

  uint32_t /* width from decompiler */ local_5c;

  uint16_t local_58;

  uint16_t *local_54;

  uint8_t *local_50;

  uint local_44 [3];

  uint8_t local_38 [56];

  

  local_a8 = *(int *)(param_1 + 4);

  local_ac = CONCAT22(local_ac._2_2_,*param_6);

  local_a4 = 0;

  local_58 = param_5;

  local_54 = param_6;

  local_b1 = *param_7;

  local_50 = param_7;

  local_5c = param_4;

  iVar3 = 0;

  do {

    FUN_00716180(&local_5c,&local_b8,*(uint32_t /* width from decompiler */ *)((int)&DAT_00a0f650 + iVar3));

    iVar4 = iVar3 + 4;

    *(uint *)((int)local_44 + iVar3) = (uint)local_b8 & 0xff;

    iVar3 = iVar4;

  } while (iVar4 < 0x44);

  local_b8 = *(float *)(param_1 + 0x68);

  local_b0 = *(float *)(param_1 + 100);

  iVar3 = local_44[1] - (local_44[1] & 8);

  if (7 < iVar3) {

    iVar3 = 0;

  }

  local_94 = (float)(&DAT_00a0f530)[iVar3];

  local_9c = local_94;

  if ((local_44[1] & 8) == 0) {

    local_9c = local_b8;

  }

  fVar6 = (float10)1.4426950408889634 *

          ((float10)_DAT_00a0f6a8 - (float10)(int)local_44[2] * (float10)_DAT_00a0f6ac);

  fVar5 = ROUND(fVar6);

  fVar6 = (float10)f2xm1(fVar6 - fVar5);

  fVar5 = (float10)fscale((float10)1 + fVar6,fVar5);

  local_98 = (float)((float10)_DAT_00a0f528 /

                    (((float10)_DAT_00a0f528 / fVar5) * (float10)*(float *)(param_1 + 0x34) *

                     (float10)*(float *)(param_1 + 0x24) + (float10)*(float *)(param_1 + 0x28)));

  if (DAT_00a0f6a4 <= local_98) {

    if (_DAT_00a0f6a0 < local_98) {

      local_98 = 160.0;

    }

  }

  else {

    local_98 = 8.0;

  }

  if ((local_b0 * _DAT_00a0f69c < local_98) || (local_98 < local_b0 * DAT_00a0f698)) {

    fVar1 = local_94;

    local_a0 = local_98;

    if (local_94 < local_b8) {

      fVar1 = local_b8;

      local_a0 = local_b0;

    }

    if (((local_a0 < DAT_00a0f694) && (fVar1 * local_a0 * DAT_00a0f298 < g_flOne)) &&

       (local_a0 = local_b0, local_b0 < local_98)) {

      local_a0 = local_98;

    }

  }

  else {

    local_a0 = (local_98 + local_b0) * DAT_00a0f298;

  }

  if (0x3f < (int)local_44[0]) {

    local_44[0] = 0;

  }

  local_90 = (&DAT_00a0f550)[local_44[0]];

  FUN_00715f30(local_38,local_8c,0xc,local_94,local_a8);

  local_94 = local_94 * *(float *)(param_1 + 0x38);

  if (*(short *)(param_1 + 0x54) == 1) {

    FUN_00715b70(local_8c,local_90,*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),

                 *(uint16_t *)(param_1 + 0x30),

                 CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0x32)),param_8,param_9);

  }

  FUN_00715ac0(param_1,&local_a0,param_2,&local_a4);

  iVar3 = local_a4;

  *param_3 = 0x50;

  *param_10 = local_90;

  if (*(short *)(param_1 + 0x54) == 0) {

    *(uint16_t *)(param_1 + 0x54) = 1;

    (*(code *)PTR_memcpy_00af8a54)(param_1 + 100,&local_98,8);

  }

  else {

    *(uint16_t *)(param_1 + 0x54) = 0;

    *param_6 = (uint16_t)local_ac;

    *param_7 = local_b1;

    if (*(short *)(param_1 + 0x56) == 1) {

      *(uint16_t *)(param_1 + 0x56) = 0;

      local_b8 = 0.0;

      if (0 < local_a4) {

        do {

          fVar1 = local_b8;

          local_ac = (int)*param_2;

          sVar2 = ftol();

          *param_2 = sVar2;

          local_b8 = (float)((int)fVar1 + 1);

          param_2 = param_2 + 1;

        } while ((int)local_b8 < iVar3);

      }

    }

  }

  iVar3 = local_a8;

  (*(code *)PTR_memcpy_00af8a54)(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),local_a8 + 0x808,0x104);

  (*(code *)PTR_memcpy_00af8a54)(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),iVar3 + 0x90c,0x104);

  return;

}
