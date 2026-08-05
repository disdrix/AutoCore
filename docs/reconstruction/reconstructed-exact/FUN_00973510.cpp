// =============================================================================
// FUN_00973510
// -----------------------------------------------------------------------------
// Stable ID: aa_00973510
// Address:   0x00973510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00973510 @ 0x00973510
// Stable ID: aa_00973510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00973510.
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

void __fastcall FUN_00973510(byte *param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  float fVar4;

  float *in_EAX;

  

  fVar4 = DAT_00aaa7a8;

  bVar1 = param_1[1];

  bVar2 = *param_1;

  bVar3 = param_1[3];

  *in_EAX = (float)param_1[2] * DAT_00aaa7a8;

  in_EAX[1] = (float)bVar1 * fVar4;

  in_EAX[2] = (float)bVar2 * fVar4;

  in_EAX[3] = (float)bVar3 * fVar4;

  return;

}
