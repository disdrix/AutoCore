# Annotated low-level: FUN_0090dab0

| Field | Value |
|---|---|
| Stable ID | `aa_0090dab0` |
| VA | `0x0090dab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0090dab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0090dab0(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00d09a38;
  do {
    FUN_0090d400();
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0xd09a4c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
