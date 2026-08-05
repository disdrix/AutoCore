// =============================================================================
// FUN_00457b30 — twin of NestedHashBag_Ctor_Sentinel0x18_Inferred
// Stable ID: aa_00457b30 | VA 0x00457b30 | W34-G dual seal 2026-07-29
// =============================================================================

#include <cstdint>

extern "C" void* FUN_00457c60(void);
extern "C" void  FUN_004646e0(void* vec_base, uint32_t capacity, void** fill_value);

struct NestedHashBag_Sentinel0x18 {
  uint32_t pad00;
  uint32_t pad04;
  void*    sentinel;
  uint32_t size;
  uint32_t vec_unk10;
  void*    buckets_begin;
  void*    buckets_end;
  void*    buckets_cap;
  uint32_t flag20;
  uint32_t flag24;
};

extern "C" NestedHashBag_Sentinel0x18*
NestedHashBag_Ctor_Sentinel0x18_Inferred(NestedHashBag_Sentinel0x18* self);

extern "C" NestedHashBag_Sentinel0x18* FUN_00457b30(NestedHashBag_Sentinel0x18* self /*stack*/)
{
  return NestedHashBag_Ctor_Sentinel0x18_Inferred(self);
}
