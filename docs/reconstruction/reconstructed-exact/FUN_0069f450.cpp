// =============================================================================
// FUN_0069f450
// -----------------------------------------------------------------------------
// Stable ID: aa_0069f450
// Address:   0x0069f450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069f450 @ 0x0069f450
// Stable ID: aa_0069f450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0068ec20, FUN_0069f450, fpatan.
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



void FUN_0069f450(float *param_1)



{

  float10 fVar1;

  

  fVar1 = (float10)fpatan((float10)param_1[2],-(float10)*param_1);

  if ((DAT_00d08f78 & 1) == 0) {

    DAT_00d08f78 = DAT_00d08f78 | 1;

    _DAT_00d08f6c = 0.0;

    DAT_00d08f70 = 0.5;

    DAT_00d08f74 = 1.0;

  }

  if ((DAT_00d08f78 & 2) == 0) {

    DAT_00d08f78 = DAT_00d08f78 | 2;

    _DAT_00d08f60 = 0.0;

    DAT_00d08f64 = -0.5;

    DAT_00d08f68 = 1.0;

  }

  if ((DAT_00d08f78 & 4) == 0) {

    DAT_00d08f78 = DAT_00d08f78 | 4;

    _DAT_00d08f54 = 0.0;

    DAT_00d08f58 = -0.5;

    DAT_00d08f5c = 0.0;

  }

  if ((DAT_00d08f78 & 8) == 0) {

    DAT_00d08f78 = DAT_00d08f78 | 8;

    _DAT_00d08f48 = 0.0;

    DAT_00d08f4c = 0.5;

    DAT_00d08f50 = 0.0;

  }

  if ((DAT_00d08f78 & 0x10) == 0) {

    DAT_00d08f78 = DAT_00d08f78 | 0x10;

  }

  _DAT_00d08f18 = -_DAT_00d08f6c;

  _DAT_00d08f20 = DAT_00d08f70;

  _DAT_00d08f24 = -_DAT_00d08f60;

  _DAT_00d08f28 = DAT_00d08f68;

  _DAT_00d08f30 = -_DAT_00d08f54;

  _DAT_00d08f1c = DAT_00d08f74;

  _DAT_00d08f34 = DAT_00d08f5c;

  _DAT_00d08f3c = -_DAT_00d08f48;

  _DAT_00d08f38 = DAT_00d08f58;

  _DAT_00d08f2c = DAT_00d08f64;

  _DAT_00d08f44 = DAT_00d08f4c;

  _DAT_00d08f40 = DAT_00d08f50;

  FUN_0068ec20((float)(fVar1 * (float10)_DAT_009ea7bc));

  _DAT_00af5810 = _DAT_00d08f18 * 1.0 + DAT_00d08f70 * 0.0 + DAT_00d08f74 * 0.0;

  _DAT_00af5814 = _DAT_00d08f18 * 0.0 + DAT_00d08f70 * 0.0 + DAT_00d08f74 * 1.0;

  _DAT_00af5818 = _DAT_00d08f18 * 0.0 + DAT_00d08f70 * 1.0 + DAT_00d08f74 * 0.0;

  _DAT_00af581c = _DAT_00d08f24 * 1.0 + DAT_00d08f68 * 0.0 + DAT_00d08f64 * 0.0;

  _DAT_00af5820 = _DAT_00d08f24 * 0.0 + DAT_00d08f68 * 1.0 + DAT_00d08f64 * 0.0;

  _DAT_00af5824 = _DAT_00d08f24 * 0.0 + DAT_00d08f68 * 0.0 + DAT_00d08f64 * 1.0;

  _DAT_00af5828 = _DAT_00d08f30 * 1.0 + DAT_00d08f5c * 0.0 + DAT_00d08f58 * 0.0;

  _DAT_00af582c = _DAT_00d08f30 * 0.0 + DAT_00d08f5c * 1.0 + DAT_00d08f58 * 0.0;

  _DAT_00af5830 = _DAT_00d08f30 * 0.0 + DAT_00d08f5c * 0.0 + DAT_00d08f58 * 1.0;

  _DAT_00af5834 = _DAT_00d08f3c * 1.0 + DAT_00d08f50 * 0.0 + DAT_00d08f4c * 0.0;

  _DAT_00af5838 = _DAT_00d08f3c * 0.0 + DAT_00d08f50 * 1.0 + DAT_00d08f4c * 0.0;

  _DAT_00af583c = _DAT_00d08f3c * 0.0 + DAT_00d08f50 * 0.0 + DAT_00d08f4c * 1.0;

  return;

}
