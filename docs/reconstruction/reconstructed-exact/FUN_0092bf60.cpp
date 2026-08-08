// =============================================================================
// FUN_0092bf60
// -----------------------------------------------------------------------------
// Stable ID: aa_0092bf60
// Address:   0x0092bf60–0x0092c075  (autoassault.exe, image base 0x400000)
// Size:      278 bytes (0x116)
// System:    inventory-transfer (partition) / MissionTracker refresh (role)
// Generated: 2026-08-05 R11-040 — bytes-authority rewrite
// Exactness: Behavior-preserving control flow from image. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Named twin: MissionTracker_RefreshTrackedTargets_Inferred.cpp
//
// DECOMPILER WARNING: live Ghidra collapses primary FUN_0092a440 + TFID copy +
// type gate; marks those blocks unreachable. This twin follows read_memory +
// get_assembly_context.
// =============================================================================

#include <cstdint>
#include <cstring>

using u8 = std::uint8_t;

extern float DAT_00aaa690; // 4.0f
extern float DAT_00aaaaf8; // 1e9f

extern "C" u8 Tracker_ClearOwnedPtrVectorAt11c_Inferred_EDI(void* host);
extern "C" u8 FUN_0092af80_filter(void* host, void** bestObjOut, void* origin, float* bestDistSq);
extern "C" void* __thiscall FUN_0092a440(void* worldObj, void* host);
extern "C" u8 FUN_0092b2a0(void* host, void* origin);

static void* character_origin_vtbl1a0(void* character)
{
    auto* base = reinterpret_cast<u8*>(character);
    int*  p1   = *reinterpret_cast<int**>(base + 4);
    int   adj  = p1[1];
    u8*   self = base + adj + 4;
    void** vtbl = *reinterpret_cast<void***>(self);
    using VFn = void*(__thiscall*)(void*);
    return reinterpret_cast<VFn>(vtbl[0x1A0 / 4])(self);
}

// Image entry: EAX = host. Explicit parameter for reconstruction ports.
extern "C" u8 FUN_0092bf60(void* host /*EAX*/)
{
    void* client = *reinterpret_cast<void**>(host);
    if (client == nullptr)
        return 0;
    if (*reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xE98) == nullptr)
        return 0;
    if (*reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xE04) == nullptr)
        return 0;

    Tracker_ClearOwnedPtrVectorAt11c_Inferred_EDI(host);
    *reinterpret_cast<float*>(reinterpret_cast<u8*>(host) + 0x14) = DAT_00aaa690;

    void* character = *reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xE98);
    if (*reinterpret_cast<u8*>(reinterpret_cast<u8*>(character) + 0x4F1) != 0)
        return 0;
    if (*reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xD34) == nullptr)
        return 0;

    void* origin = character_origin_vtbl1a0(character);

    void* bestObj = nullptr;
    float bestDistSq = DAT_00aaaaf8;

    if (FUN_0092af80_filter(host, &bestObj, origin, &bestDistSq) != 0 && bestObj != nullptr) {
        if (*reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x0B) != 0) {
            void* clone = *reinterpret_cast<void**>(reinterpret_cast<u8*>(bestObj) + 0xA8);
            int type = *reinterpret_cast<int*>(reinterpret_cast<u8*>(clone) + 0x38);
            if (type != 0x12 && type != 0x0E)
                *reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x0B) = 0;
        }
        void* node = FUN_0092a440(bestObj, host);
        if (node == nullptr)
            return 1;
        *reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x08) = 0;
        std::memcpy(node, reinterpret_cast<u8*>(bestObj) + 0x160, 16);
        return 1;
    }

    if (FUN_0092b2a0(host, origin) != 0)
        return 1;

    *reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x08) = 0;
    return 0;
}
