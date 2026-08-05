// READABILITY (auto CF):
//  - Body size: ~169 non-empty decompiler lines.
//  - Control keywords: if×16, while×3, do×2, return×2, for×1, goto×1.
//  - Notable callees: Experience_EnsureLevelTableLoaded_INFERRED×2, FUN_004022a0×2, __RTDynamicCast×2, CVOGCharacter_LevelUp, CVOGCharacter_SearchAutoMissions, Client_SendLogicUiPacket, ExperienceLevelMapEntry_INFERRED, FUN_004294f0.
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_LevelUp
// -----------------------------------------------------------------------------
// Purpose:  Apply one character level gain from the tExperienceLevel map:
//           increment nLevel, grant skill/attribute/research pools, refresh
//           skill HB / attributes / vehicle combat pools, optional LogicUI 0x2D.
//
// Address:  0x00532d30  (autoassault.exe, image base 0x400000)
// Stable:   aa_00532d30
// System:   missions-progression / XP
//
// Convention: MSVC __thiscall
//   this      = CVOGCharacter*
//   bNotifyUi = if true, send LogicUI packet type 0x2D (level-up toast/HUD)
//
// Returns:  void
//
// Character fields (VERIFIED by stores in this body / XP.md):
//   +0x6c8  nLevel (int) - looked up as (level+1) then ++
//   +0x6cc  wSkillPoints pool (short) - += low 16 of row+0x14
//   +0x6ce  wAttributePoints pool (short) - += high 16 of row+0x14
//   +0x580  wResearchPoints pool (short) - += row+0x18 (low short)
//   +0x250  vehicle / context object* (optional combat-pool recalc)
//   dirty flags via dual-base +0x180 |= 0x80
//
// ExperienceLevel map row (INFERRED layout used here):
//   +0x10  experience threshold dword (loaded, not stored back here)
//   +0x14  packed skill (lo short) + attribute (hi short) grants
//   +0x18  research grant (low short used)
//
// Algorithm:
//   1) Ensure experience-level table loaded
//   2) Lower-bound map by (currentLevel + 1); bail if end iterator
//   3) Dirty |0x80; nLevel++; add skill/attrib/research from row
//   4) Two-pass skill-HB walk (char HB @ dual-base+0xb4, then vehicle+0x250 HB)
//      - refresh AddSkillLevels skill objects that match filters
//   5) Research pool += row; attribute refresh helpers FUN_004c2ef0..f10
//   6) If vehicle: vtable level/HP snapshot → Vehicle_RecalcCombatPools → HP delta
//   7) Vtable +0x5c refresh; copy short +0x12e → +0x12c (300); flag +0x4f2 = 1
//   8) If local flag +0x7e: CVOGCharacter_SearchAutoMissions
//   9) Side helpers FUN_00531330 / FUN_00523e60
//  10) if bNotifyUi: LogicUI type 0x2D with level / HP-delta / UI scalar
//
// Callers: CVOGReaction_AddExperience level-up loop (bNotifyUi=true)
// Exactness: Behavior-preserving rewrite of raw decompile (2026-07-23).
// Dual reviews: reviews/A_aa_00532d30_review.md, reviews/B_aa_00532d30_review.md
// =============================================================================

#include <cmath>
#include <cstdint>

// Windows / CRT
extern void* ExceptionList;
extern unsigned char LAB_009a3cb6;
void LeaveCriticalSection(void* cs);

// Experience level table
extern int   g_nExperienceLevelTableReady;
extern void* g_pExperienceLevelMap_INFERRED;
extern void* g_pExperienceLevelMapEnd;
void         Experience_EnsureLevelTableLoaded_INFERRED();
void         StdMap_LowerBoundByIntKey_INFERRED(void* map, void* outIt, int* pKey);

// Helpers still FUN_* where unresolved
void  FUN_004294f0();
int   FUN_004022a0(void* a, int* pOut);
void  FUN_0053a820();
void  FUN_004c2ef0();
void  FUN_004c2ee0();
void  FUN_004c2f00();
void  FUN_004c2f10();
void  Vehicle_RecalcCombatPools(void* pVehicle);
short FUN_006a3db0();
void  CVOGCharacter_SearchAutoMissions(void* character);
void  FUN_00531330();
void  FUN_00523e60();
void  Client_SendLogicUiPacket();
void* __RTDynamicCast(void* obj, int, void* from, void* to, int /* isRef */);
void  operator_delete(void* p);

// RTTI anchors used in skill-HB filter
extern void* CVOGHBBase_RTTI;
extern void* CVOGHBSkillBase_RTTI;
extern void* CVOGHBSkill_AddSkillLevels_RTTI;

// Level-up UI race scalar table + base (float)
extern float g_flLevelUpUiRace_Inferred[];
extern float g_flLevelUpUiBase_Inferred;

