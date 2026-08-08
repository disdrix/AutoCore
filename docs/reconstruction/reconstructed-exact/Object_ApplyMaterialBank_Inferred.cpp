// =============================================================================
// Object_ApplyMaterialBank_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b310
// Address:   0x0051b310–0x0051b34f  (autoassault.exe, image base 0x400000)
// System:    object / gfx material bank
// Generated: 2026-07-23 scaffold as FUN_0051b310; **sealed 2026-08-04** dual A/B WQ9R-I
// Exactness: Behavior-preserving. Offsets/stride/vcall sealed from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// =============================================================================

/*
 * Behavioral notes (2026-08-04 seal):
 * - thiscall: ECX = object* (SharedBase-like; vtbl at [this]).
 * - Material bank header at this+0x144; active range begin@+0x148 end@+0x14C;
 *   element stride 0x10 (SAR 4). Empty/null begin → no-op.
 * - If non-empty: vcall vtbl+0x1CC → gfx/material component*.
 *   If component non-null and component+8 non-null:
 *     FUN_005194f0(component+8, this+0x144)
 *     — commits bank entries to shader params MatDiffuse/Ambient/Emissive
 *       (callee not owned by this dual; seals argument order only).
 * - Sibling (not owned): FUN_0051b2a0 @ 0x0051b2a0 is the *empty-bank fill*
 *   path (same vector + vtbl+0x1CC, callee FUN_00519280). Adjacent vtbl slots.
 * - Preserves ECX across body (PUSH ECX / POP ECX); PUSH ESI for bank base.
 * - cdecl callee FUN_005194f0 cleaned with ADD ESP,8; bare RET.
 */

#include <cstdint>

// Nested callees — not dual-owned by this unit.
extern "C" void FUN_005194f0(void *gfxMatHost /* component+8 */, void *bankHeader /* this+0x144 */);

using VGetGfxComponent = void *(__thiscall *)(void *self);

extern "C" void __fastcall Object_ApplyMaterialBank_Inferred(void *self)
{
  // Assembly: PUSH ECX; material begin = *(this+0x148)
  auto *base = reinterpret_cast<std::uint8_t *>(self);
  void *begin = *reinterpret_cast<void **>(base + 0x148);
  if (begin == nullptr) {
    return;
  }

  // end = *(this+0x14C); count = (end-begin) >> 4
  void *end = *reinterpret_cast<void **>(base + 0x14C);
  auto count = static_cast<std::intptr_t>(
      reinterpret_cast<std::uint8_t *>(end) - reinterpret_cast<std::uint8_t *>(begin)) >> 4;
  if (count == 0) {
    return;
  }

  auto **vtbl = *reinterpret_cast<void ***>(self);
  auto getGfx = *reinterpret_cast<VGetGfxComponent *>(
      reinterpret_cast<std::uint8_t *>(vtbl) + 0x1cc);
  void *component = getGfx(self);
  if (component == nullptr) {
    return;
  }

  void *gfxMatHost = *reinterpret_cast<void **>(
      reinterpret_cast<std::uint8_t *>(component) + 8);
  if (gfxMatHost == nullptr) {
    return;
  }

  // bank header at this+0x144 (callee reads begin@+4 end@+8)
  FUN_005194f0(gfxMatHost, base + 0x144);
}
