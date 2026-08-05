// =============================================================================
// FUN_009697a0 — scaffold twin of StringVec_PushBackIfAbsent_EnsureTrailingDirSep
// Stable ID: aa_009697a0
// Address:   0x009697a0–0x0096982D exclusive (141 B)
// W34-J: prefer named clean StringVec_PushBackIfAbsent_EnsureTrailingDirSep.cpp
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;
  uint8_t* end;
  uint8_t* capEnd;
};

extern "C" void StringVec_PushBackIfAbsent_EnsureTrailingDirSep(
    StringVecShell* self /*EDI*/,
    const void* path);

// Retail entry: EDI=self; stack path*; ret 4
extern "C" void FUN_009697a0(const void* path)
{
  // Callers must place StringVecShell* in EDI (Ghidra unaff_EDI).
  (void)path;
}
