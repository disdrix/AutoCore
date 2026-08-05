# Annotated low-level: FUN_0057ade0

| Field | Value |
|---|---|
| Stable ID | `aa_0057ade0` |
| VA | `0x0057ade0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0057ade0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0057ade0(int *param_1,int *param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *local_8;
  undefined4 *local_4;
  
  if ((char)param_1[0x7d] == '\0') {
    if (*(char *)((int)param_1 + 0x1f6) == '\0') {
      if (*(char *)((int)param_1 + 0x1f5) == '\0') {
        puVar7 = (undefined4 *)param_1[0x77];
        puVar6 = (undefined4 *)param_1[0x76];
        local_4 = puVar7;
        if (puVar6 != puVar7) {
          do {
            piVar5 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar6,puVar6[1]);
            local_8 = piVar5;
            if (piVar5 != (int *)0x0) {
              if (*(int *)(piVar5[0x2a] + 0x38) == 0x3c) {
                __RTDynamicCast(piVar5,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                &CVOGMapModulePlacement::RTTI_Type_Descriptor,0);
              }
              else if (((char)param_4 == '\0') || (*(int *)(piVar5[0x2a] + 0x38) != 0x36)) {
                cVar1 = (**(code **)(*param_1 + 0x2c4))(piVar5);
                if (cVar1 != '\0') {
                  FUN_00402d10(&local_8);
                }
              }
              else {
                (**(code **)(*piVar5 + 0x1ec))();
                FUN_004294f0();
                local_8 = (int *)0x0;
                iVar3 = FUN_004022a0(&local_8,&param_2);
                while (iVar3 == 0) {
                  if ((param_2 != (int *)0x0) &&
                     (cVar1 = (**(code **)(*param_1 + 0x2c4))(piVar5), cVar1 != '\0')) {
                    FUN_00402d10(&param_2);
                  }
                  iVar3 = FUN_004022a0(&local_8,&param_2);
                }
                FUN_0040c700();
                puVar7 = local_4;
              }
            }
            puVar6 = puVar6 + 2;
          } while (puVar6 != puVar7);
        }
      }
      else if ((param_2 != (int *)0x0) &&
              (cVar1 = (**(code **)(*param_1 + 0x2c4))(param_2), cVar1 != '\0')) {
        FUN_00402d10(&stack0x00000000);
        return;
      }
    }
    else if ((param_2 != (int *)0x0) && (iVar3 = (**(code **)(*param_2 + 0x210))(0), iVar3 != 0)) {
      cVar1 = (**(code **)(*param_1 + 0x2c4))(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);
      if (cVar1 != '\0') {
        param_2 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);
        FUN_00402d10(&param_2);
      }
      if (*(int *)(iVar3 + 0xcb0) != 0) {
        iVar2 = 0;
        do {
          iVar4 = FUN_00574760(iVar2);
          if (((iVar4 != 0) && (iVar3 != iVar4)) &&
             (cVar1 = (**(code **)(*param_1 + 0x2c4))(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4)
             , cVar1 != '\0')) {
            param_2 = (int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);
            FUN_00402d10(&param_2);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 4);
        return;
      }
    }
  }
  else {
    piVar5 = *(int **)(param_1[0x29] + 0xe75c);
    if (piVar5 != *(int **)(param_1[0x29] + 0xe760)) {
      do {
        iVar3 = *piVar5;
        if ((iVar3 != 0) &&
           (cVar1 = (**(code **)(*param_1 + 0x2c4))(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3),
           cVar1 != '\0')) {
          param_4 = *piVar5;
          if (param_4 == 0) {
            param_4 = 0;
          }
          else {
            param_4 = *(int *)(*(int *)(param_4 + 4) + 4) + 4 + param_4;
          }
          iVar3 = *(int *)(param_3 + 4);
          iVar2 = FUN_00418700(iVar3,*(undefined4 *)(iVar3 + 4),&param_4);
          FUN_00404840(1);
          *(int *)(iVar3 + 4) = iVar2;
          **(int **)(iVar2 + 4) = iVar2;
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 != *(int **)(param_1[0x29] + 0xe760));
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
