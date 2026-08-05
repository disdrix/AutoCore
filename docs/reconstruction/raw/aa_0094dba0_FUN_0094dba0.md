# Raw capture: FUN_0094dba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094dba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094dba0` |
| **Canonical name** | `FUN_0094dba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0094dba0(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *_Str;
  undefined4 local_c;
  undefined1 local_8;
  int local_4;
  
  local_c = 0x9021;
  _Str = strtok((char *)0x0,param_3);
  local_8 = 0;
  if (_Str == (char *)0x0) {
    local_4 = -1;
  }
  else {
    local_4 = atoi(_Str);
  }
  if (*(int *)(param_1 + 0xc7c) != 0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0xc7c) + 8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(param_1 + 0xc7c) + 0x18))(0xffffffff,&local_c,0xc,0);
    }
  }
  return 1;
}
```
