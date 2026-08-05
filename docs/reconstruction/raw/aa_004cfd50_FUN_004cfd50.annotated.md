# Annotated low-level: FUN_004cfd50

| Field | Value |
|---|---|
| Stable ID | `aa_004cfd50` |
| VA | `0x004cfd50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cfd50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004cfd50(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1f5d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("UpdatePhysXPositions");
  piVar5 = *(int **)(*(int *)(param_1 + 0xe4a4) + 8);
  local_4 = 0;
  if (piVar5 != piVar5 + *(int *)(*(int *)(param_1 + 0xe4a4) + 0xc)) {
    do {
      piVar6 = *(int **)(*piVar5 + 0x3c);
      if (piVar6 != piVar6 + *(int *)(*piVar5 + 0x40)) {
        do {
          iVar1 = *(int *)(*piVar6 + 0x34);
          iVar2 = 0;
          if (0 < iVar1) {
            piVar3 = *(int **)(*piVar6 + 0x30);
            piVar4 = piVar3;
            do {
              if (*piVar4 == 1) {
                piVar3 = (int *)piVar3[iVar2 * 2 + 1];
                if (((piVar3 != (int *)0x0) && (((uint)piVar3[0x5f] >> 6 & 1) != 0)) &&
                   (((uint)piVar3[0x5f] >> 5 & 1) != 0)) {
                  piVar3 = (int *)(**(code **)(*piVar3 + 0x1c8))();
                  (**(code **)(*piVar3 + 0x30))();
                }
                break;
              }
              iVar2 = iVar2 + 1;
              piVar4 = piVar4 + 2;
            } while (iVar2 < iVar1);
          }
          piVar6 = piVar6 + 1;
        } while (piVar6 != (int *)(*(int *)(*piVar5 + 0x3c) + *(int *)(*piVar5 + 0x40) * 4));
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 != (int *)(*(int *)(*(int *)(param_1 + 0xe4a4) + 8) +
                              *(int *)(*(int *)(param_1 + 0xe4a4) + 0xc) * 4));
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
