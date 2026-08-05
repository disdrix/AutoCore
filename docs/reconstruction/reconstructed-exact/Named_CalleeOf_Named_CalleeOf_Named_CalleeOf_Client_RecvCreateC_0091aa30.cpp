// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_0091aa30
// -----------------------------------------------------------------------------
// Stable ID: aa_0091aa30
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x0091aa30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×9, goto×3, return×2, for×1.
//  - Notable callees: FUN_0076df50×3, CVOGReaction_GiveItemByCbid, FUN_0040d1a0, FUN_0048f370, FUN_00555f10, FUN_0076f5f0, FUN_007a4480, FUN_0090dd50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_0091aa30(void)



{

  byte *pbVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  float fVar4;

  float fVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  int iVar8;

  int unaff_ESI;

  

  if ((*(char *)(DAT_00d1b644 + 0xf5) == '\0') &&

     (((DAT_00d1b6d8 == 0 || (*(int *)(DAT_00d1b6d8 + 0x250) == 0)) ||

      (*(char *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x101) == '\0')))) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x60c) = 1;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x60c) = 0;

  }

  FUN_0090dd50();

  iVar8 = DAT_00d17944;

  if (DAT_00d1b6d8 == 0) {

    *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x228) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar8 + 0x22c) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar8 + 0x230) = 0;

  }

  else {

    puVar6 = (uint32_t /* width from decompiler */ *)

             (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                         0x1a0))();

    iVar8 = DAT_00d17944;

    uVar2 = puVar6[1];

    uVar3 = puVar6[2];

    *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x228) = *puVar6;

    *(uint32_t /* width from decompiler */ *)(iVar8 + 0x22c) = uVar2;

    *(uint32_t /* width from decompiler */ *)(iVar8 + 0x230) = uVar3;

  }

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x220) = DAT_00aaa668;

  fVar4 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x21c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x224) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x210) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x214) = 0;

  *(float *)(iVar8 + 0x218) = fVar4;

  *(float *)(iVar8 + 0x204) = 0.0 - *(float *)(iVar8 + 0x220) * fVar4;

  *(float *)(iVar8 + 0x208) = fVar4 * 0.0 - 0.0;

  uVar2 = DAT_00a0f718;

  *(float *)(iVar8 + 0x20c) = *(float *)(iVar8 + 0x220) * 0.0 - 0.0;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x270) = uVar2;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x134) = DAT_00a110d8;

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0x130) = DAT_00a0f694;

  fVar5 = g_flLevelUpUiBase_Inferred;

  *(float *)(iVar8 + 0x264) = fVar4;

  *(float *)(iVar8 + 0x138) = fVar5;

  FUN_0040d1a0();

  iVar8 = *(int *)(DAT_00d1b644 + 0xe894);

  FUN_0076f5f0();

  fsin((float10)_DAT_00d1e490 * (float10)DAT_00a0f298);

  fcos((float10)_DAT_00d1e490 * (float10)DAT_00a0f298);

  FUN_0076df50();

  FUN_0076df50();

  iVar8 = *(int *)(*(int *)(iVar8 + 0xc0) + 8);

  FUN_0076df50(iVar8 + 0x80,iVar8 + 0x80);

  *(uint32_t /* width from decompiler */ *)(iVar8 + 0xbc) = 0xffffffff;

  *(int *)(iVar8 + 0xb4) = *(int *)(iVar8 + 0xb4) + 1;

  puVar6 = &DAT_00d1b0cc;

  for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar6 = 0x3f800000;

    puVar6 = puVar6 + 1;

  }

  if (*(int *)(unaff_ESI + 0xd20) != 0) goto LAB_0091af9b;

  FUN_0048f370();

  piVar7 = (int *)CVOGReaction_GiveItemByCbid(0x194);

  if (piVar7 == (int *)0x0) {

    FUN_007a4480();

    return;

  }

  (**(code **)(*piVar7 + 8))();

  iVar8 = (**(code **)(*piVar7 + 0x1cc))();

  *(int *)(unaff_ESI + 0xd20) = iVar8;

  if (iVar8 != 0) {

    if (*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8) + 0x38) == 1) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x218))();

      pbVar1 = (byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xd20) + 4) + 4) + 0x182 +

                       *(int *)(unaff_ESI + 0xd20));

      *pbVar1 = *pbVar1 | 4;

      (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xd20))(1);

      iVar8 = *(int *)(unaff_ESI + 0xd20);

      if (*(int **)(iVar8 + 8) != (int *)0x0) {

        (**(code **)(**(int **)(iVar8 + 8) + 0x18))();

        (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xd20) + 8) + 0x14))();

        goto LAB_0091af9b;

      }

      if (iVar8 == 0) goto LAB_0091af91;

    }

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8))();

  }

LAB_0091af91:

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xd20) = 0;

LAB_0091af9b:

  if ((DAT_00d1b644 != 0) && (*(int *)(DAT_00d1b644 + 0x78) != 0)) {

    FUN_00555f10();

  }

  return;

}
