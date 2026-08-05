# Annotated low-level: FUN_005fcb00

| Field | Value |
|---|---|
| Stable ID | `aa_005fcb00` |
| VA | `0x005fcb00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fcb00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005fcb00(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  
  cVar3 = FUN_004f5560();
  iVar7 = (int)cVar3;
  piVar1 = (int *)(param_3 + 4);
  if ((int)(*(uint *)(param_3 + 0xc) & 0x7fffffff) < iVar7) {
    iVar5 = (*(uint *)(param_3 + 0xc) & 0x7fffffff) * 2;
    if (iVar5 <= iVar7) {
      iVar5 = iVar7;
    }
    FUN_005b3300(piVar1,iVar5,4);
  }
  *(int *)(param_3 + 8) = iVar7;
  cVar3 = FUN_004f5560();
  iVar7 = (int)cVar3;
  piVar2 = (int *)(param_3 + 0x10);
  if ((int)(*(uint *)(param_3 + 0x18) & 0x7fffffff) < iVar7) {
    iVar5 = (*(uint *)(param_3 + 0x18) & 0x7fffffff) * 2;
    if (iVar5 <= iVar7) {
      iVar5 = iVar7;
    }
    FUN_005b3300(piVar2,iVar5,4);
  }
  *(int *)(param_3 + 0x14) = iVar7;
  cVar3 = FUN_004f5560();
  iVar7 = (int)cVar3;
  piVar9 = (int *)(param_3 + 0x20);
  if ((int)(*(uint *)(param_3 + 0x28) & 0x7fffffff) < iVar7) {
    iVar5 = (*(uint *)(param_3 + 0x28) & 0x7fffffff) * 2;
    if (iVar5 <= iVar7) {
      iVar5 = iVar7;
    }
    FUN_005b3300(piVar9,iVar5,1);
  }
  *(int *)(param_3 + 0x24) = iVar7;
  uVar4 = FUN_004f5560();
  *param_3 = uVar4;
  *(undefined4 *)(param_3 + 0x1c) = 0;
  bVar6 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 0xac +
                                     *(int *)(param_1 + 600)) + 0x3c) + 0x4cc);
  uVar8 = 0;
  if ('\0' < (char)bVar6) {
    uVar8 = (uint)bVar6;
    iVar7 = 0;
    param_3 = (undefined1 *)uVar8;
    do {
      *(float *)(*piVar1 + iVar7 * 4) =
           *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c
                              ) + 0x57c) * *(float *)(param_1 + 0x200);
      *(byte *)(iVar7 + *piVar9) =
           *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)
                    + 0x5f0) & 1;
      *(undefined4 *)(*piVar2 + iVar7 * 4) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x58c
            );
      iVar7 = iVar7 + 1;
      param_3 = (undefined1 *)((int)param_3 - 1);
    } while (param_3 != (undefined1 *)0x0);
  }
  cVar3 = FUN_004f5560();
  if ((char)uVar8 < cVar3) {
    do {
      iVar7 = (int)(char)uVar8;
      *(float *)(*piVar1 + iVar7 * 4) =
           *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c
                              ) + 0x580) * *(float *)(param_1 + 0x204);
      bVar6 = (char)uVar8 + 1;
      uVar8 = (uint)bVar6;
      *(byte *)(iVar7 + *piVar9) =
           *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)
                    + 0x5f0) >> 1 & 1;
      *(undefined4 *)(*piVar2 + iVar7 * 4) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x590
            );
      cVar3 = FUN_004f5560();
    } while ((char)bVar6 < cVar3);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
