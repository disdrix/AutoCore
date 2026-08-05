// READABILITY (auto CF):
//  - Body size: ~164 non-empty decompiler lines.
//  - Control keywords: if×23, return×9, while×2, do×1.
//  - Notable callees: Experience_GetCumulativeThreshold×9, pool×2, CVOGCharacter_LevelDown, CVOGCharacter_LevelUp, CVOGCharacter_WeaponAllowsKillXpBonus, CVOGReaction_AddExperience, GetTickCount, PacketOrNonKill.
//  - Return sites: 9.

// =============================================================================
// CVOGReaction_AddExperience
// -----------------------------------------------------------------------------
// Purpose:  Client XP apply kernel (docs/XP.md). Single path that mutates total
//           experience and drives level-up / level-down loops.
//
// Address:  0x00533c30  (autoassault.exe, image base 0x400000)
// Stable:   aa_00533c30
// System:   missions-progression  (XP / progression kernel; also kill path)
//
// Convention: MSVC __thiscall
//   this        = CVOGCharacter*
//   nAmount     = raw XP delta (may be negative)
//   isKillPath  = XpIsKillPath: KillPath enables 5s spree + weapon bonus table
//
// Returns:  false if no XP applied (scaled == 0); true otherwise
//
// Character field offsets (VERIFIED by use in this body):
//   +0x6b4  specialMode (int) - skips max-level soft cap when > 0
//   +0x6c8  nLevel (int)
//   +0x6cc  wSkillPoints pool (short)   [LevelUp writes]
//   +0x6ce  wAttributePoints pool (short)
//   +0x730  nTotalExperience (int)
//   +0x734  dwLastKillTick (DWORD)
//   +0x738  cSpreeOrLevelHint (byte)
//   +0xc50  nMaxLevel (int)
//   +0xc54  flPersonalXpGain (float)
//
// Algorithm:
//   1) if KillPath: update spree 0..5 within 5s window; optional weapon bonus scale
//   2) scaled = (int)(nAmount * flPersonalXpGain)
//   3) at max level (unless specialMode): clamp so total stays < threshold(level)
//   4) if scaled == 0 return false
//   5) nTotalExperience += scaled
//   6) level-up / level-down loops (guard 300) when local-player flag +0x7e set
//
// S2C GiveXP and mission complete use PacketOrNonKill (no spree).
// AutoCore: ExperienceService.GiveXp should mirror cap + personal scalar rules.
//
// Callers:
//   Client_AwardKillExperience          GiveXP 0x205F (PacketOrNonKill)
//   CVOGCombat_CalculateAndAwardKillXP  kill path (KillPath)
//   CVOGReaction_CompleteObjective      mission final XP (PacketOrNonKill)
// Callees: CVOGCharacter_LevelUp / LevelDown; Experience_GetCumulativeThreshold
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// Dual reviews: reviews/A_aa_00533c30_review.md, reviews/B_aa_00533c30_review.md
// =============================================================================

#include <cstdint>
#include <cmath> // ROUND / nearbyint if needed; raw uses ROUND()

// Windows
using DWORD = unsigned long;
DWORD GetTickCount();

// XpIsKillPath
enum XpIsKillPath { PacketOrNonKill = 0, KillPath = 1 };

char     CVOGCharacter_WeaponAllowsKillXpBonus(); // also used as mode gate elsewhere
unsigned Experience_GetCumulativeThreshold(unsigned short wLevel);
void     CVOGCharacter_LevelUp(void* character, bool bNotifyUi);
void     CVOGCharacter_LevelDown(void* character);

// Globals used by kill-path weapon bonus table
extern float g_flOne;
extern float DAT_00aaa7b8; // spree table slot 2
extern float DAT_00aaa8f4; // spree table slot 3
extern float DAT_00aaa8f0; // spree table slots 4..15 (repeated)

// Level getter via vtable slot 0x27c on the entity dual-base chain
//   (**(code**)(*(int*)(*(int*)(*(int*)(this+4)+4)+4+(int)this)+0x27c))()
#define CHAR_VTABLE_GET_LEVEL(thisPtr) \
    ((int(*)())(*(int*)(*(int*)(*(int*)(*(int*)((int)(thisPtr) + 4) + 4) + 4 + (int)(thisPtr)) + \
                       0x27c)))()

// Local / authority flag at entity+0x7e (level loops only when set)
#define CHAR_FLAG_7E_XP(thisPtr) \
    (*(char*)(*(int*)(*(int*)(*(int*)((int)(thisPtr) + 4) + 4) + 0xa8 + (int)(thisPtr)) + 0x7e))

