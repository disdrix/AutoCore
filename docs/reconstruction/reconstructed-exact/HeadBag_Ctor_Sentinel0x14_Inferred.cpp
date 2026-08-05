// =============================================================================
// HeadBag_Ctor_Sentinel0x14_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004642d0
// Address:   0x004642d0–0x00464332 exclusive  (98 B / 0x62; autoassault.exe base 0x400000)
// System:    list-head + pointer-vector bag (0x14 circular sentinel)
// Generated: 2026-07-23 scaffold as FUN_004642d0; dual A/B seal 2026-07-29 (W34-H)
// Exactness: Behavior-preserving rewrite of decompiler + full 98 B body.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a list-head + 9-slot pointer-vector bag.
//   Allocates a 0x14 circular sentinel via FUN_0043c460, stores at +0x08, zeros
//   +0x0c, reserves a 9-slot pointer vector at +0x10 via FUN_004646e0 (fill =
//   sentinel*), sets +0x20/+0x24 = 1, returns self.
//
// ABI (bytes):
//   stack(self*); RET 4; returns self in EAX. SEH LAB_009bdd3b.
//
// TWIN CF:
//   Same shape as AssResolverA_NestedHash_Ctor (FUN_00423cf0) and
//   AssResolverCore_HeadBag_Ctor (FUN_00469db0) but sentinel is 0x14
//   (FUN_0043c460) not 0x28 (FUN_00423d60). No static callers found.
//
// REJECT: invent-Ass product plate; ECX-thiscall; vtbl write.
//

#include <cstdint>

// Nested (not owned this unit)
extern "C" void* FUN_0043c460(void); // operator_new(0x14) circular next/prev
// W33-B: stdcall 3-arg PtrVecShell_InitFill_Inferred
extern "C" void __stdcall FUN_004646e0(void* shell, uint32_t count, void** fill_src);

struct HeadBag_Sentinel0x14 {
  uint8_t  unk_00[8];     // +0x00 untouched here
  void*    list_head;     // +0x08
  uint32_t list_aux;      // +0x0c
  uint8_t  ptr_vec[0x10]; // +0x10 shell; FUN_004646e0 writes shell+4/+8/+0xc
  uint32_t flag_20;       // +0x20
  uint32_t flag_24;       // +0x24
};

// Retail: stack(self*); RET 4; return self
extern "C" HeadBag_Sentinel0x14* HeadBag_Ctor_Sentinel0x14_Inferred(
    HeadBag_Sentinel0x14* self /*stack*/)
{
  void* head = FUN_0043c460();
  self->list_head = head;
  self->list_aux = 0;
  {
    void* fill = head;
    FUN_004646e0(self->ptr_vec, 9, reinterpret_cast<void**>(&fill));
  }
  self->flag_20 = 1;
  self->flag_24 = 1;
  return self;
}

// Ghidra twin symbol
extern "C" HeadBag_Sentinel0x14* FUN_004642d0(HeadBag_Sentinel0x14* self)
{
  return HeadBag_Ctor_Sentinel0x14_Inferred(self);
}
