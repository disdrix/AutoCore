// =============================================================================
// Inventory_SerializeAddItemPacket
// -----------------------------------------------------------------------------
// Purpose:  Fill an InventoryAddItem packet (opcode 0x2047, size 0x20) for an
//           item being placed into cargo. Sets wasAdded (+0x18), addToExisting
//           (+0x12), item COID at +0x08/+0x0c, and slot X/Y at +0x10/+0x11.
//           Two paths: free-slot place (addToExisting=0) or stack-merge onto an
//           existing same-CBID item (addToExisting=1, X/Y cleared).
//
// Address:  0x004fadb0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004fadb0
// System:   inventory-transfer
//
// Convention: MSVC __thiscall
//   this / pVehicle   vehicle (cargo inventory pointer at +0x2b0 must be non-null)
//   pPacket           0x20-byte AddItem buffer (opcode already written by caller)
//   pItem             item object being added
//   pIterOut          iterator / match out used by stack-scan path
//
// Packet layout written (matches Documentation/PACKET STRUCTURES.md 0x2047):
//   +0x08  u32/u32  item COID lo/hi  (from item dword indices [0x58]/[0x59]
//                   = byte offsets +0x160/+0x164 — NOT grid X/Y)
//   +0x10  u8       cargo X          (from FindFreeSlot FUN_005714e0, or 0 on merge)
//   +0x11  u8       cargo Y
//   +0x12  u8       bAddToExistingItem
//   +0x18  u8       bWasSuccessful / wasAdded
//
// Note: Older plate text saying packet+8 = grid X is WRONG; free-slot and merge
//       paths both write COID halves to +8/+0xc. X/Y live at +0x10/+0x11.
//
// Stack-merge path:
//   FUN_00513e70() non-zero → scan inventory with FUN_004022a0
//   Match: same CBID (clonebase+0x34), both flag bit 0x13 clear at +0x17c
//   Quantity-compatible via item vfunc+0x25c + FUN_0040abf0
//   On match: wasAdded=1, addToExisting=1, X=Y=0, COID from matched obj +0x160/+0x164
//
// Free-slot path (no stack or scan miss):
//   type==4 OR FUN_005714e0(item, &pkt.X, &pkt.Y, 1, -1) succeeds
//   → wasAdded=1, addToExisting=0, COID from item[0x58]/[0x59]
//
// Returns: 1 if packet filled (wasAdded), 0 if cargo missing or no slot/merge.
// Exactness: CF mirrors raw. Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h> // LeaveCriticalSection

// Unresolved helpers
char FUN_00513e70(); // stack-eligible / merge-mode probe
char FUN_005714e0(int* item, void* outX, void* outY, int a, unsigned banMask);
void FUN_004294f0();
int  FUN_004022a0(void* iterState, int** outItem);
char FUN_0040abf0(std::uint32_t qtyOrKey);

