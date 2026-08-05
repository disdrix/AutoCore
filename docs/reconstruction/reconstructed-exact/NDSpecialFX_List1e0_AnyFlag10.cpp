// =============================================================================
// NDSpecialFX_List1e0_AnyFlag10
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6a80
// Address:   0x004b6a80–0x004b6aa7  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX residual list probe
// Generated: 2026-07-23 scaffold as FUN_004b6a80; dual A/B seal 2026-07-29 (W26-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf predicate: walk circular list at host+0x1e0; true if any payload has
 *   byte(payload+0x989) bit 0x10 set.
 * - Retail ABI: ECX=host; plain RET; AL = 0|1.
 * - Callers (type switch case 4): NDSpecialFX_HostTick_Inferred (FUN_004b8ed0),
 *   FUN_004ba0a0 — non-zero keeps/re-enters active path.
 * - Name is structural (_Inferred family); product English for flag open.
 */

#include <cstdint>

struct ListNode {
  ListNode* next;   // +0
  ListNode* prev;   // +4  (not read here)
  uint8_t*  payload; // +8
};

// host+0x1e0 holds ListNode* sentinel (circular).
uint8_t NDSpecialFX_List1e0_AnyFlag10(void* host /*ECX*/)
{
  // Retail: MOV ECX, [host+0x1e0] → sentinel; MOV EAX, [sentinel] → first node.
  auto* sentinel = *reinterpret_cast<ListNode**>(
      reinterpret_cast<uint8_t*>(host) + 0x1e0);
  ListNode* node = *reinterpret_cast<ListNode**>(sentinel);

  while (true) {
    if (node == sentinel) {
      return 0;
    }
    uint8_t* elem = *reinterpret_cast<uint8_t**>(
        reinterpret_cast<uint8_t*>(node) + 8); // node[2]
    if ((elem[0x989] & 0x10) != 0) {
      return 1;
    }
    node = *reinterpret_cast<ListNode**>(node); // *node
  }
}
