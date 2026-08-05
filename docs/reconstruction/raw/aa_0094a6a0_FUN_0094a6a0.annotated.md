# Annotated low-level: Client_InitInstance

| Field | Value |
|---|---|
| Stable ID | `aa_0094a6a0` |
| VA | `0x0094a6a0`–`0x0094b324` |
| System | `client-boot` / InitInstance |
| Date | 2026-07-29 (W18-H) |

## Machine-level notes

- **Large worker** (~3.2 KB body). EBP frame + SEH (`LAB_009bbed0`).
- **ABI:** one stack arg = client application / game object (`param_1`). Exit **`RET 4`** → **`__stdcall`**.
- Sole static caller: `FUN_0094ba40` (developer-mode client entry after mutex / fonts) passes `&DAT_00d1a840`.
- Returns **1** on success. Graphics init failure path **`_exit(1)`** (non-returning).
- Orchestrates subsystem bring-up in fixed string-marked phases (see raw phase map).
- Flag **`param_1+0x31f5`**: when set, skips heavy data ensures (XP/credits/loot/medal tables), map generators, and one asset post-init call — light/alternate boot.
- Clonebase construction always runs; table **ensure** batch is the gated portion.
- Installs many pointers on the client object and process globals (`DAT_00b04830`, `DAT_00b041fc`, asset catalog, etc.).
- Uses progress banners via `FUN_007a4400` / `FUN_007a4480` / `FUN_007a4390` and optional splash UI pump (`FUN_00753a50` / `FUN_007545c0`).

## Annotated phase skeleton

```c
// uint32_t __stdcall Client_InitInstance(ClientApp* app)
// Full CF in scaffold raw + clean Client_InitInstance.cpp

uint32_t Client_InitInstance(int app)
{
  // SEH setup …
  LogProgress("Client InitInstance");

  if (*(int*)(app + 0x3c10))
    LoadLedFx("LED_FX/LED_FX_startup.xml", *(int*)(app + 0x3c10));

  EarlyClientInit();                         // 00932af0, 00933a80
  app->slot_31ec = NewObject_0x44();         // FUN_00573c10
  app->slot_31f0 = NewObject_0x208();        // FUN_004c2460; *obj = -1
  app->slot_4d0  = NewObject_0x128(app);     // FUN_0092a670
  app->slot_4ec  = NewObject_0x28();         // FUN_009808d0

  Log("before CVOGClonedObjectList");
  DAT_00b04830 = NewClonedObjectList(5,10);  // FUN_004bbfb0
  app->slot_d34 = DAT_00b04830;

  Log("before NDCryptoInitialize"); NDCryptoInit();
  CoInitializeEx(0,0); VersionIniKeymapColors(app);

  Log("@@new CNDRenderEngine…");
  app->slot_de8 = NewRenderEngine();         // FUN_007a26c0
  LoadInputDll();
  app->slot_dc0 = NewSoundManager();         // FUN_00799940
  BindMissionCompleteAudioFromClientFlags(app);

  // … audio critical section on FUN_00720d40 object …

  app->slot_dec = NewObject_0x5c();          // FUN_008218b0
  InstallGfxHooks();                         // PTR_FUN_00af31e0/e4

  Log("@@new CVOGSectorMap");
  app->slot_e04 = NewSectorMap_0xe920();     // FUN_004d8a10
  app->slot_e04->flag_e8b4 = app->byte_a7;

  Log("@@InitAssetManager and CNDAssetCatalog");
  NDXml_GetLoaderSingleton(); InitAssetPaths();
  InstallCNDAssetCatalog();                  // RTTI cast old catalog

  if (app->hwnd_318c) DestroyWindow(app->hwnd_318c);
  app->hwnd_318c = 0;

  Log("@@InitRenderEngine");
  if (InitRenderEngine() != 0) {
    LogFail("Failed to initialize your graphics card, exiting...");
    _exit(1);
  }

  Log("@@m_pMap->WorldInitialize"); WorldInitialize(0);

  app->slot_d38 = NewCVOGHBList();
  // splash UI object, dict files, …
  if (app->byte_31f5 == 0)
    NDXml_GetLoaderSingleton();              // post-init gated call

  Log("@@new CCloneBaseList");
  BuildCloneBaseLists(app);
  app->slot_d30 = NewCloneBaseListHost(…, app->byte_31f5, …);
  if (app->byte_31f5 == 0) {
    EnsureMedalTables();
    Experience_Ensure*Tables();
    EnsureQuestCreditsLookupLoaded();
    EnsureQuestBaseCreditsLoaded();
    EnsureLootTables…();
  }
  DAT_00b041fc = app->slot_d30;

  Log("@@InitPhysics"); InitPhysics(app);
  if (app->byte_31f5 == 0) {
    Log("@@m_pMap->InitGenerators"); InitGenerators();
  }
  Log("@@InitSound"); InitSound();
  // destroy splash; load splash.dds texture path
  Log("@@InitUserInterface"); app->slot_4f0 = NewUIRoot(); InitUI();

  Log("@@Finish of InitInstance");
  QueryPerformanceCounter(app+0xd90);
  QueryPerformanceCounter(app+0xd98);
  app->byte_d80 = 1;
  app->byte_13 = 1;
  // optional LED teardown if +0x3c10
  return 1;
}
```

## Open questions

1. Product C++ class name for `param_1` / `DAT_00d1a840` (client app singleton).
2. Exact English for flag `+0x31f5` (editor? headless? skip-data?).
3. Full product names for each allocated manager at slots (render/sound/map sealed by strings; mid-size objects Tentative).
4. Whether server AutoCore needs any of this client boot path (likely **no** — client-only).
5. Runtime order verification vs this phase map.

