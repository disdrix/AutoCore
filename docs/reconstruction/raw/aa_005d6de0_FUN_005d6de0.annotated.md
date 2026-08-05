# Annotated low-level: FUN_005d6de0

| Field | Value |
|---|---|
| Stable ID | `aa_005d6de0` |
| VA | `0x005d6de0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d6de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005d6de0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(char *)(param_1 + 0xb2) != '\0') {
    *(undefined1 *)(param_1 + 0xb2) = 0;
    FUN_004fc650(param_2,param_3,param_4,*(undefined1 *)(param_1 + 0xb3));
    *(undefined1 *)(param_1 + 0xb3) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
