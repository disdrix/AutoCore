// =============================================================================
// FUN_0091d460
// -----------------------------------------------------------------------------
// Stable ID: aa_0091d460
// Address:   0x0091d460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (2026-07-29): Superseded name plate — see Client_Input_ApplyRandomUpPhysicsKick_Inferred.cpp
// Stable ID: aa_0091d460 — dual A/B + three-rep refine under inferred name.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_00404cb0, FUN_0091d460, SQRT.
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

void FUN_0091d460(void)



{

  ushort uVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  iVar2 = *(int *)(DAT_00d1b6d8 + 0x250);

  if (((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) && (*(char *)(iVar2 + 0x101) == '\0')) {

    cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x198))();

    if (cVar3 == '\0') {

      fStack_20 = DAT_00afda50;

      fStack_1c = DAT_00afda54;

      fStack_18 = (float)DAT_00afda58;

      fStack_14 = DAT_00afda5c;

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      fStack_20 = (float)uVar1 * DAT_00aaaaf0 - g_flOverheatCoolFrac;

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      fVar6 = (float)uVar1 * DAT_00aaaaf0 - g_flOverheatCoolFrac;

      fVar5 = fVar6 * fVar6 + fStack_1c * fStack_1c + fStack_20 * fStack_20;

      if (fVar5 == 0.0) {

        fVar5 = 0.0;

      }

      else {

        fVar5 = g_flOne / SQRT(fVar5);

      }

      fVar7 = *(float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0x2c);

      if (fVar7 == 0.0) {

        fVar7 = 0.0;

      }

      else {

        fVar7 = g_flOne / fVar7;

      }

      fVar7 = fVar7 * DAT_00aaaad0;

      fStack_20 = fVar7 * fVar5 * fStack_20;

      fStack_1c = fVar5 * fStack_1c * fVar7;

      fStack_18 = fVar5 * fVar6 * fVar7;

      fStack_14 = fVar5 * fStack_14 * fVar7;

      FUN_00404cb0(&fStack_20);

    }

  }

  return;

}
