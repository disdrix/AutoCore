// =============================================================================
// FUN_00801c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00801c50
// Address:   0x00801c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00801c50 @ 0x00801c50
// Stable ID: aa_00801c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×9, for×3, do×1, while×1, return×1.
//  - Notable callees: FUN_007ffcf0×2, FUN_00402dd0, FUN_00402ed0, FUN_00406790, FUN_00406840, FUN_007fdba0, FUN_00801c50, FUN_008f7650.
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



void FUN_00801c50(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ auStack_17c [23];

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ auStack_11c [12];

  uint32_t /* width from decompiler */ uStack_ec;

  uint32_t /* width from decompiler */ uStack_e8;

  uint32_t /* width from decompiler */ local_d0 [14];

  uint32_t /* width from decompiler */ local_98 [32];

  uint8_t local_18;

  uint8_t local_17;

  uint8_t local_16;

  uint8_t local_15;

  

  if (*(int *)(param_1 + 0x109c) != 0) {

    uStack_e8 = 0x801c72;

    FUN_008f7650();

  }

  if (*(int *)(param_1 + 0x1138) != 0) {

    *(uint8_t *)(*(int *)(param_1 + 0x1138) + 0x924) = 0;

    *(uint8_t *)(*(int *)(param_1 + 0x1138) + 0x515) = 0;

    *(uint8_t *)(*(int *)(param_1 + 0x1138) + 0x526) = 0;

    *(uint8_t *)(*(int *)(param_1 + 0x1138) + 0x53a) = 0;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1138) + 0x510) = 10;

    *(uint16_t *)(*(int *)(param_1 + 0x1138) + 0x538) = 0;

    iVar3 = 0;

    do {

      *(uint8_t *)(iVar3 + 0x941 + *(int *)(param_1 + 0x1138)) = 0;

      *(uint8_t *)(iVar3 + 0x952 + *(int *)(param_1 + 0x1138)) = 0;

      *(uint8_t *)(iVar3 + 0x966 + *(int *)(param_1 + 0x1138)) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x93c + *(int *)(param_1 + 0x1138)) = 10;

      *(uint16_t *)(iVar3 + 0x964 + *(int *)(param_1 + 0x1138)) = 0;

      iVar3 = iVar3 + 0x418;

    } while (iVar3 < 0x19960);

  }

  uVar1 = DAT_00aaa6b0;

  iVar3 = *(int *)(param_1 + 0x10c0);

  if (iVar3 != 0) {

    *(uint8_t *)(iVar3 + 0x524) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x534) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x530) = uVar1;

  }

  iVar3 = *(int *)(param_1 + 0x10d0);

  if (iVar3 != 0) {

    *(uint8_t *)(iVar3 + 0x528) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x538) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x534) = uVar1;

  }

  if (*(int *)(param_1 + 0x107c) != 0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x107c) + 0x544) = 0;

    uStack_e8 = 0;

    uStack_ec = 0x801d89;

    FUN_00402dd0();

  }

  DAT_00af9300 = 1;

  DAT_00af9338 = 1;

  DAT_00d17928 = 0;

  DAT_00d17929 = 0;

  DAT_00d1792a = 0;

  DAT_00af92d8 = 0xffffffff;

  DAT_00d178f8 = 0;

  DAT_00d17920 = 0;

  DAT_00d17924 = 0;

  if (DAT_00d1775c != '\0') {

    uStack_e8 = 0;

    uStack_ec = 0x801dda;

    FUN_007ffcf0();

  }

  if (DAT_00d1775d != '\0') {

    uStack_e8 = 1;

    uStack_ec = 0x801deb;

    FUN_007ffcf0();

  }

  _DAT_00d17768 = 0;

  _DAT_00d1776c = 0;

  _DAT_00d17770 = 0;

  _DAT_00d17774 = 0;

  _DAT_00d17778 = 0;

  _DAT_00d1777c = 0;

  DAT_00d17780 = 0;

  _DAT_00d17784 = 0;

  DAT_00d17764 = 0;

  if (*(int *)(param_1 + 0xe04) != 0) {

    local_16 = 0xff;

    local_17 = 0xff;

    local_18 = 0xff;

    local_15 = 0xff;

    puVar4 = local_98;

    puVar5 = auStack_17c;

    for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    FUN_00402ed0();

    FUN_00406840();

    puVar4 = local_d0;

    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    puVar4 = local_d0;

    puVar5 = auStack_11c;

    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    uStack_120 = 0x801ebe;

    FUN_00406790();

  }

  fVar2 = g_flOne;

  iVar3 = *(int *)(param_1 + 0x1080);

  if (iVar3 != 0) {

    *(float *)(iVar3 + 0x51c) = g_flOne;

    *(float *)(iVar3 + 0x520) = fVar2;

    *(float *)(iVar3 + 0x524) = fVar2;

    uVar1 = DAT_00a0f298;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x530) = DAT_00a0f298;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x538) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x528) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x534) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x53c) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x52c) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x550) = 0;

  }

  DAT_00d1ad1c = 0;

  uStack_e8 = 0x801f33;

  FUN_007fdba0();

  return;

}
