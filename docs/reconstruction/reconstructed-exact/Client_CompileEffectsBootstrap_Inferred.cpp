// =============================================================================
// Client_CompileEffectsBootstrap_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00948bd0
// Address:   0x00948bd0–0x009492c7  (autoassault.exe, image base 0x400000)
// System:    client / -compileeffects tool path
// Generated: 2026-07-23 scaffold as Drive_NDRiver_fx; dual A/B seal 2026-07-29 (W31-H)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Sole caller FUN_0094ba40: only when cmdline contains "-compileeffects" (after
 *   "-developer" gate); then process exits. This is the effect-compile bootstrap,
 *   not general client game entry (Client_InitInstance is 0x0094a6a0).
 * - Retail ABI: ESI = client host; bare RET (C3); void.
 * - Stages: new(0x2ec) helper @ +0xde8 → AssManager flags=3 + init mode=1
 *   → RegisterClass/CreateWindow "XutoAssault"/"Auto Assault" → HWND @ +0x3188
 *   → RenderEngine init → ShowWindow(SW_HIDE) → 36× FX string load.
 * - Reject scaffold Drive_NDRiver_fx (single FX name, not purpose).
 * - Nested AssManager dual sealed W30-D.
 */

#include <cstdint>
#include <windows.h>

struct ClientHost {
  // +0xde8: helper object*
  // +0x3180: HINSTANCE
  // +0x3188: HWND
  uint8_t pad[0xde8];
  void* helper_0x2ec; // +0xde8
  // ... gap to 0x3180 ...
};

// Unowned nested
extern "C" void* operator_new(uint32_t);
extern "C" void* FUN_007a26c0(void* mem);
extern "C" void* FUN_007b6a20(/* optional arg in decompile */);
extern "C" void AssManager_InitPrecompileAndResolvers_Inferred(void* self, char mode); // 0x007b75b0
extern "C" int FUN_007a3e90(HWND hwnd, void* dims, int, int, int);
extern "C" void FUN_00989e00(void* slot, const char* fxName);
extern "C" void FUN_009701d0(void* slot);
extern "C" void FUN_007a4480(int level, const char* msg);

// Retail: ESI = client host; void; bare RET
extern "C" void Client_CompileEffectsBootstrap_Inferred(void* self /*ESI*/)
{
  void* mem = operator_new(0x2ec);
  void* helper = (mem != nullptr) ? FUN_007a26c0(mem) : nullptr;
  // *(self+0xde8) = helper
  *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0xde8) = helper;

  void* mgr = FUN_007b6a20();
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(mgr) + 4) = 3;
  void* mgr2 = FUN_007b6a20(); // decompile shows second call with 1
  AssManager_InitPrecompileAndResolvers_Inferred(mgr2, /*mode=*/1);

  HINSTANCE hInst = *reinterpret_cast<HINSTANCE*>(
      reinterpret_cast<uint8_t*>(self) + 0x3180);

  WNDCLASSA wc{};
  wc.style = 0x302b;
  wc.lpfnWndProc = reinterpret_cast<WNDPROC>(0x009484d0); // LAB_009484d0
  wc.hInstance = hInst;
  wc.hIcon = LoadIconA(hInst, MAKEINTRESOURCEA(0x65));
  wc.lpszClassName = "XutoAssault";
  ATOM atom = RegisterClassA(&wc);
  HWND* pHwnd = reinterpret_cast<HWND*>(
      reinterpret_cast<uint8_t*>(self) + 0x3188);
  if (atom != 0) {
    *pHwnd = CreateWindowExA(0x40000, "XutoAssault", "Auto Assault", 0xca0000,
                             0x14, 0x14, 0x20, 0x20,
                             nullptr, nullptr, hInst, nullptr);
  }
  if (*pHwnd == nullptr) {
    FUN_007a4480(1, "Failed to CreateWindowEx!");
    return;
  }

  UpdateWindow(*pHwnd);
  uint32_t dims[2] = {0x18, 0x20}; // height 24, width 32 (decompile local order)
  // decompile: local_cc=0x20, local_d0=0x18; pass &local_cc
  if (FUN_007a3e90(*pHwnd, &dims[0], 0, 0, 0) == 0) {
    FUN_007a4480(1, "Failed to initialize the RenderEngine!");
    return;
  }

  ShowWindow(*pHwnd, SW_HIDE);

  // 36× FX preload (order sealed in raw decompile)
  static const char* kFx[] = {
      "NDBiomekCar.fx", "NDBog.fx", "NDCyborgCharacter.fx",
      "NDDiffAlphaParticle.fx", "NDDiffAlphaParticleBright.fx",
      "NDDiffAlphaParticleBrightSkybox.fx", "NDDiffAlphaParticleGlow.fx",
      "NDDiffAlphaParticleSkybox.fx", "NDDiffAlphaParticleTerrain.fx",
      "NDDiffMapRoad.fx", "NDDiffTerrainBasic.fx", "NDDiffTerrainLayered.fx",
      "NDDiffTerrainLayered2.fx", "NDHumanCar.fx", "NDHumanCharacter.fx",
      "NDLeaf.fx", "NDMutantCar.fx", "NDMutantCharacter.fx", "NDMutantTown.fx",
      "NDPhaseform.fx", "NDRiver.fx", "NDTacArc.fx", "NDTree.fx",
      "NDTreeBillboard.fx", "NDVegetation.fx", "NDXosen.fx",
      "PalDiffGlossMapEnvMap.fx", "PalDiffMap.fx", "PalDiffMapFresnel.fx",
      "PalDiffMapNorGlossMapEnvMap.fx", "PalDiffMapNorGlossMapEnvMapCorrect.fx",
      "PalDiffMapNorGlossMapEnvMapGlow.fx", "PalDiffMapNorMap.fx",
      "PalDiffMapNorSpecGlossMap.fx", "PalDiffMapNorSpecGlossMapGlow.fx",
      "PalDiffMapVertColor.fx",
  };
  uint8_t slots[36][4];
  for (int i = 0; i < 36; ++i) {
    FUN_00989e00(slots[i], kFx[i]);
    FUN_009701d0(slots[i]);
  }
}
