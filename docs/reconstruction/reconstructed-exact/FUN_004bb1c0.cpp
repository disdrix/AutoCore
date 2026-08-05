// =============================================================================
// FUN_004bb1c0 — scaffold alias for Object_ResolveCoidVtbl1e8_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb1c0
// Address:   0x004bb1c0–0x004bb1e9  (autoassault.exe, image base 0x400000)
// Canonical: Object_ResolveCoidVtbl1e8_Inferred.cpp
// Generated: 2026-07-23 scaffold; sealed 2026-07-29 dual A/B W18-T
// =============================================================================

#include <cstdint>

extern "C" void * __thiscall CVOGReaction_ResolveObjectTarget(
    void *ctx,
    std::uint32_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi);

// Scaffold entry keeps Ghidra name; body matches sealed clean.
extern "C" void * __thiscall FUN_004bb1c0(
    void *ctx,
    std::uint32_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi)
{
  void *obj = CVOGReaction_ResolveObjectTarget(ctx, bGlobal, coidLo, coidHi);
  if (obj == nullptr) {
    return nullptr;
  }
  using VFn = void *(__thiscall *)(void *self);
  auto *vtbl = *reinterpret_cast<std::uint8_t **>(obj);
  auto fn = *reinterpret_cast<VFn *>(vtbl + 0x1e8);
  return fn(obj);
}
