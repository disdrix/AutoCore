# Raw capture: FUN_0055ead0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ead0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0055ead0` |
| **Canonical name** | `FUN_0055ead0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0055ead0(int param_1,int param_2)

{
  if (*(uint *)(param_1 + 0x10c) == (*(uint *)(param_1 + 0x110) & 0x7fffffff)) {
    FUN_005b3370((int *)(param_1 + 0x108),4);
  }
  *(int *)(*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x10c) * 4) = param_2;
  *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;
  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;
  return;
}
```
