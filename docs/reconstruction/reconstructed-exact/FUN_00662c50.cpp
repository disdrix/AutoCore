// =============================================================================
// FUN_00662c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00662c50
// Address:   0x00662c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00662c50 @ 0x00662c50
// Stable ID: aa_00662c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005d68f0×2, FUN_0063a190, FUN_00662140, FUN_00662230, FUN_00662280, FUN_00662510, FUN_00662c50, FUN_0066dd00.
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

void __thiscall FUN_00662c50(int param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iStack_114;

  int local_110;

  int local_10c;

  int local_108;

  uint32_t /* width from decompiler */ uStack_104;

  uint32_t /* width from decompiler */ uStack_100;

  uint32_t /* width from decompiler */ uStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  uint8_t auStack_f4 [16];

  uint8_t auStack_e4 [20];

  uint8_t local_d0 [48];

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94 [17];

  uint8_t local_50 [76];

  

  FUN_0066dd00(param_3);

  FUN_00662510(param_2,local_d0,local_50);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = local_a0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = local_9c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = local_98;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = local_94[0];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xbc);

  FUN_00662280(param_4);

  FUN_00662230(param_4);

  if (*(int *)(param_2 + 0x20) != 0) {

    FUN_0063a190(local_d0,param_2 + 0x70);

    if (*(int **)(param_2 + 0x20) != (int *)0x0) {

      local_110 = 0;

      local_10c = 0;

      local_108 = -0x80000000;

      (**(code **)(**(int **)(param_2 + 0x20) + 0x34))(&local_110);

      if (1 < local_110) {

        local_108 = local_110 + -1;

        iVar3 = 0x10;

        do {

          uStack_104 = *(uint32_t /* width from decompiler */ *)(iVar3 + iStack_114);

          uStack_100 = *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iStack_114);

          uStack_fc = *(uint32_t /* width from decompiler */ *)(iVar3 + 8 + iStack_114);

          uStack_f8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc + iStack_114);

          FUN_005d68f0(local_94,&uStack_104);

          uStack_104 = *(uint32_t /* width from decompiler */ *)(iVar3 + -0x10 + iStack_114);

          uStack_100 = *(uint32_t /* width from decompiler */ *)(iVar3 + -0xc + iStack_114);

          uStack_fc = *(uint32_t /* width from decompiler */ *)(iVar3 + -8 + iStack_114);

          uStack_f8 = *(uint32_t /* width from decompiler */ *)(iVar3 + -4 + iStack_114);

          FUN_005d68f0(local_94,&uStack_104);

          iVar1 = *param_3;

          uVar2 = FUN_00662140(0,0x3e800000,0x3f800000,0x3f800000,param_4);

          (**(code **)(iVar1 + 0x1c))(auStack_e4,auStack_f4,uVar2);

          iVar3 = iVar3 + 0x10;

          local_108 = local_108 + -1;

        } while (local_108 != 0);

      }

      if (-1 < local_10c) {

        (**(code **)(*DAT_00b05060 + 0x14))(iStack_114,local_10c << 4,0x12);

      }

    }

  }

  return;

}
