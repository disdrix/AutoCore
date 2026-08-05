// =============================================================================
// FUN_006399a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006399a0
// Address:   0x006399a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006399a0 @ 0x006399a0
// Stable ID: aa_006399a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: SQRT×2, FUN_005eadb0, FUN_006399a0.
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

int __thiscall FUN_006399a0(int param_1,float *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  fVar2 = *param_2;

  *(float *)(param_1 + 0x70) = *(float *)(param_1 + 0x40) * fVar2 + *(float *)(param_1 + 0x70);

  *(float *)(param_1 + 0x74) = *(float *)(param_1 + 0x44) * fVar2 + *(float *)(param_1 + 0x74);

  *(float *)(param_1 + 0x78) = *(float *)(param_1 + 0x48) * fVar2 + *(float *)(param_1 + 0x78);

  *(float *)(param_1 + 0x7c) = *(float *)(param_1 + 0x4c) * fVar2 + *(float *)(param_1 + 0x7c);

  fVar7 = DAT_00a0f298;

  pfVar1 = (float *)(param_1 + 0x30);

  *(float *)(param_1 + 0x6c) =

       SQRT(*(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58) +

            *(float *)(param_1 + 0x54) * *(float *)(param_1 + 0x54) +

            *(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x50)) * *(float *)(param_1 + 0xc) *

       *param_2;

  fVar2 = *pfVar1;

  fVar6 = *(float *)(param_1 + 0x50) * fVar7;

  fVar8 = *(float *)(param_1 + 0x58) * fVar7;

  fVar7 = *(float *)(param_1 + 0x54) * fVar7;

  fVar4 = *param_2;

  fVar3 = (*(float *)(param_1 + 0x3c) * fVar7 +

          *(float *)(param_1 + 0x34) * 0.0 + (*pfVar1 * fVar8 - *(float *)(param_1 + 0x38) * fVar6))

          * fVar4 + *(float *)(param_1 + 0x34);

  fVar5 = (*(float *)(param_1 + 0x3c) * g_flZero -

          (*(float *)(param_1 + 0x34) * fVar7 + *pfVar1 * fVar6 + *(float *)(param_1 + 0x38) * fVar8

          )) * fVar4 + *(float *)(param_1 + 0x3c);

  *pfVar1 = (*(float *)(param_1 + 0x3c) * fVar6 +

            *pfVar1 * g_flZero +

            (*(float *)(param_1 + 0x38) * fVar7 - *(float *)(param_1 + 0x34) * fVar8)) * fVar4 +

            *pfVar1;

  fVar4 = (fVar8 * *(float *)(param_1 + 0x3c) +

          *(float *)(param_1 + 0x38) * 0.0 + (*(float *)(param_1 + 0x34) * fVar6 - fVar2 * fVar7)) *

          fVar4 + *(float *)(param_1 + 0x38);

  *(float *)(param_1 + 0x3c) = fVar5;

  *(float *)(param_1 + 0x34) = fVar3;

  *(float *)(param_1 + 0x38) = fVar4;

  fVar2 = 0.0;

  fVar4 = *pfVar1 * *pfVar1 + fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5;

  if (fVar4 != 0.0) {

    fVar2 = g_flOne / SQRT(fVar4);

  }

  *pfVar1 = *pfVar1 * fVar2;

  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) * fVar2;

  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) * fVar2;

  *(float *)(param_1 + 0x3c) = fVar2 * *(float *)(param_1 + 0x3c);

  FUN_005eadb0(pfVar1);

  fVar5 = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x3c) * g_flLevelUpUiBase_Inferred -

          g_flOne;

  fVar4 = (*pfVar1 * *(float *)(param_1 + 0x20) +

           *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x34) +

          *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x38)) * g_flLevelUpUiBase_Inferred;

  fVar7 = *(float *)(param_1 + 0x3c) * g_flLevelUpUiBase_Inferred;

  fVar3 = fVar7 * g_flZero;

  *(float *)(param_1 + 0xb0) =

       *(float *)(param_1 + 0x70) -

       ((*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x34) -

        *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x24)) * fVar7 +

       *pfVar1 * fVar4 + *(float *)(param_1 + 0x20) * fVar5);

  fVar2 = g_flOne;

  *(float *)(param_1 + 0xb4) =

       *(float *)(param_1 + 0x74) -

       ((*(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x38) -

        *pfVar1 * *(float *)(param_1 + 0x28)) * fVar7 +

       fVar4 * *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x24) * fVar5);

  *(float *)(param_1 + 0xb8) =

       *(float *)(param_1 + 0x78) -

       ((*pfVar1 * *(float *)(param_1 + 0x24) -

        *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x34)) * fVar7 +

       *(float *)(param_1 + 0x38) * fVar4 + *(float *)(param_1 + 0x28) * fVar5);

  *(float *)(param_1 + 0xbc) =

       *(float *)(param_1 + 0x7c) -

       (fVar3 + *(float *)(param_1 + 0x3c) * fVar4 + *(float *)(param_1 + 0x2c) * fVar5);

  *(float *)(param_1 + 0x7c) = fVar2;

  return param_4 + 0x80;

}
