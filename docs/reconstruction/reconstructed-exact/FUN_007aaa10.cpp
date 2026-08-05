// =============================================================================
// FUN_007aaa10
// -----------------------------------------------------------------------------
// Stable ID: aa_007aaa10
// Address:   0x007aaa10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007aaa10 @ 0x007aaa10
// Stable ID: aa_007aaa10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007aaa10.
//  - Return sites: 2.

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

void __fastcall FUN_007aaa10(int *param_1)



{

  int iVar1;

  float fVar2;

  int *in_EAX;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int local_8;

  int local_4;

  

  fVar2 = DAT_00aaa670;

  if (DAT_00d17944 != 0) {

    fVar3 = (float)DAT_00d1e818;

    fVar5 = (float)param_1[2] * DAT_00aaa674;

    fVar4 = (float)DAT_00d1e81c;

    fVar6 = (float)param_1[1] * DAT_00aaa670;

    iVar1 = param_1[3];

    *in_EAX = (int)(((float)*param_1 * DAT_00aaa674) / fVar3);

    in_EAX[1] = (int)(fVar6 / fVar4);

    in_EAX[2] = (int)(fVar5 / fVar3);

    in_EAX[3] = (int)(((float)iVar1 * fVar2) / fVar4);

    return;

  }

  *in_EAX = 0;

  in_EAX[1] = 0;

  in_EAX[2] = local_8;

  in_EAX[3] = local_4;

  return;

}
