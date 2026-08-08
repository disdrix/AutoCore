// =============================================================================
// Client_RecvOpenAvailableGadgetResponse  (FUN_0080d570)
// -----------------------------------------------------------------------------
// Purpose:  S2C 0x20A8 OpenAvailableGadgetResponse — client result of opening a
//           gadget slot on an inventory item via tinkering kit.
//
// Address:  0x0080d570  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080d570
// System:   inventory-transfer
// Body:     0x0080d570–0x0080d915 (933 B); epilogue ADD ESP,0x104; RET 4
//
// Wire:     Client_PacketDispatch case 0x20A8 → FUN_0080d570(packet*)
// ABI:      stack packet*; RET 4; ClientContext* in ESI (dispatch custom ABI)
//
// Packet (body-used):
//   +0x10/+0x14 item COID; +0x18/+0x1c kit id; +0x28 failReason;
//   +0x2c success (char); +0x2d catastrophic (char, case 4)
//
// Item find (asm; decompiler hides this):
//   cargo = *(*(ESI+0xe98)+0x250)+0x2b0; FindItemByCoid
//   else locker = *(ESI+0xe98)+0xcbc; FindItemByCoid
//
// Dual A/B: docs/reconstruction/reviews/A|B_aa_0080d570_...
// Exactness: CF/opcode/grids/fail enum sealed; nested kit-host MI residual.
// =============================================================================

#include <cstdint>
#include <cstdio>

// Forward decls — sealed siblings / shared client helpers
extern "C" void* __thiscall InventoryGrid_FindItemByCoid(void* grid, std::uint32_t lo, std::uint32_t hi);
extern "C" std::uint8_t InventoryGrid_ContainsItem_Probe(void* p);  // FUN_00571b60
extern "C" void* __thiscall InventoryGrid_RemoveItem(void* grid, void* item, int qty, char force);
extern "C" void* __cdecl CVOGReaction_ResolveObjectTarget(int mode, std::uint32_t lo, std::uint32_t hi);
extern "C" void FUN_007a69d0();
extern "C" void* FUN_007a6de0(const char* s, int n);
extern "C" void FUN_007fdfb0(void* client, void* msg, int a, int b, int c);
extern "C" void FUN_00933310(void* client, int a, int b, int c, int d);
extern "C" void* Client_GetMissionCompleteAudioTable(const char*, int, int, int, int, int, int, int);
extern "C" void Client_PlayNamedInterfaceSound(const char*, int, int, int, int, int, int, int);
extern "C" void Client_RefreshOpenMissionUiWindows(void* client);

// DAT_00a7d1f0 → "of" (read_memory)
static const char kStrOf[] = "of";

