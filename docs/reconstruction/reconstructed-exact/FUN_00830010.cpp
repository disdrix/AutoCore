// =============================================================================
// FUN_00830010
// -----------------------------------------------------------------------------
// Stable ID: aa_00830010
// Address:   0x00830010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00830010 @ 0x00830010
// Stable ID: aa_00830010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×22, return×4, goto×3, switch×2.
//  - Notable callees: FUN_0090d400×2, FUN_00573a30, FUN_00573af0, FUN_00573bb0, FUN_00574880, FUN_008011e0, FUN_008073b0, FUN_00830010.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_00830010(int *param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ auStack_10 [2];

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (param_2 != 8) {

LAB_008305fa:

    if (param_3 == 70000) {

      switch(param_2) {

      case 8:

      case 0xb:

        goto LAB_008300d7;

      case 10:

      case 0xd:

        FUN_0090d400();

        return 0;

      }

    }

    cVar2 = (**(code **)(*param_1 + 0xd8))();

    if ((cVar2 != '\0') && (param_1[0xac] != 0)) {

      uVar7 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

      return uVar7;

    }

    return 0;

  }

  piVar3 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x15e));

  if ((piVar3 == (int *)0x0) ||

     (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x298))(piVar3), cVar2 != '\0')) goto LAB_008300d7;

  switch(param_3) {

  case 0x11171:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if (iVar6 != 0) {

      iVar6 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x160))();

      if (iVar6 != 0) {

        iVar6 = (**(code **)(*piVar3 + 0x210))(0);

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x160))();

        FUN_008011e0(&DAT_00d1a840);

      }

    }

    break;

  case 0x11172:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if (((iVar6 != 0) && (DAT_00d1b6d8 != 0)) &&

       ((*(int *)(DAT_00d1b6d8 + 0xcb0) != 0 && (iVar6 = FUN_00574880(), iVar6 == DAT_00d1b6d8)))) {

      auStack_10[0] = 0x800b;

      iVar4 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = *(int *)(*(int *)(iVar4 + 4) + 4);

      uStack_8 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar4);

      uStack_4 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar4);

      FUN_008073b0(0x10,auStack_10);

    }

    break;

  case 0x11173:

    if (((DAT_00d1da30 != 0) && (DAT_00d1b6d8 != 0)) &&

       (iVar6 = (**(code **)(*piVar3 + 0x210))(0), iVar6 != 0)) {

      iVar4 = (**(code **)(*piVar3 + 0x210))(0);

      iVar5 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = *(int *)(*(int *)(iVar5 + 4) + 4);

      uVar7 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar5);

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar5);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))();

      FUN_0094bfe0(uVar7,uVar1);

    }

    break;

  case 0x11174:

    if (((DAT_00d1da30 != 0) && (DAT_00d1b6d8 != 0)) &&

       (iVar6 = (**(code **)(*piVar3 + 0x210))(0), iVar6 != 0)) {

      iVar4 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = *(int *)(*(int *)(iVar4 + 4) + 4);

      FUN_0094c150(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar4),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar4));

    }

    break;

  case 0x11175:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if ((iVar6 != 0) && (DAT_00d1b6d8 != 0)) {

      iVar5 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = *(int *)(*(int *)(iVar5 + 4) + 4);

      iVar4 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

      FUN_0094c8b0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x164 + DAT_00d1b6d8),

                   *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + DAT_00d1b6d8),

                   *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar5),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar5));

    }

    break;

  case 0x11176:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if ((iVar6 != 0) && (DAT_00d1b978 != (int *)0x0)) {

      cVar2 = (**(code **)(*DAT_00d1b978 + 0x3d8))();

      if (cVar2 == '\0') {

        (**(code **)(*(int *)*DAT_00d1b780 + 0x338))(8,0x4e2a);

      }

      iVar6 = *DAT_00d1b978;

      DAT_00d1b978[0x144] = 2;

      (**(code **)(iVar6 + 0x444))();

      if (DAT_00d1b978[0x68ad] != 0) {

        iVar4 = (**(code **)(*piVar3 + 0x210))(0);

        iVar6 = *(int *)DAT_00d1b978[0x68ad];

        uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))();

        (**(code **)(iVar6 + 0x3ac))(uVar7);

        (**(code **)(*(int *)DAT_00d1b978[0x68ad] + 0x34c))();

      }

    }

    break;

  case 0x11177:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if (iVar6 != 0) {

      iVar4 = (**(code **)(*piVar3 + 0x210))(0);

      iVar5 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = *(int *)(*(int *)(iVar5 + 4) + 4);

      uVar7 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar5);

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar5);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))();

      FUN_0094d900(uVar7,uVar1);

    }

    break;

  case 0x11178:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if (iVar6 != 0) {

      iVar4 = (**(code **)(*piVar3 + 0x210))(0);

      iVar5 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = *(int *)(*(int *)(iVar5 + 4) + 4);

      uVar7 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar5);

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar5);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))();

      FUN_0094d380(uVar7,uVar1);

    }

    break;

  case 0x11179:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if (iVar6 != 0) {

      iVar4 = (**(code **)(*piVar3 + 0x210))(0);

      iVar5 = (**(code **)(*piVar3 + 0x210))(0);

      iVar6 = *(int *)(*(int *)(iVar5 + 4) + 4);

      uVar7 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar5);

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar5);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))();

      FUN_0094d700(uVar7,uVar1);

    }

    break;

  case 0x1117a:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if ((iVar6 != 0) && (DAT_00d1da2c != 0)) {

      iVar6 = (**(code **)(*piVar3 + 0x210))(0);

      uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x160))();

      iVar6 = FUN_00573a30(uVar7);

      if (iVar6 != 0) {

        FUN_0094c680(*(uint32_t /* width from decompiler */ *)(iVar6 + 8),*(uint32_t /* width from decompiler */ *)(iVar6 + 0xc));

      }

    }

    break;

  case 0x1117b:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if ((iVar6 != 0) && (DAT_00d1da2c != 0)) {

      iVar6 = (**(code **)(*piVar3 + 0x210))(0);

      uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x160))();

      iVar6 = FUN_00573bb0(uVar7);

      if (iVar6 != 0) {

        FUN_0094c300(*(uint32_t /* width from decompiler */ *)(iVar6 + 8),*(uint32_t /* width from decompiler */ *)(iVar6 + 0xc));

      }

    }

    break;

  case 0x1117c:

    iVar6 = (**(code **)(*piVar3 + 0x210))(0);

    if ((iVar6 != 0) && (DAT_00d1da2c != 0)) {

      iVar6 = (**(code **)(*piVar3 + 0x210))(0);

      uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x160))();

      iVar6 = FUN_00573af0(uVar7);

      if (iVar6 != 0) {

        FUN_0094c630(*(uint32_t /* width from decompiler */ *)(iVar6 + 8),*(uint32_t /* width from decompiler */ *)(iVar6 + 0xc));

      }

    }

    break;

  case 0x1117d:

  case 0x1117e:

  case 0x1117f:

    break;

  default:

    goto LAB_008305fa;

  }

LAB_008300d7:

  FUN_0090d400();

  return 1;

}
