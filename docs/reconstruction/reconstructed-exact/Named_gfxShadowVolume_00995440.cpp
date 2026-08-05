// READABILITY (auto CF):
//  - Body size: ~165 non-empty decompiler lines.
//  - Control keywords: if×18, return×5.
//  - Notable callees: vog_LogMessage×5, CONCAT31×3, FUN_00414b60×2, FUN_004380f0×2, FUN_0076cec0×2, FUN_009701d0, FUN_00989e00, FUN_00990b80.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp"; "Shadow contains no vertices"; "Shadow contains no faces"; "PalShadowProjection.fx".
//  - Return sites: 5.

// =============================================================================
// Named_gfxShadowVolume_00995440
// -----------------------------------------------------------------------------
// Stable ID: aa_00995440
// Address:   0x00995440  (autoassault.exe, image base 0x400000)
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

int * __fastcall Named_gfxShadowVolume_00995440(int *param_1)



{

  undefined **ppuVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uStack_48;

  undefined **ppuStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  undefined **ppuStack_3c;

  int *piStack_38;

  uint8_t auStack_34 [4];

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint8_t auStack_24 [4];

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b22f6;

  local_c = ExceptionList;

  if (param_1[5] == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = *(int *)(param_1[5] + 0x18);

  }

  if (param_1[3] == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = *(int *)(param_1[3] + 0x1c);

  }

  if (iVar7 < 3) {

    ExceptionList = &local_c;

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x191,1,

                   "Shadow contains no vertices");

    ExceptionList = local_c;

    return (int *)0x0;

  }

  if (iVar4 < 3) {

    ExceptionList = &local_c;

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x197,1,

                   "Shadow contains no faces");

    ExceptionList = local_c;

    return (int *)0x0;

  }

  ExceptionList = &local_c;

  piVar5 = (int *)(**(code **)(*param_1 + 0x7c))();

  if (piVar5 == (int *)0x0) {

    ExceptionList = local_c;

    return (int *)0x0;

  }

  FUN_00989e00(&uStack_48,"PalShadowProjection.fx");

  FUN_009701d0(&uStack_48);

  uStack_40 = 0;

  ppuStack_44 = &PTR_FUN_00a9db18;

  piStack_38 = (int *)0x0;

  ppuStack_3c = &PTR_FUN_00a9da80;

  uStack_30 = 0;

  uStack_2c = 0;

  uStack_28 = 0;

  uStack_4._0_1_ = 2;

  uStack_4._1_3_ = 0;

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x1a7,1,

                 "Creating Skinned Shadow Volume Object:");

  if (piVar5[3] == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = *(int *)(piVar5[3] + 0x1c);

  }

  if (piVar5[5] == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = *(uint32_t /* width from decompiler */ *)(piVar5[5] + 0x18);

  }

  uVar6 = FUN_0076cec0(&uStack_48,"Initial Mesh Piece Contains: %d verts, %d faces",uVar6,iVar7 / 3)

  ;

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x1a9,1,uVar6)

  ;

  uStack_20 = 0;

  uStack_1c = 0;

  uStack_18 = 0;

  uStack_14 = 0;

  pvStack_10 = (void *)0x0;

  uStack_4 = CONCAT31(uStack_4._1_3_,3);

  uStack_48 = CONCAT31(uStack_48._1_3_,(char)piVar5[0x33]);

  FUN_00990b80(uStack_48);

  FUN_009952b0(&ppuStack_44,&ppuStack_3c,auStack_34,auStack_24);

  uStack_48 = CONCAT31(uStack_48._1_3_,(char)piVar5[0x33]);

  iVar7 = FUN_00993a10(*(uint32_t /* width from decompiler */ *)(piVar5[0x32] + 0x14),uStack_48);

  piVar3 = piStack_38;

  if (iVar7 < 0) {

    (**(code **)*piVar5)(1);

    FUN_00414b60();

    puStack_8._0_1_ = 1;

    FUN_004380f0();

    puStack_8 = (uint8_t *)((uint)puStack_8._1_3_ << 8);

    if (ppuStack_3c != (undefined **)0x0) {

      ppuVar1 = ppuStack_3c + 1;

      *ppuVar1 = *ppuVar1 + -1;

      if (*ppuVar1 == (undefined *)0x0) {

        (**(code **)(*ppuStack_3c + 8))();

      }

    }

    puStack_8 = (uint8_t *)0xffffffff;

    if (ppuStack_44 != (undefined **)0x0) {

      ppuVar1 = ppuStack_44 + 1;

      *ppuVar1 = *ppuVar1 + -1;

      if (*ppuVar1 == (undefined *)0x0) {

        (**(code **)(*ppuStack_44 + 8))();

      }

    }

    ExceptionList = pvStack_10;

    return (int *)0x0;

  }

  if (piStack_38 == (int *)0x0) {

    iVar7 = 0;

  }

  else {

    iVar7 = piStack_38[7];

  }

  FUN_009951d0(iVar7);

  FUN_00994fd0(auStack_34);

  iVar7 = (**(code **)(*piVar5 + 0x50))(0x5400000);

  if (iVar7 < 0) {

    uVar6 = FUN_0076cec0(&stack0xffffffb4,"Unable to optimize shadow mesh");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x1bc,2,

                   uVar6);

  }

  piVar5[0x2f] = piVar5[0x2f] | 0x60;

  (**(code **)(*piVar5 + 0x68))();

  FUN_00414b60();

  puStack_8._0_1_ = 1;

  FUN_004380f0();

  puStack_8 = (uint8_t *)((uint)puStack_8._1_3_ << 8);

  if (piVar3 != (int *)0x0) {

    piVar2 = piVar3 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  puStack_8 = (uint8_t *)0xffffffff;

  if (ppuStack_44 != (undefined **)0x0) {

    ppuVar1 = ppuStack_44 + 1;

    *ppuVar1 = *ppuVar1 + -1;

    if (*ppuVar1 == (undefined *)0x0) {

      (**(code **)(*ppuStack_44 + 8))();

    }

  }

  ExceptionList = pvStack_10;

  return piVar5;

}
