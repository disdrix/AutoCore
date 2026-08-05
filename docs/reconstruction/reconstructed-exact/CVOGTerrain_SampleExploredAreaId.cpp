// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGTerrain_SampleExploredAreaId, World.
//  - Return sites: 2.

// =============================================================================
// CVOGTerrain_SampleExploredAreaId
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8b90
// Address:   0x004a8b90  (autoassault.exe, image base 0x400000)
// System:    missions-progression
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
