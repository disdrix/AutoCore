// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_004d8a10
// -----------------------------------------------------------------------------
// Stable ID: aa_004d8a10
// Callee of Named_Client_InitInstance
// Address:   0x004d8a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~447 non-empty decompiler lines.
//  - Control keywords: if×19, for×1, return×1.
//  - Notable callees: InitializeCriticalSection×16, FUN_004e7450×4, FUN_00671610×3, FUN_004e5840×2, FUN_004e7420×2, FUN_00418e60, FUN_004bff60, FUN_004d8a10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_Client_InitInstance_004d8a10(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  DWORD DVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *pvVar6;

  int iVar7;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  *param_1 = &PTR_FUN_009cc770;

  param_1[0xc] = 0;

  FUN_004e7450();

  *(uint8_t *)(param_1 + 0x10) = 0;

  FUN_004e7450();

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  uVar3 = FUN_004e28c0();

  param_1[0x19] = uVar3;

  param_1[0x1a] = 0;

  param_1[0x1c] = 0;

  *(uint8_t *)(param_1 + 0x1d) = 0;

  param_1[0x1e] = 0;

  *(uint8_t *)(param_1 + 0x1f) = 0;

  *(uint8_t *)((int)param_1 + 0x7d) = 0;

  *(uint8_t *)((int)param_1 + 0x7e) = 1;

  *(uint8_t *)((int)param_1 + 0x7f) = 0;

  *(uint8_t *)(param_1 + 0x20) = 0;

  *(uint8_t *)((int)param_1 + 0x81) = 0;

  *(uint8_t *)((int)param_1 + 0x82) = 0;

  *(uint8_t *)((int)param_1 + 0x83) = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  param_1[0x24] = 0;

  param_1[0x48] = 0;

  param_1[0x47] = 0;

  param_1[0x46] = 0;

  param_1[0x3929] = 0;

  param_1[0x392a] = 0;

  param_1[0x3938] = 0;

  param_1[0x3939] = 0;

  param_1[0x393b] = 0;

  param_1[0x393c] = 0;

  param_1[0x393d] = 0;

  param_1[0x393e] = 0;

  param_1[0x393f] = 0;

  param_1[0x3940] = 0;

  param_1[0x3941] = 0;

  FUN_004e7450();

  param_1[0x394b] = 0;

  param_1[0x394c] = 0;

  param_1[0x394d] = 0;

  param_1[0x394f] = 0;

  param_1[0x3950] = 0;

  param_1[0x3951] = 0;

  param_1[0x3953] = 0;

  param_1[0x3954] = 0;

  param_1[0x3955] = 0;

  FUN_004e5840(2);

  FUN_004e5840(2);

  param_1[0x3978] = 0;

  param_1[0x3979] = 0;

  param_1[0x397a] = 0;

  uVar3 = FUN_00671610();

  param_1[0x397c] = uVar3;

  param_1[0x397d] = 0;

  param_1[0x3980] = &PTR_FUN_009cb368;

  param_1[0x3981] = 0;

  param_1[0x3982] = 0;

  param_1[0x3983] = 0;

  param_1[0x3990] = 0xffffffff;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3984));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x398a));

  param_1[0x3994] = &PTR_FUN_009cc3e4;

  param_1[0x3995] = 0;

  param_1[0x3996] = 0;

  param_1[0x3997] = 0;

  param_1[0x39a4] = 0xffffffff;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3998));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x399e));

  param_1[0x39a5] = &PTR_FUN_009cc3ec;

  param_1[0x39a6] = 0;

  param_1[0x39a7] = 0;

  param_1[0x39a8] = 0;

  param_1[0x39b5] = 0xffffffff;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x39a9));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x39af));

  param_1[0x39b6] = 1;

  param_1[0x39b7] = 0;

  param_1[0x39b8] = 0xffffffff;

  param_1[0x39b9] = 0;

  param_1[0x39ba] = 0xffffffff;

  param_1[0x39bb] = 0x7fffffff;

  param_1[0x39bd] = 0;

  param_1[0x39be] = 0;

  param_1[0x39bf] = 0;

  param_1[0x39c1] = 0;

  param_1[0x39c2] = 0;

  param_1[0x39c3] = 0;

  uVar3 = FUN_004e2920();

  param_1[0x39c5] = uVar3;

  param_1[0x39c6] = 0;

  param_1[0x39c8] = 0;

  param_1[0x39c9] = 0;

  param_1[0x39ca] = 0;

  param_1[0x39cc] = 0;

  param_1[0x39cd] = 0;

  param_1[0x39ce] = 0;

  FUN_00589b00();

  param_1[0x39d3] = 0;

  param_1[0x39d4] = 0;

  param_1[0x39d5] = 0;

  param_1[0x39d7] = 0;

  param_1[0x39d8] = 0;

  param_1[0x39d9] = 0;

  param_1[0x39db] = 0;

  param_1[0x39dc] = 0;

  param_1[0x39dd] = 0;

  uVar3 = FUN_005b43b0();

  param_1[0x39df] = uVar3;

  param_1[0x39e0] = 0;

  param_1[0x39e2] = 0;

  param_1[0x39e3] = 0;

  param_1[0x39e4] = 0;

  param_1[0x39e6] = 0;

  param_1[0x39e7] = 0;

  param_1[0x39e8] = 0;

  param_1[0x39ea] = 0;

  param_1[0x39eb] = 0;

  param_1[0x39ec] = 0;

  param_1[0x39f6] = 0xffffffff;

  param_1[0x39f7] = 0xffffffff;

  param_1[0x39f8] = 0xffffffff;

  param_1[0x39f9] = 0xffffffff;

  param_1[0x39fa] = 0xffffffff;

  param_1[0x39fb] = 0xffffffff;

  param_1[0x39fc] = 0xffffffff;

  param_1[0x39fd] = 0xffffffff;

  param_1[0x39ff] = 0;

  param_1[0x3a00] = 0;

  param_1[0x3a01] = 0;

  param_1[0x3a03] = 0;

  param_1[0x3a04] = 0;

  param_1[0x3a05] = 0x80000000;

  FUN_004e7420();

  FUN_004e7420();

  param_1[0x3a19] = 0;

  param_1[0x3a1a] = 0;

  param_1[0x3a1b] = 0;

  param_1[0x3a1d] = 0;

  param_1[0x3a1e] = 0;

  param_1[0x3a1f] = 0;

  param_1[0x3a21] = 0;

  param_1[0x3a22] = 0;

  param_1[0x3a23] = 0;

  param_1[0x3a28] = 0;

  param_1[0x3a2a] = 0;

  param_1[0x3a2b] = 0;

  param_1[0x3a2c] = 0;

  param_1[0x3a2f] = 0;

  param_1[0x3a30] = 0;

  param_1[0x3a31] = 0;

  param_1[0x3a33] = 0;

  param_1[0x3a34] = 0;

  param_1[0x3a35] = 0;

  uVar3 = FUN_00671610();

  param_1[0x3a37] = uVar3;

  param_1[0x3a38] = 0;

  uVar3 = FUN_00671610();

  param_1[0x3a3a] = uVar3;

  param_1[0x3a3b] = 0;

  FUN_004e7450();

  fVar1 = g_flOne;

  param_1[0x3a42] = 0;

  param_1[0x3a43] = 0;

  param_1[0x3a44] = 0;

  param_1[0x3a45] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0x3a0e] = fVar1;

  param_1[0x3a0f] = fVar1;

  param_1[0x3a10] = fVar1;

  param_1[0x3a11] = fVar1;

  param_1[0x3a02] = 0xffffffff;

  DVar4 = GetTickCount();

  uVar2 = DAT_00aaaca8;

  uVar3 = DAT_00aaa7ac;

  param_1[0x1b] = DVar4;

  param_1[0x392c] = 0;

  param_1[0x392d] = 0;

  param_1[0x392e] = 0;

  param_1[0x392f] = 0;

  param_1[0x3930] = uVar2;

  param_1[0x3932] = uVar2;

  fVar1 = g_flOne;

  param_1[0x3931] = uVar3;

  param_1[0x3933] = 0;

  param_1[0x3937] = 0;

  param_1[0x3936] = 0;

  param_1[0x3935] = 0;

  param_1[0x3934] = 0;

  param_1[0x3937] = fVar1;

  param_1[0x39f4] = 0x20;

  param_1[0x39f5] = 0;

  param_1[0x25] = 0;

  puVar5 = operator_new(0x44);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = &PTR_FUN_009cb368;

    puVar5[1] = 0;

    puVar5[2] = 0;

    puVar5[3] = 0;

    puVar5[0x10] = 0xffffffff;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 4));

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 10));

  }

  param_1[0x397f] = puVar5;

  puVar5 = operator_new(0x44);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = &PTR_FUN_009cb368;

    puVar5[1] = 0;

    puVar5[2] = 0;

    puVar5[3] = 0;

    puVar5[0x10] = 0xffffffff;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 4));

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 10));

  }

  param_1[0x3991] = puVar5;

  puVar5 = param_1 + 0x3254;

  for (iVar7 = 0x612; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  param_1[0x26] = 0x2005;

  *(uint16_t *)(param_1 + 0x250) = 0;

  param_1[0x49] = 0;

  *(uint8_t *)((int)param_1 + 0xf6) = 0;

  *(uint8_t *)((int)param_1 + 0xf5) = 0;

  param_1[0x29] = 1;

  param_1[0x3e] = 0xffffffff;

  param_1[0x2c] = 0xffffffff;

  param_1[0x2b] = 0;

  param_1[0x28] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x2d) = 0;

  *(uint8_t *)(param_1 + 0x2a) = 1;

  param_1[0x3f] = 0xffffffff;

  param_1[0x42] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x3866) = 0;

  *(uint8_t *)(param_1 + 0x38a7) = 0;

  *(uint8_t *)(param_1 + 0x38e8) = 0;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e59b0(8);

  }

  param_1[0x3970] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e5a30(8);

  }

  param_1[0x3948] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e5b50(3);

  }

  param_1[0x3949] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e5c90(4);

  }

  param_1[0x3947] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e5d10(5);

  }

  param_1[0x3971] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e5e10(5);

  }

  param_1[0x3972] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e5f10(3);

  }

  param_1[0x3973] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e6010(3);

  }

  param_1[0x3974] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e6190(3);

  }

  param_1[0x3975] = uVar3;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e62d0(3);

  }

  param_1[0x3976] = uVar3;

  pvVar6 = operator_new(0x5118);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_005abfa0(param_1);

  }

  param_1[0x3943] = uVar3;

  pvVar6 = operator_new(0x40);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_005b0650(param_1);

  }

  param_1[0x3942] = uVar3;

  param_1[0x39ed] = 0;

  param_1[0x39ee] = 0;

  param_1[0x39ef] = 0;

  param_1[0x39f0] = 0;

  param_1[0x39f1] = 0;

  *(uint8_t *)(param_1 + 0x39f2) = 0;

  *(uint8_t *)((int)param_1 + 0xe7c9) = 0;

  param_1[0x39f3] = 0;

  param_1[0x3a25] = 0;

  param_1[0x3a26] = 0;

  param_1[0x3a3c] = 0;

  pvVar6 = operator_new(0x34);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004e6410(3);

  }

  param_1[0x3a3d] = uVar3;

  pvVar6 = operator_new(0x70);

  if (pvVar6 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004bff60();

  }

  param_1[0x3a45] = uVar3;

  _DAT_00b03600 = param_1;

  puVar5 = operator_new(0x44);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = &PTR_FUN_009cb368;

    puVar5[1] = 0;

    puVar5[2] = 0;

    puVar5[3] = 0;

    puVar5[0x10] = 0xffffffff;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 4));

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 10));

  }

  param_1[0x3992] = puVar5;

  puVar5 = operator_new(0x44);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = &PTR_FUN_009cb368;

    puVar5[1] = 0;

    puVar5[2] = 0;

    puVar5[3] = 0;

    puVar5[0x10] = 0xffffffff;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 4));

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 10));

  }

  param_1[0x3993] = puVar5;

  puVar5 = operator_new(0x44);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = &PTR_FUN_009cc3f4;

    puVar5[1] = 0;

    puVar5[2] = 0;

    puVar5[3] = 0;

    puVar5[0x10] = 0xffffffff;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 4));

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar5 + 10));

  }

  param_1[0x397e] = puVar5;

  param_1[0x3a06] = 0;

  param_1[0x3a0a] = 0;

  param_1[0x393a] = 0;

  param_1[0x3a27] = 0;

  FUN_004e4620(0x20);

  local_8 = 0;

  local_4 = 0;

  FUN_00418e60(param_1[0x15],0x20,&local_8);

  _DAT_00b037e4 = _DAT_00b037e4 + 1;

  param_1[0x3a07] = 0;

  param_1[0x3a0b] = 0;

  param_1[0x3a08] = 0;

  param_1[0x3a0c] = 0;

  param_1[0x3a09] = 0;

  param_1[0x3a0d] = 0;

  return param_1;

}