// Raw uses ROUND((table[i] + 1.0f) * amount) - nearest int
static inline int RoundToInt(float x)
{
    // Decompiler ROUND; MSVC typically nearbyint/x87. Keep as cast-of-rounded.
    return (int)(x >= 0.0f ? (x + 0.5f) : (x - 0.5f));
}

bool __thiscall CVOGReaction_AddExperience(
    void* thisCharacter,
    int nAmount,
    XpIsKillPath isKillPath)
{
    char     bWeaponBonusOk;
    unsigned short wLevel;
    DWORD    nowTick;
    int      nTmp;
    int      nPlayerLevel;
    unsigned nThreshold;
    unsigned char cSpreeClamped;
    int      nLevelLoopGuard;
    int      nScaledAmount;
    // Raw lays out float[4] + 12×undefined4 locals as one contiguous 16-float table
    // so aflSpreeBonusTable[nTmp] with nTmp∈[0,15] is well-defined on the stack.
    float    aflSpreeBonusTable[16];

    nLevelLoopGuard = 0;

    // =========================================================================
    // 1) Kill-path only: 5-second spree counter + optional weapon bonus scale
    // =========================================================================
    if (isKillPath != PacketOrNonKill) {
        nowTick = GetTickCount();
        if (nowTick - *(int*)((int)thisCharacter + 0x734) < 5000) {
            // Within spree window: increment, clamp to 5
            *(char*)((int)thisCharacter + 0x738) =
                *(char*)((int)thisCharacter + 0x738) + '\x01';
            cSpreeClamped = *(unsigned char*)((int)thisCharacter + 0x738);
            if (4 < cSpreeClamped) {
                cSpreeClamped = 5;
            }
            *(unsigned char*)((int)thisCharacter + 0x738) = cSpreeClamped;
        } else {
            // Window expired: reset spree
            *(unsigned char*)((int)thisCharacter + 0x738) = 0;
        }
        *(DWORD*)((int)thisCharacter + 0x734) = nowTick;

        bWeaponBonusOk = CVOGCharacter_WeaponAllowsKillXpBonus();
        if (bWeaponBonusOk != '\0') {
            // Index from entity graph +0xe818; clamp to 0..15
            nTmp = *(int*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0xa8 +
                                   (int)thisCharacter) +
                           0xe818);
            // Table: [0]=0, [1]=0, [2]=DAT_aaa7b8, [3]=DAT_aaa8f4, [4..15]=DAT_aaa8f0
            aflSpreeBonusTable[0] = 0.0f;
            aflSpreeBonusTable[1] = 0.0f;
            aflSpreeBonusTable[2] = (float)DAT_00aaa7b8;
            aflSpreeBonusTable[3] = (float)DAT_00aaa8f4;
            for (int i = 4; i < 16; ++i) {
                aflSpreeBonusTable[i] = (float)DAT_00aaa8f0;
            }
            if (0xe < nTmp) {
                nTmp = 0xf;
            }
            // Raw: nAmount = (int)ROUND((aflSpreeBonusTable[nTmp] + g_flOne) * (float)nAmount)
            nAmount = RoundToInt((aflSpreeBonusTable[nTmp] + g_flOne) * (float)nAmount);
        }
    }

    // =========================================================================
    // 2) Personal XP gain scalar  scaled = (int)(nAmount * flPersonalXpGain)
    // =========================================================================
    nTmp = *(int*)((int)thisCharacter + 0xc50); // nMaxLevel
    nScaledAmount =
        (int)((float)nAmount * *(float*)((int)thisCharacter + 0xc54));
    nPlayerLevel = CHAR_VTABLE_GET_LEVEL(thisCharacter);

    // =========================================================================
    // 3) Soft cap at max level (unless specialMode +0x6b4 > 0)
    //    Condition: nMaxLevel < playerLevel+1  &&  specialMode < 1
    //    Clamp scaled so totalXp + scaled <= threshold(level) - 1
    // =========================================================================
    if ((nTmp < nPlayerLevel + 1) && (*(int*)((int)thisCharacter + 0x6b4) < 1)) {
        nTmp = *(int*)((int)thisCharacter + 0x730); // current total XP
        wLevel = (unsigned short)CHAR_VTABLE_GET_LEVEL(thisCharacter);
        nThreshold = Experience_GetCumulativeThreshold(wLevel);
        nTmp = (nThreshold - nTmp) + -1; // room under next threshold
        if (nTmp < nScaledAmount) {
            nScaledAmount = nTmp;
        }
    }

    // =========================================================================
    // 4) No-op if nothing to apply
    // =========================================================================
    if (nScaledAmount == 0) {
        return false;
    }

    // =========================================================================
    // 5) Apply to total experience
    // =========================================================================
    *(int*)((int)thisCharacter + 0x730) =
        *(int*)((int)thisCharacter + 0x730) + nScaledAmount;

    // =========================================================================
    // 6) Level-up / level-down loops - only when entity flag +0x7e is set
    // =========================================================================
    if (CHAR_FLAG_7E_XP(thisCharacter) != '\0') {
        if (nScaledAmount < 1) {
            // ----- Negative XP: de-level or floor at 0 -----
            if (*(int*)((int)thisCharacter + 0x6c8) < 2) {
                // Level < 2: clamp total XP to 0 if negative
                if (*(int*)((int)thisCharacter + 0x730) < 0) {
                    *(std::uint32_t*)((int)thisCharacter + 0x730) = 0;
                    return true;
                }
            } else {
                // Below cumulative threshold of (level-1) → LevelDown loop
                nThreshold = Experience_GetCumulativeThreshold(
                    (unsigned short)(*(short*)((int)thisCharacter + 0x6c8) - 1));
                if (*(int*)((int)thisCharacter + 0x730) < (int)nThreshold) {
                    do {
                        nLevelLoopGuard = nLevelLoopGuard + 1;
                        if (300 < nLevelLoopGuard) {
                            return true; // guard
                        }
                        nThreshold = Experience_GetCumulativeThreshold(
                            *(unsigned short*)((int)thisCharacter + 0x6c8));
                        if (nThreshold == 0x7fffffffu) {
                            return true; // sentinel - table missing
                        }
                        if (*(int*)((int)thisCharacter + 0x6c8) < 1) {
                            return true;
                        }
                        CVOGCharacter_LevelDown(thisCharacter);
                        nThreshold = Experience_GetCumulativeThreshold(
                            (unsigned short)(*(short*)((int)thisCharacter + 0x6c8) - 1));
                    } while (*(int*)((int)thisCharacter + 0x730) < (int)nThreshold);
                }
            }
        } else if ((*(int*)((int)thisCharacter + 0xc50) <
                    *(int*)((int)thisCharacter + 0x6c8) + 1) &&
                   (*(int*)((int)thisCharacter + 0x6b4) < 1))
        {
            // ----- Positive XP but already at max level (no specialMode) -----
            // Soft-clamp total to threshold(level) - 1 if overshot
            nThreshold = Experience_GetCumulativeThreshold(
                *(unsigned short*)((int)thisCharacter + 0x6c8));
            if ((int)nThreshold < *(int*)((int)thisCharacter + 0x730)) {
                nThreshold = Experience_GetCumulativeThreshold(
                    *(unsigned short*)((int)thisCharacter + 0x6c8));
                *(unsigned*)((int)thisCharacter + 0x730) = nThreshold - 1;
                return true;
            }
        } else {
            // ----- Positive XP: level-up while total >= threshold(current) -----
            nThreshold = Experience_GetCumulativeThreshold(
                *(unsigned short*)((int)thisCharacter + 0x6c8));
            if ((int)nThreshold <= *(int*)((int)thisCharacter + 0x730)) {
                // while ( (level < maxLevel || specialMode>0)
                //         && ++guard < 0x12d
                //         && threshold(level) != 0x7FFFFFFF )
                //   LevelUp; if total < new threshold → return
                while ((((*(int*)((int)thisCharacter + 0x6c8) <
                          *(int*)((int)thisCharacter + 0xc50) ||
                          (0 < *(int*)((int)thisCharacter + 0x6b4))) &&
                         (nLevelLoopGuard = nLevelLoopGuard + 1, nLevelLoopGuard < 0x12d)) &&
                        (nThreshold = Experience_GetCumulativeThreshold(
                             *(unsigned short*)((int)thisCharacter + 0x6c8)),
                         nThreshold != 0x7fffffffu)))
                {
                    CVOGCharacter_LevelUp(thisCharacter, true);
                    nThreshold = Experience_GetCumulativeThreshold(
                        *(unsigned short*)((int)thisCharacter + 0x6c8));
                    if (*(int*)((int)thisCharacter + 0x730) < (int)nThreshold) {
                        return true;
                    }
                }
            }
        }
    }
    return true;
}
