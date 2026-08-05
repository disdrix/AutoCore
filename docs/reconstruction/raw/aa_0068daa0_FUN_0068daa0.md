# Raw capture: FUN_0068daa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068daa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068daa0` |
| **Canonical name** | `FUN_0068daa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0068daa0(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_4;
  
  local_4 = 0;
  iVar3 = 0;
  while( true ) {
    if ((*(int *)(param_1 + 0x44) == 0) ||
       ((uint)(*(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x44) >> 4) <= local_4)) {
      iVar3 = *(int *)(param_1 + 0x44);
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x44) = 0;
        *(undefined4 *)(param_1 + 0x48) = 0;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        return;
      }
      iVar4 = *(int *)(param_1 + 0x48);
      while( true ) {
        if (iVar3 == iVar4) {
                    /* WARNING: Subroutine does not return */
          operator_delete(*(void **)(param_1 + 0x44));
        }
        if (*(void **)(iVar3 + 4) != (void *)0x0) break;
        *(undefined4 *)(iVar3 + 4) = 0;
        *(undefined4 *)(iVar3 + 8) = 0;
        *(undefined4 *)(iVar3 + 0xc) = 0;
        iVar3 = iVar3 + 0x10;
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(iVar3 + 4));
    }
    uVar5 = 0;
    while( true ) {
      iVar4 = *(int *)(*(int *)(param_1 + 0x44) + 4 + iVar3);
      if ((iVar4 == 0) ||
         ((uint)(*(int *)(*(int *)(param_1 + 0x44) + iVar3 + 8) - iVar4 >> 2) <= uVar5)) break;
      iVar1 = uVar5 * 4;
      operator_delete__(*(void **)(iVar4 + iVar1));
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x44) + iVar3 + 4) + iVar1) = 0;
    }
    pvVar2 = *(void **)(*(int *)(param_1 + 0x44) + 4 + iVar3);
    iVar4 = *(int *)(param_1 + 0x44) + iVar3;
    if (pvVar2 != (void *)0x0) break;
    local_4 = local_4 + 1;
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    iVar3 = iVar3 + 0x10;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar2);
}
```
