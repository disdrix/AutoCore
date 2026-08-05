// READABILITY (auto CF):
//  - Body size: ~197 non-empty decompiler lines.
//  - Control keywords: if×28, return×11, goto×4, switch×1.
//  - Notable callees: Client_RefreshOpenMissionUiWindows×6, FUN_007a6de0×4, FUN_007fc150×4, FUN_007fdfb0×3, sprintf×3, FUN_00571620×2, FUN_0092ce90×2, FUN_009440e0×2.
//  - Strings: "Inventory Drop failed... server returned false"; "Called Drop on invalid inventory object, get a programmer"; "Dropping failed trying to add to inventory"; "Swapped Item didn\'t exist".
//  - Return sites: 11.

// =============================================================================
// Client_RecvInventoryDropResponse
// -----------------------------------------------------------------------------
// Purpose:  S2C InventoryDropResponse (opcode 0x2037). On success, resolve the
//           target inventory by type and either place the dropped item, perform
//           a swap, or concatenate stacks. Early-out on opcode 0x203b.
//
// Address:  0x00813730  (autoassault.exe, image base 0x400000)
// Stable:   aa_00813730
// System:   inventory-transfer
//
// Convention: PacketDispatch — client in EAX, packet in EBX (Confirmed).
//
// Opcode + ABI seal (2026-07-29 dual residual):
//   Client_PacketDispatch case 0x2037 / 0x203b → this function (sole xref 0x008159c2).
//   Call site 0x008159be: MOV EBX,ESI; MOV EAX,EBP; CALL 0x00813730.
//   Prologue: MOV ESI,EAX; clear [ESI+0xb6]; CMP [EBX],0x203b; CMP BYTE [EBX+0x22],0.
//   Body never positive-compares 0x2037; only early-outs 0x203b (shared slot).
//   Body range: 0x00813730 – 0x00813bd2.
//
// Packet fields:
//   +0x00  u32  opcode (0x2037; 0x203b → return)
//   +0x08  TFID dropped item (packet+2 as TFID_16*)
//   +0x18  u8   locX          (packet dword[6] low / +0x18)
//   +0x19  u8   locY
//   +0x1A  u8   inventoryType  1=cargo 3=locker 5=trade 6=other
//   +0x1C  i32  quantity
//   +0x22  u8   success
//   +0x23  u8   swapFlag
//   +0x28  i64  swap/occupant COID
//   +0x38  u8   concat sub-mode (1 = merge)
//
// Type → grid binding:
//   1 cargo  : vehicle+0x2b0; UI page host client+0x1040 → +0x50c → +0x580
//   3 locker : character+0xcbc; UI host client+0x1034 → +0x510 → +0x580
//   5 trade  : character+0xce0; UI host client+0x1050 → +0x588
//   6 other  : resolve TFID at char+0xcd8; UI host +0x58c
//
// Place: InventoryGrid_PlaceItemFootprint (FUN_00571620) at locX/locY
//        only when not already at that cell (FUN_00571b60 + vfuncs +0x250/+0x254).
//        Server success does NOT guarantee client place success.
//
// Control flow summary:
//   1) opcode 0x203b → return; success@+0x22 gate
//   2) resolve dropped item TFID; bind grid by inventoryType@+0x1A
//   3) swapFlag@+0x23 → swap occupant COID@+0x28 path
//   4) concat@+0x38!=0 → stack merge; else PlaceItemFootprint(locX,locY)
//   5) UI page host refresh per type (cargo/locker/trade/other)
//
// Related: docs/inventory-cargo-wire-re.md, stack-split design (concat path)
// Exactness: CF mirrors raw; names/types cleaned; no Ghidra placeholder types.
// Dual reviews (modern):
//   reviews/A_aa_00813730_Client_RecvInventoryDropResponse.md
//   reviews/B_aa_00813730_Client_RecvInventoryDropResponse.md
// Prior dual:
//   reviews/aa_00813730_reconstruction_review.md
//   reviews/aa_00813730_skeptical_review.md
// Scratch A: tmp/a_00813730.md
// =============================================================================

#include <cstdint>
#include <cstdio>

struct TFID_16 {
    std::uint32_t dwCoidLo;
    std::uint32_t dwCoidHi;
};

