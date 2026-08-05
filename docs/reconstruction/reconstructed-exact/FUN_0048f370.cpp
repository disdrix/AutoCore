// =============================================================================
// FUN_0048f370  (twin of PalantirEnv_RebuildDefaultLights_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f370
// Address:   0x0048f370-0x0048f65f exclusive (751 B / 0x2EF)
// System:    client / Palantir env default lights
// Generated: 2026-07-29 W32-R dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Named twin: PalantirEnv_RebuildDefaultLights_Inferred.cpp
// Reject: Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3_0048f370

#include <cstdint>

extern "C" void  __thiscall FUN_0048eb10(void *env);
extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall FUN_0096e4b0(void *self);
extern "C" void  FUN_0096e430(void);
extern "C" void  FUN_0074e310(void *effectCore);
extern "C" void  FUN_0074e0d0(void);
extern "C" void  FUN_0076f5f0(void);
extern "C" void  FUN_009733d0(void *argbOrOut);
extern "C" void  FUN_005b3520(void);

extern "C" float DAT_00aaa6d4;
extern "C" float DAT_00aaa6cc;
extern "C" float g_flOne;
extern "C" float DAT_00b03530;
extern "C" float DAT_00b03534;
extern "C" float DAT_00b03538;
extern "C" uint32_t DAT_00aef970;
extern "C" uint32_t DAT_00aef980;
extern "C" uint32_t DAT_00aef990;

// __thiscall; ECX=param_1 env*; bare RET; void
void __fastcall FUN_0048f370(int param_1)
{
  auto *e = reinterpret_cast<uint8_t *>(param_1);
  void *raw;
  void *light;
  using Lookup = void *(__thiscall *)(void *, const char *);
  using Set4 = void(__thiscall *)(void *, void *, void *);
  using SetVec = void(__thiscall *)(void *, void *);

  FUN_0048eb10(reinterpret_cast<void *>(param_1));

  raw = operator_new(0x94);
  light = (raw == nullptr) ? nullptr : FUN_0096e4b0(raw);
  *reinterpret_cast<void **>(e + 0x108) = light;
  FUN_0096e430();
  FUN_0074e310(*reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(light) + 0x8c));
  FUN_0074e0d0();

  DAT_00b03530 = DAT_00aaa6d4;
  DAT_00b03534 = DAT_00aaa6cc;
  DAT_00b03538 = g_flOne;
  FUN_0076f5f0();

  {
    auto *fx = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(light) + 0x8c);
    auto **vt = *reinterpret_cast<void ***>(fx);
    reinterpret_cast<Lookup>(vt[0x40 / 4])(fx, "Direction");
    reinterpret_cast<SetVec>(vt[0x50 / 4])(fx, &DAT_00b03530);
    FUN_009733d0(nullptr);
    void *h = reinterpret_cast<Lookup>(vt[0x40 / 4])(fx, "Color");
    reinterpret_cast<Set4>(vt[0x4c / 4])(fx, h, &DAT_00aef970);
    auto *pi = reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(fx) + 0xdc);
    *pi = *pi + 1;
    *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(fx) + 0xd0) = 1;
  }

  raw = operator_new(0x94);
  light = (raw == nullptr) ? nullptr : FUN_0096e4b0(raw);
  *reinterpret_cast<void **>(e + 0x104) = light;
  FUN_0096e430(); // retail stack: "Hemispheric"

  {
    auto *fx = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(light) + 0x8c);
    auto **vt = *reinterpret_cast<void ***>(fx);
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
