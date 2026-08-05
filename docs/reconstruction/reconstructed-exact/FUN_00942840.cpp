// =============================================================================
// FUN_00942840
// -----------------------------------------------------------------------------
// Stable ID: aa_00942840
// Address:   0x00942840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00942840 @ 0x00942840
// Stable ID: aa_00942840
// Embedded strings (evidence for future rename):
//   - "gWorldFogCenter"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~164 non-empty decompiler lines.
//  - Control keywords: if×16, goto×4, return×1.
//  - Notable callees: FUN_0040ac70×3, FUN_00409a30×2, FUN_004cd220×2, FUN_00758c80, FUN_00759090, FUN_007a17e0, FUN_007f7060, FUN_007fc490.
//  - Strings: "gWorldFogCenter".
//  - Return sites: 1.

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

void __fastcall FUN_00942840(int param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ uVar6;

  float unaff_ESI;

  float10 fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x33c))(*in_EAX);

  FUN_007fd470();

  FUN_00801f80();

  if (((*(int *)(param_1 + 0x111c) != 0) &&

      (cVar3 = (**(code **)(**(int **)(param_1 + 0x111c) + 0x3d8))(), cVar3 != '\0')) &&

     (*(char *)(*(int *)(param_1 + 0x111c) + 0x780) != '\0')) {

    FUN_007fc490(param_1);

    FUN_007f7060();

    if (DAT_00d1b920 != (int *)0x0) {

      (**(code **)(*DAT_00d1b920 + 0x338))(8,0x9cbd);

    }

  }

  FUN_007fdc60();

  (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x340))();

  FUN_00758c80();

  if ((*(int **)(param_1 + 0xf40) == (int *)0x0) ||

     (iVar4 = **(int **)(param_1 + 0xf40), iVar4 != *(int *)(param_1 + 0xf38))) goto LAB_00942dd6;

  iVar1 = *(int *)(param_1 + 0xe98);

  if (iVar1 == 0) {

LAB_00942d42:

    iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe04) + 0xe894) + 0xc0) + 8);

    iVar1 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe898);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x8c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x90);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x94);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x98);

    iVar1 = DAT_00d1f05c;

    iVar4 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe898);

    if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

      uVar6 = 0;

    }

    else {

      piVar2 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

      uVar6 = (**(code **)(*piVar2 + 0x24))(piVar2,0,"gWorldFogCenter");

    }

    piVar2 = *(int **)(*(int *)(iVar1 + 4) + 0xc);

    (**(code **)(*piVar2 + 0x50))(piVar2,uVar6,iVar4 + 0x8c,0xffffffff);

  }

  else if (*(int *)(iVar1 + 0x250) == 0) {

    if (((iVar1 == 0) || (*(char *)(iVar1 + 0x4f1) != '\0')) || (*(int *)(iVar1 + 0x48) == 0))

    goto LAB_00942d42;

    iVar4 = (**(code **)(**(int **)(iVar1 + 0x48) + 0xc))();

    fStack_1c = *(float *)(iVar4 + 0x90);

    fStack_18 = *(float *)(iVar4 + 0x94);

    fStack_14 = *(float *)(iVar4 + 0x98);

    fVar7 = (float10)FUN_004cd220(fStack_1c,fStack_14);

    fStack_18 = (float)(fVar7 + (float10)g_flMultiKillCountBlend);

    FUN_00409a30(&fStack_1c);

    iVar4 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe898);

    *(float *)(iVar4 + 0x8c) = fStack_1c;

    *(float *)(iVar4 + 0x90) = fStack_18;

    *(float *)(iVar4 + 0x94) = fStack_14;

  }

  else {

    iVar4 = *(int *)(iVar4 + 0x60c);

    if (iVar4 == 0) {

      if (*(int **)(iVar1 + 0x48) == (int *)0x0) {

        fStack_8 = 0.0;

        unaff_ESI = 0.0;

        fStack_24 = 0.0;

        fStack_20 = 0.0;

        fStack_10 = 0.0;

        fStack_c = g_flOne;

      }

      else {

        iVar4 = (**(code **)(**(int **)(iVar1 + 0x48) + 0xc))();

        unaff_ESI = *(float *)(iVar4 + 0x90);

        fStack_24 = *(float *)(iVar4 + 0x94);

        fStack_20 = *(float *)(iVar4 + 0x98);

        iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe98) + 0x48) + 0xc))();

        fVar9 = *(float *)(iVar4 + 0x80) * *(float *)(iVar4 + 0x88);

        fVar8 = *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x84);

        fVar10 = *(float *)(iVar4 + 0x80) * *(float *)(iVar4 + 0x8c);

        pfVar5 = (float *)(iVar4 + 0x80);

