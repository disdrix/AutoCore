// =============================================================================
// FUN_004cf120 — scaffold alias for AllocateNewObjectFromCbid
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf120
// Address:   0x004cf120–0x004cf296  (autoassault.exe, image base 0x400000)
// Canonical: AllocateNewObjectFromCbid.cpp
// Generated: 2026-07-23 scaffold; sealed 2026-07-29 dual A/B W18-T
// =============================================================================

// Forward to sealed clean implementation name.
// See AllocateNewObjectFromCbid.cpp for full body + plate-backed name.

#include <cstdint>

struct SectorMapHost;

extern "C" void *__thiscall AllocateNewObjectFromCbid(
    SectorMapHost *self, int cbid, int templateId);

extern "C" void *__thiscall FUN_004cf120(
    SectorMapHost *self, int cbid, int templateId)
{
  return AllocateNewObjectFromCbid(self, cbid, templateId);
}
