# Raw capture: FUN_0051bdd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bdd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051bdd0` |
| **Canonical name** | `FUN_0051bdd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0051bdd0(int param_1,undefined4 *param_2,void *param_3)

{
  memmove(param_3,(void *)((int)param_3 + 8),(*(int *)(param_1 + 8) - ((int)param_3 + 8) >> 3) * 8);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -8;
  *param_2 = param_3;
  return;
}
```
