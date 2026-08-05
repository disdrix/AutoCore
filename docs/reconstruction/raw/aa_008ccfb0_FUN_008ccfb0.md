# Raw capture: FUN_008ccfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ccfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ccfb0` |
| **Canonical name** | `FUN_008ccfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008ccfb0(undefined4 param_1)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x578) = param_1;
  FUN_007fdfb0(&DAT_00d1a840,
               "Deleting your character is permanent. Are you sure you want to delete this character?  If so, type DELETE into the box below."
               ,0x4e23,1,1);
  return;
}
```
