// =============================================================================
// NestedHashBag_Ctor_Sentinel0x18_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00457b30
// Address:   0x00457b30–0x00457b91  (autoassault.exe, image base 0x400000)
// System:    containers / NestedHashBag shell (sentinel 0x18)
// Generated: 2026-07-23 scaffold as FUN_00457b30; dual A/B seal 2026-07-29 (W34-G)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a NestedHash/HeadBag bag identical in layout to
//   AssResolver NestedHash/HeadBag, but with **0x18** sentinel nodes via
//   FUN_00457c60 (StdList_AllocSentinel_0x18).
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 98 B; SEH LAB_009bc89b.
//
// CALLER:
//   FUN_0073c810 @ 0x0073cae5:
//     host = operator_new(0x40);
//     FUN_00457b30(host);
//     zero host+0x28 .. host+0x3e (caller-owned tail)
//
// TWIN SHAPE:
//   NestedHashBag_Ctor_Sentinel0x30 (0x004438c0), Ass NestedHash/HeadBag, FUN_00457ac0.
//

#include <cstdint>

extern "C" void* FUN_00457c60(void); // StdList_AllocSentinel_0x18_Inferred
extern "C" void  FUN_004646e0(void* vec_base /*stack*/, uint32_t capacity /*stack*/,
                              void** fill_value /*stack*/);

struct NestedHashBag_Sentinel0x18 {
  uint32_t pad00;          // +0x00  not written
  uint32_t pad04;          // +0x04  not written
  void*    sentinel;       // +0x08  circular node* (0x18 bytes)
  uint32_t size;           // +0x0c  set 0
  uint32_t vec_unk10;      // +0x10
  void*    buckets_begin;  // +0x14
  void*    buckets_end;    // +0x18
  void*    buckets_cap;    // +0x1c
  uint32_t flag20;         // +0x20  set 1
  uint32_t flag24;         // +0x24  set 1
}; // core bag 0x28; host may be 0x40 with tail zeroed by caller

// Retail: stack(self*); RET 4; return self
extern "C" NestedHashBag_Sentinel0x18*
NestedHashBag_Ctor_Sentinel0x18_Inferred(NestedHashBag_Sentinel0x18* self /*stack*/)
{
  // SEH frame LAB_009bc89b
  void* node = FUN_00457c60();
  self->sentinel = node;
  self->size = 0;

  void* fill = node;
  FUN_004646e0(&self->vec_unk10, 9, &fill);

  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}

extern "C" NestedHashBag_Sentinel0x18* FUN_00457b30(NestedHashBag_Sentinel0x18* self)
{
  return NestedHashBag_Ctor_Sentinel0x18_Inferred(self);
}
