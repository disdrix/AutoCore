# Raw capture: FUN_008cafd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cafd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008cafd0` |
| **Canonical name** | `FUN_008cafd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008cafd0(int param_1)

{
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  *(undefined4 *)(param_1 + 0x4bc) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x508) = 0;
  *(undefined4 *)(param_1 + 0x924) = 0;
  *(undefined4 *)(param_1 + 0x928) = 0;
  *(undefined4 *)(param_1 + 0x92c) = 0;
  *(undefined4 *)(param_1 + 0x930) = 0;
  *(undefined4 *)(param_1 + 0x934) = 0;
  *(undefined4 *)(param_1 + 0x938) = 0;
  *(undefined4 *)(param_1 + 0x93c) = 0;
  *(undefined4 *)(param_1 + 0x940) = 0;
  *(undefined4 *)(param_1 + 0x944) = 0;
  if (*(int **)(param_1 + 0x948) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x948) + 0x458))();
  }
  if (*(int **)(param_1 + 0x94c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x94c) + 0x458))();
  }
  *(undefined4 *)(param_1 + 0x948) = 0;
  *(undefined4 *)(param_1 + 0x94c) = 0;
  *(undefined4 *)(param_1 + 0x950) = 0;
  return;
}
```
