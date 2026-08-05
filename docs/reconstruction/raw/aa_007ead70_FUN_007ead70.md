# Raw capture: FUN_007ead70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ead70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ead70` |
| **Canonical name** | `FUN_007ead70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall
FUN_007ead70(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009b0c63;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return -0x7fffbffc;
  }
  if (DAT_00d1793c == '\0') {
    ExceptionList = &local_c;
    iVar1 = FUN_007e1fb0(param_2,param_3,param_5);
    if (iVar1 < 0) {
      ExceptionList = local_c;
      return iVar1;
    }
    param_5 = *param_4;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_4 = 0;
    FUN_004230d0(&local_24,&param_5);
    iVar1 = FUN_00422fb0(1,1,4);
    if ((((iVar1 < 0) || (iVar1 = FUN_00422fb0(1,2,4), iVar1 < 0)) ||
        (iVar1 = FUN_00422fb0(1,3,2), iVar1 < 0)) ||
       ((iVar1 = FUN_00422fb0(1,4,2), iVar1 < 0 ||
        (iVar1 = FUN_0041b670(&local_24,param_1 + 0x28,0,0,&DAT_00a140c8,0,0), iVar1 < 0)))) {
      FUN_00423170();
      FUN_007a4480(1,"DBReader: %u against %s",iVar1,"dcEngine_Insert::Open");
    }
    else {
      FUN_00423170();
    }
    local_4 = 0xffffffff;
    FUN_0041a4b0(&local_24);
  }
  ExceptionList = local_c;
  return 0;
}
```
