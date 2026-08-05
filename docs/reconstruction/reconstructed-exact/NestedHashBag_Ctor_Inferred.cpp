// =============================================================================
// NestedHashBag_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a0d0
// Address:   0x0044a0d0–0x0044a131  (autoassault.exe, image base 0x400000)
// Body:      98 B / 0x62; SEH LAB_009bd46b; RET 4
// System:    assets / nested hash-bag (Ass-style twin)
// Generated: 2026-07-23 scaffold as FUN_0044a0d0; dual A/B seal 2026-07-29 (W34-D)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a nested hash/map bag (0x28 span shape):
//   circular sentinel node @+0x08, size0 @+0x0c, 9-bucket pointer table @+0x10,
//   flags @+0x20/+0x24 = 1. Twin CF of AssResolverA_NestedHash_Ctor (00423cf0)
//   and AssResolverCore_HeadBag_Ctor (00469db0).
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Not ECX-thiscall.
//
// CALLER:
//   FUN_0074d750 @ 0x0074d786: FUN_0044a0d0(self+0x0c)  // param_1+3 as dword*
//
// CALLEES (owned elsewhere):
//   CircularSentinel_Alloc0x28_Inferred (FUN_00423d60)
//   PtrVecShell_InitFill_Inferred (FUN_004646e0) — stdcall 3-arg RET 12
//

#include <cstdint>

// Unowned callees
extern "C" void* FUN_00423d60(void); // operator_new(0x28) circular sentinel
extern "C" void  FUN_004646e0(void* shell /*stack*/, uint32_t count /*stack*/,
                              void** fill_src /*stack*/);

struct NestedHashBag {
  uint32_t pad00;          // +0x00  not written by this ctor
  uint32_t pad04;          // +0x04  not written by this ctor
  void*    sentinel;       // +0x08  circular node*
  uint32_t size;           // +0x0c  set 0
  uint32_t vec_unk10;      // +0x10  FUN_004646e0 base (callee may leave +0)
  void*    buckets_begin;  // +0x14
  void*    buckets_end;    // +0x18
  void*    buckets_cap;    // +0x1c
  uint32_t flag20;         // +0x20  set 1
  uint32_t flag24;         // +0x24  set 1
}; // 0x28

// Retail: stack(self*); RET 4; return self
extern "C" NestedHashBag*
NestedHashBag_Ctor_Inferred(NestedHashBag* self /*stack*/)
{
  // SEH frame LAB_009bd46b
  void* node = FUN_00423d60();
  self->sentinel = node;
  self->size = 0;

  void* fill = node;
  FUN_004646e0(&self->vec_unk10, 9, &fill);

  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}

// Ghidra twin symbol
extern "C" NestedHashBag* FUN_0044a0d0(NestedHashBag* self)
{
  return NestedHashBag_Ctor_Inferred(self);
}
