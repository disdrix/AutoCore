// READABILITY (auto CF):
//  - Body size: ~376 non-empty decompiler lines.
//  - Control keywords: if×43, return×9, goto×5, do×3, while×3, for×3.
//  - Notable callees: CNDHash_LookupByKey×8, FUN_007a6de0×7, FUN_007a4480×6, sprintf×3, Client_GetMissionCompleteAudioTable×2, Client_PlayNamedInterfaceSound×2, Client_SendLogicUiPacket×2, FUN_00519660×2.
//  - Strings: "Finishing mission %d"; "Finishing mission %d.\n"; "VOG_DEBUG_STOP"; "Missing mission reward COIdchar:%I64d, coid:%I64d".
//  - Return sites: 9.

// =============================================================================
// CVOGReaction_CompleteObjective
// -----------------------------------------------------------------------------
// Purpose:  Finish or advance a single objective on the local character.
//           Central mission-progression kernel:
//             - resolve objective in active-objectives hash (char+0x548)
//             - optional GiveMission chain if objective not active
//             - evaluate/force requirement callbacks on pending node
//             - ADVANCE (seq < last): next AddActiveObjective + unlock + skill/attrib
//             - FINAL (last objective): XP/credits/medals/inventory,
//               toast/audio, completed-hash insert, SearchAutoMissions
//
// Address:  0x00533f90  (autoassault.exe, image base 0x400000)
// Stable:   aa_00533f90
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   thisCharacter = CVOGCharacter*  (decompiler: int *param_1)
//   objectiveId   = key into active-objectives hash
//   rewardCoidLo  = optional inventory-reward COID filter (low half)
//   rewardCoidHi  = optional inventory-reward COID filter (high half)
//   forceComplete = non-zero skips requirement eval failures (0x2070 path uses 1)
//
// Returns:  1 on success / dirty path, 0 on reject (missing obj, failed reqs, …)
//
// Character hash dword indices (int* this → byte offset = index * 4):
//   [0x14c] → +0x530  mission-reward inventory table (inferred)
//   [0x14e] → +0x538  completed missions
//   [0x14f] → +0x53c  instance-completed (also completed-insert root here)
//   [0x152] → +0x548  active objectives
//   [0x157] → +0x55c  pending objectives
// Dirty: this[0x18d] |= 0x10 (and |= 1 on credit award)
//
// Callers (prior RE / system map):
//   Client_MissionDialogHandleButton  - local turn-in (do NOT also send 0x2070)
//   Client_RecvCompleteDynamicObjective (0x2070) - force=1  [not RecvObjectiveState]
//   CVOGCharacter_CompleteMissionObjectives - bulk
//   CVOGCharacter_EvaluatePendingObjectives - pending eval
//
// Control flow summary:
//   1) Active-objectives hash walk (this[0x152] / +0x548) by objectiveId
//   2) Missing active → if CHAR_FLAG_7E != 0 return 0; else def lookup +
//      type short check + completed reject + CVOGReaction_GiveMission
//   3) Null mission def → 0; log "Finishing mission %d."
//   4) Pending-req walk (this[0x157] / +0x55c): eval vtbl+0x8, action +0x2c;
//      forceComplete bypasses fail; min-pass via FUN_0059d880
//   5) ADVANCE when seq < count-1: next AddActiveObjective, unlock, skill/attrib,
//      dirty-only exit (no XP/credits)
//   6) FINAL when not already completed: XP bias + AddExperience(PacketOrNonKill),
//      64-bit credits, medals, inventory rewards, toast/audio, completed insert,
//      SearchAutoMissions (flag path)
//   7) Return 1 on success/dirty, 0 on reject
//
// Callees (addresses known from sealed siblings / headers):
//   CNDHash_LookupByKey                 hash walk helper
//   CVOGReaction_GiveMission            start missing mission
//   CVOGMission_AddActiveObjective      advance next objective
//   Mission_ComputeObjectiveXp          0x0059dde0  aa_0059dde0
//   Mission_ComputeObjectiveCredits     0x0059df20
//   CVOGReaction_AddExperience          non-kill mission XP
//   CVOGCharacter_AddSkillPoints / AddAttributePoints
//   Client_SendInventoryAddItem         reward inventory
//   CVOGCharacter_SearchAutoMissions    post-complete auto missions
//   Client_RecvCompleteDynamicObjective 0x0080ff00 (caller force=1 via 0x2070)
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// Bit-for-bit vs retail EXE: DEFERRED. Many FUN_* callees unresolved.
// Dual reviews:
//   reviews/A_aa_00533f90_CVOGReaction_CompleteObjective.md
//   reviews/B_aa_00533f90_CVOGReaction_CompleteObjective.md
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

