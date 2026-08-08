// =============================================================================
// FUN_00416240  (twin of FieldBlock_CopyFrom_ClearFlags0xBC_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00416240
// Address:   0x00416240  (autoassault.exe, image base 0x400000)
// Wave:      WQ9I-H OWN-ONLY dual 2026-08-05
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_00416160(void* dest, const void* src);

extern "C" void* __thiscall FUN_00416240(void* dest, const void* src)
{
  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(dest) + 0xBC) = 0u;
  FUN_00416160(dest, src);
  return dest;
}
