# Annotated low-level: FUN_008cc2b0

| Field | Value |
|---|---|
| Stable ID | `aa_008cc2b0` |
| VA | `0x008cc2b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cc2b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008cc2b0(void)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  cVar2 = (**(code **)(*in_EAX + 0x3d8))();
  if (cVar2 != '\0') {
    piVar4 = in_EAX + 0x167;
    piVar5 = &DAT_00d1b6dc;
    do {
      if ((*piVar5 != 0) && (*piVar4 != 0)) {
        iVar1 = *(int *)*piVar4;
        uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(*piVar5 + 4) + 4) + 4 + *piVar5) + 0x160))
                          (1,0);
        (**(code **)(iVar1 + 0x1d8))(uVar3);
        (**(code **)(*(int *)*piVar4 + 0x34c))();
      }
      piVar5 = piVar5 + 1;
      piVar4 = piVar4 + 1;
    } while ((int)piVar5 < 0xd1b70c);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
