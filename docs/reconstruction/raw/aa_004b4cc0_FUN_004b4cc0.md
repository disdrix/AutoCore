# Raw capture: FUN_004b4cc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b4cc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b4cc0` |
| **Canonical name** | `FUN_004b4cc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004b4cc0(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_1c [12];
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a144b;
  local_c = ExceptionList;
  uVar2 = 0;
  if (*param_1 == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  NxInitCooking(0,0);
  FUN_005c65c0();
  local_4 = 0;
  cVar1 = NxCookClothMesh(param_2,local_1c);
  NxCloseCooking();
  if (cVar1 != '\0') {
    uVar2 = FUN_005c6610(local_10);
    local_4._0_1_ = 1;
    uVar2 = (**(code **)(*(int *)*param_1 + 0x44))(uVar2);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_005c6630();
  }
  local_4 = 0xffffffff;
  FUN_005c65e0();
  ExceptionList = local_c;
  return uVar2;
}
```
