// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: CNDHash_LookupByKey×4, CVOGCharacter_HasCompletedMission×2, CVOGCharacter_WeaponAllowsKillXpBonus×2, FUN_0053fff0, completed, hash.
//  - Return sites: 4.

// =============================================================================
// CVOGCharacter_HasCompletedMission
// -----------------------------------------------------------------------------
// Purpose:  True if missionId is treated as completed for this character.
//           NOT a naïve OR of +0x538 and +0x53c:
//             - null continent attach (+0xa8) → +0x538 only
//             - attached Path A: (no def / +0xfc mismatch / !mode) && +0x538
//             - attached Path B: mode && +0x53c
//             - attached + mode + def OK + +0xfc match → only Path B (538-only false)
//           Mode gate = WeaponAllowsKillXpBonus (+0x100==0 && +0xac!=2), not weapon math.
//           Used to gate re-offers, prereqs, interact icons, logic var type 9.
//
// Address:  0x0052aa20  (autoassault.exe, image base 0x400000)
// Stable:   aa_0052aa20
// System:   missions-progression
//
// Convention: MSVC __thiscall  (this = CVOGCharacter* in ECX)
//
// Callers:  CVOGCharacter_CheckMissionRequirements (prereq loop at mission+0x9c),
//           other offer / eligibility gates.
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// =============================================================================

#include <cstdint>

// char+0x538 completed, +0x53c instanced-completed (docs/missionState.md §2.1)
// mission def +0xfc continent id for match against continent object +0xfc

void* CNDHash_LookupByKey(void* hash, unsigned missionId);
std::uint32_t* FUN_0053fff0(); // GetMissionDefTableRoot (inferred; returns &hash*)
// Ghidra symbol; in mission CF also gates instance-completed (+0x53c) use.
char CVOGCharacter_WeaponAllowsKillXpBonus();

bool __thiscall CVOGCharacter_HasCompletedMission(void* thisCharacter, unsigned missionId)
{
    char cVar1;
    std::uint32_t* puVar2;
    void* pvVar3;

    // Continent attachment:
    //   *(*( *(this+4)+4 ) + this + 0xa8)
    // If null → only global completed hash.
    if (*(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0xa8 + (int)thisCharacter) == 0) {
        pvVar3 = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x538), missionId);
        return pvVar3 != (void*)0x0;
    }

    // Continent-attached: compound condition (preserve decompiler nesting).
    // True if:
    //   (no mission table OR def missing OR continent id mismatch OR !instanceGate)
    //   AND completed-hash hit
    // else fall through to instance-hash check.
    puVar2 = (std::uint32_t*)FUN_0053fff0();
    if ((((((void*)*puVar2 == (void*)0x0) ||
          (pvVar3 = CNDHash_LookupByKey((void*)*puVar2, missionId), pvVar3 == (void*)0x0)) ||
         (*(int*)((int)pvVar3 + 0xfc) !=
          *(int*)(*(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0xa8 +
                         (int)thisCharacter) +
                  0xfc))) ||
        (cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus(), cVar1 == '\0')) &&
       (pvVar3 = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x538), missionId),
        pvVar3 != (void*)0x0))
    {
        return true;
    }

    // Instance-completed hash (+0x53c) when instance gate nonzero.
    cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus();
    if ((cVar1 != '\0') &&
        (pvVar3 = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x53c), missionId),
         pvVar3 != (void*)0x0))
    {
        return true;
    }
    return false;
}
