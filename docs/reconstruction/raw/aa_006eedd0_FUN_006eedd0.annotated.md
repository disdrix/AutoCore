# Annotated low-level: FUN_006eedd0

| Field | Value |
|---|---|
| Stable ID | `aa_006eedd0` |
| VA | `0x006eedd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006eedd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006eedd0(void)

{
  FUN_006cb4b0(4,1);
  FUN_006cb4b0(5,1);
  FUN_006cb4b0(6,1);
  FUN_006cb4b0(7,1);
  FUN_006cb4b0(8,1);
  FUN_006cb4b0(0x17,1);
  FUN_006cb4b0(0xb,2);
  FUN_006cb4b0(10,2);
  FUN_006cb4b0(0x13,3);
  FUN_006cb4b0(1,0x10);
  FUN_006cb4b0(0x12,0xd);
  FUN_006cb4b0(0xe,0xd);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
