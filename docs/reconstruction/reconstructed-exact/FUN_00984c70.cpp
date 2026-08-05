// =============================================================================
// FUN_00984c70  (Ghidra twin of AssPackManager_AddDirectoryTree_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00984c70
// Address:   0x00984c70–0x00984d25  (autoassault.exe, image base 0x400000)
// Wave:      W33-E dual seal 2026-07-29
// =============================================================================

extern "C" int AssPackManager_AddDirectoryTree_Inferred(const char* dir_path,
                                                        void* ass_pack_manager);

extern "C" int FUN_00984c70(const char* dir_path, void* ass_pack_manager)
{
  return AssPackManager_AddDirectoryTree_Inferred(dir_path, ass_pack_manager);
}
