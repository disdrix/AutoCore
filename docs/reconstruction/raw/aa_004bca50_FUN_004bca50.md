# Raw capture: FUN_004bca50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bca50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bca50` |
| **Canonical name** | `FUN_004bca50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004bca50(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 != (int *)0x0) && (puVar1 = (undefined4 *)*param_2, puVar1 != (undefined4 *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    if (*(char *)(param_1 + 0x28) == '\0') {
      puVar1[1] = 0;
      FUN_004bc8e0(puVar1);
      (**(code **)*puVar1)(1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    return 0;
  }
  return 0x80070057;
}
```
