// =============================================================================
// FUN_0073e1e0  (twin of EffEffect_CreateAndLoad_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e1e0
// Address:   0x0073e1e0
// Wave:      W38-Q — see EffEffect_CreateAndLoad_Inferred.cpp for plate.
// =============================================================================

#include <cstdint>

extern "C" void* PTR_FUN_00a9f9c4;
extern "C" void* FUN_00457040(void);
extern "C" int32_t __thiscall FUN_007533e0(void* pathOrToken, void* effect, int32_t flag);
extern "C" void __thiscall FUN_0073d830(void* manager, void* effect);

typedef void(__thiscall* Eff_ScalarDeletingDtor)(void* self, int32_t freeFlag);

void* __stdcall FUN_0073e1e0(void* manager, void* pathOrToken, int32_t* outStatus)
{
    void* obj = FUN_00457040();
    auto* o = reinterpret_cast<uint32_t*>(obj);

    if (o != nullptr) {
        o[1] = 0;
        o[2] = 0;
        o[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9f9c4);
        o[3] = 0;
        o[4] = 0;
        o[5] = 0;
        o[6] = 0;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(o) + 0x1c) = 0xffff;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(o) + 0x1e) = 0xffff;
        o[8] = 0;
    }

    int32_t status = FUN_007533e0(pathOrToken, obj, 0);
    *outStatus = status;
    if (status < 0) {
        if (o != nullptr) {
            void** vtbl = *reinterpret_cast<void***>(o);
            reinterpret_cast<Eff_ScalarDeletingDtor>(vtbl[0])(o, 1);
        }
        return nullptr;
    }

    FUN_0073d830(manager, obj);
    return obj;
}
