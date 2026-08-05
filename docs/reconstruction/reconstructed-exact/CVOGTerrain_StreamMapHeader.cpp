// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00498740×5, FUN_00498980×3, FUN_00498800×2, CVOGTerrain_StreamMapHeader, FUN_004988c0, FUN_0079cd30, FUN_0079ce30, FUN_0079d1e0.
//  - Strings: "CVOGTerrain::StreamMapHeader"; "c_lMapVersion"; "m_lMapIterationVersion"; "m_lWidth".
//  - Return sites: 1.

// =============================================================================
// CVOGTerrain_StreamMapHeader
// -----------------------------------------------------------------------------
// Stable ID: aa_004aa0f0
// Address:   0x004aa0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* CVOGTerrain::StreamMapHeader [VOGTerrain.cpp]. Streams .fam/.fat map header (bidirectional VOG

   stream). Object field offsets: +0x10 m_lWidth, +0x14 m_lHeight, +0x18 m_fGridSize, +0x1c

   m_ucTileSet. Fields: MapVersion(0x3e=62), IterationVersion, Width, Height, GridSize, TileSet,

   UseRoad, Music[3], UseClouds, UseTimeOfDay, SkyboxName, CullingScale, NumImports. See

   docs/terrain-format-findings.md. Header only - height grid loaded elsewhere. */



void __fastcall CVOGTerrain_StreamMapHeader(uint32_t /* width from decompiler */ *param_1)



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
