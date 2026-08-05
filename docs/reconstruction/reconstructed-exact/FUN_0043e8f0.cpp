// =============================================================================
// FUN_0043e8f0  (twin of PodU32U8_StoreByValue)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e8f0
// Address:   0x0043e8f0–0x0043e902  (autoassault.exe, image base 0x400000)
// Dual:      W33-M 2026-07-29
// Canonical: PodU32U8_StoreByValue
// =============================================================================

#include <cstdint>

extern "C" void PodU32U8_StoreSplit(void* dest /*EAX*/,
                                    const uint32_t* pU32 /*ECX*/,
                                    const uint8_t* pU8 /*stack*/);

// Ghidra plate is incomplete (void / no formals). Bytes-faithful twin:
void* FUN_0043e8f0(void* dest /*ESI*/,
                   uint32_t u32_val /*stack*/,
                   uint32_t u8_val /*stack*/)
{
  const uint8_t u8 = static_cast<uint8_t>(u8_val);
  PodU32U8_StoreSplit(dest, &u32_val, &u8);
  return dest;
}
