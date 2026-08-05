// =============================================================================
// Object_ResolveFromTFID  (legacy path: FUN_004bb950.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb950
// Address:   0x004bb950–0x004bb966  (autoassault.exe, image base 0x400000)
// System:    object-resolve / TFID (cross-cutting client)
// Canonical: reconstructed-exact/Object_ResolveFromTFID.cpp  (same body)
// Generated: 2026-07-23 scaffold; **strengthened 2026-07-29** dual A/B
// Exactness: Behavior-preserving. Decompiler omitted ECX thiscall passthrough.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

#include <cstdint>

struct TFID_16 {
  std::uint32_t dwCoidLo;  // +0
  std::uint32_t dwCoidHi;  // +4
  std::uint8_t  bGlobal;   // +8
  std::uint8_t  bPad[7];   // +9..+15 — not read here
};

extern "C" void * __thiscall CVOGReaction_ResolveObjectTarget(
    void *ctx,
    std::uint8_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi);

// Image: unpack TFID_16; CALL 0x004bae70 with ECX preserved; RET 4.
extern "C" void * __thiscall Object_ResolveFromTFID(void *ctx, TFID_16 *pTfid)
{
  const std::uint32_t coidHi = pTfid->dwCoidHi;
  const std::uint32_t coidLo = pTfid->dwCoidLo;
  const std::uint8_t  bGlobal = pTfid->bGlobal;
  return CVOGReaction_ResolveObjectTarget(ctx, bGlobal, coidLo, coidHi);
}
