# Raw capture: FUN_008b1ed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b1ed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008b1ed0` |
| **Canonical name** | `FUN_008b1ed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_008b1ed0(undefined4 *param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b6543;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a49844;
  param_1[0x13f] = 9;
  param_1[0x140] = 2;
  FUN_008b12d0();
  *(undefined1 *)(param_1 + 0x124) = 0;
  FUN_008b1c80("i_d_map2.xml");
  pvVar1 = operator_new(0x6b0);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0085ba60(pvVar1,1);
  }
  param_1[0x14e] = uVar2;
  ExceptionList = local_c;
  return param_1;
}
```
