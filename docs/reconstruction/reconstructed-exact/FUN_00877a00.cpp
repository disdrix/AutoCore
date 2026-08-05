// =============================================================================
// FUN_00877a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00877a00
// Address:   0x00877a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00877a00 @ 0x00877a00
// Stable ID: aa_00877a00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007ab7f0, FUN_00877a00.
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

void __fastcall FUN_00877a00(int *param_1)



{

  float fVar1;

  float *pfVar2;

  float unaff_ESI;

  float local_18;

  float local_14;

  int iStack_10;

  uint8_t local_8 [8];

  

  FUN_007ab7f0();

  if (((char)param_1[0x149] != '\0') && ((int *)param_1[0x163] != (int *)0x0)) {

    if (DAT_00d17944 == 0) {

      local_18 = 0.0;

      local_14 = 0.0;

    }

    else {

      local_18 = ((float)param_1[0x14a] * DAT_00aaa674) / (float)DAT_00d1e818;

      local_14 = ((float)param_1[0x14b] * DAT_00aaa670) / (float)DAT_00d1e81c;

    }

    pfVar2 = (float *)(**(code **)(*(int *)param_1[0x163] + 0x124))(local_8);

    fVar1 = pfVar2[1];

    param_1[0x14c] = (int)(*pfVar2 + unaff_ESI);

    param_1[0x14d] = (int)(fVar1 + local_18);

    local_14 = (float)(int)((float)DAT_00d1e818 * (float)param_1[0x14c] * DAT_00aaa67c);

    iStack_10 = (int)((float)DAT_00d1e81c * (float)param_1[0x14d] * DAT_00aaa678);

    (**(code **)(*param_1 + 0x110))(&local_14);

  }

  return;

}
