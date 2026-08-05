// =============================================================================
// AssResolverA_NestedHash_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00423cf0
// Address:   0x00423cf0–0x00423d51  (autoassault.exe, image base 0x400000)
// System:    assets / assManager / resolver A nested member
// Generated: 2026-07-23 scaffold as FUN_00423cf0; dual A/B seal 2026-07-29 (W32-D)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for the nested hash/map member of AssManager resolver A.
//   Allocates a circular sentinel node (0x28), installs a 9-bucket pointer table
//   filled with that sentinel, zeros the size field, and sets two structural flags to 1.
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 98 B; SEH LAB_009bcd6b.
//
// CALLER:
//   AssManager_ResolverA_Ctor_Inferred (0x00423be0) @ 0x00423c0e:
//     FUN_00423cf0(self+0x08)  // nested span 0x28 up to outer CS at +0x30
//
// TWIN SHAPE:
//   FUN_00469db0 (AssResolverCore nested member ctor — owned elsewhere / W32-E).
//

#include <cstdint>

// Unowned callees
extern "C" void* FUN_00423d60(void); // operator_new(0x28) circular sentinel
extern "C" void  FUN_004646e0(void* vec_base /*stack*/, uint32_t capacity /*stack*/,
                              void** fill_value /*stack*/);

struct AssResolverA_NestedHash {
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
extern "C" AssResolverA_NestedHash*
AssResolverA_NestedHash_Ctor_Inferred(AssResolverA_NestedHash* self /*stack*/)
{
  // SEH frame LAB_009bcd6b
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
extern "C" AssResolverA_NestedHash* FUN_00423cf0(AssResolverA_NestedHash* self)
{
  return AssResolverA_NestedHash_Ctor_Inferred(self);
}
