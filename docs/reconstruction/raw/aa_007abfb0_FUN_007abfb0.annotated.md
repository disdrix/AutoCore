# Annotated low-level: FUN_007abfb0

| Field | Value |
|---|---|
| Stable ID | `aa_007abfb0` |
| VA | `0x007abfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007abfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007abfb0(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x22b) = *(undefined1 *)(in_EAX + 0xf8);
  *(undefined1 *)(in_EAX + 0x22f) = *(undefined1 *)(in_EAX + 0xfc);
  *(undefined1 *)(in_EAX + 0x233) = *(undefined1 *)(in_EAX + 0x100);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
