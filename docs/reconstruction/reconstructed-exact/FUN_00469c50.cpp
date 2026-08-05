// =============================================================================
// FUN_00469c50 / StdVector_Elem28_Size
// -----------------------------------------------------------------------------
// Stable ID: aa_00469c50
// Address:   0x00469c50–0x00469c70  (autoassault.exe, image base 0x400000)
// System:    containers / std::vector size helper
// Generated: dual A/B seal 2026-07-29 (W33-J); prior scaffold 2026-07-23
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Prefer named twin: StdVector_Elem28_Size.cpp
// Ghidra name retained for inventory linkage.

#include <cstdint>

int __fastcall FUN_00469c50(int param_1 /*ECX*/)
{
  if (*reinterpret_cast<int*>(param_1 + 4) == 0) {
    return 0;
  }
  return (*reinterpret_cast<int*>(param_1 + 8) -
          *reinterpret_cast<int*>(param_1 + 4)) / 0x1c;
}
