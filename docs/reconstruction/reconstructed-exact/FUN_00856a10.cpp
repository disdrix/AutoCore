// =============================================================================
// FUN_00856a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00856a10
// Address:   0x00856a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00856a10 @ 0x00856a10
// Stable ID: aa_00856a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~257 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, goto×4, for×3, do×3, while×3.
//  - Notable callees: FUN_007a69d0×2, FUN_007a6de0×2, __RTDynamicCast×2, Client_MaybeShowFirstTimeTip, FUN_0040da70, FUN_0040f540, FUN_0048a780, FUN_00514050.
//  - Return sites: 6.

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

void __thiscall FUN_00856a10(int *param_1,int *param_2)



{

  char cVar1;

  short sVar2;

  int *piVar3;

  char *pcVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  uint uVar8;

  char *pcVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ *puVar11;

  char *pcVar12;

  uint32_t /* width from decompiler */ uStack_2b0;

  TypeDescriptor ***pppTStack_2ac;

  uint32_t /* width from decompiler */ uStack_2a8;

  uint32_t /* width from decompiler */ uStack_2a4;

  int *piStack_2a0;

  uint32_t /* width from decompiler */ *puStack_29c;

  uint32_t /* width from decompiler */ uStack_298;

  uint8_t **ppuStack_294;

  uint32_t /* width from decompiler */ uStack_290;

  int iStack_28c;

  TypeDescriptor **ppTStack_288;

  uint32_t /* width from decompiler */ uStack_284;

  uint8_t **ppuStack_280;

  uint32_t /* width from decompiler */ uStack_27c;

  uint32_t /* width from decompiler */ uStack_278;

  uint32_t /* width from decompiler */ uStack_274;

  int **ppiStack_270;

  uint32_t /* width from decompiler */ uStack_26c;

  uint8_t *puStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  int iStack_260;

  int *piStack_25c;

  uint8_t *puStack_258;

  TypeDescriptor *pTStack_254;

  TypeDescriptor *pTStack_250;

  uint8_t *puStack_24c;

  uint8_t auStack_238 [39];

  char cStack_211;

  char acStack_210 [2];

  uint32_t /* width from decompiler */ auStack_20e [58];

  uint8_t auStack_124 [8];

  uint8_t auStack_11c [280];

  

  puStack_24c = (uint8_t *)0x856a26;

  (**(code **)(*param_1 + 0x58))();

  param_1[0x122] = 0;

  *(uint8_t *)(param_1 + 0x123) = 1;

  if (param_2 == (int *)0x0) {

LAB_00856e63:

    puStack_24c = (uint8_t *)0x0;

    pTStack_250 = (TypeDescriptor *)0x856e6c;

    (**(code **)(*param_1 + 4))();

    *(uint8_t *)(param_1 + 0x123) = 0;

    return;

  }

  iVar7 = *(int *)(param_2[0x2a] + 0x3c);

  if (((*(char *)(iVar7 + 0x406) == '\0') || (*(char *)(iVar7 + 0x407) == '\0')) ||

     (DAT_00d1a8dd != '\0')) goto LAB_00856e63;

  iVar5 = *(int *)(param_2[0x2a] + 0x38);

  if ((iVar5 == 6) && ((*(byte *)(iVar7 + 0x3f2) & 0x80) != 0)) {

    puStack_24c = (uint8_t *)0x24;

  }

  else {

    if (iVar5 == 0xc) {

      puStack_24c = (uint8_t *)0x0;

      pTStack_250 = &CVOGWeapon::RTTI_Type_Descriptor;

      pTStack_254 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

      puStack_258 = (uint8_t *)0x0;

      piStack_25c = param_2;

      iStack_260 = 0x856aa6;

      __RTDynamicCast();

      puStack_24c = (uint8_t *)0x856ab0;

      iVar7 = FUN_0040da70();

      if (*(char *)(iVar7 + 0x3f4) == '\t') {

        puStack_24c = (uint8_t *)0x2c;

        goto LAB_00856ae5;

      }

    }

    if ((*(int *)(param_2[0x2a] + 0x38) != 6) ||

       (*(short *)(*(int *)(param_2[0x2a] + 0x3c) + 0x3f4) != 0xb)) goto LAB_00856aef;

    puStack_24c = (uint8_t *)0x856add;

    sVar2 = FUN_0040f540();

    if (sVar2 < 0x28) goto LAB_00856aef;

    puStack_24c = (uint8_t *)0x2d;

  }

LAB_00856ae5:

  pTStack_250 = (TypeDescriptor *)0x856aef;

  Client_MaybeShowFirstTimeTip();

LAB_00856aef:

  if (DAT_00d1e450 != (uint8_t *)0x0) {

    puStack_24c = DAT_00d1e450;

    pTStack_250 = (TypeDescriptor *)PTR_s_LED_FX_LED_FX_pickup_item_xml_00b00264;

    pTStack_254 = (TypeDescriptor *)0x856b05;

    FUN_0048a780();

  }

  puStack_24c = auStack_238;

  pTStack_250 = (TypeDescriptor *)0x856b14;

  piVar3 = (int *)FUN_00514050();

  param_1[0x126] = *piVar3;

  acStack_210[0] = '\0';

  acStack_210[1] = '\0';

  puVar11 = auStack_20e;

  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar11 = 0;

    puVar11 = puVar11 + 1;

  }

  uVar8 = param_2[0x5f];

  *(uint16_t *)puVar11 = 0;

  if ((uVar8 >> 0x13 & 1) != 0) {

    puStack_24c = (uint8_t *)0xffffffff;

    pTStack_250 = (TypeDescriptor *)0xa2fb18;

    pTStack_254 = (TypeDescriptor *)0x856b4c;

    FUN_007a69d0();

    pTStack_254 = (TypeDescriptor *)0x856b53;

    pcVar4 = (char *)FUN_007a6de0();

    pcVar9 = acStack_210;

    do {

      cVar1 = *pcVar4;

      *pcVar9 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

  }

  puStack_24c = (uint8_t *)0xffffffff;

  pTStack_250 = (TypeDescriptor *)0x856b71;

  pTStack_250 = (TypeDescriptor *)(**(code **)(*param_2 + 0x15c))();

  pTStack_254 = (TypeDescriptor *)0x856b77;

  FUN_007a69d0();

  pTStack_254 = (TypeDescriptor *)0x856b7e;

  pcVar4 = (char *)FUN_007a6de0();

  pcVar9 = pcVar4;

  do {

    cVar1 = *pcVar9;

    pcVar9 = pcVar9 + 1;

  } while (cVar1 != '\0');

  pcVar12 = &cStack_211;

  do {

    pcVar10 = pcVar12 + 1;

    pcVar12 = pcVar12 + 1;

  } while (*pcVar10 != '\0');

  pcVar10 = pcVar4;

  for (uVar8 = (uint)((int)pcVar9 - (int)pcVar4) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar10;

    pcVar10 = pcVar10 + 4;

    pcVar12 = pcVar12 + 4;

  }

  iVar7 = *param_1;

  puStack_24c = (uint8_t *)0x0;

  for (uVar8 = (int)pcVar9 - (int)pcVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

    *pcVar12 = *pcVar10;

    pcVar10 = pcVar10 + 1;

    pcVar12 = pcVar12 + 1;

  }

  pTStack_250 = (TypeDescriptor *)0x1;

  pTStack_254 = (TypeDescriptor *)acStack_210;

  puStack_258 = (uint8_t *)0x856bbd;

  (**(code **)(iVar7 + 0x1d8))();

  puStack_258 = auStack_11c;

  piStack_25c = param_2;

  iStack_260 = 0x856bce;

  FUN_0085d970();

  puStack_258 = (uint8_t *)(uint)*(byte *)(*(int *)(param_2[0x2a] + 0x3c) + 0x407);

  piStack_25c = (int *)(uint)*(byte *)(*(int *)(param_2[0x2a] + 0x3c) + 0x406);

  iStack_260 = 0x856bf4;

  (**(code **)(*param_1 + 0x3b0))();

  iVar7 = *param_1;

  iStack_260 = 0;

  uStack_264 = 0x856c00;

  uStack_264 = (**(code **)(iVar7 + 0x2c8))();

  puStack_268 = auStack_124;

  uStack_26c = 0x856c0e;

  (**(code **)(iVar7 + 0x50))();

  uStack_26c = 1;

  ppiStack_270 = (int **)0x856c1a;

  (**(code **)(*param_1 + 0xcc))();

  ppiStack_270 = (int **)0x856c24;

  (**(code **)(*param_1 + 0x34c))();

  piStack_25c = (int *)(int)((float)(int)(float)param_1[0x95] * (float)DAT_00d1e818 * DAT_00aaa67c);

  puStack_258 = (uint8_t *)

                (int)((float)((int)((uint)*(byte *)(*(int *)(param_2[0x2a] + 0x3c) + 0x406) *

                                   (int)(float)param_1[0x96]) /

                             (int)(uint)*(byte *)(*(int *)(param_2[0x2a] + 0x3c) + 0x407)) *

                      (float)DAT_00d1e81c * DAT_00aaa678);

  ppiStack_270 = &piStack_25c;

  uStack_274 = 0x856ca0;

  (**(code **)(*param_1 + 300))();

  piStack_25c = (int *)(int)(float)param_1[0x94];

  iStack_260 = (int)(float)param_1[0x93];

  iVar7 = *param_1;

  uStack_274 = 0x856cc7;

  uStack_274 = FUN_007aa870();

  uStack_278 = 0x856cd0;

  (**(code **)(iVar7 + 0x110))();

  uStack_278 = 0;

  uStack_27c = 1;

  ppuStack_280 = &puStack_24c;

  uStack_284 = 0x856ce3;

  iVar5 = (**(code **)(*param_1 + 0x120))();

  uStack_284 = 1;

  ppTStack_288 = &pTStack_250;

  iStack_28c = 0x856cf6;

  iVar7 = (**(code **)(*param_1 + 0x140))();

  iVar7 = *(int *)(iVar7 + 4);

  iVar5 = *(int *)(iVar5 + 4);

  iStack_28c = 0;

  uStack_290 = 1;

  ppuStack_294 = &puStack_268;

  uStack_298 = 0x856d16;

  piVar3 = (int *)(**(code **)(*param_1 + 0x120))();

  uStack_298 = 1;

  puStack_29c = &uStack_27c;

  piStack_2a0 = (int *)0x856d29;

  piVar6 = (int *)(**(code **)(*param_1 + 0x140))();

  iStack_28c = *piVar3 - *piVar6 / 2;

  piStack_2a0 = &iStack_28c;

  uStack_2a4 = 0x856d4b;

  ppTStack_288 = (TypeDescriptor **)(iVar5 - iVar7 / 2);

  (**(code **)(*param_1 + 0x110))();

  iVar7 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);

  uStack_2a4 = 0;

  uStack_2a8 = 1;

  pppTStack_2ac = &ppTStack_288;

  uStack_2b0 = 0x856d73;

  piVar3 = (int *)(**(code **)(*param_1 + 0x120))();

  iVar5 = *piVar3;

  uStack_2b0 = 1;

  piVar3 = (int *)(**(code **)(*param_1 + 0x140))(&iStack_28c);

  param_1[0x124] = *piVar3 / 2 + iVar5;

  param_1[0x125] = (int)(float)iVar7;

  if (DAT_00d1b8f0 == (int *)0x0) {

    return;

  }

  cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))();

  if (cVar1 == '\0') {

    return;

  }

  if (DAT_00d1b8f0[0x199] == 0) {

    return;

  }

  iVar7 = __RTDynamicCast(DAT_00d1b8f0[0x199],0,&CVOGMenu::RTTI_Type_Descriptor,

                          &CMenuQuickBar::RTTI_Type_Descriptor,0);

  if (*(int *)(iVar7 + 0x568) == 0) {

    return;

  }

  iVar5 = 1;

  puVar11 = &uStack_2a4;

  (**(code **)(**(int **)(iVar7 + 0x568) + 0x120))(puVar11,1,1);

  (**(code **)(**(int **)(iVar7 + 0x568) + 0x140))(&uStack_2a8,1);

  iVar7 = (**(code **)(**(int **)(iVar7 + 0x568) + 0x140))(&uStack_2b0,1);

  iVar7 = *(int *)(iVar7 + 4);

  param_1[0x124] = (int)puVar11;

  param_1[0x125] = iVar7 / 2 + iVar5;

  return;

}
