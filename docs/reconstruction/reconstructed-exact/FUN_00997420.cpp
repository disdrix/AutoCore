// =============================================================================
// FUN_00997420
// -----------------------------------------------------------------------------
// Stable ID: aa_00997420
// Address:   0x00997420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00997420 @ 0x00997420
// Stable ID: aa_00997420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00436030×7, FUN_00436f80, FUN_00767160, FUN_00997420, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint __fastcall FUN_00997420(uint32_t /* width from decompiler */ *param_1)



{

  undefined *puVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int unaff_EBX;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad607;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  stoChunkWriter_BeginChunk(0x42444154,2);

  local_4 = 0;

  puVar1 = *(undefined **)(unaff_EBX + 8);

  if (*(undefined **)(unaff_EBX + 8) == (undefined *)0x0) {

    puVar1 = PTR_DAT_00afa2bc;

  }

  if (param_1[7] == 0) {

    uVar2 = FUN_00436f80(param_1,puVar1);

    param_1[1] = param_1[1] | uVar2;

  }

  else {

    uVar2 = FUN_00767160(&DAT_00a9d6f8,puVar1);

    param_1[1] = param_1[1] | uVar2;

    uVar2 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

    param_1[8] = 0;

    param_1[1] = uVar2 | param_1[1];

  }

  uVar2 = param_1[1];

  uVar3 = FUN_00436030();

  uVar4 = FUN_00436030();

  uVar5 = FUN_00436030();

  FUN_00436030();

  FUN_00436030();

  FUN_00436030();

  FUN_00436030();

  uVar2 = uVar3 | uVar2 | uVar4 | uVar5 | param_1[1];

  if (*(int *)(unaff_EBX + 0x80) != 0) {

    uVar3 = (**(code **)(**(int **)(unaff_EBX + 0x80) + 0xc))(param_1);

    uVar2 = uVar2 | uVar3;

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = pvStack_c;

  return uVar2;

}
