// =============================================================================
// FUN_006ec970
// -----------------------------------------------------------------------------
// Stable ID: aa_006ec970
// Address:   0x006ec970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ec970 @ 0x006ec970
// Stable ID: aa_006ec970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005ffdb0, FUN_006c7fa0, FUN_006e8880, FUN_006ec970.
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

void __thiscall

FUN_006ec970(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  undefined **local_a0;

  uint local_9c;

  float local_94;

  undefined ***local_90;

  int local_8c;

  uint8_t *local_88;

  int *local_84;

  float local_80;

  float local_7c;

  uint8_t local_70 [32];

  float local_50;

  float local_4c;

  float local_48;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar4 = *param_2;

  FUN_006e8880(param_2[2]);

  FUN_006c7fa0(0);

  iVar5 = *(int *)(param_1 + 0xc);

  iVar7 = *(int *)(param_1 + 0x10) + -1;

  local_88 = local_70;

  local_84 = param_2;

  if (-1 < iVar7) {

    pfVar6 = (float *)(iVar7 * 0x10 + 0x18 + iVar4);

    do {

      fVar1 = pfVar6[-2];

      iVar4 = param_2[2];

      fVar2 = pfVar6[-1];

      fVar3 = *pfVar6;

      local_80 = local_50 * fVar1 + local_40 * fVar2 + local_30 * fVar3;

      local_7c = local_4c * fVar1 + local_3c * fVar2 + local_2c * fVar3;

      local_20 = local_80 + *(float *)(iVar4 + 0x50);

      local_1c = local_7c + *(float *)(iVar4 + 0x54);

      local_18 = local_48 * fVar1 + local_38 * fVar2 + local_28 * fVar3 + *(float *)(iVar4 + 0x58);

      local_14 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5c);

      local_94 = pfVar6[1];

      local_90 = &local_a0;

      local_8c = iVar7;

      (**(code **)(**(int **)(iVar5 + 4) + 0xc))(&local_90,param_3,param_4,param_5,param_6);

      iVar7 = iVar7 + -1;

      pfVar6 = pfVar6 + -4;

    } while (-1 < iVar7);

  }

  local_a0 = &PTR_FUN_009d81e8;

  if ((char)(local_9c >> 8) < '\0') {

    local_9c = local_9c & 0xffff7fff;

    FUN_005ffdb0(0);

  }

  return;

}
