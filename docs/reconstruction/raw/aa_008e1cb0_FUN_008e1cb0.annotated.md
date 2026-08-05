# Annotated low-level: FUN_008e1cb0

| Field | Value |
|---|---|
| Stable ID | `aa_008e1cb0` |
| VA | `0x008e1cb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008e1cb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008e1cb0(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  
  cVar3 = (**(code **)(*param_1 + 0x3d8))();
  fVar2 = DAT_00a0f704;
  if ((cVar3 != '\0') && (DAT_00d1b6d8 != 0)) {
    fVar1 = (float)param_1[0x189];
    param_1[0x189] = (int)(fVar1 + param_2);
    if (fVar2 < fVar1 + param_2) {
      param_1[0x189] = 0;
      FUN_008e1bb0();
      piVar4 = param_1 + 0x149;
      if (0 < *(short *)(DAT_00d1b6d8 + 0x580)) {
        cVar3 = (**(code **)(*(int *)param_1[0x149] + 0xd8))();
        if (cVar3 == '\0') {
          iVar5 = 0x10;
          do {
            if (*piVar4 != 0) {
              (**(code **)(*(int *)*piVar4 + 0xd4))(1);
              (**(code **)(*(int *)*piVar4 + 0x34c))();
            }
            piVar4 = piVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          FUN_00791f30(param_2);
          return;
        }
LAB_008e1d73:
        FUN_00791f30(param_2);
        return;
      }
      cVar3 = (**(code **)(*(int *)param_1[0x149] + 0xd8))();
      if (cVar3 == '\0') goto LAB_008e1d73;
      iVar5 = 0x10;
      do {
        if (*piVar4 != 0) {
          (**(code **)(*(int *)*piVar4 + 0xd4))(0);
          (**(code **)(*(int *)*piVar4 + 0x34c))();
        }
        piVar4 = piVar4 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      FUN_0092cc60();
    }
    FUN_00791f30(param_2);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
