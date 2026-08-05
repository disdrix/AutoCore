// =============================================================================
// FUN_00984910  (twin of AssPackManager_AddOrReplaceFileInPack_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00984910
// Address:   0x00984910–0x00984c65  (autoassault.exe, image base 0x400000)
// System:    palantir assets / assPackManager
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W33-Q)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Add or replace a filesystem file into an open pack under optional host CS.
// Plate: assPackManager.cpp — "Not replacing %s." / "Added file %s" / "Unable to open file"
// Canonical: AssPackManager_AddOrReplaceFileInPack_Inferred
// See AssPackManager_AddOrReplaceFileInPack_Inferred.cpp for sealed port notes.

#include <cstdint>

extern "C" int AssPackManager_AddOrReplaceFileInPack_Inferred(
    const char* srcPath,
    void* host,
    int typeId,
    char forceReplace,
    uint32_t arg4,
    uint32_t replaceCookie);

extern "C" int FUN_00984910(
    const char* srcPath /*ECX*/,
    void* host /*stack0*/,
    int typeId /*stack1*/,
    char forceReplace /*stack2*/,
    uint32_t arg4 /*stack3*/,
    uint32_t replaceCookie /*stack4*/)
{
  return AssPackManager_AddOrReplaceFileInPack_Inferred(
      srcPath, host, typeId, forceReplace, arg4, replaceCookie);
}
