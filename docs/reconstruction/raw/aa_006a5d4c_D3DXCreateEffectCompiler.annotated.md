# Annotated low-level: D3DXCreateEffectCompiler

| Field | Value |
|---|---|
| Stable ID | `aa_006a5d4c` |
| VA | `0x006a5d4c` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a5d4c`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void D3DXCreateEffectCompiler(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXCreateEffectCompiler();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
