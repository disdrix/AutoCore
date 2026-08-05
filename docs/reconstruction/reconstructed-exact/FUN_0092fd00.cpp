// =============================================================================
// FUN_0092fd00 — alias plate for Client_TryBindActiveMissionTracker
// -----------------------------------------------------------------------------
// Stable ID: aa_0092fd00
// Address:   0x0092fd00  (autoassault.exe, image base 0x400000)
// Canonical: Client_TryBindActiveMissionTracker
// See:       Client_TryBindActiveMissionTracker.cpp  (authoritative clean)
// Sealed:    2026-07-29 dual W21-Q
// =============================================================================
//
// Image ABI: EDI = Client*, EAX = missionId, AL = success. No stack args.
// Body range: 0x0092fd00 – 0x0092fd84
//
// Faithful control flow (no bare undefined4):

#include <cstdint>

void* CNDHash_LookupByKey(void* hash, std::uint32_t key);
// thiscall ECX=node; stack Character*
char __thiscall FUN_0059dc50(void* objectiveNode, void* character);
// thiscall/fast ECX=tracker; EAX=missionId
char __fastcall FUN_0092a590(void* tracker, std::uint32_t missionId);

// Custom dual-register entry matching retail call sites.
char Client_TryBindActiveMissionTracker(void* client /*EDI*/, std::uint32_t missionId /*EAX*/)
{
    void* character = *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0xe98);
    if (character == nullptr) {
        return 0;
    }

    if (missionId != 0) {
        void* hash = *reinterpret_cast<void**>(reinterpret_cast<char*>(character) + 0x548);
        void* node = CNDHash_LookupByKey(hash, missionId);
        if (node == nullptr) {
            return 0;
        }
        if (FUN_0059dc50(node, character) == 0) {
            return 0;
        }
    } else {
        void* tracker = *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0x4d0);
        std::uint32_t cur =
            *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(tracker) + 0x10);
        if (cur == 0) {
            return 1;
        }
    }

    void* tracker = *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0x4d0);
    char ok = FUN_0092a590(tracker, missionId);
    if (ok != 0) {
        void* ui = *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0x107c);
        if (ui != nullptr) {
            using VBool = char(__thiscall*)(void*);
            using VAct  = void(__thiscall*)(void*);
            void** vtbl = *reinterpret_cast<void***>(ui);
            if (reinterpret_cast<VBool>(vtbl[0x3d8 / sizeof(void*)])(ui) != 0) {
                reinterpret_cast<VAct>(vtbl[0x448 / sizeof(void*)])(ui);
            }
        }
    }
    return ok;
}

// Decompiler-shaped entry (unaff_EDI / in_EAX) — do not call as cdecl.
char FUN_0092fd00(void)
{
    void* unaff_EDI = nullptr;
    std::uint32_t in_EAX = 0;
    return Client_TryBindActiveMissionTracker(unaff_EDI, in_EAX);
}
