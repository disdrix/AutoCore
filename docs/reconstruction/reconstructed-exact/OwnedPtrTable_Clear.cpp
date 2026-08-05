// =============================================================================
// OwnedPtrTable_Clear  (INFERRED name for FUN_0040d9c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d9c0
// Address:   0x0040d9c0–0x0040da23  (autoassault.exe, image base 0x400000)
// System:    container / resource cleanup
// Generated: 2026-07-29 W18-M dual A/B seal
// =============================================================================

#include <cstdint>

extern "C" void __cdecl operator_delete(void *p);

struct OwnedPtrTable {
  void **data;    // +0x04
  int count;      // +0x08
  void *cached;   // +0x0C
  int liveCount;  // +0x10
};

// Retail: this in ESI. Portable model takes explicit this*.
void OwnedPtrTable_Clear(OwnedPtrTable *self)
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
