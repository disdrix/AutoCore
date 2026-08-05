// =============================================================================
// StdList_AllocSentinel_0x18_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00457c60
// Address:   0x00457c60  (autoassault.exe, image base 0x400000)
// System:    shared std::list-style sentinel factory
// Generated: 2026-07-29 W30-E dual (from raw + live read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Allocate a 0x18-byte list node and self-link next/prev as empty circular sentinel.
// Sibling of StdList_AllocEmptySentinel_Inferred (0x0040fb90, node 0x0C).
// Callers store returned head and zero a separate size dword.

#include <cstdint>

struct ListNode18 {
  ListNode18* next;  // +0x00
  ListNode18* prev;  // +0x04
  // +0x08..+0x17: payload / unused by this factory (not written)
};

// Retail: no formals; returns node* in EAX; bare RET (C3).
// Decompiler displays void — incorrect.
extern void* operator_new(uint32_t size);

ListNode18* StdList_AllocSentinel_0x18_Inferred(void)
{
  ListNode18* node = static_cast<ListNode18*>(operator_new(0x18));

  if (node != nullptr) {
    node->next = node;
  }

  // Retail: LEA ECX,[EAX+4]; TEST ECX,ECX; JZ; MOV [ECX],EAX
  // When node==nullptr this writes 0 to absolute address 4 (dead under throwing new).
  uint32_t* prev_slot = reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(node) + 4);
  if (prev_slot != nullptr) {
    *prev_slot = reinterpret_cast<uint32_t>(node);
  }

  return node;
}
