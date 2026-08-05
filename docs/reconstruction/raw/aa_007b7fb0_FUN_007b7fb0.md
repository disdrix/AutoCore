# Raw capture: FUN_007b7fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b7fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b7fb0` |
| **Canonical name** | `FUN_007b7fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007b7ff3) */

void FUN_007b7fb0(undefined4 param_1)

{
  undefined4 uVar1;
  wchar_t local_100 [128];
  
  uVar1 = (*(code *)PTR_FUN_00af8c9c)();
  FUN_00404b30(param_1,uVar1);
  wcscpy((wchar_t *)&DAT_00d09c78,local_100);
  return;
}
```
