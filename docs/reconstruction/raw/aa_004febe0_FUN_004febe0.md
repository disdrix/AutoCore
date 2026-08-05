# Raw capture: FUN_004febe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004febe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004febe0` |
| **Canonical name** | `FUN_004febe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004febe0(int param_1,int param_2)

{
  int *piVar1;
  undefined1 local_18 [4];
  int *local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2d79;
  local_c = ExceptionList;
  if ((param_2 != 0) && (*(int *)(param_1 + 0x2b0) != 0)) {
    ExceptionList = &local_c;
    local_14 = (int *)FUN_0040fb90();
    local_10 = 0;
    local_4 = 0;
    FUN_00572110(0x10,local_18);
    if (local_10 != 0) {
      piVar1 = (int *)*local_14;
      if (piVar1 != local_14) {
        do {
          if (*(uint *)(*(int *)(*(int *)(piVar1[2] + 0xa8) + 0x3c) + 0x3d4) ==
              (uint)*(byte *)(param_2 + 9)) {
            FUN_00403430();
            ExceptionList = local_c;
            return 1;
          }
          piVar1 = (int *)*piVar1;
        } while (piVar1 != local_14);
      }
    }
    FUN_00403430();
  }
  ExceptionList = local_c;
  return 0;
}
```
