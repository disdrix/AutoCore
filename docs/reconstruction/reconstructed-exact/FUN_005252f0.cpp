// =============================================================================
// FUN_005252f0 — scaffold twin of Character_SwitchVehicle_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005252f0
// Address:   0x005252f0  (autoassault.exe, image base 0x400000)
// Body:      1955 B (0x005252f0–0x00525a92); exclusive end 0x00525a93
// System:    vehicle / inventory-transfer / client chassis switch
// Generated: 2026-07-29 W25-E dual seal (replaces 2026-07-23 scaffold)
// Exactness: Control-flow preserved from live decompile; see named clean for stages.
// Bit-for-bit / runtime: OPEN (large coordinator).
// Dual A/B: accept-with-gaps (reviews/A|B_aa_005252f0_*).
// Named clean: Character_SwitchVehicle_Inferred.cpp
// Strings: "switched vehicles, and no room for old vehicle in either inventory"
//          "VOG_DEBUG_STOP"
// =============================================================================

// Full decompiler body retained in raw/aa_005252f0_FUN_005252f0.md
// (authoritative). This twin points ports at the named stage reconstruction.

#include <cstdint>

std::uint32_t __thiscall FUN_005252f0(
    int param_1,
    std::uint32_t *param_2,
    int *param_3,
    std::uint32_t param_4,
    std::uint32_t param_5);

// Implementation: see raw capture + Character_SwitchVehicle_Inferred.cpp stages.
// Live Ghidra body is ~300 decompiler lines; not duplicated here to avoid drift.
// Use raw pseudocode as the line-level authority; named clean for stage contract.
