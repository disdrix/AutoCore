// =============================================================================
// RETIRED SCAFFOLD — do not use as canonical name
// -----------------------------------------------------------------------------
// Stable ID: aa_004023f0
// Address:   0x004023f0
// Retired:   2026-08-05 MEGA-052
// Reason:    Parent-seed plate (CVOGReaction_Dispatch) only. Unit is generic
//            MSVC std::list default ctor (myhead@+4, mysize@+8), not reaction logic.
// Canonical: StdList_DefaultCtor_Inferred
// Artifacts: reconstructed-exact/StdList_DefaultCtor_Inferred.cpp
//            reconstructed-exact/FUN_004023f0.cpp
//            reviews/A_aa_004023f0_StdList_DefaultCtor_Inferred.md
//            reviews/B_aa_004023f0_StdList_DefaultCtor_Inferred.md
// =============================================================================

#include <cstdint>

extern "C" void* __fastcall StdList_DefaultCtor_Inferred(void* self);

// Thin redirect kept so old include paths still resolve to the dualed unit.
extern "C" void* __fastcall Named_CalleeOf_CVOGReaction_Dispatch_004023f0(void* self)
{
    return StdList_DefaultCtor_Inferred(self);
}
