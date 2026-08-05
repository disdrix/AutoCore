# Raw capture: CVOGReaction_RandomUnitScalar

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4330` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007a4330` |
| **Canonical name** | `CVOGReaction_RandomUnitScalar` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined * CVOGReaction_RandomUnitScalar(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b009f;
  local_c = ExceptionList;
  if ((DAT_00d20c34 & 1) == 0) {
    DAT_00d20c34 = DAT_00d20c34 | 1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_007a42d0();
    _atexit((_func_4879 *)&LAB_009c30c0);
  }
  ExceptionList = local_c;
  return &DAT_00d20c1c;
}
```
