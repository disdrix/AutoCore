// =============================================================================
// FUN_006508d0 — Ghidra alias twin of CVOGHBMissionEscort_OnHeartBeat
// -----------------------------------------------------------------------------
// Stable ID: aa_006508d0
// Address:   0x006508d0–0x00650cf6  (autoassault.exe, image base 0x400000)
// System:    missions-progression / heartbeat
// Generated: 2026-08-04 WQ7R-H dual seal
// Exactness: Thin FUN_* twin — body is the named clean reconstruction.
// Verdict:   accept-with-gaps
// Terminal:  false
// Product:   CVOGHBMissionEscort_OnHeartBeat (RTTI + vtable+0x0C)
// ABI:       __thiscall; stack EHBStatus* out; ret 4; returns out
// Prefer:    CVOGHBMissionEscort_OnHeartBeat.cpp for sealed CF + field map
// =============================================================================

#include <cstdint>

struct CVOGHBBase;

// Named clean reconstruction (same VA / ABI / CF).
extern "C" std::uint32_t* __thiscall CVOGHBMissionEscort_OnHeartBeat(
    CVOGHBBase* self,
    std::uint32_t* pOutStatus);

// Ghidra symbol alias — keep FUN_* name for xref continuity.
std::uint32_t* __thiscall FUN_006508d0(
    CVOGHBBase* param_1,
    std::uint32_t* param_2)
{
  return CVOGHBMissionEscort_OnHeartBeat(param_1, param_2);
}
