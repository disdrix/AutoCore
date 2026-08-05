// =============================================================================
// Client_TryBindActiveMissionTracker
// -----------------------------------------------------------------------------
// Stable ID: aa_0092fd00
// Address:   0x0092fd00  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0092fd00
// System:    missions-progression
// Sealed:    2026-07-29 dual W21-Q (decompile + read_memory + call-site asm)
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Bind or clear the client's active-mission objective tracker from a mission id.
//   On success with a live mission UI root (client+0x107c), run the standard
//   visibility probe (vtbl+0x3d8) and refresh action (vtbl+0x448).
//
// ABI (image-sealed, custom dual-register — not cdecl)
//   EDI = Client* / game controller (often global 0x00d1a840)
//   EAX = missionId (u32).  0 = clear/idle path
//   AL  = success (bool)
//   Stack: none (ret)
//
// RELATED
//   Tracker write:     FUN_0092a590 @ tracker (client+0x4d0), missionId in EAX
//   Objective gate:    FUN_0059dc50 thiscall(node), character on stack
//   FailMission path:  calls this with EAX==0 after active-objectives hash miss
// =============================================================================

#include <cstdint>

using u32 = std::uint32_t;

struct Client;
struct Character;
struct ObjectiveNode;
struct MissionTracker;
struct MissionUiRoot;

// Hash @ character+0x548
void* CNDHash_LookupByKey(void* hash, u32 key);

// thiscall: ECX = objective hash node; stack = Character*
// Returns non-zero if node may be bound for this character.
char __thiscall ObjectiveNode_CanBindToCharacter(ObjectiveNode* node, Character* character);

// thiscall: ECX = tracker (client+0x4d0); EAX = missionId
// Sets tracker+0x10 / flags; on id!=0 looks up objective and stamps tracker+0x0c.
// On id==0 clears tracker and related state. Returns 1 on success, 0 on miss.
char __fastcall Tracker_SetActiveMissionObjective(MissionTracker* tracker /*ECX*/,
                                                  u32 missionId /*EAX*/);

// Alias plate for Ghidra symbol used at call sites still naming FUN_0092a590.
char __fastcall FUN_0092a590(MissionTracker* tracker, u32 missionId);

// Ghidra gate symbol (thiscall node + character stack arg).
char __thiscall FUN_0059dc50(ObjectiveNode* node, Character* character);

// ---------------------------------------------------------------------------
// Primary entry — custom: EDI=client, EAX=missionId, AL=bool
// ---------------------------------------------------------------------------
char Client_TryBindActiveMissionTracker(Client* client /*EDI*/, u32 missionId /*EAX*/)
{
    Character* character =
        *reinterpret_cast<Character**>(reinterpret_cast<char*>(client) + 0xe98);
    if (character == nullptr) {
        return 0;
    }

    if (missionId != 0) {
        void* hash =
            *reinterpret_cast<void**>(reinterpret_cast<char*>(character) + 0x548);
        auto* node =
            reinterpret_cast<ObjectiveNode*>(CNDHash_LookupByKey(hash, missionId));
        if (node == nullptr) {
            return 0;
        }
        // Image: push character; mov ecx, node; call FUN_0059dc50
        if (FUN_0059dc50(node, character) == 0) {
            return 0;
        }
        // fall through to bind
    } else {
        // missionId == 0: if tracker already idle (+0x10 == 0), success without work
        auto* tracker =
            *reinterpret_cast<MissionTracker**>(reinterpret_cast<char*>(client) + 0x4d0);
        u32 currentId =
            *reinterpret_cast<u32*>(reinterpret_cast<char*>(tracker) + 0x10);
        if (currentId == 0) {
            return 1;
        }
        // else fall through — clear via binder
    }

    auto* tracker =
        *reinterpret_cast<MissionTracker**>(reinterpret_cast<char*>(client) + 0x4d0);
    // Image: mov ecx, [edi+0x4d0]; mov eax, ebx; call FUN_0092a590
    char ok = FUN_0092a590(tracker, missionId);
    if (ok != 0) {
        auto* ui =
            *reinterpret_cast<MissionUiRoot**>(reinterpret_cast<char*>(client) + 0x107c);
        if (ui != nullptr) {
            using VBool = char(__thiscall*)(MissionUiRoot*);
            using VAct  = void(__thiscall*)(MissionUiRoot*);
            void** vtbl = *reinterpret_cast<void***>(ui);
            auto isLive  = reinterpret_cast<VBool>(vtbl[0x3d8 / sizeof(void*)]);
            auto refresh = reinterpret_cast<VAct>(vtbl[0x448 / sizeof(void*)]);
            if (isLive(ui) != 0) {
                refresh(ui);
            }
        }
    }
    return ok;
}

// Ghidra symbol alias (same body / same VA).
char FUN_0092fd00(void)
{
    // Decompiler phantom form: unaff_EDI + in_EAX. Prefer named entry above.
    Client* client = nullptr; // EDI
    u32 missionId = 0;        // EAX
    return Client_TryBindActiveMissionTracker(client, missionId);
}
