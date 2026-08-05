// =============================================================================
// FUN_0043df90  (clean twin of GuardedVector_EraseRange_Thiscall)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043df90
// Address:   0x0043df90–0x0043e07d  (autoassault.exe, image base 0x400000)
// Generated: dual A/B seal 2026-07-29 (W34-L)
// Exactness: Behavior-preserving rewrite; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void*    slots;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  int32_t              index;
};

extern "C" void FUN_0043ebb0(void* a0, GuardedVectorHeader* a1, int32_t a2,
                             uint32_t a3, int32_t a4, uint32_t a5, int32_t a6);
extern "C" void FUN_0043ec50(void* a0, uint32_t a1, int32_t a2,
                             GuardedVectorHeader* a3, int32_t a4,
                             uint32_t a5, int32_t a6,
                             GuardedVectorIteratorPair* a7);

// Retail: __thiscall ECX=container; 5 stack formals; RET 0x14
void __thiscall FUN_0043df90(
    GuardedVectorHeader* this_,
    GuardedVectorIteratorPair* out_pair,
    uint32_t erase_from_c,
    int32_t erase_from,
    uint32_t erase_to_c,
    int32_t erase_to)
{
  const int32_t begin = this_->begin;
  const uint32_t prefix =
      static_cast<uint32_t>(erase_from - begin);
  int erase_cnt = erase_to - erase_from;
  const int32_t end_idx = this_->size + begin;
  const uint32_t suffix_len =
      static_cast<uint32_t>(end_idx - erase_to);

  if (prefix < suffix_len) {
    FUN_0043ebb0(&erase_from_c, this_, begin,
                 erase_from_c, erase_from, erase_to_c, erase_to);
    if (erase_cnt != 0) {
      int size_work = this_->size;
      do {
        if (size_work != 0) {
          this_->begin += 1;
          if (static_cast<uint32_t>(this_->capacity * 4) <=
              static_cast<uint32_t>(this_->begin)) {
            this_->begin = 0;
          }
          size_work -= 1;
          if (size_work == 0) {
            this_->begin = 0;
          }
        }
        erase_cnt -= 1;
      } while (erase_cnt != 0);
      this_->size = size_work;
    }
  } else {
    FUN_0043ec50(&erase_from_c, erase_to_c, erase_to,
                 this_, end_idx, erase_from_c, erase_from, out_pair);
    if (erase_cnt != 0) {
      int size_work = this_->size;
      do {
        if (size_work != 0) {
          size_work -= 1;
          if (size_work == 0) {
            this_->begin = 0;
          }
        }
        erase_cnt -= 1;
      } while (erase_cnt != 0);
      this_->size = size_work;
    }
  }

  out_pair->container = this_;
  out_pair->index = this_->begin + static_cast<int32_t>(prefix);
}
