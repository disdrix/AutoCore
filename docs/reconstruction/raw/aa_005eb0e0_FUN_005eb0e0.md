# Raw capture: FUN_005eb0e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb0e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005eb0e0` |
| **Canonical name** | `FUN_005eb0e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005eb0e0(int param_1,undefined4 param_2)

{
  undefined1 local_30 [44];
  
  FUN_005eb040(param_2);
  (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
            (param_2,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8),local_30);
  FUN_00634450(&stack0xffffffc4);
  return;
}
```
