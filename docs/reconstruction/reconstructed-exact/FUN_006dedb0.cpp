// =============================================================================
// FUN_006dedb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006dedb0
// Address:   0x006dedb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006dedb0 @ 0x006dedb0
// Stable ID: aa_006dedb0
// Embedded strings (evidence for future rename):
//   - "TtCapsCaps"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006dedb0, FUN_006f6ef0.
//  - Strings: "TtCapsCaps".
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

void FUN_006dedb0(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint64_t uVar7;

  float local_a0;

  float local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  float local_90;

  float local_8c;

  float local_88;

  uint32_t /* width from decompiler */ local_84;

  float local_80;

  float local_7c;

  float local_78;

  uint32_t /* width from decompiler */ local_74;

  float local_70;

  float local_6c;

  float local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  float local_4c;

  float local_48;

  uint32_t /* width from decompiler */ local_44;

  uint8_t local_40 [32];

  float local_20;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtCapsCaps";

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar4 = *param_1;

  fVar1 = *(float *)(iVar4 + 0x10);

  iVar5 = param_1[2];

  fVar2 = *(float *)(iVar4 + 0x14);

  fVar3 = *(float *)(iVar4 + 0x18);

  iVar6 = *param_2;

  local_a0 = fVar2 * *(float *)(iVar5 + 0x30) +

             fVar3 * *(float *)(iVar5 + 0x40) + fVar1 * *(float *)(iVar5 + 0x20) +

             *(float *)(iVar5 + 0x50);

  local_9c = fVar2 * *(float *)(iVar5 + 0x34) +

             fVar3 * *(float *)(iVar5 + 0x44) + fVar1 * *(float *)(iVar5 + 0x24) +

             *(float *)(iVar5 + 0x54);

  local_98 = fVar2 * *(float *)(iVar5 + 0x38) +

             fVar3 * *(float *)(iVar5 + 0x48) + fVar1 * *(float *)(iVar5 + 0x28) +

             *(float *)(iVar5 + 0x58);

  local_94 = 0;

  fVar1 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_90 = fVar2 * *(float *)(iVar5 + 0x30) +

             fVar3 * *(float *)(iVar5 + 0x40) + fVar1 * *(float *)(iVar5 + 0x20) +

             *(float *)(iVar5 + 0x50);

  local_8c = fVar2 * *(float *)(iVar5 + 0x34) +

             fVar3 * *(float *)(iVar5 + 0x44) + fVar1 * *(float *)(iVar5 + 0x24) +

             *(float *)(iVar5 + 0x54);

  local_88 = fVar2 * *(float *)(iVar5 + 0x38) +

             fVar3 * *(float *)(iVar5 + 0x48) + fVar1 * *(float *)(iVar5 + 0x28) +

             *(float *)(iVar5 + 0x58);

  iVar5 = param_2[2];

  local_84 = 0;

  fVar1 = *(float *)(iVar6 + 0x10);

  fVar2 = *(float *)(iVar6 + 0x14);

  fVar3 = *(float *)(iVar6 + 0x18);

  local_80 = fVar2 * *(float *)(iVar5 + 0x30) +

             fVar3 * *(float *)(iVar5 + 0x40) + fVar1 * *(float *)(iVar5 + 0x20) +

             *(float *)(iVar5 + 0x50);

  local_7c = fVar2 * *(float *)(iVar5 + 0x34) +

             fVar3 * *(float *)(iVar5 + 0x44) + fVar1 * *(float *)(iVar5 + 0x24) +

             *(float *)(iVar5 + 0x54);

  local_78 = fVar2 * *(float *)(iVar5 + 0x38) +

             fVar3 * *(float *)(iVar5 + 0x48) + fVar1 * *(float *)(iVar5 + 0x28) +

             *(float *)(iVar5 + 0x58);

  local_74 = 0;

  fVar1 = *(float *)(iVar6 + 0x20);

  fVar2 = *(float *)(iVar6 + 0x24);

  fVar3 = *(float *)(iVar6 + 0x28);

  local_70 = fVar2 * *(float *)(iVar5 + 0x30) +

             fVar3 * *(float *)(iVar5 + 0x40) + fVar1 * *(float *)(iVar5 + 0x20) +

             *(float *)(iVar5 + 0x50);

  local_6c = fVar2 * *(float *)(iVar5 + 0x34) +

             fVar3 * *(float *)(iVar5 + 0x44) + fVar1 * *(float *)(iVar5 + 0x24) +

             *(float *)(iVar5 + 0x54);

  local_68 = fVar2 * *(float *)(iVar5 + 0x38) +

             fVar3 * *(float *)(iVar5 + 0x48) + fVar1 * *(float *)(iVar5 + 0x28) +

             *(float *)(iVar5 + 0x58);

  local_64 = 0;

  local_44 = 0;

  local_54 = 0;

  local_50 = local_90 - local_a0;

  local_4c = local_8c - local_9c;

  local_48 = local_88 - local_98;

  local_60 = local_70 - local_80;

  local_5c = local_6c - local_7c;

  local_58 = local_68 - local_78;

  FUN_006f6ef0(&local_a0,&local_50,&local_80,&local_60,local_40);

  fVar1 = *(float *)(iVar6 + 0xc) + *(float *)(iVar4 + 0xc);

  if (local_20 < fVar1 * fVar1) {

    (**(code **)(*param_4 + 4))(param_1,param_2);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
