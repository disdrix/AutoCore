// =============================================================================
// FUN_00589bc0  — twin of Skill_HB_ApplyHeatDelta_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00589bc0
// Address:   0x00589bc0–0x00589c69 inclusive (170 B / 0xAA)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / Skill HB combat pools
// Generated: 2026-08-05 MEGA-005 dual seal
// Canonical: docs/reconstruction/reconstructed-exact/Skill_HB_ApplyHeatDelta_Inferred.cpp
// Exactness: Behavior-preserving rewrite from sealed assembly (decompiler wrong).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Scaffold twin kept under Ghidra name for path compatibility.
 * Prefer Skill_HB_ApplyHeatDelta_Inferred as the meaningful export.
 *
 * Sealed facts (MEGA-005):
 * - __cdecl 3 args; bare RET; callers ADD ESP,0xC
 * - amount + → heat, amount − → cool; |amount|<=1 → % max heat (+0x244)
 * - RTTI vehicle / creature→vehicle@+0x250; gate net+0x7E; Vehicle_AddHeat
 * - param_1 source unused in body; return actual +0x150 delta
 */

#include <cstdint>

extern "C" float DAT_00aaa668;
extern "C" float g_flOne;

extern "C" void *__cdecl __RTDynamicCast(
    void *in, long vfDelta, void *srcType, void *targetType, int isReference);

extern "C" void CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern "C" void CVOGVehicle_RTTI_Type_Descriptor;
extern "C" void CVOGCreature_RTTI_Type_Descriptor;

extern "C" void __thiscall Vehicle_AddHeat(void *pVehicle, int nHeatDelta);

extern "C" int Skill_HB_ApplyHeatDelta_Inferred(void *sourceUnused, void *targetObj, float amount);

extern "C" int FUN_00589bc0(void *param_1, void *param_2, float param_3)
{
  return Skill_HB_ApplyHeatDelta_Inferred(param_1, param_2, param_3);
}
