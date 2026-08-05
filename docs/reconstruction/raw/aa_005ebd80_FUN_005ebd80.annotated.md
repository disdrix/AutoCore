# Annotated low-level: FUN_005ebd80

| Field | Value |
|---|---|
| Stable ID | `aa_005ebd80` |
| VA | `0x005ebd80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ebd80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005ebd80(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xc4)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xc0) + iVar1 * 8) + 0x1c))
                (param_1 + 0xc,*(undefined4 *)(*(int *)(param_1 + 0xc0) + iVar1 * 8 + 4),
                 *(undefined4 *)(*(int *)(param_1 + 8) + 0xcc));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0xc4));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
