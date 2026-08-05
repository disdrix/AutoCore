// =============================================================================
// FUN_0060b410 / CVOGHBPendingUseObject_Stop_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b410
// Address:   0x0060b410 – 0x0060b438  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0060b410
// System:    heartbeat / missions-progression (pending use-object aux HB)
// Generated: 2026-07-29 W26-T dual A/B seal (scaffold 2026-07-23 refined)
// Exactness: Behavior-preserving rewrite of decompiler control flow + this-adjust.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md
//            reviews/B_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md
// Related:   CVOGCharacter_ResolveUseObjectPending_Inferred (0x00535ed0);
//            CVOGHBBase_EndOrDestroy (vtbl+0x18); ctor FUN_0060b380; OnHB 0x0060b440
// =============================================================================
//
// PURPOSE:
//   Stop/destroy the pending-use-object heartbeat stored at character+0xca0.
//   Optionally cancel character pending resolve (commit=0) when flag!=0 and
//   owner is linked, then always EndOrDestroy(onEnd=1, hard=1).
//
// ABI: __thiscall ECX=HB aux; stack char flag; void; ret 4.
// =============================================================================

#include <cstdint>

// Subclass of CVOGHBBase, sizeof 0x2c (ctor FUN_0060b380 / vtbl 0x009df668).
struct CVOGHBPendingUseObject {
    void*          pVTable;            // +0x00 → PTR_FUN_009df668
    std::uint32_t  nRefOrFlags;        // +0x04
    int            nPeriodMs;          // +0x08
    int            nPeriodSentinel;    // +0x0C
    int            nPeriodCounter;     // +0x10
    unsigned       dwLastFireTickMs;   // +0x14
    void*          pOwnerObject;       // +0x18
    int            nTypeTag;           // +0x1C  (= 10 from ctor)
    char           cStopped;           // +0x20
    // +0x21 fDormant …
    void*          pSecondaryObject;   // +0x24  (not read here)
    void*          pCharacter;         // +0x28
};

// sealed W25-A: character pending use-object resolve
extern "C" std::uint8_t __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(
    void* character, char commit);

// sealed: vtbl+0x18 dual-flag end (OnEnd + hard/soft tail)
using EndOrDestroyFn = void(__thiscall*)(void* self, int flag_onEnd, int flag_hard);

void __thiscall FUN_0060b410(CVOGHBPendingUseObject* self, char flag_cancel_pending)
{
    if (flag_cancel_pending != '\0' && self->pOwnerObject != nullptr) {
        CVOGCharacter_ResolveUseObjectPending_Inferred(self->pCharacter, /*commit=*/0);
    }

    auto** vt = reinterpret_cast<void**>(self->pVTable);
    auto* endOrDestroy = reinterpret_cast<EndOrDestroyFn>(vt[0x18 / 4]);
    endOrDestroy(self, /*flag_onEnd=*/1, /*flag_hard=*/1);
    return;
}

// Alias for named twin consumers
void __thiscall CVOGHBPendingUseObject_Stop_Inferred(
    CVOGHBPendingUseObject* self, char flag_cancel_pending)
{
    FUN_0060b410(self, flag_cancel_pending);
}
