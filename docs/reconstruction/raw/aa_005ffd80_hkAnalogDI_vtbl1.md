# Raw capture: hkAnalogDI_vtbl1

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffd80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffd80` |
| **Canonical name** | `hkAnalogDI_vtbl1` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall hkAnalogDI_vtbl1(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 5) & 0x80) != 0) {
    uVar1 = FUN_005ffc90(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}
```
