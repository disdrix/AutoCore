// =============================================================================
// Vehicle_EquipPowerPlant
// -----------------------------------------------------------------------------
// Purpose:  Swap the vehicle PowerPlant hardpoint (this+0x268). Captures previous
//           plant into optional out-param, unbinds old (unless keep flag), attaches
//           new plant, copies plant TFID to vehicle+0x620/+0x624, recalculates
//           MaxHeat into vehicle+0x244 via Vehicle_CalcHeatMaximum.
//
// Address:  0x004fe1b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004fe1b0
// System:   inventory-transfer
//
// Convention: MSVC __thiscall (this = vehicle)
//
// Callers:
//   Client_RecvInventoryEquip        0x00813f40  (obj class 10)
//   Client_RecvInventoryUnequipNotify 0x00813bf0 (clear with null plant)
//   Vehicle_EquipFromCreate          0x00504480
//
// Offsets (vehicle):
//   +0x268  void*  current power plant
//   +0x244  int    MaxHeat (from Vehicle_CalcHeatMaximum)
//   +0x620  u32    equipped plant COID lo
//   +0x624  u32    equipped plant COID hi
//
// Object layout used:
//   item link chain *( *(item+4) + 4 ) + item + 0xac → clonebase*
//   clonebase+0x38 == 10 expected type (power plant)
//   clonebase+0x34 CBID (log only)
//   object COID at link_adj+0x164 / +0x168
//   vfunc +0x158 attach/bind (0 = clear parent; vehicle bind ctx = attach)
//   vfunc +0x218 post-attach (arg = vehicle link+0xa8)
//   owner notify: vehicle+0xb0 → vfunc+0x1dc → char → vfunc+0x5c
//
// Exactness: Behavior-preserving rewrite of decompiler CF. Not modernization.
//            Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

// Unresolved callees preserved from raw
void FUN_007a4480(std::uint32_t level, const char* fmt, ...);
void FUN_00512670();
void FUN_004fbb50(std::int32_t bindCtx);
void FUN_004fdcb0(std::int32_t bindCtx);
int  Vehicle_CalcHeatMaximum(void* vehicle);

