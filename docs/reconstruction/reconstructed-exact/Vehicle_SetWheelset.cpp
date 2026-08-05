// =============================================================================
// Vehicle_SetWheelset
// -----------------------------------------------------------------------------
// Purpose:  Attach (or clear) the vehicle wheelset object at vehicle+0x258
//           (decimal 600). Validates clonebase type == 0x10 (Wheelset).
//           Called from Vehicle_EquipFromCreate and InventoryEquip (0x203C).
//
// Address:  0x004fea90  (autoassault.exe, image base 0x400000)
// Stable:   aa_004fea90
// System:   inventory-transfer / vehicle equip
//
// Convention: MSVC __thiscall  (this = vehicle; arg = wheelset object or null)
// Returns:    void
//
// On non-null wheelset:
//   1. FUN_00512670()  — pre-attach teardown / cache clear (INFERRED)
//   2. store pWheelset at this+0x258
//   3. if type at clonebase+0x38 != 0x10 → log "unhappy type" with CBID/COID
//   4. wheelset vfunc+0x158(vehicleBase)  — bind owner
//   5. FUN_004fdcb0(wheelsetBase)         — wheel graphics / contact setup
//   6. wheelset vfunc+0x218(sectorMap)    — world/sector notify
//   7. for i in [0, wheelCount@wheelset+0xb0):
//        FUN_005a6e00(i) → wheel object; vfunc+0x1c(scale)
//        scale = chassis float table[+0x600 + i]*g_flLevelUpUiBase_Inferred
//
// See also: docs/nullWheels.md, PATH_A_DEBUGGER.md (historical notes).
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Human-refined: 2026-07-23 (priority_013)
// =============================================================================

#include <cstdint>

extern "C" void FUN_00512670();
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void FUN_004fdcb0(int pWheelsetBase);
extern "C" int  FUN_005a6e00(std::uint32_t wheelIndex);

// Scale constant used when applying per-wheel radius / visual scale.
extern float g_flLevelUpUiBase_Inferred;

/// @param thisVehicle  Vehicle object (this).
/// @param pWheelset    Wheelset SimpleObject* or null to clear slot.
void __thiscall Vehicle_SetWheelset(int thisVehicle, int pWheelset)
{
    FUN_00512670();
    *reinterpret_cast<int*>(thisVehicle + 600) = pWheelset; // +0x258

    if (pWheelset == 0) {
        return;
    }

    // type = *(clonebase + 0x38); clonebase via MI +0xac
    int nMi = *reinterpret_cast<int*>(*reinterpret_cast<int*>(pWheelset + 4) + 4);
    int nType = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(nMi + 0xac + pWheelset) + 0x38);
    if (nType != 0x10) {
        int nBase = pWheelset + nMi;
        FUN_007a4480(
            1,
            "Set wheelset1 of unhappy type: CBID:%d COID:%I64d",
            *reinterpret_cast<std::uint32_t*>(
                *reinterpret_cast<int*>(nBase + 0xac) + 0x34),
            *reinterpret_cast<std::uint32_t*>(nBase + 0x164),
            *reinterpret_cast<std::uint32_t*>(pWheelset + 0x168 + nMi));
    }

    // Bind wheelset to vehicle base (vfunc +0x158)
    int pWs = *reinterpret_cast<int*>(thisVehicle + 600);
    int nWsMi = *reinterpret_cast<int*>(*reinterpret_cast<int*>(pWs + 4) + 4);
    int pWsVtable = *reinterpret_cast<int*>(nWsMi + 4 + pWs);
    (**(void(**)(int))(pWsVtable + 0x158))(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(thisVehicle + 4) + 4) + 4 +
        thisVehicle);

    // Wheel contact / graphics helper
    pWs = *reinterpret_cast<int*>(thisVehicle + 600);
    int pWsBase = 0;
    if (pWs != 0) {
        pWsBase = *reinterpret_cast<int*>(*reinterpret_cast<int*>(pWs + 4) + 4) + 4 + pWs;
    }
    FUN_004fdcb0(pWsBase);

    // Sector-map notify (vfunc +0x218)
    pWs = *reinterpret_cast<int*>(thisVehicle + 600);
    nWsMi = *reinterpret_cast<int*>(*reinterpret_cast<int*>(pWs + 4) + 4);
    pWsVtable = *reinterpret_cast<int*>(nWsMi + 4 + pWs);
    (**(void(**)(std::uint32_t))(pWsVtable + 0x218))(
        *reinterpret_cast<std::uint32_t*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(thisVehicle + 4) + 4) +
            0xa8 + thisVehicle));

    // Per-wheel scale from chassis float table at clonebase+0x600
    char nWheel = 0;
    std::uint32_t uIdx = 0; // low byte = wheel index
    if (*reinterpret_cast<char*>(*reinterpret_cast<int*>(thisVehicle + 600) + 0xb0) > 0) {
        do {
            int pWheel = FUN_005a6e00(uIdx);
            if (pWheel != 0) {
                int* pWheelObj = reinterpret_cast<int*>(FUN_005a6e00(uIdx));
                int nVehMi =
                    *reinterpret_cast<int*>(*reinterpret_cast<int*>(thisVehicle + 4) + 4);
                float flScale =
                    *reinterpret_cast<float*>(
                        *reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(nVehMi + 0xac + thisVehicle) + 0x3c) +
                        0x600 + nWheel * 4) *
                    g_flLevelUpUiBase_Inferred;
                (**(void(**)(float))(*pWheelObj + 0x1c))(flScale);
            }
            nWheel = static_cast<char>(nWheel + 1);
            uIdx = (uIdx & 0xffffff00u) | static_cast<std::uint8_t>(nWheel);
        } while (nWheel <
                 *reinterpret_cast<char*>(
                     *reinterpret_cast<int*>(thisVehicle + 600) + 0xb0));
    }
}
