// =============================================================================
// FUN_005b43b0  (twin of StdList_AllocSentinel_0x30_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b43b0
// Address:   0x005b43b0–0x005b43c9 inclusive (26 B)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W35-G 2026-07-29 (scaffold 2026-07-23 refined)
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// =============================================================================

#include <cstdint>

void* __cdecl operator_new(unsigned int size);

// Decompiler shows void; EAX = allocated sentinel*
extern "C" void* FUN_005b43b0(void)
{
  void* pvVar1 = operator_new(0x30);
  if (pvVar1 != nullptr) {
    *reinterpret_cast<void**>(pvVar1) = pvVar1;
  }
  if (reinterpret_cast<std::uint32_t*>(static_cast<char*>(pvVar1) + 4) != nullptr) {
    *reinterpret_cast<void**>(static_cast<char*>(pvVar1) + 4) = pvVar1;
  }
  return pvVar1;
}
