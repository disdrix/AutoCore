// =============================================================================
// FUN_00748800
// -----------------------------------------------------------------------------
// Stable ID: aa_00748800
// Address:   0x00748800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00748800 @ 0x00748800
// Stable ID: aa_00748800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: FUN_00436f80×2, FUN_00767160×2, FUN_00439810, FUN_00748800, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint32_t /* width from decompiler */ __thiscall FUN_00748800(uint32_t /* width from decompiler */ *param_1,uint param_2)



{

  int *piVar1;

  int iVar2;

  undefined *puVar3;

  int iVar4;

  undefined *puVar5;

  uint uVar6;

  undefined *puVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad8b7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  stoChunkWriter_BeginChunk(0x55534441,1);

  local_4 = 0;

  FUN_00439810();

  param_2 = 0;

  while ((iVar2 = *(int *)(iVar4 + 0x9c), iVar2 != 0 &&

         (param_2 < (uint)(*(int *)(iVar4 + 0xa0) - iVar2 >> 3)))) {

    piVar1 = (int *)(iVar2 + param_2 * 8);

    puVar5 = (undefined *)*piVar1;

    if (puVar5 == (undefined *)0x0) {

      puVar5 = PTR_DAT_00afa2bc;

    }

    puVar3 = (undefined *)piVar1[1];

    puVar7 = PTR_DAT_00afa2bc;

    if (puVar3 != (undefined *)0x0) {

      puVar7 = puVar3;

    }

    if (param_1[7] == 0) {

      uVar6 = FUN_00436f80(param_1,puVar5);

    }

    else {

      uVar6 = FUN_00767160(&DAT_00a9d6f8,puVar5);

      param_1[1] = param_1[1] | uVar6;

      param_1[8] = 0;

      uVar6 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

    }

    param_1[1] = param_1[1] | uVar6;

    if (param_1[7] == 0) {

      uVar6 = FUN_00436f80(param_1,puVar7);

      param_1[1] = param_1[1] | uVar6;

      param_2 = param_2 + 1;

    }

    else {

      uVar6 = FUN_00767160(&DAT_00a9d6f8,puVar7);

      param_1[1] = param_1[1] | uVar6;

      param_1[8] = 0;

      uVar6 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

      param_1[1] = param_1[1] | uVar6;

      param_2 = param_2 + 1;

    }

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = pvStack_c;

  return 0;

}
