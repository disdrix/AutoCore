# Annotated low-level: FUN_004ac0e0

| Field | Value |
|---|---|
| Stable ID | `aa_004ac0e0` |
| VA | `0x004ac0e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ac0e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004ac0e0(void)

{
  CVOGTerrain_LoadMapImage(1);
  CVOGTerrain_ApplyTilesetTextures();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
