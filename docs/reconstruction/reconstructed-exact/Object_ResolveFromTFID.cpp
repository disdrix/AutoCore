// =============================================================================
// Object_ResolveFromTFID
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb950
// Address:   0x004bb950–0x004bb966  (autoassault.exe, image base 0x400000)
// System:    object-resolve / TFID (cross-cutting client)
// Generated: 2026-07-23 scaffold; **strengthened 2026-07-29** dual A/B
//            (read_memory body + call-site ECX setup)
// Exactness: Behavior-preserving. Decompiler omitted ECX thiscall passthrough —
//            clean follows image.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - Thin unwrap: TFID_16 → (bGlobal, coidLo, coidHi) + passthrough resolve ctx.
 * - ABI: __thiscall — ECX = resolve context (same object as CVOGReaction_ResolveObjectTarget);
 *   stack = TFID_16*; RET 4. Ghidra signature lacked ECX; callers load often
 *   *(host+0xe4e8) or *(host+0xd34) immediately before CALL.
 * - TFID fields: +0 dwCoidLo, +4 dwCoidHi, +8 bGlobal (byte). No pad use.
 * - Sole callee: CVOGReaction_ResolveObjectTarget @ 0x004bae70 (ret 0x0c).
 * - No null check, no stores, no branches in this body.
 * - Return: object* or NULL (from dual-table hash lookup inside callee).
 */

#include <cstdint>

// 16-byte TFID block as used on wire / obj+0x160 class. This unit only reads +0..+8.
struct TFID_16 {
  std::uint32_t dwCoidLo;  // +0
  std::uint32_t dwCoidHi;  // +4
  std::uint8_t  bGlobal;   // +8
  std::uint8_t  bPad[7];   // +9..+15 — not read here
};

// aa_004bae70 — permissioned dual-table TFID resolve (not owned by this unit).
extern "C" void * __thiscall CVOGReaction_ResolveObjectTarget(
    void *ctx,
    std::uint8_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi);

// Image: MOV EAX,[ESP+4]; unpack; CALL 0x004bae70 with ECX preserved; RET 4.
extern "C" void * __thiscall Object_ResolveFromTFID(void *ctx, TFID_16 *pTfid)
{
  // Match push order / field widths from body bytes (no pTfid null gate).
  const std::uint32_t coidHi = pTfid->dwCoidHi;
  const std::uint32_t coidLo = pTfid->dwCoidLo;
  const std::uint8_t  bGlobal = pTfid->bGlobal;

  return CVOGReaction_ResolveObjectTarget(ctx, bGlobal, coidLo, coidHi);
}
