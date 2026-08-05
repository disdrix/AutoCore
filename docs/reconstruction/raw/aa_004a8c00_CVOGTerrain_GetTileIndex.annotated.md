# Annotated low-level: CVOGTerrain_GetTileIndex

| Field | Value |
|---|---|
| Stable ID | `aa_004a8c00` |
| VA | `0x004a8c00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a8c00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGTerrain::GetTileIndex(x, y). Per-cell terrain tile layer = map TGA G channel & 7 (buffer at
   +0x3dc, stored column-major dim*x+y). Selects the atlas row (0-7) in tile2_*.dds. G's high 5 bits
   are not used here. */

uint __thiscall CVOGTerrain_GetTileIndex(int param_1,int param_2,int param_3)

{
  uint in_EAX;
  int iVar1;
  
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10))) && (-1 < param_3)) &&
     (in_EAX = *(uint *)(param_1 + 0x14), param_3 < (int)in_EAX)) {
    iVar1 = in_EAX * param_2 + *(int *)(param_1 + 0x3dc);
    return CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)(iVar1 + param_3)) & 0xffffff07;
  }
  return in_EAX & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
