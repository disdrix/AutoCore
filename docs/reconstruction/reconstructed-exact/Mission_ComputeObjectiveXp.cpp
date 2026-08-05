// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: Experience_EnsureLevelTableLoaded_INFERRED×4, Experience_EnsureQuestXpTableLoaded_INFERRED×2, StdMap_LowerBoundByIntKey_INFERRED×2, Map_LowerBoundFindByIntKey, Mission_ComputeObjectiveXp, XPIndex, amount, fXPBalanceScaler.
//  - Return sites: 4.

// =============================================================================
// Mission_ComputeObjectiveXp
// -----------------------------------------------------------------------------
// Purpose:  Integer mission-complete XP from objective XPIndex fraction ×
//           objective scalers × tExperienceLevel span at mission TargetLevel.
//
// Address:  0x0059dde0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0059dde0
// System:   missions-progression
//
// Convention: MSVC __fastcall (decompiler); arg = CVOGObjective*
// Returns:  int XP (trunc toward zero). Grant path applies
//           ± g_flMissionXpRoundBias (0.5001f @ 0x00aaa6d0) in CompleteObjective
//           before AddExperience — NOT in this function.
//
// Objective / mission offsets (INFERRED, plate-verified vs wad in XP.md):
//   objective +0x13c  short  wXPIndex → tQuestXPLookup key
//   objective +0x140  float  fXPScaler
//   objective +0x144  float  fXPBalanceScaler
//   objective +0x14c  ptr    mission def* (null → return 0)
//   mission   +0x11c  short  TargetLevel
//
// Map protocol (sealed 2026-07-29 via helper image + body):
//   Helpers: Map_LowerBoundFindByIntKey (nil +0x15) / StdMap… (nil +0x1d)
//   ABI: __thiscall(map*, node** out, int* key); ret 8  (no 4th arg)
//   After call: EAX = out-it*; *EAX = node* (or end); key +0xc; payload +0x10
//   Exact key match only (miss → end → 0). L-1 uses same node* shape.
//
// Algorithm:
//   if !missionDef: return 0
//   lazy-load quest XP map; exact_find(wXPIndex)
//   if miss: return 0
//   spanMult = fXPBalanceScaler * frac * fXPScaler
//   lazy-load level table; exact_find(TargetLevel)
//   if miss: return 0
//   nLevelSpan = threshold[TargetLevel]
//   if TargetLevel > 1:
//     nLevelSpan -= threshold[TargetLevel-1]  (if prev row exists)
//   return (int)(nLevelSpan * spanMult)   // float cast of int, then trunc
//
// Callers (xrefs 2026-07-29):
//   Grant: CVOGReaction_CompleteObjective final (not advance)
//   Presentation: Client_ShowMissionRewardChatToast ×2, FUN_0051f510 (float wrap)
// Exactness: CF mirrors raw; map residual sealed (table payloads / runtime open).
// =============================================================================

#include <cstdint>

// Lazy loaders / map find helpers (names from reconstruction registry)
void Experience_EnsureQuestXpTableLoaded_INFERRED();
void Experience_EnsureLevelTableLoaded_INFERRED();
// Real ABI: MSVC __thiscall — ECX=map*, stack (node** outIt, int* key), ret 8. No 4th arg.
// Declared here as free functions with map* first for readability.
void Map_LowerBoundFindByIntKey(void* mapThis, void** outIt, int* key);
void StdMap_LowerBoundByIntKey_INFERRED(void* mapThis, void** outIt, int* key);

extern int   g_nQuestXpLookupReady;
extern int   g_nExperienceLevelTableReady;
extern void* g_pQuestXpLookupMap_INFERRED;
extern void* g_pQuestXpLookupMapEnd;
extern void* g_pExperienceLevelMap_INFERRED;
extern void* g_pExperienceLevelMapEnd;

int __fastcall Mission_ComputeObjectiveXp(void* pObjective)
{
    void*  pvMapNode;
    void** pOutIt;           // after call, EAX holds this address; *EAX = node*
    int    nLevelSpan;
    int    nLookupKey;
    float  flSpanMult;
    void*  local_4;          // stack out-it for level map
    void*  pPrevNode;
    short  nTargetLevel;

    // Need mission definition pointer
    if (*(int*)((int)pObjective + 0x14c) == 0) {
        return 0;
    }

    // -------------------------------------------------------------------------
    // 1) Quest XP fraction by objective XPIndex (+0x13c) — exact key
    // -------------------------------------------------------------------------
    nLookupKey = (int)*(short*)((int)pObjective + 0x13c);
    if (g_nQuestXpLookupReady == 0) {
        Experience_EnsureQuestXpTableLoaded_INFERRED();
    }
    // Scratch slot reused as out-it storage (decompiler: flSpanMult stack)
    pOutIt = (void**)&flSpanMult;
    Map_LowerBoundFindByIntKey(&g_pQuestXpLookupMap_INFERRED, pOutIt, &nLookupKey);
    pvMapNode = *pOutIt;
    if (g_nQuestXpLookupReady == 0) {
        Experience_EnsureQuestXpTableLoaded_INFERRED();
    }
    if (pvMapNode == g_pQuestXpLookupMapEnd) {
        return 0;
    }

    // spanMult = XPBalanceScaler * frac(+0x10) * XPScaler
    nLookupKey = (int)*(short*)(*(int*)((int)pObjective + 0x14c) + 0x11c); // TargetLevel
    flSpanMult = *(float*)((int)pObjective + 0x144) *
                 *(float*)((int)pvMapNode + 0x10) *
                 *(float*)((int)pObjective + 0x140);

    // -------------------------------------------------------------------------
    // 2) Level-span at TargetLevel from tExperienceLevel — exact key
    // -------------------------------------------------------------------------
    if (g_nExperienceLevelTableReady == 0) {
        Experience_EnsureLevelTableLoaded_INFERRED();
    }
    StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED, &local_4, &nLookupKey);
    pvMapNode = local_4;
    if (g_nExperienceLevelTableReady == 0) {
        Experience_EnsureLevelTableLoaded_INFERRED();
    }
    if (pvMapNode == g_pExperienceLevelMapEnd) {
        return 0;
    }

    nTargetLevel = *(short*)(*(int*)((int)pObjective + 0x14c) + 0x11c);
    nLevelSpan   = *(int*)((int)pvMapNode + 0x10);

    // Span = threshold[L] - threshold[L-1] when L > 1
    if (1 < nTargetLevel) {
        nLookupKey = nTargetLevel + -1;
        if (g_nExperienceLevelTableReady == 0) {
            Experience_EnsureLevelTableLoaded_INFERRED();
        }
        StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED, &local_4, &nLookupKey);
        pPrevNode = local_4;
        if (g_nExperienceLevelTableReady == 0) {
            Experience_EnsureLevelTableLoaded_INFERRED();
        }
        if (pPrevNode != g_pExperienceLevelMapEnd) {
            nLevelSpan = nLevelSpan - *(int*)((int)pPrevNode + 0x10);
        }
    }

    // Trunc toward zero (cast float product to int)
    return (int)((float)nLevelSpan * flSpanMult);
}
