// =============================================================================
// FUN_005792d0  →  Mission_FormatDialogTokenValue_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005792d0
// Address:   0x005792d0–0x00579584  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 R10-014 (twin of Mission_FormatDialogTokenValue_Inferred.cpp)
// Exactness: Behavior-preserving rewrite. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical clean unit lives at:
//   docs/reconstruction/reconstructed-exact/Mission_FormatDialogTokenValue_Inferred.cpp
// This twin keeps the Ghidra symbol for inventory/tooling joins.
// =============================================================================

#include <cstdint>
#include <cstdio>

extern "C" void *FUN_007a69d0();
extern "C" char *FUN_007a6de0(const char *src, int maxLen);
extern "C" char TFID_EqualsObjectId(void *a, void *b);
extern "C" char CVOGMap_LookupVariable(uint32_t varId, float *outValue, void *mapOrChar);
extern "C" char *Character_GetRaceDisplayName_Inferred(void *character);
extern "C" char *Character_GetClassDisplayName_Inferred(void *character);

// See Mission_FormatDialogTokenValue_Inferred.cpp for full annotated port.
// Control-flow summary sealed R10-014:

uint32_t __thiscall FUN_005792d0(
    int context,
    char *outBuf,
    char *formatOrTokenText,
    uint8_t *tokenDesc,
    float objectOrFloatSlot,
    int *mapOrCharacter)
{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint32_t uVar4;
  char *pcVar5;
  uint32_t uVar6;

  FUN_007a69d0();
  piVar1 = mapOrCharacter;
  switch (*tokenDesc) {
  case 0:
    objectOrFloatSlot = 0.0f;
    if ((mapOrCharacter == nullptr) ||
        (iVar3 = TFID_EqualsObjectId(mapOrCharacter + 0x58,
                                     reinterpret_cast<void *>(context + 0x30)),
         (char)iVar3 == '\0')) {
      cVar2 = CVOGMap_LookupVariable(
          *reinterpret_cast<uint32_t *>(tokenDesc + 4),
          &objectOrFloatSlot, piVar1);
      if (cVar2 == '\0') {
        return 0;
      }
    } else {
      objectOrFloatSlot = *reinterpret_cast<float *>(tokenDesc + 8);
    }
    std::sprintf(outBuf, formatOrTokenText,
                 static_cast<double>(objectOrFloatSlot));
    return 1;

  case 1:
    if (*reinterpret_cast<int *>(&objectOrFloatSlot) != 0) {
      // object pointer reinterprets float slot — decompiler typing artifact
      int obj = *reinterpret_cast<int *>(&objectOrFloatSlot);
      pcVar5 = reinterpret_cast<char *>(
          (**(code **)(*(int *)(*(int *)(*(int *)(obj + 4) + 4) + 4 + obj) +
                       0x160))());
      do {
        cVar2 = *pcVar5;
        *outBuf = cVar2;
        pcVar5 = pcVar5 + 1;
        outBuf = outBuf + 1;
      } while (cVar2 != '\0');
      return 1;
    }
    break;

  case 2:
    if (*reinterpret_cast<int *>(&objectOrFloatSlot) != 0) {
      uVar6 = 0xffffffff;
      uVar4 = reinterpret_cast<uint32_t>(
          Character_GetClassDisplayName_Inferred(
              *reinterpret_cast<void **>(&objectOrFloatSlot)));
      pcVar5 = FUN_007a6de0(reinterpret_cast<char *>(uVar4),
                            static_cast<int>(uVar6));
      do {
        cVar2 = *pcVar5;
        *outBuf = cVar2;
        pcVar5 = pcVar5 + 1;
        outBuf = outBuf + 1;
      } while (cVar2 != '\0');
      return 1;
    }
    break;

  case 3:
    if (*reinterpret_cast<int *>(&objectOrFloatSlot) != 0) {
      uVar6 = 0xffffffff;
      uVar4 = reinterpret_cast<uint32_t>(
          Character_GetRaceDisplayName_Inferred(
              *reinterpret_cast<void **>(&objectOrFloatSlot)));
      pcVar5 = FUN_007a6de0(reinterpret_cast<char *>(uVar4),
                            static_cast<int>(uVar6));
      do {
        cVar2 = *pcVar5;
        *outBuf = cVar2;
        pcVar5 = pcVar5 + 1;
        outBuf = outBuf + 1;
      } while (cVar2 != '\0');
      return 1;
    }
    break;

  case 4:
    if ((mapOrCharacter != nullptr) &&
        (iVar3 = (**(code **)(*mapOrCharacter + 0x210))(), iVar3 != 0)) {
      (**(code **)(*piVar1 + 0x210))(0, 0xffffffff);
      uVar4 = reinterpret_cast<uint32_t>(
          Character_GetRaceDisplayName_Inferred(
              /* result of vtbl+0x210 in ECX path — see named unit */ piVar1));
      pcVar5 = FUN_007a6de0(reinterpret_cast<char *>(uVar4), -1);
      do {
        cVar2 = *pcVar5;
        *outBuf = cVar2;
        pcVar5 = pcVar5 + 1;
        outBuf = outBuf + 1;
      } while (cVar2 != '\0');
      return 1;
    }
    pcVar5 = FUN_007a6de0("!Non-Character Faction not implemented yet!",
                          0xffffffff);
    do {
      cVar2 = *pcVar5;
      *outBuf = cVar2;
      pcVar5 = pcVar5 + 1;
      outBuf = outBuf + 1;
    } while (cVar2 != '\0');
    return 1;

  case 5:
    if (mapOrCharacter != nullptr) {
      iVar3 = (**(code **)(*mapOrCharacter + 0x210))();
      if (iVar3 != 0) {
        iVar3 = (**(code **)(*piVar1 + 0x210))(0);
        uVar6 = 0xffffffff;
        uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 +
                                      iVar3) +
                             0x160))(0xffffffff);
        pcVar5 = FUN_007a6de0(reinterpret_cast<char *>(uVar4),
                              static_cast<int>(uVar6));
        do {
          cVar2 = *pcVar5;
          *outBuf = cVar2;
          pcVar5 = pcVar5 + 1;
          outBuf = outBuf + 1;
        } while (cVar2 != '\0');
        return 1;
      }
      pcVar5 = FUN_007a6de0(
          reinterpret_cast<char *>(piVar1[0x2a] + 0x40), 0xffffffff);
      do {
        cVar2 = *pcVar5;
        *outBuf = cVar2;
        pcVar5 = pcVar5 + 1;
        outBuf = outBuf + 1;
      } while (cVar2 != '\0');
      return 1;
    }
    break;

  case 6:
    if ((mapOrCharacter != nullptr) &&
        (iVar3 = (**(code **)(*mapOrCharacter + 0x210))(), iVar3 != 0)) {
      (**(code **)(*piVar1 + 0x210))(0, 0xffffffff);
      uVar4 = reinterpret_cast<uint32_t>(
          Character_GetClassDisplayName_Inferred(piVar1));
      pcVar5 = FUN_007a6de0(reinterpret_cast<char *>(uVar4), -1);
      do {
        cVar2 = *pcVar5;
        *outBuf = cVar2;
        pcVar5 = pcVar5 + 1;
        outBuf = outBuf + 1;
      } while (cVar2 != '\0');
      return 0; // machine-confirmed: write then fail
    }
    *outBuf = '\0';
  }
  return 0;
}
