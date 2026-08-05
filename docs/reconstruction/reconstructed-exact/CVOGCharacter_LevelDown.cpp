// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×10, for×2, return×1.
//  - Notable callees: Experience_EnsureLevelTableLoaded_INFERRED×2, CONCAT22, CVOGCharacter_LevelDown, CVOGCharacter_SearchAutoMissions, FUN_004c2ee0, FUN_004c2ef0, FUN_004c2f00, FUN_004c2f10.
//  - Return sites: 1.

// =============================================================================
// CVOGCharacter_LevelDown
// -----------------------------------------------------------------------------
// Purpose:  Reverse one character level: look up the CURRENT level's
//           tExperienceLevel row, decrement nLevel, subtract skill/attribute
//           grants (clamped >= 0), optional odd-level base-stat tweaks,
//           vehicle pool recalc, SearchAutoMissions if local.
//
// Address:  0x005330e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005330e0
// System:   missions-progression / XP
//
// Convention: MSVC __fastcall (this in ECX; decompiler surface)
//   this = CVOGCharacter*
//
// Returns:  void
//
// Character fields (VERIFIED by stores in this body):
//   +0x6c8  nLevel (int) - lookup key BEFORE decrement, then --
//   +0x6cc  wSkillPoints pool (short) - -= row+0x14 short; clamp >= 0
//   +0x6ce  wAttributePoints pool (short) - -= row+0x16 short; clamp >= 0
//   +0x13c / +0x13e / +0x140 / +0x142  base-stat shorts (odd-level path only)
//   +0x250  vehicle* → Vehicle_RecalcCombatPools
//   +0x12c (300) ← copy of +0x12e after vtable +0x5c
//   +0x4f2  byte flag = 1
//   dirty flags dual-base +0x180 |= 0x80
//
// NOTE: Research pool (+0x580) is granted in LevelUp but NOT reversed here
//       (no store to +0x580 in this body - do not invent a research reverse).
//
// Algorithm:
//   1) Ensure experience-level table loaded
//   2) Lower-bound map by CURRENT level (+0x6c8); bail if end
//   3) Dirty |0x80; nLevel--; subtract skill/attrib from row; clamp pools
//   4) if (level after dec) is odd: decrement four base-stat shorts via helpers
//   5) Vehicle_RecalcCombatPools if vehicle present
//   6) Vtable +0x5c; copy +0x12e → +0x12c; +0x4f2 = 1
//   7) If local flag +0x7e: SearchAutoMissions
//
// Callers: CVOGReaction_AddExperience negative-XP level-down loop
// Exactness: Behavior-preserving rewrite of raw decompile (2026-07-23).
// Dual reviews: reviews/A_aa_005330e0_review.md, reviews/B_aa_005330e0_review.md
// =============================================================================

#include <cstdint>

// Experience level table
extern int   g_nExperienceLevelTableReady;
extern void* g_pExperienceLevelMap_INFERRED;
extern void* g_pExperienceLevelMapEnd;
void         Experience_EnsureLevelTableLoaded_INFERRED();
void         StdMap_LowerBoundByIntKey_INFERRED(void* map, void* outIt, int* pKey);

// Odd-level base-stat helpers (args as decompiled)
void FUN_004c2ef0(unsigned argPack);
void FUN_004c2ee0(short nNewOrDelta);
void FUN_004c2f00(short nNewOrDelta);
void FUN_004c2f10(short nNewOrDelta);
void Vehicle_RecalcCombatPools(void* pVehicle);
void CVOGCharacter_SearchAutoMissions(void* character);

// MSVC x86 oddness idiom: (x & 0x80000001) with negative adjustment ≈ (x % 2)
// used so "if (nLevel & 1)" survives decompiler. Keep exact pattern.

