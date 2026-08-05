// =============================================================================
// Client_ApplyVehicleSwitch_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Client-side apply path for a vehicle chassis switch onto newVehicle:
//           tear down related UI slots/dialogs, call Character_SwitchVehicle
//           with allocate-id sentinels (0xFFFFFFFF,0xFFFFFFFF), rebind garage
//           UI, open dialog slot 0x12, refresh combat pools + mission windows.
//           Always returns 1 (does not branch on SwitchVehicle HRESULT).
//
// Address:  0x0093d880  (autoassault.exe, image base 0x400000)
// End:      0x0093da26 exclusive (422 / 0x1A6 bytes)
// Stable:   aa_0093d880
// Ghidra:   FUN_0093d880
// Machine:  55 8B EC 83 E4 F0 51 53 8B D8 ... B0 01 ... C2 04 00
//
// Convention: custom register + stack
//   EAX = Client* at entry (saved to EBX)
//   [ebp+8] = Vehicle* newVehicle
//   RET 4; AL = 1
//
// Primary nested: Character_SwitchVehicle_Inferred (0x005252f0) @ 0x0093d95b
// Contrast:       Client_OnVehicleSwitchFailure (0x00810360) — failure UX path
//
// CODE xrefs: 0 (Ghidra) — invoker unresolved (likely indirect)
// Exactness:  CF from live decompile 2026-07-29 ≡ raw 2026-07-23.
// Bit-for-bit / runtime / differential: OPEN.
// Dual A/B (static): SEALED accept-with-gaps 2026-07-29 (W26-S).
// =============================================================================

#include <cstdint>

struct Client;
struct Character;
struct Vehicle;

// Nested (declared only)
std::uint32_t /*HRESULT*/ __thiscall Character_SwitchVehicle_Inferred(
    Character *self,
    Vehicle *newVehicle,
    Vehicle **outOldVehicle,
    std::uint32_t argA,
    std::uint32_t argB);
void FUN_007fca10(void); // EAX=dialog*, EBX=client*
void FUN_009147a0(void);
void FUN_008801b0(void *garageUi);
void FUN_0085e970(void);
void __thiscall FUN_007fef20(Client *self, int dialogIndex, char show, char flag);
void Vehicle_EnsureRegenerationHeartbeat(void *vehicle);
void Vehicle_RecalcCombatPools(void *vehicle);
void Client_RefreshOpenMissionUiWindows(Client *client);

/// Apply vehicle switch on the client; always returns 1.
std::uint8_t Client_ApplyVehicleSwitch_Inferred(Client *client /*EAX*/, Vehicle *newVehicle)
{
    auto *cli = reinterpret_cast<std::uint8_t *>(client);
    Character *character = *reinterpret_cast<Character **>(cli + 0xe98);
    auto *char_b = reinterpret_cast<std::uint8_t *>(character);
    void *vehicle = *reinterpret_cast<void **>(char_b + 0x250);

    // Stage 1: vehicle host vfunc +0x1c8 (this-adjust vbase)
    // (virtual call through vehicle layout — preserved as opaque)

    void *subHost = nullptr;
    if (vehicle != nullptr) {
        subHost = reinterpret_cast<std::uint8_t *>(vehicle) + 0x40;
    }

    void *uiObj = *reinterpret_cast<void **>(cli + 0x1078);
    cli[0x30b4] = 1;
    cli[0x30b5] = 0;

    void **p309c = *reinterpret_cast<void ***>(cli + 0x309c);
    if (p309c != nullptr) {
        // (*p309c)->vtbl[1](0)
        (void)p309c;
    }
    // subHost->vtbl[+0x1c](0) when non-null layout

    if (uiObj != nullptr) {
        // if uiObj->vtbl[+0xd0](): FUN_007fca10();
    }

    auto *f38 = *reinterpret_cast<std::uint8_t **>(cli + 0xf38);
    void **slot0 = *reinterpret_cast<void ***>(f38 + 0xc70);
    void **slot1 = *reinterpret_cast<void ***>(f38 + 0xc74);
    if (slot0 != nullptr) {
        // slot0->vtbl[+0x18](1, 1)
    }
    if (slot1 != nullptr) {
        // slot1->vtbl[+0x18](1, 1)
    }
    *reinterpret_cast<void **>(f38 + 0xc70) = nullptr;
    *reinterpret_cast<void **>(f38 + 0xc74) = nullptr;

    Vehicle *outOld = nullptr;
    Character_SwitchVehicle_Inferred(
        character,
        newVehicle,
        &outOld,
        0xFFFFFFFFu,
        0xFFFFFFFFu);

    FUN_009147a0();

    // Rebind garage UI object to post-switch vehicle
    void *newVeh = *reinterpret_cast<void **>(
        *reinterpret_cast<std::uint8_t **>(cli + 0xe98) + 0x250);
    if (uiObj != nullptr) {
        *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(uiObj) + 0x514) = newVeh;
        FUN_008801b0(uiObj);
    }

    auto *p1040 = *reinterpret_cast<std::uint8_t **>(cli + 0x1040);
    auto *nested = *reinterpret_cast<std::uint8_t **>(p1040 + 0x50c);
    if (nested != nullptr && *reinterpret_cast<std::uint32_t *>(nested + 0x580) != 0) {
        FUN_0085e970();
    }

    FUN_007fef20(client, /*dialogIndex=*/0x12, /*show=*/1, /*flag=*/0);

    std::uint8_t flag9c4 = cli[0x9c4];
    auto *veh_b = reinterpret_cast<std::uint8_t *>(
        *reinterpret_cast<void **>(
            *reinterpret_cast<std::uint8_t **>(cli + 0xe98) + 0x250));
    veh_b[0x105] = flag9c4;
    veh_b[0x106] = flag9c4;

    Vehicle_EnsureRegenerationHeartbeat(veh_b);
    Vehicle_RecalcCombatPools(veh_b);
    Client_RefreshOpenMissionUiWindows(client);
    return 1;
}
