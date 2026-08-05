// =============================================================================
// FUN_00423cf0  (Ghidra twin of AssResolverA_NestedHash_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00423cf0
// Address:   0x00423cf0–0x00423d51  (autoassault.exe, image base 0x400000)
// Wave:      W32-D dual seal 2026-07-29
// =============================================================================

#include <cstdint>

extern "C" void* FUN_00423d60(void);
extern "C" void  FUN_004646e0(void* vec_base, uint32_t capacity, void** fill_value);

struct AssResolverA_NestedHash {
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

extern "C" AssResolverA_NestedHash*
AssResolverA_NestedHash_Ctor_Inferred(AssResolverA_NestedHash* self);

extern "C" AssResolverA_NestedHash* FUN_00423cf0(AssResolverA_NestedHash* self /*stack*/)
{
  return AssResolverA_NestedHash_Ctor_Inferred(self);
}
