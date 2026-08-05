# Raw capture: FUN_005bdea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bdea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bdea0` |
| **Canonical name** | `FUN_005bdea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005bdea0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  if (pvVar2 != *(void **)(param_1 + 4)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  FUN_005bddf0(**(undefined4 **)(param_1 + 4),param_2,param_3,param_3);
  return;
}
```
