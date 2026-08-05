# Raw capture: FUN_004baf50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004baf50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004baf50` |
| **Canonical name** | `FUN_004baf50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004baf50(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(*(undefined1 *)(param_1 + 2),*param_1,param_1[1])
  ;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x1cc))();
    return uVar2;
  }
  return 0;
}
```
