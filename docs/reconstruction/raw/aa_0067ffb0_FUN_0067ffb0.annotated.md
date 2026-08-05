# Annotated low-level: FUN_0067ffb0

| Field | Value |
|---|---|
| Stable ID | `aa_0067ffb0` |
| VA | `0x0067ffb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067ffb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0067ffb0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 2))) {
    puVar2 = *(undefined4 **)(param_1 + 8);
    *puVar2 = *param_2;
    *(undefined4 **)(param_1 + 8) = puVar2 + 1;
    return;
  }
  FUN_0067f930(*(undefined4 *)(param_1 + 8),1,param_2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
