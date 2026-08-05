// =============================================================================
// FUN_004f6a80
// -----------------------------------------------------------------------------
// Stable ID: aa_004f6a80
// Address:   0x004f6a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f6a80 @ 0x004f6a80
// Stable ID: aa_004f6a80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~161 non-empty decompiler lines.
//  - Control keywords: if×33, return×19.
//  - Notable callees: FUN_004ce5f0, FUN_004f6a80, FUN_005714e0, __RTDynamicCast.
//  - Return sites: 19.

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

uint32_t /* width from decompiler */ __thiscall FUN_004f6a80(int param_1,int *param_2)



{

  byte bVar1;

  short sVar2;

  int iVar3;

  int *piVar4;

  char cVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar4 = param_2;

  if (param_2 == (int *)0x0) {

    return 8;

  }

  iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if ((iVar7 != 0) && (*(char *)(iVar7 + 0xf6) != '\0')) {

    return 0xf;

  }

  uStack_4 = param_1;

  cVar5 = FUN_005714e0(param_2,(int)&uStack_4 + 3,&param_2,1,0xffffffff);

  if (cVar5 == '\0') {

    return 2;

  }

  iVar7 = *(int *)(piVar4[0x2a] + 0x38);

  if (iVar7 == 0xc) {

    iVar6 = (**(code **)(*piVar4 + 0x1e0))();

    iVar7 = *(int *)(*(int *)(iVar6 + 4) + 4) + iVar6;

    if (*(int *)(iVar7 + 0xac) == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(*(int *)(iVar7 + 0xac) + 0x3c);

    }

    if (*(char *)(iVar8 + 0x3f4) == '\t') {

      iVar6 = *(int *)(param_1 + 0x264);

      if (((iVar6 != 0) &&

          (iVar8 = *(int *)(*(int *)(iVar6 + 4) + 4),

          *(int *)(iVar7 + 0x164) == *(int *)(iVar8 + 0x164 + iVar6))) &&

         (*(int *)(iVar7 + 0x168) == *(int *)(iVar8 + 0x168 + iVar6))) {

        return 0;

      }

    }

    else {

      bVar1 = *(byte *)(iVar6 + 0xc4);

      if ((bVar1 & 2) == 0) {

        if ((bVar1 & 0x10) == 0) {

          if (((((bVar1 & 4) != 0) && (iVar6 = *(int *)(*(int *)(param_1 + 0x260) + 8), iVar6 != 0))

              && (iVar8 = *(int *)(*(int *)(iVar6 + 4) + 4),

                 *(int *)(iVar7 + 0x164) == *(int *)(iVar8 + 0x164 + iVar6))) &&

             (*(int *)(iVar7 + 0x168) == *(int *)(iVar8 + 0x168 + iVar6))) {

            return 0;

          }

        }

        else {

          iVar6 = *(int *)(*(int *)(param_1 + 0x260) + 4);

          if (((iVar6 != 0) &&

              (iVar8 = *(int *)(*(int *)(iVar6 + 4) + 4),

              *(int *)(iVar7 + 0x164) == *(int *)(iVar8 + 0x164 + iVar6))) &&

             (*(int *)(iVar7 + 0x168) == *(int *)(iVar8 + 0x168 + iVar6))) {

            return 0;

          }

        }

      }

      else {

        iVar6 = **(int **)(param_1 + 0x260);

        if (((iVar6 != 0) &&

            (iVar8 = *(int *)(*(int *)(iVar6 + 4) + 4),

            *(int *)(iVar7 + 0x164) == *(int *)(iVar8 + 0x164 + iVar6))) &&

           (*(int *)(iVar7 + 0x168) == *(int *)(iVar8 + 0x168 + iVar6))) {

          return 0;

        }

      }

    }

  }

  else if (iVar7 == 0x1c) {

    iVar6 = (**(code **)(*piVar4 + 0x1f8))();

    iVar7 = *(int *)(param_1 + 0x254);

    if (iVar7 != 0) {

      iVar8 = *(int *)(*(int *)(iVar7 + 4) + 4);

      iVar3 = *(int *)(*(int *)(iVar6 + 4) + 4);

      if ((*(int *)(iVar3 + 0x164 + iVar6) == *(int *)(iVar8 + 0x164 + iVar7)) &&

         (*(int *)(iVar3 + 0x168 + iVar6) == *(int *)(iVar8 + 0x168 + iVar7))) {

        return 0;

      }

    }

  }

  else if (iVar7 == 10) {

    iVar6 = (**(code **)(*piVar4 + 500))();

    iVar7 = *(int *)(param_1 + 0x268);

    if (iVar7 != 0) {

      iVar8 = *(int *)(*(int *)(iVar7 + 4) + 4);

      iVar3 = *(int *)(*(int *)(iVar6 + 4) + 4);

      if ((*(int *)(iVar3 + 0x164 + iVar6) == *(int *)(iVar8 + 0x164 + iVar7)) &&

         (*(int *)(iVar3 + 0x168 + iVar6) == *(int *)(iVar8 + 0x168 + iVar7))) {

        return 0;

      }

    }

  }

  else if (iVar7 == 0x10) {

    iVar6 = (**(code **)(*piVar4 + 0x1f0))();

    iVar7 = *(int *)(param_1 + 600);

    if (iVar7 != 0) {

      iVar8 = *(int *)(*(int *)(iVar7 + 4) + 4);

      iVar3 = *(int *)(*(int *)(iVar6 + 4) + 4);

      if ((*(int *)(iVar3 + 0x164 + iVar6) == *(int *)(iVar8 + 0x164 + iVar7)) &&

         (*(int *)(iVar3 + 0x168 + iVar6) == *(int *)(iVar8 + 0x168 + iVar7))) {

        iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

        if ((iVar7 != 0) && (*(char *)(iVar7 + 0xf5) != '\0')) {

          return 0;

        }

        return 1;

      }

    }

  }

  else if (iVar7 == 6) {

    iVar7 = __RTDynamicCast(piVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0);

    sVar2 = *(short *)(*(int *)(piVar4[0x2a] + 0x3c) + 0x3f4);

    if (sVar2 == 10) {

      iVar6 = *(int *)(param_1 + 0x26c);

      if (iVar6 != 0) {

        iVar8 = *(int *)(*(int *)(iVar6 + 4) + 4);

        iVar3 = *(int *)(*(int *)(iVar7 + 4) + 4);

        if ((*(int *)(iVar3 + 0x164 + iVar7) == *(int *)(iVar8 + 0x164 + iVar6)) &&

           (*(int *)(iVar3 + 0x168 + iVar7) == *(int *)(iVar8 + 0x168 + iVar6))) {

          return 0;

        }

      }

    }

    else if ((sVar2 == 0xb) && (iVar6 = *(int *)(param_1 + 0x270), iVar6 != 0)) {

      iVar8 = *(int *)(*(int *)(iVar6 + 4) + 4);

      iVar3 = *(int *)(*(int *)(iVar7 + 4) + 4);

      if ((*(int *)(iVar3 + 0x164 + iVar7) == *(int *)(iVar8 + 0x164 + iVar6)) &&

         (*(int *)(iVar3 + 0x168 + iVar7) == *(int *)(iVar8 + 0x168 + iVar6))) {

        iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))

                          (0);

        if (iVar7 == 0) {

          return 0;

        }

        iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))

                          (0);

        if (*(char *)(iVar7 + 0x6b8) == '\0') {

          return 0;

        }

        return 0xd;

      }

    }

  }

  else if (iVar7 == 0xe) {

    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) == 0) {

      return 1;

    }

    cVar5 = FUN_004ce5f0(param_1);

    if (cVar5 == '\0') {

      return 1;

    }

    return 10;

  }

  return 8;

}
