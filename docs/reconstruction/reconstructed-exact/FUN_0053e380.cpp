// =============================================================================
// FUN_0053e380
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e380
// Address:   0x0053e380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053e380 @ 0x0053e380
// Stable ID: aa_0053e380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004f2e20, FUN_004f2e70, FUN_0053e380.
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

void __fastcall FUN_0053e380(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  float *pfVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 8) != 0)) {

    cVar5 = (**(code **)(**(int **)(param_1 + 0xc) + 0x68))();

    if (cVar5 != '\0') {

      iVar4 = **(int **)(param_1 + 0xc);

      uVar6 = FUN_004f2e20(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);

      (**(code **)(iVar4 + 0x38))(uVar6);

      pfVar7 = (float *)FUN_004f2e70(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30);

      fVar8 = pfVar7[1];

      fVar1 = pfVar7[2];

      fVar2 = *pfVar7;

      fVar3 = pfVar7[3];

      fStack_18 = fVar1 * fVar1 * g_flLevelUpUiBase_Inferred;

      fVar9 = fVar8 * fVar8 * g_flLevelUpUiBase_Inferred;

      fStack_28 = (g_flOne - fVar9) - fStack_18;

      fStack_1c = fVar1 * fVar3 * g_flLevelUpUiBase_Inferred;

      fVar10 = fVar8 * fVar2 * g_flLevelUpUiBase_Inferred;

      fStack_24 = fVar10 - fStack_1c;

      fStack_1c = fStack_1c + fVar10;

      fStack_10 = fVar1 * fVar2 * g_flLevelUpUiBase_Inferred;

      fVar10 = fVar8 * fVar3 * g_flLevelUpUiBase_Inferred;

      fStack_20 = fVar10 + fStack_10;

      fStack_c = fVar2 * fVar3 * g_flLevelUpUiBase_Inferred;

      fStack_8 = g_flOne - fVar2 * fVar2 * g_flLevelUpUiBase_Inferred;

      fVar8 = fVar1 * fVar8 * g_flLevelUpUiBase_Inferred;

      fStack_18 = fStack_8 - fStack_18;

      fStack_8 = fStack_8 - fVar9;

      fStack_14 = fVar8 - fStack_c;

      fStack_10 = fStack_10 - fVar10;

      fStack_c = fStack_c + fVar8;

      (**(code **)(**(int **)(param_1 + 0xc) + 0x3c))(&fStack_28);

    }

  }

  return;

}
