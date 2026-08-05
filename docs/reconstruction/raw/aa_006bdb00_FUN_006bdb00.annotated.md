# Annotated low-level: FUN_006bdb00

| Field | Value |
|---|---|
| Stable ID | `aa_006bdb00` |
| VA | `0x006bdb00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bdb00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bdb00(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 8);
  if ((int)(param_4[2] & 0x7fffffffU) < iVar4) {
    iVar5 = (param_4[2] & 0x7fffffffU) * 2;
    if (iVar5 <= iVar4) {
      iVar5 = iVar4;
    }
    FUN_005b3300(param_4,iVar5,2);
  }
  param_4[1] = iVar4;
  iVar4 = *(int *)(param_3 + 8);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 4) + iVar5 * 8);
      if ((*(short *)((int)puVar1 + 6) == 1) || (*(short *)((int)puVar1 + 6) == 2)) {
        *(undefined2 *)(*param_4 + iVar5 * 2) = *(undefined2 *)(param_3 + 8);
        if (*(uint *)(param_3 + 8) == (*(uint *)(param_3 + 0xc) & 0x7fffffff)) {
          FUN_005b3370((int *)(param_3 + 4),8);
        }
        iVar2 = *(int *)(param_3 + 8);
        iVar3 = *(int *)(param_3 + 4);
        *(undefined4 *)(iVar3 + iVar2 * 8) = *puVar1;
        *(undefined4 *)(iVar3 + 4 + iVar2 * 8) = puVar1[1];
        *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 1;
      }
      else {
        *(undefined2 *)(*param_4 + iVar5 * 2) = 0xffff;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 8));
  }
  if (iVar4 < *(int *)(param_3 + 8)) {
    do {
      iVar5 = *(int *)(param_3 + 4) + iVar4 * 8;
      *(undefined2 *)(iVar5 + 2) = *(undefined2 *)(*param_4 + (uint)*(ushort *)(iVar5 + 2) * 2);
      *(undefined2 *)(iVar5 + 4) = *(undefined2 *)(*param_4 + (uint)*(ushort *)(iVar5 + 4) * 2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_3 + 8));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
