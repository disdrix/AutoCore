# Raw capture: FUN_0073dff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073dff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0073dff0` |
| **Canonical name** | `FUN_0073dff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0073dff0(int param_1,undefined4 param_2,int param_3)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_48 [28];
  char local_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b084c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x24) == 0) {
    ExceptionList = &local_c;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);
    local_4 = 0;
    FUN_0073d640(param_2);
    uVar1 = FUN_00766250();
    _snprintf(local_2c,0x20,"%u",uVar1);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (param_1 + 0x10),local_2c);
    local_4 = 0xffffffff;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);
  }
  this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
         (param_1 + 0x2c);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
            (this,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  (param_1 + 0x10));
  for (uVar4 = 0;
      (iVar3 = *(int *)(param_3 + 4), iVar3 != 0 &&
      (uVar4 < (uint)(*(int *)(param_3 + 8) - iVar3 >> 2))); uVar4 = uVar4 + 1) {
    pcVar2 = *(char **)(iVar3 + uVar4 * 4);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = PTR_DAT_00afa2bc;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=
              (this,pcVar2);
    uVar1 = FUN_0075d9c0(iVar3 + uVar4 * 4);
    _snprintf(local_2c,0x20,"%u",uVar1);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=
              (this,local_2c);
  }
  for (iVar3 = *(int *)(param_1 + 0x40); iVar3 != 0; iVar3 = iVar3 + -1) {
  }
  ExceptionList = local_c;
  return;
}
```
