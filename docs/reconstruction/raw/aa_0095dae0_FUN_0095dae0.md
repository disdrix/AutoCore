# Raw capture: FUN_0095dae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0095dae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0095dae0` |
| **Canonical name** | `FUN_0095dae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall
FUN_0095dae0(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 local_40 [12];
  char local_34;
  int local_2c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];
  undefined4 **local_24 [5];
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b1f79;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0044c270(0,0);
  iVar1 = FUN_0076a900();
  if (iVar1 != 0x4e4f4445) {
    if (*(int *)(param_2 + 0x4044) == 0) {
      uVar3 = FUN_00437050(param_4);
      ExceptionList = local_c;
      return uVar3;
    }
    uVar3 = FUN_00768760(param_4);
    ExceptionList = local_c;
    return uVar3;
  }
  stoChunkReader_EnterChunkScope(param_2);
  local_4 = 0;
  if (local_2c != 1) {
    if (local_2c != 2) {
      local_4 = 0xffffffff;
      if (local_34 != '\0') {
        FUN_00769e40();
      }
      ExceptionList = local_c;
      return 0xffffffff;
    }
    FUN_0095d8f0(param_1);
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (*(int *)(param_2 + 0x4044) == 0) {
    FUN_00437050(param_4);
  }
  else {
    FUN_00768760(param_4);
  }
  if (*(int *)(param_2 + 0x4044) == 0) {
    FUN_00436f10();
  }
  else {
    FUN_0076a200();
  }
  if (local_10 < 0x10) {
    local_24[0] = local_24;
  }
  puVar2 = (undefined4 *)FUN_00989e00(local_40,local_24[0]);
  *param_3 = *puVar2;
  local_4 = local_4 & 0xffffff00;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
  local_4 = 0xffffffff;
  if (local_34 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return 0;
}
```
