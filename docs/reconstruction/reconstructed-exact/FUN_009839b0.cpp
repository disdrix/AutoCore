// =============================================================================
// FUN_009839b0  (Ghidra twin of Fs_DirRecurseCollectLeafPaths_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009839b0
// Address:   0x009839b0–0x00983b53  (autoassault.exe, image base 0x400000)
// Wave:      W32-D dual seal 2026-07-29
// =============================================================================

extern "C" int Fs_DirRecurseCollectLeafPaths_Inferred(const char* path,
                                                      void* out_string_vec);

extern "C" int FUN_009839b0(const char* path, void* out_string_vec /*stack*/)
{
  return Fs_DirRecurseCollectLeafPaths_Inferred(path, out_string_vec);
}
