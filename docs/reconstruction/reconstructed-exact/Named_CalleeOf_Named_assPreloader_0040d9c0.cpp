// =============================================================================
// Named_CalleeOf_Named_assPreloader_0040d9c0
// Alias of OwnedPtrTable_Clear / FUN_0040d9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d9c0
// Address:   0x0040d9c0  (autoassault.exe, image base 0x400000)
// System:    container / resource cleanup
// Generated: 2026-07-29 W18-M dual A/B seal (replaces 2026-07-23 scaffold)
// =============================================================================

// Prefer: reconstructed-exact/OwnedPtrTable_Clear.cpp
// Prefer: reconstructed-exact/FUN_0040d9c0.cpp
// This file kept as xref-seed alias only.

#include <cstdint>

extern "C" void __cdecl operator_delete(void *p);

struct OwnedPtrTable {
  void **data;
  int count;
  void *cached;
  int liveCount;
};

void Named_CalleeOf_Named_assPreloader_0040d9c0(OwnedPtrTable *self)
{
  while (self->liveCount != 0) {
    if (self->liveCount != 0) {
      int n = self->liveCount - 1;
      self->liveCount = n;
      if (n == 0) {
        self->cached = nullptr;
      }
    }
  }

  int i = self->count;
  while (i != 0) {
    void *p = self->data[i - 1];
    --i;
    if (p != nullptr) {
      operator_delete(p);
    }
  }

  if (self->data != nullptr) {
    operator_delete(self->data);
  }
  self->count = 0;
  self->data = nullptr;
}
