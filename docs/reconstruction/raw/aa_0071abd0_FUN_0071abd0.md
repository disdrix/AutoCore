# Raw capture: FUN_0071abd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071abd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071abd0` |
| **Canonical name** | `FUN_0071abd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
FUN_0071abd0(undefined4 *param_1,undefined4 *param_2,uint *param_3,uint param_4)

{
  undefined4 in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 *local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int *local_10;
  code *local_c;
  code *local_8;
  undefined4 local_4;
  
  switch(in_EAX) {
  case 0:
    for (uVar2 = param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    for (uVar2 = param_4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    *param_3 = param_4;
    break;
  case 1:
    iVar1 = FUN_00481db0();
    if (iVar1 == -5) {
      printf("Error: uncompress buffer not large enough.\n");
      return 0xffffffff;
    }
    if (iVar1 == -4) {
      printf("Error: Not enough memory.\n");
      return 0xffffffff;
    }
    if (iVar1 == -3) {
      printf("Error: compressed data is bad!.\n");
      return 0xffffffff;
    }
    break;
  case 2:
    if (((param_2 != (undefined4 *)0x0) && (param_3 != (uint *)0x0)) &&
       (param_1 != (undefined4 *)0x0)) {
      local_4 = 0;
      local_c = FUN_0047f700;
      local_8 = FUN_00481e90;
      local_10 = (int *)FUN_0047f700(0,0xfa74,1);
      if (local_10 != (int *)0x0) {
        *local_10 = (int)&local_30;
        local_10[1] = 10;
        local_10[8] = 0;
        local_10[7] = 0;
        local_10[0x319] = 0;
        local_28 = 0;
        local_24 = 0;
        local_18 = 0;
        local_14 = 0;
        *(undefined1 *)(local_10 + 10) = 0;
        local_10[0x315] = 0;
        local_10[0x314] = 0;
        local_10[0x313] = 0;
        local_10[0xb] = 0;
        local_10[0xc] = 0;
        local_1c = *param_3;
        local_20 = param_2;
        local_2c = param_4;
        local_30 = param_1;
        iVar1 = FUN_004830e0();
        if ((iVar1 != 0) && (iVar1 == 4)) {
          *param_3 = *param_3 - local_1c;
          FUN_00483250();
          return 0;
        }
        FUN_00483250();
        return 0xffffffff;
      }
    }
  case 3:
    return 0xffffffff;
  }
  return 0;
}
```
