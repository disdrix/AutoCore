// =============================================================================
// Tracker_SetActiveMissionObjective_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a590
// Address:   0x0092a590 – 0x0092a5fe  (111 B / 0x6F)
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_0092a590
// System:    missions-progression
// Sealed:    2026-08-05 dual MEGA-010
//            (decompile + analyze_function_complete + disassemble_function +
//             read_memory + callers/xrefs + get_assembly_context @ 0x0092fd4c)
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED. Terminal: false.
// Prior scaffold retired:
//   Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton_0092a590
// =============================================================================
//
// PURPOSE
//   Bind or clear the active mission objective on the client mission tracker
//   (object at client+0x4d0). Sole caller is Client_TryBindActiveMissionTracker
//   (FUN_0092fd00), which has already gated non-zero ids through the character
//   active-objectives hash + FUN_0059dc50 eligibility.
//
// ABI (image-sealed, dual-register — not cdecl)
//   ECX = MissionTracker* (this)
//   EAX = missionId (u32).  0 = clear path
//   AL  = success (bool)
//   Stack: none (bare RET / C3) ×3 exits
//
// TRACKER FIELD MAP (sealed offsets)
//   +0x00  host/client* (used as *tracker → +0xe98 character)
//   +0x04  flag_bound (set 1 on successful non-zero bind)
//   +0x06  flag_dirty (set 1 on every entry)
//   +0x0c  activeObjectiveHead (first dword of *(node+0x14c))
//   +0x10  activeMissionId
//   +0x11c / +0x120  objective-related vector (cleared by FUN_0092a3d0 via EDI)
//
// RELATED
//   Parent:  Client_TryBindActiveMissionTracker @ 0x0092fd00 (dualed W21-Q)
//   Hash:    CNDHash_LookupByKey @ 0x005b0920
//   Clear:   FUN_0092a3d0 (EDI=tracker), FUN_00929c00 (EAX=tracker)
// =============================================================================

#include <cstdint>

using u32  = std::uint32_t;
using u8   = std::uint8_t;

struct Client;
struct Character;
struct ObjectiveNode;
struct MissionTracker;

// thiscall: ECX = hash @ character+0x548; stack = key
void* __thiscall CNDHash_LookupByKey(void* hash, u32 key);

// Custom: EDI = tracker. Clears objective vector at tracker+0x11c / +0x120.
u32 Tracker_ClearObjectiveVector_EDI(/* EDI = MissionTracker* */);

// Custom: EAX = tracker. Resets display/timer fields (+0x18..+0x10c family).
u32 Tracker_ResetDisplayFields_EAX(/* EAX = MissionTracker* */);

// Ghidra symbols for the clear helpers (same VAs).
u32 FUN_0092a3d0(void); // EDI=tracker
u32 FUN_00929c00(void); // EAX=tracker

// ---------------------------------------------------------------------------
// Primary entry
// ---------------------------------------------------------------------------
char __fastcall Tracker_SetActiveMissionObjective_Inferred(
    MissionTracker* tracker /*ECX*/,
    u32 missionId /*EAX*/)
{
    auto* base = reinterpret_cast<u8*>(tracker);

    // 0092a598 / 0092a59b — always stamp id + dirty
    *reinterpret_cast<u32*>(base + 0x10) = missionId;
    *(base + 0x6) = 1;

    if (missionId == 0) {
        // 0092a5a1..0092a5b7 — clear path always succeeds
        // Image: CALL FUN_0092a3d0 with EDI=tracker; MOV EAX,EDI; CALL FUN_00929c00
        FUN_0092a3d0();
        FUN_00929c00();
        *reinterpret_cast<u32*>(base + 0x10) = 0;
        *reinterpret_cast<u32*>(base + 0x0c) = 0;
        return 1;
    }

    // 0092a5b8 — host → character @ +0xe98
    auto* host = *reinterpret_cast<Client**>(base + 0x00);
    auto* character =
        *reinterpret_cast<Character**>(reinterpret_cast<u8*>(host) + 0xe98);
    if (character != nullptr) {
        void* hash =
            *reinterpret_cast<void**>(reinterpret_cast<u8*>(character) + 0x548);
        // Image: PUSH missionId; thiscall CNDHash_LookupByKey
        auto* node =
            reinterpret_cast<ObjectiveNode*>(CNDHash_LookupByKey(hash, missionId));
        if (node != nullptr) {
            // 0092a5d4..0092a5e7 — stamp objective head + bind flag
            auto* headPtr =
                *reinterpret_cast<u32**>(reinterpret_cast<u8*>(node) + 0x14c);
            *reinterpret_cast<u32*>(base + 0x0c) = *headPtr;
            *(base + 0x4) = 1;
            return 1;
        }
    }

    // 0092a5e8..0092a5fe — miss / null character: clear and fail
    FUN_0092a3d0();
    FUN_00929c00();
    *reinterpret_cast<u32*>(base + 0x10) = 0;
    *reinterpret_cast<u32*>(base + 0x0c) = 0;
    return 0;
}

// Ghidra symbol alias (same body / same VA).
char __fastcall FUN_0092a590(MissionTracker* tracker /*ECX*/, u32 missionId /*EAX*/)
{
    return Tracker_SetActiveMissionObjective_Inferred(tracker, missionId);
}
