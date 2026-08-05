# Annotated low-level: FUN_00897dfb

| Field | Value |
|---|---|
| Stable ID | `aa_00897dfb` |
| VA | `0x00897dfb` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00897dfb`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_00897dfb(void)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBX;
  int *unaff_ESI;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  cVar1 = FUN_0040cf50();
  if ((cVar1 == '\0') && (DAT_00d1b6d8 != 0)) {
    (**(code **)(*(int *)unaff_ESI[unaff_EBX + -0x9aad] + 0x120))(&stack0x0000000c,1,1);
    (**(code **)(*(int *)unaff_ESI[unaff_EBX + -0x9aad] + 0x140))(&stack0x00000008,1);
    uVar7 = 1;
    if ((int *)unaff_ESI[0x157] == (int *)0x0) {
      iVar4 = *unaff_ESI;
      puVar2 = &stack0x00000010;
    }
    else {
      iVar4 = *(int *)unaff_ESI[0x157];
      puVar2 = &stack0x00000008;
    }
    (**(code **)(iVar4 + 0x120))(puVar2,1,1);
    uVar6 = 1;
    if ((int *)unaff_ESI[0x159] == (int *)0x0) {
      puVar5 = &stack0x0000001c;
      piVar3 = (int *)(**(code **)(*unaff_ESI + 0x140))(puVar5,1);
      iVar4 = *piVar3;
    }
    else {
      puVar5 = (undefined1 *)0x1;
      piVar3 = (int *)(**(code **)(*(int *)unaff_ESI[0x159] + 0x120))(&stack0x0000000c,1);
      iVar4 = *piVar3;
      piVar3 = (int *)(**(code **)(*(int *)unaff_ESI[0x159] + 0x140))(&stack0x00000008,1);
      iVar4 = *piVar3 + (iVar4 - (int)puVar2);
    }
    FUN_007fd350(&DAT_00d1a840,puVar5,uVar6,iVar4,uVar7,0);
    return 1;
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
