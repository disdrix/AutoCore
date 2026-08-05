// =============================================================================
// FUN_0097a2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0097a2d0
// Address:   0x0097a2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097a2d0 @ 0x0097a2d0
// Stable ID: aa_0097a2d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_00757970×2, CONCAT13, CONCAT22, CONCAT31, FUN_00404d80, FUN_00757890, FUN_00758c80, FUN_00759090.
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

void __fastcall FUN_0097a2d0(int *param_1)



{

  float fVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  float10 fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uStack_84;

  float afStack_68 [4];

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  float fStack_50;

  float fStack_4c;

  uint32_t /* width from decompiler */ uStack_44;

  float fStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  float fStack_38;

  float fStack_34;

  uint32_t /* width from decompiler */ uStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  float fStack_c;

  

  FUN_00758c80();

  cVar2 = (**(code **)(*param_1 + 0xd0))();

  if (cVar2 != '\0') {

    if ((param_1[0x145] == 0) && (param_1[0x146] == 0)) {

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x164))(0);

      uVar13 = *puVar3;

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x164))(0);

      FUN_00757970(param_1,*puVar3,&DAT_00d1ecac);

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x164))(0);

      uVar13 = *puVar3;

    }

    FUN_00757970(param_1,uVar13,&DAT_00d1ecac);

    if ((param_1[0x13f] != 0) && ((char)param_1[0x150] == '\0')) {

      fVar7 = (float10)fsin((float10)(float)param_1[0x14b] * (float10)DAT_00aaa68c);

      fVar10 = (float)fVar7;

      fVar7 = (float10)fcos((float10)(float)param_1[0x14b] * (float10)DAT_00aaa68c);

      fVar1 = (float)fVar7;

      FUN_00404d80(afStack_68,0x18,4,&LAB_00413510);

      iVar4 = *param_1;

      pfVar6 = afStack_68;

      for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {

        *pfVar6 = 0.0;

        pfVar6 = pfVar6 + 1;

      }

      iVar4 = (**(code **)(iVar4 + 0x164))(0);

      fStack_20 = (float)param_1[0x147];

      uStack_84 = CONCAT13(*(uint8_t *)(iVar4 + 3),0xff0000);

      uStack_84 = CONCAT22(uStack_84._2_2_,0xff00);

      uStack_84 = CONCAT31(uStack_84._1_3_,0xff);

      uStack_14 = uStack_84;

      uStack_2c = uStack_84;

      uStack_44 = uStack_84;

      afStack_68[3] = (float)uStack_84;

      uStack_10 = 0;

      uStack_3c = 0;

      uStack_54 = 0;

      uStack_58 = 0;

      fStack_c = g_flOne;

      fStack_40 = g_flOne;

      fStack_28 = g_flOne;

      fStack_24 = g_flOne;

      fStack_1c = (float)-(param_1[0x149] / 2);

      fStack_4c = (float)-(param_1[0x14a] / 2);

      fVar8 = fStack_1c * fVar1;

      fVar9 = fStack_4c * fVar10;

      afStack_68[0] = (fVar8 - fVar9) + fStack_20;

      fStack_1c = fStack_1c * fVar10;

      fStack_34 = (float)param_1[0x148];

      fStack_4c = fStack_4c * fVar1;

      afStack_68[1] = fStack_34 + fStack_1c + fStack_4c;

      fVar11 = (float)(param_1[0x149] / 2);

      fVar12 = fVar11 * fVar10;

      fVar11 = fVar11 * fVar1;

      fStack_50 = (fVar11 - fVar9) + fStack_20;

      fVar9 = (float)(param_1[0x14a] / 2);

      fVar10 = fVar9 * fVar10;

      fStack_38 = (fVar11 - fVar10) + fStack_20;

      fVar9 = fVar9 * fVar1;

      fStack_4c = fVar12 + fStack_34 + fStack_4c;

      fStack_1c = fVar9 + fStack_34 + fStack_1c;

      fStack_34 = fVar9 + fVar12 + fStack_34;

      fStack_20 = (fVar8 - fVar10) + fStack_20;

      FUN_00757890(afStack_68,4,param_1[0x13f],1,&DAT_00d1ecac);

    }

  }

  FUN_00759090();

  (**(code **)(*param_1 + 0xe0))(0);

  return;

}
