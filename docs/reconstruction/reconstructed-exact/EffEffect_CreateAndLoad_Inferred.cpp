// =============================================================================
// EffEffect_CreateAndLoad_Inferred  (FUN_0073e1e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e1e0
// Address:   0x0073e1e0  (autoassault.exe, image base 0x400000)
// Body:      0x0073e1e0–0x0073e257 exclusive (119 B / 0x77)
// System:    graphics effect shell alloc + path load + manager register
// Wave:      W38-Q OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler CF + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

// Process freelist pool head used by FUN_00457040 (EDI = &pool).
extern "C" void* DAT_00d21970;
// Effect vtbl installed on new shells.
extern "C" void* PTR_FUN_00a9f9c4;

// Unowned callees (sealed as symbols only).
// FUN_00457040: freelist pop; EDI = &DAT_00d21970; returns block* (0x30) in EAX.
extern "C" void* FUN_00457040(void);
// thiscall ECX=pathOrToken; stack (effect*, flag); returns status (<0 fail).
extern "C" int32_t __thiscall FUN_007533e0(void* pathOrToken, void* effect, int32_t flag);
// thiscall ECX=manager; stack (effect*).
extern "C" void __thiscall FUN_0073d830(void* manager, void* effect);

typedef void(__thiscall* Eff_ScalarDeletingDtor)(void* self, int32_t freeFlag);

// stdcall; RET 0x0C
// (manager*, pathOrToken, int* outStatus) → effect* or nullptr
void* __stdcall EffEffect_CreateAndLoad_Inferred(
    void* manager,
    void* pathOrToken,
    int32_t* outStatus)
{
    // Retail: mov edi, &DAT_00d21970; call FUN_00457040
    // Emulate by setting EDI before call is not expressible in portable C++;
    // treat as freelist alloc of effect shell (size 0x30).
    void* obj = FUN_00457040();
    auto* o = reinterpret_cast<uint32_t*>(obj);

    if (o != nullptr) {
        o[1] = 0; // +4 refcount
        o[2] = 0; // +8 inner
        o[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9f9c4);
        o[3] = 0;
        o[4] = 0;
        o[5] = 0;
        o[6] = 0;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(o) + 0x1c) = 0xffff;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(o) + 0x1e) = 0xffff;
        o[8] = 0; // +0x20
    }

    // Bytes: ECX = pathOrToken; push flag=0; push obj.
    int32_t status = FUN_007533e0(pathOrToken, obj, 0);
    *outStatus = status;
    if (status < 0) {
        if (o != nullptr) {
            void** vtbl = *reinterpret_cast<void***>(o);
            reinterpret_cast<Eff_ScalarDeletingDtor>(vtbl[0])(o, 1);
        }
        return nullptr;
    }

    // Bytes: ECX = manager; push obj.
    FUN_0073d830(manager, obj);
    return obj;
}
