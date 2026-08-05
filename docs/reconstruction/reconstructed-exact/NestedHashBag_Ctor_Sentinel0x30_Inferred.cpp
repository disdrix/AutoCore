// =============================================================================
// NestedHashBag_Ctor_Sentinel0x30_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004438c0
// Address:   0x004438c0–0x00443921  (autoassault.exe, image base 0x400000)
// System:    containers / NestedHashBag shell (sentinel 0x30)
// Generated: 2026-07-23 scaffold as FUN_004438c0; dual A/B seal 2026-07-29 (W34-G)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a NestedHash/HeadBag bag: circular sentinel at
//   +0x08, size 0 at +0x0c, 9-bucket pointer table at +0x10 filled with the
//   sentinel, structural flags +0x20/+0x24 = 1. Sentinel node size is **0x30**
//   via FUN_005b43b0 (vs Ass twins using 0x28 / FUN_00423d60).
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 98 B; SEH LAB_009bed5b.
//
// CALLER:
//   FUN_00754ee0 @ 0x00754f3e: FUN_004438c0(host + 0x44)
//
// TWIN SHAPE:
//   AssResolverA_NestedHash_Ctor (0x00423cf0), AssResolverCore_HeadBag_Ctor
//   (0x00469db0), NestedHashBag_Ctor_Sentinel0x18 (0x00457b30), FUN_00457ac0.
//

#include <cstdint>

// Unowned / sealed elsewhere
extern "C" void* FUN_005b43b0(void); // operator_new(0x30) circular sentinel
extern "C" void  FUN_004646e0(void* vec_base /*stack*/, uint32_t capacity /*stack*/,
                              void** fill_value /*stack*/); // PtrVecShell_InitFill

struct NestedHashBag_Sentinel0x30 {
  uint32_t pad00;          // +0x00  not written by this ctor
  uint32_t pad04;          // +0x04  not written by this ctor
  void*    sentinel;       // +0x08  circular node* (0x30 bytes)
  uint32_t size;           // +0x0c  set 0
  uint32_t vec_unk10;      // +0x10  FUN_004646e0 base (callee may leave +0)
  void*    buckets_begin;  // +0x14
  void*    buckets_end;    // +0x18
  void*    buckets_cap;    // +0x1c
  uint32_t flag20;         // +0x20  set 1
  uint32_t flag24;         // +0x24  set 1
}; // core bag 0x28

// Retail: stack(self*); RET 4; return self
extern "C" NestedHashBag_Sentinel0x30*
NestedHashBag_Ctor_Sentinel0x30_Inferred(NestedHashBag_Sentinel0x30* self /*stack*/)
{
  // SEH frame LAB_009bed5b
  void* node = FUN_005b43b0();
  self->sentinel = node;
  self->size = 0;

  void* fill = node;
  FUN_004646e0(&self->vec_unk10, 9, &fill);

  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}

// Ghidra twin symbol
extern "C" NestedHashBag_Sentinel0x30* FUN_004438c0(NestedHashBag_Sentinel0x30* self)
{
  return NestedHashBag_Ctor_Sentinel0x30_Inferred(self);
}