LAB_00942a48:

        fStack_10 = (fVar9 + fVar8) * g_flLevelUpUiBase_Inferred;

        fStack_c = (pfVar5[2] * pfVar5[1] - fVar10) * g_flLevelUpUiBase_Inferred;

        fStack_8 = g_flOne - (*pfVar5 * *pfVar5 + pfVar5[1] * pfVar5[1]) *

                             g_flLevelUpUiBase_Inferred;

      }

    }

    else {

      if (iVar4 == 3) {

        iVar4 = *(int *)(param_1 + 0xe98);

        if ((*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa4 + iVar4) != 0) &&

           (iVar4 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa4 + iVar4) +

                                0x1d0))(), iVar4 != 0)) {

          pfVar5 = (float *)FUN_0040ac70();

          fVar9 = pfVar5[3] * pfVar5[1];

          fVar8 = pfVar5[2] * *pfVar5;

          fVar10 = pfVar5[3] * *pfVar5;

          goto LAB_00942a48;

        }

        pfVar5 = (float *)FUN_0040ac70();

        fStack_10 = (*pfVar5 * pfVar5[2] + pfVar5[1] * pfVar5[3]) * g_flLevelUpUiBase_Inferred;

        fStack_c = (pfVar5[1] * pfVar5[2] - *pfVar5 * pfVar5[3]) * g_flLevelUpUiBase_Inferred;

        fVar8 = *pfVar5 * *pfVar5 + pfVar5[1] * pfVar5[1];

      }

      else {

        pfVar5 = (float *)FUN_0040ac70();

        fStack_10 = (*pfVar5 * pfVar5[2] + pfVar5[1] * pfVar5[3]) * g_flLevelUpUiBase_Inferred;

        fStack_c = (pfVar5[1] * pfVar5[2] - pfVar5[3] * *pfVar5) * g_flLevelUpUiBase_Inferred;

        fVar8 = pfVar5[1] * pfVar5[1] + *pfVar5 * *pfVar5;

      }

      fStack_8 = g_flOne - fVar8 * g_flLevelUpUiBase_Inferred;

    }

    fStack_14 = fStack_8;

    fStack_18 = fStack_c;

    fStack_1c = fStack_10;

    if (*(int *)(param_1 + 0xf38) != 0) {

      if (*(int *)(*(int *)(param_1 + 0xf38) + 0xc78) != 0) goto LAB_00942dc0;

      unaff_ESI = *(float *)(DAT_00d17944 + 0x228);

      fStack_24 = *(float *)(DAT_00d17944 + 0x22c);

      fStack_20 = *(float *)(DAT_00d17944 + 0x230);

      fStack_10 = unaff_ESI;

      fStack_c = fStack_24;

      fStack_8 = fStack_20;

    }

    FUN_00409a30(&stack0xffffffd8);

    iVar4 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe898);

    *(float *)(iVar4 + 0x8c) = unaff_ESI;

    *(float *)(iVar4 + 0x90) = fStack_24;

    *(float *)(iVar4 + 0x94) = fStack_20;

    FUN_004cd220(unaff_ESI,fStack_20);

    FUN_007a17e0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xde8),*in_EAX,&stack0xffffffd8);

  }

LAB_00942dc0:

  if (*(char *)(param_1 + 0x9d) == '\0') {

    FUN_00937a60(param_1,*(uint8_t *)(param_1 + 0x22ee));

  }

LAB_00942dd6:

  if ((*(char *)(*(int *)(param_1 + 0xe04) + 0x80) == '\0') && (*(char *)(param_1 + 0x9d) == '\0'))

  {

    FUN_0093ab90(param_1);

    FUN_00937d50(param_1);

    FUN_00940ed0(param_1);

    if (*(char *)(param_1 + 0x16) != '\0') {

      FUN_009387e0(param_1);

    }

  }

  FUN_00759090();

  return;

}
