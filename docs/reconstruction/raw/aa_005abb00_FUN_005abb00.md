# Raw capture: FUN_005abb00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005abb00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005abb00` |
| **Canonical name** | `FUN_005abb00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005abb00(undefined4 *param_1)

{
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a6523;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_009d8da8;
  local_4 = 0;
  FUN_005ac890(local_10,*(undefined4 *)param_1[0x1443],(undefined4 *)param_1[0x1443]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)param_1[0x1443]);
}
```
