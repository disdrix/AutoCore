# Raw capture: FUN_0065eac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065eac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0065eac0` |
| **Canonical name** | `FUN_0065eac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0065eac0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009e728c;
  FUN_0065e6c0(param_2);
  return extraout_ECX;
}
```
