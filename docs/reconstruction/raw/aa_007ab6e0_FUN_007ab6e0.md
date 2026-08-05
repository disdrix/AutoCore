# Raw capture: FUN_007ab6e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ab6e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ab6e0` |
| **Canonical name** | `FUN_007ab6e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007ab6e0(int *param_1)

{
  int unaff_ESI;
  int local_10;
  int iStack_c;
  int iStack_8;
  
  (**(code **)(*param_1 + 0x204))(&local_10);
  iStack_8 = param_1[0x5d] + local_10;
  iStack_c = param_1[0x5c] + unaff_ESI;
  (**(code **)(*param_1 + 8))(&iStack_c);
  return;
}
```
