# Annotated low-level: FUN_0043edb0

| Field | Value |
|---|---|
| Stable ID | `aa_0043edb0` |
| VA | `0x0043edb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0043edb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0043edb0(void)

{
  int unaff_ESI;
  
  stoChunkReader_readF32Array(unaff_ESI);
  stoChunkReader_readF32Array(unaff_ESI);
  stoChunkReader_readF32Array(unaff_ESI);
  stoChunkReader_readF32Array(unaff_ESI);
  return *(undefined4 *)(unaff_ESI + 0x402c);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
