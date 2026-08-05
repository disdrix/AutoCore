# Raw capture: FUN_008ec6d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ec6d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ec6d0` |
| **Canonical name** | `FUN_008ec6d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008ec6d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int in_EAX;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x5ac);
  if (piVar1 != (int *)0x0) {
    piVar1[0x13f] = in_EAX;
    (**(code **)(*piVar1 + 0x444))();
    (**(code **)(*piVar1 + 0x34c))();
    FUN_008ec250(unaff_EDI,param_1,param_2,param_3,param_4);
    (**(code **)(**(int **)(unaff_EDI + 0x5ac) + 0xcc))(1);
    (**(code **)(**(int **)(unaff_EDI + 0x5ac) + 0x34c))();
    (**(code **)(**(int **)(unaff_EDI + 0x5ac) + 0x94))();
    FUN_0092f000();
  }
  return;
}
```
