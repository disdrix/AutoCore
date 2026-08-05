// =============================================================================
// FUN_004fabc0  (canonical: Character_TryEquipItem)
// -----------------------------------------------------------------------------
// Stable ID: aa_004fabc0
// Address:   0x004fabc0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / equip
// Generated: 2026-07-29 W17-E dual (scaffold name kept; prefer Character_TryEquipItem)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// Prefer reconstructed-exact/Character_TryEquipItem.cpp

extern void __fastcall FUN_00512670(int item);
extern char FUN_00514390(void *ctx, int zero);
extern unsigned int FUN_004f6940(void *simpleObj, void *outOpt);
extern unsigned int FUN_004f6840(void *sub, void *outOpt);
extern unsigned int FUN_004f65e0(void *sub, void *outOpt);
extern unsigned int FUN_004f6890(void *sub, void *outOpt);
extern unsigned int FUN_004f67e0(void *sub, void *outOpt);
extern char FUN_004ce5f0(int host);
extern char FUN_004f6560(void);
extern void *__cdecl __RTDynamicCast(void *in, int, void *from, void *to, int);

unsigned int __thiscall FUN_004fabc0(int param_1, int *param_2, unsigned int *param_3)
{
  int iVar1;
  char cVar2;
  void *uVar3;
  unsigned int uVar4;
  int uVar5;

  if (param_2 == (int *)0x0) {
    return 8;
  }
  if (param_3 != (unsigned int *)0x0) {
    *param_3 = 0;
  }
  param_2[0x5f] = param_2[0x5f] | 0x10;
  FUN_00512670((int)param_2);
  if (((unsigned int)param_2[0x5f] >> 0x13 & 1) != 0) {
    return 9;
  }
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0xf6) != '\0')) {
    return 0xf;
  }
  uVar5 = 0;
  uVar3 = (**(void *(**)(int, int))(
      *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0, 1);
  cVar2 = FUN_00514390(uVar3, uVar5);
  if (cVar2 != '\0') {
    switch (*(unsigned int *)(param_2[0x2a] + 0x38)) {
    case 6:
      uVar3 = __RTDynamicCast(param_2, 0, 0, 0, 0);
      uVar4 = FUN_004f6940(uVar3, param_3);
      return uVar4;
    default:
      return 8;
    case 8:
    case 0x32:
      return 0xc;
    case 10:
      uVar3 = (**(void *(**)(void *))(*param_2 + 500))(param_3);
      uVar4 = FUN_004f6840(uVar3, param_3);
      return uVar4;
    case 0xc:
      uVar3 = (**(void *(**)(void *))(*param_2 + 0x1e0))(param_3);
      uVar4 = FUN_004f65e0(uVar3, param_3);
      return uVar4;
    case 0xe:
      goto switchD_004fac7b_caseD_e;
    case 0x10:
      uVar3 = (**(void *(**)(void *))(*param_2 + 0x1f0))(param_3);
      uVar4 = FUN_004f6890(uVar3, param_3);
      return uVar4;
    case 0x1c:
      uVar3 = (**(void *(**)(void *))(*param_2 + 0x1f8))(param_3);
      uVar4 = FUN_004f67e0(uVar3, param_3);
      return uVar4;
    }
  }
  return 6;
switchD_004fac7b_caseD_e:
  cVar2 = FUN_004ce5f0(param_1);
  if (cVar2 == '\0') {
    return 1;
  }
  cVar2 = FUN_004f6560();
  return -(unsigned int)(cVar2 != '\0') & 0xe;
}
