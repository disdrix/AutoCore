# Annotated low-level: FUN_008ef9f0

| Field | Value |
|---|---|
| Stable ID | `aa_008ef9f0` |
| VA | `0x008ef9f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ef9f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008ef9f0(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = FUN_0040e490(param_1 + 0x16c);
  while (iVar2 != 0) {
    (**(code **)(*param_1 + 0xbc))(iVar2);
    iVar2 = FUN_0040e490(param_1 + 0x16c);
  }
  if (DAT_00d1b6d8 != 0) {
    iVar2 = *(int *)(DAT_00d1b6d8 + 0x534);
    iVar5 = 0;
    if (*(char *)(iVar2 + 0x1d) != '\0') {
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    *(undefined1 *)(iVar2 + 0x1d) = 1;
LAB_008efa60:
    iVar2 = *(int *)(DAT_00d1b6d8 + 0x534);
    if (*(char *)(iVar2 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar5 == 0) {
      iVar5 = *(int *)(iVar2 + 0x14);
      if (iVar5 == 0) goto LAB_008efaa8;
      puVar3 = *(uint **)(iVar5 + 8);
    }
    else {
      iVar5 = *(int *)(iVar5 + 0x14);
      if (iVar5 == 0) {
LAB_008efaa8:
        puVar3 = (uint *)0x0;
      }
      else {
        puVar3 = *(uint **)(iVar5 + 8);
      }
    }
    if (puVar3 != (uint *)0x0) {
      uVar1 = *puVar3;
      iVar2 = FUN_00541a80();
      uVar4 = *(uint *)(iVar2 + 8) & uVar1;
      iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + uVar4 * 4) + 4);
      if (iVar2 == 0) {
LAB_008efae2:
        iVar2 = 0;
      }
      else {
        do {
          if (uVar1 == *(uint *)(iVar2 + 0x10)) {
            if (iVar2 == 0) goto LAB_008efae2;
            iVar2 = *(int *)(iVar2 + 8);
            goto LAB_008efae9;
          }
          iVar2 = *(int *)(iVar2 + 0xc);
        } while (iVar2 != 0);
        iVar2 = 0;
      }
LAB_008efae9:
      if (iVar2 != 0) {
        FUN_008ef7d0(param_1,CONCAT31((int3)(uVar4 >> 8),(char)puVar3[1]));
      }
      goto LAB_008efa60;
    }
    *(undefined1 *)(*(int *)(DAT_00d1b6d8 + 0x534) + 0x1d) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
