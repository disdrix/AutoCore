# Annotated low-level: CVOGTerrainChunk_GetCornerData

| Field | Value |
|---|---|
| Stable ID | `aa_005bf480` |
| VA | `0x005bf480` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bf480`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGTerrainChunk::GetCornerData(out, x, y). Returns 8-byte corner record {u16 height16; u8
   tileIndex; u8 pad; float packedColor}. height16 from CVOGTerrain+0x3e0 u16 buffer ((A<<8)|B of
   the map TGA). NOTE: tile index and tint color are fetched at (x-1, y-1) — the tile/tint grid is
   offset one cell from the height-vertex grid. */

void __thiscall
CVOGTerrainChunk_GetCornerData(int param_1,undefined2 *param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  param_3 = *(int *)(param_1 + 0xcc) * DAT_00b03650 + param_3;
  param_4 = *(int *)(param_1 + 0xd0) * DAT_00b03650 + param_4;
  iVar4 = *(int *)(DAT_00bc5524 + 0x10) + -1;
  iVar3 = param_3;
  if (iVar4 <= param_3) {
    iVar3 = iVar4;
  }
  if (iVar3 < 1) {
    param_3 = 0;
  }
  else if (iVar4 <= param_3) {
    param_3 = iVar4;
  }
  iVar3 = *(int *)(DAT_00bc5524 + 0x14) + -1;
  iVar4 = param_4;
  if (iVar3 <= param_4) {
    iVar4 = iVar3;
  }
  if (iVar4 < 1) {
    param_4 = 0;
  }
  else if (iVar3 <= param_4) {
    param_4 = iVar3;
  }
  *param_2 = *(undefined2 *)
              (*(int *)(DAT_00bc5524 + 0x3e0) +
              (*(int *)(DAT_00bc5524 + 0x10) * param_4 + param_3) * 2);
  uVar1 = CVOGTerrain_GetTileIndex(param_3 + -1,param_4 + -1);
  *(undefined1 *)(param_2 + 1) = uVar1;
  uVar2 = FUN_004a8c40(param_3 + -1,param_4 + -1);
  *(undefined4 *)(param_2 + 2) = uVar2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
