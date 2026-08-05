// =============================================================================
// FUN_005cc980
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc980
// Address:   0x005cc980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cc980 @ 0x005cc980
// Stable ID: aa_005cc980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_005cc980, SQRT.
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall FUN_005cc980(int *param_1)



{

  ushort uVar1;

  float *pfVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  iVar3 = param_1[0x19];

  if ((*(byte *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb8 + iVar3) & 0x80) != 0) {

    pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1a4))

                                ();

    fVar5 = pfVar2[1];

    fStack_18 = g_flOne - (*pfVar2 * *pfVar2 + fVar5 * fVar5) * g_flLevelUpUiBase_Inferred;

    fStack_1c = (fVar5 * pfVar2[2] - *pfVar2 * pfVar2[3]) * g_flLevelUpUiBase_Inferred;

    fStack_20 = (*pfVar2 * pfVar2[2] + pfVar2[1] * pfVar2[3]) * g_flLevelUpUiBase_Inferred;

    fStack_14 = 0.0;

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    fStack_20 = ((float)uVar1 * _DAT_009da890 + fStack_20) - DAT_00a10e78;

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    fVar4 = ((float)uVar1 * _DAT_009da890 + fStack_18) - DAT_00a10e78;

    fVar6 = fVar4 * fVar4 + fStack_1c * fStack_1c + fStack_20 * fStack_20;

    fVar5 = 0.0;

    if (fVar6 != 0.0) {

      fVar5 = g_flOne / SQRT(fVar6);

    }

    fStack_20 = fVar5 * fStack_20 * DAT_00aaa7ac;

    fStack_1c = fVar5 * fStack_1c * DAT_00aaa7ac;

    fStack_18 = fVar5 * fVar4 * DAT_00aaa7ac;

    fStack_14 = fVar5 * fStack_14 * DAT_00aaa7ac;

    pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +

                                           param_1[0x19]) + 0x1a0))();

    fStack_20 = *pfVar2 + fStack_20;

    fStack_1c = pfVar2[1] + fStack_1c;

    fStack_18 = pfVar2[2] + fStack_18;

    fStack_14 = pfVar2[3] + fStack_14;

    (**(code **)(*param_1 + 0x4c))(&fStack_20,1);

    return 1;

  }

  return 0;

}
