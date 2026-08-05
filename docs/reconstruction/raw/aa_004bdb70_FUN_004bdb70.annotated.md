# Annotated low-level: FUN_004bdb70

| Field | Value |
|---|---|
| Stable ID | `aa_004bdb70` |
| VA | `0x004bdb70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bdb70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool __thiscall FUN_004bdb70(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  *(undefined1 *)(param_1 + 0x5b0) = 0;
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(char *)(*(int *)(param_1 + 0x5d4) + 0x7d) == '\0')) {
    if (*(int *)(param_1 + 0x5b4) == 0) {
      if (*(void **)(param_1 + 0x340) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(*(void **)(param_1 + 0x340));
      }
      (**(code **)(*(int *)(param_1 + 0x2c8) + 0x58))();
      iVar2 = (**(code **)(*(int *)(param_1 + 0x2c8) + 0x10))(3);
      *(undefined4 *)(iVar2 + 0xbc) = 0xffffffff;
      *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;
      *(undefined4 *)(iVar2 + 0x90) = *(undefined4 *)(param_1 + 0x598);
      *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(param_1 + 0x59c);
      *(undefined4 *)(iVar2 + 0x98) = *(undefined4 *)(param_1 + 0x5a0);
    }
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x5b4) < *(int *)(param_1 + 0x1c)) {
      iVar2 = 0;
      do {
        if (iVar2 < *(int *)(param_1 + 0x5b4)) {
          iVar2 = iVar2 + 1;
        }
        else {
          if (*(int *)(param_1 + 0x18) != 0) {
            piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 0xc);
            if (*piVar1 != 0) {
              if ((char)piVar1[2] == '\0') {
                FUN_00765170(*piVar1,0);
              }
              else {
                piVar1 = (int *)*piVar1;
                uVar5 = (**(code **)(*piVar1 + 0xc))();
                uVar6 = (**(code **)(*piVar1 + 0x48))(uVar5);
                FUN_0074c9c0(&DAT_00d1eb60,uVar6,uVar5);
              }
            }
          }
          *(int *)(param_1 + 0x5b4) = *(int *)(param_1 + 0x5b4) + 1;
          iVar2 = *(int *)(param_1 + 0x5b4);
          iVar3 = FUN_0076c3c0();
          if (*param_3 <= iVar3) break;
        }
        if ((*(int *)(param_1 + 0x18) == 0) ||
           (iVar3 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar3 == 0)) break;
        *(int *)(param_1 + 0x18) = iVar3;
      } while( true );
    }
    iVar2 = FUN_0076c3c0();
    if (*param_3 <= iVar2) {
      return true;
    }
    piVar1 = (int *)(param_1 + 0x2c8);
    FUN_00764dc0(0);
    (**(code **)(*piVar1 + 0x50))();
    puVar4 = operator_new(0xc);
    *puVar4 = 10;
    *(int *)(puVar4 + 4) = param_1;
    *(undefined1 **)(param_1 + 0x340) = puVar4;
    uVar5 = (**(code **)(*piVar1 + 0xc))();
    uVar6 = (**(code **)(*piVar1 + 0x48))(uVar5);
    FUN_0074c9c0(&DAT_00d1eb60,uVar6,uVar5);
  }
  *(undefined1 *)(param_1 + 0x5c4) = 1;
  *(undefined1 *)(param_1 + 0x571) = 0;
  *(undefined1 *)(param_1 + 0x574) = 1;
  *(undefined4 *)(param_1 + 0x5b4) = 0;
  iVar2 = FUN_0076c3c0();
  return *param_3 <= iVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
