// =============================================================================
// FUN_006c6c50  — twin of CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006c6c50
// Address:   0x006c6c50–0x006c6c98 inclusive (73 B / 0x49)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation / CVOGPhysicsUtils area-query filter gate
// Generated: 2026-08-05 MEGA-039 dual seal (machine-name twin)
// Canonical: docs/reconstruction/reconstructed-exact/
//            CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.cpp
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Ghidra symbol twin — prefer the named clean source for ports.
// ABI: __thiscall ECX=this; stack out*, a, b; RET 0xC; leaf.

#include <cstdint>

extern "C" void __thiscall FUN_006c6c50(
    void *self,
    std::uint8_t *out,
    std::uint32_t object_type,
    std::uint32_t filter_flags)
{
  if ((((object_type ^ filter_flags) & 0xffff0000u) == 0) &&
      ((object_type & 0xffff0000u) != 0)) {
    *out = 0;
    return;
  }

  const std::uint32_t row = object_type & 0x1fu;
  const std::uint32_t bit = filter_flags & 0x1fu;
  const auto *base = reinterpret_cast<const std::uint8_t *>(self);
  const std::uint32_t dword =
      *reinterpret_cast<const std::uint32_t *>(base + 0x1c + row * 4);
  *out = (dword & (1u << bit)) != 0 ? 1 : 0;
}
