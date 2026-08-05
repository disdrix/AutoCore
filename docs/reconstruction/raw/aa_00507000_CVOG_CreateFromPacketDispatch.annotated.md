# Annotated low-level: CVOG_CreateFromPacketDispatch

| Field | Value |
|---|---|
| Stable ID | `aa_00507000` |
| VA | `0x00507000` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00507000`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void CVOG_CreateFromPacketDispatch(void)

{
  FUN_004ff850();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
