// =============================================================================
// FUN_00663a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00663a70
// Address:   0x00663a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00663a70 @ 0x00663a70
// Stable ID: aa_00663a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005d68f0×2, FUN_005d6ae0×2, FUN_00662140×2, FUN_00662230, FUN_00662280, FUN_00662510, FUN_00663a70, FUN_0066dd00.
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



void __thiscall FUN_00663a70(float *param_1,int param_2,int *param_3,float param_4)



{

  float *pfVar1;

  uint32_t /* width from decompiler */ uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float *pfStack_100;

  float *pfStack_fc;

  float *pfStack_f8;

  int *piStack_f4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  float local_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  uint8_t local_90 [64];

  uint8_t local_50 [76];

  

  piStack_f4 = param_3;

  pfStack_f8 = (float *)0x663a90;

  FUN_0066dd00();

  piStack_f4 = (int *)local_50;

  pfStack_f8 = (float *)local_90;

  pfStack_fc = (float *)param_2;

  pfStack_100 = (float *)0x663aa8;

  FUN_00662510();

  piStack_f4 = (int *)(param_2 + 0x30);

  pfStack_f8 = (float *)local_90;

  pfVar1 = param_1 + 0x14;

  pfStack_fc = (float *)0x663abb;

  FUN_005d68f0();

  piStack_f4 = (int *)(param_2 + 0x20);

  pfStack_f8 = (float *)local_50;

  pfStack_fc = (float *)0x663acf;

  FUN_005d68f0();

  piStack_f4 = (int *)param_4;

  pfStack_f8 = (float *)0x663ada;

  FUN_00662230();

  piStack_f4 = (int *)param_4;

  pfStack_f8 = (float *)0x663ae5;

  FUN_00662280();

  piStack_f4 = (int *)(param_2 + 0x50);

  pfStack_f8 = param_1 + 0x24;

  pfStack_fc = (float *)0x663af9;

  FUN_005d6ae0();

  piStack_f4 = (int *)(param_2 + 0x60);

  pfStack_f8 = param_1 + 0x24;

  pfStack_fc = (float *)0x663b0d;

  FUN_005d6ae0();

  piStack_f4 = (int *)param_4;

  pfStack_f8 = (float *)0xffff0000;

  pfStack_100 = param_1 + 0x10;

  pfStack_fc = pfVar1;

  (**(code **)(*param_3 + 0x1c))();

  if (*(float *)(param_2 + 0xa4) == _DAT_009e75ac) {

    piStack_f4 = (int *)*param_3;

    fVar7 = 0.0 - *param_1;

    fStack_e0 = *pfVar1 + fVar7 * fStack_d0;

    fStack_dc = param_1[0x15] + fStack_cc * fVar7;

    fStack_d8 = param_1[0x16] + fStack_c8 * fVar7;

    fStack_d4 = param_1[0x17] + fStack_c4 * fVar7;

    uVar2 = FUN_00662140(0,0x3f000000,0x3f800000,0x3f800000,param_4);

  }

  else {

    piStack_f4 = (int *)*param_3;

    fVar7 = *(float *)(param_2 + 0xa0);

    fStack_e0 = *pfVar1 + fVar7 * fStack_d0;

    fStack_dc = param_1[0x15] + fStack_cc * fVar7;

    fStack_d8 = param_1[0x16] + fStack_c8 * fVar7;

    fStack_d4 = param_1[0x17] + fStack_c4 * fVar7;

    uVar2 = FUN_00662140(0,0x3f000000,0x3f800000,0x3f800000,param_4);

  }

  (**(code **)((int)piStack_f4 + 0x1c))(&fStack_e0,&stack0xffffff10,uVar2);

  fVar7 = *(float *)(param_2 + 0xa0);

  fVar3 = *pfVar1 + fVar7 * fStack_e0;

  fVar4 = param_1[0x15] + fStack_dc * fVar7;

  fVar5 = param_1[0x16] + fStack_d8 * fVar7;

  fVar6 = param_1[0x17] + fStack_d4 * fVar7;

  fVar7 = *param_1 * DAT_00a0f298;

  pfStack_fc = (float *)(fStack_cc * fVar7);

  local_c0 = fVar3 + fStack_d0 * fVar7;

  fStack_bc = fVar4 + (float)pfStack_fc;

  fStack_b8 = fVar5 + fStack_c8 * fVar7;

  fStack_b4 = fVar6 + fStack_c4 * fVar7;

  fVar8 = *param_1 * DAT_00aaa6cc;

  pfStack_f8 = (float *)(fStack_c8 * fVar8);

  fVar5 = fVar5 + (float)pfStack_f8;

  fVar7 = param_4;

  (**(code **)(*param_3 + 0x1c))(&local_c0,&stack0xffffff10,0xffffffff,param_4);

  fVar3 = (fVar3 + fVar8 * fStack_d0) * fVar7 + *pfVar1;

  fVar4 = param_1[0x15] + (fVar4 + fStack_cc * fVar8) * fVar7;

  fVar5 = param_1[0x16] + fVar5 * fVar7;

  fVar7 = param_1[0x17] + (fVar6 + fStack_c4 * fVar8) * fVar7;

  fVar6 = *param_1 * DAT_00a0f298;

  fStack_d0 = fVar3 + fVar6 * fStack_e0;

  fStack_cc = fVar4 + fStack_dc * fVar6;

  fStack_c8 = fVar5 + fStack_d8 * fVar6;

  fStack_c4 = fVar7 + fStack_d4 * fVar6;

  fVar6 = *param_1 * DAT_00aaa6cc;

  pfStack_f8 = (float *)(fVar5 + fStack_d8 * fVar6);

  pfStack_100 = (float *)(fVar3 + fVar6 * fStack_e0);

  pfStack_fc = (float *)(fVar4 + fStack_dc * fVar6);

  piStack_f4 = (int *)(fVar7 + fStack_d4 * fVar6);

  (**(code **)(*param_3 + 0x1c))(&fStack_d0,&pfStack_100,0xffffffff,param_4);

  return;

}
