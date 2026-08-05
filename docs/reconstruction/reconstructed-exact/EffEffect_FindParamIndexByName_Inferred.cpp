// =============================================================================
// EffEffect_FindParamIndexByName_Inferred  (FUN_00752370)
// -----------------------------------------------------------------------------
// Stable ID: aa_00752370
// Address:   0x00752370  (autoassault.exe, image base 0x400000)
// Body:      0x00752370–0x007523cb exclusive (91 B / 0x5b)
// System:    graphics effect parameter index lookup
// Wave:      W38-Q OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler CF + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

// Effect shell: +0 vtbl, +4 refcount, +8 inner resource*
// Inner resource: +0xc param iface*, +0x10 table (stride 8), +0x18 count
// Iface vtbl+0x24: handle = f(iface, 0, nameOrToken)

typedef int(__thiscall* ParamIface_GetByName)(void* self, int unused, const void* nameOrToken);

// __thiscall; RET 0x08
// ECX = effect*; stack = (int* outIndex, const void* nameOrToken)
// Writes *outIndex = table index or -1. No meaningful EAX return.
void __thiscall EffEffect_FindParamIndexByName_Inferred(
    void* effect,
    int32_t* outIndex,
    const void* nameOrToken)
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
                auto* table = *reinterpret_cast<int32_t**>(i8 + 0x10); // entries: dword0=handle
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
