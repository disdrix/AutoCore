// =============================================================================
// FUN_006c8e10
// -----------------------------------------------------------------------------
// Stable ID: aa_006c8e10
// Address:   0x006c8e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c8e10 @ 0x006c8e10
// Stable ID: aa_006c8e10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006c8e10, FUN_006eefc0.
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

void __thiscall FUN_006c8e10(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  uint uVar8;

  uint local_3c;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  uVar3 = param_4 + 3U & 0xfffffffc;

  piVar1 = (int *)(param_1 + 0x30);

  *(int *)(param_1 + 0xd0) = param_4;

  iVar4 = (int)(uVar3 + ((int)(param_4 + 3U) >> 0x1f & 3U)) >> 2;

  uVar7 = *(uint *)(param_1 + 0x38) & 0x7fffffff;

  if ((int)uVar7 < iVar4) {

    iVar2 = uVar7 * 2;

    iVar5 = iVar4;

    if (iVar4 < iVar2) {

      iVar5 = iVar2;

    }

    FUN_005b3300(piVar1,iVar5,0x30);

  }

  uVar7 = 0;

  *(int *)(param_1 + 0x34) = iVar4;

  puVar6 = param_2;

  if (3 < param_4) {

    local_3c = 1;

    do {

      uVar8 = uVar7 >> 2;

      *(uint32_t /* width from decompiler */ *)(*piVar1 + uVar8 * 0x30) = *puVar6;

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x10 + uVar8 * 0x30) = puVar6[1];

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x20 + uVar8 * 0x30) = puVar6[2];

      iVar4 = (local_3c & 3) + (local_3c >> 2) * 0xc;

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x10 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 + 4);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x20 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 + 8);

      iVar4 = (local_3c + 1 & 3) + (local_3c + 1 >> 2) * 0xc;

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 * 2);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x10 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 * 2 + 4);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x20 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 * 2 + 8);

      iVar4 = (local_3c - 2 & 3) + (local_3c + 2 >> 2) * 0xc;

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 * 3);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x10 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 * 3 + 4);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x20 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar6 + param_3 * 3 + 8);

      local_3c = local_3c + 4;

      uVar7 = uVar7 + 4;

      puVar6 = puVar6 + param_3;

    } while ((int)uVar7 < param_4 + -3);

  }

  for (; (int)uVar7 < param_4; uVar7 = uVar7 + 1) {

    iVar4 = (uVar7 & 3) + (uVar7 >> 2) * 0xc;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = *puVar6;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x10 + iVar4 * 4) = puVar6[1];

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x20 + iVar4 * 4) = puVar6[2];

    puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + param_3);

  }

  puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 - param_3);

  for (; (int)uVar7 < (int)uVar3; uVar7 = uVar7 + 1) {

    iVar4 = (uVar7 & 3) + ((int)uVar7 >> 2) * 0xc;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = *puVar6;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x10 + iVar4 * 4) = puVar6[1];

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x20 + iVar4 * 4) = puVar6[2];

  }

  FUN_006eefc0(param_2,param_4,param_3,&local_30);

  *(float *)(param_1 + 0x20) = local_20 + local_30;

  *(float *)(param_1 + 0x24) = local_1c + local_2c;

  *(float *)(param_1 + 0x28) = local_18 + local_28;

  *(float *)(param_1 + 0x2c) = local_14 + local_24;

  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) * DAT_00a0f298;

  *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) * DAT_00a0f298;

  *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x28) * DAT_00a0f298;

  *(float *)(param_1 + 0x2c) = *(float *)(param_1 + 0x2c) * DAT_00a0f298;

  *(float *)(param_1 + 0x10) = local_20 - local_30;

  *(float *)(param_1 + 0x14) = local_1c - local_2c;

  *(float *)(param_1 + 0x18) = local_18 - local_28;

  *(float *)(param_1 + 0x1c) = local_14 - local_24;

  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) * DAT_00a0f298;

  *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x14) * DAT_00a0f298;

  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) * DAT_00a0f298;

  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) * DAT_00a0f298;

  return;

}
