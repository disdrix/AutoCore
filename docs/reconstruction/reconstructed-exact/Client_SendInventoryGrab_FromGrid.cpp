// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: Client_SendInventoryGrab_FromGrid, FUN_007fbbb0, InventoryGrab.
//  - Return sites: 1.

// =============================================================================
// Client_SendInventoryGrab_FromGrid
// -----------------------------------------------------------------------------
// Purpose:  Build and send C2S InventoryGrab (opcode 0x2034, size 0x20) for an
//           item taken from an inventory grid UI window. Optionally refreshes a
//           UI widget when the grabbed object matches the tracked selection.
//
// Address:  0x00860e20  (autoassault.exe, image base 0x400000)
// Stable:   aa_00860e20
// System:   inventory-transfer
//
// Convention: selection / live-object host arrives in EDI (decompiler
//             `unaff_EDI`); inv window and quantity are stack args.
//
// Packet layout (0x20 bytes @ stack) — decompile-sealed written fields:
//   +0x00  u32  opcode = 0x2034          (literal)
//   +0x04  —    NOT written by FromGrid  (stack garbage; docs may call txn id)
//   +0x08  u32  item id lo               (object +0x160)
//   +0x0C  u32  item id hi               (object +0x164)
//   +0x10  u8   TFID global byte         (object +0x168)
//   +0x11..+0x17 pad (unwritten)
//   +0x18  u8   ucTypeFrom               (window+0x56c → +4)
//   +0x19..+0x1b pad (unwritten)
//   +0x1C  u32  lQuantity                (stack arg — whole or partial-split request)
//
// Retail struct: SMSG_Sector_InventoryGrab Size=0x20 (PACKET STRUCTURES.md).
// Server: InventoryGrabPacket / GameOpcode.InventoryGrab = 0x2034.
//
// Pack vs split: this unit ONLY packs lQuantity. Stack peel / SplitCoid /
// cursor live in Client_RecvInventoryGrabResponse (0x00811be0). Callers load
// qty via item vfunc +0x25c or field +0x4fc; sites 0x00861a98 / 0x00861b3c /
// 0x0083e677 also MOV EDI=selection host before CALL.
// Hardpoint sibling (0x00862d90): type=2 literal, no +0x1c write.
//
// Send: g_pSectorNetConnection_INFERRED vtable +0x18 (channel -1, size 0x20).
// Busy: DAT_00d1a8f6 - skip send when non-zero; set on send path.
// Always returns 1 (including busy-skip — not a "sent OK" code).
//
// Control flow summary:
//   1) Optional UI path: selectionHost GetObject @ vtbl+0x3ac; if match/null,
//      set DAT_00d1d8f4/f5 and refresh tracked host via DAT_00d1d8dc vtbl+4 (not +0x3ac)
//   2) FUN_007fbbb0() pre-send hook
//   3) if DAT_00d1a8f6 == 0:
//        pack 0x2034 (item TFID from object via GetObject +0x3ac, type from window, qty arg)
//        net send size 0x20; set busy flags DAT_00d1b4b0 / DAT_00d1a8f6
//   4) return 1
//
// Drop closes the transfer: DropToGrid (0x2036) → DropResponse (0x2037) binds
// destination grid by inventoryType@+0x1A (1 cargo / 3 locker / 5 trade / 6).
// See: raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md
//
// Related: docs/inventory-cargo-wire-re.md
// Exactness: Preserves UI-refresh gate, busy gate, dual GetObject calls, fields.
// Dual reviews (pack/split residual 2026-07-29):
//   reviews/A_aa_00860e20_Client_SendInventoryGrab_FromGrid.md
//   reviews/B_aa_00860e20_Client_SendInventoryGrab_FromGrid.md
// =============================================================================

#include <cstdint>

