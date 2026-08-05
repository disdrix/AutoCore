// =============================================================================
// Host54_NestedHash0xC_At28_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00996bc0
// Address:   0x00996bc0 – 0x00996c1e exclusive (94 B / 0x5E)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W35-S OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF sealed by full body hex.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a 0x54-byte host that zeros a prefix (capacity 8
//   at +0x10), embeds NestedHash (sentinel node 0x0C) at +0x28, and sets a
//   host flag at +0x50. Sole host FUN_00989cf0 places this at outer +0x14
//   (CriticalSection at outer +0x68 → span 0x54).
//
// ABI: stack(self*); RET 4; returns self in EAX. Not ECX-thiscall.
// SEH: LAB_009acd74
// Nested: NestedHash_Ctor_Sentinel0xC_Inferred (FUN_0043fdf0, W34-F) at +0x28
// =============================================================================

#include <cstddef>
#include <cstdint>

extern "C" void* NestedHash_Ctor_Sentinel0xC_Inferred(void* self /*stack; RET 4*/);

struct Host54_NestedHash0xC_At28 {
  uint32_t p0;
  uint32_t p4;
  uint32_t p8;
  uint8_t  b0c;
  uint8_t  pad0d[3];
  uint32_t cap10;   // written 8
  uint32_t p14;
  uint32_t p18;     // intentionally unwritten by this ctor
  uint32_t p1c;
  uint32_t p20;
  uint32_t p24;
  uint8_t  nested_hash[0x28];  // at +0x28
  uint8_t  flag50;
  uint8_t  pad51[3];
};
static_assert(offsetof(Host54_NestedHash0xC_At28, nested_hash) == 0x28, "hash offset");
static_assert(offsetof(Host54_NestedHash0xC_At28, flag50) == 0x50, "flag offset");
static_assert(sizeof(Host54_NestedHash0xC_At28) == 0x54, "host size");

// stack(self*); RET 4
extern "C" Host54_NestedHash0xC_At28* Host54_NestedHash0xC_At28_Ctor_Inferred(
    Host54_NestedHash0xC_At28* self)
{
  self->p0 = 0;
  self->p4 = 0;
  self->p8 = 0;
  self->b0c = 0;
  self->cap10 = 8;
  self->p14 = 0;
  // +0x18 not written
  self->p1c = 0;
  self->p20 = 0;
  self->p24 = 0;

  NestedHash_Ctor_Sentinel0xC_Inferred(self->nested_hash);

  self->flag50 = 1;
  return self;
}

extern "C" Host54_NestedHash0xC_At28* FUN_00996bc0(Host54_NestedHash0xC_At28* self)
{
  return Host54_NestedHash0xC_At28_Ctor_Inferred(self);
}
