// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×14, return×9, goto×1.
//  - Notable callees: sprintf×2, CONCAT11, CONCAT12, CONCAT31, Client_SendSectorPacket, Client_UI_InventoryDropToGrid, FUN_00513770, FUN_007a69d0.
//  - Strings: "You cannot trade items that have been customized to you!"; "You cannot trade this item!"; "The store does not want that item."; "Failed to drop object into inventory grid (not found)".
//  - Return sites: 9.

// =============================================================================
// Client_UI_InventoryDropToGrid
// -----------------------------------------------------------------------------
// Purpose:  UI drop handler - validate target inventory type, then send C2S
//           InventoryDrop (0x2036 / size 0x20) or store-sell (0x2027 / size 0x40).
//
// Address:  0x00860a50  (autoassault.exe, image base 0x400000)
// Stable:   aa_00860a50
// System:   inventory-transfer
//
// Convention: client/window context in EAX (`in_EAX` / clientOrWindow).
//
// Type gate (window[0x15b]+4 == window+0x56c type host):
//   1 cargo, 3 locker - class-4 items allowed into these targets
//   (not an exclusive allow-list: non-1/3 only blocks when held class==4)
//   5 trade - reject customized (bit 20 of +0x17c) and non-tradable (+0x4be)
//   4 store - sell packet path (0x2027 / 0x40)
//
// Grid drop packet (0x20) — decompile + pack-site asm sealed (residual 2026-07-29):
//   +0x00  u32  opcode = 0x2036     (mov dword …, 0x00002036)
//   +0x04  —    NOT written
//   +0x08  u64  item COID           (cursor item +0x160/+0x164)
//   +0x10  u8   TFID global         (item +0x168)
//   +0x18  u8   ucInventoryLocX     (local_106 from FUN_0085f220)
//   +0x19  u8   ucInventoryLocY     pageH*pageIdx+cellY
//                                   pageH=FUN_0085f1d0=*(typeHost+0x1c);
//                                   pageIdx=*(i8*)(window+0x564); cellY=local_105
//   +0x1a  u8   ucTypeTo            *(typeHost+4); typeHost=*(window+0x56c)
//   +0x1c  —    lQuantity NOT written on grid path (stack garbage)
//
// Retail struct: SMSG_Sector_InventoryDrop Size=0x20 (PACKET STRUCTURES.md).
// Server: InventoryDropPacket / GameOpcode.InventoryDrop = 0x2036.
//
// Busy DAT_00d1a8f6: return 1 without re-send. Success sets busy + returns 1.
// Does NOT place footprint — waits for S2C DropResponse.
//
// Control flow summary:
//   1) DAT_00d1b6d8 null → 0; FUN_0085f220 drop-coords fail → 0
//   2) Block held object-class 4 unless target cargo(1)/locker(3)
//   3) trade(5): reject customized (bit20 @+0x17c) / non-tradable (+0x4be)
//   4) else notify prior cargo owner; busy → soft 1
//   5) vendor/store paths → opcode 0x2027 size 0x40; else grid drop 0x2036 size 0x20
//   6) Client_SendSectorPacket; set busy; fail → toast
//
// DropResponse inventoryType@+0x1A switch (destination grid bind):
//   1 cargo / 3 locker / 5 trade / 6 other → PlaceItemFootprint
//   See: raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md
//
// Related: docs/inventory-cargo-wire-re.md
// Exactness: Control flow mirrors raw decompile; names/types cleaned.
// Dual reviews:
//   reviews/A_aa_00860a50_Client_UI_InventoryDropToGrid.md
//   reviews/B_aa_00860a50_Client_UI_InventoryDropToGrid.md
// =============================================================================

#include <cstdint>
#include <cstdio>

extern std::int32_t  DAT_00d1b6d8;
extern std::int32_t* DAT_00d1b1f8;
extern char          DAT_00d1a8f6;
extern std::uint8_t  DAT_00d1a840;

char         FUN_0085f220(std::uint8_t* outA, char* outB, std::uint32_t* outC);
char         FUN_0085f1d0();
char         FUN_00513770();
std::int32_t FUN_007a69d0();
char*        FUN_007a6de0(const char* key, std::uint32_t a);
void         FUN_007fdfb0(void* client, char* msg, std::uint32_t a,
                          std::uint32_t b, std::uint32_t c);
