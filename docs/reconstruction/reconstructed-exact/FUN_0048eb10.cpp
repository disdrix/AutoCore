// =============================================================================
// FUN_0048eb10  (alias clean twin)
// Canonical: PalantirEnv_TearDefaultLights_Inferred
// Stable ID: aa_0048eb10
// Address:   0x0048eb10-0x0048eb99 exclusive (137 B / 0x89)
// Wave:      W34-T 2026-07-29
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0074e260(void *mgr, void *effectCore);
extern "C" void __thiscall FUN_0074e0d0(void *mgr, void *arg);
extern "C" void __thiscall FUN_005b3580(void *reflect);

void __thiscall FUN_0048eb10(void *env)
{
  auto *e = reinterpret_cast<uint8_t *>(env);
  void *mgr = *reinterpret_cast<void **>(e + 4);

  void *hemi = *reinterpret_cast<void **>(e + 0x104);
  if (hemi != nullptr) {
    void *core = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(hemi) + 0x8c);
    FUN_0074e260(mgr, core);
    if (*reinterpret_cast<void **>(e + 0x104) != nullptr) {
      using Dtor1 = void(__thiscall *)(void *, int);
      (*reinterpret_cast<Dtor1 **>(hemi))[0](hemi, 1);
    }
    *reinterpret_cast<void **>(e + 0x104) = nullptr;
  }

  void *dir = *reinterpret_cast<void **>(e + 0x108);
  if (dir != nullptr) {
    FUN_0074e0d0(mgr, nullptr);
    void *core = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(dir) + 0x8c);
    FUN_0074e260(mgr, core);
    if (*reinterpret_cast<void **>(e + 0x108) != nullptr) {
      using Dtor1 = void(__thiscall *)(void *, int);
      (*reinterpret_cast<Dtor1 **>(dir))[0](dir, 1);
    }
    *reinterpret_cast<void **>(e + 0x108) = nullptr;
  }

  void *reflect = *reinterpret_cast<void **>(e + 0xC4);
  if (reflect != nullptr) {
    FUN_005b3580(reflect);
    return;
  }
}
