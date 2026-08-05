// =============================================================================
// FUN_0075de80  (twin of AssManager_SweepTrackedAssets_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0075de80
// Address:   0x0075de80–0x0075e2ce exclusive (1358 B / 0x54E)
// System:    assets / assManager
// Generated: 2026-07-29 W32-O dual seal (replaces 2026-07-23 scaffold body)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical named clean: AssManager_SweepTrackedAssets_Inferred.cpp
// =============================================================================

#include <stdint.h>

/* See AssManager_SweepTrackedAssets_Inferred.cpp for full reconstruction.
 * Ghidra symbol retained as thin twin for path stability. */

void AssManager_SweepTrackedAssets_Inferred(void *self, int mode,
                                            float ageThreshold);

void FUN_0075de80(void *param_1, int param_2, float param_3)
{
  AssManager_SweepTrackedAssets_Inferred(param_1, param_2, param_3);
}
