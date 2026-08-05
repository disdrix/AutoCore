# Raw capture: FUN_007abe70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007abe70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007abe70` |
| **Canonical name** | `FUN_007abe70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_007abe70(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0xd8))();
  if (cVar1 != '\0') {
    if (*(char *)((int)param_1 + 0xda) == '\0') {
      if (param_1[0xac] != 0) {
                    /* WARNING: Could not recover jumptable at 0x007abeeb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))();
        return uVar2;
      }
    }
    else {
      cVar1 = (**(code **)(*param_1 + 0x280))
                        ((int)(short)param_3,(int)(short)((uint)param_3 >> 0x10));
      if (cVar1 != '\0') {
        return 1;
      }
      (**(code **)(*param_1 + 800))(0,0,0,0,0,0);
    }
  }
  return 0;
}
```
