// =============================================================================
// FUN_00999040
// -----------------------------------------------------------------------------
// Stable ID: aa_00999040
// Address:   0x00999040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00999040 @ 0x00999040
// Stable ID: aa_00999040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_00436f80, FUN_00439810, FUN_00767160, FUN_00999040, gfxGeometryPiece_Serialize, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint __thiscall FUN_00999040(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  undefined *puVar4;

  int *piVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2ebb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x47534b4e,1);

  local_4 = 0;

  uVar2 = gfxGeometryPiece_Serialize(param_2);

  uVar3 = FUN_00439810();

  piVar1 = *(int **)(param_1 + 0xe4);

  uVar2 = uVar2 | uVar3;

  for (piVar5 = *(int **)(param_1 + 0xe0); piVar5 != piVar1; piVar5 = piVar5 + 1) {

    puVar4 = (undefined *)*piVar5;

    if ((undefined *)*piVar5 == (undefined *)0x0) {

      puVar4 = PTR_DAT_00afa2bc;

    }

    if (param_2[7] == 0) {

      uVar3 = FUN_00436f80(param_2,puVar4);

      param_2[1] = param_2[1] | uVar3;

    }

    else {

      uVar3 = FUN_00767160(&DAT_00a9d6f8,puVar4);

      param_2[1] = param_2[1] | uVar3;

      uVar3 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

      param_2[8] = 0;

      param_2[1] = uVar3 | param_2[1];

    }

    uVar2 = uVar2 | param_2[1];

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return uVar2;

}
