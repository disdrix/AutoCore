// =============================================================================
// CVOGHBPendingUseObject_Stop_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b410
// Address:   0x0060b410 – 0x0060b438  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0060b410
// Named twin of reconstructed-exact/FUN_0060b410.cpp — keep CF identical.
// Dual:      reviews/A_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md
//            reviews/B_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md
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

extern "C" std::uint8_t __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(
    void* character, char commit);

using EndOrDestroyFn = void(__thiscall*)(void* self, int flag_onEnd, int flag_hard);

void __thiscall CVOGHBPendingUseObject_Stop_Inferred(
    CVOGHBPendingUseObject* self,
    char flag_cancel_pending)
{
    if (flag_cancel_pending != '\0' && self->pOwnerObject != nullptr) {
        CVOGCharacter_ResolveUseObjectPending_Inferred(self->pCharacter, /*commit=*/0);
    }

    auto** vt = reinterpret_cast<void**>(self->pVTable);
    auto* endOrDestroy = reinterpret_cast<EndOrDestroyFn>(vt[0x18 / 4]);
    endOrDestroy(self, /*flag_onEnd=*/1, /*flag_hard=*/1);
    return;
}

// Ghidra-symbol twin
void __thiscall FUN_0060b410(CVOGHBPendingUseObject* self, char flag_cancel_pending)
{
    CVOGHBPendingUseObject_Stop_Inferred(self, flag_cancel_pending);
}
