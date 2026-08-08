// =============================================================================
// CVOGCharacter_TryType1aCraft_Inferred  (was FUN_005316c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005316c0
// Address:   0x005316c0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Dual:      WQ8R-B 2026-08-04 (A/B + read_memory ECX seal)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-level thiscall
//            grid assignment. Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Character method: multi-ingredient craft for type-0x1a recipe objects.
//   Counts craftable batches via FUN_00522060 (mode-aware), probes cargo free
//   footprint, consumes primary bank (blob+0x4d0 cost +0x4d4) and/or secondary
//   CBID list (blob+0x498..+0x4a8, up to 5 slots), grants product CBID at
//   blob+0x04 for total output batches.
//
// ABI: MSVC __thiscall, ret 12
//   ECX     CVOGCharacter* self
//   stack0  recipe/object*
//   stack1  int craftQty  (must be > 0)
//   stack2  int/char mode — 1 skips primary bank; 2 skips secondary list
// Returns: 1 success or soft no-op (no materials); 0 hard fail.
// =============================================================================

#include <cstdint>

extern int  __thiscall InventoryGrid_CountItemsByCbid(void* grid, int cbid, int includeBroken);
extern int  __thiscall InventoryGrid_FindFreeSlot(void* grid, std::uint8_t sizeX, std::uint8_t sizeY,
                                                  std::uint8_t* outX, std::uint8_t* outY, int pageIndex);
extern int  __thiscall CVOGReaction_RemoveInventoryItem(void* grid, int cbid, int qty);
extern std::uint8_t __thiscall FUN_005310a0(void* characterOrCtx, int cbid, int qty);
// Count craftable batches under mode (param_5=0 → multi-ingredient banks)
extern bool __thiscall FUN_00522060(void* character, void* pObj, int* outAvailable,
                                    int mode, int simplePathFlag);
// Count non-(-1) CBIDs in blob+0x498..+0x4a8 (max 5)
extern int  __fastcall FUN_00599dd0(void* blob);
// Ensure object definition loaded when +0x3c null
extern int  __thiscall FUN_004f1e20(void* obj, int a, int b);

std::uint32_t __thiscall CVOGCharacter_TryType1aCraft_Inferred(
    void* self,
    void* pObj,
    int craftQty,
    int mode)
{
    if (pObj == nullptr) {
        return 0;
    }

    void* cargoHolder = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x250);
    if (cargoHolder == nullptr) {
        return 0;
    }
    void* cargo = *reinterpret_cast<void**>(reinterpret_cast<char*>(cargoHolder) + 0x2b0);
    if (cargo == nullptr) {
        return 0;
    }
    void* locker = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0xcbc);

    if (craftQty <= 0 || locker == nullptr) {
        return 0;
    }

    // Load definition if needed
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(pObj) + 0x3c) == nullptr) {
        FUN_004f1e20(pObj, 0, 1);
        if (*reinterpret_cast<void**>(reinterpret_cast<char*>(pObj) + 0x3c) == nullptr) {
            return 0;
        }
    }

    int available = 0;
    if (!FUN_00522060(self, pObj, &available, mode, 0)) {
        return 1; // soft success: nothing craftable
    }
    if (craftQty > available) {
        return 0;
    }

    std::uint8_t* blob = *reinterpret_cast<std::uint8_t**>(reinterpret_cast<char*>(pObj) + 0x3c);
    std::uint8_t originX = 0;
    std::uint8_t outYScratch = 0; // decompiler reuses a stack byte for outY / flags
    if (InventoryGrid_FindFreeSlot(cargo, blob[0x406], blob[0x407],
                                   &originX, &outYScratch, -1) == 0) {
        return 0;
    }

    int qtyPrimary = craftQty;
    int secondaryNeed = craftQty;
    int totalOut = 0;

    // Primary bank: skipped when mode == 1 or cost byte == 0
    if (static_cast<char>(mode) != 1 && *reinterpret_cast<char*>(blob + 0x4d4) > 0) {
        int primaryCbid = *reinterpret_cast<int*>(blob + 0x4d0);
        int cost = static_cast<int>(*reinterpret_cast<char*>(blob + 0x4d4));
        int have = InventoryGrid_CountItemsByCbid(cargo, primaryCbid, 0)
                 + InventoryGrid_CountItemsByCbid(locker, primaryCbid, 0);
        if (have < cost * craftQty) {
            qtyPrimary = have / cost;
            secondaryNeed = craftQty - qtyPrimary;
        } else {
            secondaryNeed = 0;
            qtyPrimary = craftQty;
        }
        int removeTotal = cost * qtyPrimary;
        int removed = CVOGReaction_RemoveInventoryItem(cargo, primaryCbid, removeTotal);
        int remain = removeTotal - removed;
        if (remain > 0) {
            CVOGReaction_RemoveInventoryItem(locker, primaryCbid, remain);
        }
        totalOut = qtyPrimary;
    } else {
        // Primary skipped: secondary carries full craftQty (decompiler iVar4 = qty)
        secondaryNeed = craftQty;
        totalOut = 0;
    }

    // Secondary list: skipped when mode == 2
    if (static_cast<char>(mode) != 2) {
        int nSlots = FUN_00599dd0(blob);
        if (nSlots > 0) {
            for (int i = 0; i < nSlots; ++i) {
                int cbid = *reinterpret_cast<int*>(blob + 0x498 + 4 * i);
                if (cbid == -1) {
                    continue;
                }
                int removed = CVOGReaction_RemoveInventoryItem(cargo, cbid, secondaryNeed);
                int remain = secondaryNeed - removed;
                if (remain > 0) {
                    CVOGReaction_RemoveInventoryItem(locker, cbid, remain);
                }
            }
            totalOut += secondaryNeed;
        }
    }

    int productCbid = *reinterpret_cast<int*>(blob + 4);
    FUN_005310a0(self, productCbid, totalOut);
    return 1;
}
