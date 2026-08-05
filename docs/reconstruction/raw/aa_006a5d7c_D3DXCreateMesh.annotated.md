# Annotated low-level: D3DXCreateMesh

| Field | Value |
|---|---|
| Stable ID | `aa_006a5d7c` |
| VA | `0x006a5d7c` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a5d7c`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void D3DXCreateMesh(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXCreateMesh();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
