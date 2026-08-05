// Twin: see PoolHost_Acquire0x40_Inferred.cpp
// Stable ID: aa_00986070  VA: 0x00986070  Wave: W33-R
// ABI: EBX = pool host (*DAT_00d1f624); returns EAX = 0x40 obj* or 0.

#include <cstdint>

extern "C" void* PoolHost_Acquire0x40_Inferred(void* pool_host_via_ebx);

extern "C" void* FUN_00986070(void)
{
    return PoolHost_Acquire0x40_Inferred(nullptr);
}
