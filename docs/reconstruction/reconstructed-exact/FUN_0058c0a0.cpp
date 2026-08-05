// =============================================================================
// FUN_0058c0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058c0a0
// Address:   0x0058c0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058c0a0 @ 0x0058c0a0
// Stable ID: aa_0058c0a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×14, goto×6, return×3.
//  - Notable callees: FUN_00404a20×3, FUN_004e8a40×3, FUN_00404c90, FUN_004cb590, FUN_004e9aa0, FUN_004f70f0, FUN_00567ce0, FUN_0058c0a0.
//  - Return sites: 3.

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

float10 FUN_0058c0a0(int *param_1,int *param_2,float param_3,float param_4,uint32_t /* width from decompiler */ param_5,

                    char param_6)



{

  float fVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  int *piVar7;

  int iVar8;

  float10 fVar9;

  float fStack_44;

  int iStack_40;

  int iStack_3c;

  int iStack_38;

  int iStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint8_t auStack_20 [28];

  

  if ((param_2 == param_1) || (param_2 == (int *)param_1[0x2b])) {

LAB_0058c127:

    return (float10)g_flOne;

  }

  iVar3 = (**(code **)(*param_2 + 0x1c8))();

  iVar8 = 0;

  fStack_44 = 0.0;

  iVar4 = (**(code **)(*param_2 + 0x214))();

  if (iVar4 != 0) {

    fStack_44 = (float)(**(code **)(*param_2 + 0x214))();

    iVar8 = *(int *)((int)fStack_44 + 0x250);

    if ((((iVar8 != 0) && (iVar4 = (**(code **)(*param_1 + 0x1d4))(), iVar4 != 0)) &&

        (iVar4 = (**(code **)(*param_1 + 0x1d4))(), iVar4 == iVar8)) ||

       (iVar4 = (**(code **)(*param_1 + 0x1d8))(), (float)iVar4 == fStack_44)) goto LAB_0058c127;

  }

  piVar6 = (int *)param_1[0x2b];

  if ((piVar6 != (int *)0x0) && ((*(int *)(piVar6[0x2a] + 0x38) == 0xe || (piVar6 == param_2)))) {

    if (iVar8 == 0) {

      piVar7 = (int *)0x0;

    }

    else {

      piVar7 = (int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8);

    }

    if ((piVar6 == piVar7) && (cVar2 = FUN_004f70f0(param_1[0x58],param_1[0x59]), cVar2 == '\0'))

    goto LAB_0058c127;

    goto LAB_0058c187;

  }

  if (((iVar3 == 0) || (*(int *)(iVar3 + 8) == 0)) && (iVar8 == 0)) goto LAB_0058c127;

  uStack_30 = DAT_00af32a0;

  uStack_2c = DAT_00af32a4;

  uStack_28 = DAT_00af32a8;

  uStack_24 = DAT_00af32ac;

  iStack_40 = DAT_00b04dd0;

  iStack_3c = DAT_00b04dd4;

  iStack_38 = DAT_00b04dd8;

  iStack_34 = DAT_00b04ddc;

  if (((iVar8 == 0) || (fStack_44 == 0.0)) || (*(char *)((int)fStack_44 + 0x30c) == '\0')) {

    if (iVar3 != 0) {

      uVar5 = FUN_00404a20(&uStack_30);

      FUN_004e8a40(uVar5);

      if (((fStack_44 != 0.0) &&

          (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((int)fStack_44 + 4) + 4) + 0xac +

                                     (int)fStack_44) + 0x3c) + 0x4e8) == 1)) && (param_6 == '\0')) {

        FUN_00567ce0(&DAT_00af3290,*(uint32_t /* width from decompiler */ *)((int)fStack_44 + 0x11c));

        uVar5 = FUN_00404a20();

        FUN_004cb590(uVar5);

        FUN_004e8a40(auStack_20,&uStack_30);

      }

      goto LAB_0058c2ba;

    }

  }

  else {

    uVar5 = FUN_00404a20(&uStack_30);

    FUN_004e8a40(uVar5);

LAB_0058c2ba:

    piVar6 = (int *)FUN_00404c90();

    iStack_40 = *piVar6;

    iStack_3c = piVar6[1];

    iStack_38 = piVar6[2];

    iStack_34 = piVar6[3];

  }

  fStack_44 = g_flOne;

  if (iVar3 == 0) {

LAB_0058c351:

    uVar5 = 0;

  }

  else {

    iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x19c))();

    if (iVar8 != 0) {

      iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x19c))();

      fStack_44 = *(float *)(iVar8 + 0x34);

    }

    iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x210))(0);

    if (iVar8 == 0) goto LAB_0058c351;

    uVar5 = 1;

  }

  uVar5 = (**(code **)(*param_1 + 0x1c8))(&uStack_30,param_5,uVar5);

  fVar9 = (float10)FUN_004e9aa0(&iStack_40,fStack_44,param_4,uVar5);

  fVar1 = (float)fVar9;

  if ((param_3 <= fVar1) && (fVar1 <= param_4)) {

    return (float10)fVar1;

  }

LAB_0058c187:

  return (float10)g_flZero;

}
