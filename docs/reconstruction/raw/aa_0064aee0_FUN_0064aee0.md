# Raw capture: FUN_0064aee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064aee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064aee0` |
| **Canonical name** | `FUN_0064aee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_0064aee0(undefined4 *param_1,int *param_2)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009e4958;
  param_1[2] = *param_2;
  FUN_0065d600(*(undefined4 *)(*(int *)(*param_2 + 0xc) + 0xc),param_2[1]);
  FUN_0064ae60(param_2);
  return param_1;
}
```
