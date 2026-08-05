# Raw capture: FUN_006fb7c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006fb7c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006fb7c0` |
| **Canonical name** | `FUN_006fb7c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
byte __fastcall FUN_006fb7c0(float *param_1)

{
  float *in_EAX;
  
  return (DAT_00bc5638 < ABS(param_1[2] - in_EAX[2])) << 1 |
         (DAT_00bc5634 < ABS(param_1[1] - in_EAX[1])) << 2 |
         (DAT_00bc5630 < ABS(*param_1 - *in_EAX)) * -8 & 0xeU;
}
```
