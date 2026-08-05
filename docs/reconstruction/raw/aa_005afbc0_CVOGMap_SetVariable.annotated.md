# Annotated low-level: CVOGMap_SetVariable

| Field | Value |
|---|---|
| Stable ID | a_005afbc0 |
| VA | 0x005afbc0 |
| System | missions-progression |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Set map variable float + notify bound reaction targets via +0x13c.

## Named callees (decompiler)

- CVOGMap_SetVariable
- FUN_007a4480
- FUN_004cd3b0
- CVOGReaction_ResolveObjectTarget

## Machine-level notes

- Source: raw capture for a_005afbc0.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
void __thiscall CVOGMap_SetVariable(int param_1,uint param_2,float param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4) + 4);
  if (iVar3 == 0) {
LAB_005afbf4:
    iVar3 = 0;
  }
  else {
    do {
      if (param_2 == *(uint *)(iVar3 + 0x10)) {
        if (iVar3 == 0) goto LAB_005afbf4;
        iVar3 = *(int *)(iVar3 + 8);
        goto LAB_005afbfb;
      }
      iVar3 = *(int *)(iVar3 + 0xc);
    } while (iVar3 != 0);
    iVar3 = 0;
  }
LAB_005afbfb:
  if (iVar3 != 0) {
    if (*(char *)(param_1 + 0x3c) != '\0') {
      FUN_007a4480(0,"SV(%d: %f)\n",param_2,(double)param_3);
    }
    *(float *)(iVar3 + 0x48) = param_3;
    FUN_004cd3b0(param_2,param_3);
    puVar2 = *(undefined4 **)(iVar3 + 0x58);
    if (puVar2 != *(undefined4 **)(iVar3 + 0x5c)) {
      do {
        piVar1 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar2,puVar2[1]);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x13c))(param_4);
        }
        puVar2 = puVar2 + 2;
      } while (puVar2 != *(undefined4 **)(iVar3 + 0x5c));
    }
  }
  return;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
