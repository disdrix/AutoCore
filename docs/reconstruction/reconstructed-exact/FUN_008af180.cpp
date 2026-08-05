// =============================================================================
// FUN_008af180 — alias plate for UI_MissionPanel_SyncSlotVisibilityAndLayout
// -----------------------------------------------------------------------------
// Stable ID: aa_008af180
// Address:   0x008af180 – 0x008b01ee  (autoassault.exe, image base 0x400000)
// Canonical: UI_MissionPanel_SyncSlotVisibilityAndLayout
// See:       UI_MissionPanel_SyncSlotVisibilityAndLayout.cpp  (authoritative clean)
// Sealed:    2026-07-29 dual W21-Q
// =============================================================================
//
// Image ABI: ESI = panel host, stack char forceRelayout, void return.
//
// Authoritative staged reconstruction lives in the named clean file. This plate
// keeps the Ghidra symbol for callers still referencing FUN_008af180 and notes
// that the raw decompile retains full geometry CF (type-propagation noise on
// stack slots — treat float* temps as int/pointer except scale math).

#include <cstdint>

void UI_MissionPanel_SyncSlotVisibilityAndLayout(void* host /*ESI*/, char forceRelayout);

void FUN_008af180(char forceRelayout)
{
    void* host = nullptr; // ESI at call site
    UI_MissionPanel_SyncSlotVisibilityAndLayout(host, forceRelayout);
}
