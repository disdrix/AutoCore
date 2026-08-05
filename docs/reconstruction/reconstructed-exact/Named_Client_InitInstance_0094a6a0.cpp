// =============================================================================
// Named_Client_InitInstance_0094a6a0  — legacy alias for Client_InitInstance
// -----------------------------------------------------------------------------
// Stable ID: aa_0094a6a0
// Address:   0x0094a6a0–0x0094b324
// Canonical: Client_InitInstance
// Sealed:    2026-07-29 W18-H dual A/B
// See:       Client_InitInstance.cpp + reviews A/B
// =============================================================================
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t /* width from decompiler */ Named_Client_InitInstance_0094a6a0(int param_1)

{

  char *pcVar1;

  LPCRITICAL_SECTION lpCriticalSection;

  uint8_t uVar2;

  char cVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  int iVar8;

  void *pvVar9;

  HANDLE hProcess;

  int *piVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ uVar12;

  char local_a14 [256];

  char local_914 [256];

  int local_814;

  uint8_t local_810;

  uint8_t local_80f;

  FILE *local_180;

  char acStack_179 [261];

  ULONG_PTR local_74;

  LPCRITICAL_SECTION local_70;

  ULONG_PTR local_6c;

  uint32_t /* width from decompiler */ *local_68;

  void *local_64;

  void *local_60;

  void *local_5c;

  void *local_58;

  uint32_t /* width from decompiler */ local_54;

  void *local_50;

  void *local_4c;

  void *local_48;

  void *local_44;

  void *local_40;

  void *local_3c;

  void *local_38;

  void *local_34;

  void *local_30;

  void *local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t local_24 [4];

  int *local_20;

  int *local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bbed0;

  local_10 = ExceptionList;

  local_18 = 0x94a6c3;

  local_14 = &stack0xffffd768;

  ExceptionList = &local_10;

  FUN_007a4400("Client InitInstance");

  local_8 = 0;

  if (*(int *)(param_1 + 0x3c10) != 0) {

    FUN_0048a780("LED_FX/LED_FX_startup.xml",*(int *)(param_1 + 0x3c10));

  }

  FUN_00932af0();

  FUN_00933a80();

  local_64 = operator_new(0x44);

  local_8._0_1_ = 1;

  if (local_64 == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_00573c10();

  }

  local_8._0_1_ = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x31ec) = uVar5;

  local_60 = operator_new(0x208);

  local_8._0_1_ = 2;

  if (local_60 == (void *)0x0) {

    puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_004c2460();

  }

  local_8._0_1_ = 0;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x31f0) = puVar6;

  *puVar6 = 0xffffffff;

  local_38 = operator_new(0x128);

  local_8._0_1_ = 3;

  if (local_38 == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_0092a670(local_38,param_1);

  }

  local_8._0_1_ = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4d0) = uVar5;

  local_58 = operator_new(0x28);

  local_8._0_1_ = 4;

  if (local_58 == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_009808d0(local_58);

  }

  local_8._0_1_ = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4ec) = uVar5;

  FUN_007a4480(0xffffffff,"before CVOGClonedObjectList");

  local_40 = operator_new(0x58);

  local_8._0_1_ = 5;

  if (local_40 == (void *)0x0) {

    DAT_00b04830 = 0;

  }

  else {

    DAT_00b04830 = FUN_004bbfb0(5,10);

  }

  local_8._0_1_ = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd34) = DAT_00b04830;

  FUN_007a4480(0xffffffff,"before NDCryptoInitialize");

  FUN_00799db0();

  FUN_007a4400("@@CoInitializeEx, Version, Ini, Keymap, colors");

  local_8._0_1_ = 6;

  CoInitializeEx((LPVOID)0x0,0);

  FUN_0092f960();

  FUN_0092f710(param_1);

  FUN_0092f580();

  local_8._0_1_ = 0;

  FUN_007a4390();

  FUN_007a4400("@@new CNDRenderEngine, load input DLL, CSoundManager");

  local_8._0_1_ = 7;

  local_5c = operator_new(0x2ec);

  local_8._0_1_ = 8;

  if (local_5c == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_007a26c0(local_5c);

  }

  local_8._0_1_ = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xde8) = uVar5;

  FUN_0092dbb0();

  local_48 = operator_new(0x14);

  local_8._0_1_ = 9;

  if (local_48 == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_00799940();

  }

  local_8 = CONCAT31(local_8._1_3_,7);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc0) = uVar5;

  uVar7 = (uint)*(byte *)(param_1 + 0x9e6);

  Client_GetMissionCompleteAudioTable(uVar7);

  FUN_007242c0(uVar7);

  uVar2 = *(uint8_t *)(param_1 + 0x9e8);

  iVar8 = Client_GetMissionCompleteAudioTable();

  *(uint8_t *)(iVar8 + 0x25a) = uVar2;

  if (*(char *)(param_1 + 0x11) != '\0') {

    *(uint8_t *)(param_1 + 0x9e9) = 1;

  }

  uVar2 = *(uint8_t *)(param_1 + 0x9e9);

  iVar8 = Client_GetMissionCompleteAudioTable();

  *(uint8_t *)(iVar8 + 0x308) = uVar2;

  cVar3 = *(char *)(param_1 + 0x9e7);

  local_18 = CONCAT31(local_18._1_3_,cVar3);

  iVar8 = FUN_00720d40();

  if (cVar3 == '\0') {

    FUN_00720290(0xffffffff,1);

    FUN_00720180(0xffffffff,1);

  }

  lpCriticalSection = (LPCRITICAL_SECTION)(iVar8 + 0x158);

  local_70 = lpCriticalSection;

  EnterCriticalSection(lpCriticalSection);

  local_8._1_3_ = (uint3)(local_8 >> 8);

  *(uint8_t *)(iVar8 + 0x10) = (uint8_t)local_18;

  local_8._0_1_ = 7;

  LeaveCriticalSection(lpCriticalSection);

  local_50 = operator_new(0x5c);

  local_8._0_1_ = 0xb;

  if (local_50 == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_008218b0(local_50);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdec) = uVar5;

  PTR_FUN_00af31e0 = FUN_00802b70;

  PTR_FUN_00af31e4 = FUN_00802c80;

  DAT_00b035fc = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc0);

  local_8 = (uint)local_8._1_3_ << 8;

  FUN_007a4390();

  FUN_007a4400("@@new CVOGSectorMap");

  local_8 = CONCAT31(local_8._1_3_,0xc);

  pvVar9 = operator_new(0xe920);

  if (pvVar9 == (void *)0x0) {

    iVar8 = 0;

  }

  else {

    iVar8 = FUN_004d8a10();

  }

  *(int *)(param_1 + 0xe04) = iVar8;

  *(uint8_t *)(iVar8 + 0xe8b4) = *(uint8_t *)(param_1 + 0xa7);

  local_8 = local_8 & 0xffffff00;

  FUN_007a4390();

  FUN_007a4400("@@InitAssetManager and CNDAssetCatalog");

  local_8._0_1_ = 0xd;

  FUN_007a4480(0xffffffff,"InitAssetManager and CNDAssetCatalog");

  uVar12 = 0;

  uVar5 = FUN_007b6a20(0);

  FUN_007b75b0(uVar5,uVar12);

  puVar6 = operator_new(0x5c);

  local_8._0_1_ = 0xe;

  local_68 = puVar6;

  if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_00744a60(puVar6,0);

    *puVar6 = &PTR_FUN_00a983bc;

  }

  local_8 = CONCAT31(local_8._1_3_,0xd);

  piVar10 = (int *)(DAT_00d1f050 + 100);

  piVar4 = (int *)*piVar10;

  *piVar10 = (int)puVar6;

  if (piVar4 != (int *)0x0) {

    (**(code **)(*piVar4 + 4))(0);

  }

  if ((int *)*piVar10 != (int *)0x0) {

    (**(code **)(*(int *)*piVar10 + 4))(1);

  }

  puVar6 = (uint32_t /* width from decompiler */ *)

           __RTDynamicCast(piVar4,0,&assCatalog::RTTI_Type_Descriptor,

                           &CNDAssetCatalog::RTTI_Type_Descriptor,0);

  if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*puVar6)(1);

  }

  *(uint8_t *)(DAT_00d1f050 + 0x68) = 0;

  FUN_0075d5b0(0);

  local_8 = local_8 & 0xffffff00;

  FUN_007a4390();

  if (*(HWND *)(param_1 + 0x318c) != (HWND)0x0) {

    DestroyWindow(*(HWND *)(param_1 + 0x318c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x318c) = 0;

  FUN_007a4400("@@InitRenderEngine");

  local_8._0_1_ = 0x10;

  FUN_007a4480(0xffffffff,"InitRenderEngine");

  iVar8 = FUN_00948530();

  if (iVar8 != 0) {

    FUN_007a4480(1,"Failed to initialize your graphics card, exiting...");

                    /* WARNING: Subroutine does not return */

    _exit(1);

  }

  FUN_00934420();

  local_8._0_1_ = 0;

  FUN_007a4390();

  FUN_007a4400("@@m_pMap->WorldInitialize");

  local_8._0_1_ = 0x11;

  FUN_007a4480(0xffffffff,"before m_pMap->WorldInitialize");

  FUN_004d15c0(0);

  local_8 = (uint)local_8._1_3_ << 8;

  FUN_007a4390();

  pvVar9 = operator_new(0x34);

  if (pvVar9 == (void *)0x0) {

    _DAT_00b04220 = 0;

  }

  else {

    _DAT_00b04220 = CVOGHBList_ctor();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd38) = _DAT_00b04220;

  local_30 = operator_new(0xd20);

  local_8._0_1_ = 0x12;

  if (local_30 == (void *)0x0) {

    puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_008071c0(local_30);

  }

  local_8._0_1_ = 0;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x4f4) = puVar6;

  if (*(char *)((int)puVar6 + 0xd1d) == '\0') {

    (**(code **)*puVar6)(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4f4) = 0;

  }

  local_34 = operator_new(0x488);

  local_8._0_1_ = 0x13;

  if (local_34 == (void *)0x0) {

    local_1c = (int *)0x0;

  }

  else {

    local_1c = (int *)FUN_007b5dd0(local_34,0);

  }

  piVar4 = local_1c;

  local_8._0_1_ = 0;

  FUN_007a4400("@@splash screen");

  local_8 = CONCAT31(local_8._1_3_,0x14);

  iVar8 = *(int *)(*(int *)(param_1 + 0xde8) + 0x2c);

  local_20 = piVar4;

  if (piVar4[0x22] != 0) {

    FUN_00756be0(piVar4);

  }

  piVar4[0x22] = iVar8;

  FUN_004406e0();

  (**(code **)(*piVar4 + 0x28))("i_s_splash.xml");

  (**(code **)(*piVar4 + 0x180))();

  if (*(int *)(*(int *)(param_1 + 0xde8) + 0x128) != 0) {

    FUN_00753a50();

  }

  FUN_007545c0();

  local_8 = local_8 & 0xffffff00;

  FUN_007a4390();

  FUN_00404fa0();

  local_8._0_1_ = 0x15;

  (**(code **)(local_814 + 0x10))();

  local_180 = fopen("aa_dict_w.txt","rb");

  if (local_180 != (FILE *)0x0) {

    local_80f = 1;

    local_810 = 1;

    local_3c = operator_new(8);

    local_8._0_1_ = 0x16;

    if (local_3c == (void *)0x0) {

      uVar5 = 0;

    }

    else {

      uVar5 = FUN_0079d530();

    }

    local_8._0_1_ = 0x15;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3088) = uVar5;

    FUN_0079d7a0(&local_814);

    FUN_0079cb60();

    *(uint8_t *)(*(int *)(param_1 + 0x3088) + 4) = 1;

    *(uint8_t *)(*(int *)(param_1 + 0x3088) + 5) = 1;

    sprintf(local_914,"Bad words: %i in dictionary.\n",

            *(uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x3088));

    OutputDebugStringA(local_914);

  }

  (**(code **)(local_814 + 0x10))();

  local_180 = fopen("aa_dict_n.txt","rb");

  if (local_180 != (FILE *)0x0) {

    local_80f = 1;

    local_810 = 1;

    local_44 = operator_new(8);

    local_8._0_1_ = 0x17;

    if (local_44 == (void *)0x0) {

      uVar5 = 0;

    }

    else {

      uVar5 = FUN_0079d530();

    }

    local_8._0_1_ = 0x15;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x308c) = uVar5;

    FUN_0079d7a0(&local_814);

    FUN_0079cb60();

    *(uint8_t *)(*(int *)(param_1 + 0x308c) + 4) = 0;

    *(uint8_t *)(*(int *)(param_1 + 0x308c) + 5) = 1;

    sprintf(local_a14,"Bad names: %i in dictionary.\n",

            *(uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x308c));

    OutputDebugStringA(local_a14);

  }

  local_8._0_1_ = 0;

  FUN_00405000();

  FUN_007a4400("@@CNDAssetManager::PostInitialize()");

  local_8._0_1_ = 0x18;

  if (*(char *)(param_1 + 0x31f5) == '\0') {

    FUN_007b6a20();

  }

  local_8._0_1_ = 0;

  FUN_007a4390();

  FUN_007a4400("@@new CCloneBaseList");

  local_8 = CONCAT31(local_8._1_3_,0x19);

  FUN_007a4480(0xffffffff,"before clonebaselist");

  FUN_007b8010(param_1 + 0x1c0);

  FUN_007b7fb0(param_1 + 0x2c4);

  FUN_007b8070(param_1 + 0x3c8);

  DAT_00b04694 = *(uint8_t *)(param_1 + 0x4cc);

  DAT_00d1793c = DAT_00b04694;

  GetCurrentDirectoryA(0x103,acStack_179 + 1);

  pcVar11 = acStack_179;

  do {

    pcVar11 = (char *)((int)pcVar11 + 1);

  } while (*pcVar11 != '\0');

  if ((pcVar11[-1] != '\\') && (pcVar11[-1] != '/')) {

    pcVar11 = acStack_179;

    do {

      pcVar1 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar1 != '\0');

    *(uint16_t *)pcVar11 = DAT_00a2eb5c;

  }

  pcVar11 = acStack_179;

  do {

    pcVar1 = pcVar11 + 1;

    pcVar11 = pcVar11 + 1;

  } while (*pcVar1 != '\0');

  *(uint32_t /* width from decompiler */ *)pcVar11 = DAT_00a2eb58;

  FUN_007b7f50(acStack_179 + 1);

  local_8._0_1_ = 0x1a;

  local_4c = operator_new(0xf30);

  local_8._0_1_ = 0x1b;

  if (local_4c == (void *)0x0) {

    local_54 = 0;

  }

  else {

    local_54 = FUN_00542aa0(1,0,*(uint8_t *)(param_1 + 0x31f5),0);

  }

  local_8 = CONCAT31(local_8._1_3_,0x1a);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd30) = local_54;

  if (*(char *)(param_1 + 0x31f5) == '\0') {

    FUN_00519a30();

    FUN_00519660();

    Experience_EnsureCreatureXpTableLoaded_INFERRED();

    Experience_EnsureLevelTableLoaded_INFERRED();

    Experience_EnsureQuestXpTableLoaded_INFERRED();

    EnsureQuestCreditsLookupLoaded();

    EnsureQuestBaseCreditsLoaded();

    FUN_005197b0();

    FUN_005129b0();

    FUN_00512970();

  }

  local_8 = 0x19;

  FUN_007a4480(0xffffffff,"CloneBaselist finished");

  DAT_00b041fc = *(uint32_t /* width from decompiler */ *)(param_1 + 0xd30);

  FUN_00933650();

  if (*(int *)(*(int *)(param_1 + 0xde8) + 0x128) != 0) {

    FUN_00753a50();

  }

  FUN_007545c0();

  local_8 = local_8 & 0xffffff00;

  FUN_007a4390();

  FUN_007a4400("@@InitPhysics");

  local_8 = CONCAT31(local_8._1_3_,0x1d);

  iVar8 = *(int *)(param_1 + 0xe04);

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0xe6e0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0xe6e4) = 0;

  FUN_004cd7d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xd34));

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe4ec) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xd38);

  *(int *)(*(int *)(param_1 + 0xe04) + 0xe500) = param_1;

  *(uint8_t *)(*(int *)(param_1 + 0xe04) + 0x7e) = 0;

  FUN_004cfca0();

  if (*(int *)(*(int *)(param_1 + 0xde8) + 0x128) != 0) {

    FUN_00753a50();

  }

  FUN_007545c0();

  local_8 = local_8 & 0xffffff00;

  FUN_007a4390();

  if (*(char *)(param_1 + 0x31f5) == '\0') {

    FUN_007a4400("@@m_pMap->InitGenerators");

    local_8 = CONCAT31(local_8._1_3_,0x1e);

    FUN_007a4480(0xffffffff,"before m_pMap->InitGenerators");

    FUN_004cd670();

    if (*(int *)(*(int *)(param_1 + 0xde8) + 0x128) != 0) {

      FUN_00753a50();

    }

    FUN_007545c0();

    local_8 = local_8 & 0xffffff00;

    FUN_007a4390();

  }

  FUN_007a4400("@@InitSound");

  local_8 = CONCAT31(local_8._1_3_,0x1f);

  FUN_007a4480(0xffffffff,"InitSound");

  FUN_00935110();

  if (*(int *)(*(int *)(param_1 + 0xde8) + 0x128) != 0) {

    FUN_00753a50();

  }

  FUN_007545c0();

  local_8 = local_8 & 0xffffff00;

  FUN_007a4390();

  FUN_0095c460();

  piVar4 = local_1c;

  FUN_00756be0(local_1c);

  (**(code **)*piVar4)(1);

  FUN_007b6a20();

  FUN_00989e00(local_24,"i_s_splash.dds");

  FUN_0075e2d0(local_24);

  FUN_007a4400("@@InitUserInterface");

  local_8._0_1_ = 0x20;

  FUN_007a4480(0xffffffff,"InitUserInterface");

  local_2c = operator_new(0x1c);

  local_8._0_1_ = 0x21;

  if (local_2c == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_009772c0();

  }

  local_8 = CONCAT31(local_8._1_3_,0x20);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4f0) = uVar5;

  FUN_0094a580();

  if (*(int *)(*(int *)(param_1 + 0xde8) + 0x128) != 0) {

    FUN_00753a50();

  }

  FUN_007545c0();

  local_8 = local_8 & 0xffffff00;

  FUN_007a4390();

  FUN_007a4400("@@Finish of InitInstance");

  local_8._0_1_ = 0x22;

  FUN_007a4480(0xffffffff,"InitInstance::done");

  local_28 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x990);

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0xd90));

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0xd98));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd88) = local_28;

  *(uint8_t *)(param_1 + 0xd80) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8c) = local_28;

  hProcess = GetCurrentProcess();

  GetProcessWorkingSetSize(hProcess,&local_74,&local_6c);

  *(uint8_t *)(param_1 + 0x13) = 1;

  local_8 = (uint)local_8._1_3_ << 8;

  FUN_007a4390();

  if (*(char *)(param_1 + 0x9d5) != '\0') {

    FUN_00933a10();

  }

  if (*(int *)(param_1 + 0x3c10) != 0) {

    FUN_0048a480(0);

    FUN_008060a0(0,0,5);

  }

  local_8 = 0xffffffff;

  FUN_007a4390();

  ExceptionList = local_10;

  return 1;

}

