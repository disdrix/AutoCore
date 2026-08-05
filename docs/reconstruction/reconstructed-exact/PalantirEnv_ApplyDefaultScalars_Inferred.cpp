// =============================================================================
// PalantirEnv_ApplyDefaultScalars_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f2d0
// Address:   0x0048f2d0  (autoassault.exe, image base 0x400000)
// System:    client / Palantir env host
// Generated: 2026-07-29 W32-Q dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: After env child@+0x100 is installed (or on re-apply), optionally
// prepare/reset that child, then write sealed default scalars into the 0x198
// Palantir env host: range-like 100/200 at +0x10c/+0x110, float bank at
// +0x60..+0x6c, clear +0x178.
//
// Callers: PalantirEnv_Ctor_Inferred (0x00492dd0) tail; orphan site 0x004d966b
// loads env from parent+0xE894.

#include <cstdint>

extern "C" float DAT_00aaa7ac;   // 100.0f @ 0x00aaa7ac
extern "C" float DAT_00aaa884;   // 200.0f @ 0x00aaa884
extern "C" float DAT_009c7748;   // ~0.254894f @ 0x009c7748
extern "C" float _DAT_009c774c;  // ~0.215646f @ 0x009c774c
extern "C" float g_flOne;        // 1.0f @ 0x00a0f2a0

// Child prepare/reset (thiscall on object at env+0x100)
extern "C" uint32_t __fastcall FUN_00497c80(void *child);

extern "C" void __fastcall PalantirEnv_ApplyDefaultScalars_Inferred(void *env)
{
  void *child = *reinterpret_cast<void **>(static_cast<char *>(env) + 0x100);
  if (child != nullptr) {
    FUN_00497c80(child);
  }

  *reinterpret_cast<float *>(static_cast<char *>(env) + 0x10c) = DAT_00aaa7ac;
  *reinterpret_cast<float *>(static_cast<char *>(env) + 0x110) = DAT_00aaa884;

  float *bank = reinterpret_cast<float *>(static_cast<char *>(env) + 0x60);
  bank[0] = _DAT_009c774c;
  bank[1] = DAT_009c7748;
  bank[2] = DAT_009c7748;
  bank[3] = g_flOne;

  *reinterpret_cast<uint32_t *>(static_cast<char *>(env) + 0x178) = 0;
}
