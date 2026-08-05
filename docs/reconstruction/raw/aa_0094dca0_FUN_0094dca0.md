# Raw capture: FUN_0094dca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094dca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094dca0` |
| **Canonical name** | `FUN_0094dca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0094dca0(undefined4 param_1,char *param_2)

{
  char *_String;
  double dVar1;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  _String = strtok((char *)0x0,param_2);
  if (_String != (char *)0x0) {
    dVar1 = atof(_String);
    local_1c = -(float)dVar1;
    local_20 = 0;
    local_18 = 0;
    local_14 = 0;
    FUN_0055df80(&local_20);
  }
  return 1;
}
```
