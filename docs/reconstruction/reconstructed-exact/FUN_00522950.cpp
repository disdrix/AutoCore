// =============================================================================
// FUN_00522950  (twin of Item_PatenteeMatchesCharacterOrEmpty_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00522950
// Address:   0x00522950  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Wave:      MEGA-108 (2026-08-05)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Prefer named clean: Item_PatenteeMatchesCharacterOrEmpty_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <cstring>

// Decompiler-shaped twin (Ghidra names). Named clean is authoritative for ports.

uint32_t /* bool in AL */ __thiscall FUN_00522950(int param_1 /* Character* ECX */,
                                                   int param_2 /* Item* stack */)
{
  char cVar1;
  char *pcVar2;
  int iVar3;

  if (param_2 == 0) {
    return 0;
  }

  pcVar2 = (char *)(param_2 + 0x101);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');

  if (pcVar2 != (char *)(param_2 + 0x102)) {
    // MI this-adjust + vtbl+0x160 → char*
    pcVar2 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) +
                                 0x160))();
    iVar3 = _stricmp((char *)(param_2 + 0x101), pcVar2);
    if (iVar3 != 0) {
      return 0;
    }
  }

  return 1;
}
