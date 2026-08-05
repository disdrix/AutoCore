// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00915da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00915da0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00915da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004cd220×2, FUN_00915da0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_00915da0(int param_1)



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

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  int iVar17;

  float *unaff_ESI;

  float10 fVar18;

  float10 fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  

  iVar17 = *(int *)(param_1 + 0x2a4);

  fVar21 = *(float *)(iVar17 + 0xf0);

  fVar20 = *(float *)(iVar17 + 0xf8) + g_flOne;

  fVar22 = 0.0 - (*(float *)(iVar17 + 0xfc) + g_flOne);

  fVar24 = 0.0 - (*(float *)(iVar17 + 0xf8) + g_flOne);

  fVar25 = 0.0 - (*(float *)(iVar17 + 0xfc) + g_flOne);

  fVar23 = *(float *)(iVar17 + 0xf0);

  fVar1 = *(float *)(DAT_00d17944 + 0x220);

  fVar2 = *(float *)(DAT_00d17944 + 0x214);

  fVar3 = *(float *)(DAT_00d17944 + 0x208);

  fVar4 = *(float *)(DAT_00d17944 + 0x214);

  fVar5 = *(float *)(DAT_00d17944 + 0x218);

  fVar6 = *(float *)(DAT_00d17944 + 0x224);

  fVar7 = *(float *)(DAT_00d17944 + 0x208);

  fVar8 = *(float *)(DAT_00d17944 + 0x21c);

  fVar9 = *(float *)(DAT_00d17944 + 0x220);

  fVar10 = *(float *)(DAT_00d17944 + 0x204);

  fVar11 = *(float *)(DAT_00d17944 + 0x210);

  fVar12 = *(float *)(DAT_00d17944 + 0x20c);

  fVar13 = *(float *)(DAT_00d17944 + 0x22c);

  fVar14 = *(float *)(DAT_00d17944 + 0x228);

  fVar15 = *(float *)(DAT_00d17944 + 0x230);

  fVar16 = *(float *)(DAT_00d17944 + 0x22c);

  fVar18 = (float10)FUN_004cd220(*(float *)(DAT_00d17944 + 0x228) +

                                 *(float *)(DAT_00d17944 + 0x204) * fVar20 +

                                 *(float *)(DAT_00d17944 + 0x210) * fVar22 +

                                 *(float *)(DAT_00d17944 + 0x21c) * fVar21,

                                 *(float *)(DAT_00d17944 + 0x230) +

                                 *(float *)(DAT_00d17944 + 0x20c) * fVar20 +

                                 *(float *)(DAT_00d17944 + 0x218) * fVar22 +

                                 *(float *)(DAT_00d17944 + 0x224) * fVar21);

  fVar19 = (float10)FUN_004cd220(fVar14 + fVar10 * fVar24 + fVar11 * fVar25 + fVar8 * fVar23,

                                 fVar15 + fVar12 * fVar24 + fVar5 * fVar25 + fVar6 * fVar23);

  fVar21 = (float)fVar18 - (fVar13 + fVar3 * fVar20 + fVar2 * fVar22 + fVar1 * fVar21);

  fVar23 = (float)fVar19 - (fVar16 + fVar7 * fVar24 + fVar4 * fVar25 + fVar9 * fVar23);

  if (fVar21 <= fVar23) {

    fVar21 = fVar23;

  }

  if (g_flZero < fVar21) {

    *unaff_ESI = *unaff_ESI + fVar21;

  }

  return;

}
