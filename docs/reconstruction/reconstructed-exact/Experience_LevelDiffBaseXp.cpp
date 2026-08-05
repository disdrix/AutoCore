// =============================================================================
// Experience_LevelDiffBaseXp
// -----------------------------------------------------------------------------
// Purpose:  Integer base kill XP from level pair vs tCreatureExperienceLevel.
//           Easy/grey path reduces (or zeros) XP when the player is above the
//           victim; hard path boosts lookup level and interpolates when the
//           victim is far above the player.
//
// Address:  0x004c9800  (autoassault.exe, image base 0x400000)
// Stable:   aa_004c9800
// System:   missions-progression / combat XP
//
// Convention: MSVC __cdecl
//   nVictimLevel       dead creature/vehicle level (after call-site prep clamp)
//   nPlayerLevel       killer character level
//   bEnableGreyCheck   true → grey ≥10 levels returns 0 and applies easy slope
//
// Returns:  unsigned base XP (caller multiplies GLOBAL / participation / spree)
//
// Algorithm (docs/XP.md § Level-difference base):
//   diff = player - victim   (kill path pre-clamps |high-low| via victim ≤ player+3)
//
//   Hard (diff < 0):  // victim above player
//     hardDiff = max(diff, -9)          // 0xfffffff7 when diff ≤ -10
//     base = CreatureXP[player - hardDiff]   // boosted row (e.g. player+3)
//     if diff < hardDiff:               // only when clamped (extra beyond -9)
//       return base + trunc(abs(diff - hardDiff) * base * 0.005)
//     return base
//
//   Easy / grey (diff ≥ 0):
//     if bEnableGreyCheck && diff ≥ 10: return 0
//     base = CreatureXP[victim]
//     if bEnableGreyCheck && diff > 0:
//       adj = ROUND(|diff| * 1.5 * base * -0.1)   // ≈ -15% of base per level
//       base = max(0, base + adj)                 // bit-mask clamp in binary
//     return base
//
// Globals (image):
//   g_dGreyKillSlopeA        @ 0x009CBB68 = 1.5   (double)
//   g_dGreyKillSlopeB        @ 0x009CBB60 = -0.1  (double)
//   g_flHardKillInterpolate  @ 0x00AAA6A4 = 0.005f
//
// Callers: CVOGCombat_CalculateAndAwardKillXP (grey=true)
// Exactness: Behavior-preserving rewrite of raw decompile (2026-07-23).
// =============================================================================

#include <cstdint>

// Creature XP table row lookup (tCreatureExperienceLevel)
unsigned Experience_GetCreatureXpForLevel(int nLevel);

// MSVC / x87 ROUND helper used by decompiler surface for easy-path adj
extern "C" double ROUND(double x);

extern double g_dGreyKillSlopeA;       // 1.5  @ 0x009CBB68
extern double g_dGreyKillSlopeB;       // -0.1 @ 0x009CBB60
extern float  g_flHardKillInterpolate; // 0.005f @ 0x00AAA6A4

// Arithmetic abs for signed int via arithmetic right-shift sign mask
// (matches decompiler: (x ^ (x>>31)) - (x>>31)).
static inline int AbsI32(int x)
{
    int sign = x >> 31;
    return (x ^ sign) - sign;
}

unsigned __cdecl Experience_LevelDiffBaseXp(
    int  nVictimLevel,
    int  nPlayerLevel,
    bool bEnableGreyCheck)
{
    unsigned nBaseXp;
    unsigned nAbsExtraSign;
    unsigned nLevelDiff;
    unsigned nHardDiffClamped;
    int      nEasyAdj;

    // -------------------------------------------------------------------------
    // diff = player - victim  (signed; stored as unsigned bit pattern in binary)
    // -------------------------------------------------------------------------
    nLevelDiff = (unsigned)(nPlayerLevel - nVictimLevel);

    // =========================================================================
    // HARD: victim above player (signed diff < 0)
    // =========================================================================
    if ((int)nLevelDiff < 0) {
        // Clamp hard diff floor to -9 (0xfffffff7); keep raw when -9 < diff < 0
        // i.e. when -10 < diff (diff in [-9, -1]), use nLevelDiff as-is.
        nHardDiffClamped = 0xfffffff7; // -9
        if (-10 < (int)nLevelDiff) {
            nHardDiffClamped = nLevelDiff;
        }

        // Boosted creature-XP row: player - hardDiff  (e.g. hardDiff=-3 → player+3)
        nBaseXp = Experience_GetCreatureXpForLevel(nPlayerLevel - (int)nHardDiffClamped);

        // Extra beyond the -9 clamp: floor(abs(extra) * base * 0.005)
        // Only fires when raw diff is more negative than the clamp.
        if ((int)nLevelDiff < (int)nHardDiffClamped) {
            // abs(nLevelDiff - nHardDiffClamped) via sign-mask idiom (same as AbsI32)
            nAbsExtraSign = (unsigned)((int)(nLevelDiff - nHardDiffClamped) >> 31);
            return nBaseXp +
                   (unsigned)(int)((float)(int)(((nLevelDiff - nHardDiffClamped) ^
                                                 nAbsExtraSign) -
                                                nAbsExtraSign) *
                                   (float)(int)nBaseXp * g_flHardKillInterpolate);
        }
        return nBaseXp;
    }

    // =========================================================================
    // EASY / GREY: player at or above victim (signed diff ≥ 0)
    // =========================================================================

    // Grey: ≥10 levels above → worthless (0 XP) when grey-check enabled
    if ((9 < (int)nLevelDiff) && bEnableGreyCheck) {
        return 0;
    }

    nBaseXp = Experience_GetCreatureXpForLevel(nVictimLevel);

    // Easy slope: ~-15% of base per level above victim (only when grey-check on)
    if (bEnableGreyCheck && (0 < (int)nLevelDiff)) {
        // adj = ROUND(|diff| * 1.5 * base * -0.1)
        nEasyAdj = (int)(long long)ROUND(
            (double)AbsI32((int)nLevelDiff) * g_dGreyKillSlopeA *
            (double)(int)nBaseXp * g_dGreyKillSlopeB);

        // max(0, base + adj):
        //   (base+adj) & (((base+adj) < 0) - 1)
        // negative sum → mask 0; non-negative → mask all-ones
        nBaseXp = (unsigned)(((int)nBaseXp + nEasyAdj) &
                             ((((int)nBaseXp + nEasyAdj) < 0) - 1));
    }

    return nBaseXp;
}
