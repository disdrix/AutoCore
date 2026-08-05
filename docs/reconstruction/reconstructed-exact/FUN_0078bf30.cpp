// =============================================================================
// FUN_0078bf30
// -----------------------------------------------------------------------------
// Stable ID: aa_0078bf30
// Address:   0x0078bf30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078bf30 @ 0x0078bf30
// Stable ID: aa_0078bf30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: ABS×7, FUN_0040cf90, FUN_0078bf30.
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

void __fastcall FUN_0078bf30(int param_1)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uStack_1c;

  

  if (*(int **)(param_1 + 0x298) != (int *)0x0) {

    pfVar1 = (float *)(param_1 + 0x234);

    *pfVar1 = 0.0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x238) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x23c) = 0;

    iVar8 = (**(code **)(**(int **)(param_1 + 0x298) + 0x48))();

    fVar2 = *(float *)(iVar8 + 0x20);

    fVar3 = *(float *)(iVar8 + 0x24);

    fVar4 = *(float *)(iVar8 + 0x28);

    iVar8 = (**(code **)(**(int **)(param_1 + 0x298) + 0x48))();

    fVar5 = *(float *)(iVar8 + 0x14);

    fVar6 = *(float *)(iVar8 + 0x18);

    fVar7 = *(float *)(iVar8 + 0x1c);

    iVar8 = (**(code **)(**(int **)(param_1 + 0x298) + 0x48))();

    uStack_1c = ABS(*(float *)(iVar8 + 0xc));

    if (uStack_1c < g_flOne) {

      uStack_1c = g_flOne;

    }

    uVar9 = 3;

    *pfVar1 = *pfVar1 - (ABS(fVar2) - ABS(fVar5)) * DAT_00a0f298;

    *(float *)(param_1 + 0x238) =

         *(float *)(param_1 + 0x238) - (ABS(fVar3) - ABS(fVar6)) * DAT_00a0f298;

    *(float *)(param_1 + 0x23c) =

         uStack_1c + uStack_1c + (ABS(fVar4) - ABS(fVar7)) * DAT_00a0f298 +

         *(float *)(param_1 + 0x23c);

    (**(code **)(**(int **)(param_1 + 0x298) + 0x10))(3,pfVar1);

    FUN_0040cf90(uVar9);

  }

  return;

}
