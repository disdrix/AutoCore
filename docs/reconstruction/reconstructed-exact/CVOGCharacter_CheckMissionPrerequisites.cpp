// =============================================================================
// CVOGCharacter_CheckMissionPrerequisites
// -----------------------------------------------------------------------------
// Purpose:  Character-side mission award bootstrap (not a pure predicate).
//           Walk active hash; if live-active optionally bulk-complete; else
//           look up mission def, optionally enforce race/faction, recursively
//           award prereqs, bridge min level with XP, prep + GiveMission, and
//           optionally CompleteMissionObjectives.
//
// Address:  0x00536540  (autoassault.exe, image base 0x400000)
// Stable:   aa_00536540
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   ECX (`this`)  = CVOGCharacter*
//   stack0        = uint32_t missionId
//   stack1        = char autoComplete   (0 / nonzero)
//   stack2        = char checkLevel     (0 / nonzero)
//
// Returns:
//   1  awarded path success, or already-active + autoComplete force-complete
//   0  reject (def miss / race-faction fail / already-active without autoComplete)
//
// Distinct from CVOGCharacter_CheckMissionRequirements (0x005462b0):
//   Requirements = mission-def this, pure gate, returns -1/0/blockingId.
//   This unit     = character this, mutates state, returns 0/1.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow
//            (raw 2026-07-23; re-decompile confirmed 2026-07-29).
//            Not modernization. Bit-for-bit / runtime / diff: DEFERRED.
//
// Open:
//   - FUN_0052c700 / FUN_0053fff0 product English (shapes sealed)
//   - Server authority of XP bridge
//
// Sealed residual edges 2026-07-29:
//   - def+0x124 = RequirementsNegative (recurse award iff == 0)
//   - prep +0x88 = NPC, +0xfc = AutoAssign
//   - Call sites: self (1,parent); FUN_00536740 (1,1); client 0x00950915 (1,0);
//     debug force-add 0x00954575 (0,0) "Forced add mission"
// =============================================================================

#include <cstdint>

// Inferred / cross-unit callees (not redefined here)
std::uint32_t* FUN_0053fff0(); // mission-def table root (inferred)
void*          CNDHash_LookupByKey(void* hashRoot, unsigned missionId);
int  __thiscall Experience_XpToReachRelativeLevel(void* character, int levelDelta);
// PacketOrNonKill: plate-named third arg to AddExperience (exact enum value not sealed here)
extern int PacketOrNonKill;
void __thiscall CVOGReaction_AddExperience(void* character, int xp, int reason);
void __thiscall FUN_0052c700(void* character, unsigned missionId, std::uint32_t* prepBlob);
std::uint32_t __thiscall CVOGReaction_GiveMission(void* character, unsigned missionId);
char __cdecl CVOGCharacter_CompleteMissionObjectives(unsigned missionId, std::uint32_t reason);

// Forward (recursive)
char __thiscall CVOGCharacter_CheckMissionPrerequisites(
    void* thisCharacter,
    unsigned missionId,
    char autoComplete,
    char checkLevel);

char __thiscall CVOGCharacter_CheckMissionPrerequisites(
    void* thisCharacter,
    unsigned missionId,
    char autoComplete,
    char checkLevel)
{
    std::uint32_t* tableRoot;
    void* missionDef;
    int level;
    int minLevel;
    unsigned* pPrereq;
    int prereqRemain;
    int activeNode;
    int charData;
    std::uint32_t prep[12];

    // -------------------------------------------------------------------------
    // 1) Active-mission hash at character+0x540
    //    bucket = mask & missionId; chain: node+0x10 key, +0xc next, +8 payload
    // -------------------------------------------------------------------------
    activeNode = *(int*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 0x540) + 0x10) +
                           (*(unsigned*)(*(int*)((int)thisCharacter + 0x540) + 8) & missionId) * 4) +
                       4);

    do {
        if (activeNode == 0) {
            goto award_path;
        }

        if (missionId == *(unsigned*)(activeNode + 0x10)) {
            // Key match: live payload (node+8) means already active
            if ((activeNode != 0) && (*(int*)(activeNode + 8) != 0)) {
                if (autoComplete != '\0') {
                    CVOGCharacter_CompleteMissionObjectives(missionId, 1);
                    return '\x01';
                }
                return '\0';
            }
            // Key present but null payload → fall through to award
            goto award_path;
        }

        activeNode = *(int*)(activeNode + 0xc);
    } while (true);

