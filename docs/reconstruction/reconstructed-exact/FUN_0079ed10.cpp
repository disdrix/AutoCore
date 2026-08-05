// =============================================================================
// FUN_0079ed10
// -----------------------------------------------------------------------------
// Stable ID: aa_0079ed10
// Address:   0x0079ed10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079ed10 @ 0x0079ed10
// Stable ID: aa_0079ed10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0079ed10.
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

void __fastcall FUN_0079ed10(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  

  fVar10 = g_flLevelUpUiBase_Inferred;

  fVar9 = g_flOne;

  iVar7 = *(int *)(param_1 + 0x2e4);

  iVar8 = *(int *)(iVar7 + 8);

  fVar11 = (*(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x84) -

           *(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x8c)) * g_flLevelUpUiBase_Inferred;

  fVar12 = (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x80) +

           *(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x84)) * g_flLevelUpUiBase_Inferred;

  *(float *)(param_1 + 0x294) =

       (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x88) +

       *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x84)) * g_flLevelUpUiBase_Inferred;

  *(float *)(param_1 + 0x298) = fVar11;

  *(float *)(param_1 + 0x29c) = fVar9 - fVar12;

  iVar8 = *(int *)(iVar7 + 8);

  fVar11 = *(float *)(iVar8 + 0x80);

  fVar12 = *(float *)(iVar8 + 0x84);

  fVar1 = *(float *)(iVar8 + 0x8c);

  fVar2 = *(float *)(iVar8 + 0x88);

  fVar3 = *(float *)(iVar8 + 0x8c);

  fVar4 = *(float *)(iVar8 + 0x84);

  fVar5 = *(float *)(iVar8 + 0x80);

  fVar6 = *(float *)(iVar8 + 0x88);

  *(float *)(param_1 + 0x2a0) =

       fVar9 - (*(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x84) +

               *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x88)) * fVar10;

  *(float *)(param_1 + 0x2a4) = (fVar1 * fVar2 + fVar11 * fVar12) * fVar10;

  *(float *)(param_1 + 0x2a8) = (fVar5 * fVar6 - fVar3 * fVar4) * fVar10;

  iVar7 = *(int *)(iVar7 + 8);

  fVar11 = *(float *)(iVar7 + 0x88);

  fVar12 = *(float *)(iVar7 + 0x80);

  fVar1 = *(float *)(iVar7 + 0x84);

  fVar2 = *(float *)(iVar7 + 0x88);

  fVar3 = *(float *)(iVar7 + 0x8c);

  *(float *)(param_1 + 0x2ac) =

       (*(float *)(iVar7 + 0x84) * *(float *)(iVar7 + 0x80) -

       *(float *)(iVar7 + 0x88) * *(float *)(iVar7 + 0x8c)) * fVar10;

  *(float *)(param_1 + 0x2b0) = fVar9 - (fVar11 * fVar11 + fVar12 * fVar12) * fVar10;

  *(float *)(param_1 + 0x2b4) = (fVar1 * fVar2 + fVar12 * fVar3) * fVar10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x168) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e8) = 0;

  return;

}
