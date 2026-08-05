// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CNDHash_LookupByKey, CVOGCharacter_IsAreaExplored, bit.
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_IsAreaExplored
// -----------------------------------------------------------------------------
// Purpose:  Test whether explored-area bit (areaId-1) is set for a continent
//           in the character's USContinentUnlocked hash.
//
// Address:  0x0052b310  (autoassault.exe, image base 0x400000)
// Stable:   aa_0052b310
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   this         CVOGCharacter*
//   continentId  hash key for continent unlock record
//   areaId       1..32 inclusive (area ids outside that range → false)
//
// Returns:  true if ExploredBits has bit (areaId-1) set.
//
// Layout:
//   character+0x534  → CNDHash* of USContinentUnlocked entries
//   entry+0x08       → uint ExploredBits (32 area flags)
//
// Sibling writer: CVOGCharacter_SetAreaExploredBit (0x005326b0).
// Sample path: CVOGTerrain_SampleExploredAreaId → area id 1..32.
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

void* CNDHash_LookupByKey(void* pHash, int key);

// character+0x534 → hash of continent unlock records
static constexpr int kOffContinentUnlockHash = 0x534;
// unlock entry+0x08 → ExploredBits
static constexpr int kOffExploredBits        = 0x08;

bool __thiscall CVOGCharacter_IsAreaExplored(
    void* thisCharacter,
    int   continentId,
    char  areaId)
{
    void* pUnlockEntry;

    // Valid area ids are 1..32 ('!' == 33).
    if (areaId <= '\0' || areaId >= '!') {
        return false;
    }

    pUnlockEntry = CNDHash_LookupByKey(
        *reinterpret_cast<void**>(
            reinterpret_cast<std::uint8_t*>(thisCharacter) + kOffContinentUnlockHash),
        continentId);

    if (pUnlockEntry == nullptr) {
        return false;
    }

    const unsigned exploredBits =
        *reinterpret_cast<unsigned*>(
            reinterpret_cast<std::uint8_t*>(pUnlockEntry) + kOffExploredBits);

    const unsigned bit = 1u << (static_cast<unsigned>(areaId - 1) & 0x1fu);
    return (exploredBits & bit) != 0;
}
