// =============================================================================
// FUN_00639da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00639da0
// Address:   0x00639da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00639da0 @ 0x00639da0
// Stable ID: aa_00639da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: SQRT×2, FUN_005eadb0, FUN_00639da0.
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

void __thiscall FUN_00639da0(int param_1,float *param_2)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  fVar3 = *param_2;

  *(float *)(param_1 + 0x70) = fVar3 * *(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x70);

  *(float *)(param_1 + 0x74) = *(float *)(param_1 + 0x44) * fVar3 + *(float *)(param_1 + 0x74);

  *(float *)(param_1 + 0x78) = *(float *)(param_1 + 0x48) * fVar3 + *(float *)(param_1 + 0x78);

  *(float *)(param_1 + 0x7c) = *(float *)(param_1 + 0x4c) * fVar3 + *(float *)(param_1 + 0x7c);

  fVar9 = DAT_00a0f298;

  pfVar1 = (float *)(param_1 + 0x30);

  *(float *)(param_1 + 0x6c) =

       SQRT(*(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58) +

            *(float *)(param_1 + 0x54) * *(float *)(param_1 + 0x54) +

            *(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x50)) * *(float *)(param_1 + 0xc) *

       *param_2;

  fVar2 = *(float *)(param_1 + 0x50) * fVar9;

  fVar8 = *(float *)(param_1 + 0x54) * fVar9;

  fVar9 = *(float *)(param_1 + 0x58) * fVar9;

  fVar3 = *pfVar1;

  fVar5 = *param_2;

  fVar4 = (*(float *)(param_1 + 0x3c) * fVar2 +

          *pfVar1 * g_flZero +

          (*(float *)(param_1 + 0x38) * fVar8 - *(float *)(param_1 + 0x34) * fVar9)) * fVar5 +

          *pfVar1;

  fVar6 = (fVar9 * *(float *)(param_1 + 0x3c) +

          *(float *)(param_1 + 0x38) * 0.0 + (*(float *)(param_1 + 0x34) * fVar2 - fVar8 * *pfVar1))

          * fVar5 + *(float *)(param_1 + 0x38);

  fVar7 = (*(float *)(param_1 + 0x3c) * g_flZero -

          (*(float *)(param_1 + 0x34) * fVar8 + *(float *)(param_1 + 0x38) * fVar9 + fVar2 * *pfVar1

          )) * fVar5 + *(float *)(param_1 + 0x3c);

  *pfVar1 = fVar4;

  *(float *)(param_1 + 0x34) =

       (*(float *)(param_1 + 0x3c) * fVar8 +

       *(float *)(param_1 + 0x34) * 0.0 + (fVar9 * fVar3 - *(float *)(param_1 + 0x38) * fVar2)) *

       fVar5 + *(float *)(param_1 + 0x34);

  *(float *)(param_1 + 0x38) = fVar6;

  *(float *)(param_1 + 0x3c) = fVar7;

  fVar3 = 0.0;

  fVar5 = fVar4 * fVar4 + *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x34) + fVar6 * fVar6 +

          fVar7 * fVar7;

  if (fVar5 != 0.0) {

    fVar3 = g_flOne / SQRT(fVar5);

  }

  *pfVar1 = *pfVar1 * fVar3;

  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) * fVar3;

  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) * fVar3;

  *(float *)(param_1 + 0x3c) = fVar3 * *(float *)(param_1 + 0x3c);

  FUN_005eadb0(pfVar1);

  fVar4 = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x3c) * g_flLevelUpUiBase_Inferred -

          g_flOne;

  fVar5 = (*pfVar1 * *(float *)(param_1 + 0x20) +

           *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x34) +

          *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x38)) * g_flLevelUpUiBase_Inferred;

  fVar9 = *(float *)(param_1 + 0x3c) * g_flLevelUpUiBase_Inferred;

  fVar2 = fVar9 * g_flZero;

  *(float *)(param_1 + 0xb0) =

       *(float *)(param_1 + 0x70) -

       ((*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x34) -

        *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x24)) * fVar9 +

       *pfVar1 * fVar5 + fVar4 * *(float *)(param_1 + 0x20));

  fVar3 = g_flOne;

  *(float *)(param_1 + 0xb4) =

       *(float *)(param_1 + 0x74) -

       ((*(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x20) -

        *(float *)(param_1 + 0x28) * *pfVar1) * fVar9 +

       fVar5 * *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x24) * fVar4);

  *(float *)(param_1 + 0xb8) =

       *(float *)(param_1 + 0x78) -

       ((*pfVar1 * *(float *)(param_1 + 0x24) -

        *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x34)) * fVar9 +

       *(float *)(param_1 + 0x38) * fVar5 + *(float *)(param_1 + 0x28) * fVar4);

  *(float *)(param_1 + 0xbc) =

       *(float *)(param_1 + 0x7c) -

       (fVar2 + *(float *)(param_1 + 0x3c) * fVar5 + *(float *)(param_1 + 0x2c) * fVar4);

  *(float *)(param_1 + 0x7c) = fVar3;

  return;

}
