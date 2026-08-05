// =============================================================================
// PalantirEnv_TearDefaultLights_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0048eb10
// Address:   0x0048eb10-0x0048eb99 exclusive (137 B / 0x89)
// System:    client / Palantir env default lights
// Generated: 2026-07-29 W34-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Tear (destroy) the default light pair on the Palantir env host:
//   - hemispheric light @ env+0x104
//   - directional light @ env+0x108
// For each: unregister effect core at light+0x8c via manager at env+4, scalar-
// deleting dtor(1), null the slot. Directional path also clears mgr attach via
// FUN_0074e0d0(mgr, 0). If Reflect child env+0xC4 is live, tail to FUN_005b3580
// (tears reflect+0x150). Rebuild peer: PalantirEnv_RebuildDefaultLights_Inferred
// (0x0048f370, W32-R) calls this as prelude.
// Reject scaffold Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0048eb10.
//

#include <cstdint>

extern "C" void __thiscall FUN_0074e260(void *mgr, void *effectCore);
extern "C" void __thiscall FUN_0074e0d0(void *mgr, void *arg /* 0 */);
extern "C" void __thiscall FUN_005b3580(void *reflect);

// __thiscall; ECX=env*; bare RET; void
void __thiscall PalantirEnv_TearDefaultLights_Inferred(void *env)
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
    FUN_005b3580(reflect); // bytes: ECX=reflect; tail-jmp
    return;
  }
}
