// =============================================================================
// FUN_006632a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006632a0
// Address:   0x006632a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006632a0 @ 0x006632a0
// Stable ID: aa_006632a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d6ae0×4, FUN_005d68f0×2, FUN_00662230, FUN_00662280, FUN_00662510, FUN_006632a0, FUN_0066dd00.
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

void __thiscall FUN_006632a0(float *param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  uint8_t **ppuStack_140;

  uint8_t *puStack_13c;

  float fStack_138;

  float fStack_134;

  float **ppfStack_130;

  float *pfStack_12c;

  float *pfStack_128;

  float fStack_124;

  uint8_t *puStack_120;

  float *pfStack_11c;

  float *pfStack_118;

  float fStack_114;

  float *pfStack_110;

  float *pfStack_10c;

  uint8_t *puStack_108;

  int *piStack_104;

  float fStack_f0;

  float fStack_ec;

  float fStack_e8;

  float fStack_e4;

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

  

  piStack_104 = param_3;

  puStack_108 = (uint8_t *)0x6632c0;

  FUN_0066dd00();

  piStack_104 = (int *)local_50;

  puStack_108 = local_90;

  pfStack_10c = (float *)param_2;

  pfStack_110 = (float *)0x6632d8;

  FUN_00662510();

  piStack_104 = (int *)(param_2 + 0x40);

  puStack_108 = local_90;

  pfVar1 = param_1 + 0x14;

  pfStack_10c = (float *)0x6632ee;

  FUN_005d68f0();

  piStack_104 = (int *)(param_2 + 0x30);

  puStack_108 = local_50;

  pfStack_10c = (float *)0x663305;

  FUN_005d68f0();

  piStack_104 = (int *)param_4;

  puStack_108 = (uint8_t *)0x663310;

  FUN_00662280();

  piStack_104 = (int *)param_4;

  puStack_108 = (uint8_t *)0x66331b;

  FUN_00662230();

  piStack_104 = (int *)param_4;

  puStack_108 = (uint8_t *)0xffff0000;

  pfStack_110 = param_1 + 0x10;

  fStack_114 = 9.385583e-39;

  pfStack_10c = pfVar1;

  (**(code **)(*param_3 + 0x1c))();

  fStack_114 = (float)(param_2 + 0x90);

  pfStack_118 = param_1 + 0x24;

  pfStack_11c = (float *)0x66334a;

  FUN_005d6ae0();

  fVar2 = *param_1 * DAT_00a0f298;

  fStack_f0 = *pfVar1 + fVar2 * fStack_c0;

  fStack_ec = param_1[0x15] + fStack_bc * fVar2;

  fStack_114 = (float)param_4;

  fStack_e8 = param_1[0x16] + fStack_b8 * fVar2;

  pfStack_118 = (float *)0xff00ff00;

  pfStack_11c = &fStack_f0;

  puStack_120 = &stack0xffffff00;

  fStack_e4 = param_1[0x17] + fStack_b4 * fVar2;

  fStack_124 = 9.385953e-39;

  (**(code **)(*param_3 + 0x1c))();

  fStack_b8 = *(float *)(param_2 + 0x20);

  fStack_b4 = *(float *)(param_2 + 0x24);

  fStack_124 = (float)(param_2 + 0xa0);

  pfStack_128 = param_1 + 0x24;

  pfStack_12c = (float *)0x663467;

  FUN_005d6ae0();

  fStack_f0 = fStack_d0 * fStack_b4 + *pfVar1;

  fVar2 = *param_1 * g_flMultiKillCountBlend;

  fStack_ec = param_1[0x15] + fStack_cc * fStack_b4;

  fStack_e8 = param_1[0x16] + fStack_c8 * fStack_b4;

  fStack_e4 = param_1[0x17] + fStack_c4 * fStack_b4;

  pfStack_110 = (float *)(fStack_e0 * fVar2 + fStack_f0);

  fVar3 = *param_1 * DAT_00aaa6d4;

  pfStack_10c = (float *)(fStack_dc * fVar2 + fStack_ec);

  puStack_108 = (uint8_t *)(fStack_d8 * fVar2 + fStack_e8);

  piStack_104 = (int *)(fStack_d4 * fVar2 + fStack_e4);

  fStack_f0 = fVar3 * fStack_e0 + fStack_f0;

  fStack_124 = (float)param_4;

  pfStack_128 = (float *)0xffffffff;

  pfStack_12c = &fStack_f0;

  ppfStack_130 = &pfStack_110;

  fStack_ec = fStack_dc * fVar3 + fStack_ec;

  fStack_e8 = fStack_d8 * fVar3 + fStack_e8;

  fStack_e4 = fStack_d4 * fVar3 + fStack_e4;

  fStack_134 = 9.386434e-39;

  (**(code **)(*param_3 + 0x1c))();

  piStack_104 = (int *)(param_1[0x17] + fStack_d4 * fStack_c8);

  fVar2 = *param_1 * g_flMultiKillCountBlend;

  fStack_114 = fStack_e4 * fVar2 + (float)piStack_104;

  pfStack_11c = (float *)(fStack_ec * fVar2 + param_1[0x15] + fStack_dc * fStack_c8);

  puStack_120 = (uint8_t *)(fVar2 * fStack_f0 + *pfVar1 + fStack_e0 * fStack_c8);

  pfStack_118 = (float *)(fStack_e8 * fVar2 + param_1[0x16] + fStack_d8 * fStack_c8);

  fStack_134 = (float)param_4;

  fStack_138 = -NAN;

  puStack_13c = &stack0xffffff00;

  ppuStack_140 = &puStack_120;

  (**(code **)(*param_3 + 0x1c))();

  FUN_005d6ae0(param_1 + 0x24,param_2 + 0x50);

  fVar2 = *param_1 * DAT_00aaa6cc;

  pfStack_110 = (float *)((float)puStack_120 * fVar2 + *pfVar1);

  pfStack_10c = (float *)(param_1[0x15] + (float)pfStack_11c * fVar2);

  puStack_108 = (uint8_t *)(param_1[0x16] + (float)pfStack_118 * fVar2);

  piStack_104 = (int *)(param_1[0x17] + fStack_114 * fVar2);

  fVar2 = *param_1 * DAT_00a0f298;

  ppfStack_130 = (float **)(*pfVar1 + fVar2 * (float)puStack_120);

  pfStack_12c = (float *)(param_1[0x15] + (float)pfStack_11c * fVar2);

  pfStack_128 = (float *)(param_1[0x16] + (float)pfStack_118 * fVar2);

  fStack_124 = param_1[0x17] + fStack_114 * fVar2;

  (**(code **)(*param_3 + 0x1c))(&pfStack_110,&ppfStack_130,0xffffff00,param_4);

  FUN_005d6ae0(param_1 + 0x18,param_2 + 0x70);

  fVar2 = *param_1 * DAT_00aaa6cc;

  puStack_120 = (uint8_t *)((float)ppfStack_130 * fVar2 + param_1[0x10]);

  pfStack_11c = (float *)(param_1[0x11] + (float)pfStack_12c * fVar2);

  pfStack_118 = (float *)(param_1[0x12] + (float)pfStack_128 * fVar2);

  fStack_114 = param_1[0x13] + fStack_124 * fVar2;

  fVar2 = *param_1 * DAT_00a0f298;

  ppuStack_140 = (uint8_t **)(param_1[0x10] + fVar2 * (float)ppfStack_130);

  puStack_13c = (uint8_t *)(param_1[0x11] + (float)pfStack_12c * fVar2);

  fStack_138 = param_1[0x12] + (float)pfStack_128 * fVar2;

  fStack_134 = param_1[0x13] + fStack_124 * fVar2;

  (**(code **)(*param_3 + 0x1c))(&puStack_120,&ppuStack_140,0xff0000ff,param_4);

  return;

}
