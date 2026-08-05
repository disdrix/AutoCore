# Annotated low-level: thunk_FUN_0065ea90

| Field | Value |
|---|---|
| Stable ID | `aa_0064fdd0` |
| VA | `0x0064fdd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064fdd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall thunk_FUN_0065ea90(int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0xc);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
