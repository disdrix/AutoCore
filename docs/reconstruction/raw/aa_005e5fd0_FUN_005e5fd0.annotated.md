# Annotated low-level: FUN_005e5fd0

| Field | Value |
|---|---|
| Stable ID | `aa_005e5fd0` |
| VA | `0x005e5fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005e5fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005e5fd0(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  void *pvVar6;
  int *piVar7;
  undefined4 uStack_20;
  undefined1 local_18 [12];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a75eb;
  pvStack_c = ExceptionList;
  pvVar6 = (void *)0x0;
  ExceptionList = &pvStack_c;
  do {
    if (*(char *)((int)(param_1 + 0x69) + (int)pvVar6) != '\0') {
      puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x44))(local_18,pvVar6);
      uVar1 = puVar3[2];
      uVar2 = *puVar3;
      FUN_004cd220(uVar2,uVar1);
      if (*(int *)(param_1[0x55] + (int)pvVar6 * 4) == 0) {
        pvVar6 = operator_new(0x14c);
        piVar7 = (int *)0x0;
        pvStack_c = (void *)0x0;
        if (pvVar6 != (void *)0x0) {
          piVar7 = (int *)FUN_00764030();
        }
        pvStack_c = (void *)0xffffffff;
        FUN_00989e00(&stack0xffffffcc,"obj_gen_n_mov_barrel_01_blueandwhite.geo");
        (**(code **)(*piVar7 + 0x5c))(&stack0xffffffcc);
        iVar4 = (**(code **)(*piVar7 + 0x10))(3);
        *(undefined4 *)(iVar4 + 0xbc) = 0xffffffff;
        *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + 1;
        *(undefined4 *)(iVar4 + 0x90) = uVar2;
        *(undefined4 *)(iVar4 + 0x94) = uStack_20;
        *(undefined4 *)(iVar4 + 0x98) = uVar1;
        puVar5 = operator_new(0xc);
        *(void **)(puVar5 + 8) = pvVar6;
        *puVar5 = 2;
        *(int **)(puVar5 + 4) = param_1;
        piVar7[0x1e] = (int)puVar5;
        *(int **)(param_1[0x55] + (int)pvVar6 * 4) = piVar7;
      }
      else {
        iVar4 = (**(code **)(**(int **)(param_1[0x55] + (int)pvVar6 * 4) + 0x10))(3);
        *(undefined4 *)(iVar4 + 0xbc) = 0xffffffff;
        *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + 1;
        *(undefined4 *)(iVar4 + 0x90) = uVar2;
        *(undefined4 *)(iVar4 + 0x94) = uStack_20;
        *(undefined4 *)(iVar4 + 0x98) = uVar1;
      }
    }
    pvVar6 = (void *)((int)pvVar6 + 1);
  } while ((int)pvVar6 < 6);
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
