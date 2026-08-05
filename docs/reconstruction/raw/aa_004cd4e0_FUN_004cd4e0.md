# Raw capture: FUN_004cd4e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd4e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd4e0` |
| **Canonical name** | `FUN_004cd4e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004cd4e0(int *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,
                          &CVOGHBRecreateObject::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    if (*param_2 != '\0') {
      FUN_005dac00();
    }
    (**(code **)(*param_1 + 0x18))(1,0);
    param_2[1] = '\x01';
    *(undefined1 *)param_1 = 1;
    return 1;
  }
  return 0;
}
```
