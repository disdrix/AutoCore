// =============================================================================
// FUN_0093d110
// -----------------------------------------------------------------------------
// Stable ID: aa_0093d110
// Address:   0x0093d110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093d110 @ 0x0093d110
// Stable ID: aa_0093d110
// Embedded strings (evidence for future rename):
//   - "Only items in your cargo may be Reverse Engineered."
//   - "Broken items cannot be further Reverse Engineered."
//   - "You cannot Reverse Engineer crafting materials."
//   - "Cannot be Reverse Engineered."
//   - "This item has no associated recipe."
//   - "Are you sure you wish to reverse engineer this object? (This will make it unequippable/unu"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×19, return×11, goto×6, switch×1.
//  - Notable callees: FUN_00571b60×10, FUN_007fdfb0×8, FUN_007a6de0×7, FUN_0093bac0×4, __RTDynamicCast×2, FUN_00513e70, FUN_00522950, FUN_00571010.
//  - Strings: "Only items in your cargo may be Reverse Engineered."; "Broken items cannot be further Reverse Engineered."; "You cannot Reverse Engineer crafting materials."; "Cannot be Reverse Engineered.".
//  - Return sites: 11.

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

void FUN_0093d110(int *param_1)



{

  int iVar1;

  bool bVar2;

  bool bVar3;

  char cVar4;

  uint16_t uVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar9;

  TypeDescriptor *pTVar10;

  TypeDescriptor *pTVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  

  switch(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30c0)) {

  case 0:

    FUN_007a69d0();

    iVar8 = FUN_00571010(param_1[0x58],param_1[0x59]);

    if (iVar8 == 0) {

      uVar12 = 1;

      uVar9 = 0xffffffff;

      uVar7 = FUN_007a6de0("Only items in your cargo may be Reverse Engineered.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar7,uVar9,uVar12,iVar8);

      return;

    }

    if (((uint)param_1[0x5f] >> 0x13 & 1) != 0) {

      uVar13 = 0;

      uVar12 = 1;

      uVar9 = 0xffffffff;

      uVar7 = FUN_007a6de0("Broken items cannot be further Reverse Engineered.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar7,uVar9,uVar12,uVar13);

      return;

    }

    if (*(int *)(param_1[0x2a] + 0x38) == 0x1a) {

      uVar13 = 0;

      uVar12 = 1;

      uVar9 = 0xffffffff;

      uVar7 = FUN_007a6de0("You cannot Reverse Engineer crafting materials.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar7,uVar9,uVar12,uVar13);

      return;

    }

    cVar4 = FUN_00522950(param_1);

    if (cVar4 == '\0') {

      uVar13 = 0;

      uVar12 = 1;

      uVar9 = 0xffffffff;

      uVar7 = FUN_007a6de0("Cannot be Reverse Engineered.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar7,uVar9,uVar12,uVar13);

      return;

    }

    iVar8 = (**(code **)(*param_1 + 0x25c))();

    if ((1 < iVar8) && (cVar4 = FUN_00513e70(), cVar4 != '\0')) {

      uVar13 = 0;

      uVar12 = 1;

      uVar9 = 0xffffffff;

      uVar7 = FUN_007a6de0("You can not Reverse Engineer an item in a stack, please remove one item from the stack and Reverse Engineer the single item."

                           ,0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar7,uVar9,uVar12,uVar13);

      return;

    }

    iVar8 = FUN_00599dd0();

    uVar9 = 0;

    uVar7 = 1;

    if (iVar8 < 1) {

      uVar13 = 0xffffffff;

      uVar12 = FUN_007a6de0("This item has no associated recipe.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar12,uVar13,uVar7,uVar9);

      return;

    }

    uVar13 = 0x4e34;

    *(int *)(unaff_ESI + 0x3118) = param_1[0x58];

    *(int *)(unaff_ESI + 0x311c) = param_1[0x59];

    uVar12 = FUN_007a6de0("Are you sure you wish to reverse engineer this object? (This will make it unequippable/unusable)."

                          ,0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar12,uVar13,uVar7,uVar9);

    break;

  case 1:

  case 3:

    break;

  case 2:

    if ((*(int *)(unaff_ESI + 0xe98) != 0) && (cVar4 = FUN_00571b60(param_1), cVar4 != '\0')) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3108) = 3;

LAB_0093d191:

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x310c) = *(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x38);

      iVar8 = (**(code **)(*param_1 + 0x1e0))();

      if (iVar8 == 0) {

        uVar5 = *(uint16_t *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f4);

      }

      else {

        piVar6 = (int *)(**(code **)(*param_1 + 0x1e0))();

        uVar5 = (**(code **)(*piVar6 + 0x60))();

      }

      *(uint16_t *)(unaff_ESI + 0x3110) = uVar5;

      FUN_0093bac0(unaff_ESI,0);

      return;

    }

    if (((*(int *)(unaff_ESI + 0xe98) != 0) && (*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) != 0))

       && (cVar4 = FUN_00571b60(param_1), cVar4 != '\0')) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3108) = 1;

      goto LAB_0093d191;

    }

    goto LAB_0093d434;

  case 4:

    if (param_1 != (int *)0x0) {

      uVar12 = 0;

      pTVar11 = &CVOGTinkeringKit::RTTI_Type_Descriptor;

      pTVar10 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

      uVar9 = 0;

      uVar7 = CVOGReaction_ResolveObjectTarget

                        (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30f8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30fc));

      iVar8 = __RTDynamicCast(uVar7,uVar9,pTVar10,pTVar11,uVar12);

      if (iVar8 == 0) goto LAB_0093d434;

      bVar2 = false;

      bVar3 = false;

      if (((*(int *)(*(int *)(unaff_ESI + 0xe98) + 0xcbc) != 0) &&

          (cVar4 = FUN_00571b60(param_1), cVar4 != '\0')) ||

         ((iVar1 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar1 != 0 &&

          ((*(int *)(iVar1 + 0x2b0) != 0 && (cVar4 = FUN_00571b60(param_1), cVar4 != '\0')))))) {

        bVar2 = true;

      }

      if (((*(int *)(*(int *)(unaff_ESI + 0xe98) + 0xcbc) != 0) &&

          (cVar4 = FUN_00571b60(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8), cVar4 != '\0')) ||

         ((iVar1 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar1 != 0 &&

          ((*(int *)(iVar1 + 0x2b0) != 0 &&

           (cVar4 = FUN_00571b60(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8), cVar4 != '\0'))))))

      {

        bVar3 = true;

      }

      if ((bVar2) && (bVar3)) {

        FUN_0085f660();

        FUN_0093bac0(unaff_ESI,0);

        return;

      }

