# Raw capture: FUN_0069eed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069eed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069eed0` |
| **Canonical name** | `FUN_0069eed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0069eed0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009aaf38;
  local_c = ExceptionList;
  iVar2 = *(int *)(param_1 + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x54;
  }
  if (uVar1 < param_2) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x54;
    }
    ExceptionList = &local_c;
    FUN_0069ead0(*(undefined4 *)(param_1 + 8),param_2 - iVar2,&stack0x00000008);
  }
  else {
    ExceptionList = &local_c;
    if (iVar2 != 0) {
      ExceptionList = &local_c;
      if (param_2 < (uint)((*(int *)(param_1 + 8) - iVar2) / 0x54)) {
        ExceptionList = &local_c;
        FUN_0069ea40(&param_2,param_2 * 0x54 + iVar2,*(int *)(param_1 + 8));
      }
    }
  }
  local_4 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0x0000001c);
  ExceptionList = local_c;
  return;
}
```
