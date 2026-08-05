# Raw capture: FUN_008bfb30

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bfb30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bfb30` |
| **Canonical name** | `FUN_008bfb30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_008bfb30(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1[0x156] != 0) {
    cVar1 = (**(code **)(*(int *)param_1[0x156] + 0xd8))();
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*(int *)param_1[0x156] + 0xd0))();
      if (cVar1 != '\0') {
        if (0 < (short)((uint)param_2 >> 0x10)) {
          (**(code **)(*(int *)param_1[0x156] + 0x45c))(0xbf800000);
          return 1;
        }
        (**(code **)(*(int *)param_1[0x156] + 0x45c))(0x3f800000);
        return 1;
      }
    }
  }
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {
                    /* WARNING: Could not recover jumptable at 0x008bfbb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))();
    return uVar2;
  }
  return 0;
}
```