LAB_0093d41e:

      FUN_007fdfb0(unaff_ESI,"Both items must be in your locker and/or cargo!",0xffffffff,1,0);

LAB_0093d434:

      FUN_0093bac0(unaff_ESI,0);

      return;

    }

    break;

  case 5:

    if ((param_1 != (int *)0x0) && (*(int *)(unaff_ESI + 0xe98) != 0)) {

      uVar12 = 0;

      pTVar11 = &CVOGGadget::RTTI_Type_Descriptor;

      pTVar10 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

      uVar9 = 0;

      uVar7 = CVOGReaction_ResolveObjectTarget

                        (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3100),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3104));

      iVar8 = __RTDynamicCast(uVar7,uVar9,pTVar10,pTVar11,uVar12);

      if (iVar8 == 0) goto LAB_0093d434;

      bVar2 = false;

      bVar3 = false;

      if (((*(int *)(*(int *)(unaff_ESI + 0xe98) + 0xcbc) != 0) &&

          (cVar4 = FUN_00571b60(param_1), cVar4 != '\0')) ||

         ((iVar1 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar1 != 0 &&

          ((*(int *)(iVar1 + 0x2b0) != 0 && (cVar4 = FUN_00571b60(param_1), cVar4 != '\0')))))) {

        bVar2 = true;

      }

      if (((*(int *)(*(int *)(unaff_ESI + 0xe98) + 0xcbc) != 0) &&

          (cVar4 = FUN_00571b60(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8), cVar4 != '\0')) ||

         ((iVar1 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar1 != 0 &&

          ((*(int *)(iVar1 + 0x2b0) != 0 &&

           (cVar4 = FUN_00571b60(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8), cVar4 != '\0'))))))

      {

        bVar3 = true;

      }

      if ((bVar2) && (bVar3)) {

        FUN_0085fa20();

        FUN_0093bac0(unaff_ESI,0);

        return;

      }

      goto LAB_0093d41e;

    }

    break;

  default:

    goto switchD_0093d126_default;

  }

switchD_0093d126_default:

  return;

}
