// =============================================================================
// Phy_CPConnectionPair_ReleaseClear
// -----------------------------------------------------------------------------
// Stable ID: aa_0044adc0
// Address:   0x0044adc0 – 0x0044ae50  (autoassault.exe, image base 0x400000)
// System:    physics-cpconnection
// Twin:      reconstructed-exact/FUN_0044adc0.cpp
// Sibling:   Phy_CPConnection_AssertConnectionPoint @ 0x0044af00
// Callee:    FUN_00437150 @ 0x00437150 (×2)
// Generated: 2026-07-29 W22-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + stdcall ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Release both smart-pointer slots and clear both owner-out slots of a
//   dual CP-connection bind pair. Does not free the pair block itself.

#include <cstdint>

struct RefCountedLike {
    void **vtbl;   // [0]
    int refcount;  // [1] @ +4
};

// FUN_00437150: release helper on a single slot pointer (often already null here).
extern void __stdcall FUN_00437150(int **slot);

struct CPConnectionPair {
    void *ownerOut0;          // +0x00
    RefCountedLike *smartA;   // +0x04
    void *ownerOut1;          // +0x08
    RefCountedLike *smartB;   // +0x0C
};

static void ReleaseSlot(RefCountedLike **slot)
{
    RefCountedLike *obj = *slot;
    if (obj != nullptr) {
        obj->refcount -= 1;
        if (obj->refcount == 0) {
            // vtbl+8 — Release-like
            reinterpret_cast<void(__thiscall *)(RefCountedLike *)>(obj->vtbl[2])(obj);
        }
        *slot = nullptr;
    }
}

void __stdcall Phy_CPConnectionPair_ReleaseClear(CPConnectionPair *pair)
{
    // SEH frame with LAB_009bcaea omitted (same control effects)
    pair->ownerOut1 = nullptr;

    ReleaseSlot(&pair->smartB);

    pair->ownerOut0 = nullptr;

    ReleaseSlot(&pair->smartA);

    FUN_00437150(reinterpret_cast<int **>(&pair->smartB));
    FUN_00437150(reinterpret_cast<int **>(&pair->smartA));
}
