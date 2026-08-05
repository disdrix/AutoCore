// =============================================================================
// CVOGCharacter_IsMissionJournalReady
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b3b0
// Address:   0x0052b3b0  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0052b3b0
// System:    missions-progression
// Generated: 2026-07-29 seal (last-obj + active-hash + mode-0 readiness)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md
//            reviews/B_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md
// Sibling:   CVOGCharacter_IsMissionTurnInReady (0x0052b420) — mode 1 + NPC
// =============================================================================
//
// PURPOSE:
//   Predicate: is this mission journal-ready / "Complete" for the local character?
//   Used by journal / mission-detail UI (e.g. FUN_0082a050 label "(Complete)").
//   NOT the turn-in claim gate (that is IsMissionTurnInReady / FUN_0052b420).
//
// SEALED GATES:
//   G1 lastObj = mission.objectives[(uint8)mission.objCount - 1]
//      array @ mission+0x13c, count byte @ mission+0x130
//   G2 active-objectives CNDHash @ char+0x548, key = lastObj+0x10;
//      require node and node.value(+0x8) != 0
//   G3 FUN_0052a020(char, lastObj, flag=0) must succeed (eval vtbl+0xc)
//   (no G4 NPC type-3 filter — contrast turn-in)
//
// Convention: __thiscall (ECX=character; 1 stack arg; ret 4).
// Body is store-free (returns bool only).
// =============================================================================

#include <cstdint>

// Callee: objective readiness (mode 0 uses evaluator vtbl+0xc; mode 1 uses +0x8).
// Product name open (IsObjectiveReady); CF used as-is from Ghidra.
extern "C" char FUN_0052a020(void* character, void* objective, char modeFlag);

// Returns 1 if journal-ready, 0 otherwise.
std::uint8_t __thiscall CVOGCharacter_IsMissionJournalReady(
    void* self_character,
    void* mission_def)
{
    // G1 — last objective
    auto* mission = reinterpret_cast<std::uint8_t*>(mission_def);
    const auto obj_count = static_cast<std::uint32_t>(mission[0x130]);
    auto* objectives = *reinterpret_cast<void***>(mission + 0x13c);
    void* last_obj = objectives[obj_count - 1];

    // G2 — active objectives hash @ character+0x548
    auto* character = reinterpret_cast<std::uint8_t*>(self_character);
    auto* hash = *reinterpret_cast<std::uint8_t**>(character + 0x548);
    const auto key = *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uint8_t*>(last_obj) + 0x10);
    const auto mask = *reinterpret_cast<std::uint32_t*>(hash + 8);
    auto* buckets = *reinterpret_cast<std::uint8_t**>(hash + 0x10);
    auto* node = *reinterpret_cast<std::uint8_t**>(
        *reinterpret_cast<std::uint8_t**>(buckets + (mask & key) * 4) + 4);

    while (true) {
        if (node == nullptr) {
            return 0;
        }
        if (key == *reinterpret_cast<std::uint32_t*>(node + 0x10)) {
            break;
        }
        node = *reinterpret_cast<std::uint8_t**>(node + 0xc);
    }
    if (node == nullptr) {
        return 0;
    }
    if (*reinterpret_cast<void**>(node + 8) == nullptr) {
        return 0;
    }

    // G3 — last objective ready (journal / lightweight mode 0)
    if (FUN_0052a020(self_character, last_obj, 0) == 0) {
        return 0;
    }
    return 1;
}
