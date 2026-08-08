// =============================================================================
// FUN_00834520 — twin of CWndVehicle_CompleteDtor (aa_00834520)
// Wave: WQ9J-B 2026-08-05. Prefer named clean CWndVehicle_CompleteDtor.cpp.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall CWndVehicle_CompleteDtor(uint32_t* self);

extern "C" void __fastcall FUN_00834520(uint32_t* self)
{
  CWndVehicle_CompleteDtor(self);
}
