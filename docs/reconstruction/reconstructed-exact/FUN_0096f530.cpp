// =============================================================================
// FUN_0096f530  (twin of RefCountedPtr3Flags_DefaultCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f530
// Address:   0x0096f530–0x0096f53f inclusive (16 B)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W35-G 2026-07-29 (scaffold 2026-07-23 refined)
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// =============================================================================

#include <cstdint>

// Decompiler shows void; EAX = this*
extern "C" void* __fastcall FUN_0096f530(void* self /*ECX*/)
{
  *reinterpret_cast<void**>(self) = nullptr;
  *(reinterpret_cast<uint8_t*>(self) + 4) = 0;
  *(reinterpret_cast<uint8_t*>(self) + 5) = 0;
  *(reinterpret_cast<uint8_t*>(self) + 6) = 0;
  return self;
}
