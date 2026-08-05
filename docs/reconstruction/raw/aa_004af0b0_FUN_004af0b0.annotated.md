# Annotated low-level: FUN_004af0b0

| Field | Value |
|---|---|
| Stable ID | `aa_004af0b0` |
| VA | `0x004af0b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004af0b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004af0b0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 code *param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2;
  while( true ) {
    iVar3 = iVar2 * 2 + 2;
    if (param_3 <= iVar3) break;
    cVar1 = (*param_6)(*(undefined4 *)(param_1 + iVar3 * 8),*(undefined4 *)(param_1 + 4 + iVar3 * 8)
                       ,*(undefined4 *)(param_1 + -8 + iVar3 * 8),
                       *(undefined4 *)(param_1 + -4 + iVar3 * 8));
    if (cVar1 != '\0') {
      iVar3 = iVar2 * 2 + 1;
    }
    *(undefined4 *)(param_1 + iVar2 * 8) = *(undefined4 *)(param_1 + iVar3 * 8);
    *(undefined4 *)(param_1 + 4 + iVar2 * 8) = *(undefined4 *)(param_1 + 4 + iVar3 * 8);
    iVar2 = iVar3;
  }
  if (iVar3 == param_3) {
    *(undefined4 *)(param_1 + iVar2 * 8) = *(undefined4 *)(param_1 + -8 + param_3 * 8);
    *(undefined4 *)(param_1 + 4 + iVar2 * 8) = *(undefined4 *)(param_1 + -4 + param_3 * 8);
    iVar2 = param_3 + -1;
  }
  FUN_004aeef0(param_1,iVar2,param_2,param_4,param_5,param_6);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
