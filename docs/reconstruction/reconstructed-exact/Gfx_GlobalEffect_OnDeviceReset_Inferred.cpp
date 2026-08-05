// =============================================================================
// Gfx_GlobalEffect_OnDeviceReset_Inferred  (aa_0074f090)
// -----------------------------------------------------------------------------
// Address:   0x0074f090  (autoassault.exe, image base 0x400000)
// Body:      0x0074f090–0x0074f0be exclusive (46 B / 0x2E)
// System:    client / Palantir graphics — Global Effect device reset step
// Wave:      W38-W OWN-ONLY dual
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Device-reset rebuild step for the Global Effect holder: if holder[+0xC]
//   (inner iface*) is non-null, call vtbl[+0x118] on it; map status to 0/−1
//   (SETGE then SUB 1). Null inner → 0 (success / no-op).
//
// ABI: EAX = holder*; bare RET; return 0 | 0xFFFFFFFF.
// Sole caller: GfxDevice_Reset (FUN_0075eff0) @ 0x0075f333 with
//   EAX = *(*(EBP+0x760)+4); fail plate "Failed to Reset() device on Global Effect".
// Sibling shutdown: FUN_0074f0c0 (vtbl +0x10c / +0x114).
//
// Ghidra: FUN_0074f090. Reject Named_CalleeOf_Named_gfxDevice_0074f090 as sole name.

#include <cstdint>

using VcallStatus = int(__stdcall*)(void* self);

int Gfx_GlobalEffect_OnDeviceReset_Inferred(void* holder /*EAX*/)
{
    void* inner = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(holder) + 0xC);
    if (inner == nullptr) {
        return 0;
    }

    void** vtbl = *reinterpret_cast<void***>(inner);
    auto* fn = reinterpret_cast<VcallStatus>(vtbl[0x118 / sizeof(void*)]);
    int status = fn(inner);

    // bytes: SETGE DL; SUB EDX,1; MOV EAX,EDX
    return (status >= 0) ? 0 : -1;
}
