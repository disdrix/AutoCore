// =============================================================================
// FUN_00575350  (named: Object_009d33c4_CompleteDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00575350
// Address:   0x00575350  (autoassault.exe, image base 0x400000)
// System:    object derived complete dtor (vtbl PTR_FUN_009d33c4)
// Generated: 2026-07-29 W28-M (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite. See Object_009d33c4_CompleteDtor.cpp.
// =============================================================================

// PURPOSE: Derived complete dtor; tail-jumps Object shared-base dtor FUN_00518ec0.
// See docs/reconstruction/functions/aa_00575350_Object_009d33c4_CompleteDtor.md

#include <cstdint>

extern "C" void *__cdecl operator_delete(void *p);
extern "C" void __thiscall FUN_00497360(void *list); // StdList_Destroy_FreeHead
extern "C" void __thiscall FUN_00518ec0(void *self);
extern "C" void *PTR_FUN_009d33c4;

void __thiscall FUN_00575350(void *param_1)
{
  auto *self = reinterpret_cast<uint8_t *>(param_1);

  *reinterpret_cast<void **>(self) = &PTR_FUN_009d33c4;

  void *owned = *reinterpret_cast<void **>(self + 0x1EC);
  if (owned) operator_delete(owned);
  *reinterpret_cast<void **>(self + 0x1EC) = nullptr;
  self[0x1F0] = 0;
  self[0x1F1] = 0;

  void *begin = *reinterpret_cast<void **>(self + 0x1F8);
  if (begin) operator_delete(begin);
  *reinterpret_cast<void **>(self + 0x1F8) = nullptr;
  *reinterpret_cast<void **>(self + 0x1FC) = nullptr;
  *reinterpret_cast<void **>(self + 0x200) = nullptr;

  FUN_00497360(self + 0x1DC); // lea ecx,[esi+0x1DC]
  FUN_00518ec0(self);         // image: jmp FUN_00518ec0
}
