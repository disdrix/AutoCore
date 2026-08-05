# Annotated low-level: FUN_008becd0

| Field | Value |
|---|---|
| Stable ID | `aa_008becd0` |
| VA | `0x008becd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008becd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008becd0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  undefined2 extraout_var;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBX;
  undefined1 **ppuStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined1 *puStack_120;
  undefined4 uStack_11c;
  undefined1 *puStack_118;
  undefined1 local_104 [260];
  
  if ((in_EAX != (int *)0x0) && (*(int *)(unaff_EBX + 0x570 + param_1 * 4) != 0)) {
    puStack_118 = local_104;
    puStack_120 = (undefined1 *)0x8becfe;
    FUN_0085d970();
    piVar1 = *(int **)(unaff_EBX + 0x570 + param_1 * 4);
    iVar2 = *piVar1;
    puStack_118 = (undefined1 *)0x0;
    uStack_11c = 0x8bed16;
    uStack_11c = (**(code **)(*piVar1 + 0x2c8))();
    puStack_120 = local_104;
    uStack_124 = 0x8bed26;
    (**(code **)(iVar2 + 0x50))();
    uStack_124 = 1;
    uStack_128 = 0x8bed37;
    (**(code **)(**(int **)(unaff_EBX + 0x570 + param_1 * 4) + 0xcc))();
    uStack_128 = 0x8bed46;
    (**(code **)(**(int **)(unaff_EBX + 0x570 + param_1 * 4) + 0x34c))();
    uStack_128 = 1;
    uStack_12c = 0x8bed54;
    (**(code **)(**(int **)(unaff_EBX + 0x558 + param_1 * 4) + 4))();
    uStack_12c = 1;
    uStack_130 = 0x8bed62;
    (**(code **)(**(int **)(unaff_EBX + 0x564 + param_1 * 4) + 4))();
    uStack_130 = CONCAT22(extraout_var,*(undefined2 *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b8));
    iVar2 = **(int **)(unaff_EBX + 0x558 + param_1 * 4);
    ppuStack_134 = &puStack_120;
    uStack_130 = FUN_005140d0();
    ppuStack_134 = (undefined1 **)0x0;
    (**(code **)(iVar2 + 0x15c))();
    iVar2 = **(int **)(unaff_EBX + 0x57c + param_1 * 4);
    uVar3 = (**(code **)(*in_EAX + 0x15c))(1,1);
    (**(code **)(iVar2 + 0x1d8))(uVar3);
    iVar2 = **(int **)(unaff_EBX + 0x57c + param_1 * 4);
    uVar3 = FUN_00514050(&ppuStack_134);
    (**(code **)(iVar2 + 0x15c))(1,uVar3);
    iVar2 = **(int **)(unaff_EBX + 0x564 + param_1 * 4);
    iVar4 = FUN_0092fb30();
    (**(code **)(iVar2 + 0x15c))(0,&DAT_00afdacc + iVar4 * 4);
    (**(code **)(**(int **)(unaff_EBX + 0x540 + param_1 * 4) + 4))(1);
    (**(code **)(**(int **)(unaff_EBX + 0x54c + param_1 * 4) + 4))(1);
    (**(code **)(**(int **)(unaff_EBX + 0x57c + param_1 * 4) + 4))(1);
    (**(code **)(**(int **)(unaff_EBX + 0x57c + param_1 * 4) + 0x34c))();
    (**(code **)(**(int **)(unaff_EBX + 0x558 + param_1 * 4) + 0x34c))();
    (**(code **)(**(int **)(unaff_EBX + 0x564 + param_1 * 4) + 0x180))();
    (**(code **)(**(int **)(unaff_EBX + 0x570 + param_1 * 4) + 0x34c))();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
