# Annotated low-level: CVOGMission_EvalActiveObjectiveInteractState

| Field | Value |
|---|---|
| Stable ID | `aa_004d3ef0` |
| VA | `0x004d3ef0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d3ef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGMission_EvalActiveObjectiveInteractState
   
   For an active mission on the character, check objective requirements against this object.
   Returns:
     4 = active mission (in progress)
     5 = active, target pending (requirements not all met)
     8 = active, target complete (all reqs satisfied → ready for turn-in icon)
     0 = not related / wrong target */

undefined4 CVOGMission_EvalActiveObjectiveInteractState(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int local_8;
  
  piVar7 = *(int **)(param_1 + 0x13c);
  if (*piVar7 != 0) {
    bVar3 = true;
    iVar8 = 0;
    if (*(byte *)(param_1 + 0x130) != 0) {
      do {
        iVar1 = *piVar7;
        iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(param_3 + 0x55c) + 0x10) +
                                 (*(uint *)(*(int *)(param_3 + 0x55c) + 8) & *(uint *)(iVar1 + 0x10)
                                 ) * 4) + 4);
        if (iVar5 == 0) {
LAB_004d3f69:
          local_8 = 0;
        }
        else {
          do {
            if (*(uint *)(iVar1 + 0x10) == *(uint *)(iVar5 + 0x10)) {
              if (iVar5 == 0) goto LAB_004d3f69;
              local_8 = *(int *)(iVar5 + 8);
              goto LAB_004d3f7a;
            }
            iVar5 = *(int *)(iVar5 + 0xc);
          } while (iVar5 != 0);
          local_8 = 0;
        }
LAB_004d3f7a:
        if (local_8 != 0) {
          piVar7 = *(int **)(iVar1 + 0x158);
          if (piVar7 == *(int **)(iVar1 + 0x15c)) goto LAB_004d4016;
          bVar2 = true;
          do {
            iVar8 = (**(code **)(*(int *)*piVar7 + 0x50))();
            if ((iVar8 == 3) &&
               (*(int *)(*piVar7 + 0x18) != *(int *)(*(int *)(param_2 + 0xa8) + 0x34))) {
              bVar3 = false;
            }
            for (iVar8 = *(int *)(*(int *)(*(int *)(*(int *)(param_3 + 0x55c) + 0x10) +
                                          (*(uint *)(*(int *)(param_3 + 0x55c) + 8) &
                                          *(uint *)(iVar1 + 0x10)) * 4) + 4);
                (iVar8 != 0 && (*(uint *)(iVar1 + 0x10) != *(uint *)(iVar8 + 0x10)));
                iVar8 = *(int *)(iVar8 + 0xc)) {
            }
            cVar4 = (**(code **)(*(int *)*piVar7 + 0xc))(param_3,local_8);
            if (cVar4 == '\0') {
              bVar2 = false;
            }
            piVar7 = piVar7 + 1;
          } while (piVar7 != *(int **)(iVar1 + 0x15c));
          if (bVar2) {
LAB_004d4016:
            uVar6 = 8;
          }
          else {
            uVar6 = 5;
          }
          if (!bVar3) {
            return 0;
          }
          return uVar6;
        }
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar8 < (int)(uint)*(byte *)(param_1 + 0x130));
    }
  }
  return 4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
