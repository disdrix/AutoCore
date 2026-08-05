# Annotated low-level: FUN_004eae80

| Field | Value |
|---|---|
| Stable ID | `aa_004eae80` |
| VA | `0x004eae80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004eae80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004eae80(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x14)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0xc),*(int *)(param_1 + 0x14) * 8,0x12);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
