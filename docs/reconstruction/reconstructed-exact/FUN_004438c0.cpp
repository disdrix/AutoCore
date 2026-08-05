// =============================================================================
// FUN_004438c0 — twin of NestedHashBag_Ctor_Sentinel0x30_Inferred
// Stable ID: aa_004438c0 | VA 0x004438c0 | W34-G dual seal 2026-07-29
// =============================================================================

#include <cstdint>

extern "C" void* FUN_005b43b0(void);
extern "C" void  FUN_004646e0(void* vec_base, uint32_t capacity, void** fill_value);

struct NestedHashBag_Sentinel0x30 {
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

extern "C" NestedHashBag_Sentinel0x30*
NestedHashBag_Ctor_Sentinel0x30_Inferred(NestedHashBag_Sentinel0x30* self);

extern "C" NestedHashBag_Sentinel0x30* FUN_004438c0(NestedHashBag_Sentinel0x30* self /*stack*/)
{
  return NestedHashBag_Ctor_Sentinel0x30_Inferred(self);
}
