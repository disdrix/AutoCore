# Raw capture: FUN_006c6af0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c6af0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c6af0` |
| **Canonical name** | `FUN_006c6af0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006c6af0(undefined4 *param_1)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_00a0d3c8;
  param_1[3] = 0x3d4ccccd;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x80000000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0x80000000;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0x80000000;
  return;
}
```
