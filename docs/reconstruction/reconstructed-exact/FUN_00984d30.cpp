// =============================================================================
// FUN_00984d30  (twin of AssPackManager_ExtractPackEntryToFile_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00984d30
// Address:   0x00984d30–0x00984ed4  (autoassault.exe, image base 0x400000)
// System:    palantir assets / assPackManager
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W33-Q)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Extract one pack entry to a filesystem path under optional host CS.
// Plate: assPackManager.cpp — "<%s> couldnt be found!"
// Canonical: AssPackManager_ExtractPackEntryToFile_Inferred
// See AssPackManager_ExtractPackEntryToFile_Inferred.cpp for sealed port notes.

#include <cstdint>
#include <windows.h>

extern "C" int AssPackManager_ExtractPackEntryToFile_Inferred(
    const char* outPath,
    void* host,
    const char* entryName,
    uint32_t spill);

extern "C" int FUN_00984d30(
    const char* outPath /*ECX*/,
    void* host /*stack0*/,
    const char* entryName /*stack1*/,
    uint32_t spill /*stack2*/)
{
  return AssPackManager_ExtractPackEntryToFile_Inferred(outPath, host, entryName, spill);
}
