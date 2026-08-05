// =============================================================================
// PalantirEnv_RebuildDefaultLights_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f370
// Address:   0x0048f370-0x0048f65f exclusive (751 B / 0x2EF)
// System:    client / Palantir env default lights
// Generated: 2026-07-29 W32-R dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Rebuild-safe method on the 0x198 Palantir env host (ECX = env*).
// Tears prior lights via FUN_0048eb10, then:
//   - directional light @ env+0x108 (new 0x94 + FUN_0096e4b0); Direction + Color
//   - hemispheric light @ env+0x104 (new 0x94 + FUN_0096e4b0); ColorTop + ColorBottom
// Called from PalantirEnv_InitPhases_Inferred prelude and two other env reload paths.
// Reject scaffold Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3_0048f370.

#include <cstdint>

extern "C" void  __thiscall FUN_0048eb10(void *env);
extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall FUN_0096e4b0(void *self);
extern "C" void  FUN_0096e430(void /* light this / optional type string via stack */);
extern "C" void  FUN_0074e310(void *effectCore);
extern "C" void  FUN_0074e0d0(void);
extern "C" void  FUN_0076f5f0(void);
extern "C" void  FUN_009733d0(void *argbOrOut);
extern "C" void  FUN_005b3520(void);

extern "C" float DAT_00aaa6d4; // -0.1f (dword 0xBDCCCCCD)
extern "C" float DAT_00aaa6cc; // -0.5f (dword 0xBF000000)
extern "C" float g_flOne;
extern "C" float DAT_00b03530;
extern "C" float DAT_00b03534;
extern "C" float DAT_00b03538;
extern "C" uint32_t DAT_00aef970;
extern "C" uint32_t DAT_00aef974;
extern "C" uint32_t DAT_00aef978;
extern "C" uint32_t DAT_00aef97c;
extern "C" uint32_t DAT_00aef980;
extern "C" uint32_t DAT_00aef984;
extern "C" uint32_t DAT_00aef988;
extern "C" uint32_t DAT_00aef98c;
extern "C" uint32_t DAT_00aef990;
extern "C" uint32_t DAT_00aef994;
extern "C" uint32_t DAT_00aef998;
extern "C" uint32_t DAT_00aef99c;

// __thiscall; ECX=env*; bare RET; void
void __thiscall PalantirEnv_RebuildDefaultLights_Inferred(void *env)
{
  auto *e = reinterpret_cast<uint8_t *>(env);
  void *raw;
  void *light;
  void *core;
  using Lookup = void *(__thiscall *)(void *, const char *);
  using Set4 = void(__thiscall *)(void *, void *, void *);
  using SetVec = void(__thiscall *)(void *, void *);

  // SEH LAB_009a0822
  FUN_0048eb10(env);

  // --- directional → +0x108 ---
  raw = operator_new(0x94);
  light = (raw == nullptr) ? nullptr : FUN_0096e4b0(raw);
  *reinterpret_cast<void **>(e + 0x108) = light;
  FUN_0096e430(); // first site: no stack type string in raw bytes
  core = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(light) + 0x8c);
  FUN_0074e310(core);
  FUN_0074e0d0();

  DAT_00b03530 = DAT_00aaa6d4; // -0.1f
  DAT_00b03534 = DAT_00aaa6cc; // -0.5f
  DAT_00b03538 = g_flOne;      // 1.0f
  FUN_0076f5f0();

  {
    auto **vt = *reinterpret_cast<void ***>(
        *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(light) + 0x8c));
    void *handle = reinterpret_cast<Lookup>(vt[0x40 / 4])(
        *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(light) + 0x8c),
        "Direction");
    (void)handle;
    reinterpret_cast<SetVec>(vt[0x50 / 4])(
        *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(light) + 0x8c),
        &DAT_00b03530);
  }

  // Color path: FUN_009733d0 expands packed color → DAT_00aef970 float4; set "Color"
  FUN_009733d0(nullptr); // stack temp in retail; decompiler stack alias
  {
    auto *l = *reinterpret_cast<uint8_t **>(e + 0x108);
    auto *fx = *reinterpret_cast<void **>(l + 0x8c);
    auto **vt = *reinterpret_cast<void ***>(fx);
    void *h = reinterpret_cast<Lookup>(vt[0x40 / 4])(fx, "Color");
    reinterpret_cast<Set4>(vt[0x4c / 4])(fx, h, &DAT_00aef970);
    auto *pi = reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(fx) + 0xdc);
    *pi = *pi + 1;
    *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(fx) + 0xd0) = 1;
  }

  // --- hemispheric → +0x104 ---
  raw = operator_new(0x94);
  light = (raw == nullptr) ? nullptr : FUN_0096e4b0(raw);
  *reinterpret_cast<void **>(e + 0x104) = light;
  // retail: FUN_0096e430("Hemispheric") with light this
  FUN_0096e430();

  {
    auto *l = *reinterpret_cast<uint8_t **>(e + 0x104);
    auto *fx = *reinterpret_cast<void **>(l + 0x8c);
    auto **vt = *reinterpret_cast<void ***>(fx);
    // ColorTop / ColorBottom from ARGB 0xFF707B8F / 0xFFD1A56D (+ 0xFF3E2F2D path)
    FUN_009733d0(nullptr);
    void *hTop = reinterpret_cast<Lookup>(vt[0x40 / 4])(fx, "ColorTop");
    reinterpret_cast<Set4>(vt[0x4c / 4])(fx, hTop, &DAT_00aef980);
    void *hBot = reinterpret_cast<Lookup>(vt[0x40 / 4])(fx, "ColorBottom");
    reinterpret_cast<Set4>(vt[0x4c / 4])(fx, hBot, &DAT_00aef990);
    FUN_0074e310(fx);
    auto *pi = reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(fx) + 0xdc);
    *pi = *pi + 1;
    *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(fx) + 0xd0) = 1;
  }

  if (*reinterpret_cast<int *>(e + 0xC4) != 0) {
    FUN_005b3520();
  }
}
