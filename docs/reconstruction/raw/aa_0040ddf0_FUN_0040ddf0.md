# Raw capture: FUN_0040ddf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ddf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040ddf0` |
| **Canonical name** | `FUN_0040ddf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_0040ddf0(int param_1)

{
  int iVar1;
  
  iVar1 = (int)*(short *)(param_1 + 0x140);
  if (199 < *(short *)(param_1 + 0x140)) {
    iVar1 = 200;
  }
  return iVar1;
}
```
