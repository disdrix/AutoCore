// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, CVOGTerrain::GetTileIndex, CVOGTerrain_GetTileIndex, row.
//  - Return sites: 2.

// =============================================================================
// CVOGTerrain_GetTileIndex
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8c00
// Address:   0x004a8c00  (autoassault.exe, image base 0x400000)
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

    return CONCAT31((int3)((uint)iVar1 >> 8),*(uint8_t *)(iVar1 + param_3)) & 0xffffff07;

  }

  return in_EAX & 0xffffff00;

}
