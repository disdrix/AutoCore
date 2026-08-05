// READABILITY (auto CF):
//  - Body size: ~653 non-empty decompiler lines.
//  - Control keywords: if×24, goto×13, return×6, switch×1.
//  - Notable callees: FUN_007a6de0×4, CONCAT13, CONCAT22, FUN_0040da70, FUN_00514050, FUN_005140d0, FUN_007a69d0, FUN_00843a60.
//  - Strings: "Currently Equipped:\n"; "%s: %s".
//  - Return sites: 6.

// =============================================================================
// Inv_Currently_Equipped_00843a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00843a60
// Address:   0x00843a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Currently Equipped:
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Inv_Currently_Equipped_00843a60(int *param_1,int *param_2)



{

  byte bVar1;

  short sVar2;

  uint32_t /* width from decompiler */ **ppuVar3;

  uint8_t uVar4;

  char cVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  int iVar8;

  int iVar9;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t uVar11;

  uint32_t /* width from decompiler */ uVar10;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ ***pppuVar12;

  uint32_t /* width from decompiler */ **ppuStack_300;

  uint32_t /* width from decompiler */ uStack_2fc;

  uint32_t /* width from decompiler */ *puStack_2f8;

  uint32_t /* width from decompiler */ ****ppppuStack_2f4;

  uint32_t /* width from decompiler */ ***pppuStack_2f0;

  uint32_t /* width from decompiler */ uStack_2ec;

  uint32_t /* width from decompiler */ **ppuStack_2e8;

  uint32_t /* width from decompiler */ **ppuStack_2e4;

  uint32_t /* width from decompiler */ **ppuStack_2e0;

  uint32_t /* width from decompiler */ ***pppuStack_2dc;

  int iStack_2d8;

  uint32_t /* width from decompiler */ *puStack_2d4;

  uint32_t /* width from decompiler */ *puStack_2d0;

  uint32_t /* width from decompiler */ *puStack_2cc;

  uint32_t /* width from decompiler */ **ppuStack_2c8;

  uint32_t /* width from decompiler */ ***pppuStack_2c4;

  uint32_t /* width from decompiler */ uStack_2c0;

  uint32_t /* width from decompiler */ uStack_2bc;

  uint32_t /* width from decompiler */ ***pppuStack_2b8;

  uint32_t /* width from decompiler */ *puStack_2b4;

  int iStack_2b0;

  uint32_t /* width from decompiler */ ****ppppuStack_2ac;

  uint32_t /* width from decompiler */ uStack_2a8;

  uint32_t /* width from decompiler */ **ppuStack_2a4;

  uint32_t /* width from decompiler */ *puStack_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  uint32_t /* width from decompiler */ **ppuStack_298;

  uint32_t /* width from decompiler */ uStack_294;

  uint32_t /* width from decompiler */ *puStack_290;

  uint32_t /* width from decompiler */ uStack_28c;

  uint32_t /* width from decompiler */ uStack_288;

  uint32_t /* width from decompiler */ ***pppuStack_284;

  uint32_t /* width from decompiler */ *puStack_280;

  uint32_t /* width from decompiler */ uStack_27c;

  uint32_t /* width from decompiler */ uStack_278;

  uint32_t /* width from decompiler */ **ppuStack_274;

  uint32_t /* width from decompiler */ **ppuStack_270;

  int iStack_26c;

  uint32_t /* width from decompiler */ *puStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  uint32_t /* width from decompiler */ *puStack_260;

  uint32_t /* width from decompiler */ *puStack_25c;

  int iStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  uint32_t /* width from decompiler */ **ppuStack_250;

  uint32_t /* width from decompiler */ uStack_24c;

  uint32_t /* width from decompiler */ *puStack_248;

  uint32_t /* width from decompiler */ ***pppuStack_244;

  uint32_t /* width from decompiler */ uStack_240;

  uint32_t /* width from decompiler */ ***pppuStack_23c;

  uint32_t /* width from decompiler */ *puStack_238;

  uint32_t /* width from decompiler */ uStack_234;

  uint32_t /* width from decompiler */ uStack_230;

  uint32_t /* width from decompiler */ **ppuStack_22c;

  uint32_t /* width from decompiler */ **ppuStack_228;

  int iStack_224;

  uint32_t /* width from decompiler */ *puStack_220;

  uint32_t /* width from decompiler */ uStack_21c;

  uint32_t /* width from decompiler */ *puStack_218;

  uint32_t /* width from decompiler */ *puStack_214;

  uint32_t /* width from decompiler */ uStack_210;

  uint32_t /* width from decompiler */ uStack_20c;

  uint32_t /* width from decompiler */ *****pppppuStack_208;

  uint32_t /* width from decompiler */ uStack_204;

  uint32_t /* width from decompiler */ **ppuStack_200;

  uint32_t /* width from decompiler */ uStack_1fc;

  uint32_t /* width from decompiler */ uStack_1f8;

  uint32_t /* width from decompiler */ **ppuStack_1f4;

  uint32_t /* width from decompiler */ *puStack_1f0;

  uint32_t /* width from decompiler */ uStack_1ec;

  uint32_t /* width from decompiler */ *puStack_1e8;

  uint32_t /* width from decompiler */ uStack_1e4;

  uint32_t /* width from decompiler */ *puStack_1e0;

  uint32_t /* width from decompiler */ uStack_1dc;

  uint32_t /* width from decompiler */ uStack_1d8;

  uint32_t /* width from decompiler */ *puStack_1d4;

  uint32_t /* width from decompiler */ ****ppppuStack_1d0;

  uint32_t /* width from decompiler */ uStack_1cc;

  uint32_t /* width from decompiler */ uStack_1c8;

  char ***pppcStack_1c4;

  uint32_t /* width from decompiler */ uStack_1c0;

  uint32_t /* width from decompiler */ ***pppuStack_1bc;

  uint32_t /* width from decompiler */ uStack_1b8;

  uint32_t /* width from decompiler */ uStack_1b4;

  uint32_t /* width from decompiler */ *puStack_1b0;

  uint8_t *puStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint32_t /* width from decompiler */ ***pppuStack_1a4;

  uint8_t ***pppuStack_1a0;

  uint32_t /* width from decompiler */ uStack_19c;

  uint8_t *puStack_198;

  uint32_t /* width from decompiler */ uStack_194;

  uint32_t /* width from decompiler */ uStack_190;

  uint8_t **ppuStack_18c;

  uint8_t *puStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  uint8_t **ppuStack_180;

  char **ppcStack_17c;

  uint8_t *puStack_178;

  uint8_t *puStack_16c;

  char *pcStack_168;

  int iStack_164;

  float fStack_160;

  int **ppiStack_15c;

  float fStack_158;

  undefined *puStack_154;

  int *local_144;

  uint8_t auStack_140 [8];

  uint32_t /* width from decompiler */ local_138;

  uint8_t auStack_130 [8];

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  char acStack_11c [280];

  

  puStack_154 = (undefined *)0x843a7a;

  local_128 = param_1;

  local_138 = FUN_007a69d0();

  if (param_2 == (int *)0x0) {

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  iVar8 = *(int *)(DAT_00d1b6d8 + 0x250);

  if (iVar8 == 0) {

    return;

  }

  local_144 = (int *)0x0;

  switch(*(uint32_t /* width from decompiler */ *)(param_2[0x2a] + 0x38)) {

  case 6:

    sVar2 = *(short *)(*(int *)(param_2[0x2a] + 0x3c) + 0x3f4);

    if (sVar2 == 9) goto code_r0x00843bcd;

    if (sVar2 == 10) {

      iVar8 = *(int *)(iVar8 + 0x26c);

    }

    else {

      if (sVar2 != 0xb) goto LAB_00843beb;

      iVar8 = *(int *)(iVar8 + 0x270);

    }

    goto code_r0x00843bd3;

  default:

    goto LAB_00843beb;

  case 10:

    iVar8 = *(int *)(iVar8 + 0x268);

    if (iVar8 == 0) {

      local_144 = (int *)0x0;

      goto LAB_00843beb;

    }

    break;

  case 0xc:

    puStack_154 = &UNK_00843ad7;

    (**(code **)(*param_2 + 0x1e0))();

    puStack_154 = &UNK_00843ade;

    iVar9 = FUN_0040da70();

    if (*(char *)(iVar9 + 0x3f4) != '\t') {

      bVar1 = *(byte *)(iVar9 + 0x536);

      if ((bVar1 & 2) == 0) {

        if ((bVar1 & 0x10) != 0) {

          iVar8 = *(int *)(*(int *)(iVar8 + 0x260) + 4);

          if (iVar8 == 0) {

            local_144 = (int *)0x0;

          }

          else {

            local_144 = (int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8);

          }

          goto LAB_00843beb;

        }

        if ((bVar1 & 4) == 0) goto LAB_00843beb;

        iVar8 = *(int *)(*(int *)(iVar8 + 0x260) + 8);

        if (iVar8 == 0) {

          local_144 = (int *)0x0;

          goto LAB_00843beb;

        }

      }

      else {

        iVar8 = **(int **)(iVar8 + 0x260);

        if (iVar8 == 0) {

          local_144 = (int *)0x0;

          goto LAB_00843beb;

        }

      }

      local_144 = (int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8);

      goto LAB_00843beb;

    }

code_r0x00843bcd:

    iVar8 = *(int *)(iVar8 + 0x264);

code_r0x00843bd3:

    if (iVar8 == 0) {

      local_144 = (int *)0x0;

    }

    else {

      local_144 = (int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8);

    }

    goto LAB_00843beb;

  case 0xe:

    break;

  case 0x10:

    iVar8 = *(int *)(iVar8 + 600);

    if (iVar8 == 0) {

      local_144 = (int *)0x0;

      goto LAB_00843beb;

    }

    break;

  case 0x1c:

    iVar8 = *(int *)(iVar8 + 0x254);

    if (iVar8 == 0) {

      local_144 = (int *)0x0;

      goto LAB_00843beb;

    }

  }

  local_144 = (int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8);

LAB_00843beb:

  if ((local_144 == param_2) || (local_144 == (int *)0x0)) {

    puStack_154 = (undefined *)0x0;

    fStack_158 = 1.2147285e-38;

    (**(code **)(*param_1 + 4))();

    return;

  }

  puStack_154 = (undefined *)0x1;

  fStack_158 = 1.2143822e-38;

  (**(code **)(*param_1 + 4))();

  fStack_158 = 1.2143835e-38;

  uVar4 = FUN_00845b40();

  fStack_158 = 1.4013e-45;

  ppiStack_15c = &local_144;

  local_128 = (int *)CONCAT13(uVar4,(undefined3)local_128);

  fStack_160 = 1.214387e-38;

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x140))();

  uStack_124 = *puVar6;

  uStack_120 = puVar6[1];

  fStack_160 = 1.2143908e-38;

  (**(code **)(*(int *)param_1[0x140] + 0x268))();

  iVar8 = *(int *)param_1[0x140];

  fStack_160 = -NAN;

  iStack_164 = 0xffffffff;

  pcStack_168 = "Currently Equipped:\n";

  puStack_16c = (uint8_t *)0x843c63;

  iStack_164 = FUN_007a6de0();

  pcStack_168 = (char *)0x843c70;

  (**(code **)(iVar8 + 0x224))();

  pcStack_168 = (char *)0xffffffff;

  if (((uint)unaff_EBX[0x5f] >> 0x13 & 1) == 0) {

    iVar8 = *(int *)param_1[0x140];

    puStack_16c = (uint8_t *)0x843ce0;

    puStack_16c = (uint8_t *)(**(code **)(*unaff_EBX + 0x15c))();

    pcStack_168 = (char *)FUN_007a6de0();

    puStack_16c = (uint8_t *)0x843cf7;

    (**(code **)(iVar8 + 0x250))();

  }

  else {

    puStack_16c = (uint8_t *)0x843c8a;

    puStack_16c = (uint8_t *)(**(code **)(*unaff_EBX + 0x15c))();

    pcStack_168 = (char *)FUN_007a6de0();

    puStack_16c = (uint8_t *)0xffffffff;

    puStack_16c = (uint8_t *)FUN_007a6de0();

    puStack_178 = (uint8_t *)0x843cb6;

    sprintf(acStack_11c,"%s: %s");

    pcStack_168 = acStack_11c;

    puStack_16c = (uint8_t *)0x843ccc;

    (**(code **)(*(int *)param_1[0x140] + 0x250))();

  }

  iVar8 = *(int *)param_1[0x140];

  puStack_16c = &stack0xfffffeb0;

  puStack_16c = (uint8_t *)FUN_00514050();

  (**(code **)(iVar8 + 0x15c))();

  fStack_158 = (float)DAT_00d1e81c * *(float *)(param_1[0x140] + 600) * DAT_00aaa678;

  puStack_178 = auStack_130;

  ppcStack_17c = (char **)0x843d53;

  piVar7 = (int *)(**(code **)(*(int *)param_1[0x13f] + 0x140))();

  iStack_164 = (int)fStack_160;

  pcStack_168 = (char *)(*piVar7 + -10);

  ppcStack_17c = &pcStack_168;

  ppuStack_180 = (uint8_t **)0x843d79;

  (**(code **)(*(int *)param_1[0x140] + 300))();

  ppuStack_180 = &puStack_16c;

  puStack_16c = (uint8_t *)0x5;

  pcStack_168 = (char *)0x6;

  uStack_184 = 0x843d9c;

  (**(code **)(*(int *)param_1[0x140] + 0x110))();

  uStack_184 = 0x843daa;

  (**(code **)(*(int *)param_1[0x140] + 0x13c))();

  uStack_184 = 0x843db8;

  (**(code **)(*(int *)param_1[0x141] + 0x268))();

  uStack_184 = 1;

  ppuStack_18c = (uint8_t **)0x843dc6;

  FUN_00847240();

  uStack_184 = 1;

  puStack_188 = auStack_140;

  ppuStack_18c = (uint8_t **)0x843dde;

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x140))();

  puStack_178 = (uint8_t *)*puVar6;

  ppuStack_18c = &puStack_178;

  uStack_190 = 0x843dff;

  (**(code **)(*(int *)param_1[0x141] + 300))();

  uStack_190 = 0x843e0d;

  (**(code **)(*(int *)param_1[0x141] + 0x13c))();

  piVar7 = (int *)param_1[0x140];

  uStack_190 = 0;

  uStack_194 = 1;

  puStack_198 = &stack0xfffffeb4;

  uStack_19c = 0x843e26;

  iVar8 = (**(code **)(*piVar7 + 0x120))();

  uStack_19c = 1;

  pppuStack_1a0 = &ppuStack_180;

  pppuStack_1a4 = (uint32_t /* width from decompiler */ ***)0x843e39;

  iVar9 = (**(code **)(*piVar7 + 0x140))();

  iVar8 = *(int *)(iVar8 + 4);

  iVar9 = *(int *)(iVar9 + 4);

  pppuStack_1a4 = (uint32_t /* width from decompiler */ ***)0x0;

  uStack_1a8 = 1;

  puStack_1ac = &stack0xfffffe90;

  puStack_1b0 = (uint32_t /* width from decompiler */ *)0x843e5a;

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x120))();

  uStack_19c = *puVar6;

  puStack_1b0 = &uStack_19c;

  uStack_1b4 = 0x843e77;

  puStack_198 = (uint8_t *)(iVar8 + 1 + iVar9);

  (**(code **)(*(int *)param_1[0x141] + 0x118))();

  uStack_1b4 = 0x843e85;

  (**(code **)(*(int *)param_1[0x142] + 0x268))();

  uStack_1b4 = 0x843e93;

  (**(code **)(*(int *)param_1[0x143] + 0x268))();

  pppuVar12 = pppuStack_1a4;

  uStack_1b4 = 1;

  uStack_1b8 = 1;

  pppuStack_1bc = pppuStack_1a4;

  uStack_1c0 = 0x843ea7;

  UI_BuildItemTooltipStats();

  piVar7 = (int *)param_1[0x141];

  uStack_1b4 = 0;

  uStack_1b8 = 1;

  pppuStack_1bc = (uint32_t /* width from decompiler */ ***)&ppuStack_180;

  uStack_1c0 = 0x843ec3;

  pppuStack_1a4 = (uint32_t /* width from decompiler */ ***)(**(code **)(*piVar7 + 0x120))();

  uStack_1c0 = 1;

  pppcStack_1c4 = &ppcStack_17c;

  uStack_1c8 = 0x843ed8;

  iVar9 = (**(code **)(*piVar7 + 0x140))();

  iVar8 = *(int *)(puStack_1ac + 4);

  iVar9 = *(int *)(iVar9 + 4);

  uStack_1c8 = 0;

  uStack_1cc = 1;

  ppppuStack_1d0 = &pppuStack_1a4;

  puStack_1d4 = (uint32_t /* width from decompiler */ *)0x843efd;

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x120))();

  uStack_1c0 = *puVar6;

  puStack_1d4 = &uStack_1c0;

  uStack_1d8 = 0x843f1a;

  pppuStack_1bc = (uint32_t /* width from decompiler */ ***)(iVar8 + 1 + iVar9);

  (**(code **)(*(int *)param_1[0x142] + 0x118))();

  uStack_1d8 = 1;

  uStack_1dc = &uStack_1b4;

  puStack_1e0 = (uint32_t /* width from decompiler */ *)0x843f2f;

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x140))();

  uStack_1cc = *puVar6;

  puStack_1e0 = &uStack_1cc;

  uStack_1c8 = 0;

  uStack_1e4 = 0x843f50;

  (**(code **)(*(int *)param_1[0x142] + 300))();

  uStack_1e4 = 0x843f5e;

  (**(code **)(*(int *)param_1[0x142] + 0x13c))();

  uStack_1e4 = 1;

  puStack_1e8 = &uStack_1c0;

  uStack_1ec = 0x843f73;

  iVar8 = (**(code **)(*(int *)param_1[0x142] + 0x140))();

  uVar10 = *(uint32_t /* width from decompiler */ *)(iVar8 + 4);

  uStack_1ec = 1;

  puStack_1f0 = &uStack_1b8;

  ppuStack_1f4 = (uint32_t /* width from decompiler */ **)0x843f8b;

  puStack_1e0 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x140))();

  puStack_1e0 = (uint32_t /* width from decompiler */ *)*puStack_1e0;

  ppuStack_1f4 = &puStack_1e0;

  uStack_1f8 = 0x843fa8;

  uStack_1dc = (uint32_t /* width from decompiler */ *)uVar10;

  (**(code **)(*(int *)param_1[0x142] + 300))();

  piVar7 = (int *)param_1[0x142];

  uStack_1f8 = 0;

  uStack_1fc = 1;

  ppuStack_200 = &puStack_1d4;

  uStack_204 = 0x843fc1;

  puStack_1e8 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar7 + 0x120))();

  uStack_204 = 1;

  pppppuStack_208 = &ppppuStack_1d0;

  uStack_20c = 0x843fd6;

  iVar8 = (**(code **)(*piVar7 + 0x140))();

  iVar8 = puStack_1f0[1] + 1 + *(int *)(iVar8 + 4);

  if (uStack_1dc._3_1_ == '\0') {

    uStack_20c = 0;

    uStack_210 = 0x844114;

    (**(code **)(*(int *)param_1[0x143] + 0xcc))();

  }

  else {

    uStack_20c = 1;

    uStack_210 = 0x843fff;

    (**(code **)(*(int *)param_1[0x143] + 0xcc))();

    uStack_210 = 0x84400c;

    FUN_00845be0();

    uStack_210 = 1;

    puStack_214 = &uStack_1ec;

    puStack_218 = (uint32_t /* width from decompiler */ *)0x844021;

    puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x142] + 0x140))();

    uStack_204 = *puVar6;

    puStack_218 = &uStack_204;

    ppuStack_200 = (uint32_t /* width from decompiler */ **)0x0;

    uStack_21c = 0x844042;

    (**(code **)(*(int *)param_1[0x143] + 300))();

    uStack_21c = 0x844050;

    (**(code **)(*(int *)param_1[0x143] + 0x13c))();

    uStack_21c = 1;

    puStack_220 = &uStack_1f8;

    iStack_224 = 0x844065;

    iVar9 = (**(code **)(*(int *)param_1[0x143] + 0x140))();

    uVar10 = *(uint32_t /* width from decompiler */ *)(iVar9 + 4);

    iStack_224 = 1;

    ppuStack_228 = &puStack_1f0;

    ppuStack_22c = (uint32_t /* width from decompiler */ **)0x84407d;

    puStack_218 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x142] + 0x140))();

    puStack_218 = (uint32_t /* width from decompiler */ *)*puStack_218;

    ppuStack_22c = &puStack_218;

    uStack_230 = 0x84409a;

    puStack_214 = (uint32_t /* width from decompiler */ *)uVar10;

    (**(code **)(*(int *)param_1[0x143] + 300))();

    uStack_230 = 0;

    uStack_234 = 1;

    puStack_238 = &uStack_20c;

    pppuStack_23c = (uint32_t /* width from decompiler */ ***)0x8440b1;

    puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x142] + 0x120))();

    ppuStack_228 = (uint32_t /* width from decompiler */ **)*puVar6;

    pppuStack_23c = &ppuStack_228;

    uStack_240 = 0x8440ce;

    iStack_224 = iVar8;

    (**(code **)(*(int *)param_1[0x143] + 0x110))();

    piVar7 = (int *)param_1[0x143];

    uStack_240 = 0;

    pppuStack_244 = (uint32_t /* width from decompiler */ ***)0x1;

    puStack_248 = &uStack_21c;

    uStack_24c = 0x8440e7;

    iVar8 = (**(code **)(*piVar7 + 0x120))();

    uStack_24c = 1;

    ppuStack_250 = &puStack_218;

    uStack_254 = 0x8440fa;

    iVar9 = (**(code **)(*piVar7 + 0x140))();

    iVar8 = *(int *)(iVar8 + 4) + 1 + *(int *)(iVar9 + 4);

    pppuVar12 = pppuStack_244;

  }

  uStack_254 = 0x844122;

  (**(code **)(*(int *)param_1[0x144] + 0x268))();

  iStack_258 = param_1[0x144];

  uStack_254 = 1;

  puStack_25c = (uint32_t /* width from decompiler */ *)0x844132;

  iVar9 = FUN_00845360();

  if (iVar9 == 0) {

    uStack_254 = 0;

    iStack_258 = 0x84425d;

    (**(code **)(*(int *)param_1[0x144] + 0xcc))();

  }

  else {

    uStack_254 = 1;

    iStack_258 = 0x84414d;

    (**(code **)(*(int *)param_1[0x144] + 0xcc))();

    iStack_258 = 1;

    puStack_25c = &uStack_234;

    puStack_260 = (uint32_t /* width from decompiler */ *)0x844162;

    puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x142] + 0x140))();

    uStack_24c = *puVar6;

    puStack_260 = &uStack_24c;

    puStack_248 = (uint32_t /* width from decompiler */ *)0x0;

    uStack_264 = 0x844183;

    (**(code **)(*(int *)param_1[0x144] + 300))();

    uStack_264 = 0x844191;

    (**(code **)(*(int *)param_1[0x144] + 0x13c))();

    uStack_264 = 1;

    puStack_268 = &uStack_240;

    iStack_26c = 0x8441a6;

    iVar9 = (**(code **)(*(int *)param_1[0x144] + 0x140))();

    ppuStack_250 = *(uint32_t /* width from decompiler */ ***)(iVar9 + 4);

    iStack_26c = 1;

    ppuStack_270 = &puStack_238;

    ppuStack_274 = (uint32_t /* width from decompiler */ **)0x8441c2;

    puStack_260 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x142] + 0x140))();

    puStack_260 = (uint32_t /* width from decompiler */ *)*puStack_260;

    puStack_25c = (uint32_t /* width from decompiler */ *)iStack_258;

    ppuStack_274 = &puStack_260;

    uStack_278 = 0x8441e3;

    (**(code **)(*(int *)param_1[0x144] + 300))();

    uStack_278 = 0;

    uStack_27c = 1;

    puStack_280 = &uStack_254;

    pppuStack_284 = (uint32_t /* width from decompiler */ ***)0x8441fa;

    puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x142] + 0x120))();

    ppuStack_270 = (uint32_t /* width from decompiler */ **)*puVar6;

    pppuStack_284 = &ppuStack_270;

    uStack_288 = 0x844217;

    iStack_26c = iVar8;

    (**(code **)(*(int *)param_1[0x144] + 0x110))();

    piVar7 = (int *)param_1[0x144];

    uStack_288 = 0;

    uStack_28c = 1;

    puStack_290 = &uStack_264;

    uStack_294 = 0x844230;

    uStack_278 = (**(code **)(*piVar7 + 0x120))();

    uStack_294 = 1;

    ppuStack_298 = &puStack_260;

    uStack_29c = 0x844245;

    iVar8 = (**(code **)(*piVar7 + 0x140))();

    iVar8 = puStack_280[1] + 1 + *(int *)(iVar8 + 4);

  }

  uStack_29c = 0x84426b;

  (**(code **)(*(int *)param_1[0x145] + 0x268))();

  puStack_2a0 = (uint32_t /* width from decompiler */ *)param_1[0x145];

  uStack_29c = 1;

  ppuStack_2a4 = (uint32_t /* width from decompiler */ **)0x84427b;

  FUN_0084b770();

  ppuVar3 = ppuStack_270;

  uStack_29c = 1;

  puStack_2a0 = &uStack_278;

  ppuStack_2a4 = (uint32_t /* width from decompiler */ **)0x844297;

  puStack_290 = (uint32_t /* width from decompiler */ *)(**(code **)(*ppuStack_270[0x142] + 0x140))();

  puStack_290 = (uint32_t /* width from decompiler */ *)*puStack_290;

  ppuStack_2a4 = &puStack_290;

  uStack_28c = 0;

  uStack_2a8 = 0x8442b8;

  (**(code **)(*ppuVar3[0x145] + 300))();

  uStack_2a8 = 0x8442c6;

  (**(code **)(*ppuVar3[0x145] + 0x13c))();

  uStack_2a8 = 1;

  ppppuStack_2ac = &pppuStack_284;

  iStack_2b0 = 0x8442db;

  iVar9 = (**(code **)(*ppuVar3[0x145] + 0x140))();

  pppuStack_284 = *(uint32_t /* width from decompiler */ ****)(iVar9 + 4);

  iStack_2b0 = 1;

  puStack_2b4 = &uStack_27c;

  pppuStack_2b8 = (uint32_t /* width from decompiler */ ***)0x8442f7;

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*ppuVar3[0x142] + 0x140))();

  ppuStack_2a4 = (uint32_t /* width from decompiler */ **)*puVar6;

  puStack_2a0 = (uint32_t /* width from decompiler */ *)uStack_28c;

  pppuStack_2b8 = &ppuStack_2a4;

  uStack_2bc = 0x844318;

  (**(code **)(*ppuVar3[0x145] + 300))();

  uStack_2bc = 0;

  uStack_2c0 = 1;

  pppuStack_2c4 = &ppuStack_298;

  ppuStack_2c8 = (uint32_t /* width from decompiler */ **)0x84432f;

  piVar7 = (int *)(**(code **)(*ppuVar3[0x142] + 0x120))();

  puStack_2b4 = (uint32_t /* width from decompiler */ *)*piVar7;

  ppuStack_2c8 = &puStack_2b4;

  puStack_2cc = (uint32_t /* width from decompiler */ *)0x84434c;

  iStack_2b0 = iVar8;

  (**(code **)(*ppuVar3[0x145] + 0x110))();

  piVar7 = ppuVar3[0x145];

  puStack_2cc = (uint32_t /* width from decompiler */ *)0x0;

  puStack_2d0 = (uint32_t /* width from decompiler */ *)0x1;

  puStack_2d4 = &uStack_2a8;

  iStack_2d8 = 0x844365;

  ppppuStack_2ac = (uint32_t /* width from decompiler */ ****)(**(code **)(*piVar7 + 0x120))();

  iStack_2d8 = 1;

  pppuStack_2dc = &ppuStack_2a4;

  ppuStack_2e0 = (uint32_t /* width from decompiler */ **)0x84437a;

  iVar8 = (**(code **)(*piVar7 + 0x140))();

  pppuStack_2c4 = (uint32_t /* width from decompiler */ ***)(puStack_2b4[1] + 1 + *(int *)(iVar8 + 4));

  ppuStack_2e0 = (uint32_t /* width from decompiler */ **)0x84439a;

  (**(code **)(*ppuVar3[0x146] + 0x268))();

  if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

    ppuStack_2e0 = &puStack_2cc;

    puStack_2cc = (uint32_t /* width from decompiler */ *)0x0;

    ppuStack_2c8 = (uint32_t /* width from decompiler */ **)0x0;

    ppuStack_2e4 = (uint32_t /* width from decompiler */ **)0x84445c;

    (**(code **)(*ppuVar3[0x146] + 300))();

    ppuStack_2e4 = (uint32_t /* width from decompiler */ **)0x0;

    ppuStack_2e8 = (uint32_t /* width from decompiler */ **)0x84446b;

    (**(code **)(*ppuVar3[0x146] + 0xcc))();

  }

  else {

    ppuStack_2e0 = (uint32_t /* width from decompiler */ **)0x1;

    ppuStack_2e4 = (uint32_t /* width from decompiler */ **)0x8443c6;

    (**(code **)(*ppuVar3[0x146] + 0xcc))();

    puStack_2d0 = (uint32_t /* width from decompiler */ *)

                  (int)((float)DAT_00d1e818 * (float)ppuVar3[0x146][0x95] * DAT_00aaa67c);

    ppuStack_2e4 = &puStack_2d0;

    puStack_2cc = (uint32_t /* width from decompiler */ *)0x0;

    ppuStack_2e8 = (uint32_t /* width from decompiler */ **)0x8443fd;

    (**(code **)(*ppuVar3[0x146] + 300))();

    ppuStack_2e8 = (uint32_t /* width from decompiler */ **)0x84440a;

    FUN_008452f0();

    ppuStack_2e8 = (uint32_t /* width from decompiler */ **)0x844418;

    (**(code **)(*ppuVar3[0x146] + 0x13c))();

    puStack_2d0 = puStack_2cc;

    ppuStack_2e8 = &puStack_2d4;

    puStack_2d4 = (uint32_t /* width from decompiler */ *)0x0;

    uStack_2ec = 0x84443b;

    (**(code **)(*ppuVar3[0x146] + 0x110))();

    pppuVar12 = pppuStack_2dc;

  }

  uStack_2ec = 1;

  pppuStack_2f0 = &ppuStack_2c8;

  ppppuStack_2f4 = (uint32_t /* width from decompiler */ ****)0x844480;

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*ppuVar3[0x13f] + 0x140))();

  pppuStack_2b8 = (uint32_t /* width from decompiler */ ***)*puVar6;

  puStack_2cc = (uint32_t /* width from decompiler */ *)puVar6[1];

  puStack_2b4 = (uint32_t /* width from decompiler */ *)(iStack_2d8 + 5);

  ppppuStack_2f4 = &pppuStack_2b8;

  puStack_2f8 = (uint32_t /* width from decompiler */ *)0x8444a8;

  (**(code **)(*ppuVar3[0x13f] + 8))();

  puStack_2f8 = (uint32_t /* width from decompiler */ *)0x8444b6;

  cVar5 = (**(code **)(*ppuVar3[0x146] + 0xd0))();

  if (cVar5 == '\0') {

    puStack_2f8 = &uStack_2bc;

    uStack_2fc = 0x844518;

    (*(code *)(*ppuVar3)[2])();

    uVar11 = extraout_var_00;

  }

  else {

    piVar7 = ppuVar3[0x146];

    puStack_2f8 = (uint32_t /* width from decompiler */ *)0x0;

    uStack_2fc = 1;

    ppuStack_300 = &puStack_2d4;

    iStack_2d8 = (**(code **)(*piVar7 + 0x120))();

    iVar8 = (**(code **)(*piVar7 + 0x140))(&puStack_2d0,1);

    ppppuStack_2f4 = (uint32_t /* width from decompiler */ ****)((int)ppuStack_2e0[1] + *(int *)(iVar8 + 4));

    puStack_2f8 = puStack_2d0;

    (*(code *)(*ppuVar3)[2])(&puStack_2f8);

    uVar11 = extraout_var;

  }

  if (pppuVar12[0x2a][0xe] != (uint32_t /* width from decompiler */ *)0x4) {

    iVar8 = *ppuVar3[0x13f];

    uVar10 = FUN_005140d0(&ppuStack_2e4,

                          CONCAT22(uVar11,*(uint16_t *)(pppuVar12[0x2a][0xf] + 0x12e)));

    (**(code **)(iVar8 + 0x15c))(0,uVar10);

    (**(code **)(*ppuVar3[0x13f] + 0x34c))();

    return;

  }

  ppuStack_300 = (uint32_t /* width from decompiler */ **)0xffffffff;

  (**(code **)(*ppuVar3[0x13f] + 0x15c))(0,&ppuStack_300);

  (**(code **)(*ppuVar3[0x13f] + 0x34c))();

  return;

}
