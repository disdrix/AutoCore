// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, for×2.
//  - Notable callees: Client_SendInventoryAddItem, Client_SendLogicUiPacket, FUN_00404c90, FUN_004d2820, FUN_004d4790, FUN_00570710, FUN_00571620, FUN_00571830.
//  - Strings: "INVENTORY FAILURE for %I64d item:%I64d".
//  - Return sites: 4.

// =============================================================================
// Client_SendInventoryAddItem
// -----------------------------------------------------------------------------
// Purpose:  Build and send InventoryAddItem (opcode 0x2047, 0x20-byte struct)
//           when placing an item into cargo (e.g. drag into slot). Clears item
//           flag bit 2, allocates packet, calls Inventory_SerializeAddItemPacket,
//           then either places locally (addToExisting==0) or merges onto stack
//           (addToExisting!=0). Logs "INVENTORY FAILURE…" when residual check
//           FUN_00570710 fails after merge.
//
// Address:  0x00530df0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00530df0
// System:   inventory-transfer
//
// Convention: MSVC __thiscall
//   this / pHost   character or inventory host (vehicle cargo via +0x250)
//   pItem          item object (COID at dword [0x58]/[0x59] = +0x160/+0x164)
//   mergeContext   forwarded to FUN_00571830 on merge path
//
// Packet (filled by SerializeAddItemPacket):
//   +0x00  opcode 0x2047
//   +0x08  item COID lo/hi
//   +0x10  X, +0x11 Y, +0x12 addToExisting, +0x18 wasAdded
//
// Control flow summary:
//   1) Clear item flag bit 2; allocate 0x20 packet; SerializeAddItemPacket
//   2) Client_SendLogicUiPacket(packet)
//   3) addToExisting==0 → local PlaceItemFootprint path
//      else merge FUN_00571830; residual FUN_00570710 fail → "INVENTORY FAILURE"
//   4) free packet (operator_delete; Ghidra noreturn noise on some edges)
//
// Note: Ghidra marks operator_delete as noreturn on several paths - treated as
//       terminal free of the heap packet (may imply missing explicit return in
//       decompile). CF order preserved from raw.
//
// Related: Inventory_SerializeAddItemPacket, InventoryGrid_PlaceItemFootprint
// Exactness: CF mirrors raw. Bit-for-bit / runtime / diff: DEFERRED.
// Dual reviews: pending (SerializeAddItemPacket already dual-reviewed).
// =============================================================================

#include <cstdint>

void* operator_new(std::uint32_t size);
void  operator_delete(void* p);
char  Inventory_SerializeAddItemPacket(void* packet, int* item, int* iterOut);
// Note: thiscall this = host is implicit at call site from ECX.
void  Client_SendLogicUiPacket(void* buf);
char  FUN_00571620(int* item, std::uint8_t x, std::uint8_t y, std::uint32_t qty);
void* FUN_00404c90();
void  FUN_004d2820(int* item, void* rectOrMsg, int a, int b);
void  FUN_00571830(std::uint32_t a, std::uint32_t x, std::uint32_t y);
void  FUN_004d4790(int* item);
char  FUN_00570710();
void  FUN_007a4480(std::uint32_t level, const char* fmt, ...);

extern std::uint32_t DAT_00b045a0;
extern std::uint32_t DAT_00b045a4;
extern std::uint32_t DAT_00b045a8;
extern std::uint32_t DAT_00b045ac;

