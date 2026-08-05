// =============================================================================
// NestedHash_Ctor_Sentinel0xC_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0043fdf0
// Address:   0x0043fdf0–0x0043fe51  (autoassault.exe, image base 0x400000)
// System:    shared nested hash/map shell (list head + 9-bucket ptr table)
// Generated: 2026-07-23 scaffold as FUN_0043fdf0; dual A/B seal 2026-07-29 (W34-F)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a nested hash/map shell (span 0x28):
//   allocates a circular sentinel node (0x0C), installs a 9-bucket pointer table
//   filled with that sentinel, zeros the size field, and sets two structural flags to 1.
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 98 B; SEH LAB_009bc89b.
//
// CALLERS:
//   FUN_0074e380 @ 0x0074e3ba — outer 0x40; nested at +0x14 (float*+5).
//   FUN_0096eec0 @ 0x0096eeea — shell at object base.
//   FUN_00996bc0 @ 0x00996c02 — nested at +0x28 (dword*+10).
//
// FAMILY:
//   Twin of AssResolverA_NestedHash_Ctor_Inferred (0x00423cf0) / FUN_00469db0 —
//   same 98 B CF; sentinel factory is StdList_AllocSentinel_0xC (0x004933f0).
//   Sibling this dual: NestedHash_Ctor_Sentinel0x30_Inferred (0x00463bd0).
//

#include <cstdint>

// Unowned / sealed-elsewhere callees
extern "C" void* FUN_004933f0(void); // StdList_AllocSentinel_0xC_Inferred
extern "C" void  FUN_004646e0(void* shell /*stack*/, uint32_t count /*stack*/,
                              void** fill_src /*stack*/); // PtrVecShell_InitFill; RET 12

struct NestedHash_Sentinel0xC {
  uint32_t pad00;          // +0x00  not written by this ctor
  uint32_t pad04;          // +0x04  not written by this ctor
  void*    sentinel;       // +0x08  circular node* (0x0C)
  uint32_t size;           // +0x0c  set 0
  uint32_t shell_unk10;    // +0x10  PtrVecShell base (callee leaves +0 unwritten)
  void*    buckets_begin;  // +0x14
  void*    buckets_end;    // +0x18
  void*    buckets_cap;    // +0x1c
  uint32_t flag20;         // +0x20  set 1
  uint32_t flag24;         // +0x24  set 1
}; // 0x28

// Retail: stack(self*); RET 4; return self
extern "C" NestedHash_Sentinel0xC*
NestedHash_Ctor_Sentinel0xC_Inferred(NestedHash_Sentinel0xC* self /*stack*/)
{
  // SEH frame LAB_009bc89b
  void* node = FUN_004933f0();
  self->sentinel = node;
  self->size = 0;

  void* fill = node;
  FUN_004646e0(&self->shell_unk10, 9, &fill);

  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}

// Ghidra twin symbol
extern "C" NestedHash_Sentinel0xC* FUN_0043fdf0(NestedHash_Sentinel0xC* self)
{
  return NestedHash_Ctor_Sentinel0xC_Inferred(self);
}
