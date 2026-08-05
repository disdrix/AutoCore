// =============================================================================
// FUN_00984340  (Ghidra twin of Fs_ExpandPathSpecToStringVec_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00984340
// Address:   0x00984340–0x009847bb  (autoassault.exe, image base 0x400000)
// Wave:      W33-E dual seal 2026-07-29
// =============================================================================

extern "C" void* Fs_ExpandPathSpecToStringVec_Inferred(void* out_string_vec,
                                                       const char* path_spec,
                                                       char recurse_dirs);

extern "C" void* FUN_00984340(void* out_string_vec, const char* path_spec,
                              char recurse_dirs)
{
  return Fs_ExpandPathSpecToStringVec_Inferred(out_string_vec, path_spec,
                                               recurse_dirs);
}
