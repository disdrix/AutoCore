# Annotated low-level: FUN_005dab30

| Field | Value |
|---|---|
| Stable ID | `aa_005dab30` |
| VA | `0x005dab30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dab30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005dab30(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_005da0a0(*(undefined4 *)(param_1 + 0x14),param_1 + 0x1c,*(undefined4 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 0xc));
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
