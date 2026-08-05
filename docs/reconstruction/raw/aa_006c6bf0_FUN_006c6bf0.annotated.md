# Annotated low-level: FUN_006c6bf0

| Field | Value |
|---|---|
| Stable ID | `aa_006c6bf0` |
| VA | `0x006c6bf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c6bf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006c6bf0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(param_1 + 0x1c);
  iVar3 = 0x20;
  puVar2 = param_2;
  do {
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
