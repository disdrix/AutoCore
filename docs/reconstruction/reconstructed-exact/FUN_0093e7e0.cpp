// =============================================================================
// FUN_0093e7e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093e7e0
// Address:   0x0093e7e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093e7e0 @ 0x0093e7e0
// Stable ID: aa_0093e7e0
// Embedded strings (evidence for future rename):
//   - "i_g_2d_btn_death_respawn.xml"
//   - "(%f) %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~1014 non-empty decompiler lines.
//  - Control keywords: if×94, do×2, while×2, return×1.
//  - Notable callees: FUN_007a4400×10, FUN_007a4390×9, FUN_007b5dd0×4, CONCAT31×3, FUN_008826e0×2, CONCAT44, FUN_004063a0, FUN_004406e0.
//  - Strings: "i_g_2d_btn_death_respawn.xml"; "(%f) %s\n".
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



void FUN_0093e7e0(int param_1)



{

  void *pvVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *pvStack_268;

  int iStack_264;

  uint8_t auStack_260 [512];

  void *pvStack_60;

  int iStack_58;

  uint8_t uStack_4c;

  uint8_t uStack_44;

  uint8_t uStack_3c;

  uint8_t uStack_34;

  uint8_t uStack_30;

  uint8_t uStack_2c;

  uint8_t uStack_28;

  uint8_t uStack_24;

  uint8_t uStack_20;

  uint8_t uStack_1c;

  uint8_t uStack_14;

  uint8_t uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb29b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_007a4400();

  local_4 = 0;

  FUN_007a4400();

  local_4 = CONCAT31(local_4._1_3_,1);

  (**(code **)(**(int **)(param_1 + 0x1168) + 0x28))();

  (**(code **)(**(int **)(param_1 + 0x1168) + 0x180))();

  iVar4 = *(int *)(param_1 + 0x1168);

  uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c);

  if (*(int *)(iVar4 + 0x88) != 0) {

    FUN_00756be0();

  }

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x88) = uVar3;

  FUN_004406e0();

  pvVar1 = operator_new(0x514);

  puStack_8._0_1_ = 2;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0085e590();

  }

  puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

  *(int **)(param_1 + 0x9b8) = piVar2;

  (**(code **)(*piVar2 + 0x300))();

  pvVar1 = operator_new(0x34);

  pvStack_c._0_1_ = 3;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004063a0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3084) = uVar3;

  pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);

  FUN_007a4390();

  FUN_007a4400();

  pvStack_c._0_1_ = 4;

  pvVar1 = operator_new(0xb00);

  pvStack_c._0_1_ = 5;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00913600();

  }

  pvStack_c._0_1_ = 4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf3c) = uVar3;

  pvVar1 = operator_new(0xd30);

  pvStack_c._0_1_ = 6;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00920790();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf38) = uVar3;

  pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);

  FUN_007a4390();

  FUN_007a4400();

  pvStack_c._0_1_ = 7;

  pvVar1 = operator_new(0x570);

  pvStack_c._0_1_ = 8;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0084d140();

  }

  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,7);

  *(int **)(param_1 + 0x309c) = piVar2;

  (**(code **)(*piVar2 + 0x43c))();

  (**(code **)(**(int **)(param_1 + 0x309c) + 0xcc))();

  pvVar1 = operator_new(0xb78);

  uStack_10 = 9;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_008422f0();

  }

  uStack_10 = 7;

  *(int **)(param_1 + 0x30a0) = piVar2;

  (**(code **)(*piVar2 + 0x43c))();

  (**(code **)(**(int **)(param_1 + 0x30a0) + 0xcc))();

  pvVar1 = operator_new(0x488);

  uStack_14 = 10;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  uStack_14 = 7;

  *(int **)(param_1 + 0x1144) = piVar2;

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(**(int **)(param_1 + 0x1144) + 0xcc))();

  pvVar1 = operator_new(0x550);

  uStack_1c = 0xb;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0083e460();

  }

  uStack_1c = 7;

  *(int **)(param_1 + 0x113c) = piVar2;

  (**(code **)(*piVar2 + 0x43c))();

  (**(code **)(**(int **)(param_1 + 0x113c) + 0xcc))();

  pvVar1 = operator_new(0x488);

  uStack_20 = 0xc;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  uStack_20 = 7;

  *(int **)(param_1 + 0x1140) = piVar2;

  (**(code **)(*piVar2 + 0x28))();

  pvVar1 = operator_new(0x534);

  uStack_24 = 0xd;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0084f1e0();

  }

  uStack_24 = 7;

  *(int **)(param_1 + 0x30a4) = piVar2;

  (**(code **)(*piVar2 + 0x43c))();

  (**(code **)(**(int **)(param_1 + 0x30a4) + 0xcc))();

  pvVar1 = operator_new(0x524);

  uStack_28 = 0xe;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0084e4a0();

  }

  uStack_28 = 7;

  *(int **)(param_1 + 0x30a8) = piVar2;

  (**(code **)(*piVar2 + 0x43c))();

  (**(code **)(**(int **)(param_1 + 0x30a8) + 0xcc))();

  pvVar1 = operator_new(0x534);

  uStack_2c = 0xf;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_00843810();

  }

  uStack_2c = 7;

  *(int **)(param_1 + 0x30ac) = piVar2;

  (**(code **)(*piVar2 + 0x43c))();

  (**(code **)(**(int **)(param_1 + 0x30ac) + 0xcc))();

  pvVar1 = operator_new(0x504);

  uStack_30 = 0x10;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0083ec90();

  }

  uStack_30 = 7;

  *(int **)(param_1 + 0x30b0) = piVar2;

  (**(code **)(*piVar2 + 0x43c))();

  (**(code **)(**(int **)(param_1 + 0x30b0) + 0xcc))();

  pvVar1 = operator_new(0x488);

  uStack_34 = 0x11;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  uStack_34 = 7;

  *(int **)(param_1 + 0x1150) = piVar2;

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(**(int **)(param_1 + 0x1150) + 0xcc))();

  pvVar1 = operator_new(0x4bc);

  uStack_3c = 0x12;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_00864f20();

  }

  uStack_3c = 7;

  *(int **)(param_1 + 0x1154) = piVar2;

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(**(int **)(param_1 + 0x1154) + 0xcc))();

  pvVar1 = operator_new(0x488);

  uStack_44 = 0x13;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1);

  }

  uStack_44 = 7;

  *(int **)(param_1 + 0x114c) = piVar2;

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(**(int **)(param_1 + 0x114c) + 0xcc))(0);

  pvVar1 = operator_new(0x4cc);

  uStack_4c = 0x14;

  piVar2 = (int *)0x0;

  if (pvVar1 != (void *)0x0) {

    piVar2 = (int *)FUN_0079c860();

  }

  uStack_4c = 7;

  *(int **)(param_1 + 0x1158) = piVar2;

  (**(code **)(*piVar2 + 0x28))("i_g_2d_btn_death_respawn.xml");

  (**(code **)(**(int **)(param_1 + 0x1158) + 0x74))(0x4e5d);

  (**(code **)(**(int **)(param_1 + 0x1158) + 0xcc))(0);

  pvVar1 = operator_new(0x558);

  iStack_58._0_1_ = 0x15;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008a7640();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1118) = uVar3;

  pvVar1 = operator_new(0x784);

  iStack_58._0_1_ = 0x16;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0098cdb0();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x111c) = uVar3;

  pvVar1 = operator_new(0x528);

  iStack_58._0_1_ = 0x17;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00862740();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1124) = uVar3;

  pvVar1 = operator_new(0x530);

  iStack_58._0_1_ = 0x18;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00862690();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1128) = uVar3;

  pvVar1 = operator_new(0x528);

  iStack_58._0_1_ = 0x19;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008625f0();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x112c) = uVar3;

  pvVar1 = operator_new(0x528);

  iStack_58._0_1_ = 0x1a;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00862550();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1130) = uVar3;

  pvVar1 = operator_new(0x528);

  iStack_58._0_1_ = 0x1b;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008624b0();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1134) = uVar3;

  pvVar1 = operator_new(0x554);

  iStack_58._0_1_ = 0x1c;

  if (pvVar1 == (void *)0x0) {

    DAT_00d09a38 = 0;

  }

  else {

    DAT_00d09a38 = FUN_00831070();

  }

  iStack_58._0_1_ = 7;

  pvVar1 = operator_new(0x5d8);

  iStack_58._0_1_ = 0x1d;

  if (pvVar1 == (void *)0x0) {

    DAT_00d09a3c = 0;

  }

  else {

    DAT_00d09a3c = FUN_00832830();

  }

  iStack_58._0_1_ = 7;

  pvVar1 = operator_new(0x604);

  iStack_58._0_1_ = 0x1e;

  if (pvVar1 == (void *)0x0) {

    DAT_00d09a40 = 0;

  }

  else {

    DAT_00d09a40 = FUN_00831d10();

  }

  iStack_58._0_1_ = 7;

  pvVar1 = operator_new(0x54c);

  iStack_58._0_1_ = 0x1f;

  if (pvVar1 == (void *)0x0) {

    DAT_00d09a44 = 0;

  }

  else {

    DAT_00d09a44 = FUN_00830a10();

  }

  iStack_58._0_1_ = 7;

  pvVar1 = operator_new(0x588);

  iStack_58._0_1_ = 0x20;

  if (pvVar1 == (void *)0x0) {

    DAT_00d09a48 = 0;

  }

  else {

    DAT_00d09a48 = FUN_0082ff80();

  }

  iStack_58._0_1_ = 7;

  pvVar1 = operator_new(0x52c);

  iStack_58._0_1_ = 0x21;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00854c40();

  }

  iStack_58._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1120) = uVar3;

  pvVar1 = operator_new(0x1a2bc);

  iStack_58._0_1_ = 0x22;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00866c70();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1138) = uVar3;

  iStack_58 = (uint)iStack_58._1_3_ << 8;

  FUN_007a4390();

  FUN_007a4400();

  iStack_58._0_1_ = 0x23;

  pvVar1 = operator_new(0x52c);

  iStack_58._0_1_ = 0x24;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0088a5c0(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x23;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1040) = uVar3;

  pvVar1 = operator_new(0x538);

  iStack_58._0_1_ = 0x25;

  if (pvVar1 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_00889180(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x23;

  piVar2 = (int *)(param_1 + 0x1030);

  *piVar2 = iVar4;

  pvVar1 = operator_new(0x534);

  iStack_58._0_1_ = 0x26;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00889d30();

  }

  iStack_58._0_1_ = 0x23;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1034) = uVar3;

  pvVar1 = operator_new(0x538);

  iStack_58._0_1_ = 0x27;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008880f0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1038) = uVar3;

  iStack_58 = (uint)iStack_58._1_3_ << 8;

  FUN_007a4390();

  FUN_007a4400();

  iStack_58._0_1_ = 0x28;

  pvVar1 = operator_new(0x530);

  iStack_58._0_1_ = 0x29;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008888a0(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x28;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x103c) = uVar3;

  pvVar1 = operator_new(0x528);

  iStack_58._0_1_ = 0x2a;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008c3fd0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1044) = uVar3;

  iStack_58 = (uint)iStack_58._1_3_ << 8;

  FUN_007a4390();

  FUN_007a4400();

  iStack_58._0_1_ = 0x2b;

  pvVar1 = operator_new(0x7e4);

  iStack_58._0_1_ = 0x2c;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008fff40();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1048) = uVar3;

  pvVar1 = operator_new(0x540);

  iStack_58._0_1_ = 0x2d;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00898eb0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10fc) = uVar3;

  pvVar1 = operator_new(0x5b0);

  iStack_58._0_1_ = 0x2e;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008826e0(pvVar1,1);

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104c) = uVar3;

  pvVar1 = operator_new(0x594);

  iStack_58._0_1_ = 0x2f;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008858b0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1050) = uVar3;

  pvVar1 = operator_new(0x630);

  iStack_58._0_1_ = 0x30;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0089d0a0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1054) = uVar3;

  pvVar1 = operator_new(0x748);

  iStack_58._0_1_ = 0x31;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008ac3f0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1058) = uVar3;

  pvVar1 = operator_new(0x5d0);

  iStack_58._0_1_ = 0x32;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0088f810();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x105c) = uVar3;

  pvVar1 = operator_new(0x610);

  iStack_58._0_1_ = 0x33;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0088e070();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1060) = uVar3;

  pvVar1 = operator_new(0x6d0);

  iStack_58._0_1_ = 0x34;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008a9f40();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1088) = uVar3;

  pvVar1 = operator_new(0x52c);

  iStack_58._0_1_ = 0x35;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008a7e00();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10b8) = uVar3;

  pvVar1 = operator_new(0x528);

  iStack_58._0_1_ = 0x36;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008bce40();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10bc) = uVar3;

  pvVar1 = operator_new(0x564);

  iStack_58._0_1_ = 0x37;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008d9500();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x108c) = uVar3;

  pvVar1 = operator_new(0x584);

  iStack_58._0_1_ = 0x38;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008f33f0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1090) = uVar3;

  pvVar1 = operator_new(0x668);

  iStack_58._0_1_ = 0x39;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008fc3b0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1064) = uVar3;

  pvVar1 = operator_new(0x808);

  iStack_58._0_1_ = 0x3a;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008e6490();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1068) = uVar3;

  pvVar1 = operator_new(0x5a0);

  iStack_58._0_1_ = 0x3b;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008f26e0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x106c) = uVar3;

  pvVar1 = operator_new(0x570);

  iStack_58._0_1_ = 0x3c;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00895d30();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1070) = uVar3;

  pvVar1 = operator_new(0x6c4);

  iStack_58._0_1_ = 0x3d;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008e1860();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1074) = uVar3;

  pvVar1 = operator_new(0x5b0);

  iStack_58._0_1_ = 0x3e;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008b8bd0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1108) = uVar3;

  pvVar1 = operator_new(0x810);

  iStack_58._0_1_ = 0x3f;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00908790();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110c) = uVar3;

  pvVar1 = operator_new(0x578);

  iStack_58._0_1_ = 0x40;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008b6230();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1110) = uVar3;

  pvVar1 = operator_new(0x54c);

  iStack_58._0_1_ = 0x41;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008de8b0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10d4) = uVar3;

  pvVar1 = operator_new(0xf40);

  iStack_58._0_1_ = 0x42;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0081ab20();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10d8) = uVar3;

  pvVar1 = operator_new(0xf98);

  iStack_58._0_1_ = 0x43;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00820830();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10dc) = uVar3;

  pvVar1 = operator_new(0x10dc);

  iStack_58._0_1_ = 0x44;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0081f2f0();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10e0) = uVar3;

  pvVar1 = operator_new(0xf04);

  iStack_58._0_1_ = 0x45;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0081c460();

  }

  iStack_58._0_1_ = 0x2b;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10e4) = uVar3;

  pvVar1 = operator_new(0xea8);

  iStack_58._0_1_ = 0x46;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0081d8d0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1104) = uVar3;

  iStack_58 = (uint)iStack_58._1_3_ << 8;

  FUN_007a4390();

  FUN_007a4400();

  iStack_58._0_1_ = 0x47;

  pvVar1 = operator_new(0x5b0);

  iStack_58._0_1_ = 0x48;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008826e0(pvVar1,0);

  }

  iStack_58._0_1_ = 0x47;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1078) = uVar3;

  pvVar1 = operator_new(0x600);

  iStack_58._0_1_ = 0x49;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008a5c90(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x47;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x107c) = uVar3;

  pvVar1 = operator_new(0x688);

  iStack_58._0_1_ = 0x4a;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008f0d80();

  }

  iStack_58._0_1_ = 0x47;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1080) = uVar3;

  pvVar1 = operator_new(0x54c);

  iStack_58._0_1_ = 0x4b;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008998d0(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1084) = uVar3;

  iStack_58 = (uint)iStack_58._1_3_ << 8;

  FUN_007a4390();

  FUN_007a4400();

  iStack_58._0_1_ = 0x4c;

  pvVar1 = operator_new(0x550);

  iStack_58._0_1_ = 0x4d;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008f8850();

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x109c) = uVar3;

  pvVar1 = operator_new(0x638);

  iStack_58._0_1_ = 0x4e;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008ea770(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10a0) = uVar3;

  pvVar1 = operator_new(0x5f0);

  iStack_58._0_1_ = 0x4f;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008c8ad0();

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10ac) = uVar3;

  pvVar1 = operator_new(0x52c);

  iStack_58._0_1_ = 0x50;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008b2c70(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10a4) = uVar3;

  pvVar1 = operator_new(0x53c);

  iStack_58._0_1_ = 0x51;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008b1ed0(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10a8) = uVar3;

  pvVar1 = operator_new(0x5bc);

  iStack_58._0_1_ = 0x52;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008c1040(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1094) = uVar3;

  pvVar1 = operator_new(0x688);

  iStack_58._0_1_ = 0x53;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008a1470();

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10b0) = uVar3;

  pvVar1 = operator_new(0x558);

  iStack_58._0_1_ = 0x54;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00894190(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10b4) = uVar3;

  pvVar1 = operator_new(0x520);

  iStack_58._0_1_ = 0x55;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008ddd40();

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10e8) = uVar3;

  pvVar1 = operator_new(0x53c);

  iStack_58._0_1_ = 0x56;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008913d0();

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10ec) = uVar3;

  pvVar1 = operator_new(0x588);

  iStack_58._0_1_ = 0x57;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008bf4b0(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1098) = uVar3;

  pvVar1 = operator_new(0x554);

  iStack_58._0_1_ = 0x58;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008932c0(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10f0) = uVar3;

  pvVar1 = operator_new(0x5b4);

  iStack_58._0_1_ = 0x59;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_008bb050();

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10f4) = uVar3;

  pvVar1 = operator_new(0x558);

  iStack_58._0_1_ = 0x5a;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0088b860(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  iStack_58._0_1_ = 0x4c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10f8) = uVar3;

  pvVar1 = operator_new(0x58c);

  iStack_58._0_1_ = 0x5b;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00886e90(pvVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe890));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1100) = uVar3;

  iStack_58 = (uint)iStack_58._1_3_ << 8;

  FUN_007a4390();

  FUN_007a4400();

  iStack_58._0_1_ = 0x5c;

  pvVar1 = operator_new(0x5a0);

  iStack_58._0_1_ = 0x5d;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00878c70();

  }

  iStack_58._0_1_ = 0x5c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c0) = uVar3;

  pvVar1 = operator_new(0x640);

  iStack_58._0_1_ = 0x5e;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0087b3e0();

  }

  iStack_58._0_1_ = 0x5c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c4) = uVar3;

  pvVar1 = operator_new(0x58c);

  iStack_58._0_1_ = 0x5f;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0086ffd0();

  }

  iStack_58._0_1_ = 0x5c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c8) = uVar3;

  pvVar1 = operator_new(0x658);

  iStack_58._0_1_ = 0x60;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00872e00();

  }

  iStack_58._0_1_ = 0x5c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10cc) = uVar3;

  pvVar1 = operator_new(0x650);

  iStack_58._0_1_ = 0x61;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0086cd10();

  }

  iStack_58._0_1_ = 0x5c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10d0) = uVar3;

  uVar3 = operator_new(0x5c4);

  iStack_58._0_1_ = 0x62;

  if ((void *)uVar3 == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_0086e4d0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1114) = uVar5;

  iStack_58 = (uint)iStack_58._1_3_ << 8;

  FUN_007a4390();

  iVar4 = 0x3a;

  do {

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 0x174))(piVar2 + -0x3a);

    }

    piVar2 = piVar2 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  piVar2 = (int *)(param_1 + 0x1034);

  iVar4 = 0x1d;

  do {

    if (piVar2[-1] != 0) {

      *(uint8_t *)(piVar2[-1] + 0xc6) = 1;

    }

    if (*piVar2 != 0) {

      *(uint8_t *)(*piVar2 + 0xc6) = 1;

    }

    piVar2 = piVar2 + 2;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  if (*(int *)(param_1 + 0x1100) != 0) {

    *(uint8_t *)(*(int *)(param_1 + 0x1100) + 0xc6) = 0;

  }

  FUN_00931570();

  iStack_58 = 0xffffffff;

  QueryPerformanceCounter((LARGE_INTEGER *)&stack0xfffffb30);

  sprintf(&stack0xfffffb40,"(%f) %s\n",

          (double)((float)CONCAT44(-(uint)((uint)uVar3 < pvStack_268) - iStack_264,

                                   uVar3 - (int)pvStack_268) * _DAT_00afa254),auStack_260);

  OutputDebugStringA(&stack0xfffffb40);

  ExceptionList = pvStack_60;

  return;

}
