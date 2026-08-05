# Annotated low-level: FUN_008fda30

| Field | Value |
|---|---|
| Stable ID | `aa_008fda30` |
| VA | `0x008fda30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fda30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008fda30(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iStack_4;
  
  iVar1 = *(int *)(DAT_00d1b6d8 + 0x250);
  iVar6 = 0;
  if (0 < *(int *)(in_EAX + 0x518)) {
    do {
      iVar3 = *(int *)(*(int *)(*(int *)(in_EAX + 0x728) + iVar6 * 4) + 0x110);
      if (iVar3 < *(int *)(in_EAX + 0x50c)) {
        iVar3 = iVar3 * 0x110;
        iVar2 = *(int *)(in_EAX + 0x5fc);
        if (*(int *)(iVar1 + 0x28c + (uint)*(byte *)(*(int *)(in_EAX + 0x5fc) + 8 + iVar3) * 4) ==
            *(int *)(*(int *)(in_EAX + 0x5fc) + iVar3)) {
          if (*(int *)(in_EAX + 0x530 + (uint)*(byte *)(iVar3 + 8 + iVar2) * 4) ==
              *(int *)(iVar3 + iVar2)) {
LAB_008fdaca:
            (**(code **)(**(int **)(*(int *)(in_EAX + 0x738) + iVar6 * 4) + 0x3c8))(0,1);
            goto LAB_008fdadd;
          }
        }
        else if (*(int *)(in_EAX + 0x530 + (uint)*(byte *)(iVar3 + 8 + iVar2) * 4) !=
                 *(int *)(iVar3 + iVar2)) goto LAB_008fdaca;
        (**(code **)(**(int **)(*(int *)(in_EAX + 0x738) + iVar6 * 4) + 0x3c8))(1);
      }
LAB_008fdadd:
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_EAX + 0x518));
  }
  if (*(int *)(in_EAX + 0x730) != 0) {
    piVar4 = (int *)__RTDynamicCast(*(int *)(in_EAX + 0x730),0,
                                    &CNDUIWndBuffered::RTTI_Type_Descriptor,
                                    &CWndVehicle::RTTI_Type_Descriptor,0);
    iStack_4 = 0;
    puVar5 = (undefined4 *)(in_EAX + 0x530);
    do {
      FUN_00834470(piVar4,*puVar5);
      iStack_4 = iStack_4 + 1;
      puVar5 = puVar5 + 1;
    } while (iStack_4 < 8);
                    /* WARNING: Could not recover jumptable at 0x008fdb4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar4 + 0x34c))();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
