// =============================================================================
// Vehicle_SetEquippedRaceItem
// -----------------------------------------------------------------------------
// Purpose:  Set vehicle race-item hardpoint (this+0x270). Optional previous-out,
//           unbind old unless skip flag, type-check class 6 / subtype 0xb, bind
//           new via vfunc+0x158, post-attach vfunc+0x218, Vehicle_RecalcCombatPools.
//           Race item drives HP regen rate (CVOGHBRegeneration_OnHeartBeat).
//
// Address:  0x00502460  (autoassault.exe, image base 0x400000)
// Stable:   aa_00502460
// System:   inventory-transfer
//
// Convention: MSVC __thiscall (this = vehicle)
//
// Offsets (vehicle):
//   +0x270  void*  equipped race item
//
// Type gate:
//   clonebase+0x38 == 6 (simple/item class) AND
//   *( *(clonebase+0x3c) + 0x3f4 ) == 0xb (race-item subtype)
//
// Related: Vehicle_EquipPowerPlant, Vehicle_SetEquippedArmor, RecvInventoryEquip
// Exactness: CF mirrors raw. Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

void FUN_00512670();
void FUN_004fbb50(std::int32_t bindCtx);
void FUN_004fdcb0(std::int32_t bindCtx);
void FUN_007a4480(std::uint32_t level, const char* fmt, ...);
void Vehicle_RecalcCombatPools(void* vehicle);

/// @param thisVehicle     Vehicle
/// @param pRaceItem       New race item or null
/// @param ppOutPrevious   Optional prior item at +0x270
/// @param bSkipUnbind     Non-zero → skip unbind of previous
void __thiscall Vehicle_SetEquippedRaceItem(
    void* thisVehicle,
    void* pRaceItem,
    void** ppOutPrevious,
    char bSkipUnbind)
{
    int nCloneBase;

    FUN_00512670();

    if (ppOutPrevious != nullptr) {
        *ppOutPrevious = *reinterpret_cast<void**>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x270);
    }

    nCloneBase = *reinterpret_cast<int*>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x270);
    if (nCloneBase != 0) {
        if (bSkipUnbind == '\0') {
            FUN_004fbb50(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(nCloneBase + 4) + 4)
                + 4 + nCloneBase);
        }
        // vfunc+0x158(0) clear parent on previous race item
        (**(void(**)(std::int32_t))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(
                            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x270)
                        + 4)
                    + 4)
                + 4
                + *reinterpret_cast<int*>(
                      reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x270))
            + 0x158))(0);
    }

    *reinterpret_cast<void**>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x270) = pRaceItem;

    if (pRaceItem != nullptr) {
        nCloneBase = *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    reinterpret_cast<std::uintptr_t>(pRaceItem) + 4)
                + 4)
            + 0xac
            + reinterpret_cast<std::uintptr_t>(pRaceItem));

        if ((*reinterpret_cast<int*>(nCloneBase + 0x38) != 6)
            || (*reinterpret_cast<std::int16_t*>(
                    *reinterpret_cast<int*>(nCloneBase + 0x3c) + 0x3f4)
                != 0xb)) {
            nCloneBase = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    reinterpret_cast<std::uintptr_t>(pRaceItem) + 4)
                + 4);
            FUN_007a4480(
                1,
                "Set race item of unhappy type: CBID:%d COID:%I64d",
                *reinterpret_cast<std::uint32_t*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(pRaceItem)
                        + nCloneBase + 0xac)
                    + 0x34),
                *reinterpret_cast<std::uint32_t*>(
                    reinterpret_cast<std::uintptr_t>(pRaceItem)
                    + nCloneBase + 0x164),
                *reinterpret_cast<std::uint32_t*>(
                    nCloneBase + 0x168
                    + reinterpret_cast<std::uintptr_t>(pRaceItem)));
        }

        // Bind to vehicle
        (**(void(**)(std::int32_t))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(pRaceItem) + 4)
                    + 4)
                + 4
                + reinterpret_cast<std::uintptr_t>(pRaceItem))
            + 0x158))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    reinterpret_cast<std::uintptr_t>(thisVehicle) + 4)
                + 4)
            + 4
            + static_cast<int>(reinterpret_cast<std::uintptr_t>(thisVehicle)));

        nCloneBase = *reinterpret_cast<int*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x270);
        if (nCloneBase != 0) {
            nCloneBase =
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(nCloneBase + 4) + 4)
                + 4 + nCloneBase;
        }
        FUN_004fdcb0(nCloneBase);

        // vfunc+0x218(vehicle link+0xa8)
        (**(void(**)(std::uint32_t))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(pRaceItem) + 4)
                    + 4)
                + 4
                + reinterpret_cast<std::uintptr_t>(pRaceItem))
            + 0x218))(
            *reinterpret_cast<std::uint32_t*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(thisVehicle) + 4)
                    + 4)
                + 0xa8
                + reinterpret_cast<std::uintptr_t>(thisVehicle)));
    }

    Vehicle_RecalcCombatPools(thisVehicle);
}
