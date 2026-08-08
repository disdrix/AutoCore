// =============================================================================
// CVOGCharacter_TryType1aSimpleExchange_Inferred  (was FUN_00531570)
// -----------------------------------------------------------------------------
// Stable ID: aa_00531570
// Address:   0x00531570  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Dual:      WQ8R-B 2026-08-04 (A/B + read_memory ECX seal)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-level thiscall
//            grid assignment. Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Character method: for a clone/object type **0x1a** "recipe" object, verify
//   dual-grid (cargo+locker) stock of a single ingredient CBID (blob+0x4c0),
//   ensure cargo has free footprint for the product, consume `qty` of the
//   ingredient across cargo then locker, and grant
//   `outCbid = object+0x34` with count `(u8)blob+0x4c9 * qty`.
//
// ABI: MSVC __thiscall, ret 8
//   ECX     CVOGCharacter* self
//   stack0  type-0x1a object* (requires +0x38==0x1a, +0x3c blob)
//   stack1  int requestQty
// Returns: 1 success, 0 fail.
//
// Grids (sealed via read_memory mov ecx):
//   cargo  = *(*(self+0x250)+0x2b0)
//   locker = *(self+0xcbc)
// =============================================================================

#include <cstdint>

// Dualed inventory callees
extern int  __thiscall InventoryGrid_CountItemsByCbid(void* grid, int cbid, int includeBroken);
extern int  __thiscall InventoryGrid_FindFreeSlot(void* grid, std::uint8_t sizeX, std::uint8_t sizeY,
                                                  std::uint8_t* outX, std::uint8_t* outY, int pageIndex);
extern int  __thiscall CVOGReaction_RemoveInventoryItem(void* grid, int cbid, int qty);
// Give helper: thiscall, ret 8 — (ctx, cbid, qty); loops until qty granted or fail
extern std::uint8_t __thiscall FUN_005310a0(void* characterOrCtx, int cbid, int qty);

std::uint32_t __thiscall CVOGCharacter_TryType1aSimpleExchange_Inferred(
    void* self,
    void* pObj,
    int requestQty)
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
    if (locker == nullptr) {
        return 0;
    }

    // Type gate: object+0x38 == 0x1a
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(pObj) + 0x38) != 0x1a) {
        return 0;
    }
    std::uint8_t* blob = *reinterpret_cast<std::uint8_t**>(reinterpret_cast<char*>(pObj) + 0x3c);
    if (blob == nullptr) {
        return 0;
    }

    int ingredientCbid = *reinterpret_cast<int*>(blob + 0x4c0);
    int haveCargo  = InventoryGrid_CountItemsByCbid(cargo,  ingredientCbid, 0);
    int haveLocker = InventoryGrid_CountItemsByCbid(locker, ingredientCbid, 0);
    if (requestQty > haveCargo + haveLocker) {
        return 0;
    }

    int outCount = static_cast<int>(blob[0x4c9]) * requestQty;
    int outCbid  = *reinterpret_cast<int*>(reinterpret_cast<char*>(pObj) + 0x34);
    if (outCount <= 0 || outCbid == -1) {
        return 0;
    }

    std::uint8_t originX = 0;
    std::uint8_t originY = 0;
    // Space check on cargo; InvSize from blob; whole-grid pageIndex = -1
    if (InventoryGrid_FindFreeSlot(cargo, blob[0x406], blob[0x407],
                                   &originX, &originY, -1) == 0) {
        return 0;
    }

    int removed = CVOGReaction_RemoveInventoryItem(cargo, ingredientCbid, requestQty);
    int remain  = requestQty - removed;
    if (remain > 0) {
        CVOGReaction_RemoveInventoryItem(locker, ingredientCbid, remain);
    }

    FUN_005310a0(self, outCbid, outCount);
    return 1;
}
