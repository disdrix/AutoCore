// =============================================================================
// FUN_004370b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004370b0
// Address:   0x004370b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004370b0 @ 0x004370b0
// Stable ID: aa_004370b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: okFlag, stoChunkReader::EnterChunkScope, stoChunkReader_EnterChunkScope, stoChunkReader_OpenChunk, tag, version.
//  - Return sites: 1.

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

/* stoChunkReader::EnterChunkScope(scope*, reader*) - scoped chunk-enter helper used at the top of

   every Unserialize.

   Calls stoChunkReader_OpenChunk, then fills scope = {reader, endPos, okFlag(byte), tag(u32 4cc),

   version(u32)} from the reader's current chunk ring entry. Callers then check scope.tag against

   the expected 4CC ('VERT'=0x56455254, 'INDX'=0x494e4458, 'GPCE'=0x47504345, ...) and dispatch on

   scope.version. */



int * __thiscall stoChunkReader_EnterChunkScope(int *param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  

  *param_1 = param_2;

  iVar1 = stoChunkReader_OpenChunk();

  *(bool *)(param_1 + 2) = -1 < iVar1;

  iVar1 = *param_1;

  param_1[1] = *(int *)(iVar1 + 0x1c) + *(int *)(iVar1 + 0x18);

  uVar2 = (*(int *)(iVar1 + 0x4040) + *(int *)(iVar1 + 0x403c)) - 1;

  if (*(uint *)(iVar1 + 0x4038) <= uVar2) {

    uVar2 = uVar2 - *(uint *)(iVar1 + 0x4038);

  }

  param_1[3] = **(int **)(*(int *)(iVar1 + 0x4034) + uVar2 * 4);

  uVar2 = (*(int *)(iVar1 + 0x4040) + *(int *)(iVar1 + 0x403c)) - 1;

  if (*(uint *)(iVar1 + 0x4038) <= uVar2) {

    uVar2 = uVar2 - *(uint *)(iVar1 + 0x4038);

  }

  param_1[4] = *(int *)(*(int *)(*(int *)(iVar1 + 0x4034) + uVar2 * 4) + 8);

  return param_1;

}
