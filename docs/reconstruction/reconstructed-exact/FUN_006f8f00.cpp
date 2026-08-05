// =============================================================================
// FUN_006f8f00
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8f00
// Address:   0x006f8f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8f00 @ 0x006f8f00
// Stable ID: aa_006f8f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f8f00.
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

void __fastcall FUN_006f8f00(int param_1)



{

  float fVar1;

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

  float *pfVar13;

  float *pfVar14;

  

  pfVar13 = *(float **)(param_1 + 0x14);

  pfVar14 = *(float **)(param_1 + 0x18);

  fVar1 = *pfVar14;

  fVar2 = pfVar14[1];

  fVar3 = pfVar14[2];

  *(float *)(param_1 + 0x70) = fVar2 * pfVar13[1] + fVar3 * pfVar13[2] + fVar1 * *pfVar13;

  *(float *)(param_1 + 0x74) = fVar2 * pfVar13[5] + fVar3 * pfVar13[6] + fVar1 * pfVar13[4];

  *(float *)(param_1 + 0x78) = fVar2 * pfVar13[9] + fVar3 * pfVar13[10] + fVar1 * pfVar13[8];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  fVar1 = pfVar14[4];

  fVar2 = pfVar14[5];

  fVar3 = pfVar14[6];

  *(float *)(param_1 + 0x80) = fVar2 * pfVar13[1] + fVar3 * pfVar13[2] + fVar1 * *pfVar13;

  *(float *)(param_1 + 0x84) = fVar2 * pfVar13[5] + fVar3 * pfVar13[6] + fVar1 * pfVar13[4];

  *(float *)(param_1 + 0x88) = fVar2 * pfVar13[9] + fVar3 * pfVar13[10] + fVar1 * pfVar13[8];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0;

  fVar1 = pfVar14[8];

  fVar2 = pfVar14[9];

  fVar3 = pfVar14[10];

  *(float *)(param_1 + 0x90) = fVar2 * pfVar13[1] + fVar3 * pfVar13[2] + fVar1 * *pfVar13;

  *(float *)(param_1 + 0x94) = fVar2 * pfVar13[5] + fVar3 * pfVar13[6] + fVar1 * pfVar13[4];

  *(float *)(param_1 + 0x98) = fVar2 * pfVar13[9] + fVar3 * pfVar13[10] + fVar1 * pfVar13[8];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

  fVar1 = pfVar14[0xc];

  fVar2 = pfVar14[0xd];

  fVar3 = pfVar14[0xe];

  *(float *)(param_1 + 0xa0) = fVar2 * pfVar13[1] + fVar3 * pfVar13[2] + fVar1 * *pfVar13;

  *(float *)(param_1 + 0xa4) = fVar2 * pfVar13[5] + fVar3 * pfVar13[6] + fVar1 * pfVar13[4];

  *(float *)(param_1 + 0xa8) = fVar2 * pfVar13[9] + fVar3 * pfVar13[10] + fVar1 * pfVar13[8];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  pfVar13 = *(float **)(param_1 + 0x14);

  fVar1 = pfVar13[0xc];

  fVar2 = pfVar13[0xd];

  fVar3 = pfVar13[0xe];

  fVar4 = pfVar13[1];

  fVar5 = pfVar13[2];

  fVar6 = *pfVar13;

  fVar7 = pfVar13[5];

  fVar8 = pfVar13[6];

  fVar9 = pfVar13[4];

  fVar10 = pfVar13[9];

  fVar11 = pfVar13[10];

  fVar12 = pfVar13[8];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc);

  *(float *)(param_1 + 0xb0) =

       *(float *)(param_1 + 0xb0) - (fVar1 * fVar6 + fVar3 * fVar5 + fVar2 * fVar4);

  *(float *)(param_1 + 0xb4) =

       *(float *)(param_1 + 0xb4) - (fVar1 * fVar9 + fVar3 * fVar8 + fVar2 * fVar7);

  *(float *)(param_1 + 0xb8) =

       *(float *)(param_1 + 0xb8) - (fVar1 * fVar12 + fVar3 * fVar11 + fVar2 * fVar10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc);

  fVar1 = *(float *)(param_1 + 0xb0);

  fVar2 = *(float *)(param_1 + 0xb4);

  fVar3 = *(float *)(param_1 + 0xb8);

  *(float *)(param_1 + 0xc0) =

       fVar1 * *(float *)(param_1 + 0x70) +

       fVar2 * *(float *)(param_1 + 0x74) + fVar3 * *(float *)(param_1 + 0x78);

  *(float *)(param_1 + 0xc4) =

       fVar1 * *(float *)(param_1 + 0x80) +

       fVar2 * *(float *)(param_1 + 0x84) + fVar3 * *(float *)(param_1 + 0x88);

  *(float *)(param_1 + 200) =

       fVar1 * *(float *)(param_1 + 0x90) +

       fVar2 * *(float *)(param_1 + 0x94) + fVar3 * *(float *)(param_1 + 0x98);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = 0;

  return;

}
