// =============================================================================
// CVOGHBPendingUseObject_OnHeartBeat_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b440
// Address:   0x0060b440 – 0x0060b49f  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0060b440
// Named twin of reconstructed-exact/FUN_0060b440.cpp — keep CF identical.
// Dual:      reviews/A_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md
//            reviews/B_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md
// =============================================================================

#include <cstdint>

struct CVOGHBPendingUseObject {
    void*          pVTable;            // +0x00
    std::uint32_t  nRefOrFlags;        // +0x04
    int            nPeriodMs;          // +0x08
    int            nPeriodSentinel;    // +0x0C
    int            nPeriodCounter;     // +0x10
    unsigned       dwLastFireTickMs;   // +0x14
    void*          pOwnerObject;       // +0x18
    int            nTypeTag;           // +0x1C
    char           cStopped;           // +0x20
    void*          pSecondaryObject;   // +0x24
    void*          pCharacter;         // +0x28
};

extern "C" std::uint32_t DAT_00af49ac; // = 16 Remove

extern "C" std::uint8_t __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(
    void* character, char commit);

extern "C" void __thiscall CVOGHBBase_RescheduleAfterFire(
    void* hb, std::uint32_t* pOutNextDelayMs);

std::uint32_t* __thiscall CVOGHBPendingUseObject_OnHeartBeat_Inferred(
    CVOGHBPendingUseObject* self,
    std::uint32_t* pOutStatus)
{
    if (self->pOwnerObject != nullptr
        && self->pCharacter != nullptr
        && self->pSecondaryObject != nullptr
        && self->cStopped == '\0') {

        auto* character = reinterpret_cast<std::uint8_t*>(self->pCharacter);
        auto* pendingSecondary =
            *reinterpret_cast<void**>(character + 0xc9c);

        if (pendingSecondary != self->pSecondaryObject) {
            *pOutStatus = DAT_00af49ac;
            return pOutStatus;
        }

        CVOGCharacter_ResolveUseObjectPending_Inferred(self->pCharacter, /*commit=*/1);
        CVOGHBBase_RescheduleAfterFire(self, pOutStatus);
        return pOutStatus;
    }

    *pOutStatus = DAT_00af49ac;
    return pOutStatus;
}

std::uint32_t* __thiscall FUN_0060b440(
    CVOGHBPendingUseObject* self,
    std::uint32_t* pOutStatus)
{
    return CVOGHBPendingUseObject_OnHeartBeat_Inferred(self, pOutStatus);
}
