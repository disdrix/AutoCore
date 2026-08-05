# Annotated low-level: FUN_0073ede0

| Field | Value |
|---|---|
| Stable ID | `aa_0073ede0` |
| VA | `0x0073ede0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0073ede0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_0073ede0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int unaff_EBX;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)0x0;
  if (*(int *)(unaff_EBX + 0xc) != 0) {
    puVar2 = operator_new(0x1c);
    puVar1 = (undefined4 *)0x0;
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      *puVar2 = &PTR_FUN_00aa2f48;
      puVar2[6] = 0;
      puVar1 = puVar2;
    }
    FUN_0073ecf0(*(undefined4 *)(unaff_EBX + 0x18),*(undefined4 *)(unaff_EBX + 8));
    puVar2 = *(undefined4 **)(unaff_EBX + 0xc);
    puVar5 = (undefined4 *)puVar1[3];
    for (uVar3 = *(uint *)(unaff_EBX + 0x14) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar2 = *(undefined4 **)(unaff_EBX + 0x10);
    puVar5 = (undefined4 *)puVar1[4];
    for (uVar3 = *(uint *)(unaff_EBX + 0x14) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  return puVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
