// =============================================================================
// NestedHash_Ctor_Sentinel0x10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00457ac0
// Address:   0x00457ac0–0x00457b21  (autoassault.exe, image base 0x400000)
// System:    containers / nested hash bag (statics + gfx + heap hosts)
// Generated: 2026-07-23 scaffold as FUN_00457ac0; dual A/B seal 2026-07-29 (W34-E)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a NestedHash bag: circular sentinel node (0x10),
//   size 0, 9-bucket pointer table filled with that sentinel, flags 1/1.
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 98 B; SEH LAB_009bc89b.
//
// CALLERS:
//   FUN_00438c40 / FUN_00438ca0 / FUN_0044fee0 — once-flag static globals
//   FUN_0073c810 — heap new(0x30) bag host
//   FUN_0098fef0 — stack-local bag (gfxDeviceIB path)
//
// TWIN SHAPE:
//   NestedHash_Ctor_Sentinel0x14_Inferred (0x0043bdf0) — node size 0x14
//   AssResolverA_NestedHash_Ctor_Inferred / AssResolverCore_HeadBag_Ctor_Inferred — node 0x28
//

#include <cstdint>

// Unowned callees
extern "C" void* FUN_004397f0(void); // operator_new(0x10) circular sentinel
extern "C" void  FUN_004646e0(void* vec_base /*stack*/, uint32_t capacity /*stack*/,
                              void** fill_value /*stack*/); // PtrVecShell_InitFill_Inferred

struct NestedHash_Sentinel0x10 {
  uint32_t pad00;          // +0x00  not written by this ctor
  uint32_t pad04;          // +0x04  not written by this ctor
  void*    sentinel;       // +0x08  circular node* (0x10)
  uint32_t size;           // +0x0c  set 0
  uint32_t shell_unk10;    // +0x10  FUN_004646e0 base
  void*    buckets_begin;  // +0x14
  void*    buckets_end;    // +0x18
  void*    buckets_cap;    // +0x1c
  uint32_t flag20;         // +0x20  set 1
  uint32_t flag24;         // +0x24  set 1
}; // 0x28

// Retail: stack(self*); RET 4; return self
extern "C" NestedHash_Sentinel0x10*
NestedHash_Ctor_Sentinel0x10_Inferred(NestedHash_Sentinel0x10* self /*stack*/)
{
  // SEH frame LAB_009bc89b
  void* node = FUN_004397f0();
  self->sentinel = node;
  self->size = 0;

  void* fill = node;
  FUN_004646e0(&self->shell_unk10, 9, &fill);

  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}

// Ghidra twin symbol
extern "C" NestedHash_Sentinel0x10* FUN_00457ac0(NestedHash_Sentinel0x10* self)
{
  return NestedHash_Ctor_Sentinel0x10_Inferred(self);
}
