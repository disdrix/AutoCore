# Annotated low-level: FUN_0065adf0

| Field | Value |
|---|---|
| Stable ID | `aa_0065adf0` |
| VA | `0x0065adf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065adf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __thiscall FUN_0065adf0(int *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  
  uVar5 = 0;
  cVar2 = *param_2;
  pcVar7 = param_2;
  while (cVar2 != '\0') {
    pcVar1 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
    uVar5 = (int)cVar2 + uVar5 * 0x1f;
    cVar2 = *pcVar1;
  }
  iVar6 = *param_1;
  uVar3 = param_1[2];
  uVar8 = uVar3 & uVar5 & 0x7fffffff;
  uVar4 = *(uint *)(iVar6 + uVar8 * 4);
  while( true ) {
    if (uVar4 == 0xffffffff) {
      return param_1[2] + 1;
    }
    if ((uVar4 == (uVar5 & 0x7fffffff)) &&
       (iVar6 = FUN_00637f70(param_2,*(undefined4 *)(iVar6 + 4 + (uVar3 + uVar8) * 4)), iVar6 == 0))
    break;
    uVar3 = param_1[2];
    iVar6 = *param_1;
    uVar8 = uVar8 + 1 & uVar3;
    uVar4 = *(uint *)(iVar6 + uVar8 * 4);
  }
  return uVar8;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