extern std::int32_t* DAT_00d1d8dc;
extern std::uint8_t  DAT_00d1d8f4;
extern std::uint8_t  DAT_00d1d8f5;
extern char          DAT_00d1a8f6;
extern std::uint8_t  DAT_00d1b4b0;
extern void*         g_pSectorNetConnection_INFERRED;

void FUN_007fbbb0();

/// @param invWindow       UI window; inventory type at *(window+0x56c)+4
/// @param quantity        Grab count
/// @param selectionHost   EDI: object host with vfunc +0x3ac → world object
/// @return 1
std::uint32_t Client_SendInventoryGrab_FromGrid(std::int32_t invWindow,
                                                std::uint32_t quantity,
                                                std::int32_t* selectionHost)
{
    // --- Optional UI refresh when selection matches tracked widget ---
    if (selectionHost != nullptr) {
        using GetObjFn = std::int32_t(__thiscall*)(void*);
        auto* selVt = *reinterpret_cast<void***>(selectionHost);
        std::int32_t grabbedObj = reinterpret_cast<GetObjFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(selVt) + 0x3ac))(selectionHost);

        if (grabbedObj == 0
            || DAT_00d1d8dc == nullptr
            || grabbedObj == DAT_00d1d8dc[0x146]) {
            DAT_00d1d8f4 = 1;
            DAT_00d1d8f5 = 0;
            if (DAT_00d1d8dc != nullptr) {
                using RefreshFn = void(__thiscall*)(void*, std::int32_t);
                auto* hostVt = *reinterpret_cast<void***>(DAT_00d1d8dc);
                reinterpret_cast<RefreshFn>(
                    *reinterpret_cast<void**>(
                        reinterpret_cast<std::uint8_t*>(hostVt) + 4))(
                    DAT_00d1d8dc, 0);
            }
        }
    }

    FUN_007fbbb0();

    if (DAT_00d1a8f6 == '\0') {
        // Stack packet image (decompiler: auStack_20 / uStack_*)
        std::uint32_t pktDwords[8]; // 0x20 bytes; only written fields matter
        std::uint8_t* packet = reinterpret_cast<std::uint8_t*>(pktDwords);

        pktDwords[0] = 0x2034; // opcode

        using GetObjFn = std::int32_t(__thiscall*)(void*);
        auto* selVt = *reinterpret_cast<void***>(selectionHost);

        std::int32_t obj = reinterpret_cast<GetObjFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(selVt) + 0x3ac))(selectionHost);
        packet[0x10] = *reinterpret_cast<std::uint8_t*>(obj + 0x168);

        obj = reinterpret_cast<GetObjFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(selVt) + 0x3ac))(selectionHost);
        *reinterpret_cast<std::uint32_t*>(packet + 0x08) =
            *reinterpret_cast<std::uint32_t*>(obj + 0x160);
        *reinterpret_cast<std::uint32_t*>(packet + 0x0c) =
            *reinterpret_cast<std::uint32_t*>(obj + 0x164);

        // inventoryType from window
        std::int32_t invTypeHost =
            *reinterpret_cast<std::int32_t*>(invWindow + 0x56c);
        packet[0x18] = *reinterpret_cast<std::uint8_t*>(invTypeHost + 4);

        *reinterpret_cast<std::uint32_t*>(packet + 0x1c) = quantity;

        if (g_pSectorNetConnection_INFERRED != nullptr) {
            using NetSendFn =
                void(__thiscall*)(void*, std::uint32_t, void*, std::uint32_t,
                                  std::uint32_t);
            auto* netVt =
                *reinterpret_cast<void***>(g_pSectorNetConnection_INFERRED);
            reinterpret_cast<NetSendFn>(
                *reinterpret_cast<void**>(
                    reinterpret_cast<std::uint8_t*>(netVt) + 0x18))(
                g_pSectorNetConnection_INFERRED,
                0xFFFFFFFFu,
                packet,
                0x20,
                0);
        }

        DAT_00d1b4b0 = 1;
        DAT_00d1a8f6 = '\x01';
    }

    return 1;
}
