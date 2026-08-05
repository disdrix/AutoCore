// =============================================================================
// FUN_0043c7e0  (twin of GuardedVector_Resize)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c7e0
// Address:   0x0043c7e0–0x0043c829  (autoassault.exe, image base 0x400000)
// Dual:      W28-D 2026-07-29
// Prefer:    GuardedVector_Resize.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Prefer named clean: docs/reconstruction/reconstructed-exact/GuardedVector_Resize.cpp

// Retail: EAX=container; ECX=new_size; plain RET; SUB/ADD ESP,8.
// Ghidra may display __fastcall on ECX only and drop EAX this-reg.

void FUN_0043c7e0(uint32_t new_size /*ECX*/, int container /*EAX*/)
{
  uint32_t size = *reinterpret_cast<uint32_t*>(container + 0x10);
  uint32_t local_fill[2]{};
  local_fill[0] = 0;

  if (size < new_size) {
    // Bytes: ECX = new_size - size; CALL FUN_0043cb00 with stack
    //   (container, container, begin+size, &local_fill[0])
    extern void FUN_0043cb00(...);
    FUN_0043cb00(/* see GuardedVector_Resize.cpp */);
    return;
  }

  if (new_size < size) {
    extern void FUN_0043c8c0(...);
    // EraseRange([begin+new_size, begin+size)); EAX=container
    FUN_0043c8c0(/* out, seed, begin+new_size, seed, begin+size */);
  }
}
