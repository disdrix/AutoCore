# Raw capture: FUN_0043bcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043bcc0` |
| **Canonical name** | `FUN_0043bcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_0043bcc0(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  
  uVar3 = *(uint *)(unaff_EDI + 0x20);
  uVar5 = FUN_0043b870();
  uVar5 = uVar5 & uVar3;
  if (*(uint *)(unaff_EDI + 0x24) <= uVar5) {
    uVar5 = uVar5 + (-1 - (uVar3 >> 1));
  }
  iVar4 = *(int *)(unaff_EDI + 0x14);
  iVar1 = uVar5 * 4;
  piVar2 = *(int **)(iVar1 + iVar4);
  while ((param_2 == piVar2 &&
         (*(undefined4 *)(iVar1 + iVar4) = **(undefined4 **)(iVar1 + iVar4), uVar5 != 0))) {
    iVar4 = *(int *)(unaff_EDI + 0x14);
    uVar5 = uVar5 - 1;
    iVar1 = uVar5 * 4;
    piVar2 = *(int **)(iVar1 + iVar4);
  }
  if (param_2 == *(int **)(unaff_EDI + 8)) {
    *param_1 = *param_2;
    return param_1;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
                    /* WARNING: Subroutine does not return */
  operator_delete(param_2);
}
```
