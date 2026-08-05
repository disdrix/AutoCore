# Annotated low-level: FUN_008fbaf0

| Field | Value |
|---|---|
| Stable ID | `aa_008fbaf0` |
| VA | `0x008fbaf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fbaf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008fbaf0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1dc))();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(unaff_ESI + 0x660);
    uVar2 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1dc))(uVar3);
    FUN_00933d60(&DAT_00d1a840,uVar2,uVar3);
  }
  FUN_007fca10();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
