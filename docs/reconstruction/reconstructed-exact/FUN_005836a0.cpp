// =============================================================================
// FUN_005836a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005836a0
// Address:   0x005836a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005836a0 @ 0x005836a0
// Stable ID: aa_005836a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~277 non-empty decompiler lines.
//  - Control keywords: return×12, if×11, switch×1, goto×1.
//  - Notable callees: FUN_004e8320×10, FUN_005832b0×10, FUN_0076f900×10, FUN_0051e930, FUN_005836a0, FUN_005868f0.
//  - Return sites: 12.

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

FUN_005836a0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint8_t *puVar6;

  uint32_t /* width from decompiler */ uStack_144;

  float fStack_140;

  uint32_t /* width from decompiler */ uStack_13c;

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  float fStack_12c;

  uint8_t auStack_128 [16];

  float afStack_118 [5];

  uint32_t /* width from decompiler */ uStack_104;

  uint32_t /* width from decompiler */ uStack_100;

  float fStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  uint32_t /* width from decompiler */ uStack_f4;

  float fStack_f0;

  uint32_t /* width from decompiler */ uStack_ec;

  uint32_t /* width from decompiler */ uStack_e8;

  float fStack_e4;

  uint32_t /* width from decompiler */ uStack_e0;

  uint32_t /* width from decompiler */ uStack_dc;

  float fStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  uint32_t /* width from decompiler */ uStack_d0;

  float fStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  float afStack_c4 [5];

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  float fStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

  uint8_t auStack_a0 [16];

  uint8_t auStack_90 [16];

  uint8_t auStack_80 [16];

  uint8_t auStack_70 [16];

  uint8_t auStack_60 [16];

  uint8_t auStack_50 [16];

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [16];

  uint8_t auStack_10 [16];

  

  if (*(int **)(param_1 + -0x88) == (int *)0x0) {

    FUN_0051e930(param_2,param_3,param_4,param_5);

    return;

  }

  iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

  *param_3 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x90);

  param_3[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x94);

  param_3[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x98);

  iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

  *param_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x80);

  param_4[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84);

  param_4[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x88);

  param_4[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8c);

  piVar1 = *(int **)(param_1 + -0x88);

  fStack_12c = (float)(**(code **)(*piVar1 + 0x48))();

  iVar3 = (**(code **)(*piVar1 + 0x48))();

  fStack_12c = (*(float *)((int)fStack_12c + 0x24) - *(float *)(iVar3 + 0x18)) * DAT_00a0f298;

  switch(param_2) {

  case 1:

    cVar2 = FUN_005832b0(0x532,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0x48))();

    uStack_13c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

    uStack_144 = 0;

    fStack_140 = fStack_12c;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    fStack_d8 = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    uStack_dc = 0;

    uStack_d4 = 0;

    FUN_0076f900(auStack_128,&uStack_dc,0);

    puVar6 = auStack_a0;

    break;

  case 2:

    cVar2 = FUN_005832b0(0x53c,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0x48))();

    uStack_13c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

    uStack_144 = 0;

    fStack_140 = fStack_12c;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    fStack_a8 = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    uStack_ac = 0;

    uStack_a4 = 0;

    FUN_0076f900(auStack_128,&uStack_ac,0x40490fda);

    puVar6 = auStack_80;

    break;

  case 3:

    cVar2 = FUN_005832b0(0x534,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    piVar1 = *(int **)(param_1 + -0x88);

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    iVar5 = (**(code **)(*piVar1 + 0x48))();

    uStack_144 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20);

    uStack_13c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

    fStack_140 = fStack_12c;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    fStack_fc = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    uStack_100 = 0;

    uStack_f8 = 0;

    FUN_0076f900(auStack_128,&uStack_100,0x3f490fda);

    puVar6 = auStack_40;

    break;

  case 4:

    cVar2 = FUN_005832b0(0x533,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    piVar1 = *(int **)(param_1 + -0x88);

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    iVar5 = (**(code **)(*piVar1 + 0x48))();

    uStack_144 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14);

    uStack_13c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

    fStack_140 = fStack_12c;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    fStack_cc = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    uStack_d0 = 0;

    uStack_c8 = 0;

    FUN_0076f900(auStack_128,&uStack_d0,0xbf490fda);

    puVar6 = auStack_60;

    break;

  case 5:

    cVar2 = FUN_005832b0(0x53e,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    piVar1 = *(int **)(param_1 + -0x88);

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    iVar5 = (**(code **)(*piVar1 + 0x48))();

    uStack_144 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20);

    uStack_13c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

    fStack_140 = fStack_12c;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    fStack_e4 = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    uStack_e8 = 0;

    uStack_e0 = 0;

    FUN_0076f900(auStack_128,&uStack_e8,0x4016cbe4);

    puVar6 = auStack_20;

    break;

  case 6:

    cVar2 = FUN_005832b0(0x53d,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    piVar1 = *(int **)(param_1 + -0x88);

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    iVar5 = (**(code **)(*piVar1 + 0x48))();

    uStack_144 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14);

    uStack_13c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

    fStack_140 = fStack_12c;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    afStack_c4[4] = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    afStack_c4[3] = 0.0;

    uStack_b0 = 0;

    FUN_0076f900(auStack_128,afStack_c4 + 3,0xc016cbe4);

    puVar6 = auStack_90;

    break;

  case 7:

    cVar2 = FUN_005832b0(0x528,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0x48))();

    uStack_144 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

    fStack_140 = fStack_12c;

    uStack_13c = 0;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    afStack_118[4] = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    afStack_118[3] = 0.0;

    uStack_104 = 0;

    FUN_0076f900(auStack_128,afStack_118 + 3,0x3fc90fda);

    puVar6 = auStack_70;

    break;

  case 8:

    cVar2 = FUN_005832b0(0x51e,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0x48))();

    uStack_144 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

    fStack_140 = fStack_12c;

    uStack_13c = 0;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    fStack_f0 = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    uStack_f4 = 0;

    uStack_ec = 0;

    FUN_0076f900(auStack_128,&uStack_f4,0xbfc90fda);

    puVar6 = auStack_50;

    break;

  case 9:

    cVar2 = FUN_005832b0(0x514,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0x48))();

    fStack_140 = *(float *)(iVar3 + 0x24);

    uStack_144 = 0;

    uStack_13c = 0;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    afStack_118[0] = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    afStack_118[1] = 0.0;

    afStack_118[2] = 0.0;

    FUN_0076f900(auStack_128,afStack_118,0xbfc90fda);

    puVar6 = auStack_30;

    break;

  case 10:

    cVar2 = FUN_005832b0(0x515,param_3,param_4);

    if (cVar2 != '\0') {

      return;

    }

    iVar3 = (**(code **)(**(int **)(param_1 + -0x88) + 0x48))();

    fStack_140 = *(float *)(iVar3 + 0x18);

    uStack_144 = 0;

    uStack_13c = 0;

    FUN_004e8320(param_3,param_4,&uStack_144,&uStack_138);

    afStack_c4[0] = g_flOne;

    *param_3 = uStack_138;

    param_3[1] = uStack_134;

    param_3[2] = uStack_130;

    afStack_c4[1] = 0.0;

    afStack_c4[2] = 0.0;

    FUN_0076f900(auStack_128,afStack_c4,0x3fc90fda);

    puVar6 = auStack_10;

    break;

  default:

    goto switchD_00583755_default;

  }

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_005868f0(puVar6,auStack_128,param_4);

  *param_4 = *puVar4;

  param_4[1] = puVar4[1];

  param_4[2] = puVar4[2];

  param_4[3] = puVar4[3];

switchD_00583755_default:

  return;

}
