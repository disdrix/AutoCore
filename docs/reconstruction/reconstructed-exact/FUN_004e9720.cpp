// =============================================================================
// FUN_004e9720  (clean twin scaffold)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e9720
// Address:   0x004e9720–0x004e9a9b  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 R13-027 — see named clean for full reconstruction
// Named:     CVOGPhysicsUtils_FindClearSpawnPosition_Inferred
// Exactness: Twin points at named unit; do not diverge control flow.
// =============================================================================

// Prefer:
//   docs/reconstruction/reconstructed-exact/CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.cpp
// Dual A/B: accept-with-gaps (R13-027). Parent: 0x005eb790 query-collect ctor.
// Scaffold Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004e9720 is RETIRED.

#include <cstdint>

bool __cdecl FUN_004e9720(
    void *param_1_host,
    float *param_2_in_pos,
    float param_3_scatter_radius,
    float param_4_sphere_radius,
    float *param_5_out_pos,
    uint32_t param_6_query_cookie,
    unsigned char param_7_max_attempts,
    unsigned char param_8_keep_last_on_fail);

// Implementation lives in CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.cpp
// (same symbol / link-time twin for documentation).
