# Raw capture: FUN_005feb50

| Field | Value |
|---|---|
| **Stable ID** | `aa_005feb50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005feb50` |
| **Canonical name** | `FUN_005feb50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005feb50(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_005cb520(param_2,param_3,param_4);
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + -0x30) = *(undefined4 *)(param_2 + 0xd8);
    *(undefined4 *)(param_1 + -0x2c) = *(undefined4 *)(param_2 + 0xdc);
    *(undefined4 *)(param_1 + -0x28) = *(undefined4 *)(param_2 + 0xe0);
    *(undefined4 *)(param_1 + -0x24) = *(undefined4 *)(param_2 + 0xe4);
    *(undefined4 *)(param_1 + -0x20) = *(undefined4 *)(param_2 + 0xe8);
    FUN_00516720(param_2 + 0xf0);
    *(undefined2 *)(param_1 + -0x14) = *(undefined2 *)(param_2 + 0x154);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1) =
         *(undefined4 *)(param_2 + 0xec);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1) =
         *(undefined4 *)(param_2 + 0xec);
  }
  return;
}
```
