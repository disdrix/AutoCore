// =============================================================================
// FUN_006189d0  — clean twin of CVOGHBSkill_Common_SpawnPerTargetHB_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006189d0
// Address:   0x006189d0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual:      R12-040 OWN-ONLY 2026-08-05
// Named:     docs/reconstruction/reconstructed-exact/CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.cpp
// Exactness: Behavior-preserving twin for Ghidra symbol stability.
// =============================================================================

#include <cstdint>

// See named clean for full typed reconstruction.
// Ghidra canonical: bool FUN_006189d0(int*, int, int, int, undefined4, undefined4)
// Retail ABI: virtual thiscall (ECX unused) + 6 stack dwords; ret 0x18;
//             EAX = (spawnCount != 0).

bool FUN_006189d0(int *param_1, int param_2, int param_3, int param_4,
                  std::uint32_t param_5, std::uint32_t param_6);

// Implementation lives in CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.cpp
// (FUN_006189d0 is an extern "C" alias of the same CF).