void         Client_SendSectorPacket(void* client, std::int16_t size, void* pkt);

std::uint32_t Client_UI_InventoryDropToGrid()
{
    // EAX = client/window context (decompiler in_EAX)
    std::int32_t* clientOrWindow = nullptr; // in_EAX - caller-established
    // EDX after FUN_0085f1d0 (extraout_EDX) used for one packet byte

    if (DAT_00d1b6d8 == 0) {
        return 0;
    }

    std::uint32_t unusedLocal = 0;
    std::uint8_t  dropCoordA  = 0; // local_106
    char          dropCoordB  = 0; // local_105

    char ok = FUN_0085f220(&dropCoordA, &dropCoordB, &unusedLocal);
    if (ok == '\0') {
        return 0;
    }

    // Block held object-type 4 when target is not cargo(1) or locker(3)
    std::int32_t invType =
        *reinterpret_cast<std::int32_t*>(clientOrWindow[0x15b] + 4);
    if (invType != 3 && invType != 1) {
        std::int32_t held =
            (**(std::int32_t(**)())(*DAT_00d1b1f8 + 0x3ac))();
        if (*reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(held + 0xa8) + 0x38) == 4) {
            return 0;
        }
    }

    char* failMsg = nullptr;
    char  toastBuf[128];
    char  pkt[128];
    // Packet field overlays (decompiler stack names)
    // pkt[0..3]   opcode bytes
    // +0x08/+0x0c item id lo/hi
    // +0x10       item type byte
    // +0x18..     drop cell / vendor ids
    std::uint32_t* pktU32 = reinterpret_cast<std::uint32_t*>(pkt);
    std::uint8_t*  pktU8  = reinterpret_cast<std::uint8_t*>(pkt);

    // Trade type 5 - customized-to-you
    if (invType == 5) {
        std::int32_t held =
            (**(std::int32_t(**)())(*DAT_00d1b1f8 + 0x3ac))();
        if (((*reinterpret_cast<std::uint32_t*>(held + 0x17c) >> 0x14) & 1u) != 0) {
            failMsg = const_cast<char*>(
                "You cannot trade items that have been customized to you!");
            goto LAB_fail_toast;
        }
    }

    // Trade type 5 - non-tradable flag
    if (invType == 5) {
        std::int32_t held =
            (**(std::int32_t(**)())(*DAT_00d1b1f8 + 0x3ac))();
        if (*reinterpret_cast<char*>(
                *reinterpret_cast<std::int32_t*>(
                    *reinterpret_cast<std::int32_t*>(held + 0xa8) + 0x3c)
                + 0x4be) != '\0') {
            failMsg = const_cast<char*>("You cannot trade this item!");
            goto LAB_fail_toast;
        }
    } else {
        // Notify previous inventory owner if it has a cargo grid
        std::int32_t prior = clientOrWindow[0x15d];
        if (prior != 0
            && *reinterpret_cast<std::int32_t*>(prior + 0x2b0) != 0) {
            (**(void(**)(std::int32_t))(*clientOrWindow + 0xb0))(prior);
        }

        if (DAT_00d1a8f6 != '\0') {
            return 1; // busy - soft success
        }

        std::int32_t held =
            (**(std::int32_t(**)())(*DAT_00d1b1f8 + 0x3ac))();
        if (held != 0) {
            std::int16_t size = 0;

            // Vendor active + mode 4 → store-sell size 0x40 branch
            if (*reinterpret_cast<std::int32_t*>(DAT_00d1b6d8 + 0xcd0) != 0
                && DAT_00d1b1f8[0x125] == 4) {
                held = (**(std::int32_t(**)())(*DAT_00d1b1f8 + 0x3ac))();
                if (*reinterpret_cast<std::int32_t*>(
                        *reinterpret_cast<std::int32_t*>(held + 0xa8) + 0x38)
                    == 4) {
                    return 0;
                }
                pkt[0] = '\''; // 0x27
                pkt[1] = ' ';
                pkt[2] = '\0';
                pkt[3] = '\0';
                pktU8[0x38] = 1;
                {
                    std::int32_t* vendor =
                        *reinterpret_cast<std::int32_t**>(DAT_00d1b6d8 + 0xcd0);
                    pktU32[0x0f] = // uStack_c4 at +0x3c
                        (**(std::uint32_t(**)())(*vendor + 0x25c))();
                    std::int32_t v =
                        *reinterpret_cast<std::int32_t*>(DAT_00d1b6d8 + 0xcd0);
                    pktU32[0x06] = *reinterpret_cast<std::uint32_t*>(v + 0x160);
                    pktU32[0x07] = *reinterpret_cast<std::uint32_t*>(v + 0x164);
                    pktU32[0x08] = *reinterpret_cast<std::uint32_t*>(v + 0x168);
                    pktU32[0x09] = *reinterpret_cast<std::uint32_t*>(v + 0x16c);
                }
                size = 0x40;
            } else if (invType == 4) {
                // Store inventory type without the mode-4 vendor shortcut
                held = (**(std::int32_t(**)())(*DAT_00d1b1f8 + 0x3ac))();
                if (*reinterpret_cast<std::int32_t*>(
                        *reinterpret_cast<std::int32_t*>(held + 0xa8) + 0x38)
                    == 4) {
                    return 0;
                }
                (**(std::int32_t(**)())(*DAT_00d1b1f8 + 0x3ac))();
                if (FUN_00513770() == '\0') {
                    if (FUN_007a69d0() == 0) {
                        return 0;
                    }
                    char* fmt = FUN_007a6de0(
                        "The store does not want that item.", 0xFFFFFFFFu);
                    std::sprintf(toastBuf, "%s", fmt);
                    failMsg = toastBuf;
                    goto LAB_fail_toast;
                }
                pkt[0] = '\'';
                pkt[1] = ' ';
                pkt[2] = '\0';
                pkt[3] = '\0';
                pktU8[0x38] = 0;
                {
                    std::int32_t* vendor =
                        *reinterpret_cast<std::int32_t**>(DAT_00d1b6d8 + 0xcd0);
                    pktU32[0x0f] =
                        (**(std::uint32_t(**)())(*vendor + 0x25c))();
                    std::int32_t v =
                        *reinterpret_cast<std::int32_t*>(DAT_00d1b6d8 + 0xcd0);
                    pktU32[0x06] = *reinterpret_cast<std::uint32_t*>(v + 0x160);
                    pktU32[0x07] = *reinterpret_cast<std::uint32_t*>(v + 0x164);
                    pktU32[0x08] = *reinterpret_cast<std::uint32_t*>(v + 0x168);
                    pktU32[0x09] = *reinterpret_cast<std::uint32_t*>(v + 0x16c);
                }
                size = 0x40;
            } else {
                // Normal grid drop - opcode low bytes '6',' ' → 0x2036 packing
                pktU8[0x10] = *reinterpret_cast<std::uint8_t*>(held + 0x168);
                pktU32[0x02] = *reinterpret_cast<std::uint32_t*>(held + 0x160);
                pktU32[0x03] = *reinterpret_cast<std::uint32_t*>(held + 0x164);
                pkt[0] = '6';
                pkt[1] = ' ';
                pkt[2] = '\0';
                pkt[3] = '\0';

                // Cell encoding: dropCoordA / adjusted Y (FUN_0085f1d0 + scale)
                std::uint32_t cellWord = dropCoordA;
                char adj = FUN_0085f1d0();
                // extraout_EDX from FUN_0085f1d0 supplies a byte at +4
                std::int32_t extraout_EDX = 0; // register result of FUN_0085f1d0
                std::uint8_t yByte = static_cast<std::uint8_t>(
                    adj * static_cast<char>(clientOrWindow[0x159]) + dropCoordB);
                // decompiler CONCAT into uStack_e8 bytes:
                pktU8[0x18] = static_cast<std::uint8_t>(cellWord);
                pktU8[0x19] = yByte;
                pktU8[0x1a] =
                    *reinterpret_cast<std::uint8_t*>(extraout_EDX + 4);

                size = 0x20;
            }

            Client_SendSectorPacket(&DAT_00d1a840, size, pkt);
            DAT_00d1a8f6 = '\x01';
            return 1;
        }

        std::sprintf(pkt, "Failed to drop object into inventory grid (not found)");
        failMsg = pkt;
    }

LAB_fail_toast:
    FUN_007fdfb0(&DAT_00d1a840, failMsg, 0xFFFFFFFFu, 1, 0);
    return 0;
}
