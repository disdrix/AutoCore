# Annotated low-level: FUN_007fc6c0

| Field | Value |
|---|---|
| Stable ID | `aa_007fc6c0` |
| VA | `0x007fc6c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fc6c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fc6c0(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int unaff_ESI;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  int iStack_40;
  undefined1 *puStack_3c;
  int iStack_38;
  undefined1 *puStack_34;
  int iStack_30;
  int aiStack_20 [2];
  undefined1 auStack_18 [4];
  int iStack_14;
  int iStack_8;
  
  if (*(int *)(unaff_ESI + 0x1144) == 0) {
    return;
  }
  cVar4 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();
  if (cVar4 == '\0') {
    return;
  }
  if (*(int *)(unaff_ESI + 0x1168) == 0) {
    return;
  }
  iStack_30 = 1;
  puStack_34 = auStack_18;
  iStack_38 = 0x7fc70b;
  (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x140))();
  iStack_38 = 1;
  puStack_3c = auStack_18;
  iStack_40 = 0x7fc720;
  iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x1168) + 0x140))();
  iVar2 = *(int *)(iVar5 + 4);
  iStack_40 = 1;
  puStack_44 = auStack_18;
  uStack_48 = 0x7fc73c;
  piVar6 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x1168) + 0x140))();
  iVar7 = *piVar6 + iStack_14;
  iVar5 = iStack_30 + iVar7;
  uStack_48 = 1;
  iStack_38 = iVar7;
  puStack_34 = (undefined1 *)(iVar2 + iStack_8);
  piVar6 = (int *)(**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x140))(aiStack_20);
  puVar3 = puStack_3c;
  if (*piVar6 < iVar5) {
    iStack_40 = iStack_14 - iStack_38;
LAB_007fc782:
    if (iStack_40 < 0) goto LAB_007fc788;
  }
  else {
    if (-1 < iVar7) goto LAB_007fc782;
LAB_007fc788:
    iStack_40 = 0;
  }
  puVar1 = puStack_3c + (int)puStack_34;
  iVar5 = (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x140))(&stack0xffffffd8,1);
  if (*(int *)(iVar5 + 4) < (int)puVar1) {
    puStack_44 = (undefined1 *)(aiStack_20[0] - (int)puStack_3c);
LAB_007fc7c7:
    if (-1 < (int)puStack_44) goto LAB_007fc7d1;
  }
  else if (-1 < (int)puVar3) goto LAB_007fc7c7;
  puStack_44 = (undefined1 *)0x0;
LAB_007fc7d1:
  (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x118))(&uStack_48);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
