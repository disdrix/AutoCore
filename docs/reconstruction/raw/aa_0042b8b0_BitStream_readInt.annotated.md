# Annotated low-level: BitStream_readInt

| Field | Value |
|---|---|
| Stable ID | `aa_0042b8b0` |
| VA | `0x0042b8b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042b8b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint BitStream_readInt(byte param_1)

{
  uint local_4;
  
  local_4 = 0;
  BitStream_readBits(param_1,&local_4);
  if (param_1 != 0x20) {
    local_4 = local_4 & (1 << (param_1 & 0x1f)) - 1U;
  }
  return local_4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
