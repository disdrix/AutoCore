# Raw capture: FUN_005dec90

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dec90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dec90` |
| **Canonical name** | `FUN_005dec90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005dec90(void)

{
  undefined4 uVar1;
  
  if (DAT_00bc56a5 == '\x01') {
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))("---------------------------\n");
    FUN_00631f10(uVar1);
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))(" Havok - Build (%d)\n",0x131cb47);
    FUN_00631f10(uVar1);
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))(" Base system initialized.   \n");
    FUN_00631f10(uVar1);
    uVar1 = (**(code **)(*DAT_00d030e0 + 4))("----------------------------\n");
    FUN_00631f10(uVar1);
    (**(code **)(*DAT_00d030e0 + 4))();
    FUN_00631f70();
    return;
  }
  return;
}
```
