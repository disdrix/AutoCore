// =============================================================================
// FUN_004db1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004db1d0
// Address:   0x004db1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004db1d0 @ 0x004db1d0
// Stable ID: aa_004db1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: CONCAT31, FUN_004b4d90, FUN_004db1d0, FUN_004e7540, FUN_00560ec0, FUN_005a5b30, FUN_005d4240, FUN_005e1c80.
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

void __fastcall FUN_004db1d0(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  float afStack_180 [6];

  uint32_t /* width from decompiler */ uStack_168;

  uint32_t /* width from decompiler */ uStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  float fStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  uint32_t /* width from decompiler */ uStack_150;

  uint32_t /* width from decompiler */ uStack_14c;

  uint32_t /* width from decompiler */ uStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  uint8_t local_140 [16];

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint32_t /* width from decompiler */ uStack_108;

  uint8_t auStack_100 [12];

  uint32_t /* width from decompiler */ uStack_f4;

  int iStack_ec;

  uint32_t /* width from decompiler */ uStack_e8;

  uint32_t /* width from decompiler */ uStack_e4;

  uint32_t /* width from decompiler */ uStack_e0;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  float fStack_60;

  uint8_t uStack_58;

  uint8_t auStack_40 [32];

  uint32_t /* width from decompiler */ uStack_20;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a22ec;

  local_1c = ExceptionList;

  if (*(int *)(param_1 + 0xe4f8) != 0) {

    uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe4f8) + 0x18);

    ExceptionList = &local_1c;

    local_110 = uVar3;

    FUN_006c7d30();

    local_120 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe4f8) + 0x10);

    local_11c = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe4f8) + 0x14);

    local_130 = local_110;

    local_12c = DAT_00a0f520;

    local_124 = 0;

    local_118 = 0;

    local_114 = DAT_00a0f520;

    local_128 = uVar3;

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x70,0x22);

    *(uint16_t *)(iVar2 + 4) = 0x70;

    uStack_14 = 0;

    uVar3 = FUN_005a5b30(local_140,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe4f8) + 0x3e0));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4e0) = uVar3;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe4f8) + 0x3d8) = uVar3;

    piVar1 = *(int **)(param_1 + 0xe4e0);

    uStack_14 = 0xffffffff;

    if ((piVar1 != (int *)0x0) && (piVar1[0x18] != 0)) {

      afStack_180[3] = 0.0;

      afStack_180[2] = 0.0;

      afStack_180[1] = 0.0;

      uStack_164 = 0;

      uStack_168 = 0;

      afStack_180[4] = 0.0;

      uStack_154 = 0;

      uStack_15c = 0;

      uStack_160 = 0;

      afStack_180[0] = g_flOne;

      afStack_180[5] = g_flOne;

      fStack_158 = g_flOne;

      uStack_144 = 0;

      uStack_148 = 0;

      uStack_14c = 0;

      uStack_150 = 0;

      (**(code **)(*piVar1 + 0x18))(afStack_180,0x3dcccccd,auStack_40);

      FUN_005e1c80();

      uStack_108 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4e0);

      iStack_ec = DAT_00b03800;

      uStack_e8 = DAT_00b03804;

      uStack_e4 = DAT_00b03808;

      uStack_e0 = DAT_00b0380c;

      uStack_64 = 0;

      uStack_68 = 0;

      fStack_60 = g_flOne;

      uStack_10c = 6;

      uStack_58 = 7;

      uStack_20 = 1;

      iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

      *(uint16_t *)(iVar2 + 4) = 0xa0;

      uStack_14._0_1_ = 2;

      uVar3 = FUN_005d4240(auStack_100);

      uStack_14._0_1_ = 1;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4e4) = uVar3;

      FUN_00560ec0(uVar3);

      if (*(int *)(DAT_00b037f0 + 4) != 0) {

        pvVar4 = operator_new(0x18);

        uStack_14._0_1_ = 3;

        if (pvVar4 == (void *)0x0) {

          uVar3 = 0;

        }

        else {

          uVar3 = FUN_004e7540(*(uint32_t /* width from decompiler */ *)(DAT_00b037f0 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 0xe4f8));

        }

        uStack_14 = CONCAT31(uStack_14._1_3_,1);

        FUN_004b4d90(uVar3);

      }

      uStack_14 = 0xffffffff;

      if (-1 < iStack_ec) {

        (**(code **)(*DAT_00b05060 + 0x14))(uStack_f4,iStack_ec * 8,0x12);

      }

    }

  }

  ExceptionList = local_1c;

  return;

}
