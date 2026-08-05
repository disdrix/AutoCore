// =============================================================================
// NDSpecialFX_ExpandVehicleHardpointSlots
// -----------------------------------------------------------------------------
// Purpose:  During create-from-packet, walk the template FX hardpoint type
//           dword table (template+0x94/+0x98) and expand vehicle child FX
//           slots by named snprintf + NDSpecialFX_InstantiateFromTemplate
//           + attach helper. Empty table: attach template + 3-slot probe.
//
// Address:  0x004ff850–0x004ffe2e  (autoassault.exe, image base 0x400000)
// Body:     1502 bytes / 0x5DE
// Stable:   aa_004ff850
// System:   client-fx / vehicle create-from-packet
// Ghidra:   FUN_004ff850
// Caller:   CVOG_CreateFromPacketDispatch @ 0x00507000 (thin trampoline)
//
// ABI:      __thiscall — ECX = interior host this; stack templateFx, p3, p4;
//           ret 0x0C.  param_4 != 0 enables FailMissionNotify tracking.
// Exactness: Control flow + case table + format strings preserved from
//            live decompile + read_memory entry/exit. Nested helpers residual.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W23-Q seal).
// =============================================================================

#include <cstdint>
#include <cstdio>

// Dual-reviewed instantiate (aa_004a0b90).
extern "C" void *__thiscall NDSpecialFX_InstantiateFromTemplate(
    void *templateFx /* ECX-shaped first arg in call site */,
    char *name,
    int scale,
    uint32_t filterOrTypeId,
    int stamp);

// Residual helpers (not dual-sealed in this wave).
extern "C" void __thiscall FUN_005829d0(void *fx, uint32_t p3, int p4);
extern "C" void __thiscall FUN_004b7030(void *slot, int a, int b, uint32_t idx);
extern "C" int FUN_00989270(int hardpointId);
// Sealed elsewhere as u32 vector push (not mission-fail product English).
extern "C" void CVOGReaction_FailMissionNotify(void *pSpawnedPtr);

// Hardpoint type ids in template+0x94 dword table
enum VehicleHardpointTypeId : uint32_t {
    kHpWheelset = 0x0Bu,
    kHpExhaust  = 0x0Fu,
    kHpBrakes   = 0x10u,
    kHpLights   = 0x11u,
    kHpMelee    = 0x15u,
};

static void ZeroNameBuf(char *buf /* 0x104 */)
{
    // Decompiler: zero first 2 bytes, then 0x40 dwords, then trailing word —
    // equivalent to clearing 0x104 bytes of stack name storage.
    for (int i = 0; i < 0x104; ++i)
        buf[i] = 0;
}

static void ExpandOne(
    void *templateFx,
    char *nameBuf,
    const char *fmt,
    int nameIndex,
    uint32_t typeId,
    int stamp,
    uint32_t param_3,
    int param_4)
{
    ZeroNameBuf(nameBuf);
    _snprintf(nameBuf, 0x104, fmt,
              reinterpret_cast<char *>(templateFx) + 0xD5,
              nameIndex);
    void *child = NDSpecialFX_InstantiateFromTemplate(
        templateFx, nameBuf, /*scale*/1, typeId, stamp);
    if (param_4 != 0) {
        CVOGReaction_FailMissionNotify(&child);
    }
    FUN_005829d0(child, param_3, param_4);
}

/* NDSpecialFX_ExpandVehicleHardpointSlots

   Parameters:
     thisHost:   interior host pointer in ECX (uses this-0x330/-0x418/-0x628)
     templateFx: FX template with type vector +0x94/+0x98 and name +0xD5
     param_3:    forwarded to attach helper
     param_4:    non-zero → track spawned children via FailMissionNotify push

   Returns: void */