void __fastcall CVOGCharacter_LevelDown(void* thisCharacter)
{
    unsigned* pLevel;           // pKey - points at char+0x6c8
    uint8_t*  pbDirtyFlags;     // pbVar1
    void*     pMapNode;         // pvVar2 - experience map node for CURRENT level
    int*      extraout_EAX;     // map lower_bound result via EAX
    unsigned  uOddCheck;        // uVar3 - MSVC modulo-2 residue
    void*     pScratch;         // local_4 - reused as map out-it / this scratch
    int       nDualBaseOff;     // pLevelRow in raw - dual-base offset dword

    pScratch = thisCharacter;
    if (g_nExperienceLevelTableReady == 0) {
        Experience_EnsureLevelTableLoaded_INFERRED();
    }

    // ----- 1-2) Lookup CURRENT level row (before decrement) -----
    pLevel = (unsigned*)((int)thisCharacter + 0x6c8);
    StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED, &pScratch,
                                     (int*)pLevel);
    pMapNode = (void*)*extraout_EAX;
    if (g_nExperienceLevelTableReady == 0) {
        Experience_EnsureLevelTableLoaded_INFERRED();
    }

    if (pMapNode != g_pExperienceLevelMapEnd) {
        // ----- 3) Dirty + level-- + reverse skill/attrib grants -----
        nDualBaseOff = *(int*)(*(int*)((int)thisCharacter + 4) + 4);
        pbDirtyFlags = (uint8_t*)(nDualBaseOff + 0x180 + (int)thisCharacter);
        *pbDirtyFlags = *pbDirtyFlags | 0x80;

        *pLevel = *pLevel - 1;

        // Attribute pool (+0x6ce) -= row+0x16 (high half of packed grants)
        *(short*)((int)thisCharacter + 0x6ce) =
            *(short*)((int)thisCharacter + 0x6ce) - *(short*)((int)pMapNode + 0x16);
        if (*(short*)((int)thisCharacter + 0x6ce) < 0) {
            *(uint16_t*)((int)thisCharacter + 0x6ce) = 0;
        }

        // Skill pool (+0x6cc) -= row+0x14 (low half)
        *(short*)((int)thisCharacter + 0x6cc) =
            *(short*)((int)thisCharacter + 0x6cc) - *(short*)((int)pMapNode + 0x14);
        if (*(short*)((int)thisCharacter + 0x6cc) < 0) {
            *(uint16_t*)((int)thisCharacter + 0x6cc) = 0;
        }

        // ----- 4) Odd-level path: nudge four base-stat shorts down by 1 -----
        // MSVC: abs-style (level & 0x80000001) → 1 when level is odd
        uOddCheck = *pLevel & 0x80000001;
        if ((int)uOddCheck < 0) {
            uOddCheck = (uOddCheck - 1 | 0xfffffffe) + 1;
        }
        if (uOddCheck == 1) {
            // +0x13e / +0x13c / +0x140 / +0x142 decremented via attribute helpers
            FUN_004c2ef0(
                ((unsigned)nDualBaseOff & 0xffff0000) |
                (unsigned short)(*(short*)((int)thisCharacter + 0x13e) + -1));
            FUN_004c2ee0(*(short*)((int)thisCharacter + 0x13c) + -1);
            FUN_004c2f00(*(short*)((int)thisCharacter + 0x140) + -1);
            FUN_004c2f10(*(short*)((int)thisCharacter + 0x142) + -1);
        }

        // ----- 5) Vehicle combat pools -----
        if (*(void**)((int)thisCharacter + 0x250) != (void*)0x0) {
            Vehicle_RecalcCombatPools(*(void**)((int)thisCharacter + 0x250));
        }

        // ----- 6) Generic refresh + flag -----
        (**(int (**)())(*(int*)thisCharacter + 0x5c))();
        *(uint16_t*)((int)thisCharacter + 300) =
            *(uint16_t*)((int)thisCharacter + 0x12e);
        *(uint8_t*)((int)thisCharacter + 0x4f2) = 1;

        // ----- 7) Local-player auto-missions -----
        if (*(char*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0xa8 +
                             (int)thisCharacter) +
                     0x7e) != '\0') {
            CVOGCharacter_SearchAutoMissions(thisCharacter);
        }
    }
    return;
}
