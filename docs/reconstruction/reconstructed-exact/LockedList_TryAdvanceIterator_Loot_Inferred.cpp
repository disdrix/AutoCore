// =============================================================================
// LockedList_TryAdvanceIterator_Loot_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e1830
// Address:   0x004e1830  (autoassault.exe, image base 0x400000)
// Body:      0x004e1830–0x004e18dc (172 bytes); ret 8
// System:    combat-loot / locked list walk
// Generated: 2026-07-29 W23-T dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Thread-safe cursor advance over a critical-section-guarded singly-linked list
//   used by loot / weapon-from-group table walks. Yields one payload per call.
//
// RETURNS:
//   0           — node available (*cursor advanced/seeded, *outPayload = node+4)
//   1           — exhausted or empty start
//   0x80070005  — traversal flag list+0x28 == 0, or TryEnterCriticalSection failed
//
// LAYOUT:
//   list+0x04 CRITICAL_SECTION; list+0x1C head; list+0x28 enable flag (byte)
//   node+0x04 payload; node+0x08 next
//
// TWIN: List_IterateNext / LockedList_TryAdvanceIterator_Inferred @ 0x004022a0
//       (same CF/offsets; that copy installs SEH; this copy does not)
//
// CALLERS: KillLoot_RollTableItems_Inferred 0x0050aa80; FUN_0050a7d0; FUN_004d5c10
// CALLEES: TryEnterCriticalSection, LeaveCriticalSection (Win32 IAT)
// =============================================================================

#include <cstdint>
#include <windows.h>

using uint32_t = std::uint32_t;

uint32_t __thiscall LockedList_TryAdvanceIterator_Loot_Inferred(
    int list,
    int *pCursor,
    uint32_t *pOutPayload)
{
  LPCRITICAL_SECTION lpCriticalSection;
  int iCur;
  BOOL entered;
  uint32_t payload;

  iCur = *pCursor;
  if (*(char *)(list + 0x28) != '\0') {
    lpCriticalSection = (LPCRITICAL_SECTION)(list + 4);
    entered = TryEnterCriticalSection(lpCriticalSection);
    if (entered != 0) {
      if (*pCursor == 0) {
        if (*(int *)(list + 0x1c) == 0) {
          payload = 0;
        } else {
          payload = *(uint32_t *)(*(int *)(list + 0x1c) + 4);
        }
        *pOutPayload = payload;
        *pCursor = *(int *)(list + 0x1c);
        LeaveCriticalSection(lpCriticalSection);
        return (uint32_t)(*(int *)(list + 0x1c) == 0);
      }
      if (*(int *)(iCur + 8) != 0) {
        *pCursor = *(int *)(iCur + 8);
        *pOutPayload = *(uint32_t *)(*(int *)(iCur + 8) + 4);
        LeaveCriticalSection(lpCriticalSection);
        return 0;
      }
      *pCursor = 0;
      *pOutPayload = 0;
      LeaveCriticalSection(lpCriticalSection);
      return 1;
    }
  }
  return 0x80070005;
}
