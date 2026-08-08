// =============================================================================
// FUN_0051b310  (canonical: Object_ApplyMaterialBank_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b310
// Address:   0x0051b310–0x0051b34f  (autoassault.exe, image base 0x400000)
// System:    object / gfx material bank
// Generated: 2026-07-23 scaffold; **re-sealed 2026-08-04** dual A/B WQ9R-I
// Exactness: Behavior-preserving twin of Object_ApplyMaterialBank_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// =============================================================================

// PURPOSE: If material bank non-empty, apply bank → shader via FUN_005194f0.
// See Object_ApplyMaterialBank_Inferred.cpp for full sealed notes.

#include <cstdint>

extern "C" void FUN_005194f0(void *gfxMatHost, void *bankHeader);

using VGetGfxComponent = void *(__thiscall *)(void *self);

extern "C" void __fastcall FUN_0051b310(void *param_1)
{
  auto *base = reinterpret_cast<std::uint8_t *>(param_1);
  void *begin = *reinterpret_cast<void **>(base + 0x148);
  if (begin == nullptr) {
    return;
  }

  void *end = *reinterpret_cast<void **>(base + 0x14C);
  auto count = static_cast<std::intptr_t>(
      reinterpret_cast<std::uint8_t *>(end) - reinterpret_cast<std::uint8_t *>(begin)) >> 4;
  if (count == 0) {
    return;
  }

  auto **vtbl = *reinterpret_cast<void ***>(param_1);
  auto getGfx = *reinterpret_cast<VGetGfxComponent *>(
      reinterpret_cast<std::uint8_t *>(vtbl) + 0x1cc);
  void *component = getGfx(param_1);
  if (component == nullptr) {
    return;
  }

  void *gfxMatHost = *reinterpret_cast<void **>(
      reinterpret_cast<std::uint8_t *>(component) + 8);
  if (gfxMatHost == nullptr) {
    return;
  }

  FUN_005194f0(gfxMatHost, base + 0x144);
}
