# Raw capture: FUN_007fd7a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fd7a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fd7a0` |
| **Canonical name** | `FUN_007fd7a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_007fd7a0(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  if ((in_EAX != -1) && (in_EAX != 0)) {
    piVar1 = (int *)CVOGReaction_ResolveObjectTarget(0,in_EAX,in_EAX >> 0x1f);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x1e4))();
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*piVar1 + 0x1e4))();
        if (*(char *)(iVar2 + 0x1d1) == '=') {
          FUN_007fb690(0,(float)*(int *)(iVar2 + 0x25c),0,"Working..",DAT_00afdef4,DAT_00afdef0,0,0)
          ;
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}
```
