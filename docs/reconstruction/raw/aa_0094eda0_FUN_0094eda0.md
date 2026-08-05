# Raw capture: FUN_0094eda0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094eda0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094eda0` |
| **Canonical name** | `FUN_0094eda0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0094eda0(undefined4 param_1,char *param_2)

{
  char *_String;
  int iVar1;
  double dVar2;
  float local_8 [2];
  
  _String = strtok((char *)0x0,param_2);
  if (_String != (char *)0x0) {
    iVar1 = 0;
    do {
      dVar2 = atof(_String);
      local_8[iVar1] = (float)dVar2;
      iVar1 = iVar1 + 1;
      _String = strtok((char *)0x0,param_2);
    } while (_String != (char *)0x0);
    if (iVar1 == 2) {
      DAT_00aefa5c = local_8[0];
      DAT_00aefa58 = local_8[1];
    }
  }
  return 1;
}
```
