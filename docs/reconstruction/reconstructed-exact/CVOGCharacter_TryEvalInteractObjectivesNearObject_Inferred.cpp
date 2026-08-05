// =============================================================================
// CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00535c60
// Address:   0x00535c60  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00535c60
// System:    missions-progression
// Generated: 2026-07-29 W24-K dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md
//            reviews/B_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md
// Related:   EvaluatePending kind 9; sibling use-object path FUN_00535ed0 kind 10
// =============================================================================
//
// PURPOSE:
//   Near-object / inventory-held interact completion probe:
//     1) If target COID is in character inventory → skip range
//     2) Else require distance(player, target) - radius ≤ 20.0f (DAT_00aaa6e8)
//     3) Traverse active hash @ char+0x548
//     4) For each mission def, scan evaluators for type 0xC matching target
//     5) On first match: EvaluatePendingObjectives(kind=9, cbid_float, 0, 0) → true
//
// ABI: __thiscall ECX=character; stack object*; ret 4; bool AL.
// Static CODE callers: none recovered (entry residual / dynamic).
// =============================================================================

#include <cmath>
#include <cstdint>

extern "C" void* FUN_00571010(void* grid /*ECX*/, std::uint32_t coidLo, std::uint32_t coidHi);
extern "C" float FUN_0053e510(void* nested_ctx);
extern "C" void FUN_007a4480(int level, const char* msg);
extern "C" void CVOGCharacter_EvaluatePendingObjectives(
    void* character, std::uint32_t kind, float p2, std::uint32_t p3, std::uint32_t p4);

// Image constant sealed: 0x00aaa6e8 = 20.0f (Ghidra name g_nInferredThreatDefault)
static constexpr float kNearObjectRange = 20.0f;

using vfn_i = int(__thiscall*)(void*);
using vfn_ii = int(__thiscall*)(void*, void*, void*);
using vfn_p = float*(__thiscall*)(void*);
using vfn_o = void*(__thiscall*)(void*);

std::uint8_t __thiscall CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred(
    void* self_character,
    void* target_object)
{
    auto* character = reinterpret_cast<std::uint8_t*>(self_character);
    auto* object = reinterpret_cast<std::uint8_t*>(target_object);

    // --- Gate A: inventory COID presence ---
    auto* inv_holder = *reinterpret_cast<std::uint8_t**>(character + 0x250);
    auto* grid = *reinterpret_cast<void**>(inv_holder + 0x2b0);
    const auto coidLo = *reinterpret_cast<std::uint32_t*>(object + 0x160);
    const auto coidHi = *reinterpret_cast<std::uint32_t*>(object + 0x164);
    void* inv_item = FUN_00571010(grid, coidLo, coidHi);

    if (inv_item == nullptr) {
        // --- Gate B: world range ---
        auto** ovt = *reinterpret_cast<void***>(object);
        void* nested = reinterpret_cast<vfn_o>(ovt[0x1c8 / 4])(object);
        float dist;
        // character vbase this-adjust: *( *( *(char+4)+4 ) + 4 + char )
        auto* mid = *reinterpret_cast<std::uint8_t**>(character + 4);
        mid = *reinterpret_cast<std::uint8_t**>(mid + 4);
        auto* vbase = reinterpret_cast<std::uint8_t*>(
            *reinterpret_cast<std::uintptr_t*>(mid + 4 + reinterpret_cast<std::uintptr_t>(character)));
        auto** cvt = *reinterpret_cast<void***>(vbase);

        if (nested == nullptr || *reinterpret_cast<int*>(reinterpret_cast<std::uint8_t*>(nested) + 8) == 0) {
            float* ppos = reinterpret_cast<vfn_p>(cvt[0x1a0 / 4])(vbase);
            float ox = *reinterpret_cast<float*>(object + 0x80);
            float oy = *reinterpret_cast<float*>(object + 0x84);
            float oz = *reinterpret_cast<float*>(object + 0x88);
            void* radius_host = reinterpret_cast<vfn_o>(cvt[0x19c / 4])(vbase);
            float radius = *reinterpret_cast<float*>(reinterpret_cast<std::uint8_t*>(radius_host) + 0x34);
            const float dx = ox - ppos[0];
            const float dy = oy - ppos[1];
            const float dz = oz - ppos[2];
            dist = std::sqrt(dx * dx + dy * dy + dz * dz) - radius;
        } else {
            // Decompile: pass nested through vbase+0x19c then FUN_0053e510
            (void)reinterpret_cast<vfn_o>(cvt[0x19c / 4])(vbase);
            dist = FUN_0053e510(nested);
        }
        if (kNearObjectRange < dist) {
            return 0;
        }
    }

    // --- Active hash walk @ +0x548 ---
    auto* hash = *reinterpret_cast<std::uint8_t**>(character + 0x548);
    if (*reinterpret_cast<char*>(hash + 0x1d) != 0) {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *reinterpret_cast<std::uint8_t*>(hash + 0x1d) = 1;

    std::uint8_t* node = nullptr;
    for (;;) {
        hash = *reinterpret_cast<std::uint8_t**>(character + 0x548);
        if (*reinterpret_cast<char*>(hash + 0x1d) == 0) {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        if (node == nullptr) {
            node = *reinterpret_cast<std::uint8_t**>(hash + 0x14);
        } else {
            node = *reinterpret_cast<std::uint8_t**>(node + 0x14);
        }
        if (node == nullptr) {
            *reinterpret_cast<std::uint8_t*>(
                *reinterpret_cast<std::uint8_t**>(character + 0x548) + 0x1d) = 0;
            return 0;
        }
        auto* def = *reinterpret_cast<std::uint8_t**>(node + 8);
        if (def == nullptr) {
            *reinterpret_cast<std::uint8_t*>(
                *reinterpret_cast<std::uint8_t**>(character + 0x548) + 0x1d) = 0;
            return 0;
        }

        void** begin = *reinterpret_cast<void***>(def + 0x158);
        void** end = *reinterpret_cast<void***>(def + 0x15c);
        const int count = (begin == nullptr) ? 0 : static_cast<int>((end - begin));
        for (int i = 0; i < count; ++i) {
            auto* eval = reinterpret_cast<void*>(begin[i]);
            auto** evt = *reinterpret_cast<void***>(eval);
            const int type = reinterpret_cast<vfn_i>(evt[0x50 / 4])(eval);
            if (type == 0x0C) {
                const char match = static_cast<char>(
                    reinterpret_cast<vfn_ii>(evt[0x40 / 4])(eval, self_character, target_object));
                if (match != 0) {
                    *reinterpret_cast<std::uint8_t*>(
                        *reinterpret_cast<std::uint8_t**>(character + 0x548) + 0x1d) = 0;
                    auto* clonebase = *reinterpret_cast<std::uint8_t**>(object + 0xa8);
                    const float cbid_f = static_cast<float>(
                        *reinterpret_cast<std::int32_t*>(clonebase + 0x34));
                    CVOGCharacter_EvaluatePendingObjectives(self_character, 9, cbid_f, 0, 0);
                    return 1;
                }
            }
        }
    }
}
