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
// Ghidra symbol CVOGCharacter_WeaponAllowsKillXpBonus @ 0x004ce340.
// AUDIT-2026-08-05-01 F-027: live asm loads attach object into ECX before CALL
// (not the character). Mode fields +0x100 / +0xac live on that attach object.
// Name is historical; body is a field gate, not weapon math.
char __thiscall CVOGCharacter_WeaponAllowsKillXpBonus(void* thisAttachObject);

// Continent / attach object pointer used by mission dual-hash policy:
//   *(*( *(character+4)+4 ) + character + 0xa8)
static inline void* Character_GetContinentAttach(void* thisCharacter)
{
    return *reinterpret_cast<void**>(
        *reinterpret_cast<std::uint8_t**>(
            *reinterpret_cast<std::uint8_t**>(
                reinterpret_cast<std::uint8_t*>(thisCharacter) + 4) +
            4) +
        reinterpret_cast<std::uintptr_t>(thisCharacter) + 0xa8);
}

bool __thiscall CVOGCharacter_HasCompletedMission(void* thisCharacter, unsigned missionId)
{
    char cVar1;
    std::uint32_t* puVar2;
    void* pvVar3;
    void* attach;

    // If null attach → only global completed hash (+0x538); never +0x53c.
    attach = Character_GetContinentAttach(thisCharacter);
    if (attach == nullptr) {
        pvVar3 = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x538), missionId);
        return pvVar3 != (void*)0x0;
    }

    // Continent-attached: compound condition (preserve decompiler nesting).
    // True if:
    //   (no mission table OR def missing OR continent id mismatch OR !mode(attach))
    //   AND completed-hash hit
    // else fall through to instance-hash check.
    // Mode gate thiscall ECX = attach (asm-sealed), fields on attach not character.
    puVar2 = (std::uint32_t*)FUN_0053fff0();
    if ((((((void*)*puVar2 == (void*)0x0) ||
          (pvVar3 = CNDHash_LookupByKey((void*)*puVar2, missionId), pvVar3 == (void*)0x0)) ||
         (*(int*)((int)pvVar3 + 0xfc) != *(int*)((int)attach + 0xfc))) ||
        (cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus(attach), cVar1 == '\0')) &&
       (pvVar3 = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x538), missionId),
        pvVar3 != (void*)0x0))
    {
        return true;
    }

    // Instance-completed hash (+0x53c) when mode(attach) nonzero.
    cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus(attach);
    if ((cVar1 != '\0') &&
        (pvVar3 = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x53c), missionId),
         pvVar3 != (void*)0x0))
    {
        return true;
    }
    return false;
}
