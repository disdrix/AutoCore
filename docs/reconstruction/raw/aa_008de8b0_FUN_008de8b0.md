# Raw capture: FUN_008de8b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008de8b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008de8b0` |
| **Canonical name** | `FUN_008de8b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_008de8b0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b71c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a3ccec;
  param_1[0x13f] = 0xf;
  param_1[0x140] = 1;
  FUN_008dddf0();
  NDUIWindow_ReloadInterface("i_d_esc.xml");
  ExceptionList = local_c;
  return param_1;
}
```
