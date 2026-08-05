# Annotated low-level: CVOGMap_LookupVariable

| Field | Value |
|---|---|
| Stable ID | a_005b05f0 |
| VA | 0x005b05f0 |
| System | missions-progression |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Lookup map variable; type0 reads +0x48 else EvaluateComputed.

## Named callees (decompiler)

- CVOGMap_LookupVariable
- CVOGVariable_EvaluateComputed

## Machine-level notes

- Source: raw capture for a_005b05f0.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
undefined4 __thiscall CVOGMap_LookupVariable(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4) + 4);
  if (iVar1 == 0) {
LAB_005b061a:
    iVar1 = 0;
  }
  else {
    do {
      if (param_2 == *(uint *)(iVar1 + 0x10)) {
        if (iVar1 == 0) goto LAB_005b061a;
        iVar1 = *(int *)(iVar1 + 8);
        goto LAB_005b0621;
      }
      iVar1 = *(int *)(iVar1 + 0xc);
    } while (iVar1 != 0);
    iVar1 = 0;
  }
LAB_005b0621:
  if (iVar1 == 0) {
    return 0;
  }
  if (*(char *)(iVar1 + 0x40) == '\0') {
    *param_3 = *(undefined4 *)(iVar1 + 0x48);
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  uVar2 = CVOGVariable_EvaluateComputed();
  return uVar2;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
