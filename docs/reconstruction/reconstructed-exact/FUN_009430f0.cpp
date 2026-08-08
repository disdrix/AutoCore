// =============================================================================
// FUN_009430f0  (clean twin of Client_OnLocalCharacterReady_EnterWorldSetup_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009430f0
// Address:   0x009430f0–0x009432eb  (autoassault.exe, image base 0x400000)
// System:    client enter-world / local character ready
// Generated: 2026-08-05 R10-017 OWN dual
// Exactness: Behavior-preserving; Ghidra symbol retained as twin entry.
// =============================================================================

#include <stdint.h>

extern void FUN_004d9f00(void);
extern void FUN_004962b0(void);
extern void FUN_00923c50(void);
extern void Client_MaybeShowFirstTimeTip(int tipId);
extern void *FUN_00541a80(void);
extern void *CNDHash_LookupByKey(void *hash, uint32_t key);
extern void FUN_009301b0(void);
extern char FUN_0066e9c0(void);
extern int FUN_00941fb0(char *a, char *b, void *client, int mode, char flag);
extern float DAT_00a110d8;
extern float DAT_00aaaccc;
extern uint8_t DAT_00d1ad1c;

// ESI = client host; bare RET; void
void FUN_009430f0(void)
{
  int *piVar1;
  int iVar2;
  char cVar3;
  void *pvVar4;
  int unaff_ESI;
  uint32_t key;

  FUN_004d9f00();
  *(uint8_t *)(*(int *)(*(int *)(unaff_ESI + 0xe04) + 0xe894) + 0x8c) = 1;
  if ((*(int *)(unaff_ESI + 0xe04) != 0) &&
      (*(int *)(*(int *)(unaff_ESI + 0xe04) + 0xe898) != 0)) {
    FUN_004962b0();
  }
  if (*(int *)(unaff_ESI + 0xf38) != 0) {
    FUN_00923c50();
    piVar1 = *(int **)(unaff_ESI + 0xf38);
    if (piVar1[0x31e] != 0) {
      (**(void (**)(void))(*piVar1 + 0x318))();
      (**(void (**)(int, int))(*(int *)piVar1[0x31e] + 0xfc))(0, 0x40000000);
    }
    iVar2 = *(int *)(unaff_ESI + 0xf38);
    *(uint32_t *)(iVar2 + 0xcc4) = 6;
    *(uint8_t *)(iVar2 + 0xa82) = 0;
    (**(void (**)(int))(**(int **)(unaff_ESI + 0xf38) + 0x3c4))(1);
    *(uint8_t *)(*(int *)(unaff_ESI + 0xf38) + 0xa84) = 1;
    if (*(char *)(*(int *)(unaff_ESI + 0xe04) + 0xf5) == '\0') {
      *(float *)(*(int *)(unaff_ESI + 0xf38) + 0x530) = DAT_00a110d8;
    } else {
      *(float *)(*(int *)(unaff_ESI + 0xf38) + 0x530) = DAT_00aaaccc;
    }
    *(uint8_t *)(*(int *)(unaff_ESI + 0xf38) + 0xa83) =
        *(uint8_t *)(unaff_ESI + 0x9d1);
    *(uint8_t *)(unaff_ESI + 0x31d9) = 0;
  }
  iVar2 = *(int *)(unaff_ESI + 0xe04);
  if (((iVar2 != 0) && (*(char *)(iVar2 + 0x100) != '\0')) &&
      (*(char *)(iVar2 + 0xf5) == '\0')) {
    Client_MaybeShowFirstTimeTip(0x19);
    Client_MaybeShowFirstTimeTip(0x17);
    Client_MaybeShowFirstTimeTip(0x31);
    if ((*(uint8_t *)(*(int *)(unaff_ESI + 0xe98) + 0xd36) & 1) == 0) {
      key = *(uint32_t *)(*(int *)(unaff_ESI + 0xe04) + 0xfc);
      pvVar4 = (void *)FUN_00541a80();
      pvVar4 = CNDHash_LookupByKey(pvVar4, key);
      if ((pvVar4 != (void *)0) && (*(int *)((int)pvVar4 + 0x14c) != 0)) {
        Client_MaybeShowFirstTimeTip(0x30);
      }
    }
  }
  FUN_009301b0();
  iVar2 = *(int *)(unaff_ESI + 0xe98);
  if ((iVar2 != 0) &&
      ((*(uint32_t *)(iVar2 + 0xca8) & *(uint32_t *)(iVar2 + 0xcac)) !=
       0xffffffffu)) {
    cVar3 = FUN_0066e9c0();
    if (cVar3 == '\0') {
      FUN_00941fb0((char *)0x00a1419b, (char *)0x00a2cff8, (void *)unaff_ESI, 3,
                   0);
      FUN_00941fb0((char *)0x00a1419b, (char *)0x00a1419b, (void *)unaff_ESI, 1,
                   1);
    }
  }
  if (*(int *)(unaff_ESI + 0x4d0) != 0) {
    *(uint8_t *)(*(int *)(unaff_ESI + 0x4d0) + 4) = 1;
  }
  DAT_00d1ad1c = 0;
  *(uint8_t *)(unaff_ESI + 0xb6) = 0;
  *(uint8_t *)(unaff_ESI + 0xb7) = 1;
  return;
}
