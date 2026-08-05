# Raw capture: FUN_008bc2f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bc2f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bc2f0` |
| **Canonical name** | `FUN_008bc2f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008bc2f0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009b67b9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00a4639c;
  local_4 = 1;
  FUN_008bb2c0();
  local_4 = local_4 & 0xffffff00;
  FUN_00411000();
  *param_1 = &PTR_FUN_00a58c6c;
  local_4 = 0xffffffff;
  FUN_00792c20();
  ExceptionList = pvStack_c;
  return;
}
```
