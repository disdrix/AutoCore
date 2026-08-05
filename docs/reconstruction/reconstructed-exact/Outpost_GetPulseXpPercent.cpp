// =============================================================================
// Outpost_GetPulseXpPercent
// -----------------------------------------------------------------------------
// Purpose:  Index the outpost (or non-outpost) fPercentLevelXP pulse table and
//           return the float percent used by Outpost_ComputePulseXp:
//             amount = round(levelSpan * percent * scalar@+0x21c)
//
// Address:  0x006075b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_006075b0
// System:   missions-progression / outpost XP
//
// Convention: MSVC __fastcall (ECX = this / outpost state object)
//   pOutpost  outpost/state object
//
// Fields (INFERRED from this + Outpost_ComputePulseXp callers):
//   pOutpost+0x220  char  bIsOutpost — non-zero → true-outpost table
//                   DAT_00d029e0; zero → non-outpost table DAT_00d029f0
//   pOutpost+0x23c  int   table row index (must be >= 0 and < row count)
//
// Table layout (vector of 0x10-byte rows at DAT_*):
//   table+0x04  begin pointer
//   table+0x08  end pointer
//   count       = (end - begin) >> 4
//   row[i]+0x08 float fPercentLevelXP  (fraction of current level XP span)
//
// Returns: float10 percent, or g_flZero if index invalid / empty table.
// Fallback FUN_00608620 is the defensive operator[] path (normally unreachable
// once the first count check has passed with a non-null begin).
//
// docs/XP.md § Outpost pulse XP. Sample: true-outpost pulse 0 ≈ 0.0006.
// Exactness: Behavior-preserving rewrite of raw decompile (priority_001 batch).
// =============================================================================

#include <cstdint>

// Vector-ish table header at fixed BSS/data addresses.
struct PulseXpPercentTable {
    void* unused0;   // +0x00
    char* begin;     // +0x04  first row
    char* end;       // +0x08  one-past-last row (stride 0x10)
};

// Row: 16 bytes; fPercentLevelXP lives at +0x08.
struct PulseXpPercentRow {
    uint32_t pad0;   // +0x00
    uint32_t pad1;   // +0x04
    float    fPercentLevelXP; // +0x08
    // +0x0c trailing dword of 0x10 stride
};

extern PulseXpPercentTable DAT_00d029e0; // true-outpost (bIsOutpost != 0)
extern PulseXpPercentTable DAT_00d029f0; // non-outpost  (bIsOutpost == 0)
extern float               g_flZero;

// Defensive table accessor used when second bounds check fails (vector[] style).
float FUN_00608620(/* table/index context from registers */);

float /*float10*/ __fastcall Outpost_GetPulseXpPercent(void* pOutpost)
{
    PulseXpPercentTable* pTable;
    int                  nIndex;
    char*                pBegin;
    unsigned             nCount;
    float                flFallback;

    // -------------------------------------------------------------------------
    // Select percent table: true outpost vs non-outpost
    // -------------------------------------------------------------------------
    pTable = &DAT_00d029e0;
    if (*(char*)((int)pOutpost + 0x220) == '\0') {
        pTable = &DAT_00d029f0;
    }

    nIndex = *(int*)((int)pOutpost + 0x23c);

    // -------------------------------------------------------------------------
    // Valid signed index + in-range of (end-begin)/0x10 rows
    // -------------------------------------------------------------------------
    if (-1 < nIndex) {
        pBegin = pTable->begin;
        if (pBegin == 0) {
            nCount = 0;
        } else {
            nCount = (unsigned)(pTable->end - pBegin) >> 4;
        }

        if ((unsigned)nIndex < nCount) {
            // Second check mirrors MSVC vector operator[] safety; same predicates.
            if ((pBegin != 0) &&
                ((unsigned)nIndex < (unsigned)(pTable->end - pBegin) >> 4)) {
                return ((PulseXpPercentRow*)(pBegin + nIndex * 0x10))->fPercentLevelXP;
            }
            flFallback = FUN_00608620();
            return flFallback;
        }
    }

    return g_flZero;
}
