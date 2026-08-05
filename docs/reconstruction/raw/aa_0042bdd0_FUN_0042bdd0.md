# Raw capture: FUN_0042bdd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042bdd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042bdd0` |
| **Canonical name** | `FUN_0042bdd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0042bdd0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  
  FUN_00784d20(param_2,in_EAX + 0x138,*(int *)(in_EAX + 0x18) + 7U >> 3);
  return;
}
```
