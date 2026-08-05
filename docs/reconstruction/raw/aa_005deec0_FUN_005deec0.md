# Raw capture: FUN_005deec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005deec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005deec0` |
| **Canonical name** | `FUN_005deec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005deec0(undefined4 *param_1,char *param_2)

{
  FILE *pFVar1;
  
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0xffffffff;
  *param_1 = &PTR_FUN_009dbb1c;
  *(undefined1 *)(param_1 + 4) = 1;
  pFVar1 = fopen(param_2,"rb");
  param_1[3] = pFVar1;
  *(bool *)(param_1 + 4) = pFVar1 != (FILE *)0x0;
  return param_1;
}
```
