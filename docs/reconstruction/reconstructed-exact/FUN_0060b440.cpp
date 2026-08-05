// =============================================================================
// FUN_0060b440 / CVOGHBPendingUseObject_OnHeartBeat_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b440
// Address:   0x0060b440 – 0x0060b49f  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0060b440
// System:    heartbeat / missions-progression (pending use-object aux HB)
// Generated: 2026-07-29 W26-T dual A/B seal (scaffold 2026-07-23 refined)
// Exactness: Behavior-preserving rewrite; decompiler field map corrected from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md
//            reviews/B_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md
// Related:   CVOGCharacter_ResolveUseObjectPending_Inferred; CVOGHBBase_RescheduleAfterFire;
//            Stop helper 0x0060b410; ctor FUN_0060b380; vtbl PTR_FUN_009df668 +0x0C
// =============================================================================
//
// PURPOSE:
//   OnHeartBeat for pending-use-object HB (char+0xca0):
//     - Gate owner / character / secondary / not-stopped
//     - If character+0xc9c != HB+0x24 secondary → *out = Remove (16)
//     - Else commit ResolveUseObjectPending(1) then RescheduleAfterFire
//
// ABI: __thiscall ECX=HB; stack uint32_t* pOutStatus; returns pOut; ret 4.
// =============================================================================

#include <cstdint>

struct CVOGHBPendingUseObject {
    void*          pVTable;            // +0x00 → PTR_FUN_009df668
    std::uint32_t  nRefOrFlags;        // +0x04
    int            nPeriodMs;          // +0x08
    int            nPeriodSentinel;    // +0x0C
    int            nPeriodCounter;     // +0x10
    unsigned       dwLastFireTickMs;   // +0x14
    void*          pOwnerObject;       // +0x18
    int            nTypeTag;           // +0x1C  (= 10)
    char           cStopped;           // +0x20
    // +0x21 …
    void*          pSecondaryObject;   // +0x24
    void*          pCharacter;         // +0x28
};

// DAT_00af49ac @ 0x00af49ac = 16 → EHBStatus Remove
extern "C" std::uint32_t DAT_00af49ac;

extern "C" std::uint8_t __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(
    void* character, char commit);

// sealed: writes next delay / status into pOut
extern "C" void __thiscall CVOGHBBase_RescheduleAfterFire(
    void* hb, std::uint32_t* pOutNextDelayMs);

std::uint32_t* __thiscall FUN_0060b440(
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
            *pOutStatus = DAT_00af49ac; // Remove (16)
            return pOutStatus;
        }

        CVOGCharacter_ResolveUseObjectPending_Inferred(self->pCharacter, /*commit=*/1);
        CVOGHBBase_RescheduleAfterFire(self, pOutStatus);
        return pOutStatus;
    }

    *pOutStatus = DAT_00af49ac; // Remove (16)
    return pOutStatus;
}

std::uint32_t* __thiscall CVOGHBPendingUseObject_OnHeartBeat_Inferred(
    CVOGHBPendingUseObject* self,
    std::uint32_t* pOutStatus)
{
    return FUN_0060b440(self, pOutStatus);
}