void         FUN_007a69d0();
char*        FUN_007a6de0(const char* key, std::uint32_t a);
void         FUN_007fdfb0(std::int32_t client, void* msg, std::uint32_t a,
                          std::uint32_t b, std::uint32_t c);
void         FUN_007fc150();
void         FUN_007fc270(std::uint8_t invType);
void         Client_RefreshOpenMissionUiWindows(std::int32_t client);
void*        Client_LookupObjectByTfid_Inferred(std::int32_t a, std::uint32_t lo,
                                                std::uint32_t hi);
void*        Object_ResolveFromTFID(TFID_16* tfid);
char         FUN_00571b60(void* item);
std::uint32_t FUN_00571620(void* item, char x, std::uint8_t y,
                           std::uint32_t qtyOrFlag); // PlaceItemFootprint (ECX=grid)
void*        FUN_00571010(std::uint32_t lo, std::uint32_t hi);
void         FUN_00571b80(void* item, std::uint32_t a, std::uint32_t b);
void         FUN_00513eb0(std::uint32_t a);
void         FUN_009440e0(void* obj, std::int32_t a, std::int32_t b,
                          std::uint32_t c, std::uint32_t d);
void         FUN_0092ce90();
void         FUN_0085e890();

void Client_RecvInventoryDropResponse()
{
    std::int32_t  client = 0;       // in_EAX
    std::int32_t* packet = nullptr; // unaff_EBX
    char          toastBuf[128];
    std::int32_t  uiPageHost = 0;   // local_94 - refreshed at end if set
    std::int32_t  targetGrid = 0;   // iVar8

    *reinterpret_cast<std::uint8_t*>(client + 0xb6) = 0;
    FUN_007a69d0();

    // Shared slot: not a drop response
    if (*packet == 0x203b) {
        return;
    }

    // success@+0x22
    if (*reinterpret_cast<char*>(reinterpret_cast<std::uint8_t*>(packet) + 0x22)
        == '\0') {
        char* msg = FUN_007a6de0(
            "Inventory Drop failed... server returned false", 0xFFFFFFFFu);
        std::sprintf(toastBuf, "%s", msg);
        FUN_007fdfb0(client, toastBuf, 0xFFFFFFFFu, 1, 0);
        FUN_007fc150();
        return;
    }

    // Require world / sector context
    if (*reinterpret_cast<std::int32_t*>(client + 0xe04) == 0) {
        return;
    }
    if (*reinterpret_cast<std::int32_t*>(
            *reinterpret_cast<std::int32_t*>(client + 0xe04) + 0xe4e8)
        == 0) {
        return;
    }

    std::int32_t character = *reinterpret_cast<std::int32_t*>(client + 0xe98);
    if (character == 0) {
        return;
    }

    // --- Bind target grid + optional UI page host by inventoryType@+0x1A ---
    std::uint8_t invType =
        *reinterpret_cast<std::uint8_t*>(
            reinterpret_cast<std::uint8_t*>(packet) + 0x1a);

    switch (invType) {
    case 1: { // cargo
        std::int32_t ui =
            *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(client + 0x1040) + 0x50c);
        if (ui != 0) {
            uiPageHost = *reinterpret_cast<std::int32_t*>(ui + 0x580);
        }
        if (*reinterpret_cast<std::int32_t*>(character + 0x250) == 0) {
            goto invalid_inventory;
        }
        targetGrid = *reinterpret_cast<std::int32_t*>(
            *reinterpret_cast<std::int32_t*>(character + 0x250) + 0x2b0);
        break;
    }
    case 3: { // locker
        std::int32_t ui =
            *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(client + 0x1034) + 0x510);
        if (ui != 0) {
            uiPageHost = *reinterpret_cast<std::int32_t*>(ui + 0x580);
        }
        targetGrid = *reinterpret_cast<std::int32_t*>(character + 0xcbc);
        break;
    }
    case 5: { // trade (self side)
        targetGrid = *reinterpret_cast<std::int32_t*>(character + 0xce0);
        if (*reinterpret_cast<std::int32_t*>(client + 0x1050) != 0) {
            uiPageHost = *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(client + 0x1050) + 0x588);
        }
        Client_RefreshOpenMissionUiWindows(client);
        break;
    }
    case 6: { // trade / other party
        void* other = Client_LookupObjectByTfid_Inferred(
            1,
            *reinterpret_cast<std::uint32_t*>(character + 0xcd8),
            *reinterpret_cast<std::uint32_t*>(character + 0xcdc));
        if (other != nullptr) {
            targetGrid =
                *reinterpret_cast<std::int32_t*>(
                    reinterpret_cast<std::uint8_t*>(other) + 0xce0);
        }
        if (*reinterpret_cast<std::int32_t*>(client + 0x1050) != 0) {
            uiPageHost = *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(client + 0x1050) + 0x58c);
        }
        Client_RefreshOpenMissionUiWindows(client);
        break;
    }
    default:
        goto invalid_inventory;
    }

    if (targetGrid == 0) {
    invalid_inventory:
        {
            void* msg = FUN_007a6de0(
                "Called Drop on invalid inventory object, get a programmer",
                0xFFFFFFFFu);
            FUN_007fdfb0(client, msg, 0xFFFFFFFFu, 1, 0);
        }
        return;
    }

    auto* pktBytes = reinterpret_cast<std::uint8_t*>(packet);
    char  swapFlag = static_cast<char>(pktBytes[0x23]);
    char  locX     = static_cast<char>(packet[6]); // +0x18 as low byte of dword[6]
    std::uint8_t locY = pktBytes[0x19];

    if (swapFlag == '\0') {
        // --- Normal place (no swap) ---
        std::int32_t* dropItem = nullptr;

        if (invType == 6) {
            dropItem = reinterpret_cast<std::int32_t*>(
                Object_ResolveFromTFID(reinterpret_cast<TFID_16*>(packet + 2)));
        } else {
            std::int32_t* cursor =
                *reinterpret_cast<std::int32_t**>(client + 0x9b8);
            if (cursor == nullptr) {
                return;
            }
            std::int32_t held =
                (**(std::int32_t(**)())(*cursor + 0x3ac))();
            if (held == 0) {
                return;
            }
            dropItem = reinterpret_cast<std::int32_t*>(
                (**(std::int32_t(**)())(*cursor + 0x3ac))());
            FUN_007fc150(); // clear cursor after taking held ref
        }

        if (dropItem == nullptr) {
            return;
        }

        // If item not already at (locX,locY), try PlaceItemFootprint
        char already =
            FUN_00571b60(dropItem);
        char atX = (**(char(**)())(*dropItem + 0x250))();
        char atY = (**(char(**)())(*dropItem + 0x254))();

        if (already == '\0' || atX != locX || atY != static_cast<char>(locY)) {
            std::uint32_t qtyOrFlag =
                (**(std::uint32_t(**)())(*dropItem + 0x25c))();
            // ECX = targetGrid (thiscall); decompiler omits explicit this
            char placed = static_cast<char>(
                FUN_00571620(dropItem, locX, locY, qtyOrFlag));
            if (placed == '\0') {
                std::uint32_t coidLo = static_cast<std::uint32_t>(packet[2]);
                char* msg = FUN_007a6de0(
                    "Dropping failed trying to add to inventory", 0xFFFFFFFFu);
                std::sprintf(toastBuf, "%s: %i", msg, coidLo);
                FUN_007fdfb0(client, toastBuf, 0xFFFFFFFFu, 1, 0);
                FUN_007fc150();
                goto end_ui_refresh;
            }
        }

        Client_RefreshOpenMissionUiWindows(client);
        FUN_0092ce90();
    } else {
        // --- Swap or concatenate ---
        std::int32_t* occupant = reinterpret_cast<std::int32_t*>(
            FUN_00571010(static_cast<std::uint32_t>(packet[10]),
                         static_cast<std::uint32_t>(packet[11])));

        char concatMode = static_cast<char>(packet[0xe]); // +0x38

        if (concatMode == '\0') {
            // Positional swap
            if (occupant == nullptr) {
                std::uint32_t coidLo = static_cast<std::uint32_t>(packet[2]);
                char* msg = FUN_007a6de0("Swapped Item didn't exist", 0xFFFFFFFFu);
                std::sprintf(toastBuf, "%s: %i", msg, coidLo);
                FUN_007fdfb0(client, toastBuf, 0xFFFFFFFFu, 1, 0);
                FUN_007fc150();
            } else {
                std::uint32_t occQty =
                    (**(std::uint32_t(**)())(*occupant + 0x25c))();
                std::uint32_t occQty2 =
                    (**(std::uint32_t(**)(std::int32_t))(*occupant + 0x25c))(0);
                FUN_00571b80(occupant, occQty2, 0);

                if (invType == 6) {
                    FUN_009440e0(occupant, 1, 0, 0xFFFFFFFFu, 0xFFFFFFFFu);
                }

                std::int32_t* dropItem = reinterpret_cast<std::int32_t*>(
                    Object_ResolveFromTFID(
                        reinterpret_cast<TFID_16*>(packet + 2)));
                std::uint32_t dropQty =
                    (**(std::uint32_t(**)())(*dropItem + 0x25c))();
                char placed = static_cast<char>(
                    FUN_00571620(dropItem, locX, locY, dropQty));

                if (placed != '\0') {
                    if (invType != 6) {
                        (**(void(**)(std::uint32_t))(*occupant + 0x260))(occQty);
                        FUN_007fc270(invType);
                    }
                    Client_RefreshOpenMissionUiWindows(client);
                    FUN_0092ce90();
                    return;
                }

                std::uint32_t coidLo =
                    reinterpret_cast<TFID_16*>(packet + 2)->dwCoidLo;
                char* msg = FUN_007a6de0(
                    "Dropping failed trying to swap", 0xFFFFFFFFu);
                std::sprintf(toastBuf, "%s: %i", msg, coidLo);
                FUN_007fdfb0(client, toastBuf, 0xFFFFFFFFu, 1, 0);
                FUN_007fc150();
            }
        } else {
            // Concatenate / stack merge (concatMode != 0)
            if (occupant != nullptr) {
                if (invType == 6) {
                    (**(void(**)(std::int32_t))(*occupant + 0x260))(packet[7]);
                    *reinterpret_cast<std::int16_t*>(
                        reinterpret_cast<std::uint8_t*>(occupant) + 0x180) =
                        static_cast<std::int16_t>(packet[8]);
                    Client_RefreshOpenMissionUiWindows(client);
                } else {
                    std::int32_t* cursor =
                        *reinterpret_cast<std::int32_t**>(client + 0x9b8);
                    if (cursor != nullptr) {
                        std::int32_t held =
                            (**(std::int32_t(**)())(*cursor + 0x3ac))();
                        if (held != 0) {
                            std::uint32_t heldObj =
                                (**(std::uint32_t(**)())(*cursor + 0x3ac))();
                            FUN_00513eb0(heldObj);
                            std::int32_t* heldItem = reinterpret_cast<std::int32_t*>(
                                (**(std::int32_t(**)())(*cursor + 0x3ac))());
                            std::uint32_t sectorCtx =
                                *reinterpret_cast<std::uint32_t*>(
                                    *reinterpret_cast<std::int32_t*>(client + 0xe04)
                                    + 0xe4e8);
                            (**(void(**)(std::uint32_t))(*heldItem + 0x2a8))(
                                sectorCtx);
                            std::uint32_t destroyed =
                                (**(std::uint32_t(**)(
                                    std::int32_t, std::int32_t, std::uint32_t,
                                    std::uint32_t))(*cursor + 0x3ac))(
                                    1, 0, 0xFFFFFFFFu, 0xFFFFFFFFu);
                            FUN_009440e0(reinterpret_cast<void*>(destroyed), 0,
                                         0xFFFFFFFFu, 0xFFFFFFFFu, sectorCtx);
                        }
                    }
                    FUN_007fc150();
                    Client_RefreshOpenMissionUiWindows(client);
                }
                goto end_ui_refresh;
            }

            // Occupant missing
            {
                std::int32_t coidLo = packet[2];
                char* msg = FUN_007a6de0(
                    "Dropping failed trying to concatinate", 0xFFFFFFFFu);
                std::sprintf(toastBuf, "%s: %i", msg, coidLo);
                FUN_007fdfb0(client, toastBuf, 0xFFFFFFFFu, 1, 0);
                FUN_007fc150();
            }
        }
    }

end_ui_refresh:
    if (uiPageHost != 0) {
        FUN_0085e890();
    }
}
