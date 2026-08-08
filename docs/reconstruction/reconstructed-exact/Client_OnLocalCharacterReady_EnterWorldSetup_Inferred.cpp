// =============================================================================
// Client_OnLocalCharacterReady_EnterWorldSetup_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009430f0
// Address:   0x009430f0–0x009432eb  (autoassault.exe, image base 0x400000)
// Size:      508 B (0x1FC)
// System:    client enter-world / local character ready
//            (R10 partition tag: skills-abilities residual of dualed parent 0x00942e20)
// Generated: 2026-08-05 R10-017 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly ABI fixes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_009430f0
// Hash:      1ad832af581bdcc60c4b4a75caf7bcfa85e02bf1830345b6fdc33c2df2316299
// =============================================================================

// PURPOSE:
//   Client-side "local character is ready / enter world" setup called after
//   extended CreateCharacter success for the local player, and from the client
//   message dispatcher (FUN_00946c00) on switch case 3 and queue type 0x1e.
//   Stages: world-root scan → env flag → camera mode 6 + zoom float → first-time
//   tips → UI panel refresh → optional "//rejoinchat" → session flags.
//
// ABI (sealed):
//   ESI = ClientHost* (register host; callers MOV ESI, client before CALL)
//   no stack arguments; bare RET (C3); void
//
// KEY OFFSETS (client host ESI):
//   +0xe04  worldRoot*
//   +0xf38  camera/controller*
//   +0xe98  local character object*
//   +0xdec  chat/channel service*
//   +0x4d0  optional sub-object*
//   +0x9d1  u8 copied to camera+0xa83
//   +0xb6 / +0xb7  session flags (clear / set)
//   +0x31d9 u8 cleared during camera setup
//
// KEY OFFSETS (worldRoot):
//   +0xe894 env*; env+0x8c = 1
//   +0xe898 optional gate object*
//   +0xf5   selects camera zoom 10.0f vs ~6.7f
//   +0x100  enables first-time tips
//   +0xfc   ND hash key for tip 0x30
//
// CONSTANTS:
//   DAT_00a110d8 = 10.0f; DAT_00aaaccc ≈ 6.7f
//   tip ids: 0x19, 0x17, 0x31, 0x30
//   string: "//rejoinchat" @ 0x00a2cff8

#include <stdint.h>

// External callees (Ghidra names; undualed unless noted)
extern void FUN_004d9f00(void /* ECX=worldRoot */);
extern void FUN_004962b0(void /* ECX=obj */);
extern void FUN_00923c50(void /* EAX=cam */);
extern void Client_MaybeShowFirstTimeTip(int tipId /* ECX=client */);
extern void *FUN_00541a80(void);
extern void *CNDHash_LookupByKey(void *hash, uint32_t key);
extern void FUN_009301b0(void /* EAX=client */);
extern char FUN_0066e9c0(void /* ECX=service */);
extern int FUN_00941fb0(char *a, char *b, void *client, int mode, char flag);

// Globals
extern float DAT_00a110d8;   // 10.0f
extern float DAT_00aaaccc;   // ~6.7f
extern uint8_t DAT_00d1ad1c;

// Register host: ESI = client (not expressible portably; documented in plate).
void Client_OnLocalCharacterReady_EnterWorldSetup_Inferred(void)
{
  int *piVar1;
  int iVar2;
  char cVar3;
  void *pvVar4;
  int unaff_ESI; /* = client host in ESI */
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
      *(float *)(*(int *)(unaff_ESI + 0xf38) + 0x530) = DAT_00a110d8; /* 10.0f */
    } else {
      *(float *)(*(int *)(unaff_ESI + 0xf38) + 0x530) = DAT_00aaaccc; /* ~6.7f */
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
      /* assembly: ECX=0xa1419b, EDX="//rejoinchat", PUSH client/mode/flag */
      FUN_00941fb0((char *)0x00a1419b, (char *)0x00a2cff8 /*"//rejoinchat"*/,
                   (void *)unaff_ESI, 3, 0);
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
