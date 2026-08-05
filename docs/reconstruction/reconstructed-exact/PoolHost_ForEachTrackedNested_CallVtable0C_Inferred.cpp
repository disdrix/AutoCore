// =============================================================================
// PoolHost_ForEachTrackedNested_CallVtable0C_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00985f40
// Address:   0x00985f40–0x00985f8a inclusive (75 B / 0x4B)
// Module:    autoassault.exe (image base 0x400000)
// System:    client / gfxDevice Device Reset pre-shutdown
// Wave:      W38-AD (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI fixes.
// Bit-for-bit / runtime / diff: OPEN (no Launcher).
// =============================================================================
//
// PURPOSE:
//   Walk PoolHost track vector [+4,+8): for each tracked container, iterate
//   nested object* vector [+8,+0xC) and thiscall vtbl[+0xC] on each object.
//   Sole caller: GfxDevice Device Reset after "Beginning shutdown..." log;
//   EAX = *(GfxDevice+0x73C) (PoolHost / DAT_00d1f624 seed slot).
//
// ABI (bytes):
//   EAX = host*; no stack formals; bare RET (C3); void.
//   Virtual call: ECX=obj; CALL [(*obj)+0xC].
//
// Reject scaffold: Named_CalleeOf_Named_gfxDevice_00985f40
// =============================================================================

#include <cstdint>

using vfn0c_t = void(__thiscall *)(void *self);

void PoolHost_ForEachTrackedNested_CallVtable0C_Inferred(/* EAX */ void *host)
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
      reinterpret_cast<vfn0c_t>(vtbl[3])(obj); // +0xC / index 3
    }
  }
}
