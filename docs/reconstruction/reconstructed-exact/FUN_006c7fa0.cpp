// =============================================================================
// FUN_006c7fa0  (twin of PhysicsShape_Sphere_CtorFromRadius_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7fa0
// Address:   0x006c7fa0  (autoassault.exe, image base 0x400000)
// System:    interaction-activation / physics sphere shape
// Generated: 2026-08-05 MEGA-071 dual seal (was 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical name: PhysicsShape_Sphere_CtorFromRadius_Inferred
// =============================================================================

#include <cstdint>

extern "C" void *PTR_FUN_00a0d610[];

// __thiscall: ECX = this; stack float; RET 4; EAX = this
extern "C" void *__thiscall FUN_006c7fa0(void *self, float radius)
{
  *reinterpret_cast<std::uint16_t *>(reinterpret_cast<std::uint8_t *>(self) + 6) =
      1;
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(self) + 8) =
      0;
  *reinterpret_cast<float *>(reinterpret_cast<std::uint8_t *>(self) + 0xc) =
      radius;
  *reinterpret_cast<void ***>(self) = PTR_FUN_00a0d610;
  return self;
}
