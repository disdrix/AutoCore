// =============================================================================
// FUN_0063b820
// -----------------------------------------------------------------------------
// Stable ID: aa_0063b820
// Address:   0x0063b820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063b820 @ 0x0063b820
// Stable ID: aa_0063b820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: SQRT×2, FUN_005eadb0, FUN_0063b820.
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

int __thiscall FUN_0063b820(int param_1,float *param_2,float param_3,int param_4)



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

  

  *(float *)(param_1 + 0x40) = *(float *)(param_4 + 0x40) * param_3;

  *(float *)(param_1 + 0x44) = *(float *)(param_4 + 0x44) * param_3;

  *(float *)(param_1 + 0x48) = *(float *)(param_4 + 0x48) * param_3;

  *(float *)(param_1 + 0x4c) = *(float *)(param_4 + 0x4c) * param_3;

  *(float *)(param_1 + 0x50) = *(float *)(param_4 + 0x50) * param_3;

  *(float *)(param_1 + 0x54) = *(float *)(param_4 + 0x54) * param_3;

  *(float *)(param_1 + 0x58) = *(float *)(param_4 + 0x58) * param_3;

  *(float *)(param_1 + 0x5c) = *(float *)(param_4 + 0x5c) * param_3;

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

  fVar8 = *param_2;

  *(float *)(param_1 + 0x70) = *(float *)(param_1 + 0x40) * fVar8 + *(float *)(param_1 + 0x70);

  *(float *)(param_1 + 0x74) = *(float *)(param_1 + 0x44) * fVar8 + *(float *)(param_1 + 0x74);

  *(float *)(param_1 + 0x78) = *(float *)(param_1 + 0x48) * fVar8 + *(float *)(param_1 + 0x78);

  *(float *)(param_1 + 0x7c) = *(float *)(param_1 + 0x4c) * fVar8 + *(float *)(param_1 + 0x7c);

  fVar3 = DAT_00a0f298;

  fVar9 = 0.0;

  pfVar1 = (float *)(param_1 + 0x30);

  *(float *)(param_1 + 0x6c) =

       SQRT(*(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58) +

            *(float *)(param_1 + 0x54) * *(float *)(param_1 + 0x54) +

            *(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x50)) * *(float *)(param_1 + 0xc) *

       *param_2;

  fVar2 = *(float *)(param_1 + 0x50) * fVar3;

  fVar4 = *(float *)(param_1 + 0x58) * fVar3;

  fVar3 = *(float *)(param_1 + 0x54) * fVar3;

  fVar8 = *param_2;

  fVar5 = (*(float *)(param_1 + 0x3c) * fVar2 +

          *pfVar1 * 0.0 + (fVar3 * *(float *)(param_1 + 0x38) - fVar4 * *(float *)(param_1 + 0x34)))

          * fVar8 + *pfVar1;

  fVar6 = (fVar3 * *(float *)(param_1 + 0x3c) +

          *(float *)(param_1 + 0x34) * 0.0 + (fVar4 * *pfVar1 - *(float *)(param_1 + 0x38) * fVar2))

          * fVar8 + *(float *)(param_1 + 0x34);

  fVar7 = (fVar4 * *(float *)(param_1 + 0x3c) +

          *(float *)(param_1 + 0x38) * 0.0 + (*(float *)(param_1 + 0x34) * fVar2 - fVar3 * *pfVar1))

          * fVar8 + *(float *)(param_1 + 0x38);

  fVar8 = (*(float *)(param_1 + 0x3c) * 0.0 -

          (fVar2 * *pfVar1 + fVar4 * *(float *)(param_1 + 0x38) + fVar3 * *(float *)(param_1 + 0x34)

          )) * fVar8 + *(float *)(param_1 + 0x3c);

  *pfVar1 = fVar5;

  *(float *)(param_1 + 0x34) = fVar6;

  *(float *)(param_1 + 0x38) = fVar7;

  *(float *)(param_1 + 0x3c) = fVar8;

  fVar8 = fVar7 * fVar7 + fVar8 * fVar8 + fVar5 * fVar5 + fVar6 * fVar6;

  if (fVar8 != 0.0) {

    fVar9 = g_flOne / SQRT(fVar8);

  }

  *pfVar1 = fVar9 * *pfVar1;

  *(float *)(param_1 + 0x34) = fVar9 * *(float *)(param_1 + 0x34);

  *(float *)(param_1 + 0x38) = fVar9 * *(float *)(param_1 + 0x38);

  *(float *)(param_1 + 0x3c) = fVar9 * *(float *)(param_1 + 0x3c);

  FUN_005eadb0(pfVar1);

  fVar8 = *(float *)(param_1 + 0x24);

  fVar9 = *(float *)(param_1 + 0x28);

  fVar3 = *(float *)(param_1 + 0x20);

  *(float *)(param_1 + 0xb4) =

       *(float *)(param_1 + 0x74) -

       (*(float *)(param_1 + 0xa4) * fVar9 + *(float *)(param_1 + 0x94) * fVar8 +

       *(float *)(param_1 + 0x84) * fVar3);

  fVar2 = g_flOne;

  *(float *)(param_1 + 0xb0) =

       *(float *)(param_1 + 0x70) -

       (*(float *)(param_1 + 0xa0) * fVar9 + *(float *)(param_1 + 0x90) * fVar8 +

       fVar3 * *(float *)(param_1 + 0x80));

  *(float *)(param_1 + 0xb8) =

       *(float *)(param_1 + 0x78) -

       (*(float *)(param_1 + 0xa8) * fVar9 + *(float *)(param_1 + 0x98) * fVar8 +

       *(float *)(param_1 + 0x88) * fVar3);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  *(float *)(param_1 + 0x7c) = fVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x28);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  return param_4 + 0x80;

}
