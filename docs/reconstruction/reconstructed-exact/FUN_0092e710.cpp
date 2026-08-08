// =============================================================================
// FUN_0092e710  (twin of Character_FormatLevelRaceClassLine_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0092e710
// Address:   0x0092e710  (autoassault.exe, image base 0x400000)
// Body:      0x0092e710–0x0092e8a7 inclusive (408 B / 0x198)
// System:    missions-progression / character display UI
// Generated: 2026-08-05 R10-016 dual refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical name: Character_FormatLevelRaceClassLine_Inferred
// =============================================================================

// PURPOSE
//  Format "Level <n> <Race> <Class>" into EBX out-buffer; return strlen.
//  See Character_FormatLevelRaceClassLine_Inferred.cpp for full plate + ABI notes.
//
// Embedded strings:
//   - "Level " @ 0x00a2d280
// Separator: DAT_00a2a000 = " \0"

/*
 * Behavioral notes:
 * - Stack character* (cdecl); EBX = char* outBuf; returns int strlen or 0.
 * - Callees: FUN_007a69d0, FUN_007a6de0, _itoa, FUN_00521800, FUN_00521900.
 * - Dualed helpers: Character_GetRaceDisplayName_Inferred / GetClassDisplayName.
 * - Sole caller: FUN_008f97c0 @ 0x008f9806.
 * - Runtime / differential verification: OPEN.
 */

extern "C" void* FUN_007a69d0(void);
extern "C" char* FUN_007a6de0(const char* src, int len);
extern "C" char* _itoa(int value, char* buffer, int radix);
extern "C" char* FUN_00521800(int ignored_decomp_noise);
extern "C" char* FUN_00521900(int ignored_decomp_noise);

// Decompiler-shaped twin (unaff_EBX = out buffer register param).
int FUN_0092e710(int param_1)
{
  char cVar1;
  char* pcVar2;
  char* pcVar3;
  int _Value;
  unsigned uVar4;
  unsigned uVar5;
  unsigned uVar6;
  char* unaff_EBX; // OUT: set by caller in EBX
  char* pcVar7;
  char* pcVar8;
  int _Radix;
  unsigned uVar9;
  char local_c[12];

  // NOTE: unaff_EBX is not a real C local — retail passes out buffer in EBX.
  // Ports must thread the buffer explicitly (see named clean).
  unaff_EBX = unaff_EBX; // keep decompiler shape for inventory twin

  if ((param_1 != 0) && (unaff_EBX != (char*)0x0)) {
    FUN_007a69d0();
    pcVar2 = (char*)FUN_007a6de0("Level ", 0xffffffff);
    pcVar3 = pcVar2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar8 = unaff_EBX + -1;
    do {
      pcVar7 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar2;
    for (uVar5 = (unsigned)((int)pcVar3 - (int)pcVar2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(unsigned*)pcVar8 = *(unsigned*)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = (int)pcVar3 - (int)pcVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    _Radix = 10;
    pcVar3 = local_c;
    _Value = (**(int (**)())(*(int*)(*(int*)(*(int*)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();
    _itoa(_Value, pcVar3, _Radix);
    pcVar3 = local_c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar5 = (unsigned)((int)pcVar3 - (int)local_c);
    pcVar3 = unaff_EBX + -1;
    do {
      pcVar2 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar2 != '\0');
    pcVar2 = local_c;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(unsigned*)pcVar3 = *(unsigned*)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar3 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    pcVar3 = unaff_EBX + -1;
    do {
      pcVar2 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar2 != '\0');
    *(unsigned short*)pcVar3 = 0x0020; // DAT_00a2a000
    uVar9 = 0xffffffff;
    uVar4 = (unsigned)(uintptr_t)FUN_00521800(0xffffffff);
    pcVar2 = (char*)FUN_007a6de0((const char*)(uintptr_t)uVar4, (int)uVar9);
    pcVar3 = pcVar2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar8 = unaff_EBX + -1;
    do {
      pcVar7 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar2;
    for (uVar5 = (unsigned)((int)pcVar3 - (int)pcVar2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(unsigned*)pcVar8 = *(unsigned*)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = (int)pcVar3 - (int)pcVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar3 = unaff_EBX + -1;
    do {
      pcVar2 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar2 != '\0');
    uVar9 = 0xffffffff;
    *(unsigned short*)pcVar3 = 0x0020; // DAT_00a2a000
    uVar4 = (unsigned)(uintptr_t)FUN_00521900(0xffffffff);
    pcVar2 = (char*)FUN_007a6de0((const char*)(uintptr_t)uVar4, (int)uVar9);
    pcVar3 = pcVar2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar8 = unaff_EBX + -1;
    do {
      pcVar7 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar2;
    for (uVar5 = (unsigned)((int)pcVar3 - (int)pcVar2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(unsigned*)pcVar8 = *(unsigned*)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = (int)pcVar3 - (int)pcVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar3 = unaff_EBX + 1;
    do {
      cVar1 = *unaff_EBX;
      unaff_EBX = unaff_EBX + 1;
    } while (cVar1 != '\0');
    return (int)unaff_EBX - (int)pcVar3;
  }
  return 0;
}
