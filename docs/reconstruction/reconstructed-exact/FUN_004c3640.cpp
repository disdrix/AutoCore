// =============================================================================
// FUN_004c3640
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3640
// Address:   0x004c3640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3640 @ 0x004c3640
// Stable ID: aa_004c3640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: NAN×2, CONCAT21, CONCAT31, FUN_004c3640, FUN_0074e800, FUN_0079a110.
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

uint __fastcall FUN_004c3640(int param_1)



{

  uint3 uVar1;

  uint in_EAX;

  uint16_t extraout_var;

  float10 fVar2;

  float10 fVar3;

  

  if (*(int *)(param_1 + 0xb8) == 0x12) {

    fVar2 = (float10)FUN_0079a110();

    fVar2 = (float10)FUN_0074e800((float)fVar2);

    fVar3 = (float10)g_flZero;

    uVar1 = CONCAT21(extraout_var,

                     (fVar3 == fVar2) << 6 | (NAN(fVar3) || NAN(fVar2)) << 2 | 2U | fVar3 < fVar2);

    in_EAX = (uint)uVar1 << 8;

    if (fVar3 != fVar2) {

      return CONCAT31(uVar1,1);

    }

  }

  return in_EAX & 0xffffff00;

}