/// @return 1 if packet fields filled and wasAdded set; else 0
char __thiscall Inventory_SerializeAddItemPacket(
    int pVehicle,     // this: vehicle / inventory host (+0x2b0 = cargo grid)
    int pPacket,      // AddItem packet body
    int* pItem,       // item being added
    int* pIterOut)    // stack-scan iterator out / match holder
{
    char cWasFilled;
    int* piItem;
    int* piMatch;
    char cOk;
    int iTmp;
    std::uint32_t uQty;

    piItem = pItem;
    *reinterpret_cast<std::uint8_t*>(pPacket + 0x18) = 0; // wasAdded = 0

    // No cargo inventory → fail
    if (*reinterpret_cast<int*>(pVehicle + 0x2b0) == 0) {
        return '\0';
    }

    cWasFilled = '\0';
    cOk = FUN_00513e70();

    if (cOk == '\0') {
        // --- Free-slot path (no stack merge) ---
        // type 4 always accepted; else FindFreeSlot writes X/Y at packet+0x10/0x11
        if ((*reinterpret_cast<int*>(piItem[0x2a] + 0x38) == 4)
            || (cOk = FUN_005714e0(
                         piItem,
                         reinterpret_cast<void*>(pPacket + 0x10),
                         reinterpret_cast<void*>(pPacket + 0x11),
                         1,
                         0xFFFFFFFFu),
                cOk != '\0')) {
            *reinterpret_cast<std::uint8_t*>(pPacket + 0x18) = 1; // wasAdded
            *reinterpret_cast<std::uint8_t*>(pPacket + 0x12) = 0; // addToExisting
            // item dword [0x58]/[0x59] = COID lo/hi at +0x160/+0x164
            *reinterpret_cast<int*>(pPacket + 8) = piItem[0x58];
            *reinterpret_cast<int*>(pPacket + 0xc) = piItem[0x59];
            cWasFilled = '\x01';
        }
    } else {
        // --- Stack-merge scan path ---
        pItem = nullptr; // reused as scan cursor seed
        FUN_004294f0();
        piMatch = pIterOut;
        iTmp = FUN_004022a0(&pItem, pIterOut);

        while (iTmp == 0) {
            iTmp = *piMatch;
            // Same CBID, neither has flag bit 19 (0x80000) at +0x17c
            if ((((iTmp != 0)
                  && (*reinterpret_cast<int*>(
                          *reinterpret_cast<int*>(iTmp + 0xa8) + 0x34)
                      == *reinterpret_cast<int*>(piItem[0x2a] + 0x34)))
                 && (((*reinterpret_cast<unsigned*>(iTmp + 0x17c) >> 0x13) & 1)
                     == 0))
                && (((static_cast<unsigned>(piItem[0x5f]) >> 0x13) & 1) == 0)) {
                // Quantity / stack-key from vfunc+0x25c
                uQty = (**(std::uint32_t(**)())(*piItem + 0x25c))();
                cOk = FUN_0040abf0(uQty);
                if (cOk != '\0') {
                    *reinterpret_cast<std::uint8_t*>(pPacket + 0x18) = 1;
                    *reinterpret_cast<std::uint8_t*>(pPacket + 0x12) = 1; // merge
                    *reinterpret_cast<std::uint8_t*>(pPacket + 0x10) = 0;
                    *reinterpret_cast<std::uint8_t*>(pPacket + 0x11) = 0;
                    iTmp = *piMatch;
                    *reinterpret_cast<std::uint32_t*>(pPacket + 8) =
                        *reinterpret_cast<std::uint32_t*>(iTmp + 0x160);
                    cWasFilled = '\x01';
                    *reinterpret_cast<std::uint32_t*>(pPacket + 0xc) =
                        *reinterpret_cast<std::uint32_t*>(iTmp + 0x164);
                    break;
                }
            }
            iTmp = FUN_004022a0(&pItem, piMatch);
        }

        // Release cargo critical section if held
        iTmp = *reinterpret_cast<int*>(pVehicle + 0x2b0);
        if (*reinterpret_cast<char*>(iTmp + 0x54) != '\0') {
            *reinterpret_cast<std::uint8_t*>(iTmp + 0x54) = 0;
            LeaveCriticalSection(
                reinterpret_cast<LPCRITICAL_SECTION>(iTmp + 0x30));
        }

        // Scan miss → fall back to free-slot fill
        if ((cWasFilled == '\0')
            && ((*reinterpret_cast<int*>(piItem[0x2a] + 0x38) == 4
                 || (cOk = FUN_005714e0(
                              piItem,
                              reinterpret_cast<void*>(pPacket + 0x10),
                              reinterpret_cast<void*>(pPacket + 0x11),
                              1,
                              0xFFFFFFFFu),
                     cOk != '\0')))) {
            *reinterpret_cast<std::uint8_t*>(pPacket + 0x18) = 1;
            *reinterpret_cast<std::uint8_t*>(pPacket + 0x12) = 0;
            *reinterpret_cast<int*>(pPacket + 8) = piItem[0x58];
            *reinterpret_cast<int*>(pPacket + 0xc) = piItem[0x59];
            return '\x01';
        }
    }

    return cWasFilled;
}
