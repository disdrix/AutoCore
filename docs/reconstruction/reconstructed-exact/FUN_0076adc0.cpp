// =============================================================================
// FUN_0076adc0  (Ghidra twin of Fs_PathIsDirectory_Stat_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076adc0
// Address:   0x0076adc0–0x0076ae35  (autoassault.exe, image base 0x400000)
// System:    filesystem / path probe
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W33-C)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// See Fs_PathIsDirectory_Stat_Inferred.cpp for named clean + full plate.
// This twin keeps the Ghidra symbol as the primary export for xref continuity.
// =============================================================================

#include <cstdint>

extern "C" uint32_t Fs_PathIsDirectory_Stat_Inferred(const char* path);

extern "C" uint32_t FUN_0076adc0(const char* path)
{
  return Fs_PathIsDirectory_Stat_Inferred(path);
}
