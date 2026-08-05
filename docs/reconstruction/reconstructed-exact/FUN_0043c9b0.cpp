// =============================================================================
// FUN_0043c9b0  (twin of GuardedVector_GrowBlockMap)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c9b0
// Address:   0x0043c9b0–0x0043cafd  (autoassault.exe, image base 0x400000)
// Generated: dual A/B seal 2026-07-29 (W28-B)
// =============================================================================

#include <cstdint>
#include <cstring>

struct GuardedVectorHeader {
  uint32_t _pad0;
  uint32_t* slots;
  uint32_t capacity;
  uint32_t begin;
  uint32_t size;
};

extern "C" void FUN_00436860();
extern "C" void* operator_new(uint32_t);
extern "C" void operator_delete(void*);

// Retail: EBX=container; stdcall 1 arg; RET 0x4.
void FUN_0043c9b0(uint32_t min_grow /*stack*/, GuardedVectorHeader* self /*EBX*/)
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
  uint32_t* neu = static_cast<uint32_t*>(operator_new((cap + min_grow) * 4u));

  {
    void* src = reinterpret_cast<uint8_t*>(self->slots) + begin_blk * 4u;
    size_t nbytes = static_cast<size_t>((cap - begin_blk) * 4u);
    void* dst = neu + begin_blk;
    void* after = std::memmove(dst, src, nbytes);
    after = static_cast<uint8_t*>(after) + nbytes;

    if (min_grow < begin_blk) {
      std::memmove(after, self->slots, static_cast<size_t>(min_grow * 4u));
      void* mid_src = reinterpret_cast<uint8_t*>(self->slots) + min_grow * 4u;
      size_t mid_n = static_cast<size_t>((begin_blk - min_grow) * 4u);
      void* mid_dst = std::memmove(neu, mid_src, mid_n);
      uint32_t* zero_at = reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(mid_dst) + mid_n);
      for (uint32_t i = min_grow; i != 0; --i) {
        *zero_at++ = 0;
      }
    } else {
      size_t head_n = static_cast<size_t>(begin_blk * 4u);
      void* after_head = std::memmove(after, self->slots, head_n);
      uint32_t* fill = reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(after_head) + head_n);
      for (uint32_t extra = min_grow - begin_blk; extra != 0; --extra) {
        *fill++ = 0;
      }
      uint32_t* front = neu;
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
