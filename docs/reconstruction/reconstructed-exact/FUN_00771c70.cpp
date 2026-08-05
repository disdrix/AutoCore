// =============================================================================
// FUN_00771c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00771c70
// Address:   0x00771c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771c70 @ 0x00771c70
// Stable ID: aa_00771c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007701d0, FUN_00770440, FUN_00771c70.
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

int __fastcall FUN_00771c70(uint *param_1)



{

  uint in_EAX;

  int iVar1;

  

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    FUN_007701d0();

    *(uint *)param_1[3] = in_EAX & 0xfffffff;

    iVar1 = 0;

    *param_1 = (uint)(*(int *)param_1[3] != 0);

  }

  return iVar1;

}