/// @param this              Vehicle
/// @param pNewPowerPlant    New plant object or null (clear)
/// @param ppOutPrevious     Optional; receives prior plant at +0x268
/// @param bKeepPreviousAttached  If true, skip FUN_004fbb50 on previous
void __thiscall Vehicle_EquipPowerPlant(
    void* thisVehicle,
    void* pNewPowerPlant,
    void** ppOutPrevious,
    bool bKeepPreviousAttached)
{
    int iVar1;
    int* piVar2;
    int iVar3;
    int iVar4;

    // Already equipped with same non-null plant → log CBID and bail
    if ((pNewPowerPlant == *reinterpret_cast<void**>(
             reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268))
        && (pNewPowerPlant != nullptr)) {
        FUN_007a4480(
            0,
            "Tried to equip same powerplant %d",
            *reinterpret_cast<std::uint32_t*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(
                            reinterpret_cast<std::uintptr_t>(pNewPowerPlant) + 4)
                        + 4)
                    + 0xac
                    + reinterpret_cast<std::uintptr_t>(pNewPowerPlant))
                + 0x34));
        return;
    }

    FUN_00512670();

    if (ppOutPrevious != nullptr) {
        *ppOutPrevious = *reinterpret_cast<void**>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268);
    }

    // Unbind previous plant
    iVar4 = *reinterpret_cast<int*>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268);
    if (iVar4 != 0) {
        if (!bKeepPreviousAttached) {
            // bindCtx = *( *(prev+4) + 4 ) + 4 + prev
            FUN_004fbb50(
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar4 + 4) + 4)
                + 4 + iVar4);
        }
        // vfunc+0x158(0) on previous plant bind surface
        (**(void(**)(std::int32_t))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(
                            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268)
                        + 4)
                    + 4)
                + 4
                + *reinterpret_cast<int*>(
                      reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268))
            + 0x158))(0);
    }

    // Install new pointer
    *reinterpret_cast<void**>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268) = pNewPowerPlant;

    // Owner character notify (if vehicle has owner link at +0xb0)
    piVar2 = *reinterpret_cast<int**>(
        *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                reinterpret_cast<std::uintptr_t>(thisVehicle) + 4)
            + 4)
        + 0xb0
        + reinterpret_cast<std::uintptr_t>(thisVehicle));
    if (piVar2 != nullptr) {
        piVar2 = reinterpret_cast<int*>(
            (**(std::int32_t*(**)())(*piVar2 + 0x1dc))());
        if (piVar2 != nullptr) {
            (**(void(**)())(*piVar2 + 0x5c))();
        }
    }

    if (pNewPowerPlant != nullptr) {
        iVar4 = *reinterpret_cast<int*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268);

        // Type gate: clonebase+0x38 must be 10
        if (*reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(iVar4 + 4) + 4)
                    + 0xac
                    + iVar4)
                + 0x38)
            != 10) {
            iVar1 = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(iVar4 + 4) + 4);
            iVar3 = iVar4 + iVar1;
            FUN_007a4480(
                1,
                "Set powerplant of unhappy type: CBID:%d COID:%I64d",
                *reinterpret_cast<std::uint32_t*>(
                    *reinterpret_cast<int*>(iVar3 + 0xac) + 0x34),
                *reinterpret_cast<std::uint32_t*>(iVar3 + 0x164),
                *reinterpret_cast<std::uint32_t*>(iVar4 + 0x168 + iVar1));
        }

        // Plant TFID → vehicle+0x620 / +0x624
        iVar4 = *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                reinterpret_cast<std::uintptr_t>(pNewPowerPlant) + 4)
            + 4);
        *reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x620) =
            *reinterpret_cast<std::uint32_t*>(
                iVar4 + 0x164 + reinterpret_cast<std::uintptr_t>(pNewPowerPlant));
        *reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x624) =
            *reinterpret_cast<std::uint32_t*>(
                iVar4 + 0x168 + reinterpret_cast<std::uintptr_t>(pNewPowerPlant));

        // vfunc+0x158(vehicle bind ctx)
        (**(void(**)(std::int32_t))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(
                            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268)
                        + 4)
                    + 4)
                + 4
                + *reinterpret_cast<int*>(
                      reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268))
            + 0x158))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    reinterpret_cast<std::uintptr_t>(thisVehicle) + 4)
                + 4)
            + 4
            + static_cast<int>(reinterpret_cast<std::uintptr_t>(thisVehicle)));

        iVar4 = *reinterpret_cast<int*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268);
        if (iVar4 != 0) {
            iVar4 = *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(iVar4 + 4) + 4)
                    + 4 + iVar4;
        }
        FUN_004fdcb0(iVar4);

        // vfunc+0x218(vehicle field via link+0xa8)
        (**(void(**)(std::uint32_t))(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(
                            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268)
                        + 4)
                    + 4)
                + 4
                + *reinterpret_cast<int*>(
                      reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x268))
            + 0x218))(
            *reinterpret_cast<std::uint32_t*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(thisVehicle) + 4)
                    + 4)
                + 0xa8
                + reinterpret_cast<std::uintptr_t>(thisVehicle)));

        iVar4 = Vehicle_CalcHeatMaximum(thisVehicle);
        *reinterpret_cast<int*>(
            reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x244) = iVar4;
        return;
    }

    // Clear: sentinel TFID + recalc heat
    *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x620) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x624) = 0xFFFFFFFFu;
    iVar4 = Vehicle_CalcHeatMaximum(thisVehicle);
    *reinterpret_cast<int*>(
        reinterpret_cast<std::uintptr_t>(thisVehicle) + 0x244) = iVar4;
}
