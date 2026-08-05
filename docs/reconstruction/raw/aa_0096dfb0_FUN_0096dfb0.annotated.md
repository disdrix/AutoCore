# Annotated low-level: FUN_0096dfb0

| Field | Value |
|---|---|
| Stable ID | `aa_0096dfb0` |
| VA | `0x0096dfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096dfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0096dfb0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  *(undefined4 *)(unaff_EBX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(unaff_EBX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(unaff_EBX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(unaff_EBX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(unaff_EBX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(unaff_EBX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(unaff_EBX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(unaff_EBX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(unaff_EBX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(unaff_EBX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  FUN_00416160(param_1 + 0x30);
  if (param_1 == -0xf0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(param_1 + 0xf4);
  }
  piVar3 = (int *)*piVar3;
  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {
    (**(code **)(*piVar3 + 4))();
  }
  piVar2 = *(int **)(unaff_EBX + 0xf4);
  if (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar2 + 8))();
    }
  }
  *(int **)(unaff_EBX + 0xf4) = piVar3;
  puVar5 = (undefined4 *)(param_1 + 0x100);
  puVar6 = (undefined4 *)(unaff_EBX + 0x100);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined4 *)(unaff_EBX + 0x140) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x144) = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(unaff_EBX + 0x148) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(unaff_EBX + 0x14c) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(unaff_EBX + 0x150) = *(undefined4 *)(param_1 + 0x150);
  *(undefined4 *)(unaff_EBX + 0x154) = *(undefined4 *)(param_1 + 0x154);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
