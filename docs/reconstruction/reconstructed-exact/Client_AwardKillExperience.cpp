// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×1.
//  - Notable callees: CVOGReaction_AddExperience×2, GetTickCount×2, Client_AwardKillExperience, Client_EnqueueCombatFloater_INFERRED, FUN_007a4480, XP, character, handler.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Client_AwardKillExperience
// -----------------------------------------------------------------------------
// Purpose:  S2C GiveXP (opcode 0x205F) client handler. Historical name: awards
//           any packet XP (mission, kill server-grant, etc.), not kills only.
//
// Address:  0x0080ae70  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080ae70
// System:   missions-progression / client net
//
// Convention: MSVC __cdecl with custom packet-dispatch register state
//   formal:   GiveXpPacketBody* pGiveXp  (often unused; body read via ESI)
//   unaff_EDI + 0xe98 = local Character*
//   unaff_ESI + 4     = int32 amount
//   unaff_ESI + 8     = sbyte levelHint (-1 = none)
//
// Algorithm:
//   1) Bail if no local character → VOG_DEBUG_STOP
//   2) CVOGReaction_AddExperience(char, amount, PacketOrNonKill)
//      → isKillPath=0: no 5s spree / weapon table on this path
//   3) if levelHint != -1:
//        char+0x738 = hint; char+0x734 = GetTickCount()
//      (reuses spree fields as level-hint + stamp - same offsets as kill spree)
//   4) if vehicle present (char+0x250): build floater blob type 3 (XP) and enqueue
//
// Wire (docs/XP.md): Amount int32, LevelHint sbyte.
// Control flow summary:
//   1) localChar = unaff_EDI+0xe98; null → VOG_DEBUG_STOP return
//   2) CVOGReaction_AddExperience(localChar, amount@ESI+4, PacketOrNonKill)
//   3) if levelHint@ESI+8 != -1: write char+0x738 + GetTickCount→+0x734
//   4) if char+0x250 vehicle: build floater type 3 (XP) → enqueue
//
// Callees: CVOGReaction_AddExperience (non-kill); Client_EnqueueCombatFloater_INFERRED
// Dispatched from Client_PacketDispatch case 0x205F @ 0x00815710
// Exactness: Human-refined; control flow mirrors raw Ghidra decompile (2026-07-23).
// Dual reviews: reviews/A_aa_0080ae70_review.md, reviews/B_aa_0080ae70_review.md
// =============================================================================

#include <cstdint>

// Windows
using DWORD = unsigned long;
DWORD GetTickCount();

enum XpIsKillPath { PacketOrNonKill = 0, KillPath = 1 };

struct GiveXpPacketBody {
    // Layout used via ESI framing in this handler, not necessarily via pGiveXp:
    //   +0 amount (int32) when pointed at framing
    //   +4 amount when ESI is base of framing used below as ESI+4
    //   +8 levelHint sbyte
    int32_t amount;
    int8_t  levelHint;
};

void CVOGReaction_AddExperience(void* character, int amount, XpIsKillPath isKillPath);
void FUN_007a4480(int code, const char* msg);
void Client_EnqueueCombatFloater_INFERRED(void* pFloaterBlob);

extern uint32_t DAT_00a1e840;
extern uint32_t DAT_00a1e844;
extern uint32_t DAT_00a1e848;
extern uint32_t DAT_00a1e84c;

void __cdecl Client_AwardKillExperience(GiveXpPacketBody* /* pGiveXp */)
{
    DWORD    nowTick;
    int      pVehicleOrCtx;
    int      unaff_ESI; // packet framing (amount @ +4, levelHint @ +8)
    int      unaff_EDI; // client state (local character* @ +0xe98)

    // Floater stack blob (CombatFloaterType::XP = 3)
    uint32_t uStack_38;
    uint32_t uStack_34;
    uint32_t uStack_30;
    uint32_t uStack_2c;
    uint32_t uStack_28;
    uint32_t uStack_24;
    uint32_t uStack_20;
    uint32_t uStack_1c;
    uint32_t uStack_18;
    uint8_t  uStack_10;
    uint32_t uStack_8;

    void* pLocalChar = *(void**)(unaff_EDI + 0xe98);
    if (pLocalChar == nullptr) {
        FUN_007a4480(0, "VOG_DEBUG_STOP");
        return;
    }

    // Apply packet amount with non-kill path (no client spree scaling)
    CVOGReaction_AddExperience(pLocalChar, *(int*)(unaff_ESI + 4), PacketOrNonKill);

    // Optional level hint → spree/hint byte + timestamp
    if (*(char*)(unaff_ESI + 8) != -1) {
        *(char*)((int)pLocalChar + 0x738) = *(char*)(unaff_ESI + 8);
        nowTick = GetTickCount();
        *(DWORD*)((int)pLocalChar + 0x734) = nowTick;
    }

    // If character has vehicle/context at +0x250, show XP combat floater
    pVehicleOrCtx = *(int*)((int)pLocalChar + 0x250);
    if (pVehicleOrCtx != 0) {
        // Vtable +0x1c8 on nested dual-base of vehicle/context
        pVehicleOrCtx =
            (**(int (**)())(
                *(int*)(*(int*)(*(int*)(pVehicleOrCtx + 4) + 4) + 4 + pVehicleOrCtx) +
                0x1c8))();
        uStack_38 = DAT_00a1e840;
        uStack_30 = DAT_00a1e848;
        uStack_34 = DAT_00a1e844;
        uStack_2c = DAT_00a1e84c;
        pVehicleOrCtx = pVehicleOrCtx + *(int*)(*(int*)(pVehicleOrCtx + 4) + 4);
        uStack_28 = *(uint32_t*)(pVehicleOrCtx + 0x164);
        uStack_24 = *(uint32_t*)(pVehicleOrCtx + 0x168);
        uStack_20 = *(uint32_t*)(pVehicleOrCtx + 0x16c);
        uStack_1c = *(uint32_t*)(pVehicleOrCtx + 0x170);
        uStack_18 = *(uint32_t*)(unaff_ESI + 4); // amount shown on floater
        uStack_8  = 3;                            // CombatFloaterType::XP
        uStack_10 = 0;
        Client_EnqueueCombatFloater_INFERRED(&uStack_38);
    }
}
