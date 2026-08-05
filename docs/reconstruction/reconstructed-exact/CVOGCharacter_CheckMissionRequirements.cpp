// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×16, return×10, for×1, do×1, while×1.
//  - Notable callees: level×6, restriction×2, CVOGCharacter_CheckMissionRequirements, CVOGCharacter_HasCompletedMission, FUN_0052ada0, FUN_005405e0, condition, currency.
//  - Return sites: 10.

// =============================================================================
// CVOGCharacter_CheckMissionRequirements
// -----------------------------------------------------------------------------
// Purpose:  Validate race / class / level / discipline / event / prerequisite
//           gates for a mission definition against a character.
//           Called from SearchAutoMissions to decide auto-award eligibility.
//
// Address:  0x005462b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005462b0
// System:   missions-progression
//
// Convention: MSVC __thiscall  (asm-sealed 2026-07-29: RET 4, one stack arg)
//   ECX (`this`)     = mission definition*   (NOT the character — Ghidra name)
//   stack arg0       = character*            (decompiler often misnames pMissionDef)
//   (no stack arg1)  = decompiler third formal was phantom
//
// Returns:
//   -1  hard fail (race/class/level/discipline/event or RequirementsNegative hit)
//    0  all requirements pass
//   >0  first blocking prerequisite mission id (when RequirementsNegative==0)
//
// Mission def offsets (raw body + Mission.Read / WAD layout residual 2026-07-29):
//   +0x90  ReqRace (u16, 0xFFFF = none)
//   +0x92  ReqClass (u16, 0xFFFF = none; client plate often “faction”)
//   +0x94  ReqLevelMin (i32)
//   +0x98  ReqLevelMax (i32, 0 = none)
//   +0x9c  ReqMissionId[4] (u32, 0xFFFFFFFF = empty slot)
//   +0x104 Discipline type id, +0x108 DisciplineValue threshold
//   +0x118 RequirementEventId (-1 = skip)
//   +0x120 RequirementsOred (0 = AND-all prereqs; ≠0 = OR-any)
//   +0x124 RequirementsNegative (0 = require prereqs; ≠0 = invert / block if met)
//
// Character race/class via:
//   charData = *(*( *(char+4)+4 ) + char + 0xac ) → +0x3c → +0x532 race, +0x531 class
// Character level via vtable +0x27c on entity at *(*(char+4)+4)+char+4 chain.
// Discipline balance: FUN_0052ada0(char, type) — map @ char+0x584, end +0x588, value node+0x10.
// Event gate: FUN_005405e0(id) — membership in [DAT_00b04718, DAT_00b0471c).
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// Dual residual: reviews/a_005462b0.md (2026-07-29).
// =============================================================================

#include <cstdint>

// Roles sealed; product symbols open — leave FUN_* until string/RTTI.
int  FUN_0052ada0(int resourceTypeId); // __thiscall(Character*, type) balance; -1 if missing
char FUN_005405e0(int requirementEventId); // 1 if event id active in global vector
bool __thiscall CVOGCharacter_HasCompletedMission(void* character, unsigned missionId);

