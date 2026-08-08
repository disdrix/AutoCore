// =============================================================================
// FUN_00402d10  (scaffold twin of StdList_PushBack_Dword_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00402d10
// Address:   0x00402d10–0x00402d41  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list helper
// Generated: 2026-07-23 scaffold; sealed twin 2026-08-05 MEGA-126
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Prefer:    StdList_PushBack_Dword_Inferred.cpp
// Dual:      accept-with-gaps (A+B 2026-08-05)
// =============================================================================

#include <cstdint>

extern "C" void* __stdcall FUN_00418700(void* next, void* prev, const std::uint32_t* pValue);
extern "C" void __thiscall FUN_00404840(void* list, std::uint32_t count);

// READABILITY (sealed CF):
//  - Body size: 50 B (0x00402d10–0x00402d41); RET 4
//  - Control keywords: return×1
//  - Callees: FUN_00418700 (BuyNode 0xC), FUN_00404840 (_Incsize)
//  - Role: std::list push_back of dword payload via pValue*

void __thiscall FUN_00402d10(int param_1 /*list ECX*/, std::uint32_t param_2 /*pValue* stack*/)
{
  int iVar1;
  int iVar2;

  iVar1 = *(int*)(param_1 + 4);
  iVar2 = (int)(std::uintptr_t)FUN_00418700(
      reinterpret_cast<void*>(static_cast<std::uintptr_t>(iVar1)),
      *reinterpret_cast<void**>(static_cast<std::uintptr_t>(iVar1) + 4),
      reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(param_2)));
  FUN_00404840(reinterpret_cast<void*>(static_cast<std::uintptr_t>(param_1)), 1);
  *(int*)(iVar1 + 4) = iVar2;
  **(int**)(iVar2 + 4) = iVar2;
  return;
}
