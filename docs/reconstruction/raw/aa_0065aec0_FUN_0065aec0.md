# Raw capture: FUN_0065aec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065aec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0065aec0` |
| **Canonical name** | `FUN_0065aec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_0065aec0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xc0,0x12);
  *param_1 = uVar1;
  FUN_006380d0(uVar1,0xff,0x40);
  param_1[1] = 0;
  param_1[2] = 0xf;
  return param_1;
}
```
