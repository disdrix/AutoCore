// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGReaction_UpdateRepairStationPosition×2, GenericVar1×2, CVOGReaction_MarkRepairStation, character.
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_MarkRepairStation
// -----------------------------------------------------------------------------
// Purpose:  Reaction type 29 - remember the player's last repair station
//           (map id + station key) and update the per-map player→station map.
//
// Address:  0x00521e00  (autoassault.exe, image base 0x400000)
// Stable:   aa_00521e00
// System:   missions-progression / world state
//
// Convention: MSVC __thiscall
//   this     character (player)
//   stationKey  reaction GenericVar1 (small int key - NOT map object COID)
//
// Character writes on success:
//   +0x634 |= 1
//   +0x740  = continent/map id from related object +0xFC   (LastStationMapId)
//   +0x744  = stationKey                                   (LastStationId)
// Then: CVOGReaction_UpdateRepairStationPosition(playerTFID, stationKey)
//
// On missing related object (+0xA8 chain null):
//   +0x634 |= 1
//   +0x744  = -1
//   return false-ish (low byte cleared)
//
// AutoCore: Reaction.HandleMarkRepairStation + Character.SetLastRepairStation.
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

// aa_004d38b0
std::uint32_t __thiscall CVOGReaction_UpdateRepairStationPosition(
    void* /*map implicit via global/this path*/,
    std::uint32_t* pPlayerTfid /* 2 dwords */,
    int stationKey);

// Character dual-base field offsets used here
static constexpr int kOffFlags634        = 0x634;
static constexpr int kOffLastStationMap  = 0x740;
static constexpr int kOffLastStationId   = 0x744;

std::uint32_t __thiscall CVOGReaction_MarkRepairStation(
    void* thisCharacter,
    std::uint32_t stationKey)
{
    auto* const pChar = reinterpret_cast<std::uint8_t*>(thisCharacter);

    // Dual-base header at this+4 → inner layout offsets for map / TFID.
    const std::uint32_t dualHdr = *reinterpret_cast<std::uint32_t*>(pChar + 4);
    const int dualOff =
        *reinterpret_cast<int*>(static_cast<std::uintptr_t>(dualHdr) + 4);

    int pRelatedMapObj = *reinterpret_cast<int*>(
        dualOff + 0xa8 + reinterpret_cast<int>(thisCharacter));

    if (pRelatedMapObj != 0) {
        const std::uint32_t mapId =
            *reinterpret_cast<std::uint32_t*>(pRelatedMapObj + 0xFC);

        *reinterpret_cast<std::uint32_t*>(pChar + kOffFlags634) |= 1u;
        *reinterpret_cast<std::uint32_t*>(pChar + kOffLastStationMap) = mapId;
        *reinterpret_cast<std::uint32_t*>(pChar + kOffLastStationId)  = stationKey;

        // Player TFID from dual-base +0x164 / +0x168
        std::uint32_t playerTfid[2];
        playerTfid[0] = *reinterpret_cast<std::uint32_t*>(
            dualOff + 0x164 + reinterpret_cast<int>(thisCharacter));
        playerTfid[1] = *reinterpret_cast<std::uint32_t*>(
            dualOff + 0x168 + reinterpret_cast<int>(thisCharacter));

        // Decompiler shows UpdateRepairStationPosition(&tfid, stationKey)
        // with map `this` recovered from call site / register.
        return CVOGReaction_UpdateRepairStationPosition(
            nullptr, playerTfid, static_cast<int>(stationKey));
    }

    *reinterpret_cast<std::uint32_t*>(pChar + kOffFlags634) |= 1u;
    *reinterpret_cast<std::uint32_t*>(pChar + kOffLastStationId) = 0xFFFFFFFFu;
    // Low byte cleared → false
    return dualHdr & 0xFFFFFF00u;
}
