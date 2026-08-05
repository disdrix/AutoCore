# Annotated low-level: CVOGCharacter_CreateFromPacket_Thunk0xC0

| Field | Value |
|---|---|
| Stable ID | `aa_0053cd20` |
| VA | `0x0053cd20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053cd20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void CVOGCharacter_CreateFromPacket_Thunk0xC0(void)

{
  CVOGCharacter_ApplyCreateFromPacket();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
