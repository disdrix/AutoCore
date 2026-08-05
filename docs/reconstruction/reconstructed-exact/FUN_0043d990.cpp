// =============================================================================
// GuardedVector_GrowBlockMap_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d990
// Address:   0x0043d990–0x0043dae3  (autoassault.exe, image base 0x400000)
// Body:      340 bytes; ret 4 @ 0x0043dae1
// System:    STL / guarded ring-deque (family GuardedVector_*)
// Generated: dual A/B seal 2026-07-29 (W30-A); Ghidra FUN_0043d990
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes
//            commit tail. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Grows the deque-style block-pointer map when push needs a new page slot.
 * - ECX = container (thiscall); stack arg = minimum additional map slots
 *   (callers pass 1).
 * - Geometric growth: max(min_grow, max(capacity/2, 8)); overflow →
 *   "deque<T> too long" via FUN_00436860.
 * - begin_blk = begin >> 2 (4 elements per page index).
 * - Rebalances existing block pointers; zeros new/unused entries.
 * - operator_delete is not noreturn: always commits capacity+=grow, slots=neu.
 * - Twin of GuardedVector_GrowBlockMap @ 0x0043c9b0 (EBX entry); this unit is
 *   the ECX thiscall clone used by FUN_0043d670 / FUN_0043e3d0.
 */

#include <cstdint>
#include <cstring>

struct GuardedVectorHeader {
  uint32_t _pad0;
  uint32_t *slots;    // +0x04 block map
  uint32_t capacity;  // +0x08 map capacity (blocks)
  uint32_t begin;     // +0x0c begin element index
  uint32_t size;      // +0x10 element count (untouched here)
};

extern "C" void FUN_00436860();  // throws length_error "deque<T> too long"
extern "C" void *operator_new(uint32_t);
extern "C" void operator_delete(void *);

// Retail: ECX=container; stdcall 1 stack arg; RET 0x4.
void GuardedVector_GrowBlockMap_Thiscall(GuardedVectorHeader *self /*ECX*/,
                                         uint32_t min_grow)
{
  uint32_t cap = self->capacity;
  if (0x0FFFFFFFu - cap < min_grow) {
    FUN_00436860();
  }

  uint32_t geo = cap >> 1;
  if (geo < 8) {
    geo = 8;
  }
  if ((min_grow < geo) && (cap <= 0x0FFFFFFFu - geo)) {
    min_grow = geo;
  }

  uint32_t begin_blk = self->begin >> 2;
  uint32_t *neu = static_cast<uint32_t *>(operator_new((cap + min_grow) * 4u));

  // Tail [begin_blk, cap) → neu[begin_blk ...]
  {
    void *src = reinterpret_cast<uint8_t *>(self->slots) + begin_blk * 4u;
    size_t nbytes = static_cast<size_t>((cap - begin_blk) * 4u);
    void *dst = neu + begin_blk;
    void *after = std::memmove(dst, src, nbytes);
    after = static_cast<uint8_t *>(after) + nbytes;

    if (min_grow < begin_blk) {
      std::memmove(after, self->slots, static_cast<size_t>(min_grow * 4u));
      void *mid_src = reinterpret_cast<uint8_t *>(self->slots) + min_grow * 4u;
      size_t mid_n = static_cast<size_t>((begin_blk - min_grow) * 4u);
      void *mid_dst = std::memmove(neu, mid_src, mid_n);
      uint32_t *zero_at =
          reinterpret_cast<uint32_t *>(static_cast<uint8_t *>(mid_dst) + mid_n);
      for (uint32_t i = min_grow; i != 0; --i) {
        *zero_at++ = 0;
      }
    } else {
      size_t head_n = static_cast<size_t>(begin_blk * 4u);
      void *after_head = std::memmove(after, self->slots, head_n);
      uint32_t *fill =
          reinterpret_cast<uint32_t *>(static_cast<uint8_t *>(after_head) + head_n);
      for (uint32_t extra = min_grow - begin_blk; extra != 0; --extra) {
        *fill++ = 0;
      }
      uint32_t *front = neu;
      for (uint32_t i = begin_blk; i != 0; --i) {
        *front++ = 0;
      }
    }
  }

  if (self->slots != nullptr) {
    operator_delete(self->slots);
  }
  self->capacity = cap + min_grow;
  self->slots = neu;
}

// Ghidra symbol twin
void FUN_0043d990(GuardedVectorHeader *self, uint32_t min_grow)
{
  GuardedVector_GrowBlockMap_Thiscall(self, min_grow);
}
