// =============================================================================
// FUN_0073d8d0 — twin of EffEffectFactory_OnDeviceLost_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d8d0
// Address:   0x0073d8d0  (autoassault.exe, image base 0x400000)
// Body:      103 B / 0x67
// System:    graphics / Effects
// Generated: 2026-08-04 W38-V from raw + live re-verify
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named clean: EffEffectFactory_OnDeviceLost_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void FUN_0074f0c0(void);
extern "C" void FUN_00752640(void);
extern "C" uint8_t* DAT_00d1f048;
extern "C" uint32_t* DAT_00d1f044;

// Register formal: EAX = factory host*.
// Modeled as explicit arg for compilability of reconstruction text.
extern "C" void FUN_0073d8d0(uint8_t* host /* EAX */)
{
  int end = *reinterpret_cast<int*>(host + 8);
  for (int entry = *reinterpret_cast<int*>(host + 4); entry != end; entry += 0x14) {
    // ESI = *(int*)entry — set by call-site bytes before FUN_0074f0c0
    (void)entry;
    FUN_0074f0c0();
    int p_end = *reinterpret_cast<int*>(entry + 0x0C);
    for (int p = *reinterpret_cast<int*>(entry + 8); p != p_end; p += 4) {
      // EBX = *(int*)p — set by call-site bytes before FUN_00752640
      (void)p;
      FUN_00752640();
    }
  }

  *(uint8_t*)(DAT_00d1f048 + 0x0C) = 0;

  if (DAT_00d1f044[0x1df] == 1) {
    int* iface = reinterpret_cast<int*>(*reinterpret_cast<void**>(DAT_00d1f044));
    int* vtbl = reinterpret_cast<int*>(iface[0]);
    using Fn = void(__stdcall*)(int*, uint32_t);
    auto* slot = reinterpret_cast<Fn*>(reinterpret_cast<uint8_t*>(vtbl) + 0x134);
    (*slot)(iface, 0);
  }
}
