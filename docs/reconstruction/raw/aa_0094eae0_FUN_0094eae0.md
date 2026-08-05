# Raw capture: FUN_0094eae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094eae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094eae0` |
| **Canonical name** | `FUN_0094eae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0094eae0(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  
  pcVar1 = strtok((char *)0x0,param_2);
  if (pcVar1 != (char *)0x0) {
    atoi(pcVar1);
    pcVar1 = strtok((char *)0x0,param_2);
    if (pcVar1 != (char *)0x0) {
      atoi(pcVar1);
    }
  }
  return 1;
}
```
