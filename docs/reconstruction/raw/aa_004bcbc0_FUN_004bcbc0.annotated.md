# Annotated low-level: FUN_004bcbc0

| Field | Value |
|---|---|
| Stable ID | `aa_004bcbc0` |
| VA | `0x004bcbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bcbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004bcbc0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009cb378;
  FUN_004bc950();
  *param_1 = &PTR_FUN_009cb334;
  FUN_004bc950();
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
