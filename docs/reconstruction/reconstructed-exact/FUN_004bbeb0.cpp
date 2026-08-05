// =============================================================================
// FUN_004bbeb0  (scaffold twin → Host_ResetHashQueuesVectors_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbeb0
// Address:   0x004bbeb0  (autoassault.exe, image base 0x400000)
// Wave:      W31-N 2026-07-29 — see Host_ResetHashQueuesVectors_Inferred.cpp
// =============================================================================

#include <cstdint>

struct Host_ResetTables;

extern "C" void __fastcall Host_ResetHashQueuesVectors_Inferred(Host_ResetTables* self);

extern "C" void __fastcall FUN_004bbeb0(Host_ResetTables* self)
{
  Host_ResetHashQueuesVectors_Inferred(self);
}
