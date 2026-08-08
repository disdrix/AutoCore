// =============================================================================
// FUN_0058cc40  — twin of Skill_HB_ApplyShortAndFloater_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0058cc40
// Address:   0x0058cc40–0x0058cd54 inclusive (277 B / 0x115)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / Skill HB combat pools
// Generated: 2026-08-05 MEGA-008 dual seal
// Canonical: docs/reconstruction/reconstructed-exact/Skill_HB_ApplyShortAndFloater_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Scaffold twin kept under Ghidra name for path compatibility.
 * Prefer Skill_HB_ApplyShortAndFloater_Inferred as the meaningful export.
 *
 * Sealed facts (MEGA-008):
 * - __cdecl 3 args; bare RET; callers ADD ESP,0xC
 * - amount + → increase short @+0x12c; amount − → decrease; |amount|<=1 → % max @+0x12e
 * - set via vtbl+0xAC; resolve via vtbl+0x214
 * - floater type 2 via Client_EnqueueCombatFloater_INFERRED
 *   this = *(target+0xA4)+0xE8A4
 */

#include <cstdint>

extern "C" float DAT_00aaa668;
extern "C" float g_flOne;
extern "C" std::uint32_t DAT_009d4d28;
extern "C" std::uint32_t DAT_009d4d2c;
extern "C" std::uint32_t DAT_009d4d30;
extern "C" std::uint32_t DAT_009d4d34;

extern "C" void __thiscall Client_EnqueueCombatFloater_INFERRED(
    void *this_queue,
    void *floaterBlob);

extern "C" int Skill_HB_ApplyShortAndFloater_Inferred(
    void *sourceOrNull,
    void *targetObj,
    float amount);

// Ghidra name entry — delegates to sealed reconstruction
extern "C" int FUN_0058cc40(void *param_1, void *param_2, float param_3)
{
  return Skill_HB_ApplyShortAndFloater_Inferred(param_1, param_2, param_3);
}

// Inline body retained for grep / offline reading (mirrors named clean):
// See Skill_HB_ApplyShortAndFloater_Inferred.cpp for full annotated implementation.
