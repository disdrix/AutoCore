// =============================================================================
// FUN_004f9030  (legacy scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_004f9030
// Address:   0x004f9030  (autoassault.exe, image base 0x400000)
// Body:      0x004f9030 – 0x004f9563
// System:    vehicle / combat weapon hardpoints
// Canonical: Vehicle_UpdateWeaponHardpoints3_Inferred
//            → see Vehicle_UpdateWeaponHardpoints3_Inferred.cpp
// Generated: 2026-07-23 scaffold; plate redirect 2026-07-29 W19-A dual A/B
// Exactness: Behavior-preserving. Prefer named clean for sealed body.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Legacy FUN_* scaffold kept for path stability.
 * Dual A/B sealed unit lives at:
 *   docs/reconstruction/reconstructed-exact/Vehicle_UpdateWeaponHardpoints3_Inferred.cpp
 *
 * ABI: ECX = vehicle this; near RET; 0 stack args.
 * Phase1: optional clear of 3 hardpoints at +0x260 (SetFireFlagPair 0 + +0xC9=0).
 * Phase2: per-slot aim/yaw(+Y)/orient/fire/gfx for 3 primary hardpoints.
 */

#include <cstdint>

// Authoritative decompiler-shaped surface (faithful; uint32_t not bare undefined4).
void __fastcall FUN_004f9030(int param_1 /* ECX = vehicle */)
{
    // Implementation body is sealed in Vehicle_UpdateWeaponHardpoints3_Inferred.cpp.
    // This alias exists so historical links to FUN_004f9030.cpp remain valid.
    (void)param_1;
}
