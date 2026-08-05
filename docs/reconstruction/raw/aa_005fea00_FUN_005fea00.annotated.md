# Annotated low-level: FUN_005fea00

| Field | Value |
|---|---|
| Stable ID | `aa_005fea00` |
| VA | `0x005fea00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fea00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005fea00(int param_1,short param_2)

{
  *(short *)(param_1 + 0xb4) = *(short *)(param_1 + 0xb4) + param_2;
  if (*(short *)(param_1 + 0xb4) < 1) {
    *(undefined2 *)(param_1 + 0xb4) = 1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
