// =============================================================================
// FUN_00971030 — twin of AssPreloader_PendingRemoveWithSideNotify_Inferred
// Stable ID: aa_00971030  |  Dual W36-D 2026-07-29
// Canonical: docs/reconstruction/reconstructed-exact/AssPreloader_PendingRemoveWithSideNotify_Inferred.cpp
// Body hex (30 B):
//   56578b7c240c8bf1568bcfe8e0faffff5783c61ce8e7d5acff5f5ec20400
// =============================================================================

#include <cstdint>

extern "C" void FUN_00970b20(void* keyHolder /*ECX*/, void* host /*stack*/);
extern "C" uint8_t FUN_0043e630(const int* key /*stack*/, void* container /*ESI*/);

extern "C" void FUN_00971030(void* preloader /*ECX*/, const int* key /*stack*/)
{
  // ECX=key, stack=preloader  → SideHost_PushKeyFlag0
  FUN_00970b20(const_cast<int*>(key), preloader);

  // ESI=preloader+0x1C, stack=key → EraseFirstEqual
  void* pending = reinterpret_cast<uint8_t*>(preloader) + 0x1c;
  (void)FUN_0043e630(key, pending);
  // RET 4
}
