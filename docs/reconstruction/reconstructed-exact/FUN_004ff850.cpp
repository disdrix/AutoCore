// =============================================================================
// FUN_004ff850 — Ghidra alias for NDSpecialFX_ExpandVehicleHardpointSlots
// -----------------------------------------------------------------------------
// Stable ID: aa_004ff850
// Address:   0x004ff850  (autoassault.exe, image base 0x400000)
// See:       NDSpecialFX_ExpandVehicleHardpointSlots.cpp (canonical clean)
// Prior auto-name: Drive_s_VEHICLE_EXHAUST_d (too narrow — multi-string table)
// Dual A/B:  accept-with-gaps (2026-07-29 W23-Q)
// =============================================================================

// Include-style twin: keep a self-contained body for FUN_* consumers.
// Full annotated CF lives in NDSpecialFX_ExpandVehicleHardpointSlots.cpp.

#include <cstdint>
#include <cstdio>

extern "C" void *__thiscall FUN_004a0b90(void *a, char *name, int scale, uint32_t filter, int stamp);
extern "C" void __thiscall FUN_005829d0(void *fx, uint32_t p3, int p4);
extern "C" void __thiscall FUN_004b7030(void *slot, int a, int b, uint32_t idx);
extern "C" int FUN_00989270(int hardpointId);
extern "C" void CVOGReaction_FailMissionNotify(void *p);

static void Zero104(char *buf)
{
    for (int i = 0; i < 0x104; ++i)
        buf[i] = 0;
}

void __thiscall FUN_004ff850(void *param_1 /* ECX */, void *param_2, uint32_t param_3, int param_4)
{
    int *begin = *reinterpret_cast<int **>(reinterpret_cast<char *>(param_2) + 0x94);
    int *end   = *reinterpret_cast<int **>(reinterpret_cast<char *>(param_2) + 0x98);

    if (begin == nullptr ||
        ((reinterpret_cast<char *>(end) - reinterpret_cast<char *>(begin)) >> 2) == 0) {
        FUN_005829d0(param_2, param_3, param_4);
        char c = 0;
        int *slot = reinterpret_cast<int *>(reinterpret_cast<char *>(param_1) - 0x330);
        do {
            if (*slot != 0)
                FUN_004b7030(reinterpret_cast<void *>(*slot), 0, 1,
                             static_cast<uint32_t>(static_cast<uint8_t>(c)));
            c = static_cast<char>(c + 1);
            slot++;
        } while (c < 3);
        return;
    }

    uint32_t index = 0;
    int byteOff = 0;
    char acWheel[0x104], acExhaust[0x104], acBrakes[0x104], acLights[0x104], acMelee[0x104];

LAB_004ff8a0:
    begin = *reinterpret_cast<int **>(reinterpret_cast<char *>(param_2) + 0x94);
    end   = *reinterpret_cast<int **>(reinterpret_cast<char *>(param_2) + 0x98);
    if (begin == nullptr ||
        (static_cast<uint32_t>((reinterpret_cast<char *>(end) -
                                reinterpret_cast<char *>(begin)) >> 2) <= index)) {
        FUN_005829d0(param_2, param_3, param_4);
        return;
    }

    uint32_t typeId =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(begin) + byteOff);

    switch (typeId) {
    case 0x0B: {
        void *ws = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) - 0x418);
        if (ws != nullptr) {
            char count = *reinterpret_cast<char *>(reinterpret_cast<char *>(ws) + 0xB0);
            if (count < 3)
                count = 4;
            int i = 1;
            if (1 < count) {
                do {
                    Zero104(acWheel);
                    _snprintf(acWheel, 0x104, "%s_WHEELSET_%d",
                              reinterpret_cast<char *>(param_2) + 0xD5, i);
                    void *child = FUN_004a0b90(param_2, acWheel, 1, typeId, i);
                    if (param_4 != 0)
                        CVOGReaction_FailMissionNotify(&child);
                    FUN_005829d0(child, param_3, param_4);
                    i++;
                } while (i < count);
                index++;
                byteOff += 4;
                goto LAB_004ff8a0;
            }
        }
        break;
    }
    case 0x0F: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) - 0x628);
        if (gate != nullptr) {
            int id = 0x4BB;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    Zero104(acExhaust);
                    _snprintf(acExhaust, 0x104, "%s_VEHICLE_EXHAUST_%d",
                              reinterpret_cast<char *>(param_2) + 0xD5, id);
                    void *child = FUN_004a0b90(param_2, acExhaust, 1, typeId, id - 0x4BA);
                    if (param_4 != 0)
                        CVOGReaction_FailMissionNotify(&child);
                    FUN_005829d0(child, param_3, param_4);
                }
                id++;
            } while (id < 0x4C0);
            index++;
            byteOff += 4;
            goto LAB_004ff8a0;
        }
        break;
    }
    case 0x10: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) - 0x628);
        if (gate != nullptr) {
            int id = 0x4C5;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    Zero104(acBrakes);
                    _snprintf(acBrakes, 0x104, "%s_VEHICLE_BRAKES_%d",
                              reinterpret_cast<char *>(param_2) + 0xD5, id);
                    void *child = FUN_004a0b90(param_2, acBrakes, 1, typeId, id - 0x4C4);
                    if (param_4 != 0)
                        CVOGReaction_FailMissionNotify(&child);
                    FUN_005829d0(child, param_3, param_4);
                }
                id++;
            } while (id < 0x4CC);
        }
        break;
    }
    case 0x11: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) - 0x628);
        if (gate != nullptr) {
            int id = 0x4CF;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    Zero104(acLights);
                    _snprintf(acLights, 0x104, "%s_VEHICLE_LIGHTS_%d",
                              reinterpret_cast<char *>(param_2) + 0xD5, id);
                    void *child = FUN_004a0b90(param_2, acLights, 1, typeId, id - 0x4CE);
                    if (param_4 != 0)
                        CVOGReaction_FailMissionNotify(&child);
                    FUN_005829d0(child, param_3, param_4);
                }
                id++;
            } while (id < 0x4D8);
            index++;
            byteOff += 4;
            goto LAB_004ff8a0;
        }
        break;
    }
    case 0x15: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) - 0x628);
        if (gate == nullptr)
            break;
        {
            int id = 0x3E9;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    Zero104(acMelee);
                    _snprintf(acMelee, 0x104, "%s_VEHICLE_MELEE_%d",
                              reinterpret_cast<char *>(param_2) + 0xD5, id);
                    void *child = FUN_004a0b90(param_2, acMelee, 1, typeId, id - 1000);
                    if (param_4 != 0)
                        CVOGReaction_FailMissionNotify(&child);
                    FUN_005829d0(child, param_3, param_4);
                }
                id++;
            } while (id < 0x409);
            index++;
            byteOff += 4;
            goto LAB_004ff8a0;
        }
    }
    default:
        break;
    }

    index++;
    byteOff += 4;
    goto LAB_004ff8a0;
}
