// =============================================================================
// FUN_004ba0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba0a0
// Address:   0x004ba0a0 – 0x004ba26d  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX lifecycle
// Generated: 2026-07-29 W27-D dual seal (decompile + read_memory)
// Exactness: Line-faithful decompiler mirror. Named twin carries role labels.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

using undefined1 = uint8_t;
using undefined4 = uint32_t;

char FUN_004b6a80(void);
void FUN_004b9af0(undefined4 a);
void FUN_004b9270(int host);
void FUN_005b8340(void);
void Client_GetMissionCompleteAudioTable(undefined4 a, undefined4 b, unsigned int c, int d, int e);
void FUN_00723b20(undefined4 a, undefined4 b, unsigned int c, undefined4 d, undefined4 e);
void FUN_00593e10(undefined4 a, char keep);
void FUN_00498a90(void);
void FUN_00498ab0(int zero);

// ECX = fx host; plain ret; AL 0|1
char __fastcall FUN_004ba0a0(int param_1)
{
  int iVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char local_8;
  unsigned int local_4;

  local_8 = '\x01';
  cVar2 = '\x01';
  if (*(char *)(param_1 + 8) != '\0') {
    return '\x01';
  }
  piVar5 = *(int **)(param_1 + 0x10);
  if (piVar5 != (int *)0x0) {
    switch(*(undefined4 *)(param_1 + 0x28)) {
    case 4:
      cVar3 = FUN_004b6a80();
      if (cVar3 != '\0') break;
    case 5:
    case 6:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x14:
    case 0x15:
      if (*(char *)(param_1 + 0xb) != '\0') {
        cVar2 = '\0';
        uVar4 = (*(undefined4(__thiscall **)(int *))(*piVar5 + 0x1cc))(piVar5);
        FUN_004b9af0(uVar4);
        FUN_004b9270(param_1);
        local_8 = '\0';
      }
    }
  }
  *(undefined1 *)(param_1 + 8) = 1;
  piVar5 = (int *)**(int **)(param_1 + 0x1e0);
  if (piVar5 != *(int **)(param_1 + 0x1e0)) {
    do {
      iVar1 = piVar5[2];
      if (cVar2 != '\0') {
        *(undefined1 *)(iVar1 + 0x7f9) = 1;
      }
      FUN_005b8340();
      iVar6 = iVar1 + 0x14;
      do {
        FUN_005b8340();
        iVar6 = *(int *)(iVar6 + 0x2f4);
      } while (iVar6 != iVar1 + 0x14);
      *(undefined4 *)(iVar1 + 4) = 0;
      piVar5 = (int *)*piVar5;
      local_8 = cVar2;
    } while (piVar5 != (int *)*(int *)(param_1 + 0x1e0));
  }
  piVar5 = (int *)**(int **)(param_1 + 0x1ec);
  if (piVar5 != *(int **)(param_1 + 0x1ec)) {
    do {
      if ((*(char *)(piVar5[2] + 0x10b) != '\0') && (iVar1 = *(int *)(param_1 + 0x10), iVar1 != 0)) {
        uVar9 = 0;
        local_4 = (unsigned int)*(uint8_t *)(iVar1 + 0x168);
        uVar4 = *(undefined4 *)(iVar1 + 0x160);
        uVar7 = *(undefined4 *)(iVar1 + 0x164);
        uVar8 = 0;
        Client_GetMissionCompleteAudioTable(uVar4, uVar7, local_4, 0, 0);
        FUN_00723b20(uVar4, uVar7, local_4, uVar8, uVar9);
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(param_1 + 0x1ec));
  }
  piVar5 = (int *)**(int **)(param_1 + 0x204);
  if (piVar5 != *(int **)(param_1 + 0x204)) {
    do {
      FUN_00593e10(*(undefined4 *)(param_1 + 0x2c), cVar2);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(param_1 + 0x204));
  }
  piVar5 = (int *)**(int **)(param_1 + 0x210);
  if (piVar5 != *(int **)(param_1 + 0x210)) {
    do {
      if (local_8 != '\0') {
        *(unsigned int *)(piVar5[2] + 0x178) = *(unsigned int *)(piVar5[2] + 0x178) | 0x100;
      }
      FUN_005b8340();
      *(undefined4 *)piVar5[2] = 0;
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(param_1 + 0x210));
  }
  piVar5 = (int *)**(int **)(param_1 + 0x21c);
  if (piVar5 != *(int **)(param_1 + 0x21c)) {
    do {
      FUN_00498a90();
      FUN_00498ab0(0);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(param_1 + 0x21c));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return local_8;
}
