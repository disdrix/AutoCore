// =============================================================================
// FUN_0044be60
// -----------------------------------------------------------------------------
// Stable ID: aa_0044be60
// Address:   0x0044be60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044be60 @ 0x0044be60
// Stable ID: aa_0044be60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0044be60, FUN_00972e50.
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

void FUN_0044be60(void)



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

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float *pfVar26;

  int unaff_ESI;

  int *unaff_EDI;

  

  if (((unaff_EDI[0x16] != 0) && (unaff_EDI[0x17] != 0)) &&

     (*(int *)(unaff_EDI[0x17] + 0x1c) != unaff_EDI[0x18])) {

    (**(code **)(*unaff_EDI + 0x80))();

  }

  pfVar26 = (float *)unaff_EDI[0x19];

  if (((uint)pfVar26[0x2f] & 1) != 0) {

    pfVar26 = (float *)FUN_00972e50();

  }

  fVar1 = pfVar26[2];

  fVar2 = *(float *)(unaff_ESI + 0x28);

  fVar3 = pfVar26[1];

  fVar4 = *(float *)(unaff_ESI + 0x18);

  fVar5 = pfVar26[6];

  fVar6 = *(float *)(unaff_ESI + 0x28);

  fVar7 = pfVar26[10];

  fVar8 = *(float *)(unaff_ESI + 0x28);

  fVar9 = pfVar26[0xd];

  fVar10 = *(float *)(unaff_ESI + 0x18);

  fVar11 = *pfVar26;

  fVar12 = *(float *)(unaff_ESI + 8);

  fVar13 = pfVar26[5];

  fVar14 = *(float *)(unaff_ESI + 0x18);

  fVar15 = pfVar26[4];

  fVar16 = *(float *)(unaff_ESI + 8);

  fVar17 = pfVar26[9];

  fVar18 = *(float *)(unaff_ESI + 0x18);

  fVar19 = pfVar26[8];

  fVar20 = *(float *)(unaff_ESI + 8);

  fVar21 = pfVar26[0xe];

  fVar22 = *(float *)(unaff_ESI + 0x28);

  fVar23 = pfVar26[0xc];

  fVar24 = *(float *)(unaff_ESI + 8);

  fVar25 = *(float *)(unaff_ESI + 0x38);

  if ((*(byte *)(unaff_EDI + 0x2f) & 1) != 0) {

    (**(code **)(*unaff_EDI + 0x5c))();

  }

  unaff_EDI[0x1b] =

       (int)((float)unaff_EDI[0xc] * (fVar7 * fVar8 + fVar17 * fVar18 + fVar19 * fVar20) +

             (float)unaff_EDI[0xb] * (fVar5 * fVar6 + fVar13 * fVar14 + fVar15 * fVar16) +

             (float)unaff_EDI[10] * (fVar1 * fVar2 + fVar3 * fVar4 + fVar11 * fVar12) +

            fVar21 * fVar22 + fVar9 * fVar10 + fVar23 * fVar24 + fVar25);

  return;

}
