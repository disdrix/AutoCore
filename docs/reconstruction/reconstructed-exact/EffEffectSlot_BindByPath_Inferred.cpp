// =============================================================================
// EffEffectSlot_BindByPath_Inferred  (FUN_009701d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_009701d0
// Address:   0x009701d0  (autoassault.exe, image base 0x400000)
// Body:      0x009701d0–0x00970250 exclusive (128 B / 0x80)
// System:    graphics effect/material slot bind (intrusive refcount swap)
// Wave:      W37-Q OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler control flow + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

// Unowned callees (sealed as symbols only).
extern "C" void* FUN_0073e1e0(void* manager, void* pathOrToken, int32_t* outStatus);
extern "C" void* FUN_00965600(void* a, void* pathOrToken, int32_t flag);
extern "C" void __thiscall FUN_00744ea0(void* self, void* msg, int32_t flag);

// Process globals (image).
extern void* DAT_00d1f61c; // effect manager*
extern uint8_t* DAT_00d1f050; // debug host*

typedef void(__thiscall* RefCounted_Vfn)(void* self);

// __thiscall; RET 0x04
// ECX = void** slot holding effect/material object*
// stack = path or interned token (from FUN_00989e00 etc.)
// return: 0xFFFFFFFF on load fail; else load status (>= 0)
int32_t __thiscall EffEffectSlot_BindByPath_Inferred(void** slot, void* pathOrToken)
{
    int32_t status = 0; // stack formal also used as out-status by loader
    void* effect;
    void* old;
    int32_t* pRc;
    void** vtbl;

    // Retail: pathOrToken is the sole stack arg; &status aliases that slot.
    status = reinterpret_cast<int32_t>(pathOrToken); // placeholder for formal
    effect = FUN_0073e1e0(DAT_00d1f61c, pathOrToken, &status);
    if (effect == nullptr) {
        return static_cast<int32_t>(0xFFFFFFFF);
    }

    // AddRef new
    pRc = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(effect) + 4);
    *pRc = *pRc + 1;
    if (*pRc == 1) {
        vtbl = *reinterpret_cast<void***>(effect);
        reinterpret_cast<RefCounted_Vfn>(vtbl[1])(effect); // +4
    }

    // Release old
    old = *slot;
    if (old != nullptr) {
        pRc = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(old) + 4);
        *pRc = *pRc - 1;
        if (*pRc == 0) {
            vtbl = *reinterpret_cast<void***>(old);
            reinterpret_cast<RefCounted_Vfn>(vtbl[2])(old); // +8
        }
    }

    *slot = effect;

    // Optional debug/trace gate
    if (*(reinterpret_cast<char*>(DAT_00d1f050) + 0x68) != 0) {
        void* host = *reinterpret_cast<void**>(DAT_00d1f050 + 0x64);
        void* msg = FUN_00965600(&slot, pathOrToken, 1);
        FUN_00744ea0(host, msg, 1);
    }

    return status;
}
