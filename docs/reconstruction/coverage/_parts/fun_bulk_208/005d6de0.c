void __thiscall FUN_005d6de0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(char *)(param_1 + 0xb2) != '\0') {
    *(undefined1 *)(param_1 + 0xb2) = 0;
    FUN_004fc650(param_2,param_3,param_4,*(undefined1 *)(param_1 + 0xb3));
    *(undefined1 *)(param_1 + 0xb3) = 0;
  }
  return;
}
