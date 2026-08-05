// =============================================================================
// Client_RecvObjectResolveWeaponReset_0x201c_Inferred
// -----------------------------------------------------------------------------
// Purpose:  S2C opcode 0x201C handler (Client_PacketDispatch case):
//             1) Resolve object via CVOGReaction_ResolveObjectTarget using
//                packet fields +0x90/+0x94/+0x98 and resolver at game+0xD34
//             2) If missing: FUN_008120d0(game, packet) create path
//                If present: FUN_00811e00 sector-update path
//             3) If object exposes weapon via vtbl+0x1E0:
//                  clear fire pair (0); FireHelper(&DAT_00d1a680, suppress=1)
//
// Address:  0x00814400  (autoassault.exe, image base 0x400000)
// End:      0x00814466 exclusive (102 bytes)
// Stable:   aa_00814400
// Ghidra:   FUN_00814400
// Wire:     0x201C
//
// Convention: custom dispatch regs — EDI=packet*, EBX=game*; plain ret
// Callees:    CVOGReaction_ResolveObjectTarget, FUN_008120d0, FUN_00811e00,
//             Weapon_SetFireFlagPair_Inferred, Weapon_FireHelper_Inferred
// Caller:     Client_PacketDispatch @ 0x00815774 (sole)
//
// Exactness: Preserves retail control flow and call order.
// Bit-for-bit vs retail EXE: 102-byte body sealed via read_memory; package DEFERRED.
// Runtime / differential: OPEN.
// Dual A/B (static): SEALED accept-with-gaps 2026-07-29 (W24-Q).
// =============================================================================

#include <cstdint>

struct GameClient;
struct PacketBody_0x201c;
struct GameObject;
struct WeaponHardpoint;

extern "C" std::uint8_t DAT_00d1a680; // FireHelper param_2 blob (role open)

// Sealed / named callees (signatures approximate for port clarity)
GameObject* CVOGReaction_ResolveObjectTarget(
    void* resolverThis,
    std::uint8_t typeByte,
    std::uint32_t idLo,
    std::uint32_t idHi);
GameObject* FUN_008120d0(GameClient* game, PacketBody_0x201c* packet);
void FUN_00811e00(PacketBody_0x201c* packet, GameClient* game);
void Weapon_SetFireFlagPair_Inferred(WeaponHardpoint* weapon, std::uint8_t value);
std::uint32_t Weapon_FireHelper_Inferred(
    WeaponHardpoint* weapon,
    void* param2,
    char suppressFire);

/// S2C 0x201C: resolve-or-create object, then reset weapon fire state if present.
/// Dispatch leaves packet* in EDI and game* in EBX (not a portable C ABI).
void Client_RecvObjectResolveWeaponReset_0x201c_Inferred(
    GameClient* game /* EBX */,
    PacketBody_0x201c* packet /* EDI */)
{
    auto* pkt = reinterpret_cast<std::uint8_t*>(packet);
    auto* g = reinterpret_cast<std::uint8_t*>(game);

    void* resolver = *reinterpret_cast<void**>(g + 0xD34);
    std::uint8_t typeByte = pkt[0x98];
    std::uint32_t idLo = *reinterpret_cast<std::uint32_t*>(pkt + 0x90);
    std::uint32_t idHi = *reinterpret_cast<std::uint32_t*>(pkt + 0x94);

    GameObject* obj = CVOGReaction_ResolveObjectTarget(resolver, typeByte, idLo, idHi);
    if (obj == nullptr) {
        obj = FUN_008120d0(game, packet);
    } else {
        FUN_00811e00(packet, game);
    }

    if (obj == nullptr) {
        return;
    }

    auto* vtbl = *reinterpret_cast<void***>(obj);
    using VfnGetWeapon = WeaponHardpoint*(__thiscall*)(GameObject*);
    auto getWeapon = reinterpret_cast<VfnGetWeapon>(vtbl[0x1E0 / sizeof(void*)]);
    WeaponHardpoint* w = getWeapon(obj);
    if (w == nullptr) {
        return;
    }

    Weapon_SetFireFlagPair_Inferred(w, 0);
    Weapon_FireHelper_Inferred(w, &DAT_00d1a680, /*suppressFire=*/1);
}