int __thiscall CVOGCharacter_CheckMissionRequirements(
    void* thisMissionDef,
    int*  pCharacter)
{
    bool bAnyPrereq;
    int* character;
    char cFlagOk;
    bool bPrereqOk;
    int  level;
    int  needed;
    unsigned* pPrereq;
    std::uint8_t bAnyPass;
    unsigned firstFailId;
    int remaining;

    character = pCharacter;

    // -------------------------------------------------------------------------
    // 1-2) Race (+0x90 ReqRace) and class (+0x92 ReqClass) vs character data blob
    // -------------------------------------------------------------------------
    // charRaceByte path:
    //   *(byte*)( *(*( *(char[1]+4) + 0xac + char ) ) + 0x3c ) + 0x532
    // Evidence: raw plate + missionState §2.1 (+0x531 class/faction byte, +0x532 race)
    if (((*(unsigned short*)((int)thisMissionDef + 0x90) != 0xffff) &&
         ((unsigned short)*(std::uint8_t*)(
              *(int*)(*(int*)(*(int*)(pCharacter[1] + 4) + 0xac + (int)pCharacter) + 0x3c) +
              0x532) != *(unsigned short*)((int)thisMissionDef + 0x90))) ||
        ((*(unsigned short*)((int)thisMissionDef + 0x92) != 0xffff &&
          ((unsigned short)*(std::uint8_t*)(
               *(int*)(*(int*)(*(int*)(pCharacter[1] + 4) + 0xac + (int)pCharacter) + 0x3c) +
               0x531) != *(unsigned short*)((int)thisMissionDef + 0x92)))))
    {
        return -1;
    }

    // -------------------------------------------------------------------------
    // 3) Min level: vtable+0x27c() >= mission+0x94
    // -------------------------------------------------------------------------
    level = (**(int (**)())(
        *(int*)(*(int*)(pCharacter[1] + 4) + 4 + (int)pCharacter) + 0x27c))();
    if (level < *(int*)((int)thisMissionDef + 0x94)) {
        return -1;
    }

    // -------------------------------------------------------------------------
    // 4) Max level: if mission+0x98 > 0 and level > max → fail
    // -------------------------------------------------------------------------
    if ((0 < *(int*)((int)thisMissionDef + 0x98)) &&
        (level = (**(int (**)())(
             *(int*)(*(int*)(pCharacter[1] + 4) + 4 + (int)pCharacter) + 0x27c))(),
         *(int*)((int)thisMissionDef + 0x98) < level))
    {
        return -1;
    }

    // -------------------------------------------------------------------------
    // 5) Discipline: if type (+0x104) >= 0, balance (FUN_0052ada0) must be >= +0x108
    //    Product fields: Discipline / DisciplineValue (Mission.Read). Helper is the
    //    same character resource map used for item currency costs.
    // -------------------------------------------------------------------------
    if ((-1 < *(int*)((int)thisMissionDef + 0x104)) &&
        (needed = *(int*)((int)thisMissionDef + 0x108),
         level = FUN_0052ada0(*(int*)((int)thisMissionDef + 0x104)),
         level < needed))
    {
        return -1;
    }

    // -------------------------------------------------------------------------
    // 6) RequirementEventId at +0x118 (skip if -1); FUN_005405e0 must return nonzero
    // -------------------------------------------------------------------------
    if ((*(int*)((int)thisMissionDef + 0x118) != -1) &&
        (cFlagOk = FUN_005405e0(*(int*)((int)thisMissionDef + 0x118)), cFlagOk == '\0'))
    {
        return -1;
    }

    // -------------------------------------------------------------------------
    // 7) Prerequisites: up to 4 ids at +0x9c (0xFFFFFFFF = empty)
    //    HasCompletedMission(character, id) for each nonempty slot.
    //    Accumulates:
    //      pCharacter reused as "allPass" AND mask (starts as 1)
    //      bAnyPass  OR of individual results
    //      firstFailId first failing id (else 0xFFFFFFFF)
    // -------------------------------------------------------------------------
    bAnyPrereq  = false;
    pCharacter  = (int*)0x1; // allPass accumulator (low byte)
    bAnyPass    = 0;
    firstFailId = 0xffffffffu;
    pPrereq     = (unsigned*)((int)thisMissionDef + 0x9c);
    remaining   = 4;
    do {
        if (*pPrereq != 0xffffffffu) {
            bAnyPrereq = true;
            bPrereqOk  = CVOGCharacter_HasCompletedMission(character, *pPrereq);
            // Decompiler: pMissionDef reused as allPass AND-accumulator (low byte)
            pCharacter = (int*)(unsigned)(((std::uint8_t)(unsigned)(int)pCharacter) & bPrereqOk);
            bAnyPass   = bAnyPass | (std::uint8_t)bPrereqOk;
            if ((!bPrereqOk) && (firstFailId == 0xffffffffu)) {
                firstFailId = *pPrereq;
            }
        }
        pPrereq   = pPrereq + 1;
        remaining = remaining + -1;
    } while (remaining != 0);

    // -------------------------------------------------------------------------
    // Evaluate prereq satisfaction vs RequirementsNegative (+0x124) / Ored (+0x120)
    // -------------------------------------------------------------------------
    // RequirementsNegative == 0 (require prereqs):
    //   Ored==0 → fail firstFailId if !allPass
    //   Ored!=0 → fail firstFailId if !anyPass
    // RequirementsNegative != 0 (invert — block if prereqs met):
    //   Ored==0 → return -1 if allPass
    //   Ored!=0 → return -1 if anyPass
    if (bAnyPrereq) {
        if (*(int*)((int)thisMissionDef + 0x124) == 0) {
            if ((((std::uint8_t)(unsigned)(int)pCharacter) == '\0') &&
                ((*(int*)((int)thisMissionDef + 0x120) == 0 || (bAnyPass == 0))))
            {
                return (int)firstFailId;
            }
        } else if ((((std::uint8_t)(unsigned)(int)pCharacter) != '\0') ||
                   ((*(int*)((int)thisMissionDef + 0x120) != 0 && (bAnyPass != 0))))
        {
            return -1;
        }
    }

    // All requirements satisfied
    return 0;
}
