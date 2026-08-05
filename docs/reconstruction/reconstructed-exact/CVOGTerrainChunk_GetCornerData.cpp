// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGTerrainChunk::GetCornerData, CVOGTerrainChunk_GetCornerData, CVOGTerrain_GetTileIndex, FUN_004a8c40, at, buffer.
//  - Return sites: 1.

// =============================================================================
// CVOGTerrainChunk_GetCornerData
// -----------------------------------------------------------------------------
// Stable ID: aa_005bf480
// Address:   0x005bf480  (autoassault.exe, image base 0x400000)
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

/* CVOGTerrainChunk::GetCornerData(out, x, y). Returns 8-byte corner record {u16 height16; u8

   tileIndex; u8 pad; float packedColor}. height16 from CVOGTerrain+0x3e0 u16 buffer ((A<<8)|B of

   the map TGA). NOTE: tile index and tint color are fetched at (x-1, y-1) - the tile/tint grid is

   offset one cell from the height-vertex grid. */



void __thiscall

CVOGTerrainChunk_GetCornerData(int param_1,uint16_t *param_2,int param_3,int param_4)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

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

  *param_2 = *(uint16_t *)

              (*(int *)(DAT_00bc5524 + 0x3e0) +

              (*(int *)(DAT_00bc5524 + 0x10) * param_4 + param_3) * 2);

  uVar1 = CVOGTerrain_GetTileIndex(param_3 + -1,param_4 + -1);

  *(uint8_t *)(param_2 + 1) = uVar1;

  uVar2 = FUN_004a8c40(param_3 + -1,param_4 + -1);

  *(uint32_t /* width from decompiler */ *)(param_2 + 2) = uVar2;

  return;

}
