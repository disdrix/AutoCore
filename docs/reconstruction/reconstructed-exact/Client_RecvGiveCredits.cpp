// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×1.
//  - Notable callees: CVOGCharacter_AddCredits×2, Client_EnqueueCombatFloater_INFERRED, Client_GetMissionCompleteAudioTable, Client_PlayNamedInterfaceSound, Client_RecvGiveCredits, FUN_007a4480, Parameters, pPacket.
//  - Strings: "credits"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Client_RecvGiveCredits
// -----------------------------------------------------------------------------
// Purpose:  S2C GiveCredits (opcode 0x205E) client handler. Adds a signed
//           int64 money delta to the local character, plays "credits" UI sound
//           for positive amounts, optional combat floater type 4, money HUD.
//
// Address:  0x0080cac0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080cac0
// System:   missions-progression / client net (currency)
//
// Convention: MSVC __cdecl with custom packet-dispatch register framing
//   formal:   pGameClient, pPacket (often unused; body via unaff_*)
//   unaff_ESI + 0xe98 = local Character*
//   unaff_EDI + 8     = int64 amount (lo @ +8, hi @ +0xc)
//   Note: PacketDispatch case 0x205E calls Client_RecvGiveCredits(unaff_EDI,
//         unaff_ESI) - formal names vs register roles still have cross-unit
//         tension; body below matches raw (ESI=game, EDI=packet).
//
// Algorithm:
//   1) Bail if no local character → VOG_DEBUG_STOP
//   2) CVOGCharacter_AddCredits(char, amount@packet+8)  // char money +0x720
//   3) if amount > 0 (hi>=0 and (hi>0 or lo!=0)):
//        play "credits" interface sound
//   4) if vehicle at char+0x250:
//        if char+0xd6c == 0: build floater type 4 (credits) and enqueue
//        refresh money HUD panel via game+0x1040 / +0x50c vtable
//
// Wire: Packet_GiveCredits - additive Currency delta (NOT absolute).
// Do NOT also send after CompleteObjective if that path already added credits
// (double-count risk on mission final).
//
// Callees: CVOGCharacter_AddCredits; Client_GetMissionCompleteAudioTable;
//          Client_PlayNamedInterfaceSound; Client_EnqueueCombatFloater_INFERRED
// Dispatched from Client_PacketDispatch case 0x205E @ 0x00815710
// Exactness: Human-refined; control flow mirrors raw Ghidra decompile (2026-07-23).
// Dual reviews: reviews/A_aa_0080cac0_review.md, reviews/B_aa_0080cac0_review.md
// =============================================================================

#include <cstdint>

// Audio / floater helpers
void FUN_007a4480(int code, const char* msg);
void Client_GetMissionCompleteAudioTable(
    const char* name, int, uint32_t, uint32_t, int, int, int, int);
void Client_PlayNamedInterfaceSound(
    char* name, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
void Client_EnqueueCombatFloater_INFERRED(void* pFloaterBlob);
long long CVOGCharacter_AddCredits(void* character, long long nAmountDelta);

// Floater color / style constants (shared with GiveXP path)
extern uint32_t DAT_00a1e840;
extern uint32_t DAT_00a1e844;
extern uint32_t DAT_00a1e848;
extern uint32_t DAT_00a1e84c;

void __cdecl Client_RecvGiveCredits(void* /* pGameClient */,
                                    void* /* pPacket */)
{
    int      pVehicleOrCtx;     // iVar1
    int      unaff_ESI;         // game client* (local char @ +0xe98)
    int      unaff_EDI;         // packet framing (int64 amount @ +8)
    char*    pcSoundName;
    uint32_t uSnd0, uSnd1, uSnd2, uSnd3, uSnd4, uSnd5, uSnd6;

    // Floater stack blob (CombatFloaterType::Credits = 4)
    uint32_t uStack_38, uStack_34, uStack_30, uStack_2c;
    uint32_t uStack_28, uStack_24, uStack_20, uStack_1c, uStack_18;
    uint8_t  uStack_10;
    uint32_t uStack_8;

    // ----- 1) Require local character -----
    if (*(void**)(unaff_ESI + 0xe98) == (void*)0x0) {
        FUN_007a4480(0, "VOG_DEBUG_STOP");
        return;
    }

    // ----- 2) ADD money delta (packet+8 int64 → character +0x720) -----
    CVOGCharacter_AddCredits(*(void**)(unaff_ESI + 0xe98),
                             *(long long*)(unaff_EDI + 8));

    // ----- 3) Positive amount → "credits" UI sound -----
    // Signed int64 > 0: high dword >= 0 AND (high > 0 OR low != 0)
    if ((-1 < *(int*)(unaff_EDI + 0xc)) &&
        ((0 < *(int*)(unaff_EDI + 0xc) || (*(int*)(unaff_EDI + 8) != 0)))) {
        uSnd6 = 0;
        uSnd5 = 0x1e;
        uSnd4 = 0;
        uSnd3 = 0;
        uSnd2 = 0xffffffff;
        uSnd1 = 0xffffffff;
        uSnd0 = 0;
        pcSoundName = "credits";
        Client_GetMissionCompleteAudioTable("credits", 0, 0xffffffff, 0xffffffff, 0, 0,
                                            0x1e, 0);
        Client_PlayNamedInterfaceSound(pcSoundName, uSnd0, uSnd1, uSnd2, uSnd3, uSnd4,
                                       uSnd5, uSnd6);
    }

    // ----- 4) Vehicle present → floater type 4 + money HUD -----
    pVehicleOrCtx = *(int*)(*(int*)(unaff_ESI + 0xe98) + 0x250);
    if (pVehicleOrCtx != 0) {
        // Vtable +0x1c8 on nested dual-base of vehicle/context
        pVehicleOrCtx =
            (**(int (**)())(
                *(int*)(*(int*)(*(int*)(pVehicleOrCtx + 4) + 4) + 4 + pVehicleOrCtx) +
                0x1c8))();
        // Floater suppressed when char+0xd6c != 0 (unknown mode gate)
        if (*(int*)(*(int*)(unaff_ESI + 0xe98) + 0xd6c) == 0) {
            uStack_38 = DAT_00a1e840;
            uStack_34 = DAT_00a1e844;
            uStack_30 = DAT_00a1e848;
            uStack_2c = DAT_00a1e84c;
            pVehicleOrCtx = pVehicleOrCtx + *(int*)(*(int*)(pVehicleOrCtx + 4) + 4);
            uStack_28 = *(uint32_t*)(pVehicleOrCtx + 0x164);
            uStack_24 = *(uint32_t*)(pVehicleOrCtx + 0x168);
            uStack_20 = *(uint32_t*)(pVehicleOrCtx + 0x16c);
            uStack_1c = *(uint32_t*)(pVehicleOrCtx + 0x170);
            uStack_18 = *(uint32_t*)(unaff_EDI + 8); // amount shown (low dword)
            uStack_8 = 4;                              // CombatFloaterType::Credits
            uStack_10 = 0;
            Client_EnqueueCombatFloater_INFERRED(&uStack_38);
        }
        // Money HUD panel refresh: game+0x1040 → widget+0x50c → vtable +0x448
        pVehicleOrCtx = *(int*)(unaff_ESI + 0x1040);
        if ((pVehicleOrCtx != 0) && (*(int*)(pVehicleOrCtx + 0x50c) != 0)) {
            (**(int (**)())(**(int**)(pVehicleOrCtx + 0x50c) + 0x448))();
        }
    }
    return;
}