// ---------------------------------------------------------------------------
// Unresolved / cross-unit callees (keep FUN_ when no sealed body)
// ---------------------------------------------------------------------------
void*         CNDHash_LookupByKey(void* hash, unsigned key);
std::uint32_t* FUN_0053fff0(); // mission-def table root
void          FUN_00547920(int mode);  // mission UI/side prep
void          FUN_007a4480(int level, const char* fmt, ...); // log
std::uint32_t CVOGReaction_GiveMission(unsigned missionId); // thiscall often elided
void          CVOGMission_AddActiveObjective(int objectiveDef); // arity tension vs sibling
void          CVOGReaction_UnlockContinentObject(void* character, unsigned unlockId);
void          CVOGCharacter_AddSkillPoints(short newOrTotal);
void          CVOGCharacter_AddAttributePoints(unsigned short newOrTotal);
int           Mission_ComputeObjectiveXp(void* objective);
unsigned      Mission_ComputeObjectiveCredits(void* objective);
bool          CVOGReaction_AddExperience(void* character, int amount, int isKillPath);

// XpIsKillPath: PacketOrNonKill == 0 (mission grants use non-kill path)
enum XpIsKillPath { PacketOrNonKill = 0, KillPath = 1 };

void          FUN_00530550(unsigned medalOrFlagId);
void          FUN_00530610(unsigned a, unsigned b, int c);
void          FUN_00531960(int count);
int           CVOGReaction_RandomUnitScalar();
void          FUN_004cf100(void* missionDef, void* character, void* rewardTable);
void          FUN_004d08c0(void* missionDef, void* character, std::uint16_t roll);
unsigned      CVOGReaction_ResolveObjectTarget(int mode, unsigned coidLo, unsigned coidHi);
void          FUN_005875c0(unsigned* pResolvedId);
void          Client_SendInventoryAddItem(unsigned itemId, int qty);
void          FUN_004d4790(unsigned itemId);
void          FUN_007a69d0();
std::uint32_t FUN_007a6de0(const char* s, std::uint32_t unk);
void          Client_SendLogicUiPacket(unsigned* packet);
void          Client_GetMissionCompleteAudioTable(
                  const char* name, int, std::uint32_t, std::uint32_t, int, int, int, int);
