// =============================================================================
// Named alias → same body as FUN_0071ffc0
//   (CSoundManager_EraseNamedRecordByName_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0071ffc0
// Address:   0x0071ffc0  (autoassault.exe, image base 0x400000)
// Note: historical xref alias; prefer structural name / FUN_0071ffc0.
// Dual: 2026-07-29 OWN-ONLY W16-L
// =============================================================================

#include <windows.h>
#include <string.h>

extern void FUN_00480970(void *src, void *end, void *dest);

void Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_0071ffc0(char *name)
{
  int unaff_ESI;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  char *pcVar2;

  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_ESI + 0x170);
  EnterCriticalSection(lpCriticalSection);

  pcVar2 = *(char **)(unaff_ESI + 0x44);
  if (pcVar2 != *(char **)(unaff_ESI + 0x48)) {
    do {
      iVar1 = _stricmp(pcVar2, name);
      if (iVar1 == 0) {
        FUN_00480970(pcVar2 + 200, *(void **)(unaff_ESI + 0x48), pcVar2);
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
    FUN_00480970(pcVar2 + 200, *(void **)(unaff_ESI + 0x58), pcVar2);
    *(int *)(unaff_ESI + 0x58) = *(int *)(unaff_ESI + 0x58) + -200;
  }

  LeaveCriticalSection(lpCriticalSection);
  return;
}
