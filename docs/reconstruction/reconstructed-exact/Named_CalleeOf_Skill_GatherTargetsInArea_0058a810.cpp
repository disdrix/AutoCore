// =============================================================================
// Named_CalleeOf_Skill_GatherTargetsInArea_0058a810
// -----------------------------------------------------------------------------
// Stable ID: aa_0058a810
// Callee of Skill_GatherTargetsInArea
// Address:   0x0058a810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_GatherTargetsInArea: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×34, return×25, goto×3.
//  - Notable callees: TFID_EqualsObjectId×3, FUN_00404c90×2, FUN_0040aff0, FUN_005130e0, FUN_005134e0, FUN_005749d0, FUN_0058a810.
//  - Return sites: 25.

/*
 * Behavioral notes:
 * Callee of Skill_GatherTargetsInArea
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t

Named_CalleeOf_Skill_GatherTargetsInArea_0058a810(int *param_1,int *param_2,void *param_3,int param_4,int param_5,char param_6,

            char param_7,int *param_8)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  bool bVar5;

  uint8_t auStack_10 [16];

  

  if (param_4 == 8) {

    *param_8 = param_1[0x20];

    param_8[1] = param_1[0x21];

    param_8[2] = param_1[0x22];

    param_8[3] = param_1[0x23];

    return 1;

  }

  if ((param_1 == (int *)0x0) || (param_1 == param_2)) {

    return 0;

  }

  cVar1 = (**(code **)(*param_1 + 0x198))();

  if ((cVar1 != '\0') && (param_4 != 10)) {

    return 0;

  }

  iVar2 = TFID_EqualsObjectId(param_1 + 0x58,param_3);

  if ((char)iVar2 != '\0') {

    return 0;

  }

  if ((param_6 == '\0') && (cVar1 = FUN_005134e0(), cVar1 != '\0')) {

    return 0;

  }

  if (((((uint)param_1[0x5f] >> 10 & 1) != 0) && (param_4 != 3)) && (param_7 == '\0')) {

    return 0;

  }

  iVar2 = *(int *)(param_1[0x2a] + 0x38);

  if (iVar2 == 0xe) {

    iVar4 = (**(code **)(*param_1 + 0x1d4))();

    if (*(char *)(iVar4 + 0x2ac) == '\0') {

      iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xb0 + iVar4);

      if ((iVar4 != 0) &&

         (iVar4 = TFID_EqualsObjectId((void *)(iVar4 + 0x160),param_3), (char)iVar4 != '\0')) {

        return 0;

      }

      piVar3 = (int *)FUN_00404c90();

      goto LAB_0058a9e9;

    }

    *param_8 = param_1[0x20];

    param_8[1] = param_1[0x21];

    param_8[2] = param_1[0x22];

    param_8[3] = param_1[0x23];

  }

  else {

    if (iVar2 == 0x12) {

      (**(code **)(*param_1 + 0x1d8))();

      piVar3 = (int *)FUN_00404c90();

    }

    else {

      if (iVar2 != 0x14) {

        if (param_5 == -1) {

          cVar1 = FUN_005130e0(1);

          if (cVar1 == '\0') {

            return 0;

          }

        }

        else if (param_5 != iVar2) {

          return 0;

        }

        *param_8 = param_1[0x20];

        param_8[1] = param_1[0x21];

        param_8[2] = param_1[0x22];

        param_8[3] = param_1[0x23];

        goto LAB_0058aa03;

      }

      iVar4 = (**(code **)(*param_1 + 0x1dc))();

      piVar3 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))

                                ();

    }

LAB_0058a9e9:

    *param_8 = *piVar3;

    param_8[1] = piVar3[1];

    param_8[2] = piVar3[2];

    param_8[3] = piVar3[3];

  }

LAB_0058aa03:

  if (param_4 == 2) {

LAB_0058ab30:

    cVar1 = (**(code **)(*param_2 + 0x298))(param_1);

    if (cVar1 == '\0') {

      return 0;

    }

  }

  else {

    if (param_4 == 1) {

      cVar1 = (**(code **)(*param_2 + 0x298))(param_1);

      bVar5 = cVar1 == '\0';

    }

    else {

      if (param_4 == 0xb) {

        iVar2 = (**(code **)(*param_2 + 0x210))(0);

        iVar4 = (**(code **)(*param_1 + 0x210))(0);

        if (iVar2 == 0) {

          return 0;

        }

        if (iVar2 == iVar4) {

          return 1;

        }

        if (*(int *)(iVar2 + 0xcb0) == 0) {

          return 0;

        }

        cVar1 = FUN_005749d0(iVar4);

        if (cVar1 != '\0') {

          return 1;

        }

        return 0;

      }

      if (param_4 == 0) {

        iVar2 = (**(code **)(*param_1 + 0x214))();

        if (iVar2 == 0) {

          bVar5 = param_2 == (int *)0x0;

        }

        else {

          bVar5 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) == param_2;

        }

      }

      else {

        if (param_4 != 3) {

          if (param_4 == 4) {

            iVar2 = (**(code **)(*param_1 + 0x214))();

            if (iVar2 == 0) {

              return 0;

            }

            iVar2 = (**(code **)(*param_2 + 0x214))();

            if (iVar2 == 0) {

              return 0;

            }

            FUN_0040aff0(auStack_10);

            iVar2 = (**(code **)(*param_2 + 0x214))();

            iVar2 = TFID_EqualsObjectId(auStack_10,

                                        (void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2))

            ;

            if ((char)iVar2 == '\0') {

              return 0;

            }

            return 1;

          }

          if (param_4 != 9) {

            return 1;

          }

          if (iVar2 == 3) {

            return 1;

          }

          goto LAB_0058ab30;

        }

        if (iVar2 == 0x12) {

          return 1;

        }

        if (iVar2 == 0x14) {

          return 1;

        }

        bVar5 = iVar2 == 0xe;

      }

    }

    if (!bVar5) {

      return 0;

    }

  }

  return 1;

}
