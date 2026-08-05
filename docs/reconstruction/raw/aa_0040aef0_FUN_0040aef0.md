# Raw capture: FUN_0040aef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040aef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040aef0` |
| **Canonical name** | `FUN_0040aef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_0040aef0(int *param_1)

{
  int *piVar1;
  int *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009bc5a8;
  local_c = ExceptionList;
  piVar1 = (int *)*unaff_ESI;
  if ((piVar1 != (int *)0x0) &&
     (ExceptionList = &local_c, piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {
    (**(code **)(*piVar1 + 4))();
  }
  *param_1 = *unaff_ESI;
  ExceptionList = local_c;
  return param_1;
}
```
