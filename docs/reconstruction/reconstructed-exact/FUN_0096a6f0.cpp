// =============================================================================
// FUN_0096a6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a6f0
// Address:   0x0096a6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096a6f0 @ 0x0096a6f0
// Stable ID: aa_0096a6f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0096a6f0×2, FUN_00436f80, FUN_00767160, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
//  - Return sites: 2.

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

int __thiscall FUN_0096a6f0(int *param_1,uint32_t /* width from decompiler */ *param_2,char param_3)



{

  int iVar1;

  uint uVar2;

  undefined *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad87e;

  local_c = ExceptionList;

  if ((DAT_00d1a560 == (code *)0x0) || (param_3 == '\0')) {

    _param_3 = param_2;

    ExceptionList = &local_c;

    stoChunkWriter_BeginChunk(DAT_00d1ed20,1);

    local_4 = 0;

    puVar3 = (undefined *)*param_1;

    if ((undefined *)*param_1 == (undefined *)0x0) {

      puVar3 = PTR_DAT_00afa2bc;

    }

    if (param_2[7] == 0) {

      uVar2 = FUN_00436f80(param_2,puVar3);

      param_2[1] = param_2[1] | uVar2;

    }

    else {

      uVar2 = FUN_00767160(&DAT_00a9d6f8,puVar3);

      param_2[1] = param_2[1] | uVar2;

      uVar2 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

      param_2[8] = 0;

      param_2[1] = uVar2 | param_2[1];

    }

    iVar1 = param_2[1];

    local_4 = 0xffffffff;

    stoChunkWriter_EndChunk();

  }

  else {

    _param_3 = (uint32_t /* width from decompiler */ *)0x0;

    ExceptionList = &local_c;

    iVar1 = (*DAT_00d1a560)(param_1,&param_3);

    if (-1 < iVar1) {

      iVar1 = FUN_0096a6f0(param_2,0);

      ExceptionList = local_c;

      return iVar1;

    }

  }

  ExceptionList = local_c;

  return iVar1;

}
