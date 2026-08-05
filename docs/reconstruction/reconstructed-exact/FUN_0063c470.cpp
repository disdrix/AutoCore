// =============================================================================
// FUN_0063c470
// -----------------------------------------------------------------------------
// Stable ID: aa_0063c470
// Address:   0x0063c470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063c470 @ 0x0063c470
// Stable ID: aa_0063c470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: SQRT×2, FUN_005eadb0, FUN_0063c470.
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

int __thiscall FUN_0063c470(int param_1,float *param_2,float param_3,int param_4)



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

  float fVar10;

  float fVar11;

  float fVar12;

  

  fVar10 = 0.0;

  *(float *)(param_1 + 0x40) = *(float *)(param_4 + 0x40) * param_3;

  *(float *)(param_1 + 0x44) = *(float *)(param_4 + 0x44) * param_3;

  *(float *)(param_1 + 0x48) = *(float *)(param_4 + 0x48) * param_3;

  *(float *)(param_1 + 0x4c) = *(float *)(param_4 + 0x4c) * param_3;

  *(float *)(param_1 + 0x50) = *(float *)(param_4 + 0x50) * param_3;

  *(float *)(param_1 + 0x54) = *(float *)(param_4 + 0x54) * param_3;

  *(float *)(param_1 + 0x58) = *(float *)(param_4 + 0x58) * param_3;

  *(float *)(param_1 + 0x5c) = *(float *)(param_4 + 0x5c) * param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x58);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  fVar9 = *param_2;

  *(float *)(param_1 + 0x70) = *(float *)(param_1 + 0x40) * fVar9 + *(float *)(param_1 + 0x70);

  *(float *)(param_1 + 0x74) = *(float *)(param_1 + 0x44) * fVar9 + *(float *)(param_1 + 0x74);

  *(float *)(param_1 + 0x78) = *(float *)(param_1 + 0x48) * fVar9 + *(float *)(param_1 + 0x78);

  *(float *)(param_1 + 0x7c) = *(float *)(param_1 + 0x4c) * fVar9 + *(float *)(param_1 + 0x7c);

  fVar12 = DAT_00a0f298;

  pfVar1 = (float *)(param_1 + 0x30);

  *(float *)(param_1 + 0x6c) =

       SQRT(*(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58) +

            *(float *)(param_1 + 0x54) * *(float *)(param_1 + 0x54) +

            *(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x50)) * *(float *)(param_1 + 0xc) *

       *param_2;

  fVar11 = *(float *)(param_1 + 0x50) * fVar12;

  fVar6 = *(float *)(param_1 + 0x58) * fVar12;

  fVar12 = *(float *)(param_1 + 0x54) * fVar12;

  fVar9 = *pfVar1;

  fVar3 = *(float *)(param_1 + 0x3c);

  fVar4 = *pfVar1;

  fVar5 = *(float *)(param_1 + 0x34);

  fVar8 = *param_2;

  fVar2 = (fVar3 * fVar11 +

          *pfVar1 * 0.0 + (*(float *)(param_1 + 0x38) * fVar12 - *(float *)(param_1 + 0x34) * fVar6)

          ) * fVar8 + *pfVar1;

  fVar7 = (fVar6 * fVar3 +

          *(float *)(param_1 + 0x38) * 0.0 +

          (*(float *)(param_1 + 0x34) * fVar11 - *pfVar1 * fVar12)) * fVar8 +

          *(float *)(param_1 + 0x38);

  *pfVar1 = fVar2;

  *(float *)(param_1 + 0x34) =

       (fVar3 * fVar12 +

       *(float *)(param_1 + 0x34) * 0.0 + (fVar9 * fVar6 - *(float *)(param_1 + 0x38) * fVar11)) *

       fVar8 + *(float *)(param_1 + 0x34);

  fVar9 = (fVar3 * 0.0 - (fVar4 * fVar11 + fVar5 * fVar12 + *(float *)(param_1 + 0x38) * fVar6)) *

          fVar8 + *(float *)(param_1 + 0x3c);

  *(float *)(param_1 + 0x38) = fVar7;

  *(float *)(param_1 + 0x3c) = fVar9;

  fVar9 = fVar2 * fVar2 + *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x34) + fVar7 * fVar7 +

          fVar9 * fVar9;

  if (fVar9 != 0.0) {

    fVar10 = g_flOne / SQRT(fVar9);

  }

  *pfVar1 = fVar10 * *pfVar1;

  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) * fVar10;

  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) * fVar10;

  *(float *)(param_1 + 0x3c) = fVar10 * *(float *)(param_1 + 0x3c);

  FUN_005eadb0(pfVar1);

  fVar3 = (*(float *)(param_1 + 0x20) * *pfVar1 +

           *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x34) +

          *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x38)) * g_flLevelUpUiBase_Inferred;

  fVar4 = *(float *)(param_1 + 0x3c) * g_flLevelUpUiBase_Inferred;

  fVar8 = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x3c) * g_flLevelUpUiBase_Inferred -

          g_flOne;

  fVar5 = fVar4 * g_flZero;

  *(float *)(param_1 + 0xb0) =

       *(float *)(param_1 + 0x70) -

       ((*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x34) -

        *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x24)) * fVar4 +

       fVar3 * *pfVar1 + *(float *)(param_1 + 0x20) * fVar8);

  fVar9 = g_flOne;

  *(float *)(param_1 + 0xb4) =

       *(float *)(param_1 + 0x74) -

       ((*(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x38) -

        *(float *)(param_1 + 0x28) * *pfVar1) * fVar4 +

       fVar3 * *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x24) * fVar8);

  *(float *)(param_1 + 0xb8) =

       *(float *)(param_1 + 0x78) -

       ((*(float *)(param_1 + 0x24) * *pfVar1 -

        *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x34)) * fVar4 +

       *(float *)(param_1 + 0x38) * fVar3 + *(float *)(param_1 + 0x28) * fVar8);

  *(float *)(param_1 + 0xbc) =

       *(float *)(param_1 + 0x7c) -

       (fVar5 + *(float *)(param_1 + 0x3c) * fVar3 + *(float *)(param_1 + 0x2c) * fVar8);

  *(float *)(param_1 + 0x7c) = fVar9;

  return param_4 + 0x80;

}
