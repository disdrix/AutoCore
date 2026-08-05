# Annotated low-level: FUN_008ca6c0

| Field | Value |
|---|---|
| Stable ID | `aa_008ca6c0` |
| VA | `0x008ca6c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ca6c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008ca6c0(void)

{
  int in_EAX;
  int iVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  float fVar5;
  int iStack_4;
  
  if (*(int *)(in_EAX + 0x948) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x948) + 0x458))();
    iVar1 = 0;
    if (0 < *(int *)(in_EAX + 0x558)) {
      iVar3 = in_EAX + 0x56c;
      do {
        (**(code **)(**(int **)(in_EAX + 0x948) + 0x45c))
                  (iVar3 + 8,*(int *)(iVar3 + -8),*(int *)(iVar3 + -8) >> 0x1f,1);
        (**(code **)(**(int **)(in_EAX + 0x948) + 0x464))
                  (*(int *)(iVar3 + -8),*(int *)(iVar3 + -8) >> 0x1f,1,&stack0xffffffe8);
        iVar1 = iVar1 + 1;
        iVar3 = iVar3 + 0x3c;
      } while (iVar1 < *(int *)(in_EAX + 0x558));
    }
  }
  if (*(int *)(in_EAX + 0x94c) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x94c) + 0x458))();
    iStack_4 = 0;
    if (0 < *(int *)(in_EAX + 0x558)) {
      piVar4 = (int *)(in_EAX + 0x570);
      do {
        fVar5 = (float)*(ushort *)(piVar4 + -1) / (float)*piVar4;
        if (g_flMultiKillCountBlend <= fVar5) {
          if (DAT_00aaa6c0 <= fVar5) {
            if (DAT_00aaa6bc <= fVar5) {
              pcVar2 = "high";
              if (g_flInferredThreatScale <= fVar5) {
                pcVar2 = "high";
              }
            }
            else {
              pcVar2 = "high";
            }
          }
          else {
            pcVar2 = "medium";
          }
        }
        else {
          pcVar2 = "low";
        }
        (**(code **)(**(int **)(in_EAX + 0x94c) + 0x45c))(pcVar2,piVar4[-3],piVar4[-3] >> 0x1f,1);
        (**(code **)(**(int **)(in_EAX + 0x94c) + 0x464))
                  (piVar4[-3],piVar4[-3] >> 0x1f,1,&stack0xffffffe8);
        iStack_4 = iStack_4 + 1;
        piVar4 = piVar4 + 0xf;
      } while (iStack_4 < *(int *)(in_EAX + 0x558));
    }
  }
  FUN_007fbd30();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
