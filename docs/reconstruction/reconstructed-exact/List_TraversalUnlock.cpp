// =============================================================================
// List_TraversalUnlock
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c700
// Address:   0x0040c700  (autoassault.exe, image base 0x400000)
// System:    client::list
// Generated: 2026-08-04 WQ9D-E dual A/B (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE
//   Release traversal ownership acquired by List_TraversalLock (0x004294f0):
//   if flag list+0x28 is set, clear it and LeaveCriticalSection(list+4).
//   No-op when already unlocked. Shared by skill status-effect receive,
//   inventory/UI list walkers, and other CS list consumers.
//
// ABI: __fastcall / thiscall — ECX = list*; void; ret
// Body: 0x0040c700–0x0040c715 (21 B)
// Name: List_TraversalUnlock — role High (exact inverse of string-sealed TraversalLock)
// =============================================================================

#include <windows.h>
#include <stdint.h>

void __fastcall List_TraversalUnlock(void *list)
{
  uint8_t *base = (uint8_t *)list;

  if (*(char *)(base + 0x28) != 0) {
    *(uint8_t *)(base + 0x28) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(base + 4));
  }
}
