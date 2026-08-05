// =============================================================================
// Client_UiModalDispatch — ABANDON CONFIRM PATH ONLY
// -----------------------------------------------------------------------------
// Purpose:  Extract of modal-dispatch cases for journal abandon confirmation.
//             - case 0x4e46 + action 8: build C2S FailMission (0x20B2) and send
//             - case 0x4e47 + action 8: close modal only (No / dismiss family)
//
// Full function: FUN_00911840 / Client_UiModalDispatch @ 0x00911840 is a large
// UI switch (many modal codes). This file is intentionally NOT the whole switch.
//
// Address:  0x00911840  (autoassault.exe, image base 0x400000)
// Stable:   aa_00911840
// System:   missions-progression
//
// Upstream: Client_MissionDialogHandleButton state 2 sets DAT_00d1b4b4 and posts
//           modal via Client_ShowModalPrompt (FUN_007fdfb0):
//             EAX=0x4e46 (Yes→+0x498), stack secondary=0x4e47 (No→+0x49c).
// Downstream: Server processes 0x20B2 → S2C 0x20B2 → Client_RecvFailMission
//             → CVOGReaction_FailMission.
//
// Exactness: Behavior-preserving extract of decompiler control flow for these
//            two cases. Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

// --- unresolved / shared symbols (names from reconstruction registry) ---
extern std::uint32_t DAT_00d1b4b4;           // pendingAbandonMissionId
extern void*         DAT_00d1b6d8;           // local character object*
extern void*         DAT_00d1a840;           // client / session root
extern int*          DAT_00d1b898;           // optional mission UI controller

void*  FUN_0053fff0();                      // mission definition table root**
void*  CNDHash_LookupByKey(void* hash, std::uint32_t key);
void   Client_SendSectorPacket(void* client, std::uint32_t size, void* packet);
void   FUN_007fc360();                      // close / dismiss modal
void   FUN_007fca10();
void   FUN_007fef20(int code, int a, int b); // mission UI refresh helper

// Modal action discriminator used by many cases in the full switch.
static constexpr int kModalActionPrimary = 8;

// Modal type codes (UF-009 sealed High — see Client_ShowModalPrompt / aa_007fdfb0).
static constexpr std::uint32_t kModalAbandonConfirm = 0x4e46; // Yes (EAX at open) → send 0x20B2
static constexpr std::uint32_t kModalAbandonCancel  = 0x4e47; // No  (stack secondary) → close only
// Note: Decompiler open call shows only 0x4e47; live asm also MOV EAX,0x4e46.

static constexpr std::uint32_t OPCODE_C2S_FAIL_MISSION = 0x20b2;
static constexpr std::uint32_t kFailMissionPacketSize  = 0x18;

#pragma pack(push, 1)
struct FailMissionPacketC2S {
    std::uint32_t opcode;          // +0x00 = 0x20B2
    std::uint32_t pad0;            // +0x04
    std::uint32_t characterCoidLo; // +0x08  from char dual-base +0x164
    std::uint32_t characterCoidHi; // +0x0C  from char dual-base +0x168
    std::uint32_t missionId;       // +0x10  *missionDefNode
    std::uint32_t pad1;            // +0x14
};
#pragma pack(pop)
static_assert(sizeof(FailMissionPacketC2S) == 0x18, "FailMission C2S size");

// -----------------------------------------------------------------------------
// Case 0x4e47 — cancel / shared dismiss family (excerpt)
// In the full switch this case fall-through-groups with 0x4e45, 0x4e4b, ...
// For abandon: No button → close modal, no packet.
// -----------------------------------------------------------------------------
static void UiModal_AbandonCancel_OnPrimary(void /* *thisUi unused in body */)
{
    FUN_007fc360();
}

// -----------------------------------------------------------------------------
// Case 0x4e46 — confirm abandon (excerpt)
// keySnapshot is DAT_00d1b4b4 captured at Client_UiModalDispatch entry
// (full function does: key = DAT_00d1b4b4 before switch).
// -----------------------------------------------------------------------------
static void UiModal_AbandonConfirm_OnPrimary(std::uint32_t keySnapshot)
{
    if (DAT_00d1b4b4 != 0xffffffffu && DAT_00d1b6d8 != nullptr) {
        std::uint32_t* pTableRoot = reinterpret_cast<std::uint32_t*>(FUN_0053fff0());
        if (pTableRoot != nullptr && *reinterpret_cast<void**>(pTableRoot) != nullptr) {
            int* pMissionDefNode = reinterpret_cast<int*>(
                CNDHash_LookupByKey(*reinterpret_cast<void**>(pTableRoot), keySnapshot));
            if (pMissionDefNode != nullptr) {
                FailMissionPacketC2S packet{};
                packet.opcode = OPCODE_C2S_FAIL_MISSION;

                // Character COID: *( *(DAT_00d1b6d8 + 4) + 4 ) is dual-base;
                // fields at dualBase + DAT_00d1b6d8 + 0x164 / 0x168.
                int charObj = reinterpret_cast<int>(DAT_00d1b6d8);
                int dualBase = *reinterpret_cast<int*>(*reinterpret_cast<int*>(charObj + 4) + 4);
                packet.characterCoidLo =
                    *reinterpret_cast<std::uint32_t*>(dualBase + 0x164 + charObj);
                packet.characterCoidHi =
                    *reinterpret_cast<std::uint32_t*>(dualBase + 0x168 + charObj);
                packet.missionId = static_cast<std::uint32_t>(*pMissionDefNode);

                Client_SendSectorPacket(&DAT_00d1a840, kFailMissionPacketSize, &packet);

                // Optional mission UI refresh when controller reports active.
                if (DAT_00d1b898 != nullptr) {
                    // vtable +0x3d8 → bool-like "is live / should refresh"
                    using VBoolFn = char(__thiscall*)(int*);
                    auto** vtbl = reinterpret_cast<void***>(DAT_00d1b898);
                    auto isLive = reinterpret_cast<VBoolFn>((*vtbl)[0x3d8 / sizeof(void*)]);
                    if (isLive(DAT_00d1b898) != '\0') {
                        FUN_007fca10();
                        FUN_007fef20(0x13, 1, 0);
                    }
                }
            }
        }
    }

    FUN_007fc360(); // always close after primary action on this case
}

// -----------------------------------------------------------------------------
// Dispatch fragment — only the abandon-related modal types.
// Callers in the full function: switch(param_3) with param_2 action gate.
// -----------------------------------------------------------------------------
void Client_UiModalDispatch_AbandonCases(int actionCode, std::uint32_t modalType,
                                         std::uint32_t pendingMissionKeySnapshot)
{
    if (actionCode != kModalActionPrimary) {
        return;
    }

    if (modalType == kModalAbandonCancel) {
        // Also shared fall-through for other modal codes in the full switch.
        UiModal_AbandonCancel_OnPrimary();
        return;
    }

    if (modalType == kModalAbandonConfirm) {
        UiModal_AbandonConfirm_OnPrimary(pendingMissionKeySnapshot);
        return;
    }
}
