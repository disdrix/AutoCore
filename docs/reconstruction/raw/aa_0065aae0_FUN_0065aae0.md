# Raw capture: FUN_0065aae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065aae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0065aae0` |
| **Canonical name** | `FUN_0065aae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0065aae0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[2];
  *param_1 = &PTR_FUN_009e5ee0;
  *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;
  if (*(short *)((int)puVar1 + 6) == 0) {
    (**(code **)*puVar1)(1);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```
