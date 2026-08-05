// =============================================================================
// FUN_0040d9c0 / OwnedPtrTable_Clear
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d9c0
// Address:   0x0040d9c0–0x0040da23  (autoassault.exe, image base 0x400000)
// System:    container / resource cleanup
// Generated: 2026-07-29 W18-M dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ESI ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Clear an owned pointer table:
//   1) Spin live counter +0x10 to 0; null cache +0x0C on final tick.
//   2) operator_delete each non-null element [0..count).
//   3) operator_delete the array buffer; zero count and base.
// ABI: this pointer in ESI (not ECX). Plain RET. Callee operator_delete only.

#include <cstdint>

extern "C" void __cdecl operator_delete(void *p);

// ESI = this (custom register thiscall). Modeled with explicit this*.
struct OwnedPtrTable {
  // +0x00 unused by this function
  void **data;           // +0x04
  int count;             // +0x08
  void *cached;          // +0x0C
  int liveCount;         // +0x10
};

void FUN_0040d9c0(OwnedPtrTable *self /* retail: ESI */)
{
  // Phase 1: spin liveCount to 0; clear cached when it hits 0
  while (self->liveCount != 0) {
    if (self->liveCount != 0) {
      int n = self->liveCount - 1;
      self->liveCount = n;
      if (n == 0) {
        self->cached = nullptr;
      }
    }
  }

  // Phase 2: delete elements from the end
  int i = self->count;
  while (i != 0) {
    void *p = self->data[i - 1];
    i = i - 1;
    if (p != nullptr) {
      operator_delete(p); // returns; Ghidra "noreturn" is false
    }
  }

  // Phase 3: free buffer
  if (self->data != nullptr) {
    operator_delete(self->data);
  }
  self->count = 0;
  self->data = nullptr;
}
