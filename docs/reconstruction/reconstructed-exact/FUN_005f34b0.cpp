// =============================================================================
// FUN_005f34b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f34b0
// Address:   0x005f34b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f34b0 @ 0x005f34b0
// Stable ID: aa_005f34b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1.
//  - Notable callees: FUN_005f3070×6, FUN_005f3090×3, CONCAT31×2, FUN_006c6210×2, FUN_005f2d40, FUN_005f30f0, FUN_005f3160, FUN_005f34b0.
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

int FUN_005f34b0(uint32_t /* width from decompiler */ *param_1,float *param_2,float param_3)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  int aiStack_88 [2];

  int iStack_80;

  float fStack_78;

  float fStack_74;

  float afStack_70 [2];

  float fStack_68;

  float fStack_64;

  float fStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint8_t auStack_58 [8];

  undefined **ppuStack_50;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a7916;

  pvStack_1c = ExceptionList;

  iVar4 = 0;

  ExceptionList = &pvStack_1c;

  FUN_005f30f0(*param_1);

  local_14 = 0;

  pcVar1 = (char *)FUN_005f2d40((int)&uStack_98 + 3);

  if (*pcVar1 != '\0') {

    aiStack_88[0] = (**(code **)(*DAT_00b05060 + 0x10))(0x34,0x22);

    *(uint16_t *)(aiStack_88[0] + 4) = 0x34;

    pvStack_1c._0_1_ = 1;

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_006c6af0();

    pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);

    if (g_flZero < param_3) {

      FUN_006c6200(param_3);

    }

    FUN_005f3070(&iStack_9c);

    uStack_98 = 0;

    FUN_006c6210(iStack_9c,0);

    if (0 < iStack_9c) {

      do {

        FUN_005f3090(&fStack_78);

        FUN_005f3090(&fStack_74);

        FUN_005f3090(afStack_70);

        fStack_78 = *param_2 * fStack_78;

        fStack_74 = fStack_74 * param_2[1];

        afStack_70[0] = param_2[2] * afStack_70[0];

        FUN_006c64c0(&fStack_78);

        iVar4 = iVar4 + 1;

      } while (iVar4 < iStack_9c);

    }

    FUN_005f3070(&uStack_98);

    FUN_006c6210(iStack_9c,uStack_98);

    iVar4 = 0;

    if (0 < uStack_98) {

      do {

        FUN_005f3070(aiStack_88);

        FUN_005f3070(&uStack_8c);

        FUN_005f3070(&uStack_90);

        FUN_005f3070(&uStack_94);

        FUN_006c6280(uStack_8c,uStack_90,uStack_94);

        iVar4 = iVar4 + 1;

      } while (iVar4 < uStack_98);

    }

    FUN_006c6150();

    fStack_68 = g_flMultiKillCountBlend;

    fStack_64 = g_flMultiKillCountBlend;

    fStack_60 = g_flMultiKillCountBlend;

    pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,2);

    uStack_5c = 0;

    FUN_006c6190(&fStack_68);

    uVar3 = FUN_006c5f80(puVar2,auStack_58);

    iStack_80 = (**(code **)(*DAT_00b05060 + 0x10))(0x14,0x22);

    *(uint16_t *)(iStack_80 + 4) = 0x14;

    local_14._0_1_ = 3;

    iVar4 = FUN_006c5f00(puVar2,uVar3);

    local_14 = CONCAT31(local_14._1_3_,2);

    FUN_006c5c90();

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

    ppuStack_50 = &PTR_LAB_009cc290;

  }

  local_14 = 0xffffffff;

  FUN_005f3160();

  ExceptionList = pvStack_1c;

  return iVar4;

}
