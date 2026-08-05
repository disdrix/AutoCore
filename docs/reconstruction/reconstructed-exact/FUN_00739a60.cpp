// =============================================================================
// FUN_00739a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00739a60
// Address:   0x00739a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00739a60 @ 0x00739a60
// Stable ID: aa_00739a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00439810, FUN_004399a0, FUN_00739a60, FUN_0073ee70, gfxGeometryPiece_Serialize, gfxVertexBufferImpl_Serialize, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint __thiscall FUN_00739a60(int param_1,uint param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint uVar4;

  uint local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2e97;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x474d5048,2);

  local_4 = 0;

  param_2 = gfxGeometryPiece_Serialize(param_2);

  if (*(int *)(param_1 + 200) == 0) {

    local_14 = 1;

  }

  else {

    local_14 = FUN_0073ee70();

  }

  uVar3 = FUN_004399a0();

  param_2 = param_2 | uVar3 | local_14;

  if (*(char *)(param_1 + 0xcc) == '\0') {

    uVar3 = FUN_00439810();

    param_2 = param_2 | uVar3;

    uVar3 = 0;

    while ((iVar1 = *(int *)(param_1 + 0xd4), iVar1 != 0 &&

           (uVar3 < (uint)(*(int *)(param_1 + 0xd8) - iVar1 >> 3)))) {

      if (*(int *)(iVar1 + 4 + uVar3 * 8) == 0) {

        param_2 = param_2 | 1;

        uVar3 = uVar3 + 1;

      }

      else {

        uVar4 = gfxVertexBufferImpl_Serialize(uVar2);

        param_2 = param_2 | uVar4;

        uVar3 = uVar3 + 1;

      }

    }

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return param_2;

}
