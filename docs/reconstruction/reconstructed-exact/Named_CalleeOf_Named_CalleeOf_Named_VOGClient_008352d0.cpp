// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGClient_008352d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008352d0
// Callee of Named_CalleeOf_Named_VOGClient
// Address:   0x008352d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×17, return×12, for×2.
//  - Notable callees: GetTickCount×14, ABS×2, FUN_00413600×2, FUN_004e88e0×2, CVOGReaction_ResolveObjectTarget, FUN_0040d0a0, FUN_008352d0.
//  - Return sites: 12.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGClient
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



void Named_CalleeOf_Named_CalleeOf_Named_VOGClient_008352d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 char param_5)



{

  float fVar1;

  float fVar2;

  DWORD DVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  int unaff_EDI;

  float10 fVar8;

  float fVar9;

  float afStack_18 [2];

  float fStack_10;

  float afStack_c [2];

  float fStack_4;

  

  if (((DAT_00d1b6d8 != 0) && (DAT_00d1b644 != 0)) && (DAT_00d17944 != 0)) {

    if (param_5 != '\0') {

      DVar3 = GetTickCount();

      *(DWORD *)(unaff_EDI + 0x4a4) = DVar3;

      *(DWORD *)(unaff_EDI + 0x4a0) = DVar3;

      *(DWORD *)(unaff_EDI + 0x49c) = DVar3;

      *(DWORD *)(unaff_EDI + 0x498) = DVar3;

      return;

    }

    piVar7 = (int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8);

    if (*(char *)(DAT_00d1b6d8 + 0x30c) != '\0') {

      iVar5 = *(int *)(DAT_00d1b6d8 + 0x250);

      if (iVar5 == 0) {

        return;

      }

      piVar7 = (int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

    }

    if ((piVar7 != (int *)0x0) &&

       (piVar4 = (int *)CVOGReaction_ResolveObjectTarget(param_3,param_1,param_2),

       piVar4 != (int *)0x0)) {

      iVar5 = *(int *)(piVar4[0x2a] + 0x38);

      if ((iVar5 != 0xe) && ((iVar5 != 0x12 && (iVar5 != 0x14)))) {

        iVar5 = (**(code **)(*piVar4 + 0x214))();

        if (iVar5 == 0) {

          return;

        }

        iVar5 = (**(code **)(*piVar4 + 0x214))();

        if (iVar5 == 0) {

          piVar4 = (int *)0x0;

        }

        else {

          piVar4 = (int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

        }

      }

      uVar6 = (**(code **)(*piVar7 + 0x1a0))();

      FUN_004e88e0(afStack_c,uVar6);

      uVar6 = (**(code **)(*piVar4 + 0x1a0))();

      FUN_004e88e0(afStack_18,uVar6);

      afStack_18[0] = afStack_18[0] - afStack_c[0];

      fVar1 = *(float *)(DAT_00d17944 + 0x21c);

      fVar2 = *(float *)(DAT_00d17944 + 0x224);

      fStack_10 = fStack_10 - fStack_4;

      if ((DAT_00aaa620 <= ABS(afStack_18[0] * afStack_18[0] + fStack_10 * fStack_10)) &&

         (DAT_00aaa620 <= ABS(fVar2 * fVar2 + fVar1 * fVar1))) {

        FUN_00413600();

        FUN_00413600();

        fVar8 = (float10)FUN_0040d0a0(fStack_10 * fVar2 + fVar1 * afStack_18[0]);

        fVar9 = (float)(fVar8 * (float10)_DAT_00aaa8d8);

        if (fVar2 * afStack_18[0] - fVar1 * fStack_10 < 0.0) {

          fVar9 = 0.0 - fVar9;

        }

        for (; fVar9 < 0.0; fVar9 = fVar9 + DAT_00aaa8d4) {

        }

        for (; DAT_00aaa8d4 <= fVar9; fVar9 = fVar9 - DAT_00aaa8d4) {

        }

        if ((fVar9 < DAT_00aaa8d0) || (_DAT_00aaa8cc <= fVar9)) {

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x4a0) = DVar3;

          return;

        }

        if (fVar9 < DAT_00aaa8c8) {

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x4a0) = DVar3;

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x49c) = DVar3;

          return;

        }

        if (fVar9 < DAT_00aaa8c4) {

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x49c) = DVar3;

          return;

        }

        if (fVar9 < DAT_00aaa8c0) {

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x49c) = DVar3;

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x4a4) = DVar3;

          return;

        }

        if (fVar9 < DAT_00aaa8bc) {

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x4a4) = DVar3;

          return;

        }

        if (fVar9 < DAT_00aaa8b8) {

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x4a4) = DVar3;

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x498) = DVar3;

          return;

        }

        if (fVar9 < DAT_00aaa8b4) {

          DVar3 = GetTickCount();

          *(DWORD *)(unaff_EDI + 0x498) = DVar3;

          return;

        }

        DVar3 = GetTickCount();

        *(DWORD *)(unaff_EDI + 0x498) = DVar3;

        DVar3 = GetTickCount();

        *(DWORD *)(unaff_EDI + 0x4a0) = DVar3;

        return;

      }

      DVar3 = GetTickCount();

      *(DWORD *)(unaff_EDI + 0x4a4) = DVar3;

      *(DWORD *)(unaff_EDI + 0x4a0) = DVar3;

      *(DWORD *)(unaff_EDI + 0x498) = DVar3;

      *(DWORD *)(unaff_EDI + 0x49c) = DVar3;

    }

  }

  return;

}