award_path:
    // -------------------------------------------------------------------------
    // 2) Mission def lookup (FUN_0053fff0 + CNDHash_LookupByKey)
    // -------------------------------------------------------------------------
    tableRoot = (std::uint32_t*)FUN_0053fff0();

    // 3) Optional race/faction when checkLevel != 0
    //    Race: strict equality (no 0xFFFF skip in this function).
    //    Faction: 0xFFFF = any, else must match.
    //    Char race/faction via entity chain +0xac → +0x3c → +0x532 / +0x531.
    if ((((void*)*tableRoot != (void*)0x0) &&
         (missionDef = CNDHash_LookupByKey((void*)*tableRoot, missionId),
          missionDef != (void*)0x0)) &&
        ((checkLevel == '\0' ||
          ((charData = *(int*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) +
                                     0xac + (int)thisCharacter) +
                             0x3c),
            *(unsigned short*)((int)missionDef + 0x90) ==
                (unsigned short)*(std::uint8_t*)(charData + 0x532) &&
            ((*(unsigned short*)((int)missionDef + 0x92) == 0xffff ||
              (*(unsigned short*)((int)missionDef + 0x92) ==
               (unsigned short)*(std::uint8_t*)(charData + 0x531)))))))))
    {
        // ---------------------------------------------------------------------
        // 4) Recursive prereq award: only when def+0x124 == 0
        //    Four u32 slots at +0x9c; 0xFFFFFFFF = empty. Return ignored.
        //    Children always get autoComplete=1.
        // ---------------------------------------------------------------------
        if (*(int*)((int)missionDef + 0x124) == 0) {
            pPrereq = (unsigned*)((int)missionDef + 0x9c);
            prereqRemain = 4;
            do {
                if (*pPrereq != 0xffffffffu) {
                    CVOGCharacter_CheckMissionPrerequisites(
                        thisCharacter, *pPrereq, '\x01', checkLevel);
                }
                pPrereq = pPrereq + 1;
                prereqRemain = prereqRemain - 1;
            } while (prereqRemain != 0);
        }

        // ---------------------------------------------------------------------
        // 5) Min level (def+0x94) via entity vtable +0x27c; bridge with XP if low
        // ---------------------------------------------------------------------
        minLevel = *(int*)((int)missionDef + 0x94);
        level = (**(int (**)())(
            *(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 4 +
                    (int)thisCharacter) +
            0x27c))();

        if (level < minLevel) {
            level = (**(int (**)())(
                *(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 4 +
                        (int)thisCharacter) +
                0x27c))();
            // xp = cost to gain (minLevel - level) levels
            minLevel = Experience_XpToReachRelativeLevel(
                thisCharacter, minLevel - level);
            // Third GetLevel call present in raw (return unused)
            (**(int (**)())(
                *(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 4 +
                        (int)thisCharacter) +
                0x27c))();
            CVOGReaction_AddExperience(thisCharacter, minLevel, PacketOrNonKill);
        }

        // ---------------------------------------------------------------------
        // 6) Prep blob + GiveMission + optional bulk complete
        //    Layout matches raw uStack_30..uStack_4 (12 dwords).
        // ---------------------------------------------------------------------
        prep[0]  = 0xffffffffu; // uStack_30
        prep[1]  = 0xffffffffu; // uStack_2c
        prep[2]  = 0xffffffffu; // uStack_28
        prep[3]  = 0xffffffffu; // uStack_24
        prep[4]  = 0xffffffffu; // uStack_20
        prep[5]  = 0xffffffffu; // uStack_1c
        prep[6]  = 0xffffffffu; // uStack_18
        prep[7]  = 0xffffffffu; // uStack_14
        prep[8]  = *(std::uint32_t*)((int)missionDef + 0x88); // uStack_10
        prep[9]  = *(std::uint32_t*)((int)missionDef + 0xfc); // uStack_c
        prep[10] = missionId;                                   // uStack_8
        prep[11] = 0;                                           // uStack_4

        // Ghidra drops this on call sites; sibling GiveMission is character thiscall.
        FUN_0052c700(thisCharacter, missionId, prep);
        CVOGReaction_GiveMission(thisCharacter, missionId);

        if (autoComplete != '\0') {
            CVOGCharacter_CompleteMissionObjectives(missionId, 1);
        }
        return '\x01';
    }

    return '\0';
}