/// S2C 0x20A8. @param pkt packet*; retail ESI = client (unaff_ESI in decompiler).
void Client_RecvOpenAvailableGadgetResponse(std::uint8_t* pkt /* + ESI client */)
{
    void* client = nullptr;  // retail: ESI from Client_PacketDispatch
    char msgBuf[256];

    auto* character = *reinterpret_cast<std::uint8_t**>(reinterpret_cast<std::uint8_t*>(client) + 0xe98);
    if (character == nullptr) {
        return;
    }
    if (*reinterpret_cast<std::uint32_t*>(character + 0x250) == 0) {
        return;
    }

    FUN_007a69d0();

    // --- item by COID: cargo then locker (asm this-ptr) ---
    const std::uint32_t coidLo = *reinterpret_cast<std::uint32_t*>(pkt + 0x10);
    const std::uint32_t coidHi = *reinterpret_cast<std::uint32_t*>(pkt + 0x14);

    void* cargoHost = *reinterpret_cast<void**>(character + 0x250);
    void* cargoGrid = reinterpret_cast<std::uint8_t*>(cargoHost) + 0x2b0;
    void* item = InventoryGrid_FindItemByCoid(cargoGrid, coidLo, coidHi);
    if (item == nullptr) {
        void* lockerGrid = character + 0xcbc;
        item = InventoryGrid_FindItemByCoid(lockerGrid, coidLo, coidHi);
    }

    const std::uint32_t kitLo = *reinterpret_cast<std::uint32_t*>(pkt + 0x18);
    const std::uint32_t kitHi = *reinterpret_cast<std::uint32_t*>(pkt + 0x1c);
    // Resolve this = client+0xe04 path in asm; decompiler shows free call.
    void* kitObj = CVOGReaction_ResolveObjectTarget(1, kitLo, kitHi);

    if (item == nullptr || kitObj == nullptr) {
        void* m = FUN_007a6de0("BUG: Tinkering kit or Target Object not found.", -1);
        FUN_007fdfb0(client, m, -1, 1, 0);
        return;
    }

    // vtbl+0x200 cast-as-TinkeringKit
    using CastFn = void*(__thiscall*)(void*);
    auto** vtbl = *reinterpret_cast<void***>(kitObj);
    void* kit = reinterpret_cast<CastFn>(vtbl[0x200 / 4])(kitObj);
    if (kit == nullptr) {
        void* m = FUN_007a6de0(
            "BUG: Tinkering Kit object could not be cast as TinkeringKit type.", -1);
        FUN_007fdfb0(client, m, -1, 1, 0);
        return;
    }

    void* toastMsg = nullptr;
    int toastA = -1;
    int toastB = 1;
    int toastC = 0;

    if (pkt[0x2c] != 0) {
        // ---- SUCCESS ----
        // open-slot counter: get vtbl+0x8c, set vtbl+0x90(get+1)
        auto** itemVtbl = *reinterpret_cast<void***>(item);
        using GetI = int(__thiscall*)(void*);
        using SetI = void(__thiscall*)(void*, int);
        int cur = reinterpret_cast<GetI>(itemVtbl[0x8c / 4])(item);
        reinterpret_cast<SetI>(itemVtbl[0x90 / 4])(item, cur + 1);

        // max slots from clonebase blob +0x4b4 (short)
        // item[0x2a]+0x3c → blob; *(short*)(blob+0x4b4)
        // build sprintf "%s! %s %s %i %s %i %s." with localized fragments
        // "Tinkering successful" / item name / "now has" / N / "of" / max / "Gadget Slots available"
        Client_GetMissionCompleteAudioTable("tinker_success", 0, -1, -1, 0, 0, 0x1e, 0);
        Client_PlayNamedInterfaceSound("tinker_success", 0, -1, -1, 0, 0, 0x1e, 0);
        toastMsg = msgBuf;  // formatted buffer in retail
        // fall through to toast at LAB_0080d826
    } else {
        // ---- FAIL ----
        Client_GetMissionCompleteAudioTable("tinker_fail", 0, -1, -1, 0, 0, 0x1e, 0);
        Client_PlayNamedInterfaceSound("tinker_fail", 0, -1, -1, 0, 0, 0x1e, 0);

        const std::uint32_t reason = *reinterpret_cast<std::uint32_t*>(pkt + 0x28);
        switch (reason) {
        case 1:
            toastMsg = FUN_007a6de0(
                "BUG: Tinkering kit not found. Server thinks it worked.", -1);
            break;
        case 2:
            toastMsg = FUN_007a6de0(
                "BUG: Item to tinker not found. Server thinks it worked.", -1);
            break;
        case 3:
            toastMsg = FUN_007a6de0("No available slots to open on this item.", -1);
            break;
        case 4:
            if (pkt[0x2d] == 0) {
                toastMsg = FUN_007a6de0("Tinkering failed on this item.", -1);
                break;
            }
            {
                void* cat = FUN_007a6de0(
                    "Catastrophic failure! Item and Tinkering Kit destroyed!", -1);
                FUN_007fdfb0(client, cat, -1, 1, 0);
                // double Contains then RemoveItem(item,1,force=1)
                std::uint8_t c1 = InventoryGrid_ContainsItem_Probe(item);
                if (c1 != 0 || InventoryGrid_ContainsItem_Probe(item) != 0) {
                    InventoryGrid_RemoveItem(/*grid from item host*/ item, item, 1, 1);
                }
                FUN_00933310(client, 1, 0, -1, -1);
            }
            goto kit_cleanup;  // retail: default fallthrough skips second toast
        default:
            goto kit_cleanup;
        }
    }

    // LAB_0080d826
    FUN_007fdfb0(client, toastMsg, toastA, toastB, toastC);

kit_cleanup:
    // Remove kit if still present on kit inventory host (MI-adjusted expression
    // from decompiler: *( *(kit+4)+4 ) + 4 + kit — sealed as residual detail).
    // if Contains(kitHost): RemoveItem(kitHost, 1, force=0)
    (void)kit;
    FUN_00933310(client, 1, 0, -1, -1);
    Client_RefreshOpenMissionUiWindows(client);
}
