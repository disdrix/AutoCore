# Annotated low-level: FUN_005be6a0

| Field | Value |
|---|---|
| Stable ID | `aa_005be6a0` |
| VA | `0x005be6a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005be6a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005be6a0(int param_1)

{
  if (*(char *)(param_1 + 0xc4) != '\0') {
    *(undefined1 *)(param_1 + 0xc4) = 0;
    if (*(int *)(param_1 + 200) == 0) {
      DAT_00b45510 = *(undefined4 *)(param_1 + 0xcc);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 200) + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
    }
    if (*(int *)(param_1 + 0xcc) == 0) {
      DAT_00b45514 = *(undefined4 *)(param_1 + 200);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0xcc) + 200) = *(undefined4 *)(param_1 + 200);
    }
    DAT_00b45518 = DAT_00b45518 + -1;
    if (DAT_00b45518 == 0) {
      DAT_00b45510 = 0;
      DAT_00b45514 = 0;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
