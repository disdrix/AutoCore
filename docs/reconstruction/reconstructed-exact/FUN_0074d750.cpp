// =============================================================================
// FUN_0074d750  (twin of Class_00aa05cc_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074d750
// Address:   0x0074d750–0x0074d7ad  (94 B / 0x5E)
// Wave:      W35-C OWN-ONLY dual 2026-07-29
// See:       Class_00aa05cc_Ctor_Inferred.cpp for sealed semantics.
// =============================================================================

#include <cstdint>

extern "C" void* NestedHashBag_Ctor_Inferred(void* self);
extern "C" void* NestedHash_Ctor_Sentinel0x14_Inferred(void* self);
extern "C" void* PTR_FUN_00aa05cc[];

extern "C" uint32_t* __fastcall FUN_0074d750(uint32_t* self)
{
  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00aa05cc);
  self[1] = 0;
  self[2] = 0;
  NestedHashBag_Ctor_Inferred(self + 3);          // +0x0c
  NestedHash_Ctor_Sentinel0x14_Inferred(self + 0xd); // +0x34
  return self;
}
