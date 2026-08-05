// =============================================================================
// FUN_005effa0
// -----------------------------------------------------------------------------
// Stable ID: aa_005effa0
// Address:   0x005effa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005effa0 @ 0x005effa0
// Stable ID: aa_005effa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×2.
//  - Notable callees: FUN_005b3300, FUN_005efe50, FUN_005effa0, FUN_006ba870.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_005effa0(uint32_t /* width from decompiler */ *param_1,int param_2,uint param_3,float param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int local_3c;

  uint local_38;

  uint local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint local_28;

  int local_24;

  uint local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint local_4;

  

  if (0.0 < param_4) {

    local_3c = 0;

    local_38 = 0;

    local_34 = 0x80000000;

    if (0 < (int)param_3) {

      FUN_005b3300(&local_3c,((int)param_3 < 0) - 1 & param_3,0x10);

    }

    iVar2 = 0;

    local_38 = param_3;

    if (3 < (int)param_3) {

      iVar1 = 0;

      iVar3 = (param_3 - 4 >> 2) + 1;

      iVar2 = iVar3 * 4;

      do {

        *(uint32_t /* width from decompiler */ *)(iVar1 + local_3c) = *param_1;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + local_3c) = param_1[1];

        *(uint32_t /* width from decompiler */ *)(iVar1 + 8 + local_3c) = param_1[2];

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 + 8);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 * 2);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 * 2 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 * 2 + 8);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 * 3);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 * 3 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38 + local_3c) = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 * 3 + 8);

        param_1 = param_1 + param_2;

        iVar1 = iVar1 + 0x40;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

    if (iVar2 < (int)param_3) {

      iVar1 = iVar2 << 4;

      iVar2 = param_3 - iVar2;

      do {

        *(uint32_t /* width from decompiler */ *)(iVar1 + local_3c) = *param_1;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + local_3c) = param_1[1];

        *(uint32_t /* width from decompiler */ *)(iVar1 + 8 + local_3c) = param_1[2];

        param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + param_2);

        iVar1 = iVar1 + 0x10;

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

    }

    local_24 = local_3c;

    local_1c = 0x10;

    local_20 = param_3;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0x80000000;

    local_c = 0;

    local_8 = 0;

    local_4 = 0x80000000;

    local_30 = 0;

    local_2c = 0;

    local_28 = 0x80000000;

    FUN_006ba870(&local_24,&local_18,&local_30);

    FUN_005efe50(&local_18,param_4,param_5);

    *(float *)(param_5 + 4) = param_4;

    if ((local_28 & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_30,local_28 << 4,0x12);

    }

    if ((local_4 & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_c,(local_4 & 0x7fffffff) * 0xc,0x12);

    }

    if ((local_10 & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_18,local_10 << 4,0x12);

    }

    if ((local_34 & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_3c,local_34 << 4,0x12);

    }

    return 0;

  }

  return 1;

}
