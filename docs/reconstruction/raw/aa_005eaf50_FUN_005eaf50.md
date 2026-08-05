# Raw capture: FUN_005eaf50

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eaf50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005eaf50` |
| **Canonical name** | `FUN_005eaf50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005eaf50(int param_1,undefined1 *param_2,int param_3,float param_4)

{
  char *pcVar1;
  undefined1 local_21 [29];
  
  pcVar1 = (char *)FUN_00645230(local_21,param_3,param_4);
  if ((*pcVar1 != '\0') &&
     ((ABS(*(float *)(param_1 + 0x38) - *(float *)(param_3 + 0x38)) <= param_4 &&
      ABS(*(float *)(param_1 + 0x34) - *(float *)(param_3 + 0x34)) <= param_4) &&
      ABS(*(float *)(param_1 + 0x30) - *(float *)(param_3 + 0x30)) <= param_4)) {
    *param_2 = 1;
    return;
  }
  *param_2 = 0;
  return;
}
```
