// =============================================================================
// FUN_0073d870 — twin of EffEffectFactory_OnDeviceReset_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d870
// Address:   0x0073d870  (autoassault.exe, image base 0x400000)
// Body:      82 B / 0x52
// System:    graphics / Effects
// Generated: 2026-08-04 W38-V from raw + live re-verify
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named clean: EffEffectFactory_OnDeviceReset_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" uint32_t FUN_007525f0(void);

// Register formal: EAX = factory host*.
// Modeled as explicit arg for compilability of reconstruction text.
extern "C" uint32_t FUN_0073d870(uint8_t* host /* EAX */)
{
  int* end = *reinterpret_cast<int**>(host + 8);
  for (int* entry = *reinterpret_cast<int**>(host + 4); entry != end; entry += 5) {
    int* obj = reinterpret_cast<int*>(entry[0]);
    if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(obj) + 0x0C) != 0) {
      int* child = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(obj) + 0x0C);
      int* vtbl = reinterpret_cast<int*>(child[0]);
      using Fn = void(__stdcall*)(int*);
      auto* slot = reinterpret_cast<Fn*>(reinterpret_cast<uint8_t*>(vtbl) + 0x118);
      (*slot)(child);
    }
    int inner_end = entry[3];
    for (int inner = entry[2]; inner != inner_end; inner += 4) {
      // EDI = *(int*)inner — set by call-site bytes before FUN_007525f0
      (void)inner;
      FUN_007525f0();
    }
  }
  return 0;
}
