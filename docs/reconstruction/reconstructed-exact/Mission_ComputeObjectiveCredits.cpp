// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: Map_LowerBoundFindByIntKey×3, ceil×3, EnsureQuestBaseCreditsLoaded×2, EnsureQuestCreditsLookupLoaded×2, CreditsIndex, Mission_ComputeObjectiveCredits, ROUND, fCreditScaler.
//  - Return sites: 3.

// =============================================================================
// Mission_ComputeObjectiveCredits
// -----------------------------------------------------------------------------
// Purpose:  Pure calculator for mission-complete credit amount from an objective
//           definition. Grant path: FINAL arm of CVOGReaction_CompleteObjective
//           only (advance never grants). Also read-only for reward UI toast/list.
//
//           Formula (raw plate + body + image 2026-07-29):
//             base = (float)tQuestBaseCredits[mission.wTargetLevel].intBaseCredits
//             frac = tQuestCreditsLookup[objective.wCreditsIndex].rlLevelCredits
//             return FISTP_chop(ceil(fCreditScaler * frac * base))
//             Ghidra ROUND == MSVC float→int with RC=chop (OR AH,0x0C) after ceil;
//             for positive products ceil yields integer-valued double → identity.
//
//           Caller ADDS the result into character currency at +0x720 (64-bit
//           with carry into +0x724) — this function returns a delta, not a total.
//
// Address:  0x0059df20  (autoassault.exe, image base 0x400000)
// Stable:   aa_0059df20
// System:   missions-progression
//
// Convention: MSVC __fastcall (objective pointer in ECX as pObjective)
// Returns:  int credits to add, or 0 on map miss / end sentinel
//
// Objective / mission offsets (this unit):
//   obj+0x13e  short  wCreditsIndex     → tQuestCreditsLookup key
//   obj+0x148  float  fCreditScaler
//   obj+0x14c  ptr    pMissionDef       (NOT null-checked here — unlike XP calc)
//   mission+0x11c short wTargetLevel    → tQuestBaseCredits key
// Map node (Map_LowerBoundFindByIntKey family, flag@+0x15):
//   node+0x0C  int key
//   node+0x10  int base credits  OR  float rlLevelCredits
//   node+0x15  color / is-nil
//
// Ensure loaders (sealed dual residual 2026-07-29):
//   EnsureQuestBaseCreditsLoaded   @ 0x00512870
//   EnsureQuestCreditsLookupLoaded @ 0x00512830
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch;
// re-checked 2026-07-29). Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cmath>

// Globals (quest base credits + credits lookup tables)
extern int   g_nQuestBaseCreditsLoaded_Inferred;
extern void* g_pQuestBaseCreditsMap_Inferred;
extern void* g_pQuestBaseCreditsEndSentinel_Inferred;

extern int   g_nQuestCreditsLookupLoaded_Inferred;
extern void* g_pQuestCreditsLookupMap_Inferred;
extern void* g_pQuestCreditsLookupEndSentinel_Inferred;

void EnsureQuestBaseCreditsLoaded();    // LoadQuestBaseCreditsFromWad path
void EnsureQuestCreditsLookupLoaded();  // LoadQuestCreditsLookupFromWad path

// std::map-like lower_bound by int key; returns iterator* in EAX (modeled return).
// 4th arg is decompiler residual (unaff_EDI).
void** Map_LowerBoundFindByIntKey(
    void* pMap, void* pScratch, int* pKey, void* pThisOrUnused);

// Image ROUND after ceil: FNSTCW; OR AH,0x0C (RC=chop); FISTP; restore CW.
// After ceil on positive values the double is integer-valued → cast is identity.
// Negative products: ceil toward +∞ then chop (can return negative int).
static inline int FistpChopToInt(double x)
{
    return (int)x; // models RC=chop toward zero (MSVC post-ceil convert)
}

int __fastcall Mission_ComputeObjectiveCredits(void* pObjective)
{
    void*  pFracRow;       // pvVar1 — credits-lookup map node
    void** pIter;          // models extraout_EAX*
    int    nTableKey;      // TargetLevel, then CreditsIndex
    float  flBaseCredits;  // (float)base int from base-credits row+0x10
    std::uint8_t abLookupScratch[4];
    void*  pBaseRow;       // pTableRow
    void*  pMapThis;       // unaff_EDI residual
    double dCeiled;

    pMapThis = nullptr;
    (void)pMapThis;

    // -------------------------------------------------------------------------
    // 1) tQuestBaseCredits[mission.wTargetLevel @ missionDef+0x11c]
    //    NOTE: no null-check on obj+0x14c (differs from Mission_ComputeObjectiveXp)
    // -------------------------------------------------------------------------
    nTableKey = (int)*(short*)(*(int*)((int)pObjective + 0x14c) + 0x11c);

    if (g_nQuestBaseCreditsLoaded_Inferred == 0) {
        EnsureQuestBaseCreditsLoaded();
    }

    // Scratch is stack float (decompiler reuses flBaseCredits address as scratch)
    pIter = Map_LowerBoundFindByIntKey(
        &g_pQuestBaseCreditsMap_Inferred,
        &flBaseCredits,
        &nTableKey,
        pMapThis);
    pBaseRow = (void*)*pIter;

    if (g_nQuestBaseCreditsLoaded_Inferred == 0) {
        EnsureQuestBaseCreditsLoaded();
    }

    if (pBaseRow == g_pQuestBaseCreditsEndSentinel_Inferred) {
        return 0;
    }

    // -------------------------------------------------------------------------
    // 2) tQuestCreditsLookup[wCreditsIndex @ obj+0x13e] → frac at row+0x10
    // -------------------------------------------------------------------------
    nTableKey     = (int)*(short*)((int)pObjective + 0x13e);
    flBaseCredits = (float)*(int*)((int)pBaseRow + 0x10);

    if (g_nQuestCreditsLookupLoaded_Inferred == 0) {
        EnsureQuestCreditsLookupLoaded();
    }

    pIter = Map_LowerBoundFindByIntKey(
        &g_pQuestCreditsLookupMap_Inferred,
        abLookupScratch,
        &nTableKey,
        pMapThis);
    pFracRow = (void*)*pIter;

    if (g_nQuestCreditsLookupLoaded_Inferred == 0) {
        EnsureQuestCreditsLookupLoaded();
    }

    if (pFracRow == g_pQuestCreditsLookupEndSentinel_Inferred) {
        return 0;
    }

    // -------------------------------------------------------------------------
    // 3) ceil(CreditScaler * frac * base) → FISTP RC=chop → int grant amount
    // -------------------------------------------------------------------------
    dCeiled = std::ceil(
        (double)(*(float*)((int)pObjective + 0x148) *
                 *(float*)((int)pFracRow + 0x10) *
                 flBaseCredits));
    return FistpChopToInt(dCeiled);
}
