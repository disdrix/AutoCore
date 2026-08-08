// =============================================================================
// CNDHash_TraverseToNext_ListNext20  (FUN_004bc530)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc530
// Address:   0x004bc530–0x004bc57d inclusive (78 B / 0x4E)
// Module:    autoassault.exe (image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-08-05 MEGA-029 dual seal (body ≡ 2026-07-23 raw)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (MEGA-029 sealed):
 * - Product role: CNDHash::TraverseToNext under held TraversalLock
 * - String: "HashError:TraverseToNext, not locked for traversal" @ 0x00a27c9c
 * - Assert plate: "VOG_DEBUG_STOP" @ 0x00a15844 (not a product id)
 * - ABI: __thiscall; ECX=hash; stack int* cursor; EAX=payload|0; RET 4
 * - Layout (this family): head this+0x14; lock this+0x1d;
 *     node next +0x20; payload +0x0c
 * - Twin: CNDHash_TraverseToNext 0x00411900 (next+0x14 / payload+8) — do not merge
 * - Lock companion: FUN_00402c40 sets +0x1d=1; parent FUN_004bae00 clears after call
 * - Unlocked path logs then continues (non-fatal)
 * - Rejects scaffold Named_VOG_DEBUG_STOP_004bc530 (assert-string misname)
 */

#include <cstdint>

// FUN_007a4480: debug/log (cdecl; this unit uses ADD ESP,0x10 after two calls)
extern "C" void FUN_007a4480(std::uint32_t level, const char *msg);

// __thiscall; RET 4
// Returns payload at node+0x0c, or 0 at end of ordered list.
extern "C" std::uint32_t __thiscall CNDHash_TraverseToNext_ListNext20(
    std::uint8_t *this_hash,
    std::uint32_t *cursor /* inout: node* as dword */)
{
  std::uint32_t node;

  if (this_hash[0x1d] == 0) {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    /* fall through — does not return early */
  }

  if (*cursor == 0) {
    node = *reinterpret_cast<std::uint32_t *>(this_hash + 0x14); /* list head */
    *cursor = node;
  } else {
    node = *reinterpret_cast<std::uint32_t *>(
        reinterpret_cast<std::uint8_t *>(static_cast<std::uintptr_t>(*cursor)) + 0x20);
    *cursor = node;
  }

  if (node != 0) {
    return *reinterpret_cast<std::uint32_t *>(
        reinterpret_cast<std::uint8_t *>(static_cast<std::uintptr_t>(node)) + 0x0c);
  }
  return 0;
}