void          Client_PlayNamedInterfaceSound(
                  char* name, std::uint32_t, std::uint32_t, std::uint32_t,
                  std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
void          FUN_0040c5c0(char* toastBuf);
void          FUN_004de9f0();
void          FUN_0053c360(unsigned missionId, void* missionDef, int flags);
std::uint32_t* FUN_0053ada0();
void          FUN_00537d30();
void          FUN_00538b20(unsigned missionId, int flags);
void          FUN_00538bd0(std::uint32_t objectiveId, int flags);
void          FUN_00538e00(unsigned missionId);
void          FUN_00538e50(std::uint32_t objectiveId);
void          CVOGCharacter_EvaluatePendingObjectives(
                  void* character, int reason, void* a, void* b, int c);
void          FUN_0052d8b0(int a, unsigned missionId);
void          CVOGCharacter_SearchAutoMissions(void* character);
int           FUN_0059d880(); // min required-eval pass count (inferred)
void          FUN_00519660(); // medal table ensure-load
void*         FUN_0051a0e0(unsigned medalId);

// Globals
extern float         g_flMissionXpRoundBias; // ~0.5001 @ 0x00AAA6D0
extern float         g_flLevelUpUiBase_Inferred;
extern std::uint32_t DAT_00aaa68c;
extern int           DAT_00b042ec;
extern void*         PTR_LAB_009cf024; // completed-hash node vftable

// Entity-flag at +0x7e via this[1] chain. Used as:
//   - missing-obj early-out when NON-zero (raw: return 0)
//   - inventory rewards / SearchAutoMissions when NON-zero
// Polarity vs "local player" is consistent with XP level-up gating; see residual.
#define CHAR_FLAG_7E(thisChar) \
    (*(char*)(*(int*)(*(int*)((thisChar)[1] + 4) + 0xa8 + (int)(thisChar)) + 0x7e))

std::uint32_t __thiscall CVOGReaction_CompleteObjective(
    int* thisCharacter,
    unsigned objectiveId,
    unsigned rewardCoidLo,
    unsigned rewardCoidHi,
    char forceComplete)
{
    std::uint16_t  rollWord;           // uVar1
    std::uint32_t* pMissionDef;        // puVar2 - mission def from objective+0x14c
    bool           allReqsOk;          // bVar3
    char           reqOk;              // cVar4
    int            iNode;              // iVar5 - hash chain / loop
    void*          pObjective;         // pvVar6 - objective runtime (or def on chain path)
    void*          pCompletedOrNext;   // pvVar7 - completed hit; later next-obj hit
    unsigned       uCredits;           // uVar8
    unsigned       uResolvedItem;      // uVar9
    std::uint32_t  uStrA, uStrB;       // uVar10, uVar11
    std::uint32_t* pMoneyOrMedal;      // puVar12
    void*          pHashHit;           // pvVar13
    std::uint32_t* pHashNode;          // puVar14
    unsigned       uTmp;               // uVar15
    float          flXp;               // fVar16
    char*          pcSound;            // pcVar17
    std::uint32_t  uA, uB, uC, uD, uE; // sound staging (uVar18..uVar22)

    int            nReqPassed;         // local_2e8
    unsigned       local_resolvedId;   // uStack_2e0
    void*          pPendingOrIdx;      // local_2dc
    void*          pRewardTable;       // pvStack_2d8
    void*          pObjectiveSaved;    // local_2d4
    char           toastTitle[128];    // acStack_2d0
    std::uint32_t  toastColor;         // uStack_250
    float          toastScale;         // fStack_24c
    std::uint32_t  toastArgA;          // uStack_248
    std::uint32_t  toastArgB;          // uStack_244
    std::uint32_t  toastArgC;          // uStack_240
    std::uint32_t  toastArgD;          // uStack_23c
    char           toastBody[2];       // acStack_238 (full buffer zeroed via pad)
    std::uint32_t  toastBodyPad[63];   // auStack_236
    unsigned       logicUiPkt[7];      // auStack_138
    std::uint32_t  logicUiType;        // uStack_11c

    // =========================================================================
    // 1) Active-objectives hash lookup (char+0x548 / this[0x152])
    //    Bucket = mask & objectiveId; walk +0xc links; key at +0x10; payload +0x8.
    // =========================================================================
    iNode = *(int*)(*(int*)(*(int*)(thisCharacter[0x152] + 0x10) +
                           (*(unsigned*)(thisCharacter[0x152] + 8) & objectiveId) * 4) + 4);
    if (iNode == 0) {
LAB_00533fd2:
        pObjective = (void*)0x0;
    } else {
        do {
            if (objectiveId == *(unsigned*)(iNode + 0x10)) {
                if (iNode == 0) goto LAB_00533fd2;
                pObjective = *(void**)(iNode + 8);
                goto LAB_00533fd9;
            }
            iNode = *(int*)(iNode + 0xc);
        } while (iNode != 0);
        pObjective = (void*)0x0;
    }
LAB_00533fd9:
    pObjectiveSaved = pObjective;

    // =========================================================================
    // 2) Missing active objective → optional GiveMission chain
    //    When CHAR_FLAG_7E != 0: return 0 (raw). Else resolve objective def,
    //    require type short def[0x3e] != 0, reject if mission already completed
    //    (+0x538), then GiveMission(missionId).
    // =========================================================================
    if (pObjective == (void*)0x0) {
        if (CHAR_FLAG_7E(thisCharacter) != '\0') {
            return 0;
        }
        iNode = (int)FUN_0053fff0();
        if (*(void**)(iNode + 4) == (void*)0x0) {
            return 0;
        }
        pObjective = CNDHash_LookupByKey(*(void**)(iNode + 4), objectiveId);
        if (pObjective == (void*)0x0) {
            return 0;
        }
        // Mission type short at missionDef dword index 0x3e must be non-zero
        if ((short)(*(std::uint32_t**)((int)pObjective + 0x14c))[0x3e] == 0) {
            return 0;
        }
        uTmp = **(std::uint32_t**)((int)pObjective + 0x14c); // mission id = def[0]
        pObjectiveSaved = pObjective;
        pCompletedOrNext = CNDHash_LookupByKey((void*)thisCharacter[0x14e], uTmp);
        if (pCompletedOrNext != (void*)0x0) {
            return 0;
        }
        CVOGReaction_GiveMission(uTmp);
        // Fall through with pObjective still the definition object.
    }

    pMissionDef = *(std::uint32_t**)((int)pObjective + 0x14c);
    if (pMissionDef == (std::uint32_t*)0x0) {
        return 0;
    }

    FUN_00547920(1);
    FUN_007a4480(0xffffffff, "Finishing mission %d.\n", *pMissionDef);

    // =========================================================================
    // 3) Requirement evaluation against pending-objective node (+0x55c)
    //    pCompletedOrNext = completed-mission hit for *pMissionDef (FINAL gate).
    // =========================================================================
    pCompletedOrNext = CNDHash_LookupByKey((void*)thisCharacter[0x14e], *pMissionDef);
    pPendingOrIdx = CNDHash_LookupByKey(
        (void*)thisCharacter[0x157],
        *(unsigned*)((int)pObjective + 0x10));

    if (pPendingOrIdx != (void*)0x0) {
        uTmp = 0;
        allReqsOk = true;
        nReqPassed = 0;
        // Requirement vtable objects in [obj+0x158, obj+0x15c); count = (end-begin)>>2
        // vtable+0x8 = eval(char, pending); vtable+0x2c = action(char, pending)
        while ((iNode = *(int*)((int)pObjective + 0x158), iNode != 0) &&
               (uTmp < (unsigned)(*(int*)((int)pObjective + 0x15c) - iNode >> 2)))
        {
            if ((forceComplete == '\0') &&
                (reqOk = (**(char(**)(int*, void*))(**(int**)(iNode + uTmp * 4) + 8))(
                     thisCharacter, pPendingOrIdx),
                 reqOk == '\0'))
            {
                uTmp = uTmp + 1;
                allReqsOk = false;
            } else {
                (**(void(**)(int*, void*))(
                    **(int**)(*(int*)((int)pObjective + 0x158) + uTmp * 4) + 0x2c))(
                    thisCharacter, pPendingOrIdx);
                nReqPassed = nReqPassed + 1;
                uTmp = uTmp + 1;
            }
        }
        // Min-passed gate: if FUN_0059d880 required count not met and not force → fail
        iNode = FUN_0059d880();
        if ((((iNode < 1) || (iNode = FUN_0059d880(), nReqPassed < iNode)) && (!allReqsOk)) &&
            (forceComplete == '\0'))
        {
            return 0;
        }
        FUN_00538e50(*(std::uint32_t*)((int)pObjective + 0x10));
    }

    // =========================================================================
    // 4) ADVANCE vs FINAL on objective sequence index
    //    obj+0x14 = current sequence byte
    //    (byte)missionDef[0x4c] = objective count
    //    ADVANCE when seq < count - 1
    // =========================================================================
    if ((int)(unsigned)*(std::uint8_t*)((int)pObjective + 0x14) <
        (int)((std::uint8_t)pMissionDef[0x4c] - 1))
    {
        // ---- ADVANCE: next objective (skill/attrib only - no XP/credits) ----
        // Next def from mission objective list: def[0x4f] + 4 + seq*4
        iNode = *(int*)(pMissionDef[0x4f] + 4 +
                        (unsigned)*(std::uint8_t*)((int)pObjective + 0x14) * 4);
        if (iNode == 0) {
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        // Already have next objective active? (+0x548)
        // OVERWRITES pCompletedOrNext - advance never reuses completed-hit after this.
        pCompletedOrNext = CNDHash_LookupByKey(
            (void*)thisCharacter[0x152],
            *(unsigned*)(iNode + 0x10));
        if (pCompletedOrNext == (void*)0x0) {
            CVOGMission_AddActiveObjective(iNode);
            FUN_00538bd0(*(std::uint32_t*)((int)pObjective + 0x10), 0);
            CVOGReaction_UnlockContinentObject(
                thisCharacter,
                *(unsigned*)(iNode + 0x120));
            // Point grants (names as decompiled; pools at +0x6cc / +0x6ce):
            //   AddSkillPoints( attribPool(+0x6ce) + obj+0x130 )
            //   AddAttributePoints( obj+0x134 + skillPool this[0x1b3]==+0x6cc )
            CVOGCharacter_AddSkillPoints(
                *(short*)((int)thisCharacter + 0x6ce) +
                *(short*)((int)pObjective + 0x130));
            CVOGCharacter_AddAttributePoints(
                (unsigned short)*(std::uint8_t*)((int)pObjective + 0x134) +
                (short)thisCharacter[0x1b3]);
        }
        goto LAB_005348f3; // dirty only - skip final UI / completed insert
    }

    // =========================================================================
    // 5) FINAL rewards - only if mission NOT already in completed hash
    //    (pCompletedOrNext still holds step-3 completed-hash lookup)
    // =========================================================================
    if (pCompletedOrNext == (void*)0x0) {
        CVOGCharacter_AddSkillPoints(
            *(short*)((int)thisCharacter + 0x6ce) +
            *(short*)((int)pObjective + 0x130));
        CVOGCharacter_AddAttributePoints(
            (unsigned short)*(std::uint8_t*)((int)pObjective + 0x134) +
            (short)thisCharacter[0x1b3]);

        // XP: Mission_ComputeObjectiveXp → ± g_flMissionXpRoundBias → AddExperience
        if (*(int*)((int)pObjective + 0x14c) == 0) {
            flXp = 0.0f;
LAB_005341de:
            // FINAL: nearest-int XP bias then AddExperience
            flXp = flXp + g_flMissionXpRoundBias;
        } else {
            iNode = Mission_ComputeObjectiveXp(pObjective);
            flXp = (float)iNode;
            if (0.0f <= flXp) goto LAB_005341de;
            flXp = flXp - g_flMissionXpRoundBias;
        }
        CVOGReaction_AddExperience(thisCharacter, (int)flXp, PacketOrNonKill);

        // Credits: 64-bit add into this[0x1c8]/0x1c9] == byte offsets +0x720 / +0x724
        uCredits = Mission_ComputeObjectiveCredits(pObjective);
        pMoneyOrMedal = (std::uint32_t*)(thisCharacter + 0x1c8);
        uTmp = *pMoneyOrMedal;                    // low dword snapshot
        *pMoneyOrMedal = *pMoneyOrMedal + uCredits;
        // FINAL: ComputeMissionCredits then ADD to char money +0x720
        // High dword: sign-extend of uCredits (for negative) + carry from low add
        thisCharacter[0x1c9] =
            thisCharacter[0x1c9] + ((int)uCredits >> 0x1f) +
            (unsigned)((uTmp + uCredits) < uTmp); // CARRY4(uTmp, uCredits)
        thisCharacter[0x18d] = thisCharacter[0x18d] | 1; // currency dirty

        // Medal / flag rewards from mission-def dword indices
        if (pMissionDef[0x40] != 0xffffffffu) {
            FUN_00530550(pMissionDef[0x40]);
        }
        if (pMissionDef[0x43] != 0xffffffffu) {
            FUN_00530610(pMissionDef[0x43], pMissionDef[0x44], 0);
        }
        if (0 < (int)pMissionDef[0x45]) {
            FUN_00531960((int)pMissionDef[0x45]);
        }

        // Inventory rewards - only when CHAR_FLAG_7E != 0
        if (CHAR_FLAG_7E(thisCharacter) != '\0') {
            pObjective = CNDHash_LookupByKey((void*)thisCharacter[0x14c], *pMissionDef);
            pRewardTable = pObjective;
            if ((short)pMissionDef[0x3e] == 0) {
                FUN_004cf100(pMissionDef, thisCharacter, pObjective);
            } else {
                // Seeded roll path for non-type-0 missions
                iNode = CVOGReaction_RandomUnitScalar();
                if (0xfffff < *(int*)(iNode + 0xc)) {
                    *(std::uint32_t*)(iNode + 0xc) = 0;
                }
                rollWord = *(std::uint16_t*)(*(int*)(iNode + 8) + *(int*)(iNode + 0xc) * 2);
                *(int*)(iNode + 0xc) = *(int*)(iNode + 0xc) + 1;
                FUN_004d08c0(pMissionDef, thisCharacter, rollWord);
            }
            // Up to 4 reward COID pairs (8 bytes each) from reward table
            pPendingOrIdx = (void*)0x0;
            do {
                if (pObjective != (void*)0x0) {
                    uTmp = *(unsigned*)((int)pRewardTable + (int)pPendingOrIdx * 8);
                    uCredits =
                        *(unsigned*)((int)pRewardTable + (int)pPendingOrIdx * 8 + 4);
                    if ((uTmp & uCredits) != 0xffffffffu) {
                        uResolvedItem = CVOGReaction_ResolveObjectTarget(1, uTmp, uCredits);
                        if (uResolvedItem == 0) {
                            FUN_007a4480(
                                1,
                                "Missing mission reward COIdchar:%I64d, coid:%I64d",
                                *(std::uint32_t*)(*(int*)(thisCharacter[1] + 4) + 0x164 +
                                                  (int)thisCharacter),
                                *(std::uint32_t*)(*(int*)(thisCharacter[1] + 4) + 0x168 +
                                                  (int)thisCharacter),
                                uTmp,
                                uCredits);
                        } else {
                            local_resolvedId = uResolvedItem;
                            FUN_005875c0(&local_resolvedId);
                            // Filter: all rewards if (lo&hi)==-1, else matching pair only
                            if (((rewardCoidLo & rewardCoidHi) == 0xffffffffu) ||
                                ((rewardCoidLo == uTmp && (rewardCoidHi == uCredits))))
                            {
                                Client_SendInventoryAddItem(uResolvedItem, 1);
                            } else if (*(int*)(*(int*)(thisCharacter[1] + 4) + 0xa8 +
                                               (int)thisCharacter) != 0)
                            {
                                FUN_004d4790(uResolvedItem);
                            }
                        }
                    }
                }
                pPendingOrIdx = (void*)((int)pPendingOrIdx + 1);
                pObjective = pRewardTable;
            } while ((int)pPendingOrIdx < 4);
        }
    }

    // =========================================================================
    // 6) Toast / audio when this is the "primary" local character entity
    //    Compare entity graph identity at +0xe8a0 vs this+vtableBase+4
    // =========================================================================
    if (*(int*)(*(int*)((int)thisCharacter + *(int*)(thisCharacter[1] + 4) + 0xa8) + 0xe8a0) ==
        (int)thisCharacter + *(int*)(thisCharacter[1] + 4) + 4)
    {
        toastBody[0] = '\0';
        toastBody[1] = '\0';
        pHashNode = toastBodyPad;
        for (iNode = 0x3f; iNode != 0; iNode = iNode + -1) {
            *pHashNode = 0;
            pHashNode = pHashNode + 1;
        }
        *(std::uint16_t*)pHashNode = 0;
        FUN_007a69d0();

        if ((short)pMissionDef[0x3e] == 0) {
            // Type 0: "Completed <name>!" + mission_complete_3
            logicUiPkt[0] = *pMissionDef;
            logicUiType = 9;
            Client_SendLogicUiPacket(logicUiPkt);
            uStrA = FUN_007a6de0((const char*)pMissionDef[0x53], 0xffffffffu);
            uStrB = FUN_007a6de0("Completed", 0xffffffffu);
            sprintf(toastBody, "%s %s!", (const char*)uStrB, (const char*)uStrA);
            uE = 0;
            uD = 0x1e;
            uC = 0;
            uB = 0;
            uA = 0xffffffffu;
            uStrB = 0xffffffffu;
            uStrA = 0;
            pcSound = (char*)"mission_complete_3";
            Client_GetMissionCompleteAudioTable(
                "mission_complete_3", 0, 0xffffffffu, 0xffffffffu, 0, 0, 0x1e, 0);
            Client_PlayNamedInterfaceSound(pcSound, uStrA, uStrB, uA, uB, uC, uD, uE);
        } else if (pMissionDef[0x40] == 0xffffffffu) {
            // Type non-0, no medal: "Accepted <name>."
            FUN_00547920(0);
            uStrA = FUN_007a6de0((const char*)pMissionDef[0x53], 0xffffffffu);
            uStrB = FUN_007a6de0("Accepted", 0xffffffffu);
            sprintf(toastBody, "%s %s.", (const char*)uStrB, (const char*)uStrA);
        } else {
            // Medal path: "Earned the <medal> Medal!" + mission_complete_5
            if ((DAT_00b042ec < 1) && (FUN_00519660(), DAT_00b042ec < 1)) {
                FUN_00519660();
            }
            pMoneyOrMedal = (std::uint32_t*)FUN_0051a0e0(pMissionDef[0x40]);
            if (pMoneyOrMedal != (std::uint32_t*)0x0) {
                logicUiPkt[0] = *pMoneyOrMedal;
                logicUiType = 10;
                Client_SendLogicUiPacket(logicUiPkt);
                uTmp = pMoneyOrMedal[1];
                uStrA = FUN_007a6de0("Medal", 0xffffffffu);
                uStrB = FUN_007a6de0((const char*)uTmp, 0xffffffffu);
                uA = FUN_007a6de0("Earned the", 0xffffffffu);
                sprintf(
                    toastBody,
                    "%s %s %s!",
                    (const char*)uA,
                    (const char*)uStrB,
                    (const char*)uStrA);
                uE = 0;
                uD = 0x1e;
                uC = 0;
                uB = 0;
                uA = 0xffffffffu;
                uStrB = 0xffffffffu;
                uStrA = 0;
                pcSound = (char*)"mission_complete_5";
                Client_GetMissionCompleteAudioTable(
                    "mission_complete_5", 0, 0xffffffffu, 0xffffffffu, 0, 0, 0x1e, 0);
                Client_PlayNamedInterfaceSound(pcSound, uStrA, uStrB, uA, uB, uC, uD, uE);
            }
        }
        toastColor = 0xffffffffu;
        toastTitle[0] = '\0';
        strncpy(toastTitle, toastBody, 0x80);
        toastScale = g_flLevelUpUiBase_Inferred;
        toastArgC = 0xffffffffu;
        toastArgD = 0xffffffffu;
        toastArgB = 0;
        toastArgA = DAT_00aaa68c;
        toastColor = 0xffeee3d8u;
        FUN_0040c5c0(toastTitle);
        (void)toastScale;
        (void)toastArgA;
        (void)toastArgB;
        (void)toastArgC;
        (void)toastArgD;
        (void)toastColor;
        (void)logicUiType;
    }

    FUN_004de9f0();

    // =========================================================================
    // 7) Ensure mission present in completed hash (+0x538)
    //    If chain has no non-null payload, FUN_0053c360 insert.
    // =========================================================================
    uTmp = *pMissionDef;
    for (iNode = *(int*)(*(int*)(*(int*)(thisCharacter[0x14e] + 0x10) +
                                (*(unsigned*)(thisCharacter[0x14e] + 8) & uTmp) * 4) +
                        4);
         iNode != 0;
         iNode = *(int*)(iNode + 0xc))
    {
        if (uTmp == *(unsigned*)(iNode + 0x10)) {
            if ((iNode != 0) && (*(int*)(iNode + 8) != 0)) goto LAB_005346e1;
            break;
        }
    }
    FUN_0053c360(uTmp, pMissionDef, 0);
LAB_005346e1:

    // =========================================================================
    // 8) Insert into secondary completed hash (+0x53c / this[0x14f])
    //    Manual node construction when lookup misses (double-check pattern).
    // =========================================================================
    pObjective = (void*)thisCharacter[0x14f];
    uTmp = *pMissionDef;
    local_resolvedId = uTmp;
    if (*(char*)((int)pObjective + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:insert, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    pHashHit = CNDHash_LookupByKey(pObjective, uTmp);
    if (pHashHit == (void*)0x0) {
        pHashHit = CNDHash_LookupByKey(pObjective, uTmp);
        if (pHashHit == (void*)0x0) {
            pHashNode = FUN_0053ada0();
            pHashNode[3] = 0;
            pHashNode[5] = 0;
            pHashNode[6] = 0;
            *(std::uint8_t*)(pHashNode + 1) = 0;
            *pHashNode = (std::uint32_t)&PTR_LAB_009cf024;
            pHashNode[2] = (std::uint32_t)pMissionDef;
            pHashNode[4] = local_resolvedId;
            iNode = *(int*)(*(int*)((int)pObjective + 0x10) +
                            (*(unsigned*)((int)pObjective + 8) & local_resolvedId) * 4);
            pHashNode[3] = *(std::uint32_t*)(iNode + 4);
            *(std::uint32_t**)(iNode + 4) = pHashNode;
            FUN_00537d30();
            if (*(int*)((int)pObjective + 0x18) == 0) {
                *(std::uint32_t**)((int)pObjective + 0x18) = pHashNode;
                *(std::uint32_t**)((int)pObjective + 0x14) = pHashNode;
                pHashNode[6] = 0;
                pHashNode[5] = 0;
            } else {
                *(std::uint32_t**)(*(int*)((int)pObjective + 0x18) + 0x14) = pHashNode;
                pHashNode[5] = 0;
                pHashNode[6] = *(std::uint32_t*)((int)pObjective + 0x18);
                *(std::uint32_t**)((int)pObjective + 0x18) = pHashNode;
            }
            *(int*)((int)pObjective + 0xc) = *(int*)((int)pObjective + 0xc) + 1;
        } else {
            FUN_007a4480(0, "Duplicate hash insert %u, failing out", uTmp);
        }
    }

    // Retire mission/objective active state (double FUN_00538b20 as decompiled)
    FUN_00538b20(*pMissionDef, 0);
    FUN_00538b20(*pMissionDef, 0);
    FUN_00538bd0(*(std::uint32_t*)((int)pObjectiveSaved + 0x10), 0);
    FUN_00538e00(*pMissionDef);

    // Pending re-eval when final rewards ran (pCompletedOrNext still null)
    if (pCompletedOrNext == (void*)0x0) {
        // Decompiler reuses stack slots with float casts of medal id / mission id
        pObjectiveSaved = (void*)(float)(int)pMissionDef[0x40];
        local_resolvedId = *pMissionDef;
        pRewardTable = (void*)(float)(int)local_resolvedId;
        CVOGCharacter_EvaluatePendingObjectives(
            thisCharacter, 6, pRewardTable, pObjectiveSaved, 0);
    }

    FUN_0052d8b0(0, *pMissionDef);

    // Flag-7e path: auto-mission search + dirty, early return
    if (CHAR_FLAG_7E(thisCharacter) != '\0') {
        CVOGCharacter_SearchAutoMissions(thisCharacter);
        thisCharacter[0x18d] = thisCharacter[0x18d] | 0x10;
        return 1;
    }

LAB_005348f3:
    // ADVANCE join + non-flag-7e final join: dirty missions bit only
    thisCharacter[0x18d] = thisCharacter[0x18d] | 0x10;
    return 1;
}
