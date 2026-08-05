// =============================================================================
// CVOGCharacter_ResolveUseObjectPending_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00535ed0
// Address:   0x00535ed0 – 0x0053607e  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00535ed0
// System:    missions-progression / use-object pending
// Generated: 2026-07-29 W25-A dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md
//            reviews/B_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md
// Related:   EvaluatePending kind 10; sibling near-object path FUN_00535c60 kind 9
// =============================================================================
//
// PURPOSE:
//   Resolve / clear character pending use-object state:
//     - Guard: vbase present AND flag char+0xc7c
//     - Invalid TFID slot: optional vtbl+0x2cc on char+0xc9c (commit=1 or cancel=0)
//       and clear FUN_0060b410(0) aux at +0xca0
//     - Valid TFID + !commit + flag+0xc7d: Client_SendLogicUiPacket kind 0x14
//     - Valid TFID + commit: Object_ResolveFromTFID → EvaluatePendingObjectives kind 10
//     - Always on finish path: clear flags, null TFID from DAT_009cee98, zero aux
//
// ABI: __thiscall ECX=character; stack char commit; ret 4; bool AL.
// =============================================================================

#include <cstdint>

struct TFID_16 {
    std::uint32_t dwCoidLo;
    std::uint32_t dwCoidHi;
};

extern "C" void* Object_ResolveFromTFID(TFID_16* tfid);
extern "C" void CVOGCharacter_EvaluatePendingObjectives(
    void* character, std::uint32_t kind, float p2, std::uint32_t p3, std::uint32_t p4);
extern "C" void Client_SendLogicUiPacket(void* packet_blob);
extern "C" void FUN_0060b410(std::uint8_t flag);

extern "C" std::uint32_t DAT_009cee98;
extern "C" std::uint32_t DAT_009cee9c;
extern "C" std::uint32_t DAT_009ceea0;
extern "C" std::uint32_t DAT_009ceea4;

using vfn_commit = void(__thiscall*)(void* self, int commit_flag, void* character);

std::uint8_t __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(
    void* self_character,
    char commit)
{
    auto* character = reinterpret_cast<std::uint8_t*>(self_character);

    auto* mid = *reinterpret_cast<std::uint8_t**>(character + 4);
    mid = *reinterpret_cast<std::uint8_t**>(mid + 4);
    auto* vbase = *reinterpret_cast<std::uint8_t**>(
        mid + 0xa8 + reinterpret_cast<std::uintptr_t>(character));

    if (vbase == nullptr || character[0xc7c] == 0) {
        character[0xc7c] = 0;
        return 0;
    }

    std::uint8_t ok = 1;
    const auto lo = *reinterpret_cast<std::uint32_t*>(character + 0xc88);
    const auto hi = *reinterpret_cast<std::uint32_t*>(character + 0xc8c);
    const auto tfid_invalid = ((lo & hi) == 0xffffffffu) && (character[0xc90] == 0);

    if (tfid_invalid) {
        auto* secondary = *reinterpret_cast<void**>(character + 0xc9c);
        if (secondary != nullptr) {
            auto** vt = *reinterpret_cast<void***>(secondary);
            auto* fn = reinterpret_cast<vfn_commit>(vt[0x2cc / 4]);
            if (commit != 0) {
                fn(secondary, 1, character);
                *reinterpret_cast<void**>(character + 0xc9c) = nullptr;
                if (*reinterpret_cast<void**>(character + 0xca0) != nullptr) {
                    FUN_0060b410(0);
                    *reinterpret_cast<void**>(character + 0xca0) = nullptr;
                }
                goto finish;
            }
            if (character[0xc7d] != 0) {
                fn(secondary, 0, character);
                *reinterpret_cast<void**>(character + 0xc9c) = nullptr;
                if (*reinterpret_cast<void**>(character + 0xca0) != nullptr) {
                    FUN_0060b410(0);
                    *reinterpret_cast<void**>(character + 0xca0) = nullptr;
                }
                goto finish;
            }
        }
    } else {
        if (commit == 0) {
            if (character[0xc7d] == 0)
                return 0;
            // local_138[0]=0; local_11c=0x14; local_118=0; local_114=0
            std::uint8_t packet[0x28] = {};
            *reinterpret_cast<std::uint32_t*>(packet + 0x1c) = 0x14;
            Client_SendLogicUiPacket(packet);
            goto finish;
        }
        void* obj = Object_ResolveFromTFID(reinterpret_cast<TFID_16*>(character + 0xc88));
        if (obj != nullptr) {
            auto* o = reinterpret_cast<std::uint8_t*>(obj);
            auto* clonebase = *reinterpret_cast<std::uint8_t**>(o + 0xa8);
            const auto cbid = *reinterpret_cast<std::int32_t*>(clonebase + 0x34);
            CVOGCharacter_EvaluatePendingObjectives(
                character, 10, static_cast<float>(cbid), 0, 0);
            goto finish;
        }
    }

    ok = 0;

finish:
    character[0xc7c] = 0;
    character[0xc7d] = 0;
    *reinterpret_cast<std::uint32_t*>(character + 0xc88) = DAT_009cee98;
    *reinterpret_cast<std::uint32_t*>(character + 0xc8c) = DAT_009cee9c;
    *reinterpret_cast<std::uint32_t*>(character + 0xc90) = DAT_009ceea0;
    *reinterpret_cast<std::uint32_t*>(character + 0xc94) = DAT_009ceea4;
    *reinterpret_cast<void**>(character + 0xc9c) = nullptr;
    *reinterpret_cast<void**>(character + 0xca0) = nullptr;
    *reinterpret_cast<std::uint32_t*>(character + 0xc80) = 0;
    return ok;
}

std::uint8_t __thiscall FUN_00535ed0(void* self_character, char commit)
{
    return CVOGCharacter_ResolveUseObjectPending_Inferred(self_character, commit);
}
