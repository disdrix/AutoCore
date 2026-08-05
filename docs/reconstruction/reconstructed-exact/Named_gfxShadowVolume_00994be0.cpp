// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×22, return×5.
//  - Notable callees: vog_LogMessage×5, FUN_00414c20×3, FUN_00414b60×2, FUN_00414bc0×2, FUN_0044b9c0×2, FUN_0044bbc0×2, FUN_00450e60×2, FUN_0076cec0×2.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp"; "Initial Mesh Piece Contains: %d verts, %d faces"; "Unable to optimize shadow mesh".
//  - Return sites: 5.

// =============================================================================
// Named_gfxShadowVolume_00994be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00994be0
// Address:   0x00994be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxShadowVolume"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_gfxShadowVolume_00994be0(int *param_1)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  int *unaff_EBX;

  int *unaff_EBP;

  int *unaff_EDI;

  undefined ***pppuStack_4c;

  int *local_38;

  undefined **ppuStack_34;

  void *pvStack_30;

  undefined **ppuStack_2c;

  uint uStack_28;

  void *apvStack_20 [2];

  uint uStack_18;

  uint8_t uStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b2284;

  local_c = ExceptionList;

  if (param_1[5] == 0) {

    local_38 = (int *)0x0;

  }

  else {

    local_38 = *(int **)(param_1[5] + 0x18);

  }

  if (param_1[3] == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = *(int *)(param_1[3] + 0x1c);

  }

  if ((int)local_38 < 3) {

    pppuStack_4c = (undefined ***)0x256;

    ExceptionList = &local_c;

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp");

    ExceptionList = local_c;

    return (int *)0x0;

  }

  if (iVar5 < 3) {

    pppuStack_4c = (undefined ***)0x25c;

    ExceptionList = &local_c;

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp");

    ExceptionList = local_c;

    return (int *)0x0;

  }

  ExceptionList = &local_c;

  piVar3 = (int *)(**(code **)(*param_1 + 0x7c))();

  if (piVar3 == (int *)0x0) {

    ExceptionList = local_c;

    return (int *)0x0;

  }

  piVar3[0x2f] = piVar3[0x2f] | 0x40;

  pppuStack_4c = (undefined ***)0x994cb6;

  (**(code **)(*piVar3 + 0x68))();

  pppuStack_4c = (undefined ***)0xa977c4;

  FUN_00989e00(&ppuStack_34);

  pppuStack_4c = &ppuStack_34;

  FUN_009701d0();

  pvStack_30 = (void *)0x0;

  ppuStack_34 = &PTR_FUN_00a9db18;

  uStack_28 = 0;

  ppuStack_2c = &PTR_FUN_00a9da80;

  pppuStack_4c = (undefined ***)0xaa2e04;

  uStack_4._0_1_ = 1;

  uStack_4._1_3_ = 0;

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x26e,1);

  if (piVar3[3] == 0) {

    iVar6 = 0;

  }

  else {

    iVar6 = *(int *)(piVar3[3] + 0x1c);

  }

  if (piVar3[5] == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = *(uint32_t /* width from decompiler */ *)(piVar3[5] + 0x18);

  }

  pppuStack_4c = (undefined ***)(iVar6 / 3);

  uVar4 = FUN_0076cec0(&param_1,"Initial Mesh Piece Contains: %d verts, %d faces",uVar4);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x270,1,uVar4)

  ;

  pppuStack_4c = (undefined ***)0x100c;

  uVar4 = FUN_00414bc0();

  pppuStack_4c = (undefined ***)0x0;

  uStack_4._0_1_ = 2;

  FUN_00414c20(local_38,uVar4,8);

  uStack_4 = CONCAT31(uStack_4._1_3_,1);

  pppuStack_4c = (undefined ***)0x994d9b;

  FUN_00414b60();

  pppuStack_4c = (undefined ***)0x0;

  FUN_0044b9c0(iVar5,8,0);

  FUN_0044bbc0(piVar3 + 4,0,0);

  FUN_00450e60(piVar3 + 2,0,0,0);

  iVar5 = FUN_00994b40();

  if (iVar5 < 0) {

    (**(code **)*piVar3)(1);

    uStack_18 = uStack_18 & 0xffffff00;

    if (unaff_EBX != (int *)0x0) {

      piVar3 = unaff_EBX + 1;

      *piVar3 = *piVar3 + -1;

      if (*piVar3 == 0) {

        (**(code **)(*unaff_EBX + 8))();

      }

    }

    uStack_18 = 0xffffffff;

    if (unaff_EBP != (int *)0x0) {

      piVar3 = unaff_EBP + 1;

      *piVar3 = *piVar3 + -1;

      if (*piVar3 == 0) {

        (**(code **)(*unaff_EBP + 8))();

      }

    }

    ExceptionList = apvStack_20[0];

    return (int *)0x0;

  }

  if (local_38 == (int *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = local_38[7];

  }

  piVar3[0x2a] = iVar5 / 3;

  iVar5 = *(int *)(piVar3[8] + 8);

  cVar2 = FUN_00445050();

  if (cVar2 == '\0') {

    FUN_004451c0(&ppuStack_34,**(int **)(iVar5 + 0x50) + 0xac);

    uStack_14 = 4;

    FUN_00746c40(*(uint32_t /* width from decompiler */ *)((int)local_c + 0xb0));

    if (unaff_EDI == (int *)0x0) {

      iVar5 = 0;

    }

    else {

      iVar5 = unaff_EDI[6];

    }

    piVar3[0x2f] = piVar3[0x2f] | 1;

    FUN_00414c20(iVar5,&ppuStack_34,0x20,0);

  }

  else {

    uVar4 = FUN_00414bc0(0x1018);

    uStack_14 = 3;

    if (unaff_EDI == (int *)0x0) {

      iVar5 = 0;

    }

    else {

      iVar5 = unaff_EDI[6];

    }

    piVar3[0x2f] = piVar3[0x2f] | 1;

    FUN_00414c20(iVar5,uVar4,0x20,0);

  }

  uStack_14 = 1;

  FUN_00414b60();

  piVar3[0x2f] = piVar3[0x2f] | 1;

  FUN_0044bbc0(&stack0xffffffbc,0,0);

  if (local_38 == (int *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = local_38[7];

  }

  FUN_0044b9c0(iVar5,0x20,0,0);

  FUN_00450e60(&pppuStack_4c,0,0,0);

  iVar5 = (**(code **)(*piVar3 + 0x50))(0x5400000);

  if (iVar5 < 0) {

    uVar4 = FUN_0076cec0(apvStack_20,"Unable to optimize shadow mesh");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x2a9,2,

                   uVar4);

  }

  piVar3[0x2f] = piVar3[0x2f] | 0x20;

  uStack_28 = uStack_28 & 0xffffff00;

  if (local_38 != (int *)0x0) {

    piVar1 = local_38 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*local_38 + 8))();

    }

  }

  uStack_28 = 0xffffffff;

  if (unaff_EDI != (int *)0x0) {

    piVar1 = unaff_EDI + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*unaff_EDI + 8))();

    }

  }

  ExceptionList = pvStack_30;

  return piVar3;

}
