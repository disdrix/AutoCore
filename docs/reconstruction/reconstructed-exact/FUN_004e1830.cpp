// =============================================================================
// FUN_004e1830  (scaffold alias → LockedList_TryAdvanceIterator_Loot_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e1830
// Address:   0x004e1830  (autoassault.exe, image base 0x400000)
// Canonical: LockedList_TryAdvanceIterator_Loot_Inferred
//            (see LockedList_TryAdvanceIterator_Loot_Inferred.cpp)
// System:    combat-loot / locked list walk
// Generated: 2026-07-23 scaffold; 2026-07-29 W23-T dual seal refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

using uint32_t = std::uint32_t;

uint32_t __thiscall FUN_004e1830(int param_1, int *param_2, uint32_t *param_3)
{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  BOOL BVar2;
  uint32_t uVar3;

  iVar1 = *param_2;
  if (*(char *)(param_1 + 0x28) != '\0') {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
    BVar2 = TryEnterCriticalSection(lpCriticalSection);
    if (BVar2 != 0) {
      if (*param_2 == 0) {
        if (*(int *)(param_1 + 0x1c) == 0) {
          uVar3 = 0;
        } else {
          uVar3 = *(uint32_t *)(*(int *)(param_1 + 0x1c) + 4);
        }
        *param_3 = uVar3;
        *param_2 = *(int *)(param_1 + 0x1c);
        LeaveCriticalSection(lpCriticalSection);
        return (uint32_t)(*(int *)(param_1 + 0x1c) == 0);
      }
      if (*(int *)(iVar1 + 8) != 0) {
        *param_2 = *(int *)(iVar1 + 8);
        *param_3 = *(uint32_t *)(*(int *)(iVar1 + 8) + 4);
        LeaveCriticalSection(lpCriticalSection);
        return 0;
      }
      *param_2 = 0;
      *param_3 = 0;
      LeaveCriticalSection(lpCriticalSection);
      return 1;
    }
  }
  return 0x80070005;
}
