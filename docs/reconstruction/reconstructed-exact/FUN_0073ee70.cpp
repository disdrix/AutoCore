// =============================================================================
// FUN_0073ee70
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ee70
// Address:   0x0073ee70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073ee70 @ 0x0073ee70
// Stable ID: aa_0073ee70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_00436f80×2, FUN_00767160×2, FUN_00436030, FUN_00439870, FUN_0073ee70, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint32_t /* width from decompiler */ __fastcall FUN_0073ee70(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  undefined *puVar3;

  int *piVar4;

  int iVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad78c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x4d574754,1);

  iVar5 = 0;

  local_4 = 0;

  puVar3 = *(undefined **)(param_2 + 0x18);

  if (*(undefined **)(param_2 + 0x18) == (undefined *)0x0) {

    puVar3 = PTR_DAT_00afa2bc;

  }

  if (param_1[7] == 0) {

    uVar2 = FUN_00436f80(param_1,puVar3);

    param_1[1] = param_1[1] | uVar2;

  }

  else {

    uVar2 = FUN_00767160(&DAT_00a9d6f8,puVar3);

    param_1[1] = param_1[1] | uVar2;

    uVar2 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

    param_1[8] = 0;

    param_1[1] = uVar2 | param_1[1];

  }

  FUN_00439870();

  FUN_00436030();

  if (0 < *(int *)(param_2 + 0x14)) {

    piVar4 = (int *)(*(int *)(param_2 + 8) + 0xc);

    do {

      puVar3 = (undefined *)*piVar4;

      if ((undefined *)*piVar4 == (undefined *)0x0) {

        puVar3 = PTR_DAT_00afa2bc;

      }

      if (param_1[7] == 0) {

        uVar2 = FUN_00436f80(param_1,puVar3);

        param_1[1] = param_1[1] | uVar2;

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d6f8,puVar3);

        param_1[1] = param_1[1] | uVar2;

        uVar2 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        param_1[1] = uVar2 | param_1[1];

      }

      iVar5 = iVar5 + 1;

      piVar4 = piVar4 + 4;

    } while (iVar5 < *(int *)(param_2 + 0x14));

  }

  uVar1 = param_1[1];

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return uVar1;

}
