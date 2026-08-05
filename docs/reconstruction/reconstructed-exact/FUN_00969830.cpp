// =============================================================================
// FUN_00969830 — scaffold twin of StringVec_PushFront_EnsureTrailingDirSep
// -----------------------------------------------------------------------------
// Stable ID: aa_00969830
// Address:   0x00969830  (autoassault.exe, image base 0x400000)
// Wave:      W31-E OWN-ONLY dual 2026-07-29
// Prefer:    StringVec_PushFront_EnsureTrailingDirSep.cpp
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void* pad0;
  uint8_t* begin;
  uint8_t* end;
};

extern "C" void StringVec_PushFront_EnsureTrailingDirSep(StringVecShell* self,
                                                         const void* path);

// Retail ABI: ESI = self, stack path; ret 4.
// This twin documents Ghidra's stack-only signature; live callers load ESI.
extern "C" void FUN_00969830(const void* param_1)
{
  // unaff_ESI in decompile — must be provided by caller convention.
  // Prefer named clean entry when porting.
  (void)param_1;
}
