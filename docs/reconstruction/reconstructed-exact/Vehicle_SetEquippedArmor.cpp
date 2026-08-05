// =============================================================================
// Vehicle_SetEquippedArmor
// -----------------------------------------------------------------------------
// Purpose:  Set vehicle armor hardpoint (this+0x254). Optionally unbind previous
//           armor, store new item, type-check clonebase+0x38 == 0x1c, bind via
//           vfunc+0x158, then Vehicle_RecalcCombatPools (HP uses ArmorFactor).
//
// Address:  0x00502090  (autoassault.exe, image base 0x400000)
// Stable:   aa_00502090
// System:   inventory-transfer
//
// Convention: MSVC __thiscall (this = vehicle)
//
// Offsets (vehicle):
//   +0x254  void*  equipped armor item
//
// Object layout:
//   clonebase via *( *(item+4)+4 ) + item + 0xac; type at clonebase+0x38
//   Expected type 0x1c (armor). Unhappy type logs CBID + COID only.
//   vfunc +0x158(vehicle bind ctx) attaches armor to vehicle.
//   FUN_004fbb50 unbind previous; FUN_004fdcb0 post-attach.
//
// Related: Vehicle_EquipPowerPlant (+0x268), Vehicle_SetEquippedRaceItem (+0x270)
// Exactness: CF mirrors raw. Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

void FUN_00512670();
void FUN_004fbb50(std::int32_t bindCtx);
void FUN_004fdcb0(std::int32_t bindCtx);
void FUN_007a4480(std::uint32_t level, const char* fmt, ...);
void Vehicle_RecalcCombatPools(void* vehicle);

/// @param thisVehicle   Vehicle
/// @param pArmorItem    New armor object or null
/// @param bSkipUnbind   Non-zero → skip FUN_004fbb50 on previous armor
void __thiscall Vehicle_SetEquippedArmor(
    void* thisVehicle,
    void* pArmorItem,
    char bSkipUnbind)
{
    int pPrevOrBindCtx;

    FUN_00512670();

    if (bSkipUnbind == '\0') {
        pPrevOrBindCtx = *reinterpret_cast<int*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x254);
        if (pPrevOrBindCtx != 0) {
            pPrevOrBindCtx =
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(pPrevOrBindCtx + 4) + 4)
                + 4 + pPrevOrBindCtx;
        }
        FUN_004fbb50(pPrevOrBindCtx);
    }

    *reinterpret_cast<void**>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x254) = pArmorItem;

    if (pArmorItem != nullptr) {
        // Expect clonebase type 0x1c
        if (*reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(
                            reinterpret_cast<std::uintptr_t>(pArmorItem) + 4)
                        + 4)
                    + 0xac
                    + reinterpret_cast<std::uintptr_t>(pArmorItem))
                + 0x38)
            != 0x1c) {
            pPrevOrBindCtx = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    reinterpret_cast<std::uintptr_t>(pArmorItem) + 4)
                + 4);
            FUN_007a4480(
                1,
                "Set armor of unhappy type: CBID:%d COID:%I64d",
                *reinterpret_cast<std::uint32_t*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(pArmorItem)
                        + pPrevOrBindCtx + 0xac)
                    + 0x34),
                *reinterpret_cast<std::uint32_t*>(
                    pPrevOrBindCtx + 0x164
                    + reinterpret_cast<std::uintptr_t>(pArmorItem)),
                *reinterpret_cast<std::uint32_t*>(
                    pPrevOrBindCtx + 0x168
                    + reinterpret_cast<std::uintptr_t>(pArmorItem)));
        }

        // vfunc+0x158(vehicle bind ctx)
        (**(void(**)(std::int32_t))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(pArmorItem) + 4)
                    + 4)
                + 4
                + reinterpret_cast<std::uintptr_t>(pArmorItem))
            + 0x158))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    reinterpret_cast<std::uintptr_t>(thisVehicle) + 4)
                + 4)
            + 4
            + static_cast<int>(reinterpret_cast<std::uintptr_t>(thisVehicle)));

        pPrevOrBindCtx = *reinterpret_cast<int*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x254);
        if (pPrevOrBindCtx == 0) {
            FUN_004fdcb0(0);
            Vehicle_RecalcCombatPools(thisVehicle);
            return;
        }
        FUN_004fdcb0(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(pPrevOrBindCtx + 4) + 4)
            + 4 + pPrevOrBindCtx);
    }

    Vehicle_RecalcCombatPools(thisVehicle);
}
