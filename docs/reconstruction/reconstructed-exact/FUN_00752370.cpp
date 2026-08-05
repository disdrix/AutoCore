// =============================================================================
// FUN_00752370  (twin of EffEffect_FindParamIndexByName_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00752370
// Address:   0x00752370
// Wave:      W38-Q — see EffEffect_FindParamIndexByName_Inferred.cpp for plate.
// =============================================================================

#include <cstdint>

typedef int(__thiscall* ParamIface_GetByName)(void* self, int unused, const void* nameOrToken);

void __thiscall FUN_00752370(void* effect, int32_t* outIndex, const void* nameOrToken)
{
    auto* base = reinterpret_cast<uint8_t*>(effect);
    void* inner = *reinterpret_cast<void**>(base + 8);
    int32_t idx = -1;

    if (inner != nullptr) {
        void* iface = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(inner) + 0xc);
        if (iface != nullptr) {
            void** vtbl = *reinterpret_cast<void***>(iface);
            auto getByName = reinterpret_cast<ParamIface_GetByName>(vtbl[0x24 / 4]);
            int handle = getByName(iface, 0, nameOrToken);
            if (handle != 0) {
                auto* i8 = reinterpret_cast<uint8_t*>(inner);
                int32_t count = *reinterpret_cast<int32_t*>(i8 + 0x18);
                auto* table = *reinterpret_cast<int32_t**>(i8 + 0x10);
                int32_t i = 0;
                if (count > 0) {
                    while (true) {
                        idx = i;
                        if (table[i * 2] == handle) {
                            break;
                        }
                        i = i + 1;
                        if (i >= count) {
                            *outIndex = -1;
                            return;
                        }
                    }
                }
            }
        }
    }
    *outIndex = idx;
}
