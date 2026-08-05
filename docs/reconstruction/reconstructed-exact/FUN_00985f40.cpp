// =============================================================================
// FUN_00985f40  (twin of PoolHost_ForEachTrackedNested_CallVtable0C_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00985f40
// Address:   0x00985f40–0x00985f8a inclusive (75 B / 0x4B)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W38-AD (2026-08-04)
// Exactness: Behavior-preserving rewrite; Ghidra name twin.
// =============================================================================

#include <cstdint>

using vfn0c_t = void(__thiscall *)(void *self);

void FUN_00985f40(/* EAX */ void *host)
{
  auto **end = *reinterpret_cast<void ***>(reinterpret_cast<char *>(host) + 8);
  for (auto **it = *reinterpret_cast<void ***>(reinterpret_cast<char *>(host) + 4);
       it != end;
       ++it) {
    void *container = *it;
    auto **inner_b = *reinterpret_cast<void ***>(reinterpret_cast<char *>(container) + 8);
    if (inner_b == nullptr) {
      continue;
    }
    auto **inner_e = *reinterpret_cast<void ***>(reinterpret_cast<char *>(container) + 0xC);
    if (((reinterpret_cast<char *>(inner_e) - reinterpret_cast<char *>(inner_b)) >> 2) == 0) {
      continue;
    }
    for (auto **q = inner_b; q != inner_e; ++q) {
      void *obj = *q;
      auto **vtbl = *reinterpret_cast<void ***>(obj);
      reinterpret_cast<vfn0c_t>(vtbl[3])(obj);
    }
  }
}
