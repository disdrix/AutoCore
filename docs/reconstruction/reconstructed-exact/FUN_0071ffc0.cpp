// =============================================================================
// FUN_0071ffc0 — CSoundManager_EraseNamedRecordByName_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0071ffc0
// Address:   0x0071ffc0  (autoassault.exe, image base 0x400000)
// System:    client audio / CSoundManager
// Generated: 2026-07-29 OWN-ONLY dual W16-L (faithful from live decompile)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual reviews: reviews/A_aa_0071ffc0_CSoundManager_EraseNamedRecordByName_Inferred.md
//               reviews/B_aa_0071ffc0_CSoundManager_EraseNamedRecordByName_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Under manager+0x170 critical section, find first 200-byte record whose
//   leading C-string name case-insensitively matches `name` in either of two
//   dense ranges ([+0x44,+0x48) then [+0x54,+0x58)), erase it via FUN_00480970
//   (tail shift), shrink the corresponding end pointer by 200, unlock, return.
//
// ABI:
//   Stack: char* name; ret 4.
//   Object: ESI = CSoundManager* (not ECX thiscall at this entry).
//
// NOTE: Ghidra emits a 4th push (name) into FUN_00480970; callee uses only 3
//   params (src, end, dest). Caller cleans 0x10 bytes (4 dwords).
// =============================================================================

#include <windows.h>
#include <string.h>

// void FUN_00480970(void *src, void *end, void *dest);  // shift 200-B elements

extern void FUN_00480970(void *src, void *end, void *dest);

// Retail uses ESI as manager; reconstruct as explicit first param for readability
// while preserving control flow. Call sites: keep manager in ESI across call.
void FUN_0071ffc0(char *name)
{
  /* unaff_ESI: manager object supplied in ESI by caller */
  int unaff_ESI; /* placeholder: live binary uses ESI register */
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  char *pcVar2;

  /* The following is register-faithful to decompiler: ESI is the manager. */
  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_ESI + 0x170);
  EnterCriticalSection(lpCriticalSection);

  pcVar2 = *(char **)(unaff_ESI + 0x44);
  if (pcVar2 != *(char **)(unaff_ESI + 0x48)) {
    do {
      iVar1 = _stricmp(pcVar2, name);
      if (iVar1 == 0) {
        FUN_00480970(
            pcVar2 + 200,
            *(void **)(unaff_ESI + 0x48),
            pcVar2);
        *(int *)(unaff_ESI + 0x48) = *(int *)(unaff_ESI + 0x48) + -200;
        LeaveCriticalSection(lpCriticalSection);
        return;
      }
      pcVar2 = pcVar2 + 200;
    } while (pcVar2 != *(char **)(unaff_ESI + 0x48));
  }

  pcVar2 = *(char **)(unaff_ESI + 0x54);
  if (pcVar2 != *(char **)(unaff_ESI + 0x58)) {
    while (iVar1 = _stricmp(pcVar2, name), iVar1 != 0) {
      pcVar2 = pcVar2 + 200;
      if (pcVar2 == *(char **)(unaff_ESI + 0x58)) {
        LeaveCriticalSection(lpCriticalSection);
        return;
      }
    }
    FUN_00480970(
        pcVar2 + 200,
        *(void **)(unaff_ESI + 0x58),
        pcVar2);
    *(int *)(unaff_ESI + 0x58) = *(int *)(unaff_ESI + 0x58) + -200;
  }

  LeaveCriticalSection(lpCriticalSection);
  return;
}
