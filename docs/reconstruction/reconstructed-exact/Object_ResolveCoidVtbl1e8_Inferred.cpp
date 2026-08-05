// =============================================================================
// Object_ResolveCoidVtbl1e8_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb1c0
// Address:   0x004bb1c0–0x004bb1e9  (autoassault.exe, image base 0x400000)
// System:    object-resolve / TFID (cross-cutting client)
// Generated: 2026-07-23 scaffold as FUN_004bb1c0; **sealed 2026-07-29** dual A/B W18-T
// Exactness: Behavior-preserving. Decompiler omits ECX resolve-ctx passthrough —
//            clean follows image (same ABI class as Object_ResolveFromTFID).
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - Resolve free (bGlobal, coidLo, coidHi) via CVOGReaction_ResolveObjectTarget,
 *   then invoke virtual method at vtbl+0x1e8 on the resolved object.
 * - ABI: ECX = resolve context (caller-supplied; body never loads ECX);
 *   stack = bGlobal, coidLo, coidHi; RET 0xC. Ghidra signature lacks ECX.
 * - Null resolve → return 0. No other branches/stores.
 * - Sibling family: 004bb950 resolve-only; 004bb010 blob+vtbl+0x1d4;
 *   004bb070 +0x1d8; 004bb0a0 +0x1dc. This unit is free-arg +0x1e8.
 * - Sector load triggers use nullness then fire nested vtbl+0x114 on result chain.
 */

#include <cstdint>

// aa_004bae70 — dual-table TFID resolve (not owned by this unit).
extern "C" void * __thiscall CVOGReaction_ResolveObjectTarget(
    void *ctx,
    std::uint32_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi);

// Image: push triple → ResolveObjectTarget (ECX passthrough) →
//        if non-null CALL [vtbl+0x1e8] with ECX=obj; else 0; RET 0xC.
extern "C" void * __thiscall Object_ResolveCoidVtbl1e8_Inferred(
    void *ctx,
    std::uint32_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi)
{
  void *obj = CVOGReaction_ResolveObjectTarget(ctx, bGlobal, coidLo, coidHi);

  if (obj == nullptr) {
    return nullptr;
  }

  // thiscall virtual: ECX = obj, slot +0x1e8
  using VFn = void *(__thiscall *)(void *self);
  auto *vtbl = *reinterpret_cast<std::uint8_t **>(obj);
  auto fn = *reinterpret_cast<VFn *>(vtbl + 0x1e8);
  return fn(obj);
}
