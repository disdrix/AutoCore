// =============================================================================
// FUN_0046feb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046feb0
// Address:   0x0046feb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046feb0 @ 0x0046feb0
// Stable ID: aa_0046feb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00476d60×2, FUN_0046feb0, ROUND.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0046feb0(double param_1)



{

  int in_EAX;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_c;

  

  if ((in_EAX != 0) && (unaff_EDI != 0)) {

    if (_DAT_00aaa610 < param_1) {

      FUN_00476d60();

      param_1 = _DAT_00aaa610;

    }

    *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) | 1;

    *(float *)(unaff_EDI + 0x28) = (float)param_1;

    local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(_DAT_00aaa5e8 * param_1 + _DAT_00aaa5e0);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xfc) = local_c;

    if (param_1 == _DAT_00aaa608) {

      FUN_00476d60();

    }

  }

  return;

}
