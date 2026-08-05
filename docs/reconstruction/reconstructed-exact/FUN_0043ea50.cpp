// =============================================================================
// FUN_0043ea50 — alias of PodU32U8_StoreSplit
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ea50
// Address:   0x0043ea50–0x0043ea5f  (autoassault.exe, image base 0x400000)
// Dual:      W32-M 2026-07-29
// Prefer named clean: PodU32U8_StoreSplit.cpp
// =============================================================================

#include <cstdint>

// Retail: EAX=dest; ECX=const uint32_t*; stack=const uint8_t*; RET 0x4.
// Decompiler "thiscall" label is incomplete — dest is EAX, not only ECX.
void FUN_0043ea50(void* dest /*EAX*/,
                  const uint32_t* pU32 /*ECX*/,
                  const uint8_t* pU8 /*stack*/)
{
  *static_cast<uint32_t*>(dest) = *pU32;
  *(static_cast<uint8_t*>(dest) + 4) = *pU8;
}
