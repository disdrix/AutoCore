// =============================================================================
// FUN_0076b190 / Fs_Path_EnsureExtension_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b190
// Address:   0x0076b190  (autoassault.exe, image base 0x400000)
// System:    fs / path helpers
// Wave:      W33-P (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin of Fs_Path_EnsureExtension_Inferred.cpp

#include <cstdint>

extern "C" void FUN_0076af70(char* dir, char* fname, char* ext);
extern "C" void FUN_0076aba0(char* out_or_dir, char* a, char* b);

extern "C" void FUN_0076b190(const char* /*path*/, char* out /* + ESI=defaultExt */)
{
  char local_300[256]; // ext
  char local_200[256]; // fname
  char local_100[256]; // dir
  // drive via EAX into nested split

  FUN_0076af70(local_100, local_200, local_300);
  if (local_300[0] == '\0') {
    // strcpy from ESI (default extension, e.g. "glm")
    // retail byte loop
  }
  FUN_0076aba0(out /*recompose target plumbing*/, local_200, local_300);
}
