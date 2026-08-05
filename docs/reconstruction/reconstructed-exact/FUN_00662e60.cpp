// =============================================================================
// FUN_00662e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00662e60
// Address:   0x00662e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00662e60 @ 0x00662e60
// Stable ID: aa_00662e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~142 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005d6ae0×3, FUN_005d68f0×2, FUN_005b3300, FUN_00656580, FUN_00662140, FUN_00662230, FUN_00662280, FUN_00662510.
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

void __thiscall FUN_00662e60(float *param_1,float **param_2,int *param_3,int param_4)



{

  float **ppfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float **ppfStack_11c;

  float *pfStack_118;

  float *pfStack_114;

  float *pfStack_110;

  float *pfStack_10c;

  float fStack_108;

  float fStack_104;

  float *pfStack_100;

  float **ppfStack_fc;

  float *pfStack_f8;

  float *pfStack_f4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  uint8_t local_90 [64];

  uint8_t local_50 [76];

  

  pfStack_f4 = (float *)param_3;

  pfStack_f8 = (float *)0x662e80;

  FUN_0066dd00();

  pfStack_f4 = (float *)local_50;

  pfStack_f8 = (float *)local_90;

  ppfStack_fc = param_2;

  pfStack_100 = (float *)0x662e98;

  FUN_00662510();

  pfStack_f4 = (float *)(param_2 + 0x18);

  pfStack_f8 = (float *)local_90;

  ppfVar1 = (float **)(param_1 + 0x14);

  ppfStack_fc = (float **)0x662eab;

  FUN_005d68f0();

  pfStack_f4 = (float *)(param_2 + 8);

  pfStack_f8 = (float *)local_50;

  ppfStack_fc = (float **)0x662ebf;

  FUN_005d68f0();

  pfStack_f4 = (float *)param_4;

  pfStack_f8 = (float *)0x662eca;

  FUN_00662280();

  pfStack_f4 = (float *)param_4;

  pfStack_f8 = (float *)0x662ed5;

  FUN_00662230();

  pfStack_f4 = (float *)(param_2 + 0x1c);

  pfStack_f8 = param_1 + 0x24;

  ppfStack_fc = (float **)0x662ee9;

  FUN_005d6ae0();

  pfStack_f4 = (float *)(param_2 + 0x20);

  pfStack_f8 = param_1 + 0x24;

  ppfStack_fc = (float **)0x662f00;

  FUN_005d6ae0();

  pfStack_f4 = (float *)param_4;

  pfStack_f8 = (float *)0xffff0000;

  pfStack_100 = param_1 + 0x10;

  fStack_104 = 9.384115e-39;

  ppfStack_fc = ppfVar1;

  (**(code **)(*param_3 + 0x1c))();

  fVar2 = *param_1 * DAT_00a0f298;

  fStack_d0 = (float)*ppfVar1 + fStack_c0 * fVar2;

  fStack_cc = param_1[0x15] + fStack_bc * fVar2;

  fStack_c8 = param_1[0x16] + fStack_b8 * fVar2;

  pfStack_f4 = (float *)*param_3;

  fStack_c4 = param_1[0x17] + fStack_b4 * fVar2;

  fVar2 = *param_1 * DAT_00aaa6cc;

  fStack_e0 = (float)*ppfVar1 + fVar2 * fStack_c0;

  fStack_104 = (float)param_4;

  fStack_dc = param_1[0x15] + fStack_bc * fVar2;

  fStack_108 = 1.0;

  fStack_d8 = param_1[0x16] + fStack_b8 * fVar2;

  pfStack_10c = (float *)0x3f800000;

  pfStack_110 = (float *)0x3f000000;

  fStack_d4 = param_1[0x17] + fStack_b4 * fVar2;

  pfStack_114 = (float *)0x0;

  pfStack_118 = (float *)0x66300c;

  fStack_108 = (float)FUN_00662140();

  pfStack_10c = &fStack_d0;

  pfStack_110 = &fStack_e0;

  pfStack_114 = (float *)0x663023;

  (**(code **)((int)pfStack_f4 + 0x1c))();

  pfStack_114 = &fStack_c0;

  pfStack_118 = &fStack_d0;

  ppfStack_11c = ppfVar1;

  FUN_00656580(0x3fc00000,param_2[0x32],param_2[0x33],0x18);

  pfStack_114 = (float *)0x4;

  ppfStack_11c = &pfStack_100;

  pfStack_118 = (float *)0x1;

  pfStack_100 = (float *)0x0;

  ppfStack_fc = (float **)0x0;

  pfStack_f8 = (float *)0x80000000;

  FUN_005b3300();

  pfStack_114 = (float *)param_4;

  ppfStack_fc = (float **)0x1;

  *pfStack_100 = (float)(param_1 + 0x34);

  pfStack_118 = (float *)0xffffffff;

  ppfStack_11c = &pfStack_100;

  (**(code **)(*param_3 + 0x24))();

  if (-1 < (int)fStack_104) {

    (**(code **)(*DAT_00b05060 + 0x14))(pfStack_10c,(int)fStack_104 * 4,0x12);

  }

  pfStack_10c = *ppfVar1;

  fVar2 = *param_1 * DAT_00a0f298;

  fStack_108 = param_1[0x15];

  fStack_104 = param_1[0x16];

  pfStack_100 = (float *)param_1[0x17];

  ppfStack_fc = (float **)(fStack_cc * fVar2 + (float)pfStack_10c);

  pfStack_f8 = (float *)(fStack_c8 * fVar2 + fStack_108);

  pfStack_f4 = (float *)(fStack_c4 * fVar2 + fStack_104);

  fVar4 = fStack_c0 * fVar2 + (float)pfStack_100;

  (**(code **)(*param_3 + 0x1c))(&pfStack_10c,&ppfStack_fc,0xffffff00,param_4);

  FUN_005d6ae0(param_1 + 0x18,param_2 + 0x14);

  fVar3 = (float)pfStack_f4 * (float)pfStack_f4 + (float)pfStack_f8 * (float)pfStack_f8 +

          (float)ppfStack_fc * (float)ppfStack_fc;

  fVar2 = 0.0;

  if (fVar3 != 0.0) {

    fVar2 = g_flOne / SQRT(fVar3);

  }

  pfStack_118 = (float *)param_1[0x11];

  pfStack_f8 = (float *)((float)pfStack_f8 * fVar2);

  pfStack_f4 = (float *)((float)pfStack_f4 * fVar2);

  pfStack_114 = (float *)param_1[0x12];

  pfStack_110 = (float *)param_1[0x13];

  fVar3 = *param_1 * DAT_00a0f298;

  ppfStack_fc = (float **)(fVar2 * (float)ppfStack_fc);

  ppfStack_11c = (float **)param_1[0x10];

  fStack_104 = (float)pfStack_f4 * fVar3 + (float)pfStack_114;

  pfStack_100 = (float *)(fVar4 * fVar2 * fVar3 + (float)pfStack_110);

  pfStack_10c = (float *)(fVar3 * (float)ppfStack_fc + (float)ppfStack_11c);

  fStack_108 = (float)pfStack_f8 * fVar3 + (float)pfStack_118;

  (**(code **)(*param_3 + 0x1c))(&ppfStack_11c,&pfStack_10c,0xffffff00,param_4);

  return;

}
