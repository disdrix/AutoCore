// =============================================================================
// FUN_0063b4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0063b4b0
// Address:   0x0063b4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063b4b0 @ 0x0063b4b0
// Stable ID: aa_0063b4b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: SQRT×2, FUN_005eadb0, FUN_0063b4b0.
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

void __thiscall FUN_0063b4b0(int param_1,float *param_2)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

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

  fVar3 = *param_2;

  *(float *)(param_1 + 0x70) = *(float *)(param_1 + 0x40) * fVar3 + *(float *)(param_1 + 0x70);

  *(float *)(param_1 + 0x74) = *(float *)(param_1 + 0x44) * fVar3 + *(float *)(param_1 + 0x74);

  *(float *)(param_1 + 0x78) = *(float *)(param_1 + 0x48) * fVar3 + *(float *)(param_1 + 0x78);

  *(float *)(param_1 + 0x7c) = *(float *)(param_1 + 0x4c) * fVar3 + *(float *)(param_1 + 0x7c);

  fVar4 = DAT_00a0f298;

  pfVar1 = (float *)(param_1 + 0x30);

  *(float *)(param_1 + 0x6c) =

       SQRT(*(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58) +

            *(float *)(param_1 + 0x54) * *(float *)(param_1 + 0x54) +

            *(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x50)) * *(float *)(param_1 + 0xc) *

       *param_2;

  fVar8 = *(float *)(param_1 + 0x54) * fVar4;

  fVar2 = *(float *)(param_1 + 0x50) * fVar4;

  fVar4 = *(float *)(param_1 + 0x58) * fVar4;

  fVar3 = *param_2;

  fVar6 = (fVar4 * *(float *)(param_1 + 0x3c) +

          *(float *)(param_1 + 0x38) * g_flZero +

          (fVar2 * *(float *)(param_1 + 0x34) - fVar8 * *pfVar1)) * fVar3 +

          *(float *)(param_1 + 0x38);

  fVar5 = (*(float *)(param_1 + 0x3c) * fVar8 +

          *(float *)(param_1 + 0x34) * 0.0 + (fVar4 * *pfVar1 - fVar2 * *(float *)(param_1 + 0x38)))

          * fVar3 + *(float *)(param_1 + 0x34);

  fVar7 = (*(float *)(param_1 + 0x3c) * g_flZero -

          (fVar2 * *pfVar1 + *(float *)(param_1 + 0x34) * fVar8 + fVar4 * *(float *)(param_1 + 0x38)

          )) * fVar3 + *(float *)(param_1 + 0x3c);

  *pfVar1 = (*(float *)(param_1 + 0x3c) * fVar2 +

            *pfVar1 * 0.0 +

            (*(float *)(param_1 + 0x38) * fVar8 - fVar4 * *(float *)(param_1 + 0x34))) * fVar3 +

            *pfVar1;

  *(float *)(param_1 + 0x38) = fVar6;

  *(float *)(param_1 + 0x34) = fVar5;

  *(float *)(param_1 + 0x3c) = fVar7;

  fVar3 = *pfVar1 * *pfVar1 + fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7;

  if (fVar3 == 0.0) {

    fVar3 = 0.0;

  }

  else {

    fVar3 = g_flOne / SQRT(fVar3);

  }

  *pfVar1 = fVar3 * *pfVar1;

  *(float *)(param_1 + 0x34) = fVar3 * *(float *)(param_1 + 0x34);

  *(float *)(param_1 + 0x38) = fVar3 * *(float *)(param_1 + 0x38);

  *(float *)(param_1 + 0x3c) = fVar3 * *(float *)(param_1 + 0x3c);

  FUN_005eadb0(pfVar1);

  fVar3 = *(float *)(param_1 + 0x24);

  fVar4 = *(float *)(param_1 + 0x28);

  fVar2 = *(float *)(param_1 + 0x20);

  *(float *)(param_1 + 0xb4) =

       *(float *)(param_1 + 0x74) -

       (*(float *)(param_1 + 0xa4) * fVar4 + *(float *)(param_1 + 0x94) * fVar3 +

       *(float *)(param_1 + 0x84) * fVar2);

  fVar5 = g_flOne;

  *(float *)(param_1 + 0xb0) =

       *(float *)(param_1 + 0x70) -

       (*(float *)(param_1 + 0xa0) * fVar4 + *(float *)(param_1 + 0x90) * fVar3 +

       fVar2 * *(float *)(param_1 + 0x80));

  *(float *)(param_1 + 0xb8) =

       *(float *)(param_1 + 0x78) -

       (*(float *)(param_1 + 0xa8) * fVar4 + *(float *)(param_1 + 0x98) * fVar3 +

       *(float *)(param_1 + 0x88) * fVar2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  *(float *)(param_1 + 0x7c) = fVar5;

  return;

}
