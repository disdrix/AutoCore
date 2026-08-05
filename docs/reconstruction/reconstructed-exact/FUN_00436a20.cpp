// =============================================================================
// FUN_00436a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00436a20
// Address:   0x00436a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00436a20 @ 0x00436a20
// Stable ID: aa_00436a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00436a20.
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

void FUN_00436a20(int *param_1,int param_2,uint *param_3,int param_4,uint *param_5,int param_6,

                 uint *param_7)



{

  while ((param_3 != param_5 || (param_2 != param_4))) {

    if (param_4 == 0) {

      param_5 = param_5 + -1;

      param_4 = 0x1f;

    }

    else {

      param_4 = param_4 + -1;

    }

    if (param_6 == 0) {

      param_6 = 0x1f;

      param_7 = param_7 + -1;

    }

    else {

      param_6 = param_6 + -1;

    }

    if ((*param_5 & 1 << ((byte)param_4 & 0x1f)) == 0) {

      *param_7 = *param_7 & ~(1 << ((byte)param_6 & 0x1f));

    }

    else {

      *param_7 = *param_7 | 1 << ((byte)param_6 & 0x1f);

    }

  }

  *param_1 = param_6;

  param_1[1] = (int)param_7;

  return;

}
