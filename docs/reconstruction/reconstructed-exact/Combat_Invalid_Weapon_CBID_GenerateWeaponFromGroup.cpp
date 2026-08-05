// =============================================================================
// Combat_Invalid_Weapon_CBID_GenerateWeaponFromGroup
// -----------------------------------------------------------------------------
// Stable ID: aa_0050a7d0
// Address:   0x0050a7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Combat_Invalid_Weapon_CBID_GenerateWeaponFromGroup @ 0x0050a7d0
// Stable ID: aa_0050a7d0
// Embedded strings (evidence for future rename):
//   - "() Invalid Weapon CBID in GenerateWeaponFromGroup: %i\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×17, return×6, while×1, goto×1.
//  - Notable callees: FUN_00404d70×3, CVOGReaction_RandomUnitScalar×2, FUN_004e1830×2, CVOGReaction_FailMissionNotify, FUN_00402130, FUN_004f1e20, FUN_00508770, Combat_Invalid_Weapon_CBID_GenerateWeaponFromGroup.
//  - Strings: "() Invalid Weapon CBID in GenerateWeaponFromGroup: %i\n".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "() Invalid Weapon CBID in GenerateWeaponFromGroup: %i
"
 * Domain alias of FUN_0050a7d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Combat_Invalid_Weapon_CBID_GenerateWeaponFromGroup(int param_1,void *param_2)



{

  ushort uVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  void *pvVar7;

  uint uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  int local_24;

  int local_20;

  void *local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a32a5;

  local_c = ExceptionList;

  pvVar7 = (void *)0x0;

  local_20 = 0;

  local_24 = -1;

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  if (param_1 < 1) {

    return 0;

  }

  ExceptionList = &local_c;

  iVar3 = FUN_0050fc90(param_1);

  if (iVar3 == 0) {

    ExceptionList = local_c;

    return 0;

  }

  if (*(int *)(iVar3 + 0x5c) != 0) {

    if (param_2 == (void *)0x0) {

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      cVar2 = FUN_0050e770((uint)uVar1 % *(uint *)(iVar3 + 0x5c),&local_24);

      iVar3 = local_24;

      if (cVar2 == '\0') {

        ExceptionList = local_c;

        return local_20;

      }

    }

    else {

      param_1 = 0;

      FUN_00402130(*(int *)(iVar3 + 0x5c));

      FUN_00508770();

      iVar5 = FUN_004e1830(&param_1,&local_24);

      iVar4 = local_24;

      while (local_24 = iVar4, iVar5 == 0) {

        iVar5 = FUN_00404d70(iVar4);

        if (iVar5 == 0) {

          FUN_007a4480(1,"() Invalid Weapon CBID in GenerateWeaponFromGroup: %i\n");

        }

        else {

          iVar6 = FUN_00404d70(iVar4);

          if (*(int *)(iVar6 + 0x3c) == 0) {

            uVar10 = 1;

            uVar9 = 1;

            FUN_00404d70(iVar4,1,1);

            FUN_004f1e20(uVar9,uVar10);

          }

          if (param_2 == (void *)(uint)*(byte *)(*(int *)(iVar5 + 0x3c) + 0x535)) {

            CVOGReaction_FailMissionNotify(&local_24);

          }

        }

        iVar5 = FUN_004e1830(&param_1,&local_24);

        iVar4 = local_24;

      }

      if (*(char *)(iVar3 + 0x60) != '\0') {

        *(uint8_t *)(iVar3 + 0x60) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x3c));

      }

      pvVar7 = local_18;

      iVar3 = local_24;

      if ((local_18 != (void *)0x0) && (uVar8 = local_14 - (int)local_18 >> 2, uVar8 != 0)) {

        iVar3 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar3 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

        iVar3 = *(int *)((int)pvVar7 + ((uint)uVar1 % uVar8) * 4);

      }

    }

    if (iVar3 != -1) {

      param_2 = operator_new(0x2e0);

      local_4._0_1_ = 1;

      if (param_2 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = FUN_0056e730(1);

      }

      local_4 = (uint)local_4._1_3_ << 8;

      local_20 = iVar4;

      if (iVar4 == 0) {

LAB_0050aa2b:

        FUN_00691630();

        ExceptionList = local_c;

        return 0;

      }

      iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 8))(iVar3,0,1);

      if (iVar3 < 0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4))(1);

        goto LAB_0050aa2b;

      }

    }

    if (pvVar7 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar7);

    }

  }

  ExceptionList = local_c;

  return local_20;

}
