// =============================================================================
// AssResolverCore_HeadBag_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00469db0
// Address:   0x00469db0–0x00469e12 exclusive  (autoassault.exe, image base 0x400000)
// System:    assets / AssResolverCore head bag (twin of FUN_00423cf0)
// Generated: 2026-07-23 scaffold as FUN_00469db0; dual A/B seal 2026-07-29 (W32-E)
// Exactness: Behavior-preserving rewrite of decompiler + full 98 B body.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for the list-head + pointer-vector bag that heads
//   AssResolverCore (called first from AssResolverCore_Ctor_Inferred / FUN_00983940).
//   Allocates a 0x28 circular sentinel via FUN_00423d60, stores at +0x08, zeros
//   +0x0c, reserves a 9-slot pointer vector at +0x10 via FUN_004646e0, sets
//   +0x20/+0x24 = 1, returns self.
//
// ABI (bytes):
//   stack(self*); RET 4; returns self in EAX. SEH LAB_009bc89b.
//
// CALLERS:
//   FUN_00983940 @ 0x0098395d (AssResolverCore_Ctor_Inferred, W31-G) only.
//

#include <cstdint>

// Nested (not owned this unit)
extern "C" void* FUN_00423d60(void); // operator_new(0x28) circular sentinel
extern "C" void FUN_004646e0(void* vec_shell /*stack*/, uint32_t count /*=9*/, void* fill_src /*stack*/);

struct AssResolverCore_HeadBag {
  uint8_t unk_00[8];     // +0x00 untouched here
  void* list_head;       // +0x08
  uint32_t list_aux;     // +0x0c
  uint8_t ptr_vec[0x10]; // +0x10 shell; FUN_004646e0 writes +4/+8/+0xc of shell
  uint32_t flag_20;      // +0x20
  uint32_t flag_24;      // +0x24
};

// Retail: stack(self*); RET 4; return self
extern "C" AssResolverCore_HeadBag* AssResolverCore_HeadBag_Ctor_Inferred(
    AssResolverCore_HeadBag* self /*stack*/)
{
  void* head = FUN_00423d60();
  self->list_head = head;
  self->list_aux = 0;
  {
    void* fill = head;
    FUN_004646e0(self->ptr_vec, 9, &fill);
  }
  self->flag_20 = 1;
  self->flag_24 = 1;
  return self;
}

extern "C" AssResolverCore_HeadBag* FUN_00469db0(AssResolverCore_HeadBag* self)
{
  return AssResolverCore_HeadBag_Ctor_Inferred(self);
}
