// =============================================================================
// Client_SendUseObject
// -----------------------------------------------------------------------------
// Purpose:  C2S UseObject (0x2072, size 0x20): stash target at client+0xd28,
//           bulk-copy TFID_16 from target+0x160.., fill IDObjective via
//           Client_FindObjectiveMatchingTarget (def+0x10 or −1), sector send.
//
// Address:  0x00916740  (autoassault.exe, image base 0x400000)
// Stable:   aa_00916740
// System:   interaction-activation
// Generated: 2026-07-29 human refine; residual seal (listing) same day
// Exactness: Behavior-preserving rewrite of decompiler + listing control flow.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
//
// Convention (listing-sealed at all CALL sites):
//   ECX = client/controller*
//   EAX = target world object*
//
// Packet (SUB ESP,0x20; offsets from buffer base = ESP):
//   +0x00  opcode 0x2072
//   +0x04  pad (unwritten in body)
//   +0x08  TFID_16 bulk from obj+0x160 (4 dwords → +0x08..+0x17)
//   +0x18  IDObjective (match id or 0xFFFFFFFF)
//   +0x1c  trailer (unwritten; within size 0x20)
//
// Globals (listing):
//   DAT_00d1b6d8  — character* this for FindObjectiveMatchingTarget
//   DAT_00d1b4b8  — g_pSectorNetConnection_INFERRED (sector send)
//
// Callers (xrefs):
//   Client_InteractClickPickTarget   site 0x00924ee5
//   Client_Input_PollBoundActions   site 0x00927be1
//   Client_RecvCompleteDynamicObjective sites 0x0081004c, 0x008100fa
//
// Dual reviews:
//   reviews/A_aa_00916740_Client_SendUseObject.md
//   reviews/B_aa_00916740_Client_SendUseObject.md
// =============================================================================

#include <cstdint>

// Listing: MOV ECX, [0x00d1b4b8] before vtbl+0x18 send.
extern void* g_pSectorNetConnection_INFERRED; // DAT_00d1b4b8

// Listing: MOV ECX, [0x00d1b6d8] before CALL 0x00525bd0.
extern int* g_pLocalCharacter_INFERRED; // DAT_00d1b6d8

// thiscall: ECX = character; stack arg = match key. Returns objective def* or 0.
int __fastcall Client_FindObjectiveMatchingTarget(int* character /*ECX*/,
                                                    std::uint32_t targetKey);

// Entry: ECX = client, EAX = target (register convention; no C prototype args).
void Client_SendUseObject(void)
{
    int client; // ECX
    int target; // EAX on entry
    int pObjDef;
    std::uint32_t packet[8]; // 0x20 bytes; conceptual layout below

    // 1) Stash last-use target
    *(int*)(client + 0xd28) = target;

    // 2) TFID_16 bulk copy from object identity block
    packet[2] = *(std::uint32_t*)(target + 0x160); // +0x08
    packet[3] = *(std::uint32_t*)(target + 0x164); // +0x0c
    packet[4] = *(std::uint32_t*)(target + 0x168); // +0x10
    packet[5] = *(std::uint32_t*)(target + 0x16c); // +0x14
    // packet[1] (+0x04 pad) and packet[7] (+0x1c trailer) intentionally unwritten

    // 3) Opcode
    packet[0] = 0x2072;

    // 4) Objective: character global + clonebase key @ +0x34
    pObjDef = Client_FindObjectiveMatchingTarget(
        g_pLocalCharacter_INFERRED,
        *(std::uint32_t*)(*(int*)(target + 0xa8) + 0x34));
    if (pObjDef == 0) {
        packet[6] = 0xffffffffu; // +0x18 −1: no matching objective
    } else {
        packet[6] = *(std::uint32_t*)(pObjDef + 0x10); // objective id
    }

    // 5) Conditional sector send
    if (g_pSectorNetConnection_INFERRED != nullptr) {
        (**(void(**)(std::uint32_t, void*, std::uint32_t, std::uint32_t))(
            *(int*)g_pSectorNetConnection_INFERRED + 0x18))(
            0xffffffffu, packet, 0x20, 0);
    }
}
