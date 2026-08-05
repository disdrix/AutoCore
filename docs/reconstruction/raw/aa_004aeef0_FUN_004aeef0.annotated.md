# Annotated low-level: FUN_004aeef0

| Field | Value |
|---|---|
| Stable ID | `aa_004aeef0` |
| VA | `0x004aeef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004aeef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004aeef0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 code *param_6)

{
  char cVar1;
  int iVar2;
  
  while (param_3 < param_2) {
    iVar2 = (param_2 + -1) / 2;
    cVar1 = (*param_6)(*(undefined4 *)(param_1 + iVar2 * 8),*(undefined4 *)(param_1 + 4 + iVar2 * 8)
                       ,param_4,param_5);
    if (cVar1 == '\0') break;
    *(undefined4 *)(param_1 + param_2 * 8) = *(undefined4 *)(param_1 + iVar2 * 8);
    *(undefined4 *)(param_1 + 4 + param_2 * 8) = *(undefined4 *)(param_1 + 4 + iVar2 * 8);
    param_2 = iVar2;
  }
  *(undefined4 *)(param_1 + 4 + param_2 * 8) = param_5;
  *(undefined4 *)(param_1 + param_2 * 8) = param_4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
