// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: Client_RefreshOpenMissionUiWindows×3, FUN_007a6de0×2, FUN_0093d6e0×2, sprintf×2, CVOGReaction_GiveItemByCbid, FUN_004bc180, FUN_00512160, FUN_007fc150.
//  - Strings: "Grab Item failed: Failed creating new stack object on coid"; "%s: %i\n"; "Grab Item failed: Failed on coid".
//  - Return sites: 4.

// =============================================================================
// Client_RecvInventoryGrabResponse
// -----------------------------------------------------------------------------
// Purpose:  S2C InventoryGrabResponse (dispatch opcode 0x2035). Handles whole-
//           grab and stack-split paths: reduce source qty, create peeled stack
//           object, attach to cursor. Early-out on opcode 0x2039 (shared slot).
//
// Address:  0x00811be0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00811be0
// System:   inventory-transfer
//
// Convention (Confirmed 2026-07-29 dual residual):
//   PacketDispatch call site 0x008159b0: EAX=client, EBX=packet.
//   Prologue: ESI=client; packet remains EBX. cdecl formals unused.
//
// Packet fields (asm + AutoCore Write + design doc):
//   +0x00  u32  opcode (0x2035; 0x2039 → return)
//   +0x08  TFID item (16 bytes)
//   +0x18  u8   inventoryType          [MOV DL,[EBX+0x18] — decompiler omitted]
//   +0x1C  i32  count (grab/split qty) [EBX[7]]
//   +0x20  byte splitFlag              [EBX[8] as char; 0=whole, ≠0=split]
//   +0x28  i64  split COID (split)     [EBX[10], EBX[11]] → Object_SetCoidIdentity
//   +0x38  byte success                [EBX[0xe] as char]
//
// Control flow summary:
//   1) clear client+0xb6; FUN_007a69d0
//   2) opcode 0x2039 → return (shared dispatch slot)
//   3) success@+0x38 == 0 or resolve fail → ODS; refresh; return
//   4) splitFlag@+0x20:
//        whole: Client_InventoryGrabApplyToCursor(item, invType, client, count)
//        split: peel source qty; GiveItemByCbid; SetCoidIdentity(new, COID, 1);
//               init/set qty/register/gfx; ApplyToCursor(new, ...)
//   5) mission UI refresh
//
// Helper notes (residual):
//   FUN_0093d6e0 — proposed Client_InventoryGrabApplyToCursor
//     Real args (asm): EAX=item, DL=invType@+0x18, stack: client, count
//     Decompiler of this unit wrongly shows only (client, count).
//   FUN_00512160 — proposed Object_SetCoidIdentity (thiscall on new stack)
//   FUN_007fc150 — cursor/held UI clear on split-create fail (NOT DAT_00d1a8f6)
//   DAT_00d1a8f6 C2S busy — not cleared in this body
//
// Related: docs/superpowers/specs/2026-07-09-inventory-stack-split-design.md
// Dual residual: tmp/a_00811be0.md (2026-07-29)
// Dual reviews:
//   reviews/A_aa_00811be0_Client_RecvInventoryGrabResponse.md
//   reviews/B_aa_00811be0_Client_RecvInventoryGrabResponse.md
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <windows.h>

struct TFID_16 {
    std::uint32_t dwCoidLo;
    std::uint32_t dwCoidHi;
    // ... remainder of 16-byte TFID
};

// Callees
void*        FUN_007a69d0();
void*        Object_ResolveFromTFID(TFID_16* tfid);
// True ABI (asm): EAX=item, DL=invType, stack client + count
// Decompiler of this parent often shows only (client, count).
void         FUN_0093d6e0(/* item EAX, invType DL, client, count */);
void         Client_RefreshOpenMissionUiWindows(std::int32_t client);
char*        FUN_007a6de0(const char* key, std::uint32_t a);
void         FUN_007fdfb0(std::int32_t client, char* msg, std::uint32_t a,
                          std::uint32_t b, std::uint32_t c);
void         FUN_007fc150(); // cursor UI clear (fail path)
void*        CVOGReaction_GiveItemByCbid(std::int32_t cbid);
// thiscall: this=newStack; writes +0x160/164 coid, +0x168 flag
void         FUN_00512160(std::uint32_t coidLo, std::uint32_t coidHi,
                          std::uint8_t flag);
void         FUN_004bc180(void* item);
extern float g_flOne;

