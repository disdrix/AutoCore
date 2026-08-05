// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, while×1.
//  - Notable callees: CNDHash_LookupByKey, CVOGCharacter_SetAreaExploredBit, CVOGReaction_UnlockContinentObject, Client_SendLogicUiPacket, FUN_004e2060, FUN_00540060.
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_SetAreaExploredBit
// -----------------------------------------------------------------------------
// Purpose:  Set or clear one explored-area bit on the local character and notify
//           LogicUI (type 0x20). Creates continent unlock entry if needed.
//
// Address:  0x005326b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005326b0
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   this         CVOGCharacter*
//   continentId  hash key
//   areaId       1..32
//   setBit       non-zero → OR bit; zero → AND~bit
//
// Algorithm:
//   1) Reject areaId outside 1..32
//   2) bit = 1 << (areaId-1)
//   3) Lookup USContinentUnlocked @ character+0x534
//   4) If missing and local player (map+0x7e): UnlockContinentObject first
//      (entry still missing → no bit write this call - Unlock may insert async)
//   5) Else set/clear ExploredBits @ entry+0x08
//   6) Client_SendLogicUiPacket type 0x20 with areaId payload
//   7) Local player: walk secondary list (FUN_00540060) matching continent+area
//
// Callers: Client_RecvUnlockRegion bit-diff path; Client_LocalDiscoveryTick.
// Reader:  CVOGCharacter_IsAreaExplored (0x0052b310).
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

void* CNDHash_LookupByKey(void* pHash, int key);
void  CVOGReaction_UnlockContinentObject(void* pCharacter, int continentId);
void  Client_SendLogicUiPacket(void* pPayload /* first dword is type via separate slot */);
int   FUN_00540060(void);   // get secondary explore-notify list head (INFERRED)
void  FUN_004e2060(void);   // list iterator advance (INFERRED)

static constexpr int kOffContinentUnlockHash = 0x534;
static constexpr int kOffExploredBits        = 0x08;
static constexpr int kLogicUiTypeExploreBit  = 0x20;

void __thiscall CVOGCharacter_SetAreaExploredBit(
    void* thisCharacter,
    int   continentId,
    char  areaId,
    char  setBit)
{
    if (areaId <= '\0' || areaId >= '!') {
        return;
    }

    auto* const pChar = reinterpret_cast<std::uint8_t*>(thisCharacter);
    const unsigned bit = 1u << (static_cast<unsigned>(areaId - 1) & 0x1fu);

    void* pUnlockEntry = CNDHash_LookupByKey(
        *reinterpret_cast<void**>(pChar + kOffContinentUnlockHash),
        continentId);

    if (pUnlockEntry == nullptr) {
        // Local player only: attempt unlock so a continent entry appears.
        int pMap = *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(pChar + 4) + 4) +
            0xa8 + reinterpret_cast<int>(thisCharacter));
        if (*reinterpret_cast<char*>(pMap + 0x7e) != '\0') {
            CVOGReaction_UnlockContinentObject(thisCharacter, continentId);
        }
        return;
    }

    auto* const pBits = reinterpret_cast<unsigned*>(
        reinterpret_cast<std::uint8_t*>(pUnlockEntry) + kOffExploredBits);
    if (setBit == '\0') {
        *pBits = *pBits & ~bit;
    } else {
        *pBits = *pBits | bit;
    }

    // LogicUI notify: type 0x20, payload[0] = areaId.
    // Decompiler surface: logicUiType adjacent to payload array; call takes payload.
    unsigned logicUiPayload[7];
    std::uint32_t logicUiType = kLogicUiTypeExploreBit;
    (void)logicUiType;
    logicUiPayload[0] = static_cast<unsigned>(static_cast<int>(areaId));
    Client_SendLogicUiPacket(logicUiPayload);

    // Local player: optional secondary list walk matching (continentId, areaId).
    int pMap = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(pChar + 4) + 4) +
        0xa8 + reinterpret_cast<int>(thisCharacter));
    if (*reinterpret_cast<char*>(pMap + 0x7e) == '\0') {
        return;
    }

    int  iListCtx = FUN_00540060();
    int* piHead   = *reinterpret_cast<int**>(iListCtx + 4);
    int* piNode   = reinterpret_cast<int*>(*piHead);
    if (piNode == piHead) {
        return;
    }
    while (piNode[3] != continentId ||
           static_cast<unsigned>(*reinterpret_cast<unsigned char*>(piNode + 4)) !=
               static_cast<unsigned>(static_cast<int>(areaId))) {
        FUN_004e2060();
        if (piNode == piHead) {
            return;
        }
    }
}
