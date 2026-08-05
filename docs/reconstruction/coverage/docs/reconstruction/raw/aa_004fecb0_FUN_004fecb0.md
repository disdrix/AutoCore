# Raw capture: FUN_004fecb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fecb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fecb0` |
| **Canonical name** | `FUN_004fecb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004fecb0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x3ac) != 0) {
    uVar5 = 0;
    while( true ) {
      iVar1 = *(int *)(param_1 + 0x3ac);
      iVar2 = *(int *)(iVar1 + 4);
      if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 8) - iVar2 >> 2) <= uVar5)) break;
      if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 8) - iVar2 >> 2) <= uVar5)) {
        FUN_005062a0();
        return;
      }
      puVar3 = *(undefined4 **)(iVar2 + uVar5 * 4);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      uVar5 = uVar5 + 1;
    }
  }
  pvVar4 = *(void **)(param_1 + 0x3ac);
  if (pvVar4 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x3ac) = 0;
    return;
  }
  if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)((int)pvVar4 + 4));
  }
  *(undefined4 *)((int)pvVar4 + 4) = 0;
  *(undefined4 *)((int)pvVar4 + 8) = 0;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar4);
}
```
