// =============================================================================
// FUN_0048f2d0  (canonical twin of PalantirEnv_ApplyDefaultScalars_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f2d0
// Address:   0x0048f2d0  (autoassault.exe, image base 0x400000)
// System:    client / Palantir env host
// Generated: 2026-07-29 W32-Q dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See PalantirEnv_ApplyDefaultScalars_Inferred.cpp for named clean source.

#include <cstdint>

extern "C" float DAT_00aaa7ac;
extern "C" float DAT_00aaa884;
extern "C" float DAT_009c7748;
extern "C" float _DAT_009c774c;
extern "C" float g_flOne;
extern "C" uint32_t __fastcall FUN_00497c80(void *child);

extern "C" void __fastcall FUN_0048f2d0(void *param_1)
{
  void *child = *reinterpret_cast<void **>(static_cast<char *>(param_1) + 0x100);
  if (child != nullptr) {
    FUN_00497c80(child);
  }

  *reinterpret_cast<float *>(static_cast<char *>(param_1) + 0x10c) = DAT_00aaa7ac;
  *reinterpret_cast<float *>(static_cast<char *>(param_1) + 0x110) = DAT_00aaa884;

  float *bank = reinterpret_cast<float *>(static_cast<char *>(param_1) + 0x60);
  bank[0] = _DAT_009c774c;
  bank[1] = DAT_009c7748;
  bank[2] = DAT_009c7748;
  bank[3] = g_flOne;

  *reinterpret_cast<uint32_t *>(static_cast<char *>(param_1) + 0x178) = 0;
}
