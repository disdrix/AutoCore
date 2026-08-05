# Raw capture: FUN_007aac60

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aac60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aac60` |
| **Canonical name** | `FUN_007aac60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007aac60(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = &DAT_00d1e7e0;
  do {
    piVar2 = (int *)*piVar3;
    if (piVar2 != (int *)0x0) {
      piVar1 = piVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 8))();
      }
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0xd1e818);
  return;
}
```
