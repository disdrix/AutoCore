void __thiscall FUN_005d6870(int param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((*(uint *)(param_1 + iVar1 * 4) & 0x7f800000) == 0x7f800000) {
      *param_2 = 0;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  *param_2 = 1;
  return;
}
