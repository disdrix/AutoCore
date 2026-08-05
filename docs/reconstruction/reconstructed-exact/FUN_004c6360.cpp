// =============================================================================
// FUN_004c6360
// -----------------------------------------------------------------------------
// Stable ID: aa_004c6360
// Address:   0x004c6360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c6360 @ 0x004c6360
// Stable ID: aa_004c6360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: ABS×4, CONCAT31, FUN_004c6360, FUN_005172d0, FUN_0053d970, FUN_0053e0b0, FUN_0053eec0, FUN_005d6870.
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

void __thiscall FUN_004c6360(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  float *pfVar3;

  char *pcVar4;

  int iVar5;

  float fVar6;

  uint8_t uStack_76;

  uint8_t local_75;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20 [28];

  

  uVar2 = CVOGReaction_ResolveObjectTarget

                    (CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_2 + 100) >> 8),

                              *(uint8_t *)(param_2 + 0x68)),*(uint32_t /* width from decompiler */ *)(param_2 + 0x60),

                     *(uint32_t /* width from decompiler */ *)(param_2 + 100));

  FUN_005172d0(uVar2);

  local_40 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x40);

  local_60 = *(float *)(param_2 + 0x18);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x54);

  local_3c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x44);

  local_38 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x48);

  local_30 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

  local_5c = *(float *)(param_2 + 0x1c);

  local_2c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

  local_58 = *(float *)(param_2 + 0x20);

  local_28 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c);

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x58);

  local_54 = 0.0;

  local_34 = 0;

  local_24 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x240) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x244) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x248) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24c) = 0;

  FUN_00797170(local_20);

  pfVar3 = (float *)FUN_0053e0b0();

  local_50 = ABS(local_60 - *pfVar3);

  local_4c = ABS(local_5c - pfVar3[1]);

  local_48 = ABS(local_58 - pfVar3[2]);

  local_44 = ABS(local_54 - pfVar3[3]);

  if ((g_flMsToSeconds_Inferred < local_48 || g_flMsToSeconds_Inferred < local_4c) ||

      g_flMsToSeconds_Inferred < local_50) {

    *(uint8_t *)(param_1 + 0x279) = 0;

  }

  if (*(int *)(param_1 + 8) == 0) {

    pfVar3 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  }

  else {

    pfVar3 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);

  }

  local_70 = *pfVar3;

  local_6c = pfVar3[1];

  local_68 = pfVar3[2];

  local_64 = pfVar3[3];

  pcVar4 = (char *)FUN_005d6870(&local_75);

  if (*pcVar4 == '\0') {

    local_64 = 0.0;

    local_68 = 0.0;

    local_6c = 0.0;

    local_70 = 0.0;

  }

  local_64 = local_64 - local_54;

  local_70 = local_70 - local_60;

  local_6c = local_6c - local_5c;

  local_68 = local_68 - local_58;

  local_74 = SQRT(local_70 * local_70 + local_6c * local_6c + local_68 * local_68);

  if (((g_flOne < local_74) && (*(int *)(param_1 + 8) != 0)) &&

     (iVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x3c) + 0x18))(), iVar5 == 6)) {

    if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                0x4e0) != 1) {

      FUN_0053d970(0);

    }

    local_75 = 1;

    uStack_76 = 0;

    CVOGSpawnPoint_SetObjectActiveState

              (*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1,&local_75,&uStack_76);

  }

  fVar6 = (float)g_nInferredThreatDefault;

  if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x38) == 0x14) {

    fVar6 = DAT_00aaa688;

  }

  if (fVar6 < local_74) {

    *(uint8_t *)(param_1 + 0x314) = 1;

  }

  iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

  fVar6 = DAT_009cb8b8;

  if (*(int *)(iVar5 + 0x38) != 0x14) {

    fVar6 = DAT_00a0f70c;

  }

  if (((*(int *)(*(int *)(iVar5 + 0x3c) + 0x4e0) != 1) && (fVar6 < local_74)) &&

     (*(char *)(param_1 + 0x305) == '\0')) {

    *(uint8_t *)(param_1 + 0x304) = 1;

  }

  FUN_0053eec0(&local_60,local_20,&local_30,&local_40,param_3);

  return;

}
