// =============================================================================
// CVOGCharacter_IsMissionTurnInReady
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b420
// Address:   0x0052b420  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0052b420
// System:    missions-progression
// Generated: 2026-07-29 seal (last-obj + active-hash + readiness gates)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md
//            reviews/B_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md
// =============================================================================
//
// PURPOSE:
//   Predicate: is this mission turn-in ready for the local character?
//   Used by Client_ShowNpcMissionDialogUI to select claim chrome (+0x64c)
//   vs offer/active paths.
//
// SEALED GATES:
//   G1 lastObj = mission.objectives[(uint8)mission.objCount - 1]
//      array @ mission+0x13c, count byte @ mission+0x130
//   G2 active-objectives CNDHash @ char+0x548, key = lastObj+0x10;
//      require node and node.value(+0x8) != 0
//   G3 FUN_0052a020(char, lastObj, flag=1) must succeed
//   G4 if npcOpt != 0: every evaluator with type(vtbl+0x50)==3 must have
//      target id (+0x18) == NPC clonebase (entity chain +0xac → +0x34)
//
// Convention: __thiscall (ECX=character; 2 stack args; ret 8).
// Body is store-free (returns bool only).
// =============================================================================

#include <cstdint>

// Callee: objective complete eval (strict mode uses evaluator vtbl+8).
// Product name open; CF used as-is from Ghidra.
extern "C" char FUN_0052a020(void* character, void* objective, char strictFlag);

// Returns 1 if turn-in ready, 0 otherwise.
std::uint8_t __thiscall CVOGCharacter_IsMissionTurnInReady(
    void* self_character,
    void* mission_def,
    void* npc_opt)
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

    // G3 — last objective complete (strict)
    if (FUN_0052a020(self_character, last_obj, 1) == 0) {
        return 0;
    }

    std::uint8_t ready = 1;
    // G4 — optional NPC type-3 filter
    if (npc_opt != nullptr) {
        auto* last = reinterpret_cast<std::uint8_t*>(last_obj);
        auto** begin = *reinterpret_cast<void***>(last + 0x158);
        auto** end = *reinterpret_cast<void***>(last + 0x15c);
        if (begin != end) {
            auto** it = begin;
            while (true) {
                auto* eval = reinterpret_cast<std::uint8_t*>(*it);
                auto* vtbl = *reinterpret_cast<void***>(eval);
                using TypeFn = int(__thiscall*)(void*);
                const int type = reinterpret_cast<TypeFn>(vtbl[0x50 / 4])(eval);

                // NPC clonebase: *(*( *(npc+4)+4 ) + npc + 0xac) + 0x34
                // (raw: *(int*)(*(int*)(*(int*)(*(int*)(param_3+4)+4)+0xac+param_3)+0x34))
                const auto npc = reinterpret_cast<std::uintptr_t>(npc_opt);
                const auto base = *reinterpret_cast<std::uintptr_t*>(npc + 4);
                const auto adj = *reinterpret_cast<std::uintptr_t*>(base + 4);
                const auto component =
                    *reinterpret_cast<std::uintptr_t*>(adj + 0xac + npc);
                const auto npc_cbid = *reinterpret_cast<int*>(component + 0x34);
                const auto eval_target = *reinterpret_cast<int*>(eval + 0x18);

                // Continue while type != 3 OR target matches this NPC.
                // Fail when type == 3 AND target != npc_cbid.
                if (type == 3 && eval_target != npc_cbid) {
                    ready = 0;
                    break;
                }
                ++it;
                if (it == end) {
                    return 1;
                }
            }
        }
    }
    return ready;
}
