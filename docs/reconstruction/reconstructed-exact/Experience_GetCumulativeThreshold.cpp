// =============================================================================
// Experience_GetCumulativeThreshold
// -----------------------------------------------------------------------------
// Purpose:  Look up cumulative XP required for `wLevel` from tExperienceLevel
//           (field intExperience at map-entry +0x10). Used by AddExperience
//           level-up/down loops and max-level soft cap.
//
// Address:  0x0052c860  (autoassault.exe, image base 0x400000)
// Stable:   aa_0052c860
// System:   missions-progression  (XP table helper)
//
// Convention: MSVC __cdecl
//   wLevel - level key (ushort)
//
// Returns:  cumulative XP for that level, or 0x7FFFFFFF if missing (max sentinel)
//
// Side effects:
//   Lazy-inits the experience level table via
//   Experience_EnsureLevelTableLoaded_INFERRED when g_nExperienceLevelTableReady==0
//   (checked twice in decompile - once before lower_bound, once after).
//
// Map entry type: ExperienceLevelMapEntry_INFERRED
//   +0x10  intExperience (uint cumulative threshold)
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// Note: extraout_EAX is the decompiler's way of showing that lower_bound leaves
//       an iterator pointer in EAX; the next load is *EAX → node*.
// =============================================================================

#include <cstdint>

// Globals (inferred names from plate / docs/XP.md)
extern int   g_nExperienceLevelTableReady;
extern void* g_pExperienceLevelMap_INFERRED; // std::map-like root / head
extern void* g_pExperienceLevelMapEnd;       // end iterator sentinel

void Experience_EnsureLevelTableLoaded_INFERRED();

// MSVC std::map::lower_bound by int key - decompiler shape:
//   StdMap_LowerBoundByIntKey_INFERRED(&map, &scratch, &key)
// Returns iterator* in EAX (modeled as return value here).
void** StdMap_LowerBoundByIntKey_INFERRED(void* pMap, void* pScratch, int* pKey);

unsigned __cdecl Experience_GetCumulativeThreshold(unsigned short wLevel)
{
    void* pEntry;    // pvVar1 - map node from *iterator
    unsigned nXp;    // uVar2
    void* abScratch; // lower_bound scratch (decompiler local)
    void** pIter;    // models extraout_EAX (iterator*)

    // Decompiler stores zero-extended level (unused beyond key to lower_bound)
    unsigned _wLevel = (unsigned)wLevel;
    (void)_wLevel;

    // Lazy init #1
    if (g_nExperienceLevelTableReady == 0) {
        Experience_EnsureLevelTableLoaded_INFERRED();
    }

    // lower_bound(map, wLevel) - key is the stack ushort viewed as int*
    pIter = StdMap_LowerBoundByIntKey_INFERRED(
        &g_pExperienceLevelMap_INFERRED,
        &abScratch,
        (int*)&wLevel);

    // Raw: pvVar1 = (void*)*extraout_EAX
    pEntry = (void*)*pIter;

    // Lazy init #2 (re-check after lower_bound)
    if (g_nExperienceLevelTableReady == 0) {
        Experience_EnsureLevelTableLoaded_INFERRED();
    }

    // Default: missing → 0x7FFFFFFF sentinel (blocks level-up loops in AddExperience)
    nXp = 0x7fffffffu;
    if (pEntry != g_pExperienceLevelMapEnd) {
        nXp = *(unsigned*)((int)pEntry + 0x10); // intExperience
    }
    return nXp;
}
