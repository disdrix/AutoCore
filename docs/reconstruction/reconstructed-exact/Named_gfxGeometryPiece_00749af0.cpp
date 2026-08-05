// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, switch×1, goto×1.
//  - Notable callees: FUN_00437960×7, FUN_0074c8a0×3, FUN_0074c420×2, FUN_004378a0, FUN_0044b6e0, FUN_0044b7e0, FUN_00749af0, vog_LogMessage.
//  - Strings: ",0x510,3,

                   ".
//  - Return sites: 5.

// =============================================================================
// Named_gfxGeometryPiece_00749af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00749af0
// Address:   0x00749af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxGeometryPiece"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_gfxGeometryPiece_00749af0(int *param_1,float param_2,float param_3)



{

  float fVar1;

  float fVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint8_t auStack_58 [84];

  uint8_t uStack_4;

  uint8_t uStack_3;

  uint8_t uStack_2;

  uint8_t uStack_1;

  

  fVar1 = param_2;

  switch(param_2) {

  case 2.8026e-45:

    if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {

      (**(code **)(*param_1 + 0x5c))();

    }

    fVar1 = param_3;

    puVar9 = &param_3;

    iVar8 = (int)param_3 + 0x10;

    iVar6 = (int)param_3 + 4;

    uVar4 = FUN_00437960(iVar6,iVar8,puVar9);

    cVar3 = FUN_0074c8a0(uVar4,iVar6,iVar8,puVar9);

    if ((cVar3 != '\0') && (param_3 < *(float *)((int)fVar1 + 0x1c))) {

      *(int **)((int)fVar1 + 0x3c) = param_1;

      *(float *)((int)fVar1 + 0x1c) = param_3;

      return 1;

    }

    break;

  case 4.2039e-45:

    if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {

      (**(code **)(*param_1 + 0x5c))();

    }

    fVar1 = param_3;

    iVar8 = (int)param_3 + 0x10;

    iVar6 = (int)param_3 + 4;

    FUN_00437960(iVar6,iVar8);

    cVar3 = FUN_0074c420(iVar6,iVar8);

    param_2 = param_3;

    goto joined_r0x00749c0f;

  case 5.60519e-45:

    if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {

      (**(code **)(*param_1 + 0x5c))();

    }

    fVar1 = param_3;

    puVar9 = &param_2;

    iVar8 = (int)param_3 + 0x10;

    iVar6 = (int)param_3 + 4;

    iVar5 = iVar6;

    iVar7 = iVar8;

    uVar4 = FUN_00437960(iVar6,iVar8,puVar9);

    cVar3 = FUN_0074c8a0(uVar4,iVar5,iVar7,puVar9);

    if (cVar3 == '\0') {

      return 0;

    }

    param_3 = (float)FUN_00437960(iVar6,iVar8);

    FUN_004378a0();

    cVar3 = FUN_0074c420(iVar6,iVar8);

joined_r0x00749c0f:

    if ((cVar3 != '\0') && (param_2 < *(float *)((int)fVar1 + 0x1c))) {

      *(int **)((int)fVar1 + 0x3c) = param_1;

      *(float *)((int)fVar1 + 0x1c) = param_2;

      return 1;

    }

    break;

  case 7.00649e-45:

    if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {

      (**(code **)(*param_1 + 0x5c))();

    }

    fVar2 = param_3;

    puVar9 = &param_3;

    iVar8 = (int)param_3 + 0x10;

    iVar6 = (int)param_3 + 4;

    uVar4 = FUN_00437960(iVar6,iVar8,puVar9);

    cVar3 = FUN_0074c8a0(uVar4,iVar6,iVar8,puVar9);

    if ((cVar3 != '\0') &&

       (param_3 < *(float *)((int)fVar2 + 0x1c) || param_3 == *(float *)((int)fVar2 + 0x1c))) {

      uStack_2 = 0xff;

      uStack_3 = 0xff;

      uStack_4 = 0xff;

      uStack_1 = 0xff;

      FUN_00437960();

      FUN_0044b6e0();

      cVar3 = (**(code **)(*param_1 + 0x70))(fVar1,auStack_58,0);

      if (cVar3 != '\0') {

        uVar4 = FUN_00437960();

        FUN_0044b7e0(uVar4);

        return 1;

      }

    }

    break;

  default:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp",0x510,3,

                   "Unimplemented code reached");

  }

  return 0;

}
