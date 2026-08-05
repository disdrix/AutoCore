# Annotated low-level: FUN_007abf80

| Field | Value |
|---|---|
| Stable ID | `aa_007abf80` |
| VA | `0x007abf80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007abf80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007abf80(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x228) = *(undefined4 *)(in_EAX + 0x104);
  *(undefined4 *)(in_EAX + 0x22c) = *(undefined4 *)(in_EAX + 0x108);
  *(undefined4 *)(in_EAX + 0x230) = *(undefined4 *)(in_EAX + 0x10c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