void __thiscall NDSpecialFX_ExpandVehicleHardpointSlots(
    void *thisHost /* ECX */,
    void *templateFx,
    uint32_t param_3,
    int param_4)
{
    int *typeBegin = *reinterpret_cast<int **>(reinterpret_cast<char *>(templateFx) + 0x94);
    int *typeEnd   = *reinterpret_cast<int **>(reinterpret_cast<char *>(templateFx) + 0x98);

    // ---- empty / null type table ----
    if (typeBegin == nullptr ||
        ((reinterpret_cast<char *>(typeEnd) - reinterpret_cast<char *>(typeBegin)) >> 2) == 0) {
        FUN_005829d0(templateFx, param_3, param_4);
        char idx = 0;
        int *slot = reinterpret_cast<int *>(reinterpret_cast<char *>(thisHost) - 0x330);
        do {
            if (*slot != 0) {
                FUN_004b7030(reinterpret_cast<void *>(*slot), 0, 1,
                             static_cast<uint32_t>(static_cast<uint8_t>(idx)));
            }
            idx = static_cast<char>(idx + 1);
            slot++;
        } while (idx < 3);
        return;
    }

    uint32_t index = 0;
    int byteOff = 0;

    char nameWheel[0x104];
    char nameExhaust[0x104];
    char nameBrakes[0x104];
    char nameLights[0x104];
    char nameMelee[0x104];

LAB_walk:
    typeBegin = *reinterpret_cast<int **>(reinterpret_cast<char *>(templateFx) + 0x94);
    typeEnd   = *reinterpret_cast<int **>(reinterpret_cast<char *>(templateFx) + 0x98);
    if (typeBegin == nullptr ||
        (static_cast<uint32_t>((reinterpret_cast<char *>(typeEnd) -
                                reinterpret_cast<char *>(typeBegin)) >> 2) <= index)) {
        FUN_005829d0(templateFx, param_3, param_4);
        return;
    }

    uint32_t typeId =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(typeBegin) + byteOff);

    switch (typeId) {
    case kHpWheelset: {
        void *wsHost = *reinterpret_cast<void **>(reinterpret_cast<char *>(thisHost) - 0x418);
        if (wsHost != nullptr) {
            char count = *reinterpret_cast<char *>(reinterpret_cast<char *>(wsHost) + 0xB0);
            if (count < 3)
                count = 4;
            int i = 1;
            if (1 < count) {
                do {
                    ExpandOne(templateFx, nameWheel, "%s_WHEELSET_%d", i,
                              typeId, i, param_3, param_4);
                    i++;
                } while (i < count);
                index++;
                byteOff += 4;
                goto LAB_walk;
            }
        }
        break;
    }
    case kHpExhaust: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(thisHost) - 0x628);
        if (gate != nullptr) {
            int id = 0x4BB;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    ExpandOne(templateFx, nameExhaust, "%s_VEHICLE_EXHAUST_%d", id,
                              typeId, id - 0x4BA, param_3, param_4);
                }
                id++;
            } while (id < 0x4C0);
            index++;
            byteOff += 4;
            goto LAB_walk;
        }
        break;
    }
    case kHpBrakes: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(thisHost) - 0x628);
        if (gate != nullptr) {
            int id = 0x4C5;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    ExpandOne(templateFx, nameBrakes, "%s_VEHICLE_BRAKES_%d", id,
                              typeId, id - 0x4C4, param_3, param_4);
                }
                id++;
            } while (id < 0x4CC);
            // falls through to common index++ (same net effect as early goto)
        }
        break;
    }
    case kHpLights: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(thisHost) - 0x628);
        if (gate != nullptr) {
            int id = 0x4CF;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    ExpandOne(templateFx, nameLights, "%s_VEHICLE_LIGHTS_%d", id,
                              typeId, id - 0x4CE, param_3, param_4);
                }
                id++;
            } while (id < 0x4D8);
            index++;
            byteOff += 4;
            goto LAB_walk;
        }
        break;
    }
    case kHpMelee: {
        void *gate = *reinterpret_cast<void **>(reinterpret_cast<char *>(thisHost) - 0x628);
        if (gate == nullptr)
            break;
        {
            int id = 0x3E9;
            do {
                if (*reinterpret_cast<int *>(reinterpret_cast<char *>(gate) + 0x64) != 0 &&
                    FUN_00989270(id) != 0) {
                    ExpandOne(templateFx, nameMelee, "%s_VEHICLE_MELEE_%d", id,
                              typeId, id - 1000, param_3, param_4);
                }
                id++;
            } while (id < 0x409);
            index++;
            byteOff += 4;
            goto LAB_walk;
        }
    }
    default:
        break;
    }

    index++;
    byteOff += 4;
    goto LAB_walk;
}