/// @param pHost          Character / inventory host (this).
/// @param pItem          Item object (COID at +0x160/+0x164).
/// @param mergeContext   Forwarded to FUN_00571830 on merge path.
void __thiscall Client_SendInventoryAddItem(
    int pHost,
    int* pItem,
    std::uint32_t mergeContext)
{
    int* piVar1;
    char cVar2;
    std::uint32_t* puPacket;
    std::uint32_t uVar4;
    int iVar5;
    std::uint32_t* puVar6;
    std::uint32_t uStack_160;
    std::uint32_t uStack_15c;
    std::uint32_t uStack_158;
    std::uint32_t uStack_154;
    std::uint32_t local_150;
    int local_14c;               // stack-match / iter out for Serialize
    std::uint8_t local_148[28];  // LogicUi packet scratch
    std::uint32_t local_12c;
    int local_128;
    int local_124;

    // Clear item flag bit 2 (0x4) at dword [0x5f] / +0x17c
    pItem[0x5f] = pItem[0x5f] & 0xfffffffb;

    puPacket = reinterpret_cast<std::uint32_t*>(operator_new(0x20));
    *puPacket = 0;
    puPacket[1] = 0;
    puPacket[2] = 0;
    puPacket[3] = 0;
    puPacket[4] = 0;
    puPacket[5] = 0;
    puPacket[6] = 0;
    puPacket[7] = 0;
    *puPacket = 0x2047; // InventoryAddItem opcode

    // thiscall: ECX = pHost (vehicle/character with cargo at path involving +0x2b0)
    cVar2 = Inventory_SerializeAddItemPacket(puPacket, pItem, &local_14c);
    if (cVar2 == '\0') {
        /* WARNING: Subroutine does not return (Ghidra) */
        operator_delete(puPacket);
    }

    // Type-4 special: optional LogicUi notify with COID + code 0xc
    if (*reinterpret_cast<int*>(pItem[0x2a] + 0x38) == 4) {
        local_128 = pItem[0x58];
        local_124 = pItem[0x59];
        local_12c = 0xc;
        if (*reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(pHost + 4) + 4)
                + 0xa8 + pHost)
            != 0) {
            Client_SendLogicUiPacket(local_148);
        }
    }

    if (*reinterpret_cast<char*>(reinterpret_cast<std::uintptr_t>(puPacket) + 0x12)
        == '\0') {
        // --- New-slot place path (addToExisting == 0) ---
        *reinterpret_cast<std::uint8_t*>(
            reinterpret_cast<std::uintptr_t>(puPacket) + 0x12) = 0;
        local_150 = *reinterpret_cast<std::uint32_t*>(
            *reinterpret_cast<int*>(pHost + 0x250) + 0x2b0);
        uVar4 = (**(std::uint32_t(**)())(*pItem + 0x25c))(); // quantity
        cVar2 = FUN_00571620(
            pItem,
            *reinterpret_cast<std::uint8_t*>(puPacket + 4),       // X at +0x10
            *reinterpret_cast<std::uint8_t*>(
                reinterpret_cast<std::uintptr_t>(puPacket) + 0x11), // Y
            uVar4);
        if (cVar2 == '\0') {
            // Place failed - optional world-drop / error path
            uStack_160 = DAT_00b045a0;
            uStack_15c = DAT_00b045a4;
            uStack_158 = DAT_00b045a8;
            uStack_154 = DAT_00b045ac;
            if ((*reinterpret_cast<char*>(pHost + 0x6b9) != '\0')
                && ((piVar1 = *reinterpret_cast<int**>(
                                   *reinterpret_cast<int*>(
                                       *reinterpret_cast<int*>(pHost + 4) + 4)
                                   + 0xa4 + pHost),
                     piVar1 == nullptr
                         || (iVar5 = (**(int(**)())(*piVar1 + 0x1c8))(),
                             iVar5 == 0)))) {
                return;
            }
            puVar6 = reinterpret_cast<std::uint32_t*>(FUN_00404c90());
            uStack_160 = *puVar6;
            uStack_15c = puVar6[1];
            uStack_158 = puVar6[2];
            uStack_154 = puVar6[3];
            FUN_004d2820(pItem, &uStack_160, 0, 1);
        } else {
            // Place ok - bind item to vehicle cargo host
            iVar5 = *reinterpret_cast<int*>(pHost + 0x250);
            if (iVar5 == 0) {
                iVar5 = 0;
            } else {
                iVar5 = *reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(iVar5 + 4) + 4)
                        + 4 + iVar5;
            }
            (**(void(**)(int))(*pItem + 0x158))(iVar5);
        }
        (**(void(**)())(*pItem + 0xb4))();
        /* WARNING: Subroutine does not return (Ghidra) */
        operator_delete(puPacket);
    }

    // --- Stack-merge path (addToExisting != 0) ---
    FUN_00571830(
        mergeContext,
        *reinterpret_cast<std::uint32_t*>(local_14c + 0x160),
        *reinterpret_cast<std::uint32_t*>(local_14c + 0x164));
    FUN_004d4790(pItem);
    cVar2 = FUN_00570710();
    if (cVar2 == '\0') {
        iVar5 = *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(pHost + 4) + 4);
        FUN_007a4480(
            1,
            "INVENTORY FAILURE for %I64d item:%I64d",
            *reinterpret_cast<std::uint32_t*>(iVar5 + 0x164 + pHost),
            *reinterpret_cast<std::uint32_t*>(iVar5 + 0x168 + pHost),
            pItem[0x58],
            pItem[0x59]);
    }
    /* WARNING: Subroutine does not return (Ghidra) */
    operator_delete(puPacket);
}
