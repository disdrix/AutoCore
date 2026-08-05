# Raw capture: FUN_006d3ca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006d3ca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006d3ca0` |
| **Canonical name** | `FUN_006d3ca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_006d3ca0(int *param_1)

{
  undefined1 local_90 [124];
  undefined1 local_14;
  undefined1 local_13;
  
  local_13 = 0;
  local_14 = 0;
  if (param_1[1] == (param_1[2] & 0x7fffffffU)) {
    FUN_005b3370(param_1,0x80);
  }
  param_1[1] = param_1[1] + 1;
  FUN_006d3e80(local_90);
  return param_1[1] * 0x80 + -0x80 + *param_1;
}
```
