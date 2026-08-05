// =============================================================================
// Client_RecvFailMission
// -----------------------------------------------------------------------------
// Purpose:  S2C handler for opcode **0x20B2** (FailMission).
//           Applies server-authoritative mission failure to the local character:
//             - CVOGReaction_FailMission(missionId @ packet+0x10)
//             - post-fail helper FUN_005307e0
//             - optional active-objective hash probe (char+0x548)
//             - optional mission UI controller refresh (client+0x107c)
//
//           C2S counterpart is built at Client_UiModalDispatch case 0x4e46
//           (journal abandon confirm). Same opcode, size 0x18.
//
// Address:  0x0080b100  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080b100
// System:   missions-progression
// Prior:    FUN_0080b100
//
// Convention (asm-sealed 2026-07-29 dual residual, UF-012):
//   PacketDispatch call site 0x00815d93:
//     MOV EAX, ESI   ; packet buffer
//     MOV ECX, EBP   ; client/game context
//     CALL 0x0080b100
//   Body (0x0080b100..0x0080b174):
//     EDI = ECX (client)
//     FailMission thiscall: ECX = *(EDI+0xe98), missionId = *(EAX+0x10) pushed
//     FailMission return (AL) is IGNORED — end-quest always runs if char was live
//     FUN_005307e0 thiscall: ECX = *(EDI+0xe98) reloaded
//     After FailMission, EAX is reloaded with character (packet base dead)
//     DAT_00d1ad10: MOV ECX,[global]; key = *(ECX+0x10)  — pointer global
//     UI path: CALL vtbl+0x3d8 then POP EDI; TAIL JMP vtbl+0x448
//
// Packet layout (FailMission, absolute on buffer after opcode framing):
//   +0x00  opcode 0x20B2 (dispatch already matched)
//   +0x04  pad4
//   +0x08  CharacterCoid lo   (not read in this handler)
//   +0x0C  CharacterCoid hi   (not read in this handler)
//   +0x10  MissionId (u32)    ← only field consumed here (asm)
//   +0x14  pad4
//
// Exactness: Behavior-preserving rewrite of decompiler + image control flow.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

void* CNDHash_LookupByKey(void* hash, std::uint32_t key);
// __thiscall: ECX = character
std::uint32_t __thiscall CVOGReaction_FailMission(void* character, std::uint32_t missionId);
// __thiscall: ECX = character (reloaded from client+0xe98 after FailMission)
void  __thiscall FUN_005307e0(void* character);
void  FUN_0092fd00();

// Global pointer; image: MOV ECX,[DAT_00d1ad10]; key = *(ECX+0x10)
extern void* DAT_00d1ad10;

void Client_RecvFailMission(int client /* ECX */, int packet /* EAX */)
{
    char cUi;
    void* pObjectiveNode;

    void* character = *reinterpret_cast<void**>(client + 0xe98);
    if (character == nullptr) {
        return;
    }

    // Mission id at packet+0x10. Character thiscall ECX = character (image-sealed).
    // FailMission may return 0 (no live node); return is discarded by image.
    std::uint32_t missionId = *reinterpret_cast<std::uint32_t*>(packet + 0x10);
    (void)CVOGReaction_FailMission(character, missionId);

    character = *reinterpret_cast<void**>(client + 0xe98);
    FUN_005307e0(character);

    // Secondary path: packet base no longer in EAX (image reloads character into EAX).
    character = *reinterpret_cast<void**>(client + 0xe98);
    if (character != nullptr) {
        void* activeObjectivesHash = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(character) + 0x548);
        void* probeObj = DAT_00d1ad10;
        std::uint32_t probeKey =
            *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(probeObj) + 0x10);
        pObjectiveNode = CNDHash_LookupByKey(activeObjectivesHash, probeKey);
        if (pObjectiveNode == nullptr) {
            FUN_0092fd00();
        }
    }

    int* pMissionUi = *reinterpret_cast<int**>(client + 0x107c);
    if (pMissionUi != nullptr) {
        // vtable +0x3d8: live/open predicate; +0x448: refresh/action (tail jmp in image)
        using VBoolFn = char(__thiscall*)(int*);
        using VActFn  = void(__thiscall*)(int*);
        void** vtbl = *reinterpret_cast<void***>(pMissionUi);
        auto isLive = reinterpret_cast<VBoolFn>(vtbl[0x3d8 / sizeof(void*)]);
        auto refresh = reinterpret_cast<VActFn>(vtbl[0x448 / sizeof(void*)]);
        cUi = isLive(pMissionUi);
        if (cUi != '\0') {
            // Image: POP EDI; JMP [vtbl+0x448] — tail transfer (not a nested call return).
            refresh(pMissionUi);
            return;
        }
    }
}
