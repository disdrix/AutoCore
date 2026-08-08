// =============================================================================
// FUN_0092a590  (Ghidra twin of Tracker_SetActiveMissionObjective_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a590
// Address:   0x0092a590 – 0x0092a5fe  (111 B / 0x6F)
// Canonical: Tracker_SetActiveMissionObjective_Inferred
// System:    missions-progression
// Sealed:    2026-08-05 dual MEGA-010
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED. Terminal: false.
// =============================================================================
//
// Prefer the named clean source:
//   docs/reconstruction/reconstructed-exact/Tracker_SetActiveMissionObjective_Inferred.cpp
//
// ABI: ECX = MissionTracker*; EAX = missionId; AL = bool; bare RET.
// =============================================================================

#include <cstdint>

using u32 = std::uint32_t;
using u8  = std::uint8_t;

struct Client;
struct Character;
struct ObjectiveNode;
struct MissionTracker;

void* __thiscall CNDHash_LookupByKey(void* hash, u32 key);
u32 FUN_0092a3d0(void); // EDI = tracker
u32 FUN_00929c00(void); // EAX = tracker

char __fastcall FUN_0092a590(MissionTracker* tracker /*ECX*/, u32 missionId /*EAX*/)
{
    auto* base = reinterpret_cast<u8*>(tracker);

    *reinterpret_cast<u32*>(base + 0x10) = missionId;
    *(base + 0x6) = 1;

    if (missionId == 0) {
        FUN_0092a3d0();
        FUN_00929c00();
        *reinterpret_cast<u32*>(base + 0x10) = 0;
        *reinterpret_cast<u32*>(base + 0x0c) = 0;
        return 1;
    }

    auto* host = *reinterpret_cast<Client**>(base + 0x00);
    auto* character =
        *reinterpret_cast<Character**>(reinterpret_cast<u8*>(host) + 0xe98);
    if (character != nullptr) {
        void* hash =
            *reinterpret_cast<void**>(reinterpret_cast<u8*>(character) + 0x548);
        auto* node =
            reinterpret_cast<ObjectiveNode*>(CNDHash_LookupByKey(hash, missionId));
        if (node != nullptr) {
            auto* headPtr =
                *reinterpret_cast<u32**>(reinterpret_cast<u8*>(node) + 0x14c);
            *reinterpret_cast<u32*>(base + 0x0c) = *headPtr;
            *(base + 0x4) = 1;
            return 1;
        }
    }

    FUN_0092a3d0();
    FUN_00929c00();
    *reinterpret_cast<u32*>(base + 0x10) = 0;
    *reinterpret_cast<u32*>(base + 0x0c) = 0;
    return 0;
}
