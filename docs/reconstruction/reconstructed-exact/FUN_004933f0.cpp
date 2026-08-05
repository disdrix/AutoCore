// =============================================================================
// FUN_004933f0  (twin of StdList_AllocSentinel_0xC_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004933f0
// Address:   0x004933f0  (autoassault.exe, image base 0x400000)
// Wave:      W32-P 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

void* __cdecl operator_new(unsigned int size);

// Decompiler shows void; EAX = allocated sentinel*
void* FUN_004933f0(void)
{
    void* pvVar1 = operator_new(0x0C);
    if (pvVar1 != nullptr) {
        *reinterpret_cast<void**>(pvVar1) = pvVar1;
    }
    if (reinterpret_cast<std::uint32_t*>(static_cast<int>(reinterpret_cast<std::uintptr_t>(pvVar1)) + 4) !=
        nullptr) {
        *reinterpret_cast<std::uint32_t*>(static_cast<int>(reinterpret_cast<std::uintptr_t>(pvVar1)) + 4) =
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(pvVar1));
    }
    return pvVar1;
}
