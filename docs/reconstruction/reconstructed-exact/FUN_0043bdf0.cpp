// =============================================================================
// NestedHash_Ctor_Sentinel0x14_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0043bdf0
// Address:   0x0043bdf0–0x0043be51  (autoassault.exe, image base 0x400000)
// System:    containers / nested hash bag (NDResourceCache head + embeds)
// Generated: 2026-07-23 scaffold as FUN_0043bdf0; dual A/B seal 2026-07-29 (W34-E)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a NestedHash bag: circular sentinel node (0x14),
//   size 0, 9-bucket pointer table filled with that sentinel, flags 1/1.
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 98 B; SEH LAB_009bc89b.
//
// CALLERS:
//   FUN_0075d470 @ 0x0075d499 — NDResourceCache host (DAT_00d1f050 = self; bag at +0)
//   FUN_0074d750 @ 0x0074d797 — nested at self+0x34
//
// TWIN SHAPE:
//   NestedHash_Ctor_Sentinel0x10_Inferred (0x00457ac0) — node size 0x10
//   AssResolverA_NestedHash_Ctor_Inferred (0x00423cf0) — node size 0x28
//   AssResolverCore_HeadBag_Ctor_Inferred (0x00469db0) — node size 0x28
//

#include <cstdint>

// Unowned callees
extern "C" void* FUN_0043c460(void); // operator_new(0x14) circular sentinel
extern "C" void  FUN_004646e0(void* vec_base /*stack*/, uint32_t capacity /*stack*/,
                              void** fill_value /*stack*/); // PtrVecShell_InitFill_Inferred

struct NestedHash_Sentinel0x14 {
  uint32_t pad00;          // +0x00  not written by this ctor
  uint32_t pad04;          // +0x04  not written by this ctor
  void*    sentinel;       // +0x08  circular node* (0x14)
  uint32_t size;           // +0x0c  set 0
  uint32_t shell_unk10;    // +0x10  FUN_004646e0 base
  void*    buckets_begin;  // +0x14
  void*    buckets_end;    // +0x18
  void*    buckets_cap;    // +0x1c
  uint32_t flag20;         // +0x20  set 1
  uint32_t flag24;         // +0x24  set 1
}; // 0x28

// Retail: stack(self*); RET 4; return self
extern "C" NestedHash_Sentinel0x14*
NestedHash_Ctor_Sentinel0x14_Inferred(NestedHash_Sentinel0x14* self /*stack*/)
{
  // SEH frame LAB_009bc89b
  void* node = FUN_0043c460();
  self->sentinel = node;
  self->size = 0;

  void* fill = node;
  FUN_004646e0(&self->shell_unk10, 9, &fill);

  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}

// Ghidra twin symbol
extern "C" NestedHash_Sentinel0x14* FUN_0043bdf0(NestedHash_Sentinel0x14* self)
{
  return NestedHash_Ctor_Sentinel0x14_Inferred(self);
}
