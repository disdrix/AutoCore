# Annotated low-level: CVOGTerrain_StreamMapHeader

| Field | Value |
|---|---|
| Stable ID | `aa_004aa0f0` |
| VA | `0x004aa0f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004aa0f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGTerrain::StreamMapHeader [VOGTerrain.cpp]. Streams .fam/.fat map header (bidirectional VOG
   stream). Object field offsets: +0x10 m_lWidth, +0x14 m_lHeight, +0x18 m_fGridSize, +0x1c
   m_ucTileSet. Fields: MapVersion(0x3e=62), IterationVersion, Width, Height, GridSize, TileSet,
   UseRoad, Music[3], UseClouds, UseTimeOfDay, SkyboxName, CullingScale, NumImports. See
   docs/terrain-format-findings.md. Header only — height grid loaded elsewhere. */

void __fastcall CVOGTerrain_StreamMapHeader(undefined4 *param_1)

{
  FUN_0079d290(1,"CVOGTerrain::StreamMapHeader");
  *param_1 = 0x3e;
  FUN_00498740("c_lMapVersion",param_1);
  param_1[1] = param_1[1] + 1;
  FUN_00498740("m_lMapIterationVersion",param_1 + 1);
  FUN_00498740("m_lWidth",param_1 + 4);
  FUN_00498740("m_lHeight",param_1 + 5);
  FUN_00498800("m_fGridSize",param_1 + 6);
  FUN_004988c0("m_ucTileSet",param_1 + 7);
  FUN_00498980("m_bUseRoad",(int)param_1 + 0x1d);
  FUN_0079ce30("m_arriMusic",(int)param_1 + 0x32e,6);
  FUN_00498980("m_bUseClouds",param_1 + 0xce);
  FUN_00498980("m_bUseTimeOfDay",(int)param_1 + 0x339);
  FUN_0079cd30("m_strSkyboxName",param_1[0xcd]);
  FUN_00498800("m_fCullingScale",param_1 + 0xcf);
  FUN_00498740("m_lNumberOfImports",param_1 + 2);
  FUN_0079d1e0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
