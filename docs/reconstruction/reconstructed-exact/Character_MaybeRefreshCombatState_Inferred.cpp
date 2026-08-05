// =============================================================================
// Character_MaybeRefreshCombatState_Inferred
// -----------------------------------------------------------------------------
// Purpose:  After a vehicle combat-pool regen tick, accumulate a 64-bit elapsed
//           counter on the character, mark a dirty bit, stamp GetTickCount, and
//           optionally drive objective type-7 evaluation with the elapsed ms as
//           a float (when character owns a linked vehicle/object @ vbase+0xa8).
//
// Address:  0x005355e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005355e0
// System:   combat / character state (INFERRED name)
//
// Convention: MSVC __thiscall
//   this      character object
//   nDeltaMs  additional milliseconds to fold into the accumulator (from caller)
//
// Fields (INFERRED layout on character):
//   +0x8dc  DWORD last GetTickCount stamp
//   +0x928  uint32 low  64-bit elapsed accumulator (ms)
//   +0x92c  uint32 high 64-bit elapsed accumulator
//   +0x634  uint   dirty/flags; |= 1 on every call
//   vbase = *( *(this+4) + 4 ) + this
//   vbase+0xa8  linked owner/vehicle pointer; non-null → evaluate objectives
//
// Caller: VehicleCombatPool_OnTick when owner character present.
// Role:   minor combat/UI/objective refresh after regen pulse - not kill XP.
//         Do not expand RE of this function unless a concrete dependency appears.
//
// Globals:
//   _DAT_00aaa5dc  2^32 as float - used when casting a negative int-as-uint
//                  param to float (unsigned reinterpret path).
//
// Exactness: Behavior-preserving rewrite of raw decompile (priority_001 batch).
// =============================================================================

#include <cstdint>
#include <windows.h>

void CVOGCharacter_EvaluatePendingObjectives(
    void*  pCharacter,
    int    nObjectiveKind,
    float  flElapsedMs,
    int    a4,
    int    a5);

extern float _DAT_00aaa5dc; // 4294967296.0f

void __thiscall Character_MaybeRefreshCombatState_Inferred(void* pCharacter, uint32_t nDeltaMs)
{
    uint32_t* pAccLo;
    uint32_t  nOldLo;
    float     flDeltaAsFloat;
    DWORD     nNow;
    uint32_t  nTickDelta;
    int       pVBase;
    int       pLinkedObj;

    // -------------------------------------------------------------------------
    // Elapsed since last stamp + caller delta → 64-bit add at +0x928/+0x92c
    // -------------------------------------------------------------------------
    nNow       = GetTickCount();
    nTickDelta = nNow - *(int*)((int)pCharacter + 0x8dc);
    pAccLo     = (uint32_t*)((int)pCharacter + 0x928);
    nOldLo     = *pAccLo;
    // 64-bit add: hi += carry(delta, tickDelta) + carry(oldLo, delta+tickDelta)
    // (matches decompiler CARRY4 pair exactly)
    {
        uint32_t nSumDeltaTick = nDeltaMs + nTickDelta;
        uint32_t nCarry0       = (nSumDeltaTick < nDeltaMs) ? 1u : 0u;
        uint32_t nNewLo        = nOldLo + nSumDeltaTick;
        uint32_t nCarry1       = (nNewLo < nOldLo) ? 1u : 0u;
        *pAccLo = nNewLo;
        *(uint32_t*)((int)pCharacter + 0x92c) =
            *(uint32_t*)((int)pCharacter + 0x92c) + nCarry0 + nCarry1;
    }

    // -------------------------------------------------------------------------
    // Dirty bit + refresh last-tick stamp
    // -------------------------------------------------------------------------
    nNow = GetTickCount();
    *(uint32_t*)((int)pCharacter + 0x634) =
        *(uint32_t*)((int)pCharacter + 0x634) | 1;
    *(DWORD*)((int)pCharacter + 0x8dc) = nNow;

    // -------------------------------------------------------------------------
    // If character has linked object (vehicle) at vbase+0xa8, run objective
    // kind 7 with elapsed = (float)nDeltaMs + (float)nTickDelta.
    // Negative nDeltaMs uses +2^32 float adjust (unsigned bit pattern path).
    // -------------------------------------------------------------------------
    pVBase     = *(int*)(*(int*)((int)pCharacter + 4) + 4) + (int)pCharacter;
    pLinkedObj = *(int*)(pVBase + 0xa8);
    if (pLinkedObj != 0) {
        flDeltaAsFloat = (float)(int)nDeltaMs;
        if ((int)nDeltaMs < 0) {
            flDeltaAsFloat = flDeltaAsFloat + _DAT_00aaa5dc;
        }
        CVOGCharacter_EvaluatePendingObjectives(
            pCharacter, 7, flDeltaAsFloat + (float)nTickDelta, 0, 0);
    }
    return;
}
