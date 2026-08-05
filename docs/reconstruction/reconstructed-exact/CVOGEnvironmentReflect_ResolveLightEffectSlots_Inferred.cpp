// =============================================================================
// CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred  (was FUN_005b3520)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3520
// Address:   0x005b3520  (autoassault.exe, image base 0x400000)
// Body:      0x005b3520–0x005b357a inclusive (91 bytes / 0x5B)
// System:    client / CVOGEnvironmentReflect (RTTI Confirmed W32-T)
// Generated: 2026-08-04 W37-F dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED
//
// Dual: reviews/A|B_aa_005b3520_CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.md
// Host RTTI: CVOGEnvironmentReflect (ctor FUN_005b35a0 / enable FUN_005b39a0)
// =============================================================================

#include <cstdint>

// Refcount-bind resource onto aux host (thiscall). Unowned callee.
extern std::uint32_t __thiscall FUN_0074e310(void* aux, void* resource);

// Once-only resolve of nested light effect cores into Reflect slots:
//   self+0x154 ← dir light (host+0x108) effect core (+0x8c)
//   self+0x150 ← hemi light (host+0x104) effect core (+0x8c)
//   FUN_0074e310(self+4, hemi_core)
// Nested host = *(self+0x15c)  then  *(parent+0xe894)  (Palantir light table host family).
//
// Byte gate: enter only when self+0x154==0 && host+0x108!=0 && host+0x104==0.
// After full RebuildDefaultLights (both lights non-null) this is a no-op.
// Residual: hemi-null gate then hemi load — keep faithful; do not invent !=0.
void __thiscall CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred(void* self)
{
  auto* base = reinterpret_cast<std::uint8_t*>(self);

  if (*reinterpret_cast<void**>(base + 0x154) != nullptr) {
    return;
  }

  void* parent = *reinterpret_cast<void**>(base + 0x15c);
  auto* parent_b = reinterpret_cast<std::uint8_t*>(parent);
  void* light_host = *reinterpret_cast<void**>(parent_b + 0xe894);
  auto* host = reinterpret_cast<std::uint8_t*>(light_host);

  if (*reinterpret_cast<void**>(host + 0x108) == nullptr) {
    return;
  }

  // Bytes: JNZ ret when host+0x104 != 0
  if (*reinterpret_cast<void**>(host + 0x104) != nullptr) {
    return;
  }

  void* dir_light = *reinterpret_cast<void**>(host + 0x108);
  *reinterpret_cast<void**>(base + 0x154) =
      *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(dir_light) + 0x8c);

  // Reload light host (bytes re-walk parent+0xe894)
  light_host = *reinterpret_cast<void**>(parent_b + 0xe894);
  host = reinterpret_cast<std::uint8_t*>(light_host);
  void* hemi_light = *reinterpret_cast<void**>(host + 0x104);
  void* hemi_core =
      *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(hemi_light) + 0x8c);
  *reinterpret_cast<void**>(base + 0x150) = hemi_core;

  void* aux = *reinterpret_cast<void**>(base + 4);
  FUN_0074e310(aux, hemi_core);
}
