// =============================================================================
// FUN_0044a0d0  (Ghidra symbol twin of NestedHashBag_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a0d0
// Address:   0x0044a0d0–0x0044a131  (autoassault.exe, image base 0x400000)
// Body:      98 B; SEH LAB_009bd46b; RET 4
// System:    assets / nested hash-bag (Ass-style twin)
// Generated: 2026-07-23 scaffold; refined W34-D dual seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// Preferred name: NestedHashBag_Ctor_Inferred
// Reject: Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0044a0d0
// =============================================================================

#include <cstdint>

extern "C" void* FUN_00423d60(void);
extern "C" void  FUN_004646e0(void* shell, uint32_t count, void** fill_src);

// stdcall 1 formal; RET 4; returns self
extern "C" uint32_t* FUN_0044a0d0(uint32_t* self /*stack*/)
{
  // SEH LAB_009bd46b
  void* sentinel = FUN_00423d60();
  self[2] = reinterpret_cast<uint32_t>(sentinel); // +0x08
  self[3] = 0;                                    // +0x0c size

  void* fill = sentinel;
  FUN_004646e0(self + 4, 9, &fill);               // +0x10 shell, count 9

  self[8] = 1;                                    // +0x20
  self[9] = 1;                                    // +0x24
  return self;
}
