// =============================================================================
// FUN_0045af30
// -----------------------------------------------------------------------------
// Stable ID: aa_0045af30
// Address:   0x0045af30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045af30 @ 0x0045af30
// Stable ID: aa_0045af30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×13, do×2, while×2, return×1.
//  - Notable callees: FUN_0046d130×5, FUN_00439810×3, FUN_00436f80×2, FUN_00767160×2, FUN_0044c9e0, FUN_0045af30, FUN_0045e6a0, FUN_00734640.
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

uint32_t /* width from decompiler */ __thiscall FUN_0045af30(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  uint uVar6;

  undefined *puVar7;

  char *pcVar8;

  int iVar9;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bde28;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x5452414b,3);

  local_4 = 0;

  if ((*(int *)(param_1 + 0x20) != 0) &&

     (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 4 != 0)) {

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 8);

    FUN_00734640(0,0);

    uVar4 = *puVar1;

    if (param_1 == -0x10) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_0046d130();

    }

    *puVar1 = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar3;

    if (param_1 == -0x2c) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_0046d130();

    }

    *puVar1 = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar3;

    uVar3 = FUN_0046d130();

    *puVar1 = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar3;

    pcVar5 = *(char **)(param_1 + 0x14);

    pcVar8 = pcVar5;

    if (pcVar5 == (char *)0x0) {

      pcVar5 = PTR_DAT_00afa2bc;

      pcVar8 = PTR_DAT_00afa2bc;

    }

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    if (pcVar8 == (char *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = FUN_0046d130();

    }

    *puVar1 = *puVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar4;

    pcVar5 = *(char **)(param_1 + 0x18);

    pcVar8 = pcVar5;

    if (pcVar5 == (char *)0x0) {

      pcVar5 = PTR_DAT_00afa2bc;

      pcVar8 = PTR_DAT_00afa2bc;

    }

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    if (pcVar8 == (char *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = FUN_0046d130();

    }

    *puVar1 = *puVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar4;

  }

  iVar9 = 0;

  FUN_0044c9e0();

  FUN_00439810();

  puVar7 = *(undefined **)(param_1 + 0x14);

  if (*(undefined **)(param_1 + 0x14) == (undefined *)0x0) {

    puVar7 = PTR_DAT_00afa2bc;

  }

  if (param_2[7] == 0) {

    uVar6 = FUN_00436f80(param_2,puVar7);

    param_2[1] = param_2[1] | uVar6;

  }

  else {

    uVar6 = FUN_00767160(&DAT_00a9d6f8,puVar7);

    param_2[1] = param_2[1] | uVar6;

    uVar6 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

    param_2[8] = 0;

    param_2[1] = uVar6 | param_2[1];

  }

  puVar7 = *(undefined **)(param_1 + 0x18);

  if (*(undefined **)(param_1 + 0x18) == (undefined *)0x0) {

    puVar7 = PTR_DAT_00afa2bc;

  }

  if (param_2[7] == 0) {

    uVar6 = FUN_00436f80(param_2,puVar7);

    param_2[1] = param_2[1] | uVar6;

  }

  else {

    uVar6 = FUN_00767160(&DAT_00a9d6f8,puVar7);

    param_2[1] = param_2[1] | uVar6;

    uVar6 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);

    param_2[8] = 0;

    param_2[1] = uVar6 | param_2[1];

  }

  FUN_00439810();

  if (*(int *)(param_1 + 0x20) != 0) {

    iVar9 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 4;

  }

  FUN_00439810();

  if (iVar9 != 0) {

    FUN_0045e6a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),iVar9);

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return 0;

}
