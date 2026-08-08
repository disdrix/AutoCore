// =============================================================================
// Object_ResolveTfIdVtbl1dc_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb0d0
// Address:   0x004bb0d0–0x004bb0f9  (autoassault.exe, image base 0x400000)
// System:    object-resolve / TFID (cross-cutting client)
// Generated: 2026-07-23 scaffold as FUN_004bb0d0; **sealed 2026-08-04** dual A/B WQ9R-D
// Exactness: Behavior-preserving. Decompiler omits ECX resolve-ctx passthrough —
//            clean follows image (same ABI class as Object_ResolveTfIdVtbl1d4_Inferred).
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// =============================================================================

/*
 * Behavioral notes (2026-08-04 seal):
 * - Resolve TFID-like blob via CVOGReaction_ResolveObjectTarget, then invoke
 *   virtual method at vtbl+0x1dc on the resolved object.
 * - ABI: ECX = resolve context (caller-supplied; body never loads ECX);
 *   stack = blob*; RET 4. Ghidra signature lacks ECX.
 * - Blob fields: +0 coidLo, +4 coidHi, +8 bGlobal. Pad unused.
 * - Null resolve → return 0. No other branches/stores.
 * - Sibling family:
 *     004bb950 Object_ResolveFromTFID (no vtbl)
 *     004bb010 Object_ResolveTfIdVtbl1d4_Inferred (+0x1d4, blob*)
 *     004bb070 Object_ResolveTfIdGetIdentity_Inferred (+0x1d8, blob*)
 *     004bb0a0 Client_LookupObjectByTfid_Inferred (+0x1dc, free 3-arg cdecl RET 0xc)
 * - Same virtual slot as 004bb0a0; different stack ABI (blob* + RET 4).
 * - Callers include Skill_FilterTargetForResolveList (crew/vehicle TFID path)
 *   and CVOGHBAIBase_FindTargetToAttack.
 */

#include <cstdint>

struct TFID_Head {
  std::uint32_t dwCoidLo;  // +0
  std::uint32_t dwCoidHi;  // +4
  std::uint8_t  bGlobal;   // +8
};

// aa_004bae70 — dual-table TFID resolve (not owned by this unit).
extern "C" void * __thiscall CVOGReaction_ResolveObjectTarget(
    void *ctx,
    std::uint8_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi);

// Image: unpack blob → ResolveObjectTarget (ECX passthrough) →
//        if non-null CALL [vtbl+0x1dc] with ECX=obj; else 0; RET 4.
extern "C" void * __thiscall Object_ResolveTfIdVtbl1dc_Inferred(
    void *ctx,
    TFID_Head *pBlob)
{
  void *obj = CVOGReaction_ResolveObjectTarget(
      ctx,
      pBlob->bGlobal,
      pBlob->dwCoidLo,
      pBlob->dwCoidHi);

  if (obj == nullptr) {
    return nullptr;
  }

  // thiscall virtual: ECX = obj, slot +0x1dc
  using VFn = void *(__thiscall *)(void *self);
  auto *vtbl = *reinterpret_cast<std::uint8_t **>(obj);
  auto fn = *reinterpret_cast<VFn *>(vtbl + 0x1dc);
  return fn(obj);
}
