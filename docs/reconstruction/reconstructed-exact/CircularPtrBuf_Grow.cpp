// =============================================================================
// CircularPtrBuf_Grow
// -----------------------------------------------------------------------------
// Purpose:  Grow a circular buffer's heap pointer-slot map.
//           Geometric capacity increase, circular linearization via memmove,
//           zero new slots, replace old map.
//
// Address:  0x00436650  (autoassault.exe, image base 0x400000)
// Body:     0x00436650–0x00436794 (324 bytes; ret 4 @ 0x00436791)
// Stable:   aa_00436650
// System:   container / circular pointer-buffer utility
// Ghidra:   FUN_00436650
//
// ABI:      custom — this in EBX; stack [esp+4]=grow_request; ret 4
// Layout:   +0x04 slots**, +0x08 capacity, +0x0C head, (+0x10 count unused)
//
// Exactness: CF mirrors live decompile + read_memory commit tail.
//            Decompiler noreturn on operator_delete is WRONG — fixed here.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W18-E seal).
// =============================================================================

#include <cstddef>
#include <cstdint>

// External / CRT (names for readability; retail uses operator_new/delete + memmove IAT)
extern void *operator_new(unsigned size);
extern void operator_delete(void *p);
extern void *memmove(void *dst, const void *src, size_t n);
extern void FUN_00436860(void); // throw "deque<T> too long" (noreturn)

struct CircularPtrBuf {
  // +0x00 — not touched by this unit
  void **slots;           // +0x04
  unsigned capacity;      // +0x08
  unsigned head;          // +0x0C
  // unsigned count;      // +0x10 — not modified here
};

/* CircularPtrBuf_Grow
   Grow pointer map so capacity increases by at least grow_request (often
   geometrically to max(cap/2, 8)). Rearranges circular contents so head
   index remains valid. Sole retail caller: CircularPtrBuf_PushCopy_0x14
   (FUN_00436340) with grow_request == 1. */

void CircularPtrBuf_Grow(/* EBX */ CircularPtrBuf *self, unsigned grow_request)
{
  unsigned cap = self->capacity;

  // Max map size guard (MSVC deque stock limit / string)
  if (0x0CCCCCCCu - cap < grow_request) {
    FUN_00436860(); // noreturn
  }

  // Geometric growth: at least max(cap/2, 8) when safe
  unsigned chunk = cap >> 1;
  if (chunk < 8u) {
    chunk = 8u;
  }
  if ((grow_request < chunk) && (cap <= 0x0CCCCCCCu - chunk)) {
    grow_request = chunk;
  }

  unsigned head = self->head;
  void **neu = (void **)operator_new((cap + grow_request) * 4u);

  // --- circular linearization (matches Ghidra plate) ---
  int head_bytes = (int)(head * 4u);
  void *old_tail = (void *)(head_bytes + (int)self->slots);
  size_t tail_bytes =
      (size_t)((((int)(cap * 4u) - (int)old_tail) + (int)self->slots) >> 2) * 4u;

  void *cursor = memmove(neu + head, old_tail, tail_bytes);
  cursor = (void *)((int)cursor + (int)tail_bytes);

  void **zero_base;
  unsigned zero_count;

  if (grow_request < head) {
    // Split-copy head region across wrap when grow < head
    memmove(cursor, self->slots, (size_t)(((int)(grow_request * 4u) >> 2) * 4));
    void *mid = (void *)((int)(grow_request * 4u) + (int)self->slots);
    size_t rest =
        (size_t)(((head_bytes - (int)mid) + (int)self->slots) >> 2) * 4u;
    cursor = memmove(neu, mid, rest);
    zero_base = (void **)((int)cursor + (int)rest);
    zero_count = grow_request;
  } else {
    size_t head_copy = (size_t)((head_bytes >> 2) * 4);
    int gap = (int)(grow_request - head);
    cursor = memmove(cursor, self->slots, head_copy);
    void **gap_ptr = (void **)((int)cursor + (int)head_copy);
    if (gap != 0) {
      for (; gap != 0; gap = gap - 1) {
        *gap_ptr = 0;
        gap_ptr = gap_ptr + 1;
      }
    }
    zero_base = neu;
    zero_count = head;
  }

  if (zero_count != 0) {
    for (; zero_count != 0; zero_count = zero_count - 1) {
      *zero_base = 0;
      zero_base = zero_base + 1;
    }
  }

  // Commit (bytes-sealed: always runs after optional delete)
  void *old = self->slots;
  if (old != 0) {
    operator_delete(old);
  }
  self->capacity = cap + grow_request;
  self->slots = neu;
}
