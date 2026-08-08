// =============================================================================
// FUN_00832fa0 — twin of CWndWaypointIcon_CompleteDtor (aa_00832fa0)
// Wave: WQ9J-B 2026-08-05. Prefer named clean CWndWaypointIcon_CompleteDtor.cpp.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall CWndWaypointIcon_CompleteDtor(uint32_t* self);

extern "C" void __fastcall FUN_00832fa0(uint32_t* self)
{
  CWndWaypointIcon_CompleteDtor(self);
}
