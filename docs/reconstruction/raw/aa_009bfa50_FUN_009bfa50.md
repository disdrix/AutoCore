# Raw capture: FUN_009bfa50

| Field | Value |
|---|---|
| **Stable ID** | `aa_009bfa50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009bfa50` |
| **Canonical name** | `FUN_009bfa50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009bfa50(void)

{
  BOOL BVar1;
  LARGE_INTEGER local_8;
  
  BVar1 = QueryPerformanceFrequency(&local_8);
  DAT_00d1eaa0 = BVar1 != 0;
  _DAT_00d1ea98 = _DAT_00aaa658 / (double)(longlong)local_8;
  return;
}
```
