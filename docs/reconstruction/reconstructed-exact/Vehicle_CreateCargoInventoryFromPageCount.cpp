// =============================================================================
// Vehicle_CreateCargoInventoryFromPageCount
// -----------------------------------------------------------------------------
// Purpose:  Destroy any prior cargo InventoryGrid at vehicle+0x2b0, then (unless
//           special-flag at +0x2ac is set) allocate a fresh grid:
//             width  = 6
//             height = nPages * 13
//             pages  = nPages   (chassis InventorySlots — pages, NOT total cells)
//           Bind owner TFID / character into the grid via vfuncs +0x18 / +0x14.
//
// Address:  0x004f3a30  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f3a30
// System:   inventory-transfer
//
// Convention: MSVC __thiscall
//
// Example: Callisto X InventorySlots=1 → 6×13 = 78 cells.
// AutoCore: VehicleCargoCapacity, InventoryPacketFactory page wire.
//
// Related:  InventoryGrid_ctor_Inferred, InventoryGrid_AllocateCellArray_Inferred,
//           docs/inventory-cargo-wire-re.md, docs/inventory-grid-footprint.md
// Exactness: Preserves SEH frame, destroy-then-null, and bind order.
// =============================================================================

#include <cstdint>

static constexpr std::uintptr_t kOffVehicleLink0     = 0x04;
static constexpr std::uintptr_t kOffSkipCargoCreate  = 0x2ac; // char; non-zero skips new grid
static constexpr std::uintptr_t kOffCargoGrid        = 0x2b0; // InventoryGrid*
static constexpr std::uintptr_t kOffEntityRelChar    = 0xa8;  // character/owner via link chain
static constexpr std::size_t    kInventoryGridBytes  = 0x68;
static constexpr std::int32_t   kCargoGridWidth      = 6;
static constexpr std::int32_t   kCargoRowsPerPage    = 0x0d;  // 13

// Vtable slots on InventoryGrid (byte offsets into vtable).
static constexpr std::uintptr_t kVgridSetOwnerObj    = 0x18;
static constexpr std::uintptr_t kVgridSetOwnerChar   = 0x14;

extern "C" void* LAB_009a2c75;
extern "C" void* ExceptionList;

void* operator_new(std::uint32_t nbytes);
void* InventoryGrid_ctor_Inferred(void* self, std::int32_t w, std::int32_t h, std::int32_t pages);
void  InventoryGrid_SetOwnerFlag_Inferred(void* pGrid, std::int32_t flag);

struct VehicleEntity;

/// Rebuild vehicle cargo inventory grid from chassis page count.
/// @param nPages  Chassis InventorySlots (pages).
void Vehicle_CreateCargoInventoryFromPageCount(VehicleEntity* self, std::int16_t nPages)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(self);

    // --- SEH frame ---
    std::uint32_t uStack_4 = 0xFFFFFFFFu;
    void*         puStack_8 = &LAB_009a2c75;
    void*         pvStack_c = ExceptionList;
    ExceptionList = &pvStack_c;
    (void)puStack_8;

    // Destroy existing cargo grid (scalar deleting dtor via vtable[0](1)).
    auto** ppGrid = reinterpret_cast<void**>(base + kOffCargoGrid);
    if (*ppGrid != nullptr) {
        ExceptionList = &pvStack_c;
        auto* vtable = *reinterpret_cast<void***>(*ppGrid);
        using DtorFn = void(__thiscall*)(void*, std::int32_t);
        reinterpret_cast<DtorFn>(vtable[0])(*ppGrid, 1);
    }
    *reinterpret_cast<std::uint32_t*>(base + kOffCargoGrid) = 0;

    // Special vehicles skip cargo grid creation entirely.
    if (*reinterpret_cast<char*>(base + kOffSkipCargoCreate) == '\0') {
        void* pNewGridMem = operator_new(static_cast<std::uint32_t>(kInventoryGridBytes));

        // SEH state: constructing
        uStack_4 = 0;

        if (pNewGridMem == nullptr) {
            pNewGridMem = nullptr;
        } else {
            // width=6, height=nPages*13, pages=nPages
            pNewGridMem = InventoryGrid_ctor_Inferred(
                pNewGridMem,
                kCargoGridWidth,
                static_cast<std::int32_t>(nPages) * kCargoRowsPerPage,
                static_cast<std::int32_t>(nPages));
        }

        uStack_4 = 0xFFFFFFFFu;
        *reinterpret_cast<void**>(base + kOffCargoGrid) = pNewGridMem;

        InventoryGrid_SetOwnerFlag_Inferred(pNewGridMem, 1);

        // Bind owner object: *( *(this+4) + 4 ) + 4 + this  (entity self-view)
        void* pGrid = *reinterpret_cast<void**>(base + kOffCargoGrid);
        auto* gridVt = *reinterpret_cast<void***>(pGrid);

        auto* link0 = *reinterpret_cast<std::uint8_t**>(base + kOffVehicleLink0);
        auto* link1 = *reinterpret_cast<std::uint8_t**>(link0 + 4);
        auto* ownerObj =
            reinterpret_cast<void*>(
                reinterpret_cast<std::uintptr_t>(link1) + 4 +
                reinterpret_cast<std::uintptr_t>(self));

        using SetOwnerObjFn = void(__thiscall*)(void*, void*);
        reinterpret_cast<SetOwnerObjFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(gridVt) + kVgridSetOwnerObj))(
            pGrid, ownerObj);

        // Bind character pointer from entity-relative slot +0xa8
        auto* ownerChar = *reinterpret_cast<void**>(
            reinterpret_cast<std::uint8_t*>(link1) +
            reinterpret_cast<std::uintptr_t>(self) + kOffEntityRelChar);

        using SetOwnerCharFn = void(__thiscall*)(void*, void*);
        reinterpret_cast<SetOwnerCharFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(gridVt) + kVgridSetOwnerChar))(
            pGrid, ownerChar);
    }

    ExceptionList = pvStack_c;
}