void Client_RecvInventoryGrabResponse(/* client EAX, packet EBX */)
{
    std::int32_t  client = 0;              // in_EAX → ESI
    std::int32_t* packet = nullptr;        // unaff_EBX
    char          local_80[128];
    char          acStack_84[4]; // decompiler size likely understated

    // Clear client flag at +0xb6 (not DAT_00d1a8f6)
    *reinterpret_cast<std::uint8_t*>(client + 0xb6) = 0;

    std::uint32_t* pCtx = reinterpret_cast<std::uint32_t*>(FUN_007a69d0());

    // Shared dispatch slot: 0x2039 is not a grab response
    if (*packet == 0x2039) {
        return;
    }

    std::int32_t* item =
        reinterpret_cast<std::int32_t*>(
            Object_ResolveFromTFID(reinterpret_cast<TFID_16*>(packet + 2)));

    // success@+0x38
    if (item != nullptr && static_cast<char>(packet[0xe]) != '\0') {
        const auto invType =
            *reinterpret_cast<std::uint8_t*>(
                reinterpret_cast<std::uint8_t*>(packet) + 0x18);
        const std::int32_t count = packet[7]; // +0x1c

        // splitFlag@+0x20 — 0 means whole-grab
        if (static_cast<char>(packet[8]) == '\0') {
            // FUN_0093d6e0: EAX=item, DL=invType, stack client+count
            (void)invType;
            FUN_0093d6e0(/* item, invType, */ client, count);
            Client_RefreshOpenMissionUiWindows(client);
            return;
        }

        // --- Stack split: reduce source, spawn peeled stack ---
        std::int32_t* itemVt = reinterpret_cast<std::int32_t*>(*item);
        using GetQtyFn = std::int32_t(__thiscall*)(void*);
        using SetQtyFn = void(__thiscall*)(void*, std::int32_t);

        std::int32_t curQty = reinterpret_cast<GetQtyFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(itemVt) + 0x25c))(item);
        reinterpret_cast<SetQtyFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(itemVt) + 0x260))(
            item, curQty - count);

        // Create new stack object from source CBID (clonebase +0x34)
        std::int32_t* newStack = reinterpret_cast<std::int32_t*>(
            CVOGReaction_GiveItemByCbid(
                *reinterpret_cast<std::int32_t*>(item[0x2a] + 0x34)));

        if (newStack == nullptr) {
            std::uint32_t coidLo = *pCtx;
            char* msg = FUN_007a6de0(
                "Grab Item failed: Failed creating new stack object on coid",
                0xFFFFFFFFu);
            std::sprintf(acStack_84, "%s: %i\n", msg, coidLo);
            FUN_007fdfb0(client, acStack_84, 0xFFFFFFFFu, 1, 0);
            FUN_007fc150();
            return;
        }

        // Bind split COID (+0x28/+0x2c) onto new stack (thiscall ECX=newStack)
        FUN_00512160(static_cast<std::uint32_t>(packet[10]),
                     static_cast<std::uint32_t>(packet[11]),
                     /*flag=*/1);

        using InitFn = void(__thiscall*)(void*, std::uint32_t, std::uint32_t,
                                         std::int32_t);
        auto* newVt = *reinterpret_cast<void***>(newStack);
        reinterpret_cast<InitFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(newVt) + 8))(
            newStack,
            *reinterpret_cast<std::uint32_t*>(item[0x2a] + 0x34),
            *reinterpret_cast<std::uint32_t*>(client + 0xe04),
            0);

        reinterpret_cast<SetQtyFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(newVt) + 0x260))(
            newStack, count);

        FUN_004bc180(newStack);

        // Reset graphics transform on new stack
        using GetGfxFn = std::uint32_t*(__thiscall*)(void*);
        std::uint32_t* gfx = reinterpret_cast<GetGfxFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(newVt) + 0x1cc))(newStack);
        using GfxResetFn = void(__thiscall*)(void*, std::int32_t, std::int32_t,
                                             std::int32_t, std::int32_t,
                                             std::int32_t, std::int32_t,
                                             std::int32_t, float, std::int32_t);
        reinterpret_cast<GfxResetFn>(*reinterpret_cast<void**>(gfx))(
            gfx, 0, 0, 0, 0, 0, 0, 0, g_flOne, 0);

        // Apply new stack to cursor (EAX=newStack, DL=invType, ...)
        (void)invType;
        FUN_0093d6e0(/* newStack, invType, */ client, count);
        Client_RefreshOpenMissionUiWindows(client);
        return;
    }

    // Resolve failed or success flag clear
    std::uint32_t coidLo =
        reinterpret_cast<TFID_16*>(packet + 2)->dwCoidLo;
    char* msg = FUN_007a6de0("Grab Item failed: Failed on coid", 0xFFFFFFFFu);
    std::sprintf(local_80, "%s: %i\n", msg, coidLo);
    OutputDebugStringA(local_80);
    Client_RefreshOpenMissionUiWindows(client);
}
