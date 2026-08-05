# Annotated low-level: CVOGTerrain_SampleExploredAreaId

| Field | Value |
|---|---|
| Stable ID | `aa_004a8b90` |
| VA | `0x004a8b90` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a8b90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* World (x,z) -> explored area id from terrain tile buffer.
   cell = (pos - GridSize*0.5) / GridSize; sample tileBuffer[height*cellX+cellZ] >> 3.
   G high 5 bits = area id 1..32; low 3 bits = tile layer.
   AutoCore: ContinentAreaMask.SampleAreaId */

uchar __thiscall CVOGTerrain_SampleExploredAreaId(void *this,float worldX,float worldZ)

{
  int cellZ;
  int cellX;
  float halfCellOrigin;
  float invGridSize;
  
  halfCellOrigin = *(float *)((int)this + 0x18) * DAT_00a0f298;
  invGridSize = g_flOne / *(float *)((int)this + 0x18);
  cellX = (int)((worldX - halfCellOrigin) * invGridSize);
                    /* tileBuffer[height*cellX + cellZ] >> 3  (G high 5 bits = area id) */
  cellZ = (int)((worldZ - halfCellOrigin) * invGridSize);
  if ((((-1 < cellX) && (cellX < *(int *)((int)this + 0x10))) && (-1 < cellZ)) &&
     (cellZ < *(int *)((int)this + 0x14))) {
    return *(byte *)(*(int *)((int)this + 0x14) * cellX + *(int *)((int)this + 0x3dc) + cellZ) >> 3;
  }
  return '\0';
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
