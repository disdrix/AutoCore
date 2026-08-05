// =============================================================================
// FUN_0074f090  — twin of Gfx_GlobalEffect_OnDeviceReset_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f090
// Address:   0x0074f090  (autoassault.exe, image base 0x400000)
// Body:      46 B (0x2E). Wave W38-W.
// Exactness: Ghidra-name twin; prefer named clean for ports.
// =============================================================================

#include <cstdint>

using VcallStatus = int(__stdcall*)(void* self);

int FUN_0074f090(void* holder /*EAX*/)
{
    void* inner = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(holder) + 0xC);
    if (inner == nullptr) {
        return 0;
    }

    void** vtbl = *reinterpret_cast<void***>(inner);
    auto* fn = reinterpret_cast<VcallStatus>(vtbl[0x118 / sizeof(void*)]);
    int status = fn(inner);

    return (status >= 0) ? 0 : -1;
}
