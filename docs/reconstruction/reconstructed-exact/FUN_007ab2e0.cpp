// =============================================================================
// FUN_007ab2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ab2e0
// Address:   0x007ab2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ab2e0 @ 0x007ab2e0
// Stable ID: aa_007ab2e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×1.
//  - Notable callees: ROUND×2, FUN_007ab2e0.
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

void __fastcall FUN_007ab2e0(int *param_1)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int *unaff_retaddr;

  uint8_t local_28 [32];

  uint8_t local_8 [8];

  

  if (*(char *)((int)param_1 + 0x1ca) == '\0') {

    pfVar3 = (float *)(**(code **)(*param_1 + 0x134))(local_8);

    iVar1 = DAT_00d1e818;

    iVar2 = DAT_00d1e81c;

  }

  else {

    pfVar3 = (float *)(**(code **)(*param_1 + 0x134))(local_28);

    iVar1 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);

    iVar2 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);

  }

  if (*(char *)((int)param_1 + 0x1c9) == '\0') {

    if (DAT_00d17944 != 0) {

      fVar4 = ((float)param_1[0x1e] * DAT_00aaa674) / (float)DAT_00d1e818;

      fVar6 = ((float)param_1[0x1f] * DAT_00aaa670) / (float)DAT_00d1e81c;

      goto LAB_007ab3eb;

    }

  }

  else if (DAT_00d17944 != 0) {

    fVar4 = ((float)param_1[0x1e] * DAT_00aaa674) /

            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);

    fVar6 = ((float)param_1[0x1f] * DAT_00aaa670) /

            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);

    goto LAB_007ab3eb;

  }

  fVar6 = 0.0;

  fVar4 = 0.0;

LAB_007ab3eb:

  if (DAT_00d17944 == 0) {

    fVar5 = 0.0;

    fVar7 = 0.0;

  }

  else {

    fVar5 = ((float)param_1[0x97] * (float)iVar1 * *pfVar3 * DAT_00aaa67c * DAT_00aaa674) /

            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);

    fVar7 = ((float)param_1[0x98] * (float)iVar2 * pfVar3[1] * DAT_00aaa678 * DAT_00aaa670) /

            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);

  }

  *unaff_retaddr = (int)ROUND(fVar5 + fVar4);

  unaff_retaddr[1] = (int)ROUND(fVar7 + fVar6);

  return;

}