void __thiscall CVOGCharacter_LevelUp(void* thisCharacter, bool bNotifyUi)
{
    void*    pMapNode;          // pvVar1 - experience map node for next level
    int*     piSkillObj;        // piVar2
    short    sUiScalar;         // sVar3 - from FUN_006a3db0 after ceil race scalar
    int*     extraout_EAX;      // map lower_bound result via EAX (decompiler)
    int      iWalkOk;           // iVar4 - skill-HB iterator status
    int      pHbList;           // iVar5 - HB container pointer
    unsigned nSkillCount;       // uVar6
    unsigned nSkillIdx;         // uVar7
    int      iPass;             // iVar8 - 0=char HB, 1=vehicle HB
    int      nLookupLevel;      // key = currentLevel+1; later reused as HP delta
    int      local_16c;
    void*    pCastSkill;        // local_168 - skill RTTI hit
    uint32_t local_164[2];
    void*    pSkillVec;         // skill pointer vector begin
    int      nSkillVecEnd;      // local_158
    uint32_t local_154;
    uint32_t nRowExperience;    // row+0x10 (loaded only)
    uint32_t nSkillAttribPacked; // row+0x14
    uint32_t nResearchGrant;    // row+0x18
    uint32_t uLogicLevel;       // uStack_144 - LogicUI level field
    int      iLogicHpDelta;     // iStack_140
    int      iLogicUiScalar;    // iStack_13c
    uint32_t uLogicZero;        // uStack_128
    uint32_t uLogicType;        // uStack_124 - written then type at uStack_128 path
    uint32_t uLogicArg;         // uStack_120
    void*    pSehPrev;          // local_c
    uint8_t* pSehHandler;       // puStack_8
    uint32_t uSehState;         // local_4
    uint8_t* pbDirtyFlags;

    // SEH frame (raw)
    uSehState = 0xffffffff;
    pSehHandler = &LAB_009a3cb6;
    pSehPrev = ExceptionList;
    nLookupLevel = *(int*)((int)thisCharacter + 0x6c8) + 1;
    nSkillIdx = 0;
    ExceptionList = &pSehPrev;

    // ----- 1) Ensure table + lower_bound(currentLevel + 1) -----
    if (g_nExperienceLevelTableReady == 0) {
        ExceptionList = &pSehPrev;
        Experience_EnsureLevelTableLoaded_INFERRED();
    }
    StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED, &pCastSkill,
                                     &nLookupLevel);
    pMapNode = (void*)*extraout_EAX;
    if (g_nExperienceLevelTableReady == 0) {
        Experience_EnsureLevelTableLoaded_INFERRED();
    }

    if (pMapNode != g_pExperienceLevelMapEnd) {
        // ----- 2) Row fields -----
        nRowExperience = *(uint32_t*)((int)pMapNode + 0x10);
        nSkillAttribPacked = *(uint32_t*)((int)pMapNode + 0x14);
        nResearchGrant = *(uint32_t*)((int)pMapNode + 0x18);

        // Dirty progress flags on dual-base object+0x180
        pbDirtyFlags = (uint8_t*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0x180 +
                                  (int)thisCharacter);
        *pbDirtyFlags = *pbDirtyFlags | 0x80;

        // ----- 3) Level++ and pool grants -----
        *(int*)((int)thisCharacter + 0x6c8) =
            *(int*)((int)thisCharacter + 0x6c8) + 1;
        // skill pool += low short of packed row+0x14
        *(short*)((int)thisCharacter + 0x6cc) =
            *(short*)((int)thisCharacter + 0x6cc) + (short)nSkillAttribPacked;
        // attrib pool += high short of packed row+0x14
        *(short*)((int)thisCharacter + 0x6ce) =
            *(short*)((int)thisCharacter + 0x6ce) +
            (short)((unsigned)nSkillAttribPacked >> 0x10);

        // ----- 4) Skill-HB refresh (two passes: char then vehicle) -----
        nLookupLevel = 0; // reused as HP-delta scratch later; zero here first
        pSkillVec = (void*)0x0;
        nSkillVecEnd = 0;
        local_154 = 0;
        uSehState = 0;
        iPass = 0;
        do {
            if (iPass == 0) {
                // Character skill HB list via dual-base +0xb4
                pHbList = *(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0xb4 +
                                  (int)thisCharacter);
LAB_00532e2f:
                if (pHbList != 0) {
                    local_16c = 0;
                    local_164[0] = 0;
                    FUN_004294f0();
                    iWalkOk = FUN_004022a0(local_164, &local_16c);
                    while (iWalkOk == 0) {
                        // Filter: HB skill with flag +0x639 bit0 and AddSkillLevels type
                        if ((((local_16c != 0) && (*(int*)(local_16c + 0x1c) == 1)) &&
                             (pCastSkill = (void*)__RTDynamicCast(
                                  (void*)local_16c, 0, &CVOGHBBase_RTTI,
                                  &CVOGHBSkillBase_RTTI, 0),
                              pCastSkill != (void*)0x0)) &&
                            (((*(uint8_t*)((int)pCastSkill + 0x639) & 1) != 0 &&
                              (iWalkOk = (int)__RTDynamicCast(
                                   pCastSkill, 0, &CVOGHBSkillBase_RTTI,
                                   &CVOGHBSkill_AddSkillLevels_RTTI, 0),
                               iWalkOk != 0)))) {
                            FUN_0053a820();
                        }
                        iWalkOk = FUN_004022a0(local_164, &local_16c);
                    }
                    // Unlock HB critical section if held (+0x28)
                    if (*(char*)(pHbList + 0x28) != '\0') {
                        *(uint8_t*)(pHbList + 0x28) = 0;
                        LeaveCriticalSection((void*)(pHbList + 4));
                    }
                }
            } else if ((iPass == 1) &&
                       (pHbList = *(int*)((int)thisCharacter + 0x250), pHbList != 0)) {
                // Vehicle-side HB list
                pHbList = *(int*)(*(int*)(*(int*)(pHbList + 4) + 4) + 0xb4 + pHbList);
                goto LAB_00532e2f;
            }
            iPass = iPass + 1;
        } while (iPass < 2);

        // Skill vector post-pass (decompiler builds pSkillVec; often empty here)
        if (pSkillVec == (void*)0x0) {
            nSkillCount = 0;
        } else {
            nSkillCount = (unsigned)(nSkillVecEnd - (int)pSkillVec) >> 2;
        }
        if (nSkillCount != 0) {
            do {
                piSkillObj = *(int**)((int)pSkillVec + nSkillIdx * 4);
                (**(int (**)())(*piSkillObj + 0x14))();
                (**(int (**)())(*piSkillObj + 4))();
                nSkillIdx = nSkillIdx + 1;
            } while (nSkillIdx < nSkillCount);
        }

        // ----- 5) Research grant + attribute refresh helpers -----
        *(short*)((int)thisCharacter + 0x580) =
            *(short*)((int)thisCharacter + 0x580) + (short)nResearchGrant;
        FUN_004c2ef0();
        FUN_004c2ee0();
        FUN_004c2f00();
        FUN_004c2f10();

        // ----- 6) Vehicle combat pools + HP delta for LogicUI -----
        iPass = *(int*)((int)thisCharacter + 0x250);
        if (iPass != 0) {
            // Snapshot pre-recalc "HP" via vehicle dual-base vtable +0x244
            iPass = (**(int (**)())(
                *(int*)(*(int*)(*(int*)(iPass + 4) + 4) + 4 + iPass) + 0x244))();
            Vehicle_RecalcCombatPools(*(void**)((int)thisCharacter + 0x250));
            nLookupLevel = (**(int (**)())(
                *(int*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 0x250) + 4) + 4) + 4 +
                       *(int*)((int)thisCharacter + 0x250)) +
                0x244))();
            nLookupLevel = nLookupLevel - iPass; // HP delta after recalc
        }

        // ----- 7) Generic refresh + short copy + local flag -----
        (**(int (**)())(*(int*)thisCharacter + 0x5c))();
        *(uint16_t*)((int)thisCharacter + 300) =
            *(uint16_t*)((int)thisCharacter + 0x12e);
        // UI race scalar: ceil(raceTable[raceByte] + base)
        ceil((double)(g_flLevelUpUiRace_Inferred
                          [*(uint8_t*)(*(int*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 4) +
                                                            4) +
                                                    0xac + (int)thisCharacter) +
                                           0x3c) +
                                   0x531)] +
                      g_flLevelUpUiBase_Inferred));
        sUiScalar = FUN_006a3db0();
        *(uint8_t*)((int)thisCharacter + 0x4f2) = 1;

        // ----- 8) Local-player auto-missions -----
        if (*(char*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0xa8 +
                             (int)thisCharacter) +
                     0x7e) != '\0') {
            CVOGCharacter_SearchAutoMissions(thisCharacter);
        }

        FUN_00531330();
        FUN_00523e60();

        // ----- 9) Optional LogicUI type 0x2D -----
        if (bNotifyUi) {
            iPass = *(int*)(*(int*)((int)thisCharacter + 4) + 4);
            uLogicType = *(uint32_t*)(iPass + 0x164 + (int)thisCharacter);
            uLogicArg = *(uint32_t*)((int)thisCharacter + iPass + 0x168);
            uLogicLevel = *(uint32_t*)((int)thisCharacter + 0x6c8);
            iLogicHpDelta = nLookupLevel;
            iLogicUiScalar = (int)sUiScalar;
            uLogicZero = 0x2d; // LogicUI type = level-up
            Client_SendLogicUiPacket();
            (void)uLogicType;
            (void)uLogicArg;
            (void)uLogicLevel;
            (void)iLogicHpDelta;
            (void)iLogicUiScalar;
            (void)uLogicZero;
            (void)nRowExperience;
        }

        if (pSkillVec != (void*)0x0) {
            /* WARNING: Subroutine does not return in some CRT configs */
            operator_delete(pSkillVec);
        }
    }

    ExceptionList = pSehPrev;
    return;
}
