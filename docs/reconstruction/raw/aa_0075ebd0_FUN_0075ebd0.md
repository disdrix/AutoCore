# Raw capture: FUN_0075ebd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075ebd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0075ebd0` |
| **Canonical name** | `FUN_0075ebd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4
FUN_0075ebd0(undefined4 *param_1,byte param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00d1f048;
  bVar1 = 0;
  if ((param_2 & 1) != 0) {
    iVar2 = FUN_0043b800();
    bVar1 = -(iVar2 != 0) & 2;
  }
  if ((param_2 & 4) != 0) {
    iVar3 = *(int *)(iVar3 + 8);
    if (iVar3 == 0x49) {
      iVar3 = 1;
    }
    else if (iVar3 == 0x4b) {
      iVar3 = 8;
    }
    else if (iVar3 == 0x4f) {
      iVar3 = 4;
    }
    else {
      iVar3 = 0;
    }
    bVar1 = bVar1 | -(iVar3 != 0) & 4U;
  }
  if ((param_2 & 2) != 0) {
    bVar1 = bVar1 | 1;
  }
  if (bVar1 != 0) {
    iVar3 = (**(code **)(*(int *)*param_1 + 0xac))
                      ((int *)*param_1,0,0,bVar1,*param_3,param_4,param_5);
    if (iVar3 < 0) {
      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x19d,3,
                     "Clear() Failed");
      return 0xffffffff;
    }
  }
  return 0;
}
```
